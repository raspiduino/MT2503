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
 *   CamcoSettingHdlr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camcorder Setting Module
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef MMI_CAMCOSETTINGHDLR_C
#define MMI_CAMCOSETTINGHDLR_C

#include "MMI_include.h"

#ifdef __MMI_CAMCORDER__

#include "mdi_datatype.h"
#include "mmi_features_camcorder.h"
#include "CamcorderResDef.h"
#include "mdi_camera.h"
#include "CamcorderSetting.h"
#include "CamcorderApp.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "cal_comm_def.h"
#include "FileMgrSrvGProt.h"

extern mmi_camco_setting_cntx_struct *const mmi_camco_setting_p;
extern mmi_camco_setting_scene_sel_cntx_struct *const mmi_camco_setting_scene_sel_p;
extern void mmi_camco_osd_draw_add_frame_stop(void);
extern void mmi_camco_osd_set_add_frame_enable(MMI_BOOL is_enable);
extern MMI_BOOL mmi_camco_recsize_vs_codec_vs_qty[MMI_CAMCO_RECSIZE_END][MMI_CAMCO_VISCODEC_END][MMI_CAMCO_VISQTY_END];

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_highlight_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_highlight_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->highlight.is_hilite_mod = MMI_TRUE;

    switch (mmi_camco_setting_p->cur_item_setting)
    {
        case MMI_CAMCO_HIGHLIGHT_OFF:
            /* Turn off LED */
            mmi_camco_highlight_turn_off();
            break;

        case MMI_CAMCO_HIGHLIGHT_ON:
            /* Turn On LED */
            mmi_camco_highlight_turn_on();
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_highlight_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_highlight_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->highlight.is_hilite_mod)
    {
        switch (mmi_camco_setting_p->highlight.cur_value)
        {
            case MMI_CAMCO_HIGHLIGHT_OFF:
                /* Turn off LED */
                mmi_camco_highlight_turn_off();
                break;

            case MMI_CAMCO_HIGHLIGHT_ON:
                /* Turn On LED */
                mmi_camco_highlight_turn_on();
                break;

            default:
                MMI_ASSERT(0);
        }

        mmi_camco_setting_p->highlight.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_iso_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_iso_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */

    /* update mod flag, need restore iso when not apply this setting */
    mmi_camco_setting_p->iso.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_iso_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_iso_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->wb.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */

        mmi_camco_setting_p->iso.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_wb_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_wb_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */
    mmi_camco_update_wb(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->wb.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_wb_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_wb_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->wb.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_wb(mmi_camco_setting_p->wb.cur_value);

        mmi_camco_setting_p->wb.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camev_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_camev_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call core to update EV */
    mmi_camco_update_ev(mmi_camco_setting_p->cur_item_setting);
        
    mmi_camco_setting_p->camev.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camev_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_camev_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->camev.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_ev(mmi_camco_setting_p->camev.cur_value);

        mmi_camco_setting_p->camev.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_vdoev_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_vdoev_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* call core to update EV */
    mmi_camco_update_ev(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->vdoev.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_vdoev_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_vdoev_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->vdoev.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_ev(mmi_camco_setting_p->vdoev.cur_value);

        mmi_camco_setting_p->vdoev.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_effect_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_effect_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */
    mmi_camco_update_effect(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->effect.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_effect_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_effect_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->effect.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_effect(mmi_camco_setting_p->effect.cur_value);

        mmi_camco_setting_p->effect.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sharpness_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sharpness_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */
    mmi_camco_update_sharpness(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->sharpness.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sharpness_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sharpness_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->sharpness.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_sharpness(mmi_camco_setting_p->sharpness.cur_value);

        mmi_camco_setting_p->sharpness.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_contrast_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_contrast_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */
    mmi_camco_update_contrast(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->contrast.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_contrast_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_contrast_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->contrast.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_contrast(mmi_camco_setting_p->contrast.cur_value);

        mmi_camco_setting_p->contrast.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_saturation_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_saturation_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* app conver to drv value and call mdi to update */
    mmi_camco_update_saturation(mmi_camco_setting_p->cur_item_setting);

    mmi_camco_setting_p->saturation.is_hilite_mod = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_saturation_hilite_restore_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_saturation_hilite_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->saturation.is_hilite_mod)
    {
        /* app conver to drv value and call mdi to update */
        mmi_camco_update_saturation(mmi_camco_setting_p->saturation.cur_value);

        mmi_camco_setting_p->saturation.is_hilite_mod = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_shuttersound_hilite_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_shuttersound_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_setting_p->cur_item_setting)
    {
        case MMI_CAMCO_SHUTTERSOUND_OFF:
            /* do nothing */
            break;

        case MMI_CAMCO_SHUTTERSOUND_SOUND_1:
            /* play sound 1 */
            mmi_camco_cam_play_shuttersound(MMI_CAMCO_SHUTTERSOUND_SOUND_1);
            break;

        case MMI_CAMCO_SHUTTERSOUND_SOUND_2:
            /* play sound 2 */
            mmi_camco_cam_play_shuttersound(MMI_CAMCO_SHUTTERSOUND_SOUND_2);
            break;

        case MMI_CAMCO_SHUTTERSOUND_SOUND_3:
            /* play sound 3 */
            mmi_camco_cam_play_shuttersound(MMI_CAMCO_SHUTTERSOUND_SOUND_3);
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camswitchto_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_camswitchto_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_setting_p->cur_item_setting)
    {
        case MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN:
            /* switch to photo albumn */
            mmi_camco_switch_to_imgviewer();
            break;

        case MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER:
            /* switch to video recorder */
            mmi_camco_switch_app();
            break;
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE:
            mmi_camco_cam_switch_to_sublcd();
            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
        case MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA:
            /* switch to main camera */
            mmi_camco_switch_main_camera();
            break;
        case MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA:
            /* switch to sub camera */
            mmi_camco_switch_sub_camera();
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camswitchto_unselected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_camswitchto_unselected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_setting_p->cur_item_setting)
    {
        case MMI_CAMCO_CAMSWITCHTO_PHOTO_ALBUMN:
            /* switch to photo albumn */
            mmi_camco_unswitch_to_imgviewer();
            break;

        case MMI_CAMCO_CAMSWITCHTO_VIDEO_RECORDER:
            /* switch to video recorder */
            mmi_camco_unswitch_app();
            break;
    #ifdef __MMI_CAMCO_CAM_SUBLCD_CAPTURE__
        case MMI_CAMCO_CAMSWITCHTO_SUBLCD_CAPTURE:
            mmi_camco_cam_unswitch_to_sublcd();
            break;
    #endif /* __MMI_CAMCO_CAM_SUBLCD_CAPTURE__ */ 
        case MMI_CAMCO_CAMSWITCHTO_MAIN_CAMERA:
            /* switch to main camera */
            mmi_camco_unswitch_main_camera();
            break;
        case MMI_CAMCO_CAMSWITCHTO_SUB_CAMERA:
            /* switch to sub camera */
            mmi_camco_unswitch_sub_camera();
            break;

        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camev_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_camev_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->camev.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->camev.cur_value = mmi_camco_setting_p->cur_item_setting;

        mmi_camco_update_ev(mmi_camco_setting_p->camev.cur_value);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_vdoev_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_vdoev_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->vdoev.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->vdoev.cur_value = mmi_camco_setting_p->cur_item_setting;

        mmi_camco_update_ev(mmi_camco_setting_p->vdoev.cur_value);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_capmode_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_capmode_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_camco_set_last_capmode((mmi_camco_capmode_enum)mmi_camco_setting_p->capmode.cur_value);
    if (mmi_camco_setting_p->capmode.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->capmode.cur_value = mmi_camco_setting_p->cur_item_setting;
    #ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
        if (mmi_camco_setting_p->capmode.cur_value != MMI_CAMCO_CAPMODE_ADD_FRAME)
        {
            mmi_camco_osd_set_add_frame_enable(MMI_FALSE);
        }
    #endif /* __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__ */ 
        mmi_camco_setting_store_to_nvram();

        /* no restart preview */
        /* set capmode limitation */
        mmi_camco_update_capmode(mmi_camco_setting_p->capmode.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_CAPMODE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_camscenemode_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_camscenemode_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->camscenemode.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->last_camscenemode = (mmi_camco_camscenemode_enum)mmi_camco_setting_p->camscenemode.cur_value;
        mmi_camco_setting_p->camscenemode.cur_value = mmi_camco_setting_p->cur_item_setting;

        /* restart preview */
        mmi_camco_update_camscenemode(mmi_camco_setting_p->camscenemode.cur_value);

        mmi_camco_setting_store_to_nvram();
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_CAMSCENEMODE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_capsize_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_capsize_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->capsize.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->capsize.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* check if need to restart preview */
        mmi_camco_update_capsize();
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_CAPSIZE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_flash_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_flash_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->flash.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->flash.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_setting_scene_sel_p->camscenemode[mmi_camco_setting_p->camscenemode.cur_value].flash
            = mmi_camco_setting_p->flash.cur_value;
        mmi_camco_setting_scene_sel_store_to_nvram();
        /* update parameter */
        mmi_camco_update_flash(mmi_camco_setting_p->flash.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_FLASH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_highlight_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_highlight_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->highlight.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->highlight.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_HIGHLIGHT);        
    }

    if (!mmi_camco_setting_p->highlight.is_hilite_mod)
    {
        switch (mmi_camco_setting_p->highlight.cur_value)
        {
            case MMI_CAMCO_HIGHLIGHT_OFF:
                /* Turn off LED */
                mmi_camco_highlight_turn_off();
                break;

            case MMI_CAMCO_HIGHLIGHT_ON:
                /* Turn On LED */
                mmi_camco_highlight_turn_on();
                break;

            default:
                MMI_ASSERT(0);
        }
    }

    mmi_camco_setting_p->highlight.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_afrange_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_afrange_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afrange.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->afrange.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_afrange(mmi_camco_setting_p->afrange.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_AFRANGE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_facedetect_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_facedetect_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->facedetect.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->facedetect.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_facedetect(mmi_camco_setting_p->facedetect.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_FACEDETECT);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_selftimer_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_selftimer_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->selftimer.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_SELFTIMER);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_iso_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_iso_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_last_iso_binning = MMI_FALSE;
    U16 upperbound_capsize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->iso.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->last_iso = (mmi_camco_iso_enum)mmi_camco_setting_p->iso.cur_value;

        mmi_camco_setting_p->iso.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_setting_scene_sel_p->camscenemode[mmi_camco_setting_p->camscenemode.cur_value].iso
            = mmi_camco_setting_p->iso.cur_value;
        mmi_camco_setting_scene_sel_store_to_nvram();

        if (mmi_camco_setting_is_iso_binning(mmi_camco_setting_p->iso.cur_value))
        {
            mmi_camco_setting_p->is_current_iso_binning = MMI_TRUE;
        }
        else
        {
            mmi_camco_setting_p->is_current_iso_binning = MMI_FALSE;
        }

        if (mmi_camco_setting_is_iso_binning(mmi_camco_setting_p->last_iso))
        {
            is_last_iso_binning = MMI_TRUE;
        }

        if (mmi_camco_setting_p->is_current_iso_binning && !is_last_iso_binning)
        {
            upperbound_capsize = mmi_camco_setting_p->iso_binning.IsoBinningInfo[mmi_camco_setting_p->iso.cur_value].MaxResolution;

            if (mmi_camco_setting_p->capsize.cur_value > mmi_camco_setting_p->mdi_vs_mmi_capsize[upperbound_capsize])
            {
                mmi_camco_setting_p->capsize.cur_value = mmi_camco_setting_p->mdi_vs_mmi_capsize[upperbound_capsize];
                mmi_camco_update_capsize();
            }
        }

        mmi_camco_config_capsize_capability();
        /* update parameter */
        mmi_camco_update_iso(mmi_camco_setting_p->cur_item_setting);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_ISO);            
    }

    mmi_camco_setting_p->iso.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_wb_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_wb_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->wb.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();

    mmi_camco_setting_scene_sel_p->vdoscenemode[mmi_camco_setting_p->vdoscenemode.cur_value].wb
        = mmi_camco_setting_p->wb.cur_value;
    mmi_camco_setting_scene_sel_store_to_nvram();

    mmi_camco_update_wb(mmi_camco_setting_p->wb.cur_value);
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_WB);    

    mmi_camco_setting_p->wb.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_effect_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_effect_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->effect.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();

    mmi_camco_update_effect(mmi_camco_setting_p->effect.cur_value);
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_EFFECT);    

    mmi_camco_setting_p->effect.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_storage_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_storage_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->storage.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->storage.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* need check drive again */
        mmi_camco_update_storage(mmi_camco_setting_p->storage.cur_value);

        if(!mmi_camco_is_drive_avaiable() && mmi_camco_setting_p->storage.cur_value == SRV_FMGR_DRV_CARD_TYPE)
        {
            mmi_camco_switch_non_avaiable_storage(MMI_TRUE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_capqty_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_capqty_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->capqty.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->capqty.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* update parameter */
        mmi_camco_update_capqty(mmi_camco_setting_p->capqty.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_CAPQTY);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_afzone_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_afzone_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afzone.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->afzone.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* update parameter */
        mmi_camco_update_afzone(mmi_camco_setting_p->afzone.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_AFZONE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_aemeter_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_aemeter_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->aemeter.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->aemeter.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_setting_scene_sel_p->vdoscenemode[mmi_camco_setting_p->vdoscenemode.cur_value].aemeter
            = mmi_camco_setting_p->aemeter.cur_value;
        mmi_camco_setting_scene_sel_store_to_nvram();

        /* update parameter */
        mmi_camco_update_aemeter(mmi_camco_setting_p->aemeter.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_AEMETER);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sharpness_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sharpness_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->sharpness.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();
    mmi_camco_update_sharpness(mmi_camco_setting_p->cur_item_setting);
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_SHARPNESS);    

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->camscenemode[mmi_camco_setting_p->camscenemode.cur_value].sharpness
            = mmi_camco_setting_p->sharpness.cur_value;
    }
    else
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[mmi_camco_setting_p->vdoscenemode.cur_value].sharpness
            = mmi_camco_setting_p->sharpness.cur_value;
    }
    mmi_camco_setting_scene_sel_store_to_nvram();
    /* already set parameter when item highlited - no need udpate */

    mmi_camco_setting_p->sharpness.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_contrast_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_contrast_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->contrast.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();
    mmi_camco_update_contrast(mmi_camco_setting_p->cur_item_setting);
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_CONTRAST);    

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->camscenemode[mmi_camco_setting_p->camscenemode.cur_value].contrast
            = mmi_camco_setting_p->contrast.cur_value;
    }
    else
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[mmi_camco_setting_p->vdoscenemode.cur_value].contrast
            = mmi_camco_setting_p->contrast.cur_value;
    }
    mmi_camco_setting_scene_sel_store_to_nvram();
    /* already set parameter when item highlited - no need udpate */

    mmi_camco_setting_p->contrast.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_saturation_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_saturation_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->saturation.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();
    mmi_camco_update_saturation(mmi_camco_setting_p->cur_item_setting);
    mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_SATURATION);    

    if (mmi_camco_setting_p->active_app == MMI_CAMCO_SETTING_APP_CAMERA)
    {
        mmi_camco_setting_scene_sel_p->camscenemode[mmi_camco_setting_p->camscenemode.cur_value].saturation
            = mmi_camco_setting_p->saturation.cur_value;
    }
    else
    {
        mmi_camco_setting_scene_sel_p->vdoscenemode[mmi_camco_setting_p->vdoscenemode.cur_value].saturation
            = mmi_camco_setting_p->saturation.cur_value;
    }
    mmi_camco_setting_scene_sel_store_to_nvram();
    /* already set parameter when item highlited - no need udpate */

    mmi_camco_setting_p->saturation.is_hilite_mod = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_timestamp_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_timestamp_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->timestamp.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->timestamp.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* need set overlay, need re-start preview */
        mmi_camco_update_timestamp(mmi_camco_setting_p->timestamp.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_TIMESTAMP);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_shuttersound_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_shuttersound_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camco_setting_p->shuttersound.cur_value = mmi_camco_setting_p->cur_item_setting;
    mmi_camco_setting_store_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_banding_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_banding_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->banding.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->banding.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* update parameter or restart preview */
        mmi_camco_update_banding(mmi_camco_setting_p->banding.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_BANDING);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_vdoswitchto_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_vdoswitchto_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_camco_setting_p->cur_item_setting)
    {
        case MMI_CAMCO_VDOSWITCHTO_VIDEO_PLAYER:
            /* switch to video player */
            mmi_camco_switch_to_vdoply();
            break;

        case MMI_CAMCO_VDOSWITCHTO_CAMERA:
            /* switch to video recorder */
            mmi_camco_switch_app();
            break;

        case MMI_CAMCO_VDOSWITCHTO_MAIN_CAMERA:
            /* switch to main camera */
            mmi_camco_switch_main_camera();
            break;
        case MMI_CAMCO_VDOSWITCHTO_SUB_CAMERA:
            /* switch to sub camera */
            mmi_camco_switch_sub_camera();
            break;

        default:
            MMI_ASSERT(0);
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_camco_timelaps_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_camco_timelaps_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->timelaps.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->timelaps.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_timelaps(mmi_camco_setting_p->timelaps.cur_value);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_camco_vdoscenemode_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_vdoscenemode_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->vdoscenemode.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->last_vdoscenemode = (mmi_camco_vdoscenemode_enum)mmi_camco_setting_p->vdoscenemode.cur_value;
        mmi_camco_setting_p->vdoscenemode.cur_value = mmi_camco_setting_p->cur_item_setting;

        /* set vdoscenemode limitation */
        mmi_camco_update_vdoscenemode(mmi_camco_setting_p->vdoscenemode.cur_value);
        mmi_camco_setting_store_to_nvram();
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_VDOSCENEMODE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_recsize_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_recsize_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->recsize.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->recsize.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_vdosize(mmi_camco_setting_p->recsize.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_RECSIZE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_sizelimit_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_sizelimit_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->sizelimit.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->sizelimit.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_update_recsizelimit(mmi_camco_setting_p->sizelimit.cur_value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_timelimit_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_timelimit_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->timelimit.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->timelimit.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_update_rectimelimit(mmi_camco_setting_p->timelimit.cur_value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_limit_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_limit_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->limit.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->limit.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        mmi_camco_update_reclimit(mmi_camco_setting_p->limit.cur_value);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_camco_visqty_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_visqty_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->visqty.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->visqty.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */

        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_VISQTY);

        mmi_camco_update_visqty(mmi_camco_setting_p->visqty.cur_value);


    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_afmode_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_afmode_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->afmode.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->afmode.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* set parameter */
        mmi_camco_update_afmode(mmi_camco_setting_p->afmode.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_AFMODE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_recaud_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_recaud_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->recaud.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->recaud.cur_value = mmi_camco_setting_p->cur_item_setting;
        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_recaud(mmi_camco_setting_p->recaud.cur_value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_viscodec_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_viscodec_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->viscodec.cur_value != mmi_camco_setting_p->cur_item_setting)
    {
        mmi_camco_setting_p->viscodec.cur_value = mmi_camco_setting_p->cur_item_setting;

        mmi_camco_setting_store_to_nvram();

        /* restart preview */
        mmi_camco_update_visformat(mmi_camco_setting_p->viscodec.cur_value);
        mmi_camco_custom_update((recoorder_config_setting_target)MMI_CAMCO_SETTING_VISCODEC);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_camco_restoredefault_selected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_camco_restoredefault_selected_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_camco_setting_p->restoredefault.cur_value == MMI_CAMCO_RESTOREDEFAULT_YES)
    {
        /* restart preview */
        mmi_camco_update_restore_default_setting(mmi_camco_setting_p->restoredefault.cur_value);
    }

}

#endif /* __MMI_CAMCORDER__ */ /* MMI_CAMCOSETTINGHDLR_C */

#endif /* MMI_CAMCOSETTINGHDLR_C */ 

