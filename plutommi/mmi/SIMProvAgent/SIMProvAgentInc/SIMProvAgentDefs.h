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
 *  SIMProvAgentDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SIM Provisioning Agent Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_SPA_DEFS_H
#define MMI_SPA_DEFS_H

#ifdef __SPA_SUPPORT__

#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "sim_common_enums.h"
#include "SIMProvAgentConfig.h"
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
#include "ProvBoxSrvGprot.h"
#endif


#include "SIMProvAgentConst.h"

/* For SIM status notification */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 sim_id;
    kal_uint8 sim_inserted;     /* sim inserted status:¡¡¡¡¡¡mmi_spa_sim_id_enum£¨only sim1, sim2, dual_sim, no_sim) */
    kal_uint8 setting_mode;     /* dual sim setting mode:     mmi_spa_sim_id_enum (only sim1, sim2, dual_sim, flight_mode) */
    kal_uint8 sim1_can_read;    /* is sim can read: MMI_TRUE or MMI_FALSE, if sim is not insert or unopened, please set it to MMI_FALSE, SPA  */
    kal_uint8 sim2_can_read;
    kal_uint8 sim1_type;        /* mmi_spa_sim_type_enum,   if sim is not insert or unopened, please set it to unknown_type */
    kal_uint8 sim2_type;
} mmi_spa_sim_status_info_ind_struct;

typedef struct
{
    U16 sim_id;
    U8 *buf;
    U16 file_size;  /* length of total data */
    U16 rec_num;    /* record number */
    U16 read_len;
    mmi_spa_result_enum result;
} mmi_spa_ef_read_result_struct;

typedef struct
{
    U16 sim_id;
    S32 hconfig;
    mmi_spa_result_enum result;
} mmi_spa_sim_ef_process_result_struct;

/* typedef void (*spa_ef_handle_read_callback_fn)(mmi_spa_result_enum); */
typedef void (*spa_sim_ef_read_callback_fn) (mmi_spa_ef_read_result_struct *read_param);
typedef void (*spa_sim_ef_parse_callback_fn) (S32 hRoot, mmi_spa_result_enum result);
typedef void (*spa_sim_ef_process_callback) (mmi_spa_sim_ef_process_result_struct *result);
typedef mmi_spa_check_ef_status_result_enum(*spa_sim_ef_status_check_fn) (mmi_spa_sim_id_enum sim_id);
typedef mmi_spa_result_enum(*spa_sim_ef_read_fn) (mmi_spa_sim_id_enum sim_id, sim_file_index_enum file_idx,
                                                  mmi_spa_ef_type_enum type, spa_sim_ef_read_callback_fn callback);
typedef mmi_spa_result_enum(*spa_sim_ef_parse_fn) (void *parse_param, spa_sim_ef_parse_callback_fn callback);

#ifdef MMI_SPA_JOB_SUPPORT

typedef struct mmi_spa_ef_process_job_node_struct_tag
{
    U8 ef_info_table_index;
    mmi_spa_job_type_enum type;
    mmi_spa_job_state_enum state;
    mmi_spa_sim_id_enum sim_id;
    U32 msg_id;
    U32 trans_id;
    U32 src_trans_id;
    struct mmi_spa_ef_process_job_node_struct_tag *next;
} mmi_spa_ef_process_job_node_struct;

typedef struct
{
    mmi_spa_ef_process_job_node_struct *head;
    mmi_spa_ef_process_job_node_struct *cur_job;
} mmi_spa_ef_process_job_list;

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

typedef struct
{
    /* U32 save_timestamp; */
    U32 install_timestamp;
    mmi_provbox_msg_config_status_struct msg_config_status;
} mmi_spa_ef_msg_info_struct;

typedef struct
{
    mmi_spa_ef_msg_info_struct *sim1_info;
    mmi_spa_ef_msg_info_struct *sim2_info;
} mmi_spa_provbox_msg_info_struct;

typedef struct
{
    sim_file_index_enum file_index;
} mmi_spa_provbox_app_data_struct;

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
#endif /* MMI_SPA_JOB_SUPPORT */ 

typedef struct
{
    U8 *buf;
    U16 file_len;
    U16 rec_num;
    U16 rec_size;
    spa_sim_ef_read_callback_fn read_callback;
    mmi_spa_ef_read_state_enum status;
    mmi_spa_sim_id_enum sim_id;
    sim_file_index_enum file_idx;
    mmi_spa_ef_type_enum file_type;
} mmi_spa_read_context_struct;

