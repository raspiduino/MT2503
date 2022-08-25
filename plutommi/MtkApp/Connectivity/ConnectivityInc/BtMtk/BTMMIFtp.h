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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  BTMMIFtp.h
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#ifndef __BT_MMI_FTP_SCR_H__
#define __BT_MMI_FTP_SCR_H__

/***************************************************************************** 
* Predefine header checking
*****************************************************************************/
// RHR: add
#include "MMI_features.h"
#include "MMIDataType.h"
#include "bluetooth_struct.h"
// RHR: add

//#include "Custom_events_notify.h"
#include "FtpSrvGprots.h"


/******************************************************************************
    Enum Value
******************************************************************************/

/******************************************************************************
    MMI FTP SCR CONTEXT
******************************************************************************/
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#ifdef __MMI_FTC_SUPPORT__

#define MMI_FTP_NOTY_STR_SIZE  (40)
#define MMI_FTPC_MAX_RECV_PATH (64)

/* identify the download type */
typedef enum
{
    MMI_FTP_PULL_TYPE_NONE,
    MMI_FTP_PULL_TYPE_SINGLE,
    MMI_FTP_PULL_TYPE_MULTI,
    MMI_FTP_PULL_TYPE_ALL,
    MMI_FTP_PULL_TYPE_MAX
} mmi_ftp_pull_type_enum;

//#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
#define MMI_FTPC_MULPULL_LIST_INIT (100)
#define MMI_FTPC_MULPULL_LIST_INC  (50)
#define MMI_FTPC_MULPULL_LIST_MAX  (2000/2) /* restirct by ctrl buffer */

typedef struct
{
    /* the file indexs in file browser of current path */
    U16* p_obj_indexs_in_folder;

    /* size of download list */
    U16 list_capability;

    /* count of objs in download list */
    U16 list_obj_cnt;
} mmi_ftpc_download_list;
//#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */ 

#endif /* __MMI_FTC_SUPPORT__ */ 

/******************************************************************************
    MMI FTP SCR CONTEXT
******************************************************************************/
typedef struct
{
#ifdef __MMI_FTC_SUPPORT__
    U16 sel_obj_id;

    //U16 sel_obj_details_id;

    srv_ftp_entity_struct obj_entity;

#ifdef __MMI_FTC_MULTIPULL_SUPPORT__
    /* download list structure */
    mmi_ftpc_download_list download_list;

    /* current file id in parsed-fodler-content file, only used in pull-all, for find the file name */
    //U16 curent_file_id;

    U16 mark_several_highlight_index;
#endif /* __MMI_FTC_MULTIPULL_SUPPORT__ */

    /* pull type: single, multi, all */
    U8 pull_type;

    /* count of objs have received */
    U16 received_obj_cnt;

    U16 failed_obj_cnt;

    S32 ftpc_srv_hd;

    S32 ftpc_start_recv_hd;

    U16 entity_cnt_cur_folder;

    U16 file_cnt_cur_folder;

    S16 browse_depth; /* depth from root folder */

    //U8 ftpc_disconn_from_cm; /* 1: disconnect from cm, 0 disconnect from client */

    U8 got_root_flag; /* 1:already get root content, 0: not get the root content yet */

    U16 ftpc_recv_path[MMI_FTPC_MAX_RECV_PATH + 1];

    MMI_ID gid;

    MMI_ID subgid1;

    MMI_ID subgid2;

    MMI_ID file_browser_menu_gid;

    MMI_ID get_several_menu_gid;
#endif /* __MMI_FTC_SUPPORT__ */

#ifdef __MMI_FTS_SUPPORT__
    S32 ftps_srv_hd;

    //U8 ftps_dev_name[GOEP_MAX_DEV_NAME]; /* saving bt device name (utf-8) */

    U8 ftps_disconn_from_cm;        /* 1: disconnect from cm, 0 disconnect from client */

    S32 ftps_start_recv_hd;
#endif 
} mmi_ftp_scr_cntx_struct;

/******************************************************************************
    MMI FTP SCR EXTERNAL VARIABLE
******************************************************************************/
//extern mmi_ftp_scr_cntx_struct *g_mmi_ftp_scr_cntx_p;
#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 

/******************************************************************************
    MMI FTP SCR FUNCTIONS
******************************************************************************/
#endif /* __BT_MMI_FTP_SCR_H__ */
