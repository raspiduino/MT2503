/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*  NetSetAppResDef.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*  Resource definitions.
*
*  Author:
* -------
*  Xiangjun Dan
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __NETSET_APP_RESDEF_H__
#define __NETSET_APP_RESDEF_H__

typedef enum    //temp trace enum
{
    /* NetSetApp.c */
    TRC_MMI_NETSET_SET_CNTX_PTR,
    TRC_MMI_NETSET_GET_ACTIVE_SIM,
    TRC_MMI_NETSET_ENTRY_MAIN_SCREEN,
    TRC_MMI_NETSET_RETRIEVE_CURRENT_MODE,
    TRC_MMI_NETSET_ENTRY_SIM_MENU,

    /* NetSetAppNWSelect.c */
    TRC_MMI_NETSET_ENTRY_NETWORK_SELECTION,
    TRC_MMI_NETSET_NETSEL_AUTO,
    TRC_MMI_NETSET_NETSEL_AUTO_PROGRESS,
    TRC_MMI_NETSET_NETSEL_MANUAL,
    TRC_MMI_NETSET_NETSEL_MANUAL_SEARCH_PROGRESS,
    TRC_MMI_NETSET_NETSEL_ENTRY_MANUAL_PLMN_LIST,
    TRC_MMI_NETSET_NETSEL_EXIT_MANUAL_PLMN_LIST,
    TRC_MMI_NETSET_NETSEL_FIND_FORBID_PLMN,
    TRC_MMI_NETSET_NETSEL_ADD_FORBID_PLMN,
    TRC_MMI_NETSET_NETSEL_DEL_FORBID_PLMN,
    TRC_MMI_NETSET_NETSEL_SET_MANUAL,
    TRC_MMI_NETSET_NETSEL_MANUAL_REGISTER_PROGRESS,
    TRC_MMI_NETSET_NETSEL_ENTRY_SELECT_MODE,
    TRC_MMI_NETSET_NETSEL_SET_SELECT_MODE,
    TRC_MMI_NETSET_NETSEL_SET_SELECT_MODE_RSP,
    
    /* NetSetAppPrefList.c */


    /* NetSetAppPrefOthers.c */


    /* NetSetAppPrefMode.c */


    /* NetSetSrv.c */
    /* None */

    STR_ID_NETSET_MAX
} mmi_netset_trace_enum;

#endif /* __NETSET_APP_RESDEF_H__ */
