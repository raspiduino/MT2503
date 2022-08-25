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
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_common.h"
#include "ex_item.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_config.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"
#include "custom_nvram_config.h"
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

#if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
#include "custom_port_setting.h"
#endif

#include "tst.h"

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
/* under construction !*/
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "tl1d_custom_rf.h"
#endif // __AST_TL1_TDD__

#include "l1cal.h"
#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif



#include "dcl.h"

#include "custom_gprs_pdp_default_qos_config.h"

#if(defined(ISP_SUPPORT))
#include "drv_sw_features_isp.h"
#include "camera_tuning_para.h"
#endif

#include "nvram_default_audio.h"            /* NVRAM_EF_CUST_ACOUSTIC_DATA_SIZE */
#ifdef __GAIN_TABLE_SUPPORT__
#include "gain_table.h"
#endif /* __GAIN_TABLE_SUPPORT__ */

#include "adc_channel.h"

#if !defined(__NVRAM_SUPPORT_CUSTPACK__)// && !defined(__L1_STANDALONE__)
//    #include "nvram_cust_pack.c"
#if !defined(EXTERNAL_MMI)
    extern kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
#endif

extern kal_uint8 COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[];    

#ifdef __CPHS__
    extern kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[];
#endif
    
extern kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[];

#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    extern nvram_ef_mobile_broadband_provision_context_struct COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[];
#endif

#if defined (__UL1_HS_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)
        #if defined (__FDD_RF_CUSTOM_TOOL_SUPPORT__)
/* under construction !*/
/* under construction !*/
        #endif
    #endif
#endif

#if defined (__UL1_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
#endif



#endif  /* __MMI_FMI__*/
/*The chip doesn't support A5/3*/
#if defined( MT6208) || defined( MT6205) || defined( MT6218) || defined( MT6219) || \
    defined( MT6217) || defined( MT6227) || defined( MT6226) || defined( MT6228) || \
    defined(MT6205B) || defined(MT6226M) || defined(MT6218B)
#define __NO_SUPPORT_A5_3__
#endif

extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */

kal_uint8 const NVRAM_EF_ZERO_DEFAULT[] = { 0x00 };
kal_uint8 const NVRAM_EF_FF_DEFAULT[] = { 0xFF };

static kal_uint8 const NVRAM_EF_CFU_FLAG_DEFAULT[] = {
                  0x55, 0x55
};

static kal_uint8 const NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT[] = {
    0x00, //rplmn_rat
    0x00, //num_of_eq_plmn
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[0]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[1]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[2]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[3]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[4]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[5]
#ifdef __REL6__
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[6]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[7]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[8]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[9]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[10]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[11]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[12]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[13]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[14]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[15]
#endif
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //nvram_locigprs
};

#ifdef __TC02_SECURITY_REQUIREMENT__
static kal_uint8 const NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //EF_IMSI
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //EF_LOCI
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //EF_GLOCI
};
#endif /* __TC02_SECURITY_REQUIREMENT__ */

#if defined(__ATCMD_ONOFF_CHECK__)
const nvram_atcmd_check_context_struct NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT =
{
        {ATCMD_CHECK_ENABLE, 0x26598088, ATCMD_CHECK_ENABLE, 0X26598088},
        ATCMD_CHECK_ENABLE,  /* enable */
        {0x26598088, ATCMD_CHECK_ENABLE, 0x26598088}
};
#endif

#if defined(__ETWS_SUPPORT__)
const nvram_ef_etws_setting_struct NVRAM_EF_ETWS_SETTING_DEFAULT =
{
        0x00
};
#endif

