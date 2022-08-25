/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   med_vid_clip_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of media task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _MED_VID_CLIP_STRUCT_H_
#define _MED_VID_CLIP_STRUCT_H_

#include "kal_general_types.h"
#include "stack_config.h"

typedef void* (*alloc_mem_fun_p)(kal_uint8 mem_type, kal_uint32 mem_size, char* file_p, long line_p);
typedef void (*free_mem_fun_p)(kal_uint8 mem_type, void **mem_addr, char* file_p, long line_p);


typedef struct
{
    LOCAL_PARA_HDR    
    kal_uint32  start_time;      // start point to clip of source file, unit is ms
    kal_uint32  end_time;        // end point to clip of source file, unit is ms
    void*  src_filepath;    // source file path
    void*  dst_filepath;    // destination file path
    void*  work_filepath;   // working file path

} media_vid_clip_prepare_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;       /**< the parameter ID. */
    kal_uint32* value;      /**< the parameter value */
} media_vid_clip_get_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    alloc_mem_fun_p alloc_mem;
    free_mem_fun_p free_mem;
    
} media_vid_clip_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;    
} media_vid_clip_start_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
} media_vid_clip_stop_req_struct, media_vid_clip_close_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_vid_clip_prepare_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_clip_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
    kal_int32 cause;
}
media_vid_clip_event_ind_struct;

#endif/* _MED_VID_CLIP_STRUCT_H_*/ 