typedef struct
{
    S32 hApp;
    S32 hNap;
    S32 hProxy;
    S32 *node_buf;
    S32 node_buf_max_count;
    S32 node_buf_used_count;
} mmi_spa_parser_mmsicp_data_struct;

typedef struct
{
    U8 *data;                                       /* file data */
    U32 processed_len;                              /* length of processed data */
    S32 file_size;                                  /* length of total data */
    S32 rec_len;                                    /* record size */
    S32 rec_num;                                    /* record number */
    S32 file_pos;                                   /* current processed file position */
    S32 hRoot;
    void *app_data;
    spa_sim_ef_parse_callback_fn callback;
    mmi_spa_ef_type_enum file_type;
    //S32 temp_root;
    //S32 cur_node;                                 /* current processed node*/
    //S32 cca_node_buf[MMI_SPA_MAX_NODE_BUF_LEN];   /* for generating sub node and tracking parent node*/
} mmi_spa_parser_context_struct;

typedef struct
{
    U16 sim_last_flags;
    U16 sim_cur_flags;
    U8 read;
    U8 sim1_last_insert;
    U8 sim1_last_status;
    U8 sim2_last_insert;
    U8 sim2_last_status;
    U8 sim1_cur_insert;
    U8 sim1_cur_status;
    U8 sim2_cur_insert;
    U8 sim2_cur_status;
    U8 sim1_last_ok;
    U8 sim2_last_ok;
    U8 sim1_ok;
    U8 sim2_ok;
    U8 sim1_changed;
    U8 sim2_changed;
} mmi_spa_sim_changed_data;

typedef struct
{
    U32 sim_flag;                                   /* flag bit mask */
    S32 hConfig;
    U8 sim_status;                                  /* sim number inserted to the SIM slot, from SIM notify */
    U8 sim_setting_mode;                            /* dual sim mode, from SIM notify */
    U8 sim1_type;
    U8 sim2_type;
    U8 queue_sim_info_notify;                       /* if has new sim notify when processing */
    U8 sim1_read_retry_count;
    U8 sim2_read_retry_count;
    U8 cca_ready;                                   /* if CCA is ready */
    mmi_spa_sim_id_enum sim_id;                     /* SIM1 or SIM2 */
    mmi_spa_sim_id_enum sim_notified;               /* Which SIM status have been notified. SIM1, SIM2 or DUAL_SIM */
    mmi_spa_process_state_enum sim_process_status;  /* status */
    mmi_spa_sim_changed_data sim_changed_data;
#ifdef MMI_SPA_JOB_SUPPORT
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    U8 saved_flag_init;
#endif 
#endif /* MMI_SPA_JOB_SUPPORT */ 
} mmi_spa_context_struct;

typedef struct
{
    sim_type_query_enum sim_type;       /* SIM or USIM */
    sim_file_index_enum ef_file_idx;    /* EF file index */
    mmi_spa_ef_type_enum ef_file_type;
#ifndef MMI_SPA_JOB_SUPPORT
    U32 ef_file_processed_flag;
#endif 
    spa_sim_ef_status_check_fn ef_status_checker;
    spa_sim_ef_read_fn ef_reader;
    spa_sim_ef_read_callback_fn ef_reader_callback;
    spa_sim_ef_parse_fn ef_parser;
    spa_sim_ef_parse_callback_fn ef_parser_callback;
#ifdef MMI_SPA_JOB_SUPPORT
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    U16 ef_sim1_saved_flag_mask;
    U16 ef_sim2_saved_flag_mask;
#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 
    U8 ef_processed_flag;
    U8 ef_job_state_flag;               /* sim1 saving, sim2 saving, sim1 installing, sim2 installing */
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    mmi_spa_provbox_msg_info_struct ef_msg_info;
#endif 
#endif /* MMI_SPA_JOB_SUPPORT */ 
} mmi_spa_ef_table_item_struct;

typedef struct
{
    U16 value;
    U16 ccaValSymbol;
} mmi_spa_value_conv_struct;

typedef struct
{
    S32 simpSymbol;
    U16 ccaSymbol;
    mmi_spa_convt_type_enum type;
    mmi_spa_value_conv_struct *enumTable;
    U16 enumTableSize;
} mmi_spa_cca_conversion_struct;

typedef struct
{
    U8 *buf;
    S32 len;
    S32 hRoot;
} mmi_spa_sim_mmsicp_parse_param_struct;

#endif /* __SPA_SUPPORT__ */ 
#endif /* MMI_SPA_DEFS_H */ 

