/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_tsconfig.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the custom configurable APIs for Boot Loader
 *
 * Author:
 * -------
 *   [AUTOGEN_GenVersion]
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * 02 24 2014 yinli.liang
 * fix build error in custom_tsconfig.c
 *
 * 02 11 2014 yinli.liang
 * .
 *
 * 01 27 2014 yinli.liang
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifdef __MTK_TARGET__ 
#include "custom_tsconfig.h"

#if defined(__TINY_SYS_AP__)
/*************************************************************************
* FUNCTION
*  custom_get_TINYSYS_ROM1_on_Flash
*
* DESCRIPTION
*  Retrieve the base address where flashtool download the TINYSYS_ROM1 binary
*  This function must sync with scatter file structure
*
* PARAMETERS
*  pBase: [IN] pointer to download base address
* RETURNS
*  KAL_TRUE if get base address and length, otherwise, KAL_FALSE.
*************************************************************************/
kal_bool custom_get_TINYSYS_ROM1_on_Flash(kal_uint32 *pBase)
{
[AUTOGEN_SCAT_C_Gen_TEMPLATE_TINYSYS_ROM1_ON_FLASH]
}
/*************************************************************************
* FUNCTION
*  custom_get_TINYSYS_ROM2_on_Flash
*
* DESCRIPTION
*  Retrieve the base address where flashtool download the TINYSYS_ROM2 binary
*  This function must sync with scatter file structure
* PARAMETERS
*  pBase: [IN] pointer to download base address
* RETURNS
*  KAL_TRUE if get base address and length, otherwise, KAL_FALSE.
*************************************************************************/
kal_bool custom_get_TINYSYS_ROM2_on_Flash(kal_uint32 *pBase)
{
[AUTOGEN_SCAT_C_Gen_TEMPLATE_TINYSYS_ROM2_ON_FLASH]
}

/*************************************************************************
* FUNCTION
*  custom_get_TINYSYS_ROM1_LV_Info
*
* DESCRIPTION
*  Retrieve the information of TINYSYS_ROM1 
*
* PARAMETERS
*  pBase: [IN] pointer to TINYSYS_ROM1 LV base address
* RETURNS
*  KAL_TRUE if get base address and length, otherwise, KAL_FALSE.
*************************************************************************/
kal_bool custom_get_TINYSYS_ROM1_LV_Info(kal_uint32 *pBase)
{
[AUTOGEN_SCAT_C_Gen_TEMPLATE_TINYSYS_ROM1_LV_INFO]
}
/*************************************************************************
* FUNCTION
*  custom_get_TINYSYS_ROM2_LV_Info
*
* DESCRIPTION
*  Retrieve the information of TINYSYS_ROM2 
*
* PARAMETERS
*  pBase: [IN] pointer to TINYSYS_ROM2 LV base address
* RETURNS
*  KAL_TRUE if get base address and length, otherwise, KAL_FALSE.
*************************************************************************/
kal_bool custom_get_TINYSYS_ROM2_LV_Info(kal_uint32 *pBase)
{
[AUTOGEN_SCAT_C_Gen_TEMPLATE_TINYSYS_ROM2_LV_INFO]
}
#endif //defined(__TINY_SYS_AP__)



#if defined(__TINY_SYS_TS__)
[AUTOGEN_SCAT_C_Gen_TS_REGION_SYMBOL]

/*************************************************************************
* FUNCTION
*  custom_query_ts_dump_region
*
* DESCRIPTION
*  This function builds up the table of DUMP REGIONs on tiny system
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_query_ts_dump_region(EXTSRAM_REGION_INFO_T* region)
{
[AUTOGEN_SCAT_C_Gen_TS_TEMPLATE_DUMP_REGION_ASSIGN]
    return TS_DUMP_REGION_COUNT*2;
}

#endif //defined(__TINY_SYS_TS__)


#endif /* __MTK_TARGET__ */
