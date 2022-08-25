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
 *   flc2_entity_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the function declarations used for gprs flow
 *   control implementation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLC2_ENTITY_CONFIG_H
#define _FLC2_ENTITY_CONFIG_H

//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"

#if !defined(__MTK_TARGET__) && defined(DEBUG_KAL) && defined(DEBUG_BUF2)
#define __MTK_FLC_LEAK_DETECT__
#endif

#ifdef __MTK_FLC_LEAK_DETECT__
typedef kal_ctrl_buff_stats flc2_buff_stats;

typedef struct {
    flc2_buff_stats flc2_buff_info;
    kal_bool        is_valid;
} flc2_store_buff_stats;
#define MAX_NUM_BUFF_AVAI    100
#endif

#ifdef FLC2_UNITTEST 
#define FLC2_MAX_UT_POOL_ID  10
#define FLC2_MAX_UT_PROFILE  10
#define FLC2_MAX_UT_MB       10

#else
#define FLC2_MAX_UT_POOL_ID  0
#define FLC2_MAX_UT_PROFILE  0
#define FLC2_MAX_UT_MB       0
#endif /* FLC2_UNITTEST */
/*************************************************************************
 * Enums of Pool and MB (for add new configuration)
 *************************************************************************/
 /*
  * Eric Hsieh: MAUI_01701165
  *             For the following FLC owners, if the flc2_pool_id_enum content is modified,
  *             please remember to modify the content of flc2_pool_id_name to keep both sync.
  */
typedef enum {
    FLC2_POOL_ID_APPPDU_UL,      /* 0 */
    FLC2_POOL_ID_APPPDU_DL,
    FLC2_POOL_ID_CSPDU_UL,
    FLC2_POOL_ID_CSPDU_DL,
    FLC2_POOL_ID_NPDU_UL,
    FLC2_POOL_ID_NPDU_UL_01,   /* 5 */
    FLC2_POOL_ID_NPDU_UL_02,

    FLC2_POOL_ID_NPDU_DL,      
    FLC2_POOL_ID_NPDU_DL_01,      
    FLC2_POOL_ID_NPDU_DL_02,      

    FLC2_POOL_ID_PSPDU_ACK_SAPI3_UL,     /* 10 */
    FLC2_POOL_ID_PSPDU_ACK_SAPI5_UL,
    FLC2_POOL_ID_PSPDU_ACK_SAPI9_UL,
    FLC2_POOL_ID_PSPDU_ACK_SAPI11_UL,

    FLC2_POOL_ID_PSPDU_ACK_SAPI3_DL, 
    FLC2_POOL_ID_PSPDU_ACK_SAPI5_DL,      /* 15 */
    FLC2_POOL_ID_PSPDU_ACK_SAPI9_DL,
    FLC2_POOL_ID_PSPDU_ACK_SAPI11_DL,

    FLC2_POOL_ID_PSPDU_UNACK_PDP0_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP1_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP2_UL,      /* 20 */
    FLC2_POOL_ID_PSPDU_UNACK_PDP3_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP4_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP5_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP6_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP7_UL,      /* 25 */
    FLC2_POOL_ID_PSPDU_UNACK_PDP8_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP9_UL,
    FLC2_POOL_ID_PSPDU_UNACK_PDP10_UL,

    FLC2_POOL_ID_PSPDU_UNACK_DL,
    FLC2_POOL_ID_CIPHER,                  /* 30 */

    FLC2_POOL_ID_SPDU_UL_0,
    FLC2_POOL_ID_SPDU_UL_1,
    FLC2_POOL_ID_SPDU_UL_2,
    FLC2_POOL_ID_SPDU_UL_3,      
    FLC2_POOL_ID_SPDU_UL_4,                 /* 35 */
    FLC2_POOL_ID_SPDU_UL_5,
    FLC2_POOL_ID_SPDU_UL_6,
    FLC2_POOL_ID_SPDU_UL_7,
    FLC2_POOL_ID_SPDU_UL_8,   
    FLC2_POOL_ID_SPDU_UL_9,                 /* 40 */
    FLC2_POOL_ID_SPDU_UL_10,
    FLC2_POOL_ID_SPDU_UL_11,
    FLC2_POOL_ID_SPDU_UL_12,
    FLC2_POOL_ID_SPDU_UL_13,   
    FLC2_POOL_ID_SPDU_UL_14,                /* 45 */
    FLC2_POOL_ID_SPDU_UL_15,
    FLC2_POOL_ID_SPDU_UL_16,
    FLC2_POOL_ID_SPDU_UL_17,
    FLC2_POOL_ID_SPDU_UL_18,    
    FLC2_POOL_ID_SPDU_UL_19,                /* 50 */
    FLC2_POOL_ID_SPDU_UL_20,
    FLC2_POOL_ID_SPDU_UL_21,
    FLC2_POOL_ID_SPDU_UL_22,
    FLC2_POOL_ID_SPDU_UL_23,    
    FLC2_POOL_ID_SPDU_UL_24,                /* 55 */
    FLC2_POOL_ID_SPDU_DL,        
    FLC2_POOL_ID_HS,                        /* Pool used for hot spot feature */
    FLC2_POOL_ID_TPDU,

    FLC2_POOL_ID_IRDA_UL,
    FLC2_POOL_ID_IRDA_DL,   				/* 60 */

    FLC2_POOL_ID_FOR_UT_ONLY,
    
FLC2_POOL_ID_UT_BEGIN,                  
    FLC2_POOL_TOTAL = (FLC2_POOL_ID_UT_BEGIN + FLC2_MAX_UT_POOL_ID),
    FLC2_INVALID_POOL_ID = 0xff
} flc2_pool_id_enum;

