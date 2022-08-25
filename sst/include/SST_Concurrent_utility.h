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
 *   SST_concurrent_utility.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the necessary API needed by concurrent ulitity.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _SST_CONCURRENT_UTILITY_
#define _SST_CONCURRENT_UTILITY_
#ifdef __cplusplus
 extern "C" {
#endif


#include "kal_general_types.h"

/*************************************************************************
 * Platform Capabilities Definition   
 *************************************************************************/
#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6276) || defined(MT6256) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#if !defined(__MT6276_CONCURRENCY_TEST__) && !defined(__SLA_INST_COUNT_SUPPORT__) && !defined(__MT6256_CONCURRENCY_TEST__) && !defined(__MT6255_CONCURRENCY_TEST__)
#define __HW_EMI_MONITOR_SUPPORT__
#endif /* !__MT6276_CONCURRENCY_TEST__ */

#endif /* MT6268 || MT6236 || MT6236B || MT6253 */

/*************************************************************************
 * Prevent Wrong Configuration   
 *************************************************************************/
#if defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__)
#if !defined(__HW_EMI_MONITOR_SUPPORT__)
#error "Current Platform CAN NOT TURN ON PROFESSIONAL EMI MONITOR"
#endif /* __HW_EMI_MONITOR_SUPPORT__ */
#endif /* __MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__ */


/*************************************************************************
 * ENUM Definition : Sync with Catcher 
 *************************************************************************/
typedef enum
{
   HEADER_ID_MAIN_TQCNT           = 0x00000001,
   HEADER_ID_MAIN_USEC            = 0x00000002,
   HEADER_ID_NUCLEUS_V1           = 0x00000000,
   HEADER_ID_NUCLEUS_V2           = 0x00000010,
   HEADER_ID_TIME_STAMP_BASE      = 0x00000100,
   HEADER_ID_EXTRA_INFO           = 0x00000103,
   HEADER_ID_TWO_RATIOS           = 0x00000104,
   HEADER_ID_OVERHEAD             = 0x00000105,
   HEADER_ID_CUST_OVERHEAD        = 0x00000106,
   HEADER_ID_EXTERNAL_BN          = 0x00010005,
   HEADER_ID_EXTERNAL_EMI_GERNAL  = 0x00010006,
   HEADER_ID_EXTERNAL_EMI_PRO     = 0x00010007,
   HEADER_ID_EXTERNAL_TST         = 0x00010008,
#if defined(__MT6276_CONCURRENCY_TEST__) || defined(__MT6256_CONCURRENCY_TEST__)
   HEADER_ID_EXTERNAL_MT6276_CONCURRENCY         = 0x00010009,
#endif /* __MT6276_CONCURRENCY_TEST__ */
   HEADER_ID_EXTERNAL_INST_COUNT  = 0x0001000A,
   HEADER_ID_EXTERNAL_CONCURRENCY = 0x0001000B,
   HEADER_ID_EXTERNAL_MAX         = 0x00010010
} SA_HEADER_ID_T;

/*************************************************************************
 * Structure Definition : Basic and Professional EMI Monitor Logging Node
 *************************************************************************/
#if defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__) && ( defined(MT6268) || defined(MT6270A) )
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;         /* total bus cycle count                     */
    kal_uint32 busy_all_cnt;     /* all master busy count                     */
    kal_uint32 trans_all_cnt;    /* all master transaction count              */
    kal_uint32 word_all_cnt;     /* all master word(8bytes) count             */
    kal_uint32 trans_cnt1;       /* Monitor master group 1 transaction count  */
    kal_uint32 word_cnt1;        /* Monitor master group 1 word(8bytes) count */
    kal_uint32 trans_cnt2;       /* Monitor master group 2 transaction count  */
    kal_uint32 word_cnt2;        /* Monitor master group 2 word(8bytes) count */
    kal_uint32 trans_cnt3;       /* Monitor master group 3 transaction count  */
    kal_uint32 word_cnt3;        /* Monitor master group 3 word(8bytes) count */
}BM_Log;

