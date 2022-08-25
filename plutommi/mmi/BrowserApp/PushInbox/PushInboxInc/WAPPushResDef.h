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
 * WAPPushResDef.h
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
#ifndef _PUSHINBOXRESDEFS_H
#define _PUSHINBOXRESDEFS_H

//#include "mmi_rp_app_mmi_wap_push_def.h"
//#ifdef __MMI_PUSH_IN_UM__
//#include "mmi_rp_app_unifiedmessage_def.h"
//#endif
#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#undef __NEWSIMULATOR

#include "mmi_res_range_def.h"
#ifdef __WAP_PUSH_SUPPORT__


typedef enum
{
    PUSH_MSG_UM_OPT_READ,
    PUSH_MSG_UM_OPT_DELETE,
    PUSH_MSG_UM_OPT_DELETE_ALL,
#ifdef __MMI_PUSH_IN_UM__
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    PUSH_UM_OPT_SORT_BY,
#endif
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    PUSH_UM_OPT_MULTIPLE_SELECT,
#endif
#endif /* __MMI_PUSH_IN_UM__ */
    PUSH_MSG_UM_OPT_TOTAL
} push_msg_um_opt_enum;

typedef enum
{
    PUSH_SERVICE_MSG_GOTO,
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    PUSH_SERVICE_MSG_ADD_TO_TRUST_LIST,
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    PUSH_SERVICE_MSG_ADD_TO_BLACK_LIST,
#endif
    PUSH_SERVICE_MSG_ADD_BOOKMARK,
    PUSH_SERVICE_MSG_SEND_BY,
    PUSH_SERVICE_MSG_DELETE,
    PUSH_SERVICE_MSG_DELETE_ALL,
    PUSH_MSG_OPT_TOTAL
} push_msg_opt_enum;

typedef enum
{
    PUSH_SETTING_ENABLE,
    PUSH_SETTING_ENABLE_SL,
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    PUSH_SETTING_ENABLE_WHITE_LIST,
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    PUSH_SETTING_ENABLE_BLACK_LIST,
#endif
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    PUSH_SETTING_WHITE_LIST,
#endif
#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    PUSH_SETTING_BLACK_LIST,
#endif

    PUSH_SETTING_TOTAL
} push_setting_menu_enum;

typedef enum
{
    PUSH_ENABLE_SETTING_ACCEPT_ALL,
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    PUSH_ENABLE_SETTING_ACCEPT_AUTHENTICATED,
#endif /* __MMI_WAP_PUSH_WHITE_LIST__  */
    PUSH_ENABLE_SETTING_DISABLE,

    PUSH_ENABLE_SETTING_TOTAL
} push_enable_setting_menu_enum;

typedef enum
{
    PUSH_SL_SETTING_PROMPT,
    PUSH_SL_SETTING_AUTO_LAUNCH,
    PUSH_SL_SETTING_DISABLE,

    PUSH_SL_SETTING_TOTAL
} push_sl_setting_menu_enum;

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
typedef enum
{
    PUSH_WL_SETTING_DISCARD,
    PUSH_WL_SETTING_NOTIFY,
    PUSH_WL_SETTING_DISABLE,

    PUSH_WL_SETTING_TOTAL
} push_wl_setting_menu_enum;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
typedef enum
{
    PUSH_BL_SETTING_NOTIFY,
    PUSH_BL_SETTING_DISABLE,

    PUSH_BL_SETTING_TOTAL
} push_bl_setting_menu_enum;
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
typedef enum
{
    PUSH_ADD_NEW_PHONE_NUMBER,
    PUSH_ADD_NEW_IP_ADDR,

    PUSH_ADD_NEW_TOTAL
} push_add_new_menu_enum;

typedef enum
{
    PUSH_LIST_OPT_MODIFY,
    PUSH_LIST_OPT_DELETE,
    PUSH_LIST_OPT_DELETE_ALL,

    PUSH_LIST_OPT_TOTAL
} push_list_options_menu_enum;

typedef enum
{
    PUSH_UNKNWN_ADDR_OPT_ACCEPT,
    PUSH_UNKNWN_ADDR_OPT_REJECT,
    PUSH_UNKNWN_ADDR_OPT_ACCEPT_N_ADD_WL,

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    PUSH_UNKNWN_ADDR_OPT_REJECT_N_ADD_BL,
#endif

    PUSH_UNKNWN_ADDR_OPT_TOTAL
} push_unknwn_addr_options_menu_enum;
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

typedef enum
{
    PUSH_CONNECT_OPT_SIM1,
    PUSH_CONNECT_OPT_SIM2,

    PUSH_CONNECT_OPT_TOTAL
} push_connect_sim_enum;

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    PUSH_VIWER_SCR_FTE_TB_OPT_GOTO,
    PUSH_VIWER_SCR_FTE_TB_OPT_DELETE,

    PUSH_VIWER_SCR_FTE_TB_OPT_TOTAL
} push_viwer_scr_tb_options_enum;
#endif /* __MMI_FTE_SUPPORT__ */

typedef enum
{
	#ifndef __COSMOS_MMI__
    GRP_ID_BRW_PUSH_INBOX = MMI_WAP_PUSH_BASE + 1,
    GRP_ID_BRW_PUSH_OPTION,
    GRP_ID_BRW_PUSH_BODY,
    GRP_ID_BRW_PUSH_SETTING,
    GRP_ID_BRW_PUSH_SETTING_LIST,
    GRP_ID_BRW_PUSH_NOTIFICATION,
    GRP_ID_BRW_PUSH_POPUP,
    GRP_ID_WAP_PUSH_SERVICE_MSG_MAIN,
    GRP_ID_BRW_PUSH_FROM_IDLE,
    GRP_ID_BRW_PUSH_INLINE,
    GRP_ID_BRW_PUSH_POPUP_CONFIRM,
    GRP_ID_BRW_PUSH_DUMMY,
  #endif /*__COSMOS_MMI__*/  
    GRP_ID_BRW_PUSH_END
}scr_group_push_list_enum;


#endif /* __WAP_PUSH_SUPPORT__ */ 


#endif /* _PUSHINBOXRESDEFS_H */ 