#if defined(__ENABLE_MYBCCH__)
static kal_uint8 const NVRAM_EF_MYBCCH_SETTING_DEFAULT[] =
{
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
#endif

static nvram_at_profile_struct NVRAM_EF_AT_PROFILE_DEFAULT = {
   	{
	    0,  //s_reg.s1
	    43, //s_reg.s2
	    13, //s_reg.s3
	    10, //s_reg.s4
	    8,  //s_reg.s5
	    2,  //s_reg.s6
	    1,  //s_reg.s7
	    2,  //s_reg.s3
	    2,  //s_r8g.s10
	    17, //s_reg.s32
	    19, //s_reg.s33
	    0,  //s_reg.s95
    }, 
    
    {
	    0,  //rmmi_cbst.speed
	    0,  //rmmi_cbst.name
	    1,  //rmmi_cbst.ce
	},
	
    {
	    61, //rmmi_crlp.iws
	    61, //rmmi_crlp.mws
	    48, //rmmi_crlp.T1
	    6,  //rmmi_crlp.N2
    },

    0,  //rmmi_ciwf
    1,  //rmmi_atv
    1,  //rmmi_ate
    0,  //rmmi_atq
    4,  //rmmi_atx
    2,  //rmmi_atw
    1,  //rmmi_atampC
    2,  //rmmi_atampD
    0,  //rmmi_atampS  // Add for UART 8 wire
    3   //rmmi_atampK
};

static kal_uint8 const NVRAM_EF_BAND_INFO_DEFAULT[] = {
        0x00, /* mcc1 */
        0x00, /* mcc2 */
        0x00, /* mcc3 */
        0x00, /* learned_band */
        0x00, /* working_band */
        0x00  /* when __BAND_PRIORITY_SEARCH__ is defined, this
               * byte is used to set the priority for each band:
               *
               *      850     1900    1800    900
               *     +-------------------------------+
               * bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
               *     +-------------------------------+
               * The priority of each band is representive by two bits:
               *
               * <ex> bit 5 and 4 is the priority for 1900 band:
               *         '0'   '0' -> priority value 0
               *         '0'   '1' -> priority value 1
               *         '1'   '0' -> priority value 2
               *         '1'   '1' -> priority value 3
               *  
               *      The smaller the value is, the higher the priroity is:
               *      (1) if no band is preferred, the value can be assigned:
               *          0x00, 0x55, 0xaa, or 0xff
               *      (2) if 900/1800 is prefered, the value can be assigned:
               *          0x50, 0xF0, 0xF5 and so on.
               *      (3) if 850/1900 is prefered, the value can be assigned:
               *          0x05, 0x0F, 0x5F and so on.
               *      (4) if the band prefered order is 1900 -> 8500 -> 900 -> 1800,
               *          the value 0x4e (0100 1110) should be used.
               */
};

static kal_uint8 const NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] = {
       /*---BYTE 1 to BYTE 6 : From MS CLASSMARK3 -------------------------*/

    /*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined ( __EDGE_CARD_CLASS_12__ )

#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x25,  /* E-GSM power class 5, DCS power class 2 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x25,  /* P-GSM power class 5, DCS power class 2 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x05,  /* E-GSM power class 5 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x05,  /* P-GSM power class 5 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x02,  /* DCS power class 2 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#else /*__EDGE_CARD_CALSS_12__  */
       /* Claire 030922 change : Support multiband compile option */
#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x14,  /* E-GSM power class 4, DCS power class 1 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x14,  /* P-GSM power class 4, DCS power class 1 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x04,  /* E-GSM power class 4 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x04,  /* P-GSM power class 4 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x01,  /* DCS power class 1 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#endif /* __EDGE_CARD_CALSS_12__  */
                  0x01,  /* HSCSD multislot cap not present, UCS2 =1 */
                  /* Claire 030922 change : Support multiband compile option */


#if defined( __GSM450__) || defined( __GSM480__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xcf,  /* Extended Measurement cap = 1, AGPS support (support for conventional GPS), GSM 400 band support */
#else
                  0x81,  /* Extended Measurement cap = 1, AGPS not support (no support for conventional GPS), GSM 400 band support */
#endif /* __AGPS_CONTROL_PLANE__ */
#else
#ifdef __AGPS_CONTROL_PLANE__
                  0xce,  /* Extended Measurement cap = 1, AGPS support (support for conventional GPS), GSM 400 band not support */
#else
                  0x80,  /* Extended Measurement cap = 1, AGPS not support (no support for conventional GPS), GSM 400 band not support */
#endif /* __AGPS_CONTROL_PLANE__ */
#endif


#if !defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                  0x00,  /* GSM 400 and GSM 850 are not suported */
#elif defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                 0x90,  /* GSM 450 is supported with power class 4*/
#elif !defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0x50,  /* GSM 480 is supported with power class 4*/
#elif !defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x02,  /* GSM 850 is supported*/
#elif defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0xd0,  /* GSM 450 and 480 are supported with power class 4*/
#elif defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x92,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#elif !defined( __GSM450__) && defined( __GSM480__) && defined( __GSM850__)
                 0x52,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#else
                 0xd2,   /* GSM 450, 480 with power class 4 and 850 are supported*/
#endif

/*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined( __EDGE_CARD_CLASS_12__ )

#if defined( __GSM850__) && defined( __PCS1900__)
                  0xb2,  /* GSM 850 is power class 5 ,PCS 1900 is suportedwith power class 2*/
#elif  defined( __PCS1900__)
                  0x12,  /* PCS 1900 is suported , power class 2 */
#elif  defined( __GSM850__)
                  0xa0,  /* GSM 850 is power class 5 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#else /* __EDGE_CARD_CALSS_12__  */

#if defined( __GSM850__) && defined( __PCS1900__)
                  0x91,  /* GSM 850 is power class 4 ,PCS 1900 is suportedwith power class 1*/
#elif  defined( __PCS1900__)
                  0x11,  /* PCS 1900 is suported , power class 1 */
#elif  defined( __GSM850__)
                  0x80,  /* GSM 850 is power class 4 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#endif /* __EDGE_CARD_CALSS_12__  */


       /*---BYTE 7 to BYTE 9 : From MS CLASSMARK2 -----------  */
                  0x30,  /* ES_IND =1, Revision level =01, A51 algo supported---*/
                  0x58,  /* PS cap =1, SS sreen indicator =01, SM cap =1 */

/* CCBS supported */
#if defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa4,
#else
                  0x84,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa6,
#else
                  0x86,
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa5,
#else
                  0x85,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa7,
#else
                  0x87,
#endif
/* CCBS not supported */
#elif defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa0,
#else
                  0x80,
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa2,
#else
                  0x82,
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa1,
#else
                  0x81,
#endif
#else //!defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
                  0xa3,
#else
                  0x83,
#endif
#endif

       /*---BYTE 10 to BYTE 12 : From MS RA capability and MS network capability --*/

                           /* BYTE 10:
                            * bit 8: multislot capability present,
                            * bit 7 ~ 3: mutlislot capability,
                            * bit 2: GPRS extended Dynamic Allocation cap =1
                            * bit 1 : RL indicator = 0 => R98 MS, 1 => R99 MS */
#ifdef __R99__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xab,   /* Default GPRS multislot class 10, ext DA support, R99 */
   #else
                  0xb3,  /* Default GPRS multislot class 12, ext DA support, R99 */
   #endif
#else /* __R99__*/
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xaa,   /* Default GPRS multislot class 10, ext DA support, R98 */
   #else
                  0xb2,  /* Default GPRS multislot class 12, ext DA support, R98 */
   #endif
#endif /* __R99__ */

                           /* BYTE 11:
                            * bit 8 : GEA1
                            * bit 7 : GEA2
                            * bit 6 : GEA3
                            * bit 5 : GEA4
                            * bit 4 : GEA5
                            * bit 3 : GEA6
                            * bit 2 : GEA7
                            * bit 1 : SM cap in GPRS =1 */
/* Peter 080520: change complie option */
#ifdef __NO_SUPPORT_A5_3__
                  0xc1, /* GEA1, 2 and SM cap support */
#else // The chip support A5/3(GEA/3)
    0xe1, /* GEA1, 2, 3 and SM cap support */
#endif

                           /* BYTE 12: Lanslo 20060215: for selecting GPRS or EGPRS capability
                             * bit 8: PFC mode = 0b
                             * bit 7: EDGE multislot class present / EDGE support = 1b
                             * bit 6 ~ 2: EDGE multislot capability = 01100b
                             * bit 1: EDGE extended dynamic allocation capability = 1b
                             * Old value 0x80, new 0xd9(PFC on), 0x59 (PFC off) */

/* Evelyn 20090511: open the PFC support bit */
#ifdef __EGPRS_MODE__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__EDGE_MULTISLOT_CLASS_10__)
                  0xD5,   /* PFC on, EGPRS multislot class 10, Ext DA support */
   #else
                  0xD9,   /* PFC on, EGPRS multislot class 12, Ext DA support */
   #endif
#else /* __EGPRS_MODE__ */
   #ifdef __R99__
                  0x80,   /* PFC on */
   #else
                  0x00,   /* PFC off */
   #endif
#endif /* __EGPRS_MODE__ */

// Jelly 20090602 Use __EPSK_TX__
#if (defined(__EGPRS_MODE__) && defined(__EPSK_TX__))
                  0xAA,   /* BYTE 13: Evelyn 20090422: set 8PSK power class in NVRAM
                            * bit8~7 : 8psk radio cap 2 = E2 *
                            * bit6~5 : 8psk radio cap 1 = E2 *
                            * bit4~3 : 8psk 850 Band    = E2 *
                            * bit2~1 : 8psk 1900 Band   = E2 */
#else /* __EGPRS_MODE__ */
                  0x00,   /* No 8PSK power class */
#endif /* __EGPRS_MODE__ */

/* Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0xEc    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#else
                  0x6c    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#endif
#else
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0x80   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#else
                  0x00   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#endif
#endif

/* Bit8+Bit7(10 for VAMOS2, 01 for VAMOS1, 00 for no support VAMOS */
/* Other bits are resevered */
#if defined(__VAMOS_2__)
                    ,0x80
#elif defined(__VAMOS_1__)
                    ,0x40
#else
                    ,0x00
#endif

/* Peter, 20080804: Modify the order of classmark3 info */
#if 0
#if defined(__REL4__) || defined(__REL5__) || defined(__SAIC__) || defined(__REPEATED_ACCH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #if defined(__REL4__) || defined(__REL5__)
/* under construction !*/
   #else
/* under construction !*/
   #endif  /* defined(__REL4__) || defined(__REL5__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __SAIC__
/* under construction !*/
   #else
/* under construction !*/
   #endif /* __SAIC__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #ifdef __REPEATED_ACCH__
/* under construction !*/
   #else
/* under construction !*/
   #endif /* __REPEATED_ACCH__ */
/* under construction !*/
#endif /* defined(__REL4__) || defined(__REL5__) || defined(__SAIC__) || defined(__REPEATED_ACCH__) */
/* under construction !*/
#endif
};