#define FLC2_POOL_ID_SPDU_HS FLC2_POOL_ID_HS

typedef enum {
    FLC2_PROFILE_INDEX_APPPDU_UL,
    FLC2_PROFILE_INDEX_APPPDU_DL,
    FLC2_PROFILE_INDEX_CSPDU_UL,
    FLC2_PROFILE_INDEX_CSPDU_DL,
    FLC2_PROFILE_INDEX_NPDU_UL,
    FLC2_PROFILE_INDEX_NPDU_DL,
    FLC2_PROFILE_INDEX_PSPDU_ACK_SAPI3_UL,
    FLC2_PROFILE_INDEX_PSPDU_ACK_SAPI5_UL,
    FLC2_PROFILE_INDEX_PSPDU_ACK_SAPI9_UL,
    FLC2_PROFILE_INDEX_PSPDU_ACK_SAPI11_UL,
    FLC2_PROFILE_INDEX_PSPDU_ACK_SAPI3_5_9_11_DL,
    FLC2_PROFILE_INDEX_PSPDU_UNACK_UL,
    FLC2_PROFILE_INDEX_PSPDU_UNACK_DL,
    FLC2_PROFILE_INDEX_CIPHER,
    FLC2_PROFILE_INDEX_SPDU_UL,
    FLC2_PROFILE_INDEX_SPDU_DL,
    FLC2_PROFILE_INDEX_HOTSPOT,
    FLC2_PROFILE_INDEX_TPDU,
    FLC2_PROFILE_INDEX_IRDA_IRCOMM_UL,
    FLC2_PROFILE_INDEX_IRDA_DL,

    FLC2_PROFILE_INDEX_FOR_UT_ONLY,

    FLC2_PROFILE_INDEX_UT_BEGIN, 
    FLC2_PROFILE_TOTAL = (FLC2_PROFILE_INDEX_UT_BEGIN + FLC2_MAX_UT_PROFILE),
    FLC2_PROFILE_INDEX_INVALID
} flc2_profile_index_enum; 

#ifdef __UMTS_TDD128_MODE__

