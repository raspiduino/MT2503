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
 * nvram_cust_pack.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
#if !defined(NVRAM_NOT_PRESENT) && !defined(__L1_STANDALONE__)
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_release.h"
#include "nvram_data_items.h"
#include "nvram_defs.h"
#include "nvram_editor_data_item.h"
#include "ul1_nvram_def.h"

#if defined(__MMI_FMI__)
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"

#endif

#ifdef __PS_SERVICE__
#include "custom_gprs_pdp_default_qos_config.h" // Carlson, for PS_QOS_PROFILE_DEFAULT_REQ_XXX and PS_QOS_PROFILE_DEFAULT_MIN_XXX
#endif

/* Add include statement above this line */
#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif

/*
        3G multiband support
bit     |	8     7    6    5    4    3    2    1
  |-------------------------------------------
byte 0  | VIII  VII  VI   V    IV	  III  II   I
  |-------------------------------------------
byte 1  |                                X    IX

*/
typedef enum
{
    Support_UMTS_BAND_I     = 0x01,
    Support_UMTS_BAND_II    = 0x02,
    Support_UMTS_BAND_III   = 0x04,
    Support_UMTS_BAND_IV    = 0x08,
    Support_UMTS_BAND_V	    = 0x10,
    Support_UMTS_BAND_VI    = 0x20,
    Support_UMTS_BAND_VII   = 0x40,
    Support_UMTS_BAND_VIII  = 0x80,
    Support_UMTS_BAND_IX    = 0x01,
    Support_UMTS_BAND_X     = 0x02
}rac_multi_band_option_enum;

#if !defined(EXTERNAL_MMI)
#ifdef __MAX_MAILBOX_NAME_UPDATA_TO_30__
const kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Alpha ID */
    0x00,   /* Length of BCD number */
    0xff,   /* TON and NPI */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Dailling number */
    0xff,   /* capability/configuration identifier */
    0xff    /* extension 1 record identifier */
};
#else
const kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Alpha ID */
    0x00,   /* Length of BCD number */
    0xff,   /* TON and NPI */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Dailling number */
    0xff,   /* capability/configuration identifier */
    0xff    /* extension 1 record identifier */
};
#endif
#endif

kal_uint8 const COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[] =
{
/*
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // reg_ps_key
*/
    0x00,                                                   /* security_indication */
/*
    0x00,                                                   // auto_lock_item
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // np_code
    0x21, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // np_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // nsp_code
    0x65, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // nsp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,                                       // np_of_sp
    0x00, 0x00, 0x00,                                       // np_of_cp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // gid1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // gid2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // sp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // cp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // imsi_code
    0x33, 0x44, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // imsi_key
*/
    0x11, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // phone_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // last_imsi
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // pin1
    0x00,                                                   // pin1_valid
    0x00,                                                    // phone_lock_verified
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 // iccid
};

#ifdef __CPHS__
const kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[NVRAM_EF_ALS_LINE_ID_SIZE] =
{
    0x0, 0x0
};
#endif /* __CPHS__ */

const kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[NVRAM_EF_MSCAP_SIZE] =
{
/* Byte 1~4 describes MS supported codec
 * 1. Codec types is coded as the definition in TS26.103, Sec. 6.2, Codec Bitmap
 * 2. Spec Codec Bitmap combines GSM and UMTS together, whereas we separate codec
 *    types according to different radio access technologies. So GAS can directly
 *    read first 2 bytes for speech capability.
 */
#if defined(__AMR_SUPPORT__)
    0x1f,   /* Supported speech version (FR,HR,EFR,AMR FR,AMR HR) */
#else
    0x07,   /* Supported speech version (FR,HR,EFR) */
#endif 
//0528_AMRWB: Restructure EF_MSCAP, put speech codec bytes together
#if defined(__AMRWB_LINK_SUPPORT__)
#if defined(__AMR_WB_WHITE_LIST__)
    0x02,  /* byte 2 for GSM supported codec, (FR AMRWB) */
#else
    0x00,  /* byte 2 for GSM supported codec */
#endif
#else
    0x00,  /* byte 2 for GSM supported codec */
#endif
#ifdef __UMTS_TDD128_MODE__ /*MAUI_03233682*/
    0x20,
#else
    0x60,  /* byte 1 for UMTS supported codec,(UMTS_AMR, UMTS_AMR2) */  
#endif
#if defined(__AMRWB_LINK_SUPPORT__)
    0x04,  /* byte 2 for GSM supported codec, (UMTS_AMRWB) */
#else
    0x00,  /* byte 2 for UMTS supported codec */
#endif
#if defined(__CSD_T__) && defined(__CSD_NT__) && defined(__CSD_FAX__)
#ifdef __SYNC_HDLC_CSD__
    0x6b,   /* Supported data capability 1 (T & NT & FAX_T) */
#else
    0x63,   /* Supported data capability 1 (T & NT & FAX_T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_T__) && defined(__CSD_NT__)
#ifdef __SYNC_HDLC_CSD__
    0x69,   /* Supported data capability 1 (T & NT) */
#else
    0x61,   /* Supported data capability 1 (T & NT) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_T__) && defined(__CSD_FAX__)
#ifdef __SYNC_HDLC_CSD__
    0x2b,   /* Supported data capability 1 (T & FAX_T) */
#else
    0x23,   /* Supported data capability 1 (T & FAX_T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_NT__) && defined(__CSD_FAX__)
    0x43,   /* Supported data capability 1 (NT & FAX_T) */
#elif defined(__CSD_T__)
#ifdef __SYNC_HDLC_CSD__
    0x29,   /* Supported data capability 1 (ONLY T) */
#else
    0x21,   /* Supported data capability 1 (ONLY T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_NT__)
    0x41,   /* Supported data capability 1 (ONLY NT) */
#elif defined(__CSD_FAX__)
    0x02,   /* Supported data capability 1 (ONLY FAX_T) */
#else
    0x00,   /* Supported data capability 1 (NO SUPPORT CSD) */
#endif
    0x00,   /* Supported data capability 2 */
#if defined(CSD_SUPPORT) || defined(__CSD_FAX__)
    0x1f,    /* Supported channel coding (2.4k,4.8k,9.6k,14.4k,HR) */
#else /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */
    0x00,
#endif /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */
    0x00 /*0x01 mean disable call , 0x00 mean not disable call*/
};

