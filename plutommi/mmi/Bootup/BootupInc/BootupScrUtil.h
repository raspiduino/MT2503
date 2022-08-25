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
 *  BootupScrUtil.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Screen utility of bootup
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

#ifndef __BOOTUP_SCR_UTIL_H__
#define __BOOTUP_SCR_UTIL_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "ProfilesSrvGprot.h"  /* srv_prof_tone_enum */
#include "GlobalConstants.h"
#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_general_types.h"


/****************************************************************************
 * Constants
 ****************************************************************************/

#define MMI_BOOTUP_COUNT_DOWN_INVALID_HANDLE (NULL)


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    EVT_ID_MMI_BOOTUP_SCR_SELECTED_NEGATIVE = 0,
    EVT_ID_MMI_BOOTUP_SCR_SELECTED_POSITIVE,
    EVT_ID_MMI_BOOTUP_SCR_DELETING  = EVT_ID_SCRN_DELETE_REQ,
    EVT_ID_MMI_BOOTUP_SCR_TIMEOUT,

    EVT_ID_MMI_BOOTUP_SCR_END_OF_ENUM
} mmi_bootup_scr_event_enum;


typedef enum
{
    MMI_BOOTUP_SCR_DONT_CLOSE = MMI_RET_OK,
    MMI_BOOTUP_SCR_ALLOW_TO_CLOSE,

    MMI_BOOTUP_SCR_CLOSE_RETURN_END_OF_ENUM
} mmi_bootup_scr_close_return_enum;

#if 0 /* slim_unused_api : bootup_count_down */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* slim_unused_api : bootup_count_down */

extern void mmi_bootup_waiting_screen_show(
                mmi_id grp_id,
                U16 img_id,
                U16 prompt_str_id);
    
extern void mmi_bootup_waiting_screen_close(mmi_id grp_id);

extern void mmi_bootup_put_dummy_screen(mmi_id grp_id);

extern void mmi_bootup_close_dummy_screen(mmi_id grp_id);

extern mmi_ret mmi_bootup_block_all_keys(mmi_event_struct *evt);

extern mmi_ret mmi_bootup_block_scr_deleting(mmi_event_struct *evt);

#endif /* __BOOTUP_SCR_UTIL_H__ */

