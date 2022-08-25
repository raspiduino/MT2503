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
 * BTMMIBip.h
 *
 * Project:
 * --------
 *   BT BIP MMI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_BIP_H__
#define __MMI_BIP_H__
#include "MMI_features.h"
#include "bluetooth_struct.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "BipSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "FileMgrSrvGProt.h"

#define MMI_BIP_RECV_FOLDER     32
#define MMI_BIP_FS_CONT_DUR             (1000)
#define MMI_BIP_PROG_UPD_DUR            (1000)
#define BIP_PUSH_IND_PROG_UPD_DUR       60000

#define IS_BIPI_PUSHING  (mmi_bip_p.bipi_push_cntx.cur_service == BT_BIP_IMAGE_PUSH)


#define MMIBIP_MASK_SUCC_RECV_FILE   0x0000200
#define MMIBIP_AUTHORIZE_IND   0x0000001


#define MMIBIP_SET_FLAG(f)  ((mmi_bip_p->flag) |= f)
#define MMIBIP_RESET_FLAG(f)  ((mmi_bip_p->flag) &= ~f)
#define MMIBIP_FLAG_IS_ON(f)  ((mmi_bip_p->flag) & f)


/***************************************************************************** 
 *  Enum
 *****************************************************************************/
#ifdef __BIP_PULL_SUPPORT__
 /* identify the option selection from user */
typedef enum
{
    MMI_BIP_SCR_SELECT_OPT_GET,
    MMI_BIP_SCR_SELECT_OPT_IMG_DETAIL,
    MMI_BIP_SCR_SELECT_OPT_GET_THM,
    MMI_BIP_SCR_SELECT_OPT_GET_ALL,
    MMI_BIP_SCR_SELECT_OPT_REFRESH,
    MMI_BIP_SCR_SELECT_OPT_DISCONNECT,
    MMI_BIP_SCR_SELECT_OPT_END_OF_NUM
} mmi_bip_scr_select_opt_enum;

typedef enum
{
    MMI_BIP_NEXT_OPER_IDLE,
    MMI_BIP_NEXT_OPER_GET_IMG,
    MMI_BIP_NEXT_OPER_GET_IMGPROP,
    MMI_BIP_NEXT_OPER_GET_THM,
    MMI_BIP_NEXT_OPER_REFRESH_IMGLIST,
    MMI_BIP_NEXT_OPER_LAST
}mmi_bipi_cur_user_operation_enum;

typedef enum
{
    MMI_BIP_GET_CUR_IMG,
    MMI_BIP_GET_SELECTED_IMG,
    MMI_BIP_GET_ALL_IMG,
    MMI_BIP_GET_LAST
}mmi_bipi_get_type_enum;

typedef enum
{
    MMI_BIP_OPT_ITEM_CHANGED_NONE,
    MMI_BIP_OPT_ITEM_ENABLE_GET_SELECTED,
    MMI_BIP_OPT_ITEM_DISABLE_GET_SELECTED
}mmi_bipi_opt_item_flag;

#endif


typedef enum
{

    BIP_FILE_GET_NAME,  /* Extract file name */
    BIP_FILE_GET_EXT,   /* Extract file extension */
    BIP_FILE_GET_NAME_VALID,
    BIP_FILE_GET_LAST
}mmi_bip_get_file_enum;


typedef enum
{
    MMI_BIPI_EXIT_NOTY,
    MMI_BIPI_ABORTING_NOTY,
    MMI_BIPI_CONNECTING_NOTY,
    MMI_BIPI_DISCONNECTING_NOTY,
    MMI_BIPI_GETTING_IMGPROP_NOTY,
    MMI_BIPI_GETTING_IMGTHM_NOTY,
    MMI_BIPI_REFRESH_IMGLIST_NOTY,
    MMI_BIPI_SEND_PERSENT_UDPADE,
    MMI_BIPICONTINUE_SEND_CONVERT_FAILED,
    MMI_BIPI_CONTINUE_SEND_UNSUPPORT_MEDIA_NOTY,
    MMI_BIPR_IMG_RECV_NOTY,
    MMI_BIP_NOTY_LAST
}mmi_bip_noty_str;


/***************************************************************************** 
 *  Typedef
 *****************************************************************************/