typedef enum {
    FLC2_MB_INDEX_0,    /* for APPDU UL/DL */
    FLC2_MB_INDEX_1,    /* for CSPDU UL/DL */
    FLC2_MB_INDEX_3,    /* for NPDU UL and PSPDU DL (GPRS) */
    FLC2_MB_INDEX_4,    /* for IRDA UL/DL*/
    FLC2_MB_INDEX_10,   /* for NPDU DL and PSPDU UL, Cipher (GPRS) */
    FLC2_MB_INDEX_11,   /* for SPDU UL, TPDU */
    FLC2_MB_INDEX_12,   /* for SPDU DL */
    FLC2_MB_INDEX_MDI,  /* for MDI, FLC2 internal use */
    FLC2_MB_INDEX_UT_BEGIN,  
    FLC2_MB_TOTAL = (FLC2_MB_INDEX_UT_BEGIN + FLC2_MAX_UT_MB),
    FLC2_MB_CTRL_BUFF,
    FLC2_INVALID_MB_INDEX
} flc2_mb_index_enum;

#else

typedef enum {
    FLC2_MB_INDEX_0,    /* for APPDU UL/DL */
    FLC2_MB_INDEX_1,    /* for CSPDU UL/DL */
    FLC2_MB_INDEX_2,    /* for NPDU UL */
    FLC2_MB_INDEX_3,    /* for PSPDU DL (GPRS) */
    FLC2_MB_INDEX_4,    /* for IRDA UL/DL*/
    FLC2_MB_INDEX_5,    /* for NPDU DL */
    FLC2_MB_INDEX_10,   /* for PSPDU UL, Cipher (GPRS) */
    FLC2_MB_INDEX_11,   /* for SPDU UL, TPDU */
    FLC2_MB_INDEX_12,   /* for SPDU DL */
    FLC2_MB_INDEX_MDI,  /* for MDI, FLC2 internal use */

    FLC2_MB_INDEX_UT_ONLY, // for module UT only

    FLC2_MB_INDEX_UT_BEGIN,  
    FLC2_MB_TOTAL = (FLC2_MB_INDEX_UT_BEGIN + FLC2_MAX_UT_MB),
    FLC2_MB_CTRL_BUFF,
    FLC2_INVALID_MB_INDEX
} flc2_mb_index_enum;

#endif

typedef enum {
	FLC_SIM_1 = 0x1,
	FLC_SIM_2 = 0x2
} flc_dual_sim_enum;

typedef enum {
	FLC_POOL_NORMAL,
	FLC_POOL_FULL
} flc_pool_ut_status_enum;

typedef enum {
    FLC_POOL_STATUS_NO_CHANGE,
    FLC_POOL_STATUS_NORMAL,
    FLC_POOL_STATUS_SUSPEND,
    FLC_POOL_STATUS_NO_MEMORY
} flc_pool_em_status_enum;

/*************************************************************************
 * FLC2 internal enum
 *************************************************************************/

typedef enum {
    FLC2_BELOW_SIZE_L_THRE,
    FLC2_ABOVE_SIZE_U_THRE,
    FLC2_BELOW_PKT_NO_L_THRE,
    FLC2_ABOVE_PKT_NO_U_THRE,
    FLC2_NO_MEMORY_AVAILABLE
} flc2_thres_hit_enent_enum;

typedef enum {
    FLC2_SHRINK_AUTO,
    FLC2_SHRINK_MANUAL
} flc2_shrink_mode_enum;