#elif defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__) && ( defined(MT6236) || defined(MT6236B) )
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count     */
    kal_uint32 busy_all_cnt;    /* all master busy count     */
    kal_uint32 busy_cnt;        /* monitor master busy count */
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6268) || defined(MT6270A) )
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count                     */
    kal_uint32 busy_all_cnt;    /* all master busy count                     */
    kal_uint32 trans_all_cnt;   /* all master transaction count              */
    kal_uint32 word_all_cnt;    /* all master word(8bytes) count             */
    kal_uint32 trans_cnt;       /* Monitor master group 1 transaction count  */
    kal_uint32 word_cnt;        /* Monitor master group 1 word(8bytes) count */
}BM_Log;

#elif defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__) && (defined(MT6276) || defined(MT6256))
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count                     */
    kal_uint32 busy_all_cnt;    /* all master busy count                     */
    kal_uint32 busy_cnt;         /* monitor master busy count */
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && (defined(MT6276) || defined(MT6256))
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count                     */
    kal_uint32 busy_all_cnt;    /* all master busy count                     */
    kal_uint32 busy_cnt;         /* monitor master busy count */
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && defined(MT6255)
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count */
    kal_uint32 busy_all_cnt;    /* all master busy count */
    kal_uint32 busy_cnt;        /* monitor master busy count */
    kal_uint32 busy_cnt2;
    kal_uint32 busy_cnt3;
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6253) )
typedef struct BM_LOG_T
{
    /* Cache (cache linefill) */
    kal_uint32 cache_hcnt0L;
    kal_uint32 cache_hcnt0U;
    kal_uint32 cache_ccnt0L;
    kal_uint32 cache_ccnt0U;
    kal_uint32 cache_hcnt1L;
    kal_uint32 cache_hcnt1U;
    kal_uint32 cache_ccnt1L;
    kal_uint32 cache_ccnt1U;

    /* AHB (DMA burst transaction) */
    kal_uint32 ahb_databeat;

    /* EMI (MCU single) */
    kal_uint32 byte_cnt;        /* byte count */     
    kal_uint32 hword_cnt;       /* half-word count */
    kal_uint32 word_cnt;        /* word count */
    kal_uint32 cycle_cnt;       /* total cycle count */
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) )
typedef struct BM_LOG_T
{
    kal_uint32 cyccnt;
	kal_uint32 bsycnt;
	kal_uint32 MCU_bsycnt;
	kal_uint32 DMA_bsycnt;
    kal_uint32 cache_hcnt;
    kal_uint32 cache_ccnt;
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6250) )
typedef struct BM_LOG_T
{
    kal_uint32 emi_cyccnt;
	kal_uint32 emi_bsycnt;
	kal_uint32 emi_MCU_bsycnt;
	kal_uint32 emi_DMA_bsycnt;
	kal_uint32 sfi_cyccnt;
	kal_uint32 sfi_bsycnt;     // MAC + MCU + DMA + GMC
	kal_uint32 sfi_MAC_bsycnt; //MAC
	kal_uint32 sfi_CDP_bsycnt; //ch 2
	kal_uint32 sfi_DMA_bsycnt; //ch 3
    kal_uint32 cache_hcnt;
    kal_uint32 cache_ccnt;
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )
typedef struct BM_LOG_T
{
    kal_uint32 emi_cyccnt;
	kal_uint32 emi_bsycnt;
	kal_uint32 emi_MCU_bsycnt;
	kal_uint32 emi_DMA_bsycnt;
	kal_uint32 sfi_cyccnt;
	kal_uint32 sfi_bsycnt;     // MAC + MCU + CDP
	kal_uint32 sfi_MAC_bsycnt; // MAC
	kal_uint32 sfi_CDP_bsycnt; // ch2: CDP
    kal_uint32 cache_hcnt;
    kal_uint32 cache_ccnt;
}BM_Log;

#elif defined(__HW_EMI_MONITOR_SUPPORT__)
typedef struct BM_LOG_T
{
    kal_uint32 bus_ccnt;        /* total bus cycle count     */
    kal_uint32 busy_all_cnt;    /* all master busy count     */
    kal_uint32 busy_cnt;        /* monitor master busy count */
}BM_Log;

#endif /* __MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__ */

/*************************************************************************
 * Structure Definition : Auxiliary Structures
 *************************************************************************/
