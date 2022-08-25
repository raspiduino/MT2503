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
 *   flc2_ent_functions.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _FLC2_ENT_FUNCTIONS_H
#define _FLC2_ENT_FUNCTIONS_H

#ifndef __LOW_COST_SUPPORT_COMMON__
//#define __FLC2_NEWLINE_SUPPORT__
#endif

#include "flc2_config.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "stack_common.h"

/*************************************************************************
 * Constants
 *************************************************************************/
#define FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED 0x01
#define FLC2_ENT_SIZE_UPPER_THRES_TO_BE_REPORTED 0x00
#define FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED 0x10
#define FLC2_ENT_PKT_NO_UPPER_THRES_TO_BE_REPORTED 0x00

#define FLC2_ENT_MARK_SIZE_U_THRES_REPORTED(_pool_id_) FLC2_POOL_INFO(_pool_id_, thres_reported) |= FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED;
#define FLC2_ENT_MARK_PKT_NO_U_THRES_REPORTED(_pool_id_) FLC2_POOL_INFO(_pool_id_, thres_reported) |= FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED;

#define FLC2_ENT_MARK_SIZE_U_THRES_NOT_REPORTED(_pool_id_) FLC2_POOL_INFO(_pool_id_, thres_reported) &= 0xF0;
#define FLC2_ENT_MARK_PKT_NO_U_THRES_NOT_REPORTED(_pool_id_) FLC2_POOL_INFO(_pool_id_, thres_reported) &= 0x0F;

#define FLC2_ENT_IS_SIZE_U_THRES_REPORTED(_pool_id_) (((FLC2_POOL_INFO(_pool_id_, thres_reported) & 0x0F) == FLC2_ENT_SIZE_UPPER_THRES_ALREADY_REPORTED) ? (KAL_TRUE):(KAL_FALSE))
#define FLC2_ENT_IS_PKT_NO_U_THRES_REPORTED(_pool_id_) (((FLC2_POOL_INFO(_pool_id_, thres_reported) & 0xF0) == FLC2_ENT_PKT_NO_UPPER_THRES_ALREADY_REPORTED) ? (KAL_TRUE):(KAL_FALSE))

#ifdef __FLC2_NEWLINE_SUPPORT__
#define FLC2_NUM_MEM_NEWLINE_TRC 4
#define FLC2_MASK_MEM_NEWLINE_TRC 0x03

typedef struct flc2_get_mem_newline_trc_struct
{
    kal_uint32          curr_occ_size;
    kal_uint32          total_size;
    kal_uint32          size_used;
    void *              ret_ptr; 
    flc2_pool_id_enum   pool_id;
    kal_uint32          time_stamp;
} flc2_get_mem_newline_trc_struct;

typedef struct flc2_free_mem_newline_trc_struct
{
    kal_uint32          curr_occ_size;
    kal_uint32          total_size;
    void *              free_ptr; 
    flc2_pool_id_enum   pool_id;
    kal_uint32          time_stamp;
} flc2_free_mem_newline_trc_struct;

extern kal_uint8 flc2_num_get_peer_buff_trc;
extern kal_uint8 flc2_num_free_peer_buff_trc;
extern flc2_get_mem_newline_trc_struct flc2_get_mem_newline_trc[FLC2_NUM_MEM_NEWLINE_TRC];
extern flc2_free_mem_newline_trc_struct flc2_free_mem_newline_trc[FLC2_NUM_MEM_NEWLINE_TRC];
#endif

typedef void * (*flc2_alloc_func_ptr)(flc2_pool_id_enum, flc2_mb_index_enum, kal_uint32, kal_uint32 *);

/*************************************************************************
 * FLC2 API prototype
 *************************************************************************/

#ifdef __LOW_COST_SUPPORT_COMMON__

#define flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_) \
        flc2_ent_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_)

#define flc2_free_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_free_peer_buff(_pool_id_, _buff_ptr_)

#define flc2_init_pool(_pool_id_) flc2_ent_init_pool(_pool_id_)
#define flc2_deinit_pool(_pool_id_) flc2_ent_deinit_pool(_pool_id_)