typedef enum {
    FLC2_REASON_OK,
    FLC2_REASON_FREE_MEMORY_ERROR,
    FLC2_REASON_ALLOCATE_FROM_WRONG_MB,
    FLC2_REASON_GET_SIZE_0_BUFF,
    FLC2_REASON_UNEXPECTED_MM_TYPE,
    FLC2_REASON_UNABLE_TO_ALLOC_MEMORY,
    FLC2_REASON_FREE_A_FREED_MEMORY,
    FLC2_REASON_RECONFIG_FAIL_MORE_THAN_ONE_USER,
    FLC2_REASON_RECONFIG_ERROR,
    FLC2_REASON_SHRINK_POOL_FAIL,
    FLC2_REASON_GROW_POOL_FAIL,
    FLC2_REASON_SIZE_EXCEED_MAXIMUM,
    FLC2_REASON_FREE_CTRL_BUFF_FAIL,
    FLC2_REASON_FREE_MEM_OUT_OF_RANGE,
    FLC2_REASON_FREE_ERROR_WRONG_ADDR,
    FLC2_REASON_MEM_HEADER_CRPT,
    FLC2_REASON_MISSING_FREE_INDEX_HEADER,
    FLC2_REASON_CHUNK_NOT_IN_HALF_FREE_LIST,
    FLC2_REASON_CHUNK_ALREADY_IN_HALF_FREE_LIST,
    FLC2_REASON_CHUNK_ALREADY_IN_FULL_FREE_LIST,
    FLC2_REASON_REMOVE_FROM_FULL_FREE_LIST_ERROR,
    FLC2_REASON_MB_INIT_ERROR,
    FLC2_REASON_POOL_INIT_ERROR,
    FLC2_REASON_ONLY_FOR_DEBUG,
    FLC2_REASON_MULTI_SIZE_MEM_ALLOC_ERROR,
    FLC2_REASON_NONEMPTY_POOL,
    FLC2_REASON_MEM_NOT_IN_THIS_MB,
    FLC2_REASON_GUARD_PATTERN_CORRUPTED,
    FLC2_REASON_POOL_NOT_INIT,
    FLC2_REASON_MB_NOT_INIT,
    FLC2_REASON_USER_INFO_ALREADY_EXIST,
    FLC2_REASON_USER_INFO_NOT_EMPTY,
    FLC2_REASON_POOL_CNXT_NOT_MATCH,

    /* insert non-MDI reason here */

    FLC2_REASON_MDI_START,
    FLC2_REASON_MDI_NO_ENTITY,
    FLC2_REASON_MDI_ALREADY_MONITORED,
    FLC2_REASON_MDI_WRONG_PARA,
    FLC2_REASON_MDI_ERROR,
    FLC2_REASON_MDI_INVALID_PTR
} flc2_debug_reason_enum;

typedef enum {
    FLC2_MDI_TYPE_POOL,
    FLC2_MDI_TYPE_MB
} flc2_debug_mdi_type_enum;



typedef enum {
    FLC2_MM_FIX_SIZE,
    FLC2_MM_ADM,
#ifdef __UMTS_TDD128_MODE__

#else
    FLC2_MM_AFM,
#endif
    FLC2_MM_CTRL_BUFF,
    FLC2_MM_TYPE_TOTAL
} flc2_mem_mngr_type_enum;

typedef enum {
    FLC2_API_FUNC_INIT_POOL,
    FLC2_API_FUNC_DEINIT_POOL,
    FLC2_API_FUNC_GET_PEER_BUFF,
    FLC2_API_FUNC_FREE_PEER_BUFF,
    FLC2_API_FUNC_GROW_POOL,
    FLC2_API_FUNC_SHRINK_POOL,
    FLC2_API_FUNC_RECONFIG_POOL,
    FLC2_API_FUNC_CHECK_BUFF
} flc2_ent_func_enum ;

/*************************************************************************
 * Structures of memory block
 *************************************************************************/
typedef struct {
    kal_uint32          curr_occ;
    kal_uint32          grow_size;
    flc2_mb_index_enum  using_mb_index;
    kal_uint8           user_count;
    kal_enhmutexid      mb_mutex;
} flc2_mm_info_struct;

typedef struct {
    kal_uint32                total_size;
    flc2_mem_mngr_type_enum   mm_type;
    void *                    ctrl_header_ptr; //All the control information will be maintained in the header, different mm_types have differ control header
    kal_uint32                *subblock;
#ifdef __UMTS_TDD128_MODE__

#else
    kal_uint32                *subblock_nr;
#endif
    kal_uint32                max_grow_size;
} flc2_mm_block_struct;

typedef struct {
    kal_uint32          curr_occ;
    kal_uint32          grow_size;
    flc2_mb_index_enum  using_mb_index;    
    kal_uint8           user_count;
    kal_enhmutexid      mb_mutex;
    
    KAL_ADM_ID          adm_id;
} flc2_mb_adm_ctrl_header_struct;