#ifdef __UMTS_TDD128_MODE__
kal_uint8 const COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[] = 
{
    /* Ripple: 20050513, Auto band, then turn on all supported bands. */
    //mtk02475: change to bitmap coding style, avoid enumarate all band setting combination
    0
#if defined(__EGSM900__) && defined(__DISABLE_EGSM__) //mtk02475: AS and L1 need keep EGSM compile option turn on, request RAC turn on PGSM only
    + 0x01
#else /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __PGSM900__
    + 0x01
#endif /* __PGSM900__ */
#ifdef __EGSM900__
    + 0x02
#endif /* __EGSM900__ */
#endif /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __RGSM900__
    + 0x04
#endif /* __RGSM900__ */
#ifdef __DCS1800__
    + 0x08
#endif /* __DCS1800__ */
#ifdef __PCS1900__
    + 0x10
#endif /* __PCS1900__ */
#ifdef __GSM450__
    + 0x20
#endif /* __GSM450__ */
#ifdef __GSM850__
    + 0x80
#endif /* __GSM850__ */
    ,
    // 0x80 /* PLMN selection mode and Preferred Service in NMO III */
    //mtk02475: merge MODEM project specific default value via compile option, set GPRS always on for single SIM modem project.
#ifdef __GEMINI__
    0xC0    /* GPRS when needed */
#else /* __GEMINI__ */
    0xD0    /* GPRS always on */
#endif /* __GEMINI__ */
#ifdef __DYNAMIC_ROAMING_SUPPORT__
        +0x02
#else
        +0x00
#endif
#ifdef __PLMN_LIST_PREF_SUPPORT__
+ 0x00 /*PLMN_LIST_PREFERENCE: 0: ACCURACY FIRST, 1: SPEED_FIRST*/
#endif
#ifdef __MTK_3G_MRAT_ARCH__ /* for RAC2 */
,
/* 3rd  byte is RAT mode*/
#if defined( __UMTS_RAT__ ) && defined( __GSM_RAT__ )
/* under construction !*/
#elif defined( __UMTS_RAT__ )
/* under construction !*/
#elif defined( __GSM_RAT__ )
    0x01,
#else
    0x00,
#endif


/* 4th  byte is IR preferred RAT and MM preferred RAT */
// MM preferred RAT 0x00 : RAT_NONE  0x01 : RAT_GSM 0x02 : RAT_UMTS  
    0x00
    +
// IR preferred RAT 0x00 : RAT_NONE  0x10 : RAT_GSM 0x20 : RAT_UMTS  
    0x00
    , 

/* 5th  byte is first byte of UMTS preferred band */
    0 // initial value

#if defined(__UMTS_BAND_I__) || defined(__UMTS_TDD128_BAND_A__)
    + Support_UMTS_BAND_I
#endif

#if defined(__UMTS_BAND_II__) || defined(__UMTS_TDD128_BAND_B__) 
    + Support_UMTS_BAND_II
#endif

#if defined(__UMTS_BAND_III__) || defined(__UMTS_TDD128_BAND_C__)
    + Support_UMTS_BAND_III
#endif

#if defined(__UMTS_BAND_IV__) || defined(__UMTS_TDD128_BAND_D__) 
    + Support_UMTS_BAND_IV
#endif

#if defined(__UMTS_BAND_V__) || defined(__UMTS_TDD128_BAND_E__) 
    + Support_UMTS_BAND_V
#endif

#if defined(__UMTS_BAND_VI__) || defined(__UMTS_TDD128_BAND_F__) 
    + Support_UMTS_BAND_VI
#endif

#if defined(__UMTS_BAND_VII__) 
    + Support_UMTS_BAND_VII
#endif

#if defined(__UMTS_BAND_VIII__) 
    + Support_UMTS_BAND_VIII
#endif

#if 1 
    ,  // end of character
#endif
    /* 6th  byte is second byte of UMTS preferred band */                   
    0 // initial value

#if defined(__UMTS_BAND_IX__) 
    + Support_UMTS_BAND_IX
#endif

#if defined(__UMTS_BAND_X__) 
    + Support_UMTS_BAND_X
#endif

#if 1 
			//,	// end of character
#endif
#if 1 
		    ,  // end of character
#endif
		    /* 7th byte is HSPA preference + GPRS transfer preference*/
		    0
#ifdef __HSPA_PREFERENCE_SETTING__
        //mtk02475: default turn on maximum HSPA capability
#if defined(__HSUPA_SUPPORT__)
        + 0x20
#elif defined(__HSDPA_SUPPORT__)
        + 0x10
#else
		    + 0x00  // 0x00 for HSPA_OFF, 0x10 for HSDPA_ON, 0x20 for HSDPA_HSUPA_ON
#endif
#endif		
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
        + 0x04  // 0x00 for NO_PREEMPTION, 0x04 for PREEMPT_PEER_PS_TRANSFER
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
        + 0x01  // 0 for GPRS_PREFER, 1 for CALL prefer, // 2 for AS_OPTIMAL(reserved)
#endif

#if 1 
    //,	// end of character
#endif


#endif // end of __MTK_3G_MRAT_ARCH__
};
#else
kal_uint8 const COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[] =
{
    /* Ripple: 20050513, Auto band, then turn on all supported bands. */
    //mtk02475: change to bitmap coding style, avoid enumarate all band setting combination
    0
#if defined(__EGSM900__) && defined(__DISABLE_EGSM__) //mtk02475: AS and L1 need keep EGSM compile option turn on, request RAC turn on PGSM only
    + 0x01
#else /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __PGSM900__
    + 0x01
#endif /* __PGSM900__ */
#ifdef __EGSM900__
    + 0x02
#endif /* __EGSM900__ */
#endif /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __RGSM900__
    + 0x04
#endif /* __RGSM900__ */
#ifdef __DCS1800__
    + 0x08
#endif /* __DCS1800__ */
#ifdef __PCS1900__
    + 0x10
#endif /* __PCS1900__ */
#ifdef __GSM450__
    + 0x20
#endif /* __GSM450__ */
#ifdef __GSM850__
    + 0x80
#endif /* __GSM850__ */
    ,
    // 0x80 /* PLMN selection mode and Preferred Service in NMO III */
#if defined(__MMI_FMI__) || defined(__GEMINI__)
    0xC0    /* GPRS when needed */
#else /* __MMI_FMI__ || __GEMINI__ */
    0xD0    /* GPRS always on */
#endif /* __MMI_FMI__ || GEMINI__ */
#ifdef __PLMN_LIST_PREF_SUPPORT__
+ 0x00 /*PLMN_LIST_PREFERENCE: 0: ACCURACY FIRST, 1: SPEED_FIRST*/
#endif

,
/* 3rd  byte is RAT mode*/
#if defined( __UMTS_RAT__ ) && defined( __GSM_RAT__ )
/* under construction !*/
#elif defined( __UMTS_RAT__ )
/* under construction !*/
#elif defined( __GSM_RAT__ )
    0x01,
#else
    0x00,
#endif

/* 4th  byte is IR preferred RAT and MM preferred RAT */
// MM preferred RAT 0x00 : RAT_NONE  0x01 : RAT_GSM 0x02 : RAT_UMTS  
    0x00
    +
// IR preferred RAT 0x00 : RAT_NONE  0x10 : RAT_GSM 0x20 : RAT_UMTS  
    0x00
    , 

/* 5th  byte is first byte of UMTS preferred band, UMTS_PREFERRED_BAND_FIRST_BYTE */
// mtk02475: for MT6276/MT6573 UMTS band customization, need to default turn on all UMTS band instead of check UMTS band feature option
    0 // initial value

#if defined(__UMTS_BAND_I__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_I
#endif

#if defined(__UMTS_BAND_II__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_II
#endif

#if defined(__UMTS_BAND_III__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_III
#endif

#if defined(__UMTS_BAND_IV__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_IV
#endif

#if defined(__UMTS_BAND_V__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_V
#endif

#if defined(__UMTS_BAND_VI__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_VI
#endif

#if defined(__UMTS_BAND_VII__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_VII
#endif

#if defined(__UMTS_BAND_VIII__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_VIII
#endif

#if 1
    ,  // end of character
#endif
    /* 6th  byte is second byte of UMTS preferred band, UMTS_PREFERRED_BAND_SECOND_BYTE */
    0 // initial value

#if defined(__UMTS_BAND_IX__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_IX
#endif

#if defined(__UMTS_BAND_X__) || defined(__FDD_RF_CUSTOM_TOOL_SUPPORT__)
    + Support_UMTS_BAND_X
#endif

#if 1
    ,  // end of character
#endif
/* 7th byte is HSPA preference + GPRS transfer preference*/
    0
#ifdef __HSPA_PREFERENCE_SETTING__
    //mtk02475: default turn on maximum HSPA capability
#if defined(__HSUPA_SUPPORT__)
    + 0x20
#elif defined(__HSDPA_SUPPORT__)
    + 0x10
#else
    + 0x00  // 0x00 for HSPA_OFF, 0x10 for HSDPA_ON, 0x20 for HSDPA_HSUPA_ON
#endif 
#endif /* __HSPA_PREFERENCE_SETTING__ */
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    + 0x00  // 0x00 for NO_PREEMPTION, 0x04 for PREEMPT_PEER_PS_TRANSFER
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    + 0x00  // 0 for GPRS_PREFER, 1 for CALL prefer, // 2 for AS_OPTIMAL(reserved)
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

#if 1
    //,	// end of character
#endif

};
#endif /* #ifdef __UMTS_TDD128_MODE__ */