#define flc2_grow_pool_with_shrink_mode( _pool_id_, _req_size_, _total_size_, _shrink_mode_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, _shrink_mode_)

#define flc2_grow_pool( _pool_id_, _req_size_, _total_size_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, FLC2_SHRINK_AUTO)

#define flc2_shrink_pool( _pool_id_) \
        flc2_ent_shrink_pool( _pool_id_)

#define flc2_check_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_check_peer_buff(_pool_id_, _buff_ptr_)

#define flc2_config_user_info(_pool_id_, _user_info_ptr_)  \
        flc2_ent_config_user_info(_pool_id_, _user_info_ptr_)  

#define flc2_reset_user_info(_pool_id_)  flc2_ent_reset_user_info(_pool_id_)  
#define flc2_get_user_info(_pool_id_)  flc2_ent_get_user_info(_pool_id_)

#else


#define flc2_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_) \
        flc2_ent_get_peer_buff(_pool_id_, _pdu_len_, _header_size_, _tail_size_, __FILE__, __LINE__)

#define flc2_free_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_free_peer_buff(_pool_id_, _buff_ptr_, __FILE__, __LINE__)

#define flc2_init_pool(_pool_id_) flc2_ent_init_pool(_pool_id_, __FILE__, __LINE__)
#define flc2_deinit_pool(_pool_id_) flc2_ent_deinit_pool(_pool_id_, __FILE__, __LINE__)

#define flc2_grow_pool_with_shrink_mode( _pool_id_, _req_size_, _total_size_, _shrink_mode_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, _shrink_mode_, __FILE__, __LINE__)

#define flc2_grow_pool( _pool_id_, _req_size_, _total_size_) \
        flc2_ent_grow_pool( _pool_id_, _req_size_, _total_size_, FLC2_SHRINK_AUTO, __FILE__, __LINE__)

#define flc2_shrink_pool( _pool_id_) \
        flc2_ent_shrink_pool( _pool_id_, __FILE__, __LINE__)

#define flc2_check_peer_buff(_pool_id_, _buff_ptr_) \
        flc2_ent_check_peer_buff(_pool_id_, _buff_ptr_, __FILE__, __LINE__)

#define flc2_config_user_info(_pool_id_, _user_info_ptr_)  \
        flc2_ent_config_user_info(_pool_id_, _user_info_ptr_, __FILE__, __LINE__)  

#define flc2_reset_user_info(_pool_id_)  flc2_ent_reset_user_info(_pool_id_, __FILE__, __LINE__)  
#define flc2_get_user_info(_pool_id_)  flc2_ent_get_user_info(_pool_id_, __FILE__, __LINE__)  

#endif

#define flc2_query_pool(_pool_id_, _total_size_, _available_half_blocks_, _available_full_blocks_) \
        flc2_ent_query_pool(_pool_id_, _total_size_, _available_half_blocks_, _available_full_blocks_)

#define flc2_reconfig_pool(_pool_id_, _profile_index_)  
        /* flc2_ent_reconfig_pool(_pool_id_, _profile_index_, __FILE__, __LINE__) */

#ifdef __LOW_COST_SUPPORT_COMMON__

extern kal_bool flc2_ent_init_pool(flc2_pool_id_enum pool_id);
extern kal_bool flc2_ent_deinit_pool(flc2_pool_id_enum pool_id);

extern kal_bool flc2_ent_grow_pool(flc2_pool_id_enum pool_id, kal_uint32 req_size, kal_uint32 *total_size,
                                   flc2_shrink_mode_enum shrink_mode);

extern kal_bool flc2_ent_shrink_pool(flc2_pool_id_enum pool_id);


extern void* flc2_ent_get_peer_buff(flc2_pool_id_enum pool_id, kal_uint16 pdu_len, 
                                    kal_uint16 header_size, kal_uint16 tail_size);

extern void flc2_ent_free_peer_buff(flc2_pool_id_enum pool_id, peer_buff_struct* buff_ptr);