typedef struct {
    kal_uint32          curr_occ;
    kal_uint32          grow_size;
    flc2_mb_index_enum  using_mb_index;    
    kal_uint8           user_count;
    kal_enhmutexid      mb_mutex;

    KAL_AFM_ID          afm_id;
} flc2_mb_afm_ctrl_header_struct;

typedef struct {
    kal_uint32          curr_occ;
    kal_uint32          grow_size;
    flc2_mb_index_enum  using_mb_index;    
    kal_uint8           user_count;
    kal_enhmutexid      mb_mutex;

    kal_uint16     num_chunks;
    kal_uint8      full_free_pdu_idx ;
    kal_uint8      half_free_pdu_idx;
    kal_uint16     num_alloc ;

    /* is used to store the block size of that pool.   */
    /* Each csd type pool is divided in to # of blocks */
    kal_uint16     pdu_size;
    kal_uint16     full_blocks_available;
    kal_uint16     half_blocks_available;
} flc2_mb_fix_size_ctrl_header_struct ;


/*************************************************************************
 * Structures of pool info.
 *************************************************************************/
typedef void (*flc2_reg_callback_func_ptr)(flc2_thres_hit_enent_enum, flc2_pool_id_enum, void *);

typedef struct {

    kal_uint32  size;
    kal_uint8   size_upper_thre;
    kal_uint8   size_lower_thre;
    kal_uint8   pkt_no_upper_thre;
    kal_uint8   pkt_no_lower_thre;
    flc2_reg_callback_func_ptr reg_callback;
    flc2_mb_index_enum mb_index;
    kal_uint32  max_grow_size;
    kal_uint32  grow_step_size;
    kal_uint8   shrink_thre; /* threshold for shrink, percentage of size */
} flc2_profile_struct;

typedef struct {
    kal_uint32  total_size;
    kal_uint32  curr_occ_size;
    kal_uint32  size_upper_thre;
    kal_uint32  size_lower_thre;
    kal_uint16  pkt_no_upper_thre;
    kal_uint16  pkt_no_lower_thre;
    kal_uint16  total_req_counts;
    kal_uint16  total_not_available_counts;
    kal_uint16  curr_occ_pkt_no;
    kal_uint8   thres_reported; // 0xF0 means pkt_no_upper_thres to be reported, 0x0F means size upper thres to be reported
    kal_bool    wrong_config; 
    flc2_pool_id_enum     pool_id;
    flc2_shrink_mode_enum shrink_mode;
    void        *user_info_ptr;

} flc2_entity_struct;

typedef struct {
    kal_bool    is_pool_init; 
    kal_uint8   pool_entity_idx; 
#ifndef __MTK_TARGET__
    flc_pool_ut_status_enum  pool_status;
#endif
} flc2_pool_index_struct;

typedef struct {
    kal_uint32  max_occ_size;
    kal_uint32  max_req_size;
    kal_uint32  max_not_available_counts;
    kal_uint32  max_occ_pkt_no;
} flc2_pool_statistics_struct;

typedef struct flc_statistics_t{
    flc2_pool_statistics_struct flc_statistics[FLC2_POOL_TOTAL];
} flc_statistics_struct;



typedef struct {
    flc2_pool_id_enum pool_id;
    kal_uint8       api;
    kal_char        *filename; 
    kal_uint32      line;
    kal_char        *flc2_filename; 
    kal_uint32      flc2_line;
} flc2_user_info_struct;

typedef struct {
    kal_uint8                    mdi_id;
    flc2_debug_reason_enum       reason;
    flc2_entity_struct  *curr_active_pool_ptr;
    flc2_profile_struct  *curr_active_profile_ptr;
    flc2_mm_block_struct *curr_active_mb_ptr;
    
} flc2_debug_assert_info_struct;

typedef struct {
    flc2_entity_struct            *pool_info_ptr;
    flc2_debug_assert_info_struct *assert_info_ptr;
    flc2_user_info_struct          curr_user;
    kal_bool                       is_em_enable;
} flc2_context_info_struct;

