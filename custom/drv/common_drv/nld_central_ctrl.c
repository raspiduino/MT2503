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
 *    nld_central_ctrl.c
 *
 * Project:
 * --------
 *   Dragonfly
 *
 * Description:
 * ------------
 *   This file contains the implementation of NLD share bus central control mechanism.
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


#include "kal_release.h"      	/* Basic data type */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "nld_central_ctrl.h"

#if (!defined(__UBL__) && !defined(__FUE__))
#pragma arm section code = "PRIMARY_ROCODE", rwdata = "PRIMARY_RW", rodata = "PRIMARY_RODATA"
#endif

#if defined (__NLD_CENTRAL_CTRL__)
	
//NFI MODULE header
#if defined(NAND_SUPPORT)
#include "NAND_MTD_FDM50.h"	
#endif

#if (!defined(DRV_LCD_NOT_EXIST) && (defined(__FAST_LOGO__)||defined(__CARD_DOWNLOAD__)))
extern set_lcd_driving_current_centralize(kal_uint8 nld_driving);
#endif


#if (!defined(__UBL__) && !defined(__FUE__))
//WIFI MODULE header

//TD MODULE headerS
#include "ast_hif_hw.h"

#if (!defined(DRV_LCD_NOT_EXIST) && !defined(__FAST_LOGO__)&& !defined(__CARD_DOWNLOAD__))
extern set_lcd_driving_current_centralize(kal_uint8 nld_driving);
#endif

#if defined(__WIFI_SUPPORT__) && defined(__CUSTOM_WIFI_FEATURES_SWITCH__)
extern void set_wifi_ehpi_driving_current(kal_uint8 current);
#endif
extern NLI_ARB_Set_Handover_Cycle(kal_uint32 handoverType,kal_uint32 handoverCycle);

#endif

kal_uint32 nld_driving = NLD_DEFAULT_DRIVING_CURRENT;
kal_uint32 nli_handover_type = NLI_DEFAULT_HANDOVER_TYPE;
kal_uint32 nli_handover_cycle = NLI_DEFAULT_HANDOVER_CYCLE;

#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 

void NLDShareBusCenCtrl(void)
{	
	#if defined (__NLD_CENTRAL_CTRL__)
	
	#if (defined(__UBL__) || defined(__FUE__)) // put into bootloader
	//NFI MODULE DRIVING SETTING		
	#if defined(NAND_SUPPORT)
	set_nfi_driving_current(nld_driving);
	#endif

	//LCD MODULE DRIVING SETTING
	#if (!defined(DRV_LCD_NOT_EXIST) && (defined(__FAST_LOGO__) || defined(__CARD_DOWNLOAD__)))
	set_lcd_driving_current_centralize(nld_driving);
	#endif		
	
	#else //not put into bootloader
	
	//LCD MODULE DRIVING SETTING
	#if (!defined(DRV_LCD_NOT_EXIST) && !defined(__FAST_LOGO__) && !defined(__CARD_DOWNLOAD__))
	set_lcd_driving_current_centralize(nld_driving);
	#endif
	
	//WIFI MODULE DRIVING SETTING     
  #if defined(__WIFI_SUPPORT__) && defined(__CUSTOM_WIFI_FEATURES_SWITCH__)
  set_wifi_ehpi_driving_current(nld_driving);
  #endif
	
	//TD MODULE DRIVING SETTING
	#if defined(__AST_TL1_TDD__)
  ast_hif_set_driving_current(nld_driving);
  #endif
	//handover timing
	NLI_ARB_Set_Handover_Cycle(nli_handover_type,nli_handover_cycle);
 	#endif
	
#endif
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
