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
 *   CamcorderSettingHdlr.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_CAMCORDER__

/* hilite hdlr */
extern void mmi_camco_highlight_hilite_hdlr(void);
extern void mmi_camco_iso_hilite_hdlr(void);
extern void mmi_camco_wb_hilite_hdlr(void);
extern void mmi_camco_effect_hilite_hdlr(void);
extern void mmi_camco_sharpness_hilite_hdlr(void);
extern void mmi_camco_contrast_hilite_hdlr(void);
extern void mmi_camco_saturation_hilite_hdlr(void);
extern void mmi_camco_shuttersound_hilite_hdlr(void);

/* restore hilite hdlr */
extern void mmi_camco_highlight_hilite_restore_hdlr(void);
extern void mmi_camco_iso_hilite_restore_hdlr(void);
extern void mmi_camco_wb_hilite_restore_hdlr(void);
extern void mmi_camco_effect_hilite_restore_hdlr(void);
extern void mmi_camco_sharpness_hilite_restore_hdlr(void);
extern void mmi_camco_contrast_hilite_restore_hdlr(void);
extern void mmi_camco_saturation_hilite_restore_hdlr(void);

/* select hdlr */
extern void mmi_camco_camswitchto_selected_hdlr(void);
extern void mmi_camco_camswitchto_unselected_hdlr(void);
extern void mmi_camco_capmode_selected_hdlr(void);
extern void mmi_camco_camscenemode_selected_hdlr(void);
extern void mmi_camco_capsize_selected_hdlr(void);
extern void mmi_camco_flash_selected_hdlr(void);
extern void mmi_camco_highlight_selected_hdlr(void);
extern void mmi_camco_afrange_selected_hdlr(void);
extern void mmi_camco_facedetect_selected_hdlr(void);
extern void mmi_camco_selftimer_selected_hdlr(void);
extern void mmi_camco_iso_selected_hdlr(void);
extern void mmi_camco_wb_selected_hdlr(void);
extern void mmi_camco_effect_selected_hdlr(void);
extern void mmi_camco_storage_selected_hdlr(void);
extern void mmi_camco_capqty_selected_hdlr(void);
extern void mmi_camco_afzone_selected_hdlr(void);
extern void mmi_camco_aemeter_selected_hdlr(void);
extern void mmi_camco_sharpness_selected_hdlr(void);
extern void mmi_camco_contrast_selected_hdlr(void);
extern void mmi_camco_saturation_selected_hdlr(void);
extern void mmi_camco_timestamp_selected_hdlr(void);
extern void mmi_camco_shuttersound_selected_hdlr(void);
extern void mmi_camco_banding_selected_hdlr(void);
extern void mmi_camco_vdoswitchto_selected_hdlr(void);
extern void mmi_camco_vdoscenemode_selected_hdlr(void);
extern void mmi_camco_recsize_selected_hdlr(void);
extern void mmi_camco_sizelimit_selected_hdlr(void);
extern void mmi_camco_timelimit_selected_hdlr(void);
extern void mmi_camco_limit_selected_hdlr(void);
extern void mmi_camco_visqty_selected_hdlr(void);
extern void mmi_camco_afmode_selected_hdlr(void);
extern void mmi_camco_recaud_selected_hdlr(void);
extern void mmi_camco_viscodec_selected_hdlr(void);
extern void mmi_camco_restoredefault_selected_hdlr(void);
extern void mmi_camco_camev_hilite_restore_hdlr(void);
extern void mmi_camco_vdoev_hilite_hdlr(void);
extern void mmi_camco_camev_selected_hdlr(void);
extern void mmi_camco_vdoev_selected_hdlr(void);
extern void mmi_camco_camev_hilite_hdlr(void);
//extern void mmi_camco_vdoev_hilite_hdlr(void);
#endif /* __MMI_CAMCORDER__ */ 

