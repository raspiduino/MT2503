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
 * MMSAppResourceDB.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_RES_DB_H
#define MMS_APP_RES_DB_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "MMSAppUICommon.h"
/* ----------------------------- Base Resource DB ---------------------------------------------- */
typedef struct
{
    U16 scrn_id;        /* Screen id */
    U16 menu_item_id;   /* menu id */
    U16 title_str_id;   /* String id of title */
    U16 title_icon_id;  /* Icon id of title */
    U16 lsk_str_id;     /* String id of LSK */
    U16 lsk_icon_id;    /* Icon id of LSK */
    U16 rsk_str_id;     /* String id of RSK */
    U16 rsk_icon_id;
} mmi_umms_app_resourceDB_struct;

/* ----------------------------  screen DB----------------------------------------------------- */

typedef struct
{
    U16 scrn_id;
    mmi_umms_app_resourceDB_struct *RObj;
    U16 parent_menu_id;
      MMI_UMMS_ERROR(*create_func) (U16);
      MMI_UMMS_ERROR(*pre_func) (U16);
      MMI_UMMS_ERROR(*post_func) (U16);
      MMI_UMMS_ERROR(*draw_func) (U16);
    void (*exit_screen) (void);
    void (*EntryFunction) (void);
    void (*lsk_func) (void);
    void (*rsk_func) (void);
    void (*hilite_handler) (S32);
      mmi_ret(*delete_screen_handler) (mmi_event_struct *);
} mmi_umms_app_screenDB_struct;

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern mmi_umms_app_screenDB_struct *mmi_umms_app_if_dummy_screen_db(void);
#else
extern mmi_umms_app_screenDB_struct *mmi_umms_app_resource_get_screenDB(U16 scr_id);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
extern mmi_umms_app_resourceDB_struct *mmi_umms_app_resource_get_resourceDB(U16 scr_id);
extern mmi_umms_app_screenDB_struct *mmi_umms_app_resource_screenDB_for_menu_id(U16 menu_id);

#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_RES_DB_H */ 