#if defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256)|| defined(MT6270A)
typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
    kal_uint32 EMI_CONA_Val;
    kal_uint32 EMI_CONB_Val;
#if !defined(MT6256)	
    kal_uint32 EMI_CONC_Val;
    kal_uint32 EMI_COND_Val;
#endif	
    kal_uint32 EMI_CONE_Val;
    kal_uint32 EMI_CONF_Val;
#if !defined(MT6256)		
    kal_uint32 EMI_CONG_Val;
    kal_uint32 EMI_CONH_Val;
#endif	
    kal_uint32 EMI_CONI_Val;
    kal_uint32 EMI_CONJ_Val;
    kal_uint32 EMI_CONK_Val;
    kal_uint32 EMI_CONL_Val;
    kal_uint32 EMI_CONM_Val;
    kal_uint32 EMI_CONN_Val;    
    kal_uint32 EMI_GEND_Val;
    kal_uint32 EMI_BMEN_Val;
    kal_uint32 EMI_BSEL_Val;
#if defined(MT6276)
    kal_uint32 EPLL_CON0_Val;
#elif defined(MT6256)
    kal_uint32 EPLL_CON2_Val;
#endif
}EMI_Setting;

#elif defined(MT6255) 

typedef struct EMI_Setting_T
{
    kal_uint32 usage_type;
    kal_uint32 EMI_CONA_Val;
    kal_uint32 EMI_CONB_Val;

    kal_uint32 EMI_CONE_Val;
    kal_uint32 EMI_CONF_Val;
   
    kal_uint32 EMI_CONI_Val;
    kal_uint32 EMI_CONJ_Val;
    kal_uint32 EMI_CONK_Val;
    kal_uint32 EMI_CONL_Val;
    kal_uint32 EMI_CONM_Val;
    kal_uint32 EMI_CONN_Val;    
    kal_uint32 EMI_GEND_Val;
    kal_uint32 EMI_BMEN_Val;
    kal_uint32 EMI_MSEL_Val; 
    
    kal_uint32 EMI_FREQ;
}EMI_Setting;

#elif defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
typedef struct EMI_Setting_T
{
    kal_uint32 EMI_CONA_Val;
    kal_uint32 EMI_CONB_Val;
    kal_uint32 EMI_CONC_Val;
    kal_uint32 EMI_COND_Val;
    kal_uint32 EMI_GEN_Val;
}EMI_Setting;

#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct EMI_Setting_T
{
    kal_uint32 EMI_CONA_Val;
    kal_uint32 EMI_CONB_Val;
}EMI_Setting;

#endif

/*************************************************************************
 * Structure Definition : Basic and Professional EMI Monitor Init Reference
 *************************************************************************/
#if defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__) && ( defined(MT6268) || defined(MT6276) || defined(MT6256) || defined(MT6270A) )
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;

#elif defined(__MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__) && ( defined(MT6236) || defined(MT6236B) )
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6268) || defined(MT6276) || defined(MT6256) || defined(MT6270A) || defined(MT6255) )
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6253) )
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;

#elif defined(__HW_EMI_MONITOR_SUPPORT__) && ( defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) )
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    EMI_Setting      emi_settings;
}BM_Ref;


#elif defined(__HW_EMI_MONITOR_SUPPORT__)
typedef struct BM_REF_T
{
    SA_HEADER_ID_T   id;
    kal_uint32       szRef;
    kal_char         line1_name[8];
    kal_char         line2_name[8];
}BM_Ref;

#endif /* __MAUI_SWLA_PROFESSIONAL_EMI_MONITOR__ */

/*************************************************************************
 * Exported APIs for Software LA
 *************************************************************************/
#if defined(__HW_EMI_MONITOR_SUPPORT__)
extern void Setup_AddOn_RefData(SA_HEADER_ID_T id,  kal_uint8 **ARef, kal_uint32 *szARef);
extern void Get_BM_Log( BM_Log* pLog );
extern void Enable_Normal_EMI_Monitor(void);
#endif /* __HW_EMI_MONITOR_SUPPORT__ */



#ifdef __cplusplus
}
#endif
#endif /* _SST_CONCURRENT_UTILITY_ */
