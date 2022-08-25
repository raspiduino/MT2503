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
 *
 * Filename:
 * ---------
 *   dcmgr_comp.h
 *
 * Project:
 * --------
 *   MAUI (MT6260)
 *
 * Description:
 * ------------
 *   Dynamic Code Compression for dynamic code relocation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __DCMGR_COMP_H__
#define __DCMGR_COMP_H__

#include "kal_general_types.h"
#include "SSF_ROMInfo_type.h"
#include  "dcmgr.h"

#define DCMGR_MAX_NUM           (DYNAMIC_CODE_COMPRESS_NUM)


#if defined(__DCM_MULTITRUNK__)
typedef struct trunk_info_t {
	
	kal_uint16 dcmgr_img_id;
	kal_uint16 dcmgr_trunk_state;
	kal_uint32 dcmgr_comp_base;
	kal_uint32 dcmgr_exec_base;
	kal_uint32 dcmgr_comp_size;
	kal_uint32 dcmgr_trunk_size;
	struct trunk_info_t * next;
	
} dcmgr_trunk_info_t;

#endif /* __DCM_MULTITRUNK__ */

 /*
  * Header for compressed DCM image loading information
  */

typedef struct {
#if defined(__DCM_MULTITRUNK__)
	kal_uint16						dcmgr_img_id;
    kal_uint8						dcmgr_pool;
    kal_uint8						dcmgr_group;
	kal_uint32                      dcmgr_img_exec_base;
#else
	kal_uint32						dcmgr_img_id;
	kal_uint32                      dcmgr_img_exec_base;
	kal_uint32						dcmgr_img_zi_base;
	kal_uint32						dcmgr_img_zi_size;
#endif /* __DCM_MULTITRUNK__ */
} dcmgr_image_load_info_t;

 /*
  * Header for compressed DCM image loading information
  */

typedef struct {
    dcmgr_image_load_info_t         dcmgr_exec_info;
    kal_uint32                      dcmgr_bin_size;
    kal_uint32                      dcmgr_comp_size;
    kal_uint32                      dcmgr_file_pos;
} dcmgr_image_decomp_info_t;

 /*
  * Header for compressed DCM image group file
  */
 
typedef struct {
    kal_uint32                      dcmgr_hdr_id1;
    kal_uint32                      dcmgr_hdr_id2;
    kal_char                        dcmgr_project_id[64];
    kal_char                        dcmgr_platform_id[64];
    kal_uint32                      dcmgr_img_num;
    dcmgr_image_decomp_info_t       dcmgr_img_list[DCMGR_MAX_NUM+1];
} dcmgr_comp_header_t;

 /*
  * Header for uncompressed DCM image
  * The identifier string in header is "DCM_COMPRESS_CANDIDATE_HDR_V01".
  */
#define DCMGR_COMPRESS_ID "DCM_COMPRESS_CANDIDATE_HDR_V01"

typedef struct {
    MTK_ROMInfo_Super_Header_v1_ST  dcmgr_img_header;
    dcmgr_image_load_info_t         dcmgr_img_info;
} dcmgr_image_header_t;


typedef void (*load_func_ptr)(kal_uint32*, kal_uint32*, kal_int32, kal_uint32);

/*
 * magic number definition
 */

#define DCMGR_KEY_ID_HEAD   (0x474D4344)
#define DCMGR_KEY_ID_TAIL   (0x59444F42)
#define DCMGR_KEY_ID_DUMMY  (0x45514D44)

/*
 * decompression memory buffer size
 */

#define DCMGR_DECOMP_BUFF_SIZE (16*1024)

#define DCMGR_COMP_SEARCH_RANGE (0x10000)

/*
 * buffer for DCM trunk information, at most 128 trunk now
 * 16 bytes for dcmgr_trunk_info_t
 */
#if defined(__DCM_MULTITRUNK__)

#define MAX_TRUNK_NUM (128)

#define DCMGR_TRUNK_INFO_STRUCT_SIZE (sizeof(dcmgr_trunk_info_t))

#define DCMGR_TRUNK_INFO_BUFF_SIZE (DCMGR_TRUNK_INFO_STRUCT_SIZE * MAX_TRUNK_NUM)

#endif /* __DCM_MULTITRUNK__ */

/*
 * Macros definition
 */
#define DCMGR_ENTER_CRITICAL_SECTION     if((kal_query_systemInit() == KAL_TRUE) || (INT_QueryExceptionStatus() == KAL_TRUE)) \
                                         {                                                                                    \
                                              demgr_lock_count--;                                                             \
                                         }                                                                                    \
                                         else                                                                                 \
                                         {                                                                                    \
                                         	  kal_take_enh_mutex(g_dcmgr_mutex);                                                \
                                         }                                                                                    \
                                 
#define DCMGR_LEAVE_CRITICAL_SECTION     if((kal_query_systemInit() == KAL_TRUE) || (INT_QueryExceptionStatus() == KAL_TRUE)) \
                                         {                                                                                    \
                                            demgr_lock_count++;                                                               \
                                         }                                                                                    \
                                         else                                                                                 \
                                         {                                                                                    \
                                         	  kal_give_enh_mutex(g_dcmgr_mutex);                                                \
                                         }                                                                                    \

#endif /* __DCMGR_COMP_H__ */
