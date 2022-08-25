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
 *  mmi_frm_utility_gprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework utility export function declaration
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_UTILITY_GPROT_H
#define MMI_FRM_UTILITY_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
* Include header file
*****************************************************************************/

#include "MMI_features.h"
#include "stack_config.h"
#include "MMIDataType.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __GEMINI__
#if (MMI_MAX_SIM_NUM == 4)
#define MMI_SIM_TOTAL 4
#define MMI_SIM_ALL (MMI_SIM1 | MMI_SIM2 | MMI_SIM3 | MMI_SIM4)
#elif (MMI_MAX_SIM_NUM == 3)
#define MMI_SIM_TOTAL 3
#define MMI_SIM_ALL (MMI_SIM1 | MMI_SIM2 | MMI_SIM3)
#else
#define MMI_SIM_TOTAL 2
#define MMI_SIM_ALL (MMI_SIM1 | MMI_SIM2)
#endif /* MMI_MAX_SIM_NUM */
#else /* __GEMINI__ */
#define MMI_SIM_TOTAL 1
#define MMI_SIM_ALL (MMI_SIM1)
#endif /* __GEMINI__ */


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_FRM_CABC_MODE_OFF,
    MMI_FRM_CABC_MODE_UI,
    MMI_FRM_CABC_MODE_STILL,
    MMI_FRM_CABC_MODE_MOVING,
    MMI_FRM_CABC_MODE_END_OF_ENUM
} mmi_frm_cabc_mode_enum;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sim_to_index
 * DESCRIPTION
 *  Get SIM index according SIM enum.
 * PARAMETERS
 *  sim         [IN]       MMI SIM enum.
 * RETURNS
 *  return corresponding SIM index.
 *****************************************************************************/
extern U32 mmi_frm_sim_to_index(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_index_to_sim
 * DESCRIPTION
 *  Get SIM enum according SIM index
 * PARAMETERS
 *  sim         [IN]       MMI SIM index.
 * RETURNS
 *  return corresponding SIM enum.
 *****************************************************************************/
extern mmi_sim_enum mmi_frm_index_to_sim(U32 index);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_sim_to_l4c_mod
 * DESCRIPTION
 *  Get L4C module id according SIM enum.
 * PARAMETERS
 *  sim         [IN]       MMI SIM enum.
 * RETURNS
 *  return corresponding L4C module id.
 *****************************************************************************/
extern module_type mmi_frm_sim_to_l4c_mod(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_l4c_mod_to_sim
 * DESCRIPTION
 *  Get SIM enum according L4C module id.
 * PARAMETERS
 *  mod_id          [IN]       L4C module id.
 * RETURNS
 *  return corresponding MMI sim enum.
 *****************************************************************************/
extern mmi_sim_enum mmi_frm_l4c_mod_to_sim(module_type mod_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_cabc_mode
 * DESCRIPTION
 *  Sets CABC mode.
 * PARAMETERS
 *  mode          [IN]       CABC mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_set_cabc_mode(mmi_frm_cabc_mode_enum mode);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_cabc_mode
 * DESCRIPTION
 *  Returns the current CABC mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  current CABC mode
 *****************************************************************************/
extern mmi_frm_cabc_mode_enum mmi_frm_get_cabc_mode(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_cabc_mode
 * DESCRIPTION
 *  Resets CABC mode to default.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_reset_cabc_mode(void);


#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* MMI_FRM_UTILITY_GPROT_H */ 