#ifdef __UMTS_RAT__
/* under construction !*/
#ifdef __UMTS_FDD_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __RFC2507_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif /* __RFC2507_SUPPORT__ */
/* under construction !*/
#ifndef __UMTS_R5__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifndef __UMTS_R5__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __WCDMA_PREFERRED__
/* under construction !*/
#endif /* __WCDMA_PREFERRED__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* under construction !*/
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#ifdef __FAST_DORMANCY__
/* under construction !*/
#endif /* __FAST_DORMANCY__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R5__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__UMTS_FDD_MODE__) && defined(__HSDPA_SUPPORT__)
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef FDD_HSDSCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#ifdef TDD_HSDSCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
#endif /* __UMTS_R5__ */
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R6__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__UMTS_FDD_MODE__) && defined(__HSUPA_SUPPORT__)
/* under construction !*/
#endif    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef FDD_EDCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* __UMTS_R6__ */
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __ENHANCED_COMMON_STATE_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CPC_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MAC_EHS_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_R7__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_FDD_MODE__ */
/* under construction !*/
#ifdef __UMTS_TDD128_MODE__
#ifdef __AST_TL1_TDD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __RFC2507_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif /* __RFC2507_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __AST1001__
/* under construction !*/
#else /* __AST2001__ */
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
/* under construction !*/
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#ifdef __FAST_DORMANCY__
/* under construction !*/
#endif /* __FAST_DORMANCY__ */
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R5__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef FDD_HSDSCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#ifdef TDD_HSDSCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
#endif /* __UMTS_R5__ */
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R6__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef FDD_EDCH_CATEGORY
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* __UMTS_R6__ */
/* under construction !*/
/* under construction !*/
#ifdef __UMTS_R7__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __ENHANCED_COMMON_STATE_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __CPC_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MAC_EHS_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_R7__ */
/* under construction !*/
#endif /* __AST_TL1_TDD__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_TDD128_MODE__ */
/* under construction !*/
#endif /* __UMTS_RAT__ */


#ifdef  __BTMODULE_RFMD3500__
static kal_uint8 const NVRAM_EF_BTRADIO_RFMD3500_DEFAULT[] = {
/* BluetoothAddress                  ,  6 */ 0xAD,0x5A,0x00,0x00,0x00,0x00,
/* MinEncryptionSize                 ,  1 */ 0x01,
/* MaxEncryptionSize                 ,  1 */ 0x10,
/* HCITransportLayerParameters       ,  3 */ 0x02,0x00,0x00,
/* FixedPIN                          , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                             0x00,0x00,0x00,0x00,0x00,0x00,
/* FixedPINLength                    ,  1 */ 0x00,
/* SleepEnableMask					 ,	1 */ 0x01,
/* LowPowerClockParameter	   	  	 ,  8 */ 0x03,0x02,0x00,0x00,0x00,0x10,0x00,0x00,
/* PowerControlConfiguration         , 13 */ 0x07,0x07,0x07,0x02,0x00,0x01,0x02,0x03,0x04,0x05,
                                             0x06,0x07,0x07,
/* SleepControlParameters            , 12 */ 0x00,0x00,0x14,0x10,0x20,0x30,0x30,0x30,0x30,0x00,
                                             0x03,0x02,
/* DebugControl                      ,  4 */ 0x00,0x00,0x2C,0x01,
/* LCandRMOverrideEnable             ,  4 */ 0x10,0x00,0x00,0x00,
/* RadioRegisterOverride             ,  6 */ 0x01,0x00,0x00,0x00,0x0D,0x7F,
/* CodecConfiguration                ,  8 */ 0x20,0x00,0x10,0x1F,0x00,0x0F,0x0F,0x02,
/* CVSDGainVolumeSettings            ,  6 */ 0x02,0x00,0x00,0x00,0x0E,0x0E,
/* VoiceSettings                     ,  2 */ 0x60,0x00,
/* UserBaudRate                      ,  3 */ 0x11,0x00,0x17,
/* CoexistenceParameters             ,  4 */// 0x02,0xA4,0x0E,0x00,
/* LowPowerDriftRate                 ,  1 */ 0x2D,
/* MaxTxPowerLevel                   ,  1 */ 0x04,
/* AdaptiveFrequencyHoppingParameters, 29 */ 0x02,0x00,0x3C,0x00,0x3C,0x00,0x00,0x01,0x0A,0x05,
                                             0x13,0x4F,0x02,0x08,0x01,0x0C,0x01,0x00,0x00,0x00,
                                             0x40,0x00,0x00,0x00,0x40,0x00,0x00,0x0A,0x05,
/* BufferSize                        ,  4 */ 0x7C,0x00,0x7C,0x00,
/* GPIO Mapping                      , 16 */ 0xFF,0x01,0xFF,0x02,0x04,0x06,0xFF,0x00,0xFF,0x00,
                                             0xFF,0x00,0xFF,0x00,0xFF,0x00,
/* GPIO Polarity                     ,  4 */ 0x00,0x00,0x04,0x00
};
#endif /* __BTMODULE_RFMD3500__*/



