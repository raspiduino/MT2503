/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *  supc_common_config.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SUPC common configuration
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "app_ltlcom.h"
#include "ps2sim_struct.h"
#include "sim_common_enums.h"

#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"

kal_bool supc_check_sim_status(void)
{
#ifdef __GEMINI__ //[MAUI_01629798] mtk01612: kinki_gemini_wifi
      return ((check_sim_card_status(SIM1) != NORMAL_SIM_PRESENCE) && (check_sim_card_status(SIM1) != TEST_SIM_PRESENCE));
#else
      return ((check_sim_card_status() != NORMAL_SIM_PRESENCE) && (check_sim_card_status() != TEST_SIM_PRESENCE));
#endif
}

kal_bool supc_check_sim_ready(module_type mod_id) 
{
#ifdef __GEMINI__ //[MAUI_01629798] mtk01612: kinki_gemini_wifi
    if (mod_id == MOD_SIM_2)
    {
        return KAL_TRUE;
    }
#if (GEMINI_PLUS >= 3)
    if (mod_id == MOD_SIM_3)
    {
        return KAL_TRUE;
    }
#if (GEMINI_PLUS >= 4)
    if (mod_id == MOD_SIM_4)
    {
        return KAL_TRUE;
    }
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
    else
    {
        return KAL_FALSE;
    }
#else
    return KAL_FALSE;
#endif
}

/*MAUI_03055418
EAPOL and preauth EAPOL SM. both eapol sm use the same ssl context
(eap.globalCtx)
*/
kal_bool supc_support_pre_authentication(void)
{
#ifdef __MTK_TARGET__
	#ifdef MT5931
		#define WIFI_SUPPORT_PRE_AUTH 0x9a9a9a9a
		extern kal_int32 wifi_driver_customer_setting[];
		extern kal_uint32 WiFi_Query_Customer_Seting_Version(void);
		kal_uint32 i;
		i = WiFi_Query_Customer_Seting_Version();
		if(wifi_driver_customer_setting[i-1]==WIFI_SUPPORT_PRE_AUTH)
			return KAL_TRUE;
		else
			return KAL_FALSE;
	#else //5921 and other chip default turn off pre-authentication
		return KAL_FALSE;
	#endif
#endif
}