/*************************************************************************
 * Macros of Pool
 *************************************************************************/
#define FLC2_POOL_IDX_INFO(_pool_id_, _field_) (flc2_pool_index_g[_pool_id_].##_field_)
#define FLC2_POOL_INFO(_pool_id_, _field_) (flc2_pool_g[flc2_pool_index_g[_pool_id_].pool_entity_idx].##_field_)
#define FLC2_PROFILE_INFO(_pool_id_, _field_) ((flc2_profile_g[flc2_pool_profile_g[_pool_id_]]).##_field_)

#define FLC2_POOL_STATISTIC(_pool_id_, _field_) (flc2_pool_statistics[_pool_id_].##_field_)

#define FLC2_INIT_POOL_PROTECT(_pool_id_) \
    kal_create_enh_mutex("P_M ## _pool_id_ ##");

#define FLC2_DELETE_POOL_PROTECT(_pool_id_) { \
    /* 2006/7/12 System Service removes API. */ \
    /* kal_delete_mutex(FLC2_POOL_INFO(_pool_id_, pool_mutex)); \ */ \
    /* FLC2_POOL_INFO(_pool_id_, pool_mutex) = NULL;\ */ \
}

/*************************************************************************
 * Macros of Memory Block
 *************************************************************************/

#define FLC2_MB_INFO(_mb_index_, _field_) \
    (flc2_mem_block_g[_mb_index_].##_field_)

#define FLC2_MB_COMMON_CTRL_HEADER(_mb_index_) \
    ((flc2_mm_info_struct *)(flc2_mem_block_g[_mb_index_].ctrl_header_ptr))

#define FLC2_MB_ADM_CTRL_HEADER(_mb_index_) \
    ((flc2_mb_adm_ctrl_header_struct *)(flc2_mem_block_g[_mb_index_].ctrl_header_ptr))

#define FLC2_MB_FIX_SIZE_CTRL_HEADER(_mb_index_, _field_) \
    (((flc2_mb_fix_size_ctrl_header_struct *)(flc2_mem_block_g[_mb_index_].ctrl_header_ptr))->##_field_)

#define FLC2_MB_AFM_CTRL_HEADER(_mb_index_) \
    ((flc2_mb_afm_ctrl_header_struct *)(flc2_mem_block_g[_mb_index_].ctrl_header_ptr))

#define FLC2_MB_MULTI_SIZE_CTRL_HEADER(_mb_index_) \
    ((flc2_mb_multi_size_ctrl_header_struct *)(flc2_mem_block_g[_mb_index_].ctrl_header_ptr))

#define FLC2_INIT_MB_PROTECT(_mb_index_) { \
    if ( FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex == NULL) \
        FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex = kal_create_enh_mutex("F_MB_ ## _mb_index_ ##");\
}

#define FLC2_DELETE_MB_PROTECT(_mb_index_) { \
    /* 2006/7/12 System Service removes API. */ \
    /* kal_delete_mutex(FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex) ;\ */ \
    /* FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex = NULL; \            */ \
}

#ifdef __MTK_FLC_LEAK_DETECT__
#define FLC2_BEGIN_MB_PROTECT_UT_ONLY(_mb_index_) { \
    kal_take_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex); \
}

#define FLC2_END_MB_PROTECT_UT_ONLY(_mb_index_) { \
    kal_give_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex); \
}
#endif

#define FLC2_BEGIN_MB_PROTECT(_mb_index_) { \
    /* kal_take_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex) */ \
}

#define FLC2_END_MB_PROTECT(_mb_index_) { \
   /* kal_give_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(_mb_index_)->mb_mutex) */ \
}

#define FLC2_BEGIN_POOL_PROTECT(_pool_id_) { \
    kal_take_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(FLC2_PROFILE_INFO(_pool_id_, mb_index))->mb_mutex);  \
}

#define FLC2_END_POOL_PROTECT(_pool_id_) { \
    kal_give_enh_mutex(FLC2_MB_COMMON_CTRL_HEADER(FLC2_PROFILE_INFO(_pool_id_, mb_index))->mb_mutex);  \
}


