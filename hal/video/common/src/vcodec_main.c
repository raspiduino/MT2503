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
 *   vcodec_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Visual codec main procedure
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "task_main_func.h"
#include "stack_config.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "hisr_config.h"
#include "video_subtitle_decoder_if.h"
#include "video_comm_v2.h"
#include "drv_gfx_stack_switch_manager.h"


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(MT6225)||defined(MT6235)||defined(MT6235B)||defined(MT6236)||defined(MT6236B)||defined(MT6253)||defined(MT6253T)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__VE_MTK_TARGET__)
    #if (defined(MT6235)||defined(MT6235B))
/* under construction !*/
    #else  // !(defined(MT6235)||defined(MT6235B))
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
    #endif  // (defined(MT6235)||defined(MT6235B))
#else  // __VE_MTK_TARGET__
/* under construction !*/
#endif  // __VE_MTK_TARGET__
/* under construction !*/
#endif  // 0


/*****************************************************************************
* FUNCTION
*  vcodec_main
* DESCRIPTION
*  Main ilm handler for visual codec task
* PARAMETERS
*  ilm_ptr     [IN]        ilm pointer
* RETURNS
*  void
*****************************************************************************/
static void vcodec_main(ilm_struct *ilm_ptr)
{
    switch (ilm_ptr->msg_id)
    {
    // FIXME: Wrap me with an appropriate option.
    case MSG_ID_VSD_DATA_IND:
        // _VcodecChangeStack2Run(VsdMain, ilm_ptr);
        VsdMain(ilm_ptr);
        break;

    default:
        ASSERT(0);
    }
}


/*****************************************************************************
* FUNCTION
*  vcodec_task_main
* DESCRIPTION
*  Vcodec task main
* PARAMETERS
*  task_entry_ptr      [IN]        task struct pointer
* RETURNS
*  void
*****************************************************************************/
static void vcodec_task_main(task_entry_struct *task_entry_ptr)
{
    ilm_struct current_ilm;
    kal_uint32 my_index;

    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);
        vcodec_main((void*)&current_ilm);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
* FUNCTION
*  vcodec_task_init
* DESCRIPTION
*  Init vcodec task
* PARAMETERS
*  task_indx       [IN]    task index
* RETURNS
*  KAL_BOOL
*****************************************************************************/
static kal_bool vcodec_task_init(task_indx_type task_indx)
{
    VideoInitSource();

    return KAL_TRUE;
}


#else


/*****************************************************************************
*
*****************************************************************************/
static void vcodec_task_main(task_entry_struct *task_entry_ptr)
{
    /* Empty */
}


/*****************************************************************************
*
*****************************************************************************/
static kal_bool vcodec_task_init(task_indx_type task_indx)
{
    return KAL_TRUE;
}


#endif /* __VIDEO_ARCHI_V2__ */


/*****************************************************************************
 * FUNCTION
 *  vcodec_create
 * DESCRIPTION
 *  Create visaul codec task
 * PARAMETERS
 *  handle      [IN]     handle
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool vcodec_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct vcodec_v2_handler_info =
    {
        vcodec_task_main,       /* task entry function */
        vcodec_task_init,       /* task initialization function */
        NULL,                   /* task configuration function */
        NULL,                   /* task reset handler */
        NULL,                   /* task termination handler */
    };

    *handle = (comptask_handler_struct*)&vcodec_v2_handler_info;

    return KAL_TRUE;
}


