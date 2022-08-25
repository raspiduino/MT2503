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
 * EcompassDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines enum values of Ecompass applications.
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_ECOMPASS_H
#define  _MMI_ECOMPASS_H
#include "MMI_features.h"

#include "MMIDataType.h"
//#include "EcompassResDef.h"
#include "mmi_rp_app_ecompass_def.h"

#define MMI_EC_MAX_COUNTRIES           (STR_ID_EC_CNTR_TOTAL - (STR_ID_EC_CNTR_BASE))
#define MMI_EC_MAX_CITIES              (STR_ID_EC_CT_TOTAL - (STR_ID_EC_CT_BASE + 1))
#define MMI_EC_NUM_NVRAM_RECORDS       ((MMI_EC_MAX_CITIES + 1)/2)

#define MMI_EC_SIGSTN_LEN				30
//#define MMI_EC_NUM_ITEMS_DEC_SCR		4
#define MMI_EC_MAX_ANGLE				4
#define MMI_EC_MECCA_STR_LEN			30
#define MMI_EC_MAX_CIT_SCR				15
#define MMI_EC_CURR_HILITE				1
#define MMI_EC_ZERO                     0
#define MMI_EC_THREE_SIXTY				360
#define MMI_EC_DECIMAL_RADIX			10
#define MMI_EC_MULTITAP_COUNTRIES		26

typedef enum
{
    MMI_EC_SIGSTN_STRONG = 0,
    MMI_EC_SIGSTN_WEAK,
    MMI_EC_SIGSTN_TOTAL
} MMI_EC_SIGSTN_ENUM;

typedef enum
{
    MMI_EC_DRC_EAST = 0,
    MMI_EC_DRC_WEST,
    MMI_EC_DRC_TOTAL
} MMI_EC_DRC_ENUM;

typedef enum
{
    MMI_EC_DIR_ZERO = 0,
    MMI_EC_DIR_NIN = 90,
    MMI_EC_DIR_OET = 180,
    MMI_EC_DIR_TSY = 270,
    MMI_EC_DIR_TST = 360
} MMI_EC_DIR_ENUM;

typedef enum
{
    MMI_EC_OPTION_SL,
    MMI_EC_OPTION_SD,
    MMI_EC_OPTION_CL,
    MMI_EC_OPTION_TOTAL
} MMI_EC_OPTION_ENUM;

typedef enum
{
    MMI_EC_SIN_AC,
    MMI_EC_SIN_AN,
    MMI_EC_SIN_DC,
    MMI_EC_SIN_DR,
    MMI_EC_SIN_TOTAL
} MMI_EC_SIN_ENUM;

typedef enum
{

    /*Here the last entry for the generated string enum is selected as the base for the group ID*/
    GRP_ID_EC_MAIN = 17351,
    GRP_ID_EC_INFORMATION,
    GRP_ID_EC_DIRECTION,
    GRP_ID_EC_OPTIONS,
    GRP_ID_EC_SET_CITY,
    GRP_ID_EC_DEC_INLINE,
    GRP_ID_EC_TOTAL
} MMI_EC_GRP_ID_ENUM;

typedef enum
{
	MMI_EC_HINTS_LOCATION,
	MMI_EC_HINTS_DECLINATION,
	MMI_EC_HINTS_TOTAL
} MMI_EC_HINTS_ENUM;

typedef struct
{
    U8 sgnstn;
    U8 hilited_city;
	U8 cali_result;
    U16 curr_city_index;
    U16 hilited_country;
    U16 hilited_country_next;
    S16 curr_north;
    S32 declination_angle;
    S32 declination_direc;
    S8 *DirectionList[MMI_EC_DRC_TOTAL];
    U8 *countryDataPtr[MMI_EC_MAX_COUNTRIES];
} mmi_ecompass_cntxt_struct;

extern mmi_ecompass_cntxt_struct g_ecompass_cntxt;

#endif /* _MMI_ECOMPASS_H */ 