/*************************************************************************
 * Macros of Callback functionality
 *************************************************************************/
extern void flc2_npdu_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_npdu_dl_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);

extern void flc2_appdu_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_appdu_dl_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_cspdu_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_cspdu_dl_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_pspdu_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_pspdu_dl_ack_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_pspdu_dl_unack_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_spdu_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_spdu_dl_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
#if 0
/* under construction !*/
/* under construction !*/
#endif
extern void flc2_tpdu_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_irda_ul_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_cipher_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);

extern void flc2_npdu_dl_callback_ratdm(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);
extern void flc2_sdu_dl_callback_ratdm(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);

extern void flc2_spdu_hs_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr);

/* Eric Hsieh: 20091107, apply new compile option for WAP over CSD */
#if defined(__TCPIP_OVER_CSD__) || defined(__EXT_MODEM__)
#define flc2_ent_appdu_ul_callback flc2_appdu_ul_callback 
#define flc2_ent_appdu_dl_callback flc2_appdu_dl_callback 
#else
#define flc2_ent_appdu_ul_callback NULL 
#define flc2_ent_appdu_dl_callback NULL 
#endif

#ifdef CSD_SUPPORT
#define flc2_ent_cspdu_ul_callback flc2_cspdu_ul_callback
#define flc2_ent_cspdu_dl_callback flc2_cspdu_dl_callback
#else
#define flc2_ent_cspdu_ul_callback NULL
#define flc2_ent_cspdu_dl_callback NULL
#endif

#ifdef __PS_SERVICE__ 
#define flc2_ent_npdu_ul_callback flc2_npdu_ul_callback
#else
#define flc2_ent_npdu_ul_callback NULL
#endif

#ifdef __PS_SERVICE__ 

#define flc2_ent_npdu_dl_callback flc2_npdu_dl_callback_ratdm

#else  /* __PS_SERVICE__ */

#define flc2_ent_npdu_dl_callback NULL
#endif /* __PS_SERVICE__ */

#ifdef __PS_SERVICE__ 
#define flc2_ent_pspdu_ul_callback flc2_pspdu_ul_callback
#define flc2_ent_pspdu_dl_ack_callback flc2_pspdu_dl_ack_callback
#define flc2_ent_cipher_callback flc2_cipher_callback
#else
#define flc2_ent_pspdu_ul_callback    NULL
#define flc2_ent_pspdu_dl_ack_callback NULL
#define flc2_ent_cipher_callback NULL
#endif

#ifdef __TCPIP__
#define flc2_ent_spdu_ul_callback flc2_spdu_ul_callback
#define flc2_ent_spdu_dl_callback flc2_spdu_dl_callback
#define flc2_ent_tpdu_callback flc2_tpdu_callback
#else
#define flc2_ent_spdu_ul_callback NULL
#define flc2_ent_spdu_dl_callback NULL
#define flc2_ent_tpdu_callback NULL
#endif

#if defined(__HOTSPOT_SUPPORT__) && defined(__MTK_TARGET__)
#define flc2_ent_hs_callback flc2_spdu_hs_callback
#else
#define flc2_ent_hs_callback NULL
#endif

#ifdef __IRDA_SUPPORT__
#define flc2_ent_irda_ul_callback flc2_irda_ul_callback
#else
#define flc2_ent_irda_ul_callback NULL
#endif

/*************************************************************************
 * Globals
 *************************************************************************/

extern flc2_profile_struct flc2_profile_g[] ; 
extern flc2_mm_block_struct    flc2_mem_block_g[];

#if defined(FLC2_RECONFIG_ON) || defined(FLC2_UNITTEST)
extern flc2_profile_index_enum flc2_pool_profile_g[] ; 
#else
extern const flc2_profile_index_enum flc2_pool_profile_g[] ; 
#endif

extern flc2_entity_struct      flc2_pool_g[];
extern flc2_pool_index_struct flc2_pool_index_g[];
extern flc2_context_info_struct *flc2_context_ptr;

#endif /* _FLC2_ENTITY_CONFIG_H */

