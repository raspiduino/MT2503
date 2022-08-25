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
 *  BootupScrAni.g
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Animation common UI for bootup and shutdown.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProfilesSrvGprot.h"


/****************************************************************************
 * Typedef
 ****************************************************************************/

#define MMI_ANI_INVALID_HANDLE (NULL)

typedef void *mmi_ani_handle;

typedef enum
{
    MMI_ANI_LED_COMMAND_STOP = 0,
    MMI_ANI_LED_COMMAND_START,

    MMI_ANI_LED_COMMAND_END_OF_ENUM
} mmi_ani_led_command;


typedef struct
{
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    void (*reset_to_default)(void);
    MMI_BOOL (*get_res_filepath)(WCHAR *out_filepath, U32 buffer_size);
#endif
#if !defined(__MMI_BOOTUP_SLIM__)
    void (*led_control)(mmi_ani_led_command command);
    MMI_BOOL end_key_to_exit;
#endif
#ifdef __DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__
    mmi_ret (*key_proc)(mmi_event_struct *evt);
#endif
    U16 (*get_disp_id)(void);
    srv_prof_tone_enum audio;
    MMI_BOOL play_audio;
    MMI_BOOL wait_for_audio;
    mmi_id grp_id;
    mmi_id scr_id;
    S32 timeout;
    void (*completed_callback)(void *user_data, mmi_ani_handle handle);
    void *user_data;
} mmi_ani_param_struct;


/****************************************************************************
 * Global functions
 ****************************************************************************/

extern mmi_ani_handle mmi_ani_create(const mmi_ani_param_struct *param);
extern void mmi_ani_show(mmi_ani_handle handle);
extern void mmi_ani_close(mmi_ani_handle handle);
#ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
extern void mmi_ani_pause_video(mmi_ani_handle handle);
extern void mmi_ani_resume_video(mmi_ani_handle handle);
#endif /* #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__ */


