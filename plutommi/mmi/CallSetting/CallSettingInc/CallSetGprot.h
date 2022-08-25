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
 * CallSetGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Call setting application global prototypes
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CALLSET_GPROT_H
#define CALLSET_GPROT_H

#include "MMI_features.h"

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Typedef                                                            
*****************************************************************************/

/****************************************************************************
* structure                                                            
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_center_launch
 * DESCRIPTION
 *  launch call center
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_center_launch(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_launch
 * DESCRIPTION
 *  launch call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_setting_launch(void);


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim1_launch
 * DESCRIPTION
 *  launch sim1 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_setting_sim1_launch(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim2_launch
 * DESCRIPTION
 *  launch sim2 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_setting_sim2_launch(void);

#if (MMI_MAX_SIM_NUM>=3)

/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim3_launch
 * DESCRIPTION
 *  launch sim3 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_setting_sim3_launch(void);


#if (MMI_MAX_SIM_NUM>=4)
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_call_setting_sim4_launch
 * DESCRIPTION
 *  launch sim4 call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_call_setting_sim4_launch(void);

#endif /* MMI_MAX_SIM_NUM>=4*/
#endif /* MMI_MAX_SIM_NUM>=3*/
#endif /*  (MMI_MAX_SIM_NUM >= 2) */


#ifdef __MMI_CM_BLACK_LIST__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_blacklist_launch
 * DESCRIPTION
 *  launch blacklist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_blacklist_launch(void);
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __CTM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_ctm_setting_launch
 * DESCRIPTION
 *  launch CTM setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_ctm_setting_launch(void);
#endif /* __CTM_SUPPORT__ */

#ifdef __VOICE_CHANGER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_callset_magic_voice_launch
 * DESCRIPTION
 *  interface to launch magic voice setting menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_callset_magic_voice_launch(void);
#endif /* __VOICE_CHANGER_SUPPORT__ */


#endif /* CALLSET_GPROT_H */ 

