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
 *  OTFRes.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  On-The-Fly Resource Loader, MoDIS only.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MTK_TARGET__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_include.h"
#include "mmiapi.h"
#include "OTFResGprot.h"
#include "NotificationGprot.h"

#if defined(__COSMOS_MMI_PACKAGE__)
#ifdef __MMI_THEMES_APPLICATION__
#include "mmi_rp_vapp_theme_def.h"
#endif /*__MMI_THEMES_APPLICATION__*/
#endif /* defined(__COSMOS_MMI_PACKAGE__) */

/*****************************************************************************
 * Type Definition
 *****************************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    mmi_otfres_tool_msg_struct* param;
} mmi_otf_res_msg_struct;


/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static void* g_mmi_otf_res_data_ptr[MMI_OTFRES_MSG_END] = {NULL};
static int g_mmi_otf_res_return_vaule = 0;  /* not used now */


/*****************************************************************************
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_msg_handler
 * DESCRIPTION
 *  Message handler for events from MoDIS UI
 * PARAMETERS
 *  msg     [IN] message
 * RETURNS
 *  whether handle the event
 *****************************************************************************/
static U8 mmi_res_otf_msg_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_otf_res_msg_struct* data = (mmi_otf_res_msg_struct*)msg;
    mmi_otfres_tool_msg_struct *argv = data->param;
    FuncPtr finish_cb = (FuncPtr)argv->finish_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_otf_res_data_ptr[argv->event_id] = argv->data_ptr;

    if (argv->event_id == MMI_OTFRES_MSG_THEME_UPDATE)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        extern MMI_BOOL mmi_res_set_otf_theme(void);
        extern void vapp_launcher_restart();
        extern void mmi_fe_init_font_effect_theme();

        mmi_res_set_otf_theme();

#if defined(__MMI_FONT_EFFECTS__)
        mmi_fe_init_font_effect_theme();
#endif /* __MMI_FONT_EFFECTS__ */

        vapp_launcher_restart();

#ifdef __MMI_THEMES_APPLICATION__
        {
            mmi_event_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_THEME_CHANGED);
            MMI_FRM_CB_EMIT_POST_EVENT(&evt);
        }

        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_GENERAL,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR *)GetString(STR_ID_VAPP_THEME_CHANGED));
#endif /*__MMI_THEMES_APPLICATION__*/		
#endif /* defined(__COSMOS_MMI_PACKAGE__) */
    }

    if (finish_cb)
    {
        finish_cb();
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_init
 * DESCRIPTION
 *  Init OTF resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_otf_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_OTFRES_UPDATE_IND, mmi_res_otf_msg_handler, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_get_return_value
 * DESCRIPTION
 *  pass return value to MoDIS UI
 * PARAMETERS
 *  void
 * RETURNS
 *  return value
 *****************************************************************************/
int mmi_res_otf_get_return_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_otf_res_return_vaule;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_get_layout
 * DESCRIPTION
 *  get the layout resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_res_otf_get_layout(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_otfres_layout_update_struct* data = (mmi_otfres_layout_update_struct*)g_mmi_otf_res_data_ptr[MMI_OTFRES_MSG_LAUOUT_UPDATE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data)
    {
        S32 i = 0;

        for (i = 0 ; i < data->number_of_layout ; i ++)
        {
            if (data->layout_ids[i] == id)
            {
                return (S8*)data->layout_ptrs[i];
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_get_theme
 * DESCRIPTION
 *  get the theme resource
 * PARAMETERS
 *  void
 * RETURNS
 *  OTF theme resource
 *****************************************************************************/
S8* mmi_res_otf_get_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*)g_mmi_otf_res_data_ptr[MMI_OTFRES_MSG_THEME_UPDATE];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_res_otf_update
 * DESCRIPTION
 *  This function is used by MoDIS UI to update the OTF resource
 * PARAMETERS
 *  param   [IN]    date of the message
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_res_otf_update(int param)
{
	mmi_otf_res_msg_struct* data = NEW_LOCAL_PTR(mmi_otf_res_msg_struct);

    data->param = (mmi_otfres_tool_msg_struct*)param;
	SEND_MESSAGE(MOD_MMI, MOD_MMI, 0, MSG_ID_OTFRES_UPDATE_IND, data, NULL);
}

#endif /* __MTK_TARGET__ */