#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
static kal_uint8 const NVRAM_EF_MNL_SETTING_DATA_DEFAULT[] = {
/* Internal LNA Enable          ,  1  */ 0x00,
/* TCXO Frequency Drift         ,  1  */ 0x01,
/* SBAS Mode                    ,  1  */ 0x00,
/* Clock Type                   ,  1  */ 0x00,
/* Frequency Error for XTAL     ,  1  */ 0x00,
/* Frame Sync Enable            ,  1  */ 0x00,
/* Reserved                     ,  10 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined (__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
//#if defined(__BTMODULE_MT6276__)|| defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
static kal_uint32 const NVRAM_EF_BWCS_SETTING_DATA_DEFAULT[] =
{
    /* Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Non Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Antenna path compensation */
    10,
    /* antenna path switch protection period, Unit is frames (4.615us) */
    2000,
    /* TX Flow control : medium time / period time */
    0x0E00, 0x01,
    /* BT RX Range : Low / High */
    0xC4, 0xE2,
    /* BT TX power : WIFI OFF / WIFI SCO / WIFI ACL */
    0x07, 0x07, 0x06,
    /* Reserved                     ,  5 */
    0x00, 0x00, 0x00, 0x00, 0x00
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* #if 0 */
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */

#ifdef __PS_SERVICE__
static kal_uint8 const NVRAM_EF_TCM_PDP_PROFILE_DEFAULT[] = {
                  0x00, 0x00, 0x21, 0x01,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  //0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // req qos
                  PS_QOS_PROFILE_DEFAULT_REQ_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_REQ_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK,

                  //0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  //0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // min qos
                  PS_QOS_PROFILE_DEFAULT_MIN_LENGTH,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2,
                  PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3,
                  PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER,
                  PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE,
                  PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY,
                  PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4,
                  PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION,
                  PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK,
                  PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK,

                  0x08,

                  0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x02, 0x02, 0x00, 0x00, 0x01,
                  0xAC, 0x15, 0x78, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00,
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0xFF, // 228
                  0x00, 0x00 // N201U value 1520=(0xF0, 0x05) //erica 20070112
};
#endif /* __PS_SERVICE__*/

#if !defined(__CUSTOMIZED_PORT_SETTING__)
port_setting_struct const NVRAM_EF_PORT_SETTING_DEFAULT[]=
{
    {
		#if defined(__GPS_TRACK__)
        4,
        0,
    #elif defined (WISDOM_MMI) || defined(NEPTUNE_MMI) || defined(__MMI_TST_AUTO_OUTPUT_UART__)
        0,   /* tst-ps uses uart_port2(value is 1) */
        1,   /* APP uses uart_port1 (value is 0) */
    #elif defined(__DUAL_TALK_MODEM_SUPPORT__)
        5,   /* tst-ps uses uart_port1 */
        uart_port1,   /* APP uses uart_port2 */
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        0,   /* TST-PS uses uart_port1 */
        5,   /* ATCI uses uart_port_usb2 */           
    #elif defined(__WIFI_TCPIP_AT_SUPPORT__) || defined(__GPRS_TCPIP_AT_SUPPORT__)||defined(__IPV4V6__)
        #if defined( __WIFI_TCPIP_AT_SUPPORT__)
        4,   /* USB port */
        0,  /* uart_port1 */
        #elif defined (__USB_MULTIPLE_COMPORT_SUPPORT__)
        5,  
        4,   
        #else
        4,   /* USB port */
        99, 
        #endif
    #elif defined(__IOT__) || defined(__MMI_TST_AUTO_OUTPUT_USB__)
        4,   /* USB port */
        99,  /* uart_port_null */
    #elif defined(__BCM_AT_CMD__)
		0,	/* UART PORT 1 FOR tst-ps  */
		4,	/* USB port  1 FOR PS  */
    #else
        99,   /* tst-ps uses uart_port_null(value is 99) */
        0,   /* APP uses uart_port1 (value is 0) */
    #endif

    #if defined(EMPTY_MMI) || defined(__MMI_TST_AUTO_OUTPUT_UART__)
        #if defined(__DUAL_TALK_MODEM_SUPPORT__)
        115200,
        #else
        921600, /* tst default baud rate for project without MMI */
        #endif
    #elif defined (WISDOM_MMI)
/* under construction !*/
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        921600, /* TST-PS baud uses 921600 */
    #else
        115200, /* tst default baud rate base = 115200 = 0x0001C200 */
    #endif

    #if defined (__PS_SERVICE__)
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #elif defined (__WIFI_TCPIP_AT_SUPPORT__) || defined(__GPRS_TCPIP_AT_SUPPORT__)
        115200, /* ps default baud rate base = 115200 = 0x0001C200 */
    #else
        #if defined(__DUAL_TALK_MODEM_SUPPORT__)
        115200,
        #else
        57600, /* ps default baud rate base =   57600 = 0x0000E100 */
        #endif
    #endif

        KAL_FALSE,                   /* High SpeedSIM */
        0,                           /* SWDBG */
    #if defined(__ONLY_ONE_UART__)
        1,                           /* uart power setting (0x03) */
    #else
        3,
    #endif

        99,                          /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/
 #if defined(__GPS_TRACK__)
        4,
    #elif defined (WISDOM_MMI) || defined(NEPTUNE_MMI) || defined(__MMI_TST_AUTO_OUTPUT_UART__)
        0,
    #elif defined(__DUAL_TALK_MODEM_SUPPORT__)
        5,
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        1, /* TST-L1 baud uses uart_port2 */
    #elif defined(__MMI_TST_AUTO_OUTPUT_USB__)
        4, /* TST-L1 baud uses usb port*/
    #elif defined(__WIFI_TCPIP_AT_SUPPORT__) || defined(__GPRS_TCPIP_AT_SUPPORT__)||defined(__IPV4V6__)||defined(__IPV4V6__)
        #if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
        5,  
        #else
        99,
        #endif
    #elif defined(__BCM_AT_CMD__)
        0,
    #else
        99,                           /* tst-l1 uart port, same as tst-ps*/
    #endif

    #if defined(EMPTY_MMI) || defined(__MMI_TST_AUTO_OUTPUT_UART__)
        #if defined(__DUAL_TALK_MODEM_SUPPORT__)
        115200, /* TST-L1 default baud rate for project without MMI */
        #else
        921600, /* TST-L1 default baud rate for project without MMI */
        #endif
    #elif defined (WISDOM_MMI)
/* under construction !*/
    #elif defined(__USB_MULTIPLE_COMPORT_SUPPORT__) && defined(__L4_INIT_MULTIUSB_COM__)
        921600, /* TST-L1 baud uses 921600 */
    #else
        115200, /* TST-L1 default baud rate base = 115200 = 0x0001C200 */
    #endif

        0,                           /* tst output mode*/
     #if !defined( __UL1_STANDALONE__ )
        0,                            /* USB logging mode */
    #else
        #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
/* under construction !*/
        #else
        1,
        #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
    #endif /*  __UL1_STANDALONE__  */

        99,  										//TST-DSP
        921600,									//TST-DSP baudrate

        0       // USB CD-ROM config,  0:CD-ROM , 1: COM
    },
};
#endif /* !defined(__CUSTOMIZED_PORT_SETTING__) */

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
static kal_uint8 const NVRAM_EF_SMSAL_SMS_DEFAULT[] = {
    0xfe,                            /* status */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};
#endif

#ifndef __CB_CHANNEL_ONLY_STORED_IN_NVRAM__
/* Cell Broadcast Setting. */
/* The channels set will shown in MMI */
/* This setting may be changed by customer. DON'T remove it. */
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, /* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF  /* CH 20 */
};
#else
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,/* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, /* CH 21 */
    0xFF, 0xFF, /* CH 22 */
    0xFF, 0xFF, /* CH 23 */
    0xFF, 0xFF, /* CH 24 */
    0xFF, 0xFF, /* CH 25 */
    0xFF, 0xFF, /* CH 26 */
    0xFF, 0xFF, /* CH 27 */
    0xFF, 0xFF, /* CH 28 */
    0xFF, 0xFF, /* CH 29 */
    0xFF, 0xFF, /* CH 30 */
    0xFF, 0xFF, /* CH 31 */
    0xFF, 0xFF, /* CH 32 */
    0xFF, 0xFF, /* CH 33 */
    0xFF, 0xFF, /* CH 34 */
    0xFF, 0xFF, /* CH 35 */
    0xFF, 0xFF, /* CH 36 */
    0xFF, 0xFF, /* CH 37 */
    0xFF, 0xFF, /* CH 38 */
    0xFF, 0xFF, /* CH 39 */
    0xFF, 0xFF  /* CH 40 */
};
#endif

