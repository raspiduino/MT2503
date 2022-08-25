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
 *   vfile_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Visual file main procedure
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
 *
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
 *
 *
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
#include "kal_active_module.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "hisr_config.h"

#include "mpl_player.h"
#include "mpl_utility.h"
#include "media_player.h"

// The header files above are needed for the "#else" block below.
#include "drv_features_video.h"
#ifdef __VE_VIDEO_COMMON__



#include "mpl_recorder.h"

#include "video_muxer_if_v2.h"
#include "video_comm_v2.h"
#include "source_provider_if.h"
#include "vfile_main.h"

/*****************************************************************************
 * FUNCTION
 *  vfile_init
 * DESCRIPTION
 *  Initiation function for visual file task
 * PARAMETERS
 *  void
 * RETURNS
 * TRUE
 *****************************************************************************/
kal_bool vfile_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vfile_main
 * DESCRIPTION
 *  Main ilm handler for visual file task
 * PARAMETERS
 *  ilm_ptr     [IN]        ilm pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vfile_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (ilm_ptr->msg_id)
    {
#if defined(__VE_SUPPORT_MUXER__)
    case MSG_ID_MP4_FILE_WRITER_DATA_IND:
        MuxerMainNonDCM(ilm_ptr);
        break;
#endif        //__VE_SUPPORT_MUXER__

    case MSG_ID_SOURCE_PROVIDER_DATA_IND:
#if defined (__VE_SOURCE_PROVIDER__)
        SourceProviderSrcMain(ilm_ptr);
#endif
        break;

    default:
        /* message not handled */
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfile_task_main
 * DESCRIPTION
 *  Vfile task main
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer
 * RETURNS
 *  void
 *****************************************************************************/
void vfile_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        vfile_main((void*)&current_ilm);

        free_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  vfile_task_init
 * DESCRIPTION
 *  Init vfile task
 * PARAMETERS
 *  task_indx       [IN]    task index
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool vfile_task_init(task_indx_type task_indx)
{
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vfile_create
 * DESCRIPTION
 *  Create visaul file task
 * PARAMETERS
 *  handle      [IN]     handle
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool vfile_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct vfile_handler_info =
    {
        vfile_task_main,   /* task entry function */
        vfile_task_init,   /* task initialization function */
        NULL,               /* task configuration function */
        NULL,               /* task reset handler */
        NULL,               /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*)&vfile_handler_info;

    return KAL_TRUE;
}


#else


/*****************************************************************************
*
*****************************************************************************/
void vfile_task_main(task_entry_struct *task_entry_ptr)
{
    /* empty */
}


/*****************************************************************************
*
*****************************************************************************/
kal_bool vfile_task_init(task_indx_type task_indx)
{
    return KAL_TRUE;
}


/*****************************************************************************
*
*****************************************************************************/
kal_bool vfile_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct vfile_handler_info =
    {
        vfile_task_main,   /* task entry function */
        vfile_task_init,   /* task initialization function */
        NULL,               /* task configuration function */
        NULL,               /* task reset handler */
        NULL,               /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*)&vfile_handler_info;

    return KAL_TRUE;
}


#endif /* __VE_VIDEO_COMMON__ */

