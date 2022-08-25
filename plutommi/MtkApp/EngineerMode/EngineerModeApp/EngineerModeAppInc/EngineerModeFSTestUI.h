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
 *   EngineerModeFSTestUI.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines all structure needed in FS Test UI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef ENGINEER_MODE_FS_TEST_H
#define ENGINEER_MODE_FS_TEST_H

#include "MMI_features.h"

#if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__) )
#include "EngineerModeFSTestCore.h"

#define MMI_EM_FS_TEST_DISK_NAME_LEN    50

#define MMI_EM_FS_TEST_MAX_DRIVE_NAME_LEN ((SRV_FMGR_DRV_MAX_NAME_LEN + 1) * ENCODING_LENGTH)

typedef struct
{
    S8 drv_letter[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
    S8 * drv_names[MMI_EM_FS_TEST_FMT_DISK_TOTAL];
    U8 drv_num;
    U8 drv_state_info[MMI_EM_FS_TEST_FMT_DISK_TOTAL];

    U8 * content_text_info[MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL];
    U8 content_state_info[MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL];
    S16 content_count;

    U8 *buffer_for_fmt;
    mmi_em_fs_test_fmt_finish_iln_struct * test_result_ptr;
    U16 current_disk_index;
    WCHAR * result_text_buffer;
    
}mmi_em_fs_test_context_struct;

typedef enum
{
    MMI_EM_FS_TEST_OBJ_PHONE,
    MMI_EM_FS_TEST_OBJ_MEMORY_CARD,
    MMI_EM_FS_TEST_OBJ_BASIC,
    MMI_EM_FS_TEST_OBJ_NORMAL,
   MMI_EM_FS_TEST_OBJ_ADVANCE
}mmi_em_fs_test_obj_enum;

extern void mmi_em_fs_test_init(void);
extern void mmi_em_fs_test_hilite_main(void);
extern void mmi_em_fs_test_hilite_disk_selection(void);
extern void mmi_em_fs_test_hilite_content_selection(void);
extern void mmi_em_fs_test_hilite_run(void);
extern void mmi_em_fs_test_hilite_format(void);
extern void mmi_em_fs_test_hilite_help(void);

#endif /* ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 
#endif /*ENGINEER_MODE_FS_TEST_H*/

