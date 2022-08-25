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
 * FactoryModeQuickTest.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for Factory Mode Quick test
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
 ********************************************************************************/
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */
     
#if defined(__MMI_AP_DCM_FM__)
#pragma arm section rodata = "DYNAMIC_CODE_FM_RODATA" , code = "DYNAMIC_CODE_FM_ROCODE"
#elif defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_FM_RODATA" , code = "DYNAMIC_CODE_COSMOS_FM_ROCODE"
#endif /* #ifdef __MMI_AP_DCM_FM__ */ 


#include "MMI_features.h"

#ifdef __MMI_FACTORY_MODE__

#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "kal_general_types.h"
#include "GlobalResDef.h"


extern void mmi_fm_common_set_left_softkey(U32 item)
{    
    if (item)
    {
        change_left_softkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        change_left_softkey(STR_GLOBAL_ON, 0);
    }

    redraw_left_softkey();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fm_set_general_goback_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

extern void mmi_fm_set_general_goback_function(void)
{
    SetRightSoftkeyFunction( mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#if defined(__COSMOS_MMI_PACKAGE__)
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_BACK, KEY_EVENT_UP);
#endif
   
}


#endif

#if (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__))
#pragma arm section rodata , code
#endif /* (defined(__MMI_AP_DCM_FM__) || defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)) */


#ifdef __DCM_WITH_COMPRESSION_MMI_POOL_A__ 

void mmi_fm_send_dcm_unload_process(void)
{
    if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_COSMOS_FM)== KAL_TRUE)
    {
        DCM_Unload(DYNAMIC_CODE_COMPRESS_COSMOS_FM);
    }
}

#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__  */