kal_uint8 const COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[] =
{
#if defined (__CS_SERVICE__) && defined (__SMS_OVER_PS_SUPPORT__)
    0x03,               /* bearer service : GSM prefer */
#elif defined (__SMS_OVER_PS_SUPPORT__)
    0x00,               /* bearer service : GPRS Only */
#else
    0x01,               /* bearer service : GSM Only */
#endif
    0x00, 0x00,         /* status report, reply path OFF */
    0x02,               /* VP: Relative format */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    0x01, 0x01, 0x01,   /* mem1, mem2, mem3 */
#else/* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    0x05, 0x05, 0x05,   /* mem1, mem2, mem3 */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    0x00, 0x01,         /* CB setting */
    0x00,               /* AT default profile ID */
    0x00,               /* First Octet */
    0x00,               /* Turn Off SMS FDN */
    0x00,               /* last_used_tp_mr */
    0x00,               /* mem_capacity_available */
    0x00,               /* selected_msp */
    0x00                /* reserve */
};

/* Cell Broadcast Default Channel Setting. */
/* The channels set will not shown in MMI, but it will received CB if CB is turned on. */
/* This setting may be changed by customer. DON'T remove it. */
kal_uint8 const COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[] =
{
    0xFF, 0xFF, /* default CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* default CH 2  */
    0xFF, 0xFF, /* default CH 3  */
    0xFF, 0xFF, /* default CH 4  */
    0xFF, 0xFF, /* default CH 5  */
    0xFF, 0xFF, /* default CH 6  */
    0xFF, 0xFF, /* default CH 7  */
    0xFF, 0xFF, /* default CH 8  */
    0xFF, 0xFF, /* default CH 9  */
    0xFF, 0xFF  /* default CH 10 */
};



