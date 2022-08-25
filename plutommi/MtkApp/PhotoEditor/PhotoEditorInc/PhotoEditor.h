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
 *  PhotoEditor.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Photo Editor Applcation Header of PhotoEditor
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PHOEDT_H_
#define _PHOEDT_H_

#include "MMI_features.h"
#ifdef __MMI_PHOTOEDITOR__
#include "FileMgrSrvGProt.h"
#include "PhotoEditorGProt.h"
#include "photoeditorcui.h"


#define PHOEDT_APP_BASED_MEM_SIZE       (PHOEDT_CUI_NEED_SIZE + sizeof(phoedt_cntx_struct))

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
#define PHOEDT_MAIN_ARROW_FROM_CENTER     (70)
#else
#define PHOEDT_MAIN_ARROW_FROM_CENTER     (50)
#endif

typedef struct
{
    MMI_ID                              app_gid;
    U32                                 cui_memory_size;
    PU8                                 cui_memory_ptr;
    WCHAR                               filepath[SRV_FMGR_PATH_MAX_LEN + 1];
}phoedt_cntx_struct;

typedef struct
{
    WCHAR                               filepath[SRV_FMGR_PATH_MAX_LEN + 1];
}phoedt_app_run_para_struct;

/*****************************************************************************
* external APIs
*****************************************************************************/
extern void mmi_phoedt_hilight_app(void);
extern void mmi_phoedt_launch(void);
extern mmi_ret mmi_phoedt_fmgr_notify_handler(mmi_event_struct *evt);


#define PHOEDT_REENTRY_HANDLER
#ifdef PHOEDT_REENTRY_HANDLER
typedef enum
{
    PHOEDT_RH_INS_STATE_INITED,
    PHOEDT_RH_INS_STATE_INACTIVED,
    PHOEDT_RH_INS_STATE_ACTIVED,
    PHOEDT_RH_INS_STATE_NOT_SAVED,
    PHOEDT_RH_INS_STATE_COUNT
}phoedt_rh_ins_state_enum;

typedef union
{
    phoedt_cui_run_para_struct  cui_para;
    phoedt_app_run_para_struct  app_para;
}phoedt_rh_reentry_para_union;

typedef void(*callback)(void);
typedef void(*reentry_callback)(MMI_BOOL, phoedt_rh_reentry_para_union*);

typedef struct
{
    phoedt_rh_ins_state_enum    state;
    callback                    save_cb;
    callback                    exit_cb;
}phoedt_rh_ins_struct;

typedef struct
{
    phoedt_rh_ins_struct            current_ins;
    phoedt_rh_ins_struct            reentry_ins;
    phoedt_rh_reentry_para_union    reentry_para;
    reentry_callback                reentry_cb;
}phoedt_rh_cntx_struct;

extern void mmi_phoedt_rh_add_ins(
    const phoedt_rh_reentry_para_union    *para,
    callback                save_cb,
    callback                exit_cb,
    reentry_callback        reentry_cb);
extern void mmi_phoedt_rh_remove_ins(void);
extern void mmi_phoedt_rh_set_not_saved(MMI_BOOL is_not_save);
#endif /* PHOEDT_REENTRY_HANDLER */
#endif /* __MMI_PHOTOEDITOR__ */
#endif /* _PHOEDT_H_ */

