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
 * SndrecGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
#ifndef SOUND_RECORDER_H
#define SOUND_RECORDER_H

#include "MMI_features.h"
#if defined(__MMI_SOUND_RECORDER__)
#include "MMIDataType.h"
//#include "SoundRecorderProt.h"

#if defined(__MMI_FTE_SUPPORT__) && (defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)|| defined(__MMI_MAINLCD_320X240__))
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        #define MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    #endif
#endif

MMI_BOOL mmi_sndrec_is_in_app(void);

MMI_BOOL mmi_sndrec_is_in_recording(void);

extern void InitSoundRecorderApp(void);
extern void mmi_sndrec_pre_entry_main_screen(void);
#ifdef __MMI_APP_MANAGER_SUPPORT__
extern MMI_ID mmi_sndrec_launch_function(void *param, U32 param_size);
#endif

/* for mslt tools */
extern S32 mmi_sndrec_mslt_skin_title(void);
#ifndef __MMI_FTE_SUPPORT__
extern S32 mmi_sndrec_mslt_skin_state(void);
#endif

#if defined(__MMI_OP02_LEMEI__)
extern void mmi_sndrec_entry_record_from_lamei(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*app_callback_func) (BOOL result, U16 *filepath));
#endif
extern void mmi_sndrec_entry_in_call(void);
//extern void mmi_sndrec_entry_from_call(void);
//extern void mmi_sndrec_entry_in_voip_call(void);
extern void mmi_sndrec_entry_record_from_other_app(U16* file_path, U32 size_limit, U32 time_limit, void(*callback_func)(BOOL result, U16* filepath));
extern void mmi_sndrec_entry_record_from_autoam(U16* file_path, U32 size_limit, U32 time_limit, void(*callback_func)(BOOL result, U16* filepath));
extern void mmi_sndrec_exit_notify(void);

#if 0
/* under construction !*/
#endif

#endif /* (defined(__MMI_SOUND_RECORDER__)) */ 
#endif /* SOUND_RECORDER_H */
