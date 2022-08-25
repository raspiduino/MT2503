/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ConnectManageProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  These are the internal interfaces and structures used by connection management application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CONNECT_MANAGE_PROT_H
#define CONNECT_MANAGE_PROT_H

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "CnmgrSrvGprot.h"
#include "CnmgrSrvIprot.h"
#include "DataAccountGProt.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_CNMGR_TRC_GROUP MMI_CONN_TRC_INFO
#define MMI_CNMGR_MAX_PROFILE_NAME_LEN (MAX_DATA_ACCOUNT_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN + 1)
#define MMI_CNMGR_MAX_DATA_SIZE_STR_LEN 31
#define MMI_CNMGR_DATA_UNIT_SIZE 1024
#define MMI_CNMGR_HOUR_TO_SEC 3600
#define MMI_CNMGR_MIN_TO_SEC 60


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/* This structure is used for bearer info */
typedef struct
{
    U64 all_data_size;
    U64 connect_time;
    U32 account_id;
    U8 connect_type;
    U8 dialup_type;
    CHAR profile_name[MMI_CNMGR_MAX_PROFILE_NAME_LEN * ENCODING_LENGTH];
    CHAR data_size_str[(MMI_CNMGR_MAX_DATA_SIZE_STR_LEN + 1) * ENCODING_LENGTH];
} mmi_cnmgr_bearer_node_struct;

/* This structure is used for bearer list */
typedef struct
{
    mmi_cnmgr_bearer_node_struct bearer[SRV_CNMGR_MAX_BEARER_NUM];
    U8 bearer_num;
} mmi_cnmgr_bearer_list_struct;

/* This structure is used to record the information needed by bearer detail info screen. */
typedef struct 
{
    U32 account_id;
    U8 connect_type;
    U8 dialup_type;
    srv_cnmgr_bearer_data_struct bearer_data;
} mmi_cnmgr_bearer_detail_info_struct;

/* CNMGR context structure */
typedef struct
{
    mmi_id grp_id;
    U16 wap_icon_id;
    U8 list_select_idx;
    U8 list_highlight_idx;
    MMI_BOOL enter_from_wap;
    MMI_BOOL reg_bearer_update_callback;
    mmi_cnmgr_bearer_detail_info_struct select_bearer;
} mmi_cnmgr_context_struct;


/***************************************************************************** 
 * External interfaces
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_cnmgr_entry_bearer_list_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of Conn. management menu item in Connectivity screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_cnmgr_entry_bearer_list_highlight_hdlr(void);


#endif /* CONNECT_MANAGE_PROT_H */
