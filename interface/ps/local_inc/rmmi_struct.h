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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   rmmi_strcut.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __RMMI_STRUCT_H__
#define __RMMI_STRUCT_H__
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
//#include "l4c_common_enum.h"
#include "ps_public_enum.h"
 
typedef struct{
	kal_uint8 ref_count;
	kal_uint16 data_length;  
	kal_uint8 data[256];
} rmmi_inject_msg_req_struct;

typedef struct{
	kal_uint8 ref_count;
	kal_uint16 data_length;
	kal_uint8 data[256];
} rmmi_inject_msg_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} rmmi_atcidt_force_transfer_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port;   
    kal_bool is_dt; 
} rmmi_atcidt_force_transfer_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    rmmi_sim_uart_setting_enum sim_setting;
} rmmi_master_sim_change_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;   
} rmmi_master_sim_change_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ch_num;   
} rmmi_register_channel_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 begin_port_id;   
} rmmi_register_channel_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port_id;
    kal_uint16 length;   
} rmmi_exe_at_req_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 port_id;
} rmmi_exe_at_cnf_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 port_id;
    kal_uint16 length;   
} rmmi_response_at_ind_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 length;   
} rmmi_urc_at_ind_struct;

typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool lock; //KAL_TRUE: lock, KAL_FALSE: unlock
} rmmi_lock_at_cmd_req_struct;

 typedef struct{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result; //KAL_TRUE: success, KAL_FALSE: fail
} rmmi_lock_at_cmd_cnf_struct;

#ifdef __GAS_SUPPORT__
 /* Message Structure */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 data[1500];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint16 buf_size;                                  /* avariable size of the output buffer */
} gas_data_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 data[1500];  /* data  */
    kal_uint16 size;                                        /* size of the input data */
    kal_uint8 data_type;                                /* gati_output_data_type_enum */
} gas_data_req_struct;


typedef enum
{
    GAS_OUTPUT_NORMAL,     /* The type of output data is normal type which might be partially put to the output buffer of the ATCI */
    GAS_OUTPUT_URC,            /* The type of output data is a URC. Note that this type of data is an integrity type implicitly. */
} gas_output_data_type_enum;
#endif /*__GAS_SUPPORT__*/

#endif