//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
nvram_ef_mobile_broadband_provision_context_struct const COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[] =
{
    /* Example Entry 1: 46692, internet */
    {
        1,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "internet",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46692",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied
    },

    /* Example Entry 2: 46601, fetnet01 */
    {
        2,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "fetnet01",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46601",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied        
    },    

    /* Example Entry 3: 46697, internet */
    {
        3,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "internet",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46697",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied        
    },    

    /* Example Entry 4: 46692, emome */
    {
        4,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "emome",                   //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46692" ,                  //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied        
    },
    
    /* Example Entry 5: empty */
    {
        5,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },
    
    /* Example Entry 6: empty */
    {
        6,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },        

    /* Example Entry 7: empty */
    {
        7,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },
    
    /* Example Entry 8: empty */
    {
        8,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },            

    /* Example Entry 9: empty */
    {
        9,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },
    
    /* Example Entry 10:empty */
    {
        10,                        //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    }
};
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

#if defined (__UL1_HS_PLATFORM__)
#if defined (__MTK_UL1_FDD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__FDD_RF_CUSTOM_TOOL_SUPPORT__)
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
#endif /* #if defined (__FDD_RF_CUSTOM_TOOL_SUPPORT__) */
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
#endif /* #if defined (__MTK_UL1_FDD__) */
#endif /* #if defined (__UL1_HS_PLATFORM__) */

#if defined (__UL1_PLATFORM__)
#if defined (__MTK_UL1_FDD__)
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
#if defined (MT6162_RF) // MT6162 has two low band receivers
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if defined (__MTK_UL1_FDD__) */
#endif /* #if defined (__UL1_PLATFORM__) */


#define NVRAM_INTERNAL_USE

/* nvram default decleartion start */
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
    #include "nvram_cust_pack_default_value.c"
#else
    #if defined(__MMI_FMI__)
        #include "nvram_common_custpack.c"
        #include "nvram_user_custpack.c"
        #if defined(NEPTUNE_MMI)
            #include "nvram_mmi_cache_cust_pack.h"
        #endif
        #include "nvram_custpack_table.c"
    #endif  /* __MMI_FMI__ */
#endif /* __NVRAM_COMPRESS_SUPPORT__ */

#undef NVRAM_INTERNAL_USE

#endif /* !defined(NVRAM_NOT_PRESENT) && !defined(__L1_STANDALONE__) */

