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
 *  CallLogAdpProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_CALL_LOG_ADP_PROT_H
#define MMI_CALL_LOG_ADP_PROT_H

#include "CallLogConfig.h"
#ifdef __MMI_CLOG_ADP__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif 

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif 

#include "MMIDataType.h"
#include "CallLogSrvGprot.h"
#include "app_datetime.h"
#include "CallLogProt.h"

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/
typedef struct mmi_clog_hs_get_data_log_info_st mmi_clog_hs_get_data_log_info_struct;

typedef S32(*MMI_CLOG_HS_PARSE_INFO_HDLR) (void *data_list, U32 max_size, U32 cur_idx,
                                           mmi_clog_hs_get_data_log_info_struct *log_info);

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct mmi_clog_hs_get_data_log_info_st
{
    U32 total_log_num;
    U32 unread_num; /* for one log */
    SRV_CLOG_ID log_id;
    WCHAR *name;
    WCHAR *cid;
    applib_time_struct timestamp;
    MMI_IMG_ID icon;
} mmi_clog_hs_get_data_log_info_struct;

typedef struct
{
    U32 max_size;
    S32 req_num;
    U8 skip_read;
    U8 only_new_event;
    U8 need_cid;
    void *data_list;
    MMI_CLOG_HS_PARSE_INFO_HDLR parse_info_hdlr;
    SRV_CLOG_HANDLE handle;
} mmi_clog_hs_get_data_req_struct;

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

/*---------------------- Common for OP11 HS V2.5/V31/V32 & Venus HS ----------*/
extern void mmi_clog_hs_init_get_data_req(mmi_clog_hs_get_data_req_struct *req);
extern U32 mmi_clog_hs_get_data_create(mmi_clog_hs_get_data_req_struct *req, MMI_BOOL need_malloc);
extern U32 mmi_clog_hs_get_data_run(U32 handle);
extern U32 mmi_clog_hs_get_data_get_ttur_num(U32 handle);   /* should call after run */
extern void mmi_clog_hs_get_data_close(U32 handle);

/*---------------------- Common for OP11 HS V2.5 and Venus HS ----------------*/

#if defined(__MMI_VUI_HOMESCREEN__)
/* Recent event */
extern MMI_BOOL mmi_clog_hs_nmgr_enter(void);

extern void mmi_clog_hs_make_call_hdlr(SRV_CLOG_ID log_id, mmi_clog_key_enum from_key);

#endif /* defined(__MMI_VUI_HOMESCREEN__) */ 

/*---------------------- OP11 HS V2.5 -----------------------------------------*/


/*---------------------- OP11 HS V31 and V32 --------------------------------*/

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*  Sidebar */
extern void mmi_clog_op11_hs32_sb_update(void);

/* Shortcut */
extern void mmi_clog_op11_hs32_shct_update(void);

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

/*---------------------- End -------------------------------------------------*/

#endif /* __MMI_CLOG_ADP__ */ 
#ifdef __MMI_BT_PBAP_CLIENT__
extern  S32 mmi_clog_pbapc_parse_file(U16 *path);
extern U16 mmi_clog_pbap_current_num;

#define SRV_PHB_PBAPC_FOLDER_PATH_FIX "Z:\\@BTDIALER\\"
#define SRV_PHB_PBAPC_FOLDER_PATH_FILE "Z:\\@BTDIALER\\folder.tmp"
#define SRV_PHB_PBAPC_FILE "folder.tmp"

#endif

#endif /* MMI_CALL_LOG_ADP_PROT_H */ 