/* UEM*/
static kal_uint8 const NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT[] = {
                   'M',  'T',  'K',  '1', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __DM_MO_SUPPORT__
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#else
                   'M',  'T',  'K',  '2', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '4', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '5', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                   'M',  'T',  'K',  '6', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '7', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };

#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
/* PS QoS profile */
static nvram_ef_abm_ps_qos_profile_struct const COMMON_NVRAM_EF_ABM_PS_QOS_PROFILE_DEFAULT[] =
{
    /* (0) default qos profile */
    {
        /* req_qos */
        /*
        16, 0, 0, 3,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        4, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        */
        PS_QOS_PROFILE_DEFAULT_REQ_LENGTH,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1,
        PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_RELIABILITY_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2,
        PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3,
        PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER,
        PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE,
        PS_QOS_PROFILE_DEFAULT_REQ_SDU_ERROR_RATIO,
        PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY,
        PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY,
        PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4,
        PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION,
        PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK,

        /* min_qos */
        /*
        16, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        */
        PS_QOS_PROFILE_DEFAULT_MIN_LENGTH,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1,
        PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2,
        PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3,
        PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER,
        PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE,
        PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO,
        PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY,
        PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY,
        PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4,
        PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION,
        PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK,
    },

    /* (1) straming qos profile */
    {
        /* req_qos */
        /*
        16, 0, 0, 3,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        4, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        */
        PS_QOS_PROFILE_DEFAULT_REQ_LENGTH,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_1,
        PS_QOS_PROFILE_DEFAULT_REQ_DELAY_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_RELIABILITY_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_PEAK_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_2,
        PS_QOS_PROFILE_DEFAULT_REQ_PRECEDENCE_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_3,
        PS_QOS_PROFILE_DEFAULT_REQ_MEAN_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_CLASS,
        PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_ORDER,
        PS_QOS_PROFILE_DEFAULT_REQ_DELIVERY_OF_ERR_SDU,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_SDU_SIZE,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_MAX_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_RESIDUAL_BIT_ERROR_RATE,
        PS_QOS_PROFILE_DEFAULT_REQ_SDU_ERROR_RATIO,
        PS_QOS_PROFILE_DEFAULT_REQ_TRANSFER_DELAY,
        PS_QOS_PROFILE_DEFAULT_REQ_TRAFFIC_HNDL_PRIORITY,
        PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_GUARANTEED_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_REQ_UNUSED_4,
        PS_QOS_PROFILE_DEFAULT_REQ_SIGNALING_INDICATION,
        PS_QOS_PROFILE_DEFAULT_REQ_SOURCE_STAT_DESCPTOR,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_MAX_BIT_RATE_UP_LINK,
        PS_QOS_PROFILE_DEFAULT_REQ_EXT_GUARANTEED_BIT_RATE_UP_LINK,

        /* min_qos */
        /*
        16, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        */
        PS_QOS_PROFILE_DEFAULT_MIN_LENGTH,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_1,
        PS_QOS_PROFILE_DEFAULT_MIN_DELAY_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_RELIABILITY_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_PEAK_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_2,
        PS_QOS_PROFILE_DEFAULT_MIN_PRECEDENCE_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_3,
        PS_QOS_PROFILE_DEFAULT_MIN_MEAN_THROUGHPUT,
        PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_CLASS,
        PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_ORDER,
        PS_QOS_PROFILE_DEFAULT_MIN_DELIVERY_OF_ERR_SDU,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_SDU_SIZE,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_MAX_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_RESIDUAL_BIT_ERROR_RATE,
        PS_QOS_PROFILE_DEFAULT_MIN_SDU_ERROR_RATIO,
        PS_QOS_PROFILE_DEFAULT_MIN_TRANSFER_DELAY,
        PS_QOS_PROFILE_DEFAULT_MIN_TRAFFIC_HNDL_PRIORITY,
        PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_UPLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_GUARANTEED_BIT_RATE_DOWNLINK,
        PS_QOS_PROFILE_DEFAULT_MIN_UNUSED_4,
        PS_QOS_PROFILE_DEFAULT_MIN_SIGNALING_INDICATION,
        PS_QOS_PROFILE_DEFAULT_MIN_SOURCE_STAT_DESCPTOR,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_DONW_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_MAX_BIT_RATE_UP_LINK,
        PS_QOS_PROFILE_DEFAULT_MIN_EXT_GUARANTEED_BIT_RATE_UP_LINK,
    }
};
#endif /* __APP_STATIC_QOS_PROFILE_SUPPORT__ */

#if defined(__8_WIRE_UART_SUPPORT__)
static nvram_ef_ri_cfg_struct NVRAM_EF_RI_CFG_DEFAULT = {
    {
        1,  //INCOMING_CALL event enable
        1,  //INCOMING_CALL event RI signal shape is pulse
        100, //INCOMING_CALL event RI signal  pulse_duration 100*10 ms = 1s
    },

    {
        1,  //INCOMING_SMS event enable
        1,  //INCOMING_SMS event RI signal shape is pulse
        5, //INCOMING_SMS event RI signal  pulse_duration 50 ms
    },


    {
        1,  //INCOMING_SMS_CB event enable
        1,  //INCOMING_SMS_CB event RI signal shape is pulse
        5, //INCOMING_SMS_CB event RI signal  pulse_duration 50 ms
    },

    {
        1,  //USSD event enable
        1,  //USSD event RI signal shape is LEVEL pulse
        5, //USSD event RI signal  pulse_duration 50 ms
    },

    {
        1,  //NETWORK_STATE event enable
        1,  //NETWORK_STATE event RI signal shape is pulse
        5, //NETWORK_STATE event RI signal  pulse_duration 50 ms
    },

    1,  //RI signal ENABLE
};
#endif /* __8_WIRE_UART_SUPPORT__ */
#if defined(__M2M_CSGT_SUPPORT__)
static nvram_ef_m2m_csgt_struct NVRAM_EF_M2M_CSGT_DEFAULT = {
    1,  //1: trun on greeting text
    "NULL", //greeting text default is text NULL
};
#endif /* __M2M_CSGT_SUPPORT__ */
/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * The last LID in the MT reign now is MT1k
 */