extern kal_bool flc2_ent_config_user_info(flc2_pool_id_enum pool_id, void *user_info_ptr);

extern void* flc2_ent_reset_user_info(flc2_pool_id_enum pool_id);

extern void* flc2_ent_get_user_info(flc2_pool_id_enum pool_id);

extern kal_bool flc2_ent_check_peer_buff(flc2_pool_id_enum pool_id, peer_buff_struct *buff_ptr);

#else

extern kal_bool flc2_ent_init_pool(flc2_pool_id_enum pool_id, kal_char *filename, kal_uint32 line);
extern kal_bool flc2_ent_deinit_pool(flc2_pool_id_enum pool_id, kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_grow_pool(flc2_pool_id_enum pool_id, kal_uint32 req_size, kal_uint32 *total_size,
                                   flc2_shrink_mode_enum shrink_mode, kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_shrink_pool(flc2_pool_id_enum pool_id, kal_char *filename, kal_uint32 line);


extern void* flc2_ent_get_peer_buff(flc2_pool_id_enum pool_id, kal_uint16 pdu_len, 
                                    kal_uint16 header_size, kal_uint16 tail_size, 
                                    kal_char *filename, kal_uint32 line);

extern void flc2_ent_free_peer_buff(flc2_pool_id_enum pool_id, peer_buff_struct* buff_ptr,
                                    kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_config_user_info(flc2_pool_id_enum pool_id, void *user_info_ptr,
                                          kal_char *filename, kal_uint32 line);

extern void* flc2_ent_reset_user_info(flc2_pool_id_enum pool_id, kal_char *filename, kal_uint32 line);

extern void* flc2_ent_get_user_info(flc2_pool_id_enum pool_id, kal_char *filename, kal_uint32 line);

extern kal_bool flc2_ent_check_peer_buff(flc2_pool_id_enum pool_id, peer_buff_struct *buff_ptr,
                              kal_char *filename, kal_uint32 line);

#endif

extern void flc2_send_ilm ( module_type dest_mod_id, msg_type msg_id, sap_type sap_id,
                     local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

extern void flc2_ent_init_peer_buff(void *buff_ptr, kal_uint16 pdu_len,
                                    kal_uint16 header_size, kal_uint16 tail_size);

extern kal_uint32 flc2_ent_query_pool(flc2_pool_id_enum pool_id, kal_uint32 *total_size, 
                                      kal_uint32 *available_half_blocks, kal_uint32 *available_full_blocks);

extern kal_bool flc2_ent_reconfig_pool_profile(flc2_pool_id_enum pool_id, flc2_profile_index_enum profile_index);


extern void flc2_ent_reconfig_profile_params(flc2_pool_id_enum pool_id, kal_uint32  size,
                                      kal_uint8   size_upper_thre, kal_uint8   size_lower_thre,
                                      kal_uint8   pkt_no_upper_thre, kal_uint8   pkt_no_lower_thre,
                                      kal_uint16  max_grow_size, kal_uint16  grow_step_size,
                                      kal_uint8   shrink_thre);


extern kal_bool flc2_get_spdu_info(kal_uint8 dir,
                            kal_uint32 *pdu_block_size,
                            kal_uint32 *pdu_total_size);

#ifdef FLC2_RECONFIG_ON
extern kal_bool flc2_ent_reconfig_pool_profile(flc2_pool_id_enum pool_id, flc2_profile_index_enum profile_index);
extern void flc2_ent_reconfig_profile_params(flc2_pool_id_enum pool_id, kal_uint32  size,
                                      kal_uint8   size_upper_thre, kal_uint8   size_lower_thre,
                                      kal_uint8   pkt_no_upper_thre, kal_uint8   pkt_no_lower_thre,
                                      kal_uint16  max_grow_size, kal_uint16  grow_step_size,
                                      kal_uint8   shrink_thre);

extern kal_bool flc2_ent_reconfig_single_pool(flc2_pool_id_enum pool_id, flc2_profile_index_enum profile_index);
#endif

#endif /* _FLC2_ENT_FUNCTIONS_H */
