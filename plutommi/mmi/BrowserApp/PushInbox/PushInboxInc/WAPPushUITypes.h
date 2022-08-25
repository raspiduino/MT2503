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
 * Filename:
 * ---------
 * WAPPushSrvTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This defines the String ,screen,& Image ID for push inbox module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _PUSHMSGTYPES_H
#define _PUSHMSGTYPES_H

//#include "MMI_include.h"
//#include "custom_nvram_editor_data_item.h"
//#include "browser_api.h"
//#include "wap_adp.h"
//#include "WapPushSrvGprots.h"
//#include "WapPushSrvProts.h"

//#include "UcmSrvGprot.h"
//#include "UcmGprot.h"
//#include "SmsAppGprot.h"
    #include "MMI_features.h"
    #include "MMIDataType.h"
    #include "wap_adp.h"
    #include "kal_general_types.h"
    #include "WAPPushSrvTypes.h"
    #include "custom_phb_config.h"
    #include "common_nvram_editor_data_item.h"

#ifdef __WAP_PUSH_SUPPORT__

#ifndef __COSMOS_MMI_PACKAGE__

#ifdef __MMI_PUSH_IN_UM__
#include "UMGProt.h"
#endif /* __MMI_PUSH_IN_UM__ */
#endif

#ifdef __MMI_OP12_TOOLBAR__
#include "IdleToolbarGprot.h"
#endif 

//#ifdef __DM_LAWMO_SUPPORT__
//#include "dmuigprot.h"
//#endif /* __DM_LAWMO_SUPPORT__ */

//#include "WapProfileGprot.h"
#define __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__

#ifdef __MMI_PUSH_IN_UM__
#ifdef __MMI_UM_ITERATOR_VIEWER__
#define __MMI_WAP_PUSH_ITERATOR_VIEWER_SUPPORT__
//#define __MMI_WAP_PUSH_ITERATOR_VIEWER_UT__
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif /* __MMI_PUSH_IN_UM__ */

/****************************************  Start of constant defination  ****************************************/
#ifdef __MMI_OP12_TOOLBAR__
#define MMI_BRW_PUSH_MAX_TB_SUB_LEN                 ((MAX_SUBMENU_CHARACTERS + 2) * ENCODING_LENGTH)
#endif /* __MMI_OP12_TOOLBAR__ */ 

#define MMI_BRW_PUSH_MAX_TITLE_LENGTH               (40)

/****************************************  END of constant defination  *******************************************/





/****************************************  Start of ENUM defination  *********************************************/

typedef enum
{
    MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR_CAPTION = 0,
    MMI_BRW_PUSH_ADD_NEW_PH_NUM_SENDER_ADDR,
    MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR_CAPTION,
    MMI_BRW_PUSH_ADD_NEW_PH_NUM_SMSC_ADDR,

    MMI_BRW_PUSH_ADD_NEW_PH_NUM_END
} push_wl_add_new_ph_num_enum;

typedef enum
{
    MMI_BRW_PUSH_ADD_NEW_IP_ADDR_CAPTION = 0,
    MMI_BRW_PUSH_ADD_NEW_IP_ADDR,

    MMI_BRW_PUSH_ADD_NEW_IP_END
} push_wl_add_new_ip_enum;

typedef enum
{
    MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE_CAPTION,
    MMI_BRW_PUSH_INLINE_ADD_BKM_TITLE,
    MMI_BRW_PUSH_INLINE_ADD_BKM_ADDRESS_CAPTION,
    MMI_BRW_PUSH_INLINE_ADD_BKM_URL,

    MMI_BRW_PUSH_ADD_BKM_END
} push_add_bkm_enum;
/****************************************  END of ENUM defination  ***********************************************/


/*-----------------------------------------------------------------------------------------------------------*/
/*                                        Start of Structures defination                                     */
/*-----------------------------------------------------------------------------------------------------------*/
typedef struct 
{
    S8  title[(MMI_BRW_PUSH_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH];
    S8  url[(WAP_MAX_URL_LENGTH + 1) * ENCODING_LENGTH];
} mmi_wap_push_add_bkm_struct;

typedef struct
{
    MMI_BOOL gdi_locked;
    MMI_BOOL is_popup_scr_active;
    U16 msg_str_id;
    MMI_ID scr_grp_id;
    MMI_ID inline_gid;
#ifdef __MMI_PUSH_IN_MSG__
    MMI_ID service_msg_cid;
#endif

    U32 popup_tone;
    mmi_wap_push_add_bkm_struct add_bkm;
    MMI_ID service_msg_setting_cid;
#ifdef __MMI_PUSH_IN_UM__

    U32 um_msg_id;
    U16 um_sort_idx;
    U16  um_parent_group_id;
#ifdef __MMI_UM_ITERATOR_VIEWER__
    void *um_user_data;
    MMI_BOOL need_indexing_update;
    mmi_um_iter_viewer_result_struct um_index_success;
    mmi_um_iter_viewer_info_struct um_index_fail;
#endif /* __MMI_UM_ITERATOR_VIEWER__ */
#endif

#ifdef __MMI_OP12_TOOLBAR__ 
    MMI_BOOL is_tb_active;
    U16 tb_selected_opr;
    U32 tb_num_of_req;
    U32 tb_start_index;
    U32 tb_total_num_unread;
    U32 tb_current_msg_id;
    U32 tb_user_data[MMI_TB_MAX_NEW_MESSAGE_NUM];
    mmi_tb_evnt_struct *tb_data;
#endif /* __MMI_OP12_TOOLBAR__ */
    void (*confirmation_lsk)(void); 
    void (*confirmation_rsk)(void); 
    void (*confirmation_csk)(void); 
} mmi_wap_push_context_struct;


/*-----------------------------------------------------------------------------------------------------------*/
/*                                        END of Structures defination                                       */
/*-----------------------------------------------------------------------------------------------------------*/




#endif /* __WAP_PUSH_SUPPORT__ */ 
#endif /* _PUSHMSGTYPES_H */ 