#ifdef __MMI_BT_RECV_OBJ_DETAIL__
typedef struct
{
    bt_bip_img_format_enum img_encoding;
    U32 img_size;
    U16 img_name[BT_BIP_MAX_IMG_NAME_LEN];
}mmi_bip_img_detail_struct;
#endif


typedef struct
{
    MMI_BOOL disconn_from_cm;
    U32 conn_id;
    //U8 dev_name[MAX_DEV_NAME];
    U16 recv_path[MMI_BIP_RECV_FOLDER];
    U8 recv_drv;
    U32 total_recv_cnt;
    U32 cur_recv_cnt;
    MMI_BOOL pause_fs_oper;
    S32 app_hd;
    S32 recv_hd;
    srv_bip_obj_detail_struct detail;
    MMI_ID gid;
}mmi_bipr_push_cntx_struct;


#ifdef __BIP_PULL_SUPPORT__
typedef struct
{
    U16 sel_obj_id;
    U16 sel_opt_id;
    U16 sel_opt_index;

    mmi_bipi_opt_item_flag opt_item_changed;
    U16 old_selected_img_num;

    /* for getting */
    U16 img_total;
    
    U16 selected_img_num;
    
    U16 received_img_num;
    
    U16 cur_getting_num;

    U16 img_num_to_get;

    U8  pull_recv_drive;

        
    MMI_BOOL b_refreshed;

    mmi_bipi_cur_user_operation_enum next_oper;

    mmi_bipi_get_type_enum get_type;
    
    U16 cur_idx_to_get_img;
    U16 cur_idx_to_get_thm;
    
    MMI_BOOL b_stop_bg_getting_thm;

    MMI_BOOL b_user_get_thm;

    /* for category426 */
    U32 cur_index;
    U8 *checkbox_values;
    U8 *cache_buffer;
    S32 cache_size;

    U16 img_browser_content_path[SRV_FMGR_PATH_MAX_LEN];
    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /* img thumbnail */
    U16 img_thm_path[SRV_FMGR_PATH_MAX_LEN];

    /* image detail */
    bt_bip_img_format_enum img_encoding;
    U16 img_width;
    U16 img_height;
    U32 img_size;
    S8 img_name[BT_BIP_MAX_IMG_NAME_LEN];
#ifdef __MMI_BT_RECV_DRV_SWITCH__
    MMI_BOOL b_selecting_drv;
#endif /*__MMI_BT_RECV_DRV_SWITCH__*/
} mmi_bip_pull_cntx_struct;
#endif


typedef struct
{
    mmi_bipr_push_cntx_struct bipr_push_cntx;
    
#ifdef __BIP_PULL_SUPPORT__
    mmi_bip_pull_cntx_struct bip_pull_cntx;
#endif
    U32 flag;
} mmi_bip_struct;




/***************************************************************************** 
 *  Global variable
 *****************************************************************************/
extern mmi_bip_struct *mmi_bip_p;


#define MMI_BIP_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);                                           \
   }
#define MMI_BIP_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);                                       \
   }
#define MMI_BIP_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);                                   \
   }
#define MMI_BIP_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);                               \
   }
#define MMI_BIP_LOG4(x, x1, x2, x3, x4)                                            \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4);                           \
   }
#define MMI_BIP_LOG6(x, x1, x2, x3, x4, x5, x6)                                    \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6);                   \
   }
#define MMI_BIP_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                                \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6, x7);               \
   }

#define MMI_BIP_LOG_PATH(unicode_path)                   \
{                                                        \
    if (unicode_path != NULL)    \
    {               \
        U8 asc_path[SRV_FMGR_PATH_MAX_LEN + 1];                               \
        mmi_ucs2_to_asc((S8 *)asc_path, (S8 *)unicode_path);          \
        MMI_BIP_LOG1(MMI_BIP_PATH_LOG, asc_path);                  \
        kal_prompt_trace(MOD_MMI, "[BIP_MMI] path: %s\n", asc_path);  \
    }\
    else\
    {\
        MMI_BIP_LOG(MMI_BIP_PATH_IS_NULL);                  \
    }\
}

#endif /*  __BT_MMI_BIPSCR_H__ */