ltable_entry_struct logical_data_item_table_core[] =
{
    {
        NVRAM_EF_SYS_EXCEPTION_LID,
        NVRAM_EF_SYS_EXCEPTION_TOTAL,
        NVRAM_EF_SYS_EXCEPTION_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT03",
        VER(NVRAM_EF_SYS_EXCEPTION_LID)
    },
    
    {
        NVRAM_EF_SYS_STATISTICS_LID,
        NVRAM_EF_SYS_STATISTICS_TOTAL,
        NVRAM_EF_SYS_STATISTICS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT04",
        VER(NVRAM_EF_SYS_STATISTICS_LID)
    },
    

#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
    {
        NVRAM_EF_L1_2G_RF_PARAMETER_LID,
        NVRAM_EF_L1_2G_RF_PARAMETER_TOTAL,
        NVRAM_EF_L1_2G_RF_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP((void*)&RF_custom_input_data),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP(RF_custom_input_data),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "MT0W",
        VER(NVRAM_EF_L1_2G_RF_PARAMETER_LID)
    },
#endif


    {
        NVRAM_EF_BAND_INFO_LID,
        NVRAM_EF_BAND_INFO_TOTAL,
        NVRAM_EF_BAND_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BAND_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT0X",
        VER(NVRAM_EF_BAND_INFO_LID)
    },
    
    {
        NVRAM_EF_TST_FILTER_LID,
        NVRAM_EF_TST_FILTER_TOTAL,
        NVRAM_EF_TST_FILTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT0Y",
        VER(NVRAM_EF_TST_FILTER_LID)
    },

    {
        NVRAM_EF_PORT_SETTING_LID,
        NVRAM_EF_PORT_SETTING_TOTAL,
        NVRAM_EF_PORT_SETTING_SIZE,
    #if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
        NVRAM_NORMAL(NVRAM_EF_CUSTOM_PORT_SETTING_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_PORT_SETTING_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT0Z",
        VER(NVRAM_EF_PORT_SETTING_LID)
    },

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
    {
        NVRAM_EF_SMSAL_SMS_LID,
        NVRAM_EF_SMSAL_SMS_TOTAL,
        NVRAM_EF_SMSAL_SMS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SMSAL_SMS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT40",
        VER(NVRAM_EF_SMSAL_SMS_LID)
    },
#endif

#if !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT41",
        VER(NVRAM_EF_SMSAL_MAILBOX_ADDR_LID)
    },
#endif

    {
        NVRAM_EF_SMSAL_COMMON_PARAM_LID,
        NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL,
        NVRAM_EF_SMSAL_COMMON_PARAM_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT42",
        VER(NVRAM_EF_SMSAL_COMMON_PARAM_LID)
    },

    {
        NVRAM_EF_SMSAL_SMSP_LID,
        NVRAM_EF_SMSAL_SMSP_TOTAL,
        NVRAM_EF_SMSAL_SMSP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MT43",
        VER(NVRAM_EF_SMSAL_SMSP_LID)
    },

    {
        NVRAM_EF_SMSAL_MWIS_LID,
        NVRAM_EF_SMSAL_MWIS_TOTAL,
        NVRAM_EF_SMSAL_MWIS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT44",
        VER(NVRAM_EF_SMSAL_MWIS_LID)
    },

    {
        NVRAM_EF_CB_DEFAULT_CH_LID,
        NVRAM_EF_CB_DEFAULT_CH_TOTAL,
        NVRAM_EF_CB_DEFAULT_CH_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT45",
        VER(NVRAM_EF_CB_DEFAULT_CH_LID)
    },

    {
        NVRAM_EF_CB_CH_INFO_LID,
        NVRAM_EF_CB_CH_INFO_TOTAL,
        NVRAM_EF_CB_CH_INFO_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MT46",
        VER(NVRAM_EF_CB_CH_INFO_LID)
    },

#if (( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) ) || (defined(__TCM_UT__)))
    {
        NVRAM_EF_TCM_STATISTICS_LID,
        NVRAM_EF_TCM_STATISTICS_TOTAL,
        NVRAM_EF_TCM_STATISTICS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT47",
        VER(NVRAM_EF_TCM_STATISTICS_LID)
    },
#endif // ~ #if ( (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) && (!defined(__MSG_ID_MMI_PS_GET_GPRS_DATA_COUNTER_REQ_PHASE_OUT__)) )

#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
    {
        NVRAM_EF_TCM_PDP_PROFILE_LID,
        NVRAM_EF_TCM_PDP_PROFILE_TOTAL,
        NVRAM_EF_TCM_PDP_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_TCM_PDP_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT48",
        VER(NVRAM_EF_TCM_PDP_PROFILE_LID)
    },
#endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)

    {
        NVRAM_EF_CFU_FLAG_LID,
        NVRAM_EF_CFU_FLAG_TOTAL,
        NVRAM_EF_CFU_FLAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CFU_FLAG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT49",
        VER(NVRAM_EF_CFU_FLAG_LID)
    },

    {
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_TOTAL,
        NVRAM_EF_MM_EQPLMN_LOCIGPRS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MM_EQPLMN_LOCIGPRS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT4A",
        VER(NVRAM_EF_MM_EQPLMN_LOCIGPRS_LID)
    },
    
#if defined (__CPHS__) || defined (__CCM_NO_RESET__)
    {
        NVRAM_EF_ALS_LINE_ID_LID,
        NVRAM_EF_ALS_LINE_ID_TOTAL,
        NVRAM_EF_ALS_LINE_ID_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT4C",
        VER(NVRAM_EF_ALS_LINE_ID_LID)
    },
#endif/* (__CPHS__) || (__CCM_NO_RESET__)*/

    {
        NVRAM_EF_MSCAP_LID,
        NVRAM_EF_MSCAP_TOTAL,
        NVRAM_EF_MSCAP_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MSCAP_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT4D",
        VER(NVRAM_EF_MSCAP_LID)
    },
    
    {
        NVRAM_EF_CLASSMARK_RACAP_LID,
        NVRAM_EF_CLASSMARK_RACAP_TOTAL,
        NVRAM_EF_CLASSMARK_RACAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CLASSMARK_RACAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT17",
        VER(NVRAM_EF_CLASSMARK_RACAP_LID)
    },
    
    {
        NVRAM_EF_SIM_ASSERT_LID,
        NVRAM_EF_SIM_ASSERT_TOTAL,
        NVRAM_EF_SIM_ASSERT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_RING,
        "MT18",
        VER(NVRAM_EF_SIM_ASSERT_LID)
    },
        
    {
        NVRAM_EF_RTC_DATA_LID,
        NVRAM_EF_RTC_DATA_TOTAL,
        NVRAM_EF_RTC_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT19",
        VER(NVRAM_EF_RTC_DATA_LID)
    },
    
#if defined(__UMTS_RAT__) || defined(__STORED_CELL_SELECTION_INFO__)
    {
        NVRAM_EF_NET_PAR_LID,
        NVRAM_EF_NET_PAR_TOTAL,
        NVRAM_EF_NET_PAR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1A",
        VER(NVRAM_EF_NET_PAR_LID)
    },
#endif

#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R7__)) || (defined(__SEARCH_ALL_EHPLMN_TOGETHER__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* __UMTS_RAT__ */
#if defined(__MA_L1__) || defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
#if !defined(__LOW_COST_SUPPORT_COMMON__) && defined(__FLC_SUPPORT__ )&& defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !__LOW_COST_SUPPORT_COMMON__&&__MTK_INTERNAL__ && __FLC_SUPPORT__ */
#endif

#if defined (__E_COMPASS_SENSOR_SUPPORT__)
    {
        NVRAM_EF_ECOMPASS_DATA_LID,
        NVRAM_EF_ECOMPASS_DATA_TOTAL,
        NVRAM_EF_ECOMPASS_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1D",
        VER(NVRAM_EF_ECOMPASS_DATA_LID)
    },
#endif  /* __E_COMPASS_SENSOR_SUPPORT__ */

#ifdef __BAND_BLOCK__
    {
        NVRAM_EF_BAND_BLOCK_LID,
        NVRAM_EF_BAND_BLOCK_TOTAL,
        NVRAM_EF_BAND_BLOCK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT1E",
        VER(NVRAM_EF_BAND_BLOCK_LID),
    },
#endif /* __BAND_BLOCK__ */


#ifdef  __BTMODULE_RFMD3500__
    {
        NVRAM_EF_BTRADIO_RFMD3500_LID,
        NVRAM_EF_BTRADIO_RFMD3500_TOTAL,
        NVRAM_EF_BTRADIO_RFMD3500_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_RFMD3500_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1G",
        VER(NVRAM_EF_BTRADIO_RFMD3500_LID)
    },
#endif





#if defined(__ATCMD_ONOFF_CHECK__)
    {
        NVRAM_EF_ATCMD_ON_OFF_CHECK_LID,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_TOTAL,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT30",
        VER(NVRAM_EF_ATCMD_ON_OFF_CHECK_LID)
    },
#endif

#if defined(__TST_DNT_LOGGING__)
    {
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_TOTAL,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT31",
        VER(NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID)
    },
#endif  //#if defined(__TST_DNT_LOGGING__)

#if defined(__ETWS_SUPPORT__)
    {
            NVRAM_EF_ETWS_SETTING_LID,
            NVRAM_EF_ETWS_SETTING_TOTAL,
            NVRAM_EF_ETWS_SETTING_SIZE,
            NVRAM_NORMAL(&NVRAM_EF_ETWS_SETTING_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT32",
            VER(NVRAM_EF_ETWS_SETTING_LID)
    },
#endif

    {
            NVRAM_EF_CSM_ESSP_LID,
            NVRAM_EF_CSM_ESSP_TOTAL,
            NVRAM_EF_CSM_ESSP_SIZE,
            NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT35",
            VER(NVRAM_EF_CSM_ESSP_LID)
    },

/* UEM*/
    {
        NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
        NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL,
        NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE,
    #if defined(__MMI_FMI__)        
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_ZIP_DEFAULT,
        "MT67",
        VER(NVRAM_EF_CUST_HW_LEVEL_TBL_LID)
    },
    
    {
        NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
        NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL,
        NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT68",
        VER(NVRAM_EF_UEM_MANUFACTURE_DATA_LID)
    },
    
    {
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_TOTAL,
        NVRAM_EF_UEM_RMI_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT69",
        VER(NVRAM_EF_UEM_RMI_DATA_LID)
    },

#ifdef __GPS_SUPPORT__
    {
        NVRAM_EF_GPS_SETTING_DATA_LID,
        NVRAM_EF_GPS_SETTING_DATA_TOTAL,
        NVRAM_EF_GPS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6D",
        VER(NVRAM_EF_GPS_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ */

#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
    {
        NVRAM_EF_MNL_SETTING_DATA_LID,
        NVRAM_EF_MNL_SETTING_DATA_TOTAL,
        NVRAM_EF_MNL_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MNL_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6E",
        VER(NVRAM_EF_MNL_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
    {
        NVRAM_EF_BWCS_SETTING_DATA_LID,
        NVRAM_EF_BWCS_SETTING_DATA_TOTAL,
        NVRAM_EF_BWCS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BWCS_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6F",
        VER(NVRAM_EF_BWCS_SETTING_DATA_LID)
    },
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */


    {
        NVRAM_EF_MS_SECURITY_LID,
        NVRAM_EF_MS_SECURITY_TOTAL,
        NVRAM_EF_MS_SECURITY_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MS_SECURITY_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #ifdef __TC01__
/* under construction !*/
    #else
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #endif
        "MT6G",
        VER(NVRAM_EF_MS_SECURITY_LID)
    },

#if !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__)
    {
          NVRAM_EF_PHB_LN_ENTRY_LID,
          NVRAM_EF_PHB_LN_ENTRY_TOTAL,
          NVRAM_EF_PHB_LN_ENTRY_SIZE,
          NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6H",
          VER(NVRAM_EF_PHB_LN_ENTRY_LID)
    },

    {
          NVRAM_EF_PHB_LN_TYPE_SEQ_LID,
          NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL,
          NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6I",
          VER(NVRAM_EF_PHB_LN_TYPE_SEQ_LID)
    },

#endif /* !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__) */

#ifdef __APP_STATIC_QOS_PROFILE_SUPPORT__
    {
        NVRAM_EF_ABM_PS_QOS_PROFILE_LID,
        NVRAM_EF_ABM_PS_QOS_PROFILE_TOTAL,
        NVRAM_EF_ABM_PS_QOS_PROFILE_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_ABM_PS_QOS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        "MT6J",
        VER(NVRAM_EF_ABM_PS_QOS_PROFILE_LID)
    },
#endif/*__APP_STATIC_QOS_PROFILE_SUPPORT__ */

    {
        NVRAM_EF_SYS_CACHE_OCTET_LID,
        NVRAM_EF_SYS_CACHE_OCTET_TOTAL,
        NVRAM_EF_SYS_CACHE_OCTET_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_CACHE_OCTET_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6K",
        VER(NVRAM_EF_SYS_CACHE_OCTET_LID)
    },

#ifdef __DRM_V02__
    {
        NVRAM_EF_DRM_SETTING_LID,
        NVRAM_EF_DRM_SETTING_TOTAL,
        NVRAM_EF_DRM_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL,
        "MT6L",
        VER(NVRAM_EF_DRM_SETTING_LID)
    },
    
    {
        NVRAM_EF_DRM_STIME_LID,
        NVRAM_EF_DRM_STIME_TOTAL,
        NVRAM_EF_DRM_STIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_CONFIDENTIAL,
        "MT6M",
        VER(NVRAM_EF_DRM_STIME_LID)
    },
    
    {
        NVRAM_EF_DRM_CERPATH_LID,
        NVRAM_EF_DRM_CERPATH_TOTAL,
        NVRAM_EF_DRM_CERPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6N",
        VER(NVRAM_EF_DRM_CERPATH_LID)
    },
#endif /* __DRM_V02__ */


    {
        NVRAM_EF_RAC_PREFERENCE_LID,
        NVRAM_EF_RAC_PREFERENCE_TOTAL,
        NVRAM_EF_RAC_PREFERENCE_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MT6S",
        VER(NVRAM_EF_RAC_PREFERENCE_LID)
    },

#ifdef __TC02_SECURITY_REQUIREMENT__
    {                                                                   
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_TOTAL,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_SIZE,
        NVRAM_SECUPACK(NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT),
        NVRAM_CATEGORY_SECUPACK,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT6T", 
        VER(NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID)
    },
#endif  /* __TC02_SECURITY_REQUIREMENT__ */    

    {
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_TOTAL,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE,
//#ifdef __SEARCH_ALL_EHPLMN_TOGETHER__        
//        NVRAM_NORMAL(NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT),
//#else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
//#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6U",
        VER(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID)
    },

#if !defined(L4_NOT_PRESENT)
#ifndef __PHB_STORAGE_BY_MMI__
    #ifdef __MMI_TELEPHONY_SUPPORT__
    {
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_EF_PHB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT6V",
        VER(NVRAM_EF_PHB_LID)
    },
    #endif
#endif
#endif

//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    {
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_TOTAL,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT70",
        VER(NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID)
        //"MB PROVISION CONTEXT",
        //NVRAM_APP_RESERVED
    },        
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

  {
        NVRAM_EF_TST_CONFIG_LID,
        NVRAM_EF_TST_CONFIG_TOTAL,
        NVRAM_EF_TST_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT72",
        VER(NVRAM_EF_TST_CONFIG_LID)
    },

#if defined(__ENABLE_MYBCCH__)
    {
        NVRAM_EF_MYBCCH_SETTING_DATA_LID,
        NVRAM_EF_MYBCCH_SETTING_DATA_TOTAL,
        NVRAM_EF_MYBCCH_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MYBCCH_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT73",
        VER(NVRAM_EF_MYBCCH_SETTING_DATA_LID)
    },
#endif
#if defined(__BCM_SUPPORT__) && defined(__BT_HFG_PROFILE__)
	{
		  NVRAM_EF_LND_ENTRY_LID,
		  NVRAM_EF_LND_ENTRY_TOTAL,
		  NVRAM_EF_LND_ENTRY_SIZE,
		  NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		  NVRAM_CATEGORY_USER,
		  NVRAM_ATTR_AVERAGE,
		  "SR21",
		  VER(NVRAM_EF_LND_ENTRY_LID)
	},

#endif /*defined(__BCM_SUPPORT__) && defined(__BT_HFG_PROFILE__)*/
    {
        NVRAM_EF_AT_PROFILE_LID,
        NVRAM_EF_AT_PROFILE_TOTAL,
        NVRAM_EF_AT_PROFILE_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_AT_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ATPR",
        VER(NVRAM_EF_AT_PROFILE_LID)
    },
    
    {
        NVRAM_EF_USR_PWR_CLS_LID,
        NVRAM_EF_USR_PWR_CLS_TOTAL,
        NVRAM_EF_USR_PWR_CLS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT74",
        VER(NVRAM_EF_USR_PWR_CLS_LID)
    },    
#if defined(__8_WIRE_UART_SUPPORT__)
    {
        NVRAM_EF_RI_CFG_LID,
        NVRAM_EF_RI_CFG_TOTAL,
        NVRAM_EF_RI_CFG_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_RI_CFG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "RICF",
        VER(NVRAM_EF_RI_CFG_LID)
     },
#endif /* __8_WIRE_UART_SUPPORT__ */ 
#if defined(__M2M_CSGT_SUPPORT__)
    {
        NVRAM_EF_M2M_CSGT_LID,
        NVRAM_EF_M2M_CSGT_TOTAL,
        NVRAM_EF_M2M_CSGT_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_M2M_CSGT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "CSGT",
        VER(NVRAM_EF_M2M_CSGT_LID)
    }
#endif /* __M2M_CSGT_SUPPORT__ */ 
};

/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID begin */
#ifdef NVRAM_AUTO_GEN
nvram_sys_cache_entry nvram_sys_cache[] =
{
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_BEGIN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "Record system cache will be restore or not",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),

    SYS_CACHE_ENTRY(NVRAM_SYS_FLIGHTMODE_STATE,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FLIGHTMODE_STATE",
                #if (GEMINI_PLUS == 4)
                    0x00, 0x00, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x00),
                #elif (GEMINI_PLUS == 3)
                    0x00, 0x00, 0x07, 0x00, 0x01, 0x00, 0x00, 0x00),
                #elif (GEMINI_PLUS == 2)
                    0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00),
                #else
                    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00),
                #endif
    SYS_CACHE_ENTRY(NVRAM_SYS_DSP_PATCH,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_DSP_PATCH",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SIM_PLUS_SETTING,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_SIM_PLUS_SETTING",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FACTORY_FLAG,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FACTORY_FLAG",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_LAST_FAT_STATUS,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_LAST_FAT_STATUS",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_INFO,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_INFO",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#if defined(NEPTUNE_MMI)
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#elif defined(__OP01_FWPBW__)
	SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
	                NVRAM_APP_RESERVED,
	                KAL_FALSE,
	                "NVRAM_SYS_PHB_COMPARE_DIGIT",
	                0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#else
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#endif
    SYS_CACHE_ENTRY(NVRAM_SYS_SVN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SVN",
                    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_BOOT_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_BOOT_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_TETHERING_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_TETHERING_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),                    
    SYS_CACHE_ENTRY(NVRAM_SYS_AUTO_TEST,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_AUTO_TEST\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SWLA,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SWLA\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_MS_CALI_ACC,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_MS_CALI_ACC\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_MOT_DECRYPTION,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_MOT_DECRYPTION\0",
                    0x12, 0x34, 0x56, 0x78, 0x9a, 0xbc, 0xde, 0xf0),                      
     SYS_CACHE_ENTRY(NVRAM_SYS_CALN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_CALN\0",
                    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    /* !!Add a entry above this line by using SYS_CACHE_ENTRY macro */
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_MAX,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "The last record of system cache",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
};
#endif
/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID end */

#endif /* NVRAM_NOT_PRESENT */
