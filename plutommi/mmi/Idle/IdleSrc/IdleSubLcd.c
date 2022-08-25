/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleSubLcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the idle screen on sub-LCD.
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

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "IdleProt.h"
#include "IdleMain.h"
#include "IdleCommon.h"
#include "IdleGprot.h"
#include "gui_data_types.h"
#include "mmi_frm_history_gprot.h"
#include "DebugInitDef_Int.h"

#if defined(__MMI_AUDIO_PLAYER__)
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#endif /* defined(__MMI_AUDIO_PLAYER__) */

// auto add by kw_check begin
#include "MMIDataType.h"
// auto add by kw_check end 


/****************************************************************************
 * Prototype
 ****************************************************************************/

static void mmi_idle_sublcd_exit(void);

static void mmi_idle_sublcd_entry(void);


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sublcd_get_text
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  text1           : [IN]
 *  text2           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_sublcd_get_text(U8 **text1, U8 **text2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj;
    mmi_idle_service_indication_struct *service_indication;

#if defined(__MMI_AUDIO_PLAYER__)
    extern audply_struct g_audply;
    extern BOOL mmi_audply_is_playing(void);
#endif /* defined(__MMI_AUDIO_PLAYER__) */

#if defined(__MMI_MEDIA_PLAYER__)
    extern MMI_BOOL mmi_medply_if_show_idle_string(void);
    extern UI_string_type mmi_medply_get_idle_string(void);
#endif /* defined(__MMI_MEDIA_PLAYER__) */

#if defined(__MMI_FM_RADIO__)
    extern BOOL mmi_fmrdo_is_power_on(void);
    extern UI_string_type mmi_fmrdo_get_channel_name_or_freq(void);
#if defined(__MMI_FM_RADIO_RDS__)
    extern BOOL mmi_fmrdo_rds_is_on(void);
    extern UI_string_type mmi_fmrdo_rds_get_rds_text(void);
#endif /* defined(__MMI_FM_RADIO_RDS__) */
#endif /* defined(__MMI_FM_RADIO__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(text1 && text2);

    *text1 = NULL;
    *text2 = NULL;

    /*
     * Priority 1: Audio player
     */
#if defined(__MMI_AUDIO_PLAYER__)
    if (mmi_audply_is_playing())
    {
        *text1 = (U8 *)g_audply.title;
        return;
    }
#endif /* defined(__MMI_AUDIO_PLAYER__) */

    /*
     * Priority 2: media player
     */
#if defined(__MMI_MEDIA_PLAYER__)
    if (mmi_medply_if_show_idle_string())
    {
        *text1 = (U8 *)mmi_medply_get_idle_string();
        return;
    }
#endif /* defined(__MMI_MEDIA_PLAYER__) */

    /*
     * Priority 3: FM radio
     */
#if defined(__MMI_FM_RADIO__)
    if (mmi_fmrdo_is_power_on())
    {
    #if defined(__MMI_FM_RADIO_RDS__)
        if(mmi_fmrdo_rds_is_on())
        {
            *text1 = (U8 *)mmi_fmrdo_rds_get_rds_text();
        }
        else
    #endif /* defined(__MMI_FM_RADIO_RDS__) */
        {
            *text1 = (U8 *) mmi_fmrdo_get_channel_name_or_freq();
        }

        return;
    }
#endif /* defined(__MMI_FM_RADIO__) */

    /*
     * Priority 4: Network name
     *
     *  Single SIM
     *      Line 1: Network name
     *      Line 2: SPN
     *
     *  Dual SIM
     *      Line 1: Network name of SIM 1
     *      Line 2: Network name of SIM 2
     */
    obj = mmi_idle_get_obj();
    MMI_ASSERT(obj);

    mmi_idle_update_service_indication_context(obj);

    service_indication = mmi_idle_get_service_indication_context(obj, MMI_SIM1);

    *text1 = (U8 *)service_indication->line1;

#if !defined(__MMI_DUAL_SIM__)
    *text2 = (U8 *)service_indication->line2;
#else
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_DUAL_SIM__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sublcd_exit
 * DESCRIPTION
 *  This function exits the idle screen on the sub-LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_sublcd_exit(void)
{
#if defined(__MMI_SUBLCD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode hist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hist.scrnID = SCR_ID_IDLE_SUBLCD;
    hist.entryFuncPtr = mmi_idle_sublcd_entry;

    AddSubLCDHistoryWithScrID(&hist, SCR_ID_IDLE_SUBLCD);
#endif /* defined(__MMI_SUBLCD__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_sublcd_entry
 * DESCRIPTION
 *  This function entries the idle screen on the sub-LCD.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_sublcd_entry(void)
{
#if defined(__MMI_SUBLCD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *text1, *text2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();

    if (!srv_clam_is_close())
    {
        ShowCategory313Screen(IMG_ID_IDLE_SUBLCD_LOGO, NULL);
    }
    else
    {
        mmi_idle_sublcd_get_text(&text1, &text2);

        wgui_cat312_setinfo1(text1);
        wgui_cat312_setinfo2(text2);

        ShowCategory312Screen(0, 0, NULL);
    }

    SetSubLCDExitHandler(mmi_idle_sublcd_exit);
#endif /* defined(__MMI_SUBLCD__) */
}


/* For the detail information, please refer to the IdleGprot.h */
void mmi_idle_sublcd_display(void)
{
#if defined(__MMI_SUBLCD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplaySubLCDScreen(SCR_ID_IDLE_SUBLCD, mmi_idle_sublcd_entry, MMI_TRUE);
#endif /* defined(__MMI_SUBLCD__) */
}


/* For the detail information, please refer to the IdleGprot.h */
MMI_BOOL mmi_idle_sublcd_is_active(void)
{
#if defined(__MMI_SUBLCD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetSubLCActiveScreenId() == SCR_ID_IDLE_SUBLCD? MMI_TRUE : MMI_FALSE;
#else
    return MMI_FALSE;
#endif /* defined(__MMI_SUBLCD__) */
}

