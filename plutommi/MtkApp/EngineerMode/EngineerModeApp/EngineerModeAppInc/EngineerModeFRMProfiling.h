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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  EngineerModeFRMProfiling.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is Engineering mode Profiling for these features:
 *  - Interactive Profiling
 *  - UI Benchmark
 *  - Memory Monitor
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef ENGINEER_MODE_FRM_PROFILING_H
#define ENGINEER_MODE_FRM_PROFILING_H

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_INTERACTIVE_PROFILNG__

#define MMI_EM_MAX_PROFILING_LEN            (4)
#define MMI_EM_PROFILING_BUFFER_SIZE        ((MMI_EM_MAX_PROFILING_LEN + 1) * ENCODING_LENGTH)

#endif /* __MMI_INTERACTIVE_PROFILNG__ */


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#ifdef __MMI_INTERACTIVE_PROFILNG__

typedef struct
{
    U8  *on_off_list[2];
    S32 on_off_index;
    U8  *gdi_on_off_list[2];
    S32 gdi_on_off_index;
    WCHAR screen_delay[MMI_EM_MAX_PROFILING_LEN + 1];
    WCHAR matrix_delay[MMI_EM_MAX_PROFILING_LEN + 1];
    WCHAR list_delay[MMI_EM_MAX_PROFILING_LEN + 1];
    WCHAR delay_offset[MMI_EM_MAX_PROFILING_LEN + 1];
} mmi_em_profiling_struct;

#endif /* __MMI_INTERACTIVE_PROFILNG__ */


/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

#ifdef __MMI_INTERACTIVE_PROFILNG__
/* Frame Profiling Screen */
extern void mmi_em_profiling_frm_entry(void);
#endif /* __MMI_INTERACTIVE_PROFILNG__ */


#ifdef __MMI_UI_BENCHMARK__
/* UI Benchmark Screen */
extern void mmi_em_profiling_ui_bench_entry(void);
#endif /* __MMI_UI_BENCHMARK__ */

extern void mmi_em_profiling_menu_event_entry_hdlr(cui_menu_event_struct *event);
extern void mmi_em_profiling_menu_event_select_hdlr(cui_menu_event_struct *event);

#endif /* ENGINEER_MODE_FRM_PROFILING_H */

