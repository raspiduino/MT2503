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
 *   VdoRecCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Common UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "VdoRecCuiGprot.h"
#include "MMIDataType.h"
#include "string.h"
#if defined(__MMI_CAMCORDER__)
#include "mmi_rp_app_camco_def.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_camco_gprot.h"
#else
#include "CamcorderGprot.h"
#endif
#endif
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Function Declaration
*******************************************************************************/

/*******************************************************************************
* External Function Declaration
*******************************************************************************/
extern void mmi_vdorec_enter_from_cui(mmi_id cur_gid, p_cui_vdorec_run_struct p_args);
extern mmi_ret mmi_vdorec_app_group_proc(mmi_event_struct *evt);
extern void mmi_camco_rec_enter_from_cui(mmi_id cur_gid, p_cui_vdorec_run_struct p_args);
extern mmi_ret mmi_camco_rec_group_proc(mmi_event_struct *evt);
/*******************************************************************************
* Function Realization 
*******************************************************************************/
void cui_vdorec_struct_init(p_cui_vdorec_run_struct p_args)
{
#if defined(__MMI_CAMCORDER__)
    memset(p_args, 0, sizeof(cui_vdorec_run_struct));
#elif defined(__MMI_VIDEO_RECORDER__)
    memset(p_args, 0, sizeof(cui_vdorec_run_struct));
#endif
}


mmi_id cui_vdorec_create(mmi_id parent_gid)
{
#if defined(__MMI_CAMCORDER__)
    mmi_frm_group_close (SCR_GROUP_ID_CAMCO_EXT_APP);
    return mmi_frm_group_create (parent_gid,  SCR_GROUP_ID_CAMCO_EXT_APP, mmi_camco_rec_group_proc, NULL);
#elif defined(__MMI_VIDEO_RECORDER__)
    /* currently vdorec will have only one screen group, for it just single instance*/
    return mmi_frm_group_create (parent_gid,  GRP_ID_AUTO_GEN, mmi_vdorec_app_group_proc, NULL);
#endif
}


void cui_vdorec_run(mmi_id cui_gid, p_cui_vdorec_run_struct p_args) /*why no parent gid*/
{    
#if defined(__MMI_CAMCORDER__)
    mmi_camco_rec_enter_from_cui(cui_gid, p_args);    
#elif defined(__MMI_VIDEO_RECORDER__)
    mmi_vdorec_enter_from_cui(cui_gid, p_args);
#endif
}


U32 cui_vdorec_get_min_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MJPG_SUPPORT
    ret = 60;
#else
    /* MPEG4 */
    ret = 30;
#endif
    
    return ret;
}


void cui_vdorec_close(mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
}


MMI_BOOL cui_vdorec_check_and_display_popup(void)
{
#if defined(__MMI_CAMCORDER__) && !defined(__COSMOS_MMI_PACKAGE__)
	return mmi_camco_check_and_display_popup();
#else
    return MMI_TRUE;
#endif
}

/*
    these two interface is just for transition period only, if all app use FW20 screen, this function is useless
*/
mmi_id cui_vdorec_ex_create(mmi_id parent_gid, mmi_proc_func parent_group_proc)
{
#if defined(__MMI_CAMCORDER__)
    mmi_frm_group_create(GRP_ID_ROOT, parent_gid, parent_group_proc, NULL);
    
    mmi_frm_group_close (SCR_GROUP_ID_CAMCO_EXT_APP);      
    return mmi_frm_group_create(parent_gid,  SCR_GROUP_ID_CAMCO_EXT_APP, mmi_camco_rec_group_proc, NULL);
#elif defined(__MMI_VIDEO_RECORDER__)
    mmi_frm_group_create(GRP_ID_ROOT, parent_gid, parent_group_proc, NULL);
    
    return mmi_frm_group_create(parent_gid,  GRP_ID_AUTO_GEN, mmi_vdorec_app_group_proc, NULL);
#endif

}

void cui_vdorec_ex_run(mmi_id parent_gid, mmi_id cui_gid, p_cui_vdorec_run_struct p_args)
{
    mmi_frm_group_enter(parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_vdorec_run(cui_gid, p_args);
}


void cui_vdorec_ex_close(mmi_id cui_gid)
{
    mmi_group_node_struct node_info;

    mmi_frm_group_get_info(cui_gid, &node_info);

    mmi_frm_group_close(cui_gid);
    mmi_frm_group_close(node_info.parent);
}
