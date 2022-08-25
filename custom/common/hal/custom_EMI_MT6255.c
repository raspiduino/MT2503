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
 *   custom_EMI_MT6255.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 * -------
 *
 *   Memory Device database last modified on 2011/3/18
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(MT6255) || defined(MT6922)) && defined(__MTK_TARGET__)

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "reg_base.h"
#include "emi_hw.h"
#include "init.h"
#include "pll.h"
#include "MemoryDevice_TypeDef.h"
#include "custom_emi.h"
#include "config_hw.h"
#include "cache_hw.h"

#include "custom_EMI_release.h"
#include "cp15.h"

#if (defined(MT6255) || defined(MT6922))
#include "dcm.h"
#endif

/** 
  *     CMEM_EMIINIT_Index() is defined in "combo_flash_init.h"
  *     it should be included at autoGen for Combo Memory !!
  *
  */
#include "combo_flash_init.h"

#if (defined(MT6255) || defined(MT6922))
#include "cp15.h"
#endif /* MT6268 || MT6236 || MT6236B || MT6276 || MT6256 */

#include "custom_EMI_info.h"


/****************************************************************************
   *
   * Specify high-level feature option for EMI driver (internal usage).
   *
   ****************************************************************************/
/**
  * On SRAM configuration, the old EMI init flow will perform Sync/Page EMI initialization at INTSRAM_ROCODE section, while 
  * the new EMI init flow will perform this flow at EMIINITCODE section.
  * Note that the __EMI_INIT_FLOW_Vx__ has different version maintenance on NOR case and NAND case, that is, 
  * NOR case has its V1->V2->V3, and NAND case has its own V1->V2->V3.
  */
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)

/**
   * EMI init flow is INT_SetPLL() -> custom_setEMI() -> Init execution regions.
   */
#define __EMI_INIT_FLOW_V1__

#else /* _NAND_FLASH_BOOTING_ */
/**
   * EMI init flow is [custom_setEMI() -> INT_SetPLL() -> custom_setAdvEMI()]@int.ram -> Init execution regions.
   */
#define __EMI_INIT_FLOW_V2__

#endif /* _NAND_FLASH_BOOTING_ */

/**
  * __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
  * We add this compile option to avoid compiling functions other than custom_setEMI() so to reduce the lib size.
  * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
  * the wrapping option so that Bootloader could reference the custom_setAdvEMI() function on __EMI_INIT_FLOW_V2__.
  */
#if defined(__EMI_INIT_FLOW_V1__)

#if defined(__FUE__)
/**
   * Do nothing.
   */
#endif  /* __FUE__ */

#if defined(__UBL__)
/**
   * Do nothing.
   */
#endif /* __UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#define __EMI_NECESSARY_DRIVER__
#endif /* !__FUE__ && __UBL__!*/

#elif defined(__EMI_INIT_FLOW_V2__) /* __EMI_INIT_FLOW_V1__ */

#if defined(__FUE__)
/**
   * Do nothing.
   */
#endif  /* __FUE__ */

#if defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#endif /* __UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#define __EMI_OPTION_DRIVER__
#define __EMI_NECESSARY_DRIVER__
#endif /* !__FUE__ && __UBL__!*/

#endif /* __EMI_INIT_FLOW_V1__ */
#if !defined(_NAND_FLASH_BOOTING_)
#ifdef REMAPPING
#define FLASH_BASE_ADDR 0x10000000
#define RAM_BASE_ADDR   0x00000000
#else
#define FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR   0x10000000
#endif

#endif /*_NAND_FLASH_BOOTING_*/

#if (defined(MT6255) || defined(MT6922))
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)

/**
  * Define EMI enable data auto-tracking or not (if we do not use data auto-tracking, we will enable 1/5T PLL).
  * It is for DVT usage only.
  */
//#define __EMI_DATA_AUTO_TRACKING_ENABLE

/**
  * Use to filtering EVB 
  */
//#define __DBG_EVB_CHECK_FAIL
//#define __DQIDLY_BOUNDARY 0x1f //Use to seperate the factor4 of RX timing tuning

//#define __LOG_DATA_TRAIN_ERROR_INFO

/**
   * Define EMI that supporting MBIST functionality.
   */
#define ___EMIDATATRAIN_MBIST_DATATRAIN__
#endif
#endif //#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6922)
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)

/****************************************************************************
   *
   * Struct
   *
   ****************************************************************************/

typedef struct 
{
    unsigned long EMI_DLLV_regval;
    unsigned long EMI_DQSV_regval;    
    unsigned long EMI_CONN_regval;        
    unsigned long EMI_DQSA_regval;
    unsigned long EMI_DQSB_regval;
    unsigned long EMI_DQSE_regval;   
    unsigned long EMI_IDLA_regval;
    unsigned long EMI_IDLB_regval;
    unsigned long EMI_IDLC_regval;
    unsigned long EMI_IDLD_regval;
    unsigned long EMI_IDLE_regval;
    unsigned long EMI_IDLF_regval;
    unsigned long EMI_IDLG_regval;
    unsigned long EMI_IDLH_regval;
    unsigned long EMI_IDLI_regval;    
    unsigned long EMI_CALA_regval;
    unsigned long EMI_CALE_regval;
    unsigned long EMI_CALI_regval;
    unsigned long EMI_CALB_regval;
    unsigned long EMI_CALF_regval;
    unsigned long EMI_CALJ_regval;
    unsigned long EMI_CALP_regval;    
} EMI_DATA_TRAIN_REG_t;


typedef struct 
{
    kal_int32 algo_sel;
    kal_int32 addr_scramble_sel;
    kal_int32 data_scramble_sel;
    kal_uint32 err_addr;
    kal_uint32  err_wdataL;
    kal_uint32 err_wdataH;
    kal_uint32 err_rdataL;
    kal_uint32 err_rdataH;
} EMI_DATA_TRAIN_ERR_INFO_t;

/****************************************************************************
   *
   * Macro.
   *
   ****************************************************************************/

#define __EMI_DelayLoop(dly_val) \
    do { \
        kal_int32 dly; \
        for(dly = dly_val; dly != 0; dly--); \
    } while(0)
    
#endif
/*************************************
  *
  * Imported APIs.
  *
  *************************************/

/**
  * We will use this function to retrieve the current NOR base address with corresponding L2 cache-bypass bit set so that 
  * we could issue switch command to NOR safely.
  */
#if (!defined(_NAND_FLASH_BOOTING_) && !defined(__SIP_RAM_SIZE__))
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);
#endif


#if (defined(MT6255) || defined(MT6922))
/**
   * For auto tracking calibration 
   */
extern kal_int32 store_8word(kal_uint32,kal_uint32);
extern kal_int32 load_8word(kal_uint32,kal_uint32);
#endif /* MT6268 || MT6236 || MT6236B || MT6276 || MT6256 || MT6255*/

#if defined(__EMI_COMBO_EN)

extern kal_int32 CMEM_EMIINIT_Index(void);
extern kal_int32 CMEM_Index(void);
#endif

extern SW_SECVERSION INT_SW_SecVersion(void);
int __EMI_EnableBandwidthLimiter( void );
void EMI_Read_EF(void);
kal_int32 EMI_two_complement(kal_int32 , int );
int custom_EMIDynamicClockSwitch(mcu_clock_enum);
extern int custom_SFIDynamicClockSwitch(mcu_clock_enum);
/*************************************
  *
  * Global Variables.
  *
  *************************************/
  #if defined(__SIP_RAM_SIZE__)
  #else
  #if defined(_NAND_FLASH_BOOTING_)
  #else
   /*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
   NOR_FLASH,
   RAM,
   UNUSED,
   UNUSED

};
  #endif
  #endif

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/* Non-zero default value for EMI variable, avoid to use ZI for EMIINIT region.
   Note: since not all regions are initialized before EMI init flow,
         the using of EMIINITZI might corrupt data of other region which is still kept at load view
 */

#if (defined(MT6255) || defined(MT6922)) 

#define __EMI_VAL_DEFUALT   0xFFFFFFFF

kal_int32 CMCP_Index = __EMI_DCM_COMBO_INDEX_UND; // Index of the MCP in list
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
   kal_uint32 EMI_DRV_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRV_B_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_ODL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_F_VAL = __EMI_VAL_DEFUALT; 
   kal_uint32 EMI_ODL_G_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONTROL_I_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_J_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_K_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_L_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONTROL_N_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_IODUTY_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IODUTY_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IODUTY_C_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_RXDUTY_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_RXDUTY_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_RXDUTY_E_VAL = __EMI_VAL_DEFUALT;
   
   kal_uint32 EMI_IOMISC_L_VAL = __EMI_VAL_DEFUALT;
#else
  kal_uint32 Sel_NOR_CMD_num = __EMI_VAL_DEFUALT;
   kal_uint32 Sel_PSRAM_CMD_num = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_GENERAL_A_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONA_ASYNC = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONB_ASYNC = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_CONA_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONE_BURST;
   
   kal_uint32 EMI_CONB_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONF_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_IOCM_VAL = __EMI_VAL_DEFUALT;
   
   kal_uint32 EMI_DRVA_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_DRVB_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_ODL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_F_VAL = __EMI_VAL_DEFUALT; 
   kal_uint32 EMI_ODL_G_VAL = __EMI_VAL_DEFUALT;

   // Always BURST
   kal_uint32 EMI_NOR_BURST_OP[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_ADDRESS[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_NOR_BURST_DATA[__EMI_NOR_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};   
#endif
#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */




/* The following information will be used in custom_DynamicClockSwitch() for Combo Memory */
//#if defined(__EMI_COMBO_EN)

kal_uint32 __EMI_DCM_idx = __EMI_DCM_COMBO_INDEX_UND;
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)


#if defined(MT6255)

__align(64*1024) unsigned long EMI_DUMMY_READ_AREA[8] =
{
    0x12345678, 0x87654321, 0x5A5A5A5A, 0xFACEBEAF,
    0x0F0F0F0F, 0xDEADBEAF, 0x25487650, 0x26792679
};


#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

kal_uint32 EMI_DQSA_166M;
kal_uint32 EMI_IDLE_166M;
static kal_uint32 EMI_DQSA_backup_done = 0;

#if defined(__DBG_EVB_CHECK_FAIL)
/**
  * For detecting EVB timing shift's pattern..
  */
int dbg_is_evb_check_fail = 1;
int dbg_tx_wnd[0x10][0x10] = { 1 , 2 , 3 };
int dbg_rx_wnd[95] = { 1 , 2 , 3 };
int count_rw_y[15] = { 1 , 2 , 3 };

int __EMI_CheckTxDelayLevel( void );
void __EMI_RecordRegInitStatus( void );
void __EMI_RecordRegCrashStatus( void );
int __EMI_OutputTxWindow( void );
void _RX_EMI_Tuning_Factor_Set( unsigned int l_i4DqDelay_V );

EMI_DATA_TRAIN_REG_t debug_emi_initial_reg = {1, 2, 3};
EMI_DATA_TRAIN_REG_t debug_emi_crash_reg = {1, 2, 3};
#endif/*__DBG_EVB_CHECK_FAIL*/

#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
EMI_DATA_TRAIN_ERR_INFO_t emi_data_training_err_info = {1, 2, 3};
#endif /*__LOG_DATA_TRAIN_ERROR_INFO*/

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

kal_int8 __EMI_InitializationFlow(void);
int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG);
int __EMI_EnablePerformancePowerControl( void );

#endif /* MT6276 || MT6255*/



/** 
   *  EMI_CONTROL_J_VAL_MCP0 and EMI_CONTROL_L_VAL_MCP0 is defined here AGAIN,
   *  however the following data structure is placed at INTSRAM, but not EMIINIT,
   *  and will be used in Dynamic Clock Switch
   */

#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#if (defined(MT6255) || defined(MT6922))
kal_uint32 EMI_CONTROL_J_166_VAL = EMI_CONTROL_J_VAL_MCP0;
kal_uint32 EMI_CONTROL_K_166_VAL = EMI_CONTROL_K_VAL_MCP0;
kal_uint32 EMI_CONTROL_L_166_VAL = EMI_CONTROL_L_VAL_MCP0;
kal_uint32 EMI_CONTROL_J_13_VAL  = EMI_CONTROL_J_13_VAL_MCP0;
kal_uint32 EMI_CONTROL_K_13_VAL  = EMI_CONTROL_K_13_VAL_MCP0;
kal_uint32 EMI_CONTROL_L_13_VAL  = EMI_CONTROL_L_13_VAL_MCP0;
#endif
#pragma arm section rwdata , rodata , zidata

//#endif /* __EMI_COMBO_EN */

/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

void __EMI_SetEmiPllLowSpeed( void )
{
    volatile int delay;

*PLL_PLL_CON1 &= ~(0x2);

__EMI_DelayLoop(200);

     

}
#endif  //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

void __EMI_SetEmiPllHighSpeed( void )
{
    volatile int delay;
    *PLL_EPLL_CON3 = *PLL_EPLL_CON3 & 0xfffd;
 /**
       * Enable EMIPLL to fast clock
       */
#if defined(__EMI_CLK_200MHZ__)
    *PLL_EPLL_CON2 = (*PLL_EPLL_CON2 & 0xffc0) | 0x1D;// EPLL clock(2X EMI) = 13Mhz x (0x1D+1) = 390
    //*FPLL_CON2 = (*FPLL_CON2 & 0xff80) | 0x1D;
#else
    #if defined(__SERIAL_FLASH_EN__)
    *PLL_EPLL_CON2 = (*PLL_EPLL_CON2 & 0xffc0) | 0x17;
    #else
    *PLL_EPLL_CON2 = (*PLL_EPLL_CON2 & 0xffc0) | 0x18;
    #endif
    
    //*FPLL_CON2 = (*FPLL_CON2 & 0xff80) | 0x18;
#endif

    *PLL_EPLL_CON3 = *PLL_EPLL_CON3 | 0x0007;
    __EMI_DelayLoop(200);
    *PLL_EPLL_CON3 = *PLL_EPLL_CON3 & 0xfffe;
    *PLL_TDMA_FHCON6 = *PLL_TDMA_FHCON6 | 0x0003;

    *PLL_PLL_CON1 |= 0x2;
__EMI_DelayLoop(200);



}

#endif //#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_InitializeLPDDR()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))
    
void __EMI_InitializeLPDDR( void )
{
    
    volatile int i;
    kal_uint32 dram_rank = DRAM_CS;
    
    /**
       * Disable Dummy Read.
       */
    *EMI_DRCT=0x0;

    /* Apply output delay */
  //  *EMI_ODLA=EMI_ODL_A_VAL;
  //  *EMI_ODLB=EMI_ODL_B_VAL;
    *EMI_ODLC=EMI_ODL_C_VAL;
    *EMI_ODLD=EMI_ODL_D_VAL;
    *EMI_ODLE=EMI_ODL_E_VAL;
  //  *EMI_ODLF=EMI_ODL_F_VAL;    // only for LPDDR2, 2x CMD
    *EMI_ODLG=EMI_ODL_G_VAL;
    
    /* Apply IO duty */
    *EMI_DUTA=EMI_IODUTY_A_VAL;
    *EMI_DUTB=EMI_IODUTY_B_VAL;
   // *EMI_DUTC=EMI_IODUTY_C_VAL;

    /* Apply RX duty auto tracking */
    *EMI_DUCA=EMI_RXDUTY_A_VAL;
    *EMI_DUCB=EMI_RXDUTY_B_VAL;
    *EMI_DUCE=EMI_RXDUTY_E_VAL;

    /* Apply IO Misc. Control L */
    *EMI_IOCL=EMI_IOMISC_L_VAL;

    /**
       * Set AC Timing Parameters for according memory device.
       */
    *EMI_CONJ=EMI_CONTROL_J_VAL; 
    *EMI_CONK=EMI_CONTROL_K_VAL;

    *EMI_CONL=EMI_CONTROL_L_VAL;

    *EMI_CONN=EMI_CONTROL_N_VAL;
    
#if defined(__EMI_DEVICE_LPDDR1__)
    /**
       * Set LPDDR device configuration.
       */
    *EMI_CONI=EMI_CONTROL_I_VAL;
#endif
    
    /**
       * Set DRAM rank.
       * We enable DRAM rank, and enable the rest of the rank to be SRAM to prevent SW bug cause EMI hang.
       */
    if(0 == dram_rank)
    {
        *EMI_GEND = 0x0001000E;
    }
    else if(1 == dram_rank)
    {
        *EMI_GEND = 0x0002000D;
    }
    else
    {
        ASSERT(0);
    }
    

    /**
       * Pad swap function mode (configure as DDRI or DDRII/SRAM pad configuration).
            0x2/0x3 : LPDDR
            0x4/0x5 : LPDDR2
       */
    *EMI_IOCL |= 0x03000000;

    /**
       * Delay for a while.
       */    
    __EMI_DelayLoop(0xfff);


    /**
       * Enable external clock (DRAM clk out & HCLKX2_CK).
       */
#if defined(__EMI_DEVICE_LPDDR1__)
    *EMI_GENA |= 0x00000300;
#endif
    /**
       * Remap if necessary.
       */    
    if(0 == dram_rank)
    {
        *EMI_GENA &= (~0xF);
        *EMI_GENA |= 0x0A;
    }
    else if(1 == dram_rank)
    {
        *EMI_GENA &= (~0xF);
        *EMI_GENA |= 0x0B;
    }
    else
    {
        ASSERT(0);
    }

    
    /**
       * EMI Driving, it needs to be set before LPDDR being initialized.
       */    
    *EMI_DRVA = EMI_DRV_A_VAL;
    *EMI_DRVB = EMI_DRV_B_VAL;
    

    /**
       * Delay for a while.
       */    
    __EMI_DelayLoop(0xff);
    
    
    /**
       * LPDDR Initial Flow.
       */
#if defined(__EMI_DEVICE_LPDDR1__)    
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x10000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x08000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x04000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x02000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x01000000;
    __EMI_DelayLoop(0xff);
    *(volatile kal_uint32*)EMI_CONN = EMI_CONTROL_N_VAL | 0x1 |0x00000000; 
    __EMI_DelayLoop(0xff);

#endif  /* __EMI_DEVICE_LPDDR1__ */ 

    /**
       * Enable auto-refresh, fixed-clock (for auto-refresh), and pdn.
       */        
   *EMI_CONN |=  0x00004017;

    __EMI_DelayLoop(0xff);      
}

#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataTrackingMbistTestCore()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))


kal_int32 __EMI_DataTrackingMbistTestCore(kal_int32 algo_sel, kal_int32 addr_scramble_sel, kal_int32 data_scramble_sel)
{
    volatile kal_int32 delay;
    
    /**
       * MBIST reset.
       */
    *EMI_MBISTA = 0x0;

    /**
       * MBIST data-pattern setting.
       */
    *EMI_MBISTB = 0xFFFF0000 | ((0x0000A55A) >> (algo_sel + addr_scramble_sel + data_scramble_sel));

    /**
       * MBIST starting address.
       */
    *EMI_MBISTC = 0x410000>>10;

    /**
       * MBIST ending address.
       */
    *EMI_MBISTD = 0x410000>>10;

    /**
       * ClearBIST address/data scramble and algorithm.
       */
    *EMI_MBISTA &= 0xFFFF000F;


    *EMI_MBISTA |= (0x00220000 | algo_sel<<4 | addr_scramble_sel<<12 | data_scramble_sel<<8 | 1);
    __EMI_DelayLoop(0xff);

    /**
       * Start MBIST test.
       */
    *EMI_MBISTA = *EMI_MBISTA | 2;

    /**
       * Polling the MBIST test finish status.
       */
    while(!(*EMI_MBISTE&0x0002));

    /**
       * Check the MBIST result.
       */
    if(*EMI_MBISTE&0x0001)
    {
        /**
           * addr[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x0 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_addr = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * addr[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x1 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
         emi_data_training_err_info.err_addr |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * wdataL[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x4 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataL= ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * wdataL[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x5 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataL |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * wdataH[47:32]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x6 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataH = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * wdataH[63:48]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x7 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_wdataH |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * rdataL[15:00]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x8 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataL = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * rdataL[31:16]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0x9 << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataL |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * rdataH[47:32]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0xA << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataH = ( *EMI_MBISTE & 0xFFFF0000 ) >> 16;
#endif

        /**
           * rdataH[63:48]
           */
        *EMI_MBISTA = (*EMI_MBISTA & ~((kal_uint32)0xF << 28)) | ((kal_uint32)0xB << 28) ;
#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
        emi_data_training_err_info.err_rdataH |= ( *EMI_MBISTE & 0xFFFF0000 );
#endif

        /**
           * MBIST reset.
           */
        *EMI_MBISTA = 0x0;
        
        return -1;
    }
    else
    {
        /**
           * MBIST reset.
           */
        *EMI_MBISTA = 0x0;

        return 0;
    }
}
    
#endif // #if defined(MT6255) || defined(MT6922)
  
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

kal_int32 __EMI_DataAutoTrackingMbistTest(void)
{
    kal_int32 algo_sel, data_scramble_sel;
    // kal_int32 addr_scramble_sel;
    kal_uint32 EMI_DRCT_bakval;

    /**
       * Backup dummy read control. 
       */
    EMI_DRCT_bakval = *EMI_DRCT;

    /**
       * Disable dummy read before testing MBIST (must). 
       */
    *EMI_DRCT &= ~(0xD);
        
    for(algo_sel=0; algo_sel<3; algo_sel++)
    {
        for(data_scramble_sel=0; data_scramble_sel<7; data_scramble_sel++)
        {
            if( __EMI_DataTrackingMbistTestCore( algo_sel, 0x0, data_scramble_sel ) != 0 )
            {
                /**
                    * Restore dummy read control. 
                    */
                *EMI_DRCT = EMI_DRCT_bakval;
                return -1;
            }
        }
    }

    /**
        * Restore dummy read control. 
        */
   *EMI_DRCT = EMI_DRCT_bakval;
 
    return 0;
}


#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

void __EMI_DataAutoTrackingRegRead( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        pREG->EMI_DLLV_regval = *EMI_DLLV;
        pREG->EMI_DQSV_regval = *EMI_DQSV;
        pREG->EMI_CONN_regval = *EMI_CONN;        
        pREG->EMI_DQSB_regval = *EMI_DQSB;
        pREG->EMI_DQSE_regval = *EMI_DQSE;        
        pREG->EMI_IDLE_regval = *EMI_IDLE;
        pREG->EMI_IDLF_regval = *EMI_IDLF;
        pREG->EMI_IDLG_regval = *EMI_IDLG;
        pREG->EMI_IDLH_regval = *EMI_IDLH;
        pREG->EMI_IDLI_regval = *EMI_IDLI;        
        pREG->EMI_CALB_regval = *EMI_CALB;
        pREG->EMI_CALF_regval = *EMI_CALF;
        pREG->EMI_CALJ_regval = *EMI_CALJ;
        pREG->EMI_CALP_regval = *EMI_CALP;
    }    
    else
    {
        ASSERT(0);
    }
}


#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

/*static*/ void __EmiDataTrainRegWrite( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        *EMI_CONN = pREG->EMI_CONN_regval;                
        *EMI_DQSB = pREG->EMI_DQSB_regval;
        *EMI_DQSE = pREG->EMI_DQSE_regval;
        *EMI_IDLE = pREG->EMI_IDLE_regval;
        *EMI_IDLF = pREG->EMI_IDLF_regval;
        *EMI_IDLG = pREG->EMI_IDLG_regval;
        *EMI_IDLH = pREG->EMI_IDLH_regval;
        *EMI_IDLI = pREG->EMI_IDLI_regval;
        *EMI_CALB = pREG->EMI_CALB_regval;
        *EMI_CALF = pREG->EMI_CALF_regval;
        *EMI_CALJ = pREG->EMI_CALJ_regval;
        *EMI_CALP = pREG->EMI_CALP_regval;
    }
    
}
    

#endif //#if defined(MT6255) || defined(MT6922)
    
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

int __EMI_DataAutoTrackingTraining( EMI_DATA_TRAIN_REG_t* pResult )
{    
#define ___EMIDATATRAIN_MBIST_DATATRAIN__
#define DEBUG_MODE 0

    kal_int32 value;
    kal_int32 bytex_dly_mod, bytex_setup_mod, dqy_in_del, dqsix_dlysel;
    kal_int32 bytex_dly_mod_start = 0, bytex_setup_mod_start = 0, dqy_in_del_start = 0;// dqsix_dlysel_start = 0;
    kal_int32 prev_emi_dqsa = 0;
    kal_int32 prev_emi_idl, prev_emi_cala, prev_emi_cale, prev_emi_cali;
    kal_int32 prev_dwnd_size = 0, dwnd_size;// lbound, rbound;
    kal_int32 lbound_finding;
  
    kal_uint32 DQSI_center = 0x0, DQSI_start = 0x00, DQSI_end = 0xFF; //Use to record the DQSI start and end value
    
    kal_int32 test_result;
    kal_int32 DATA_TUNING_STEP = 2;
    kal_int32 DQSI_TUNING_STEP = 4;    
    kal_int32 WINDOW_SIZE_THRESHOLD = 6;
    kal_int32 DQSI_TUNING_WINDOW_SIZE_THRESHOLD = 10;

    int b_wnd_found = 0;
    EMI_DATA_TRAIN_REG_t REG_BAK;
    prev_emi_cali = 0;
    prev_emi_cala = 0;
    prev_emi_cale = 0;
    prev_emi_idl = 0;

    /*------------------------------------------------------------------------------
        Backup modified register at entry
      ------------------------------------------------------------------------------*/
    __EMI_DataAutoTrackingRegRead( &REG_BAK );
    

    /* Make sure the CAL_EN is disabled */
    *EMI_CONN &= ~(0x00000100); //Disable CAL_EN    

    /*------------------------------------------------------------------------------
        Disable 
            1. "Data auto tracking" & "Setup/Hold max value"
            2. "1/5T DLL" 
            3. "Mask auto-tracking"
            before data training
      ------------------------------------------------------------------------------*/
    *EMI_CALP &= ~0xFFFF0003;
    *EMI_DQSE &= ~0xFFFF;
           
    for(dqsix_dlysel=0x0; dqsix_dlysel<=0x7F; dqsix_dlysel+=DQSI_TUNING_STEP/* 8 */)
    {        
        #ifdef RTC_DEBUG
            dbg_print("DQSB = 0x%x\n\r", dqsix_dlysel);
        #endif 
        /*Mask Auto Tracking Init Value*/
        /*rank 2,3 are useless, need to train??*/
        //*EMI_DQSA = dqsix_dlysel<<24 | dqsix_dlysel<<16 | dqsix_dlysel<<8 | dqsix_dlysel;
        *EMI_DQSB = dqsix_dlysel<<24 | dqsix_dlysel<<16 | dqsix_dlysel<<8 | dqsix_dlysel;
        lbound_finding = 1;

        /*byte_delay = 0*/
        bytex_dly_mod = 0;
        *EMI_IDLI = 0;

        /*byte_setup = 0*/
        bytex_setup_mod = 0;
        *EMI_CALF = 0;
        //*EMI_CALE = 0;

        /*Reset CALA/CALI*/
        *EMI_CALB = 0;
        //*EMI_CALA = 0;
        *EMI_CALJ = 0;
        //*EMI_CALI = 0;

        /*Iterate dq_in delay 0x1F ~ 0*/
        for(dqy_in_del=0x1F; dqy_in_del>=0; dqy_in_del-=DATA_TUNING_STEP)
        {
            *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH =
            dqy_in_del<<24 | dqy_in_del<<16 | dqy_in_del<<8 | dqy_in_del;

            // Clear DDRFIFO
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /* do DQS calibration */
#if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
            #else
                store_8word(&datatraing_cmp_pattern, 0x12345678);
                test_result = load_8word(&datatraing_cmp_pattern, 0x12345678);
            #endif


            
            /* R/W ok & during boundary finding ==> 0->1 , Record the start boundary*/
            if(lbound_finding==1 && test_result == 0)
            {

                #if DEBUG_MODE
                dbg_print("Find L Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                #endif
                dqy_in_del_start = dqy_in_del;
                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                
                lbound_finding = 0;

            }
            /* R/W fail & not during boundary finding ==> 1->0 */
            else if(lbound_finding==0 && test_result != 0 )
            {
                /* handle 0001011111111111111......*/
                dwnd_size = (dqy_in_del_start-dqy_in_del)+(bytex_setup_mod-bytex_setup_mod_start)+(bytex_dly_mod-bytex_dly_mod_start);
                if (dwnd_size <= DATA_TUNING_STEP)  //ignore this window, continue find window
                {
                    lbound_finding = 1;            
                }
                else
                {
                    #if DEBUG_MODE
                    dbg_print("Find R Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                    #endif
               
                goto window_found;
            }            
        }
        }

        dqy_in_del = 0; /*This value should be already be 0*/
        *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = 0;
                
        for(bytex_setup_mod=0; bytex_setup_mod<=0x1F; bytex_setup_mod+=DATA_TUNING_STEP)
        {                       
            /*rank 2,3 are useless, need to train??*/
            *EMI_CALF = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;
            //*EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

            // Clear DDRFIFO
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /* do DQS calibration */
            #if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
            #else
                store_8word(&datatraing_cmp_pattern, 0x12345678);
                test_result = load_8word(&datatraing_cmp_pattern, 0x12345678);
            #endif

            if(lbound_finding==1 && test_result == 0 )
            {
                #if DEBUG_MODE
                dbg_print("Find L Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                #endif

                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                dqy_in_del_start = dqy_in_del;

                lbound_finding = 0;

            }
            else if(lbound_finding==0 && test_result != 0 )
            {
                /* handle 0001011111111111111......*/
                dwnd_size = (dqy_in_del_start-dqy_in_del)+(bytex_setup_mod-bytex_setup_mod_start)+(bytex_dly_mod-bytex_dly_mod_start);
                if (dwnd_size <= DATA_TUNING_STEP)  //ignore this window, continue find window
                {
                    lbound_finding = 1;            
                }
                else
                {
                    #if DEBUG_MODE
                    dbg_print("Find R Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                    #endif
               
                goto window_found;
            }
        }
        }
        bytex_setup_mod=0x1F; /*This value should be already be 0x1F*/
        /*rank 2,3 are useless, need to train??*/
        *EMI_CALF = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;
        //*EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

        for(bytex_dly_mod=0; bytex_dly_mod<=0x1F; bytex_dly_mod+=DATA_TUNING_STEP)
        {
            //*EMI_CALA = bytex_dly_mod<<24 | bytex_dly_mod<<16 | bytex_dly_mod<<8 | bytex_dly_mod;
            *EMI_IDLI = bytex_dly_mod<<24 | bytex_dly_mod<<16 | bytex_dly_mod<<8 | bytex_dly_mod;

            // Clear DDRFIFO
            *EMI_CALP |= 0x00000100;
            *EMI_CALP &= 0xFFFFFEFF;

            /* do DQS calibration */
            #if defined( ___EMIDATATRAIN_MBIST_DATATRAIN__ )
            test_result = __EMI_DataAutoTrackingMbistTest();
            #else
                store_8word(&datatraing_cmp_pattern, 0x12345678);
                test_result = load_8word(&datatraing_cmp_pattern, 0x12345678);
            #endif


            if(lbound_finding==1 && test_result == 0 )
            {

                #if DEBUG_MODE
                dbg_print("Find L Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                #endif
            
                bytex_dly_mod_start = bytex_dly_mod;
                bytex_setup_mod_start = bytex_setup_mod;
                dqy_in_del_start = dqy_in_del;

                lbound_finding = 0;

            }
            else if(lbound_finding==0 && test_result != 0 )
            {
                /* handle 0001011111111111111......*/
                dwnd_size = (dqy_in_del_start-dqy_in_del)+(bytex_setup_mod-bytex_setup_mod_start)+(bytex_dly_mod-bytex_dly_mod_start);
                if (dwnd_size <= DATA_TUNING_STEP)  //ignore this window, continue find window
                {
                    lbound_finding = 1;            
            }
                else
                {
                    #if DEBUG_MODE
                    dbg_print("Find R Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
                    #endif

                goto window_found;
            }
            }
    }

    
        /*Find a windows that only have one-end boundary,ex. 000111111...*/
        if(lbound_finding == 0)
        {
            #if DEBUG_MODE
            dbg_print("Find R Bound (0x%x, 0x%x, 0x%x)\n\r", dqy_in_del, bytex_dly_mod, bytex_setup_mod);
            #endif        
        
            goto window_found;
        }


        /*window is not found, but previous windows found, it's also a shrink case, goto windows_found*/
        /*In this case, found a window size = 0 , ex. 00000000... */
        if( ( lbound_finding == 1 ) && ( b_wnd_found == 1 ) )
        {
            if (DQSI_end == 0xff) DQSI_end = dqsix_dlysel-DQSI_TUNING_STEP;//IvanTseng: record the last DQSI value
            
            *EMI_DQSB = prev_emi_dqsa;
            //*EMI_DQSA = prev_emi_dqsa;
            
            *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl;
            *EMI_CALB = prev_emi_cala;
            *EMI_CALF = prev_emi_cale;
            *EMI_CALJ = prev_emi_cali;
            //*EMI_CALA = prev_emi_cala;
            //*EMI_CALE = prev_emi_cale;
            //*EMI_CALI = prev_emi_cali;

            #if DEBUG_MODE
                dbg_print("(N/A) Window size = %d, DQSI=0x%x\n\r", dwnd_size, dqsix_dlysel);
        continue;
            #else
                break;
            #endif
}

        /*window is not found, use next mask setting*/
        continue;

    window_found:

        if(bytex_dly_mod>0x1F)
        {
            // This is an unexpected case
            bytex_dly_mod = 0x1F;
        }

        if(bytex_setup_mod>0x1F)
        {
            // This is an unexpected case
            bytex_setup_mod = 0x1F;
        }

        if(dqy_in_del<0)
        {
            // This is an unexpected case       
            dqy_in_del = 0;
        }

        if(dqsix_dlysel>0x7F)
        {
            // This is an unexpected case
            dqsix_dlysel = 0x7F;
        }

        dwnd_size = (dqy_in_del_start-dqy_in_del)+(bytex_setup_mod-bytex_setup_mod_start)+(bytex_dly_mod-bytex_dly_mod_start);


        /*If windows <= 10, ignore this windows found,maybe it's a noise because MBIST is not reliable */
        if( dwnd_size <= DQSI_TUNING_WINDOW_SIZE_THRESHOLD )
        {
            #if DEBUG_MODE
                dbg_print("(SMALL) Window size = %d, DQSI=0x%x\n\r", dwnd_size, dqsix_dlysel);
            #endif            
            continue;
        }
        else 
        {
            b_wnd_found = 1; //it means the DQSI is found
            
            #if DEBUG_MODE
                dbg_print("Window size = %d, DQSI=0x%x\n\r", dwnd_size, dqsix_dlysel);
            #endif
        }

                
        if (DQSI_start==0x0) DQSI_start = dqsix_dlysel; //Record the 1st DQSI value

        /* Stop tuning when the prev_dwnd_size is greater than current window size */
        if(prev_dwnd_size && (prev_dwnd_size > (dwnd_size+WINDOW_SIZE_THRESHOLD)))
        {
             DQSI_end = dqsix_dlysel-DQSI_TUNING_STEP;//IvanTseng: record the last DQSI value
            
            *EMI_DQSB = prev_emi_dqsa;
           
            
            *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl;
            *EMI_CALB = prev_emi_cala;
            *EMI_CALF = prev_emi_cale;
            *EMI_CALJ = prev_emi_cali;
            
            
            /*------------------------------------------------------------------------------
                Once find a windows less or equal previous one, use:
                    1. Previous delay setting
                    2. current mask setting ( in case the previous one is in mask boundary ) and finish data training.
              ------------------------------------------------------------------------------*/
            #if DEBUG_MODE
                dbg_print("(ESCAPE) Window size = %d, DQSI=0x%x\n\r", dwnd_size, dqsix_dlysel);
                continue;
            #else
            break;
            #endif            
        }

        prev_dwnd_size = dwnd_size;

        /*Use only for a "valid windows size" shrink to "zero windows size" immmediately.*/
        prev_emi_dqsa = *EMI_DQSB;
        
        /*Align "DQS riging" & "data out"*/
        //value = (dqy_in_del_start > (dwnd_size/2)) ? (dqy_in_del_start-dwnd_size/2) : 0;
        //value<<24 | value<<16 | value<<8 | value;
        *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl =        
        dqy_in_del_start<<24 | dqy_in_del_start <<16 | dqy_in_del_start <<8 | dqy_in_del_start;

        /*Byte Data Delay*/
        value = (bytex_setup_mod_start+(dwnd_size/2))>31? (bytex_setup_mod_start+(dwnd_size/2))-31:0;
        //value = (bytex_setup_mod_start+(dwnd_size/2))<31? (bytex_setup_mod_start+(dwnd_size/2)):31; //CLS
        /*rank 2,3 are useless, need to train??*/
        *EMI_CALB = prev_emi_cala = value<<24 | value<<16 | value<<8 | value;

        /*Byte Data Setup*/
        value = (bytex_setup_mod_start+(dwnd_size/2))<31? (bytex_setup_mod_start+(dwnd_size/2)):31;
        //value = (bytex_setup_mod_start+(dwnd_size/2))>31? (bytex_setup_mod_start+(dwnd_size/2))-31:0; //CLS      
        *EMI_CALF = prev_emi_cale = (value<<24 | value<<16 | value<<8 | value);

        /*byte Data Hold*/
        value = ( dwnd_size/2 > 31 ) ? 31 : dwnd_size/2;
        *EMI_CALJ = prev_emi_cali = value<<24 | value<<16 | value<<8 | value; 

        /*Go next mask setting*/
        
    }

    /* IvanTseng : Get the proper DQSI value here */
    DQSI_center = (DQSI_start + DQSI_end)/2;
    *EMI_DQSB = DQSI_center<<24 | DQSI_center<<16 | DQSI_center<<8 | DQSI_center;
    #if DEBUG_MODE
        dbg_print("We choose DQSI = 0x%x, (0x%x, 0x%x)\n\r\n\r", DQSI_center, DQSI_start, DQSI_end);
    #endif

    /*------------------------------------------------------------------------------
        Set up MAX "Data Setup" & " Data Hold"
      ------------------------------------------------------------------------------*/
    *EMI_IDLI = 0; //If we do not enable DATA_CAL_EN, we must clear IDLI because IDLI delay will take effetc when DATA_CAL_EN is disabled.
    
    /* Enable auto data tracking*/
    value = ((prev_dwnd_size/2) > 0x1f) ? 0x1f : (prev_dwnd_size/2);
    *EMI_CALP &= 0x0000FFFF;
    *EMI_CALP |= ( 1 << 31 ) | ( value << 24) | ( 1 << 23 ) | ( value << 16 );

    /* Make sure the CAL_EN is ENABLED */
    //*EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL

     /* After enabling CAL_EN, wait for an auto refresh interval around 7.8 us is required. 
        The calibration value from DLL circuit can be applied on delay line. Then EMI can work normally. 
       */
     //for(delay=0;delay<0xfff;delay++);

     /*------------------------------------------------------------------------------
         Return Training Result and Restore Register
       ------------------------------------------------------------------------------*/
     __EMI_DataAutoTrackingRegRead( pResult );      /*Return Training Result*/
     __EmiDataTrainRegWrite( &REG_BAK );    /*Restore Register*/

     __EMI_DataAutoTrackingRegRead( &REG_BAK ); //Test

     
    return  b_wnd_found;
    
}

#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_setEMI_MT6276()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#if (defined(MT6255) || defined(MT6922))

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 __EMI_InitializationFlow(void)
{
    int ret = 1;

    EMI_DATA_TRAIN_REG_t    DATA_TRAIN_RESULT_REG;

    /*********
      *
      * Set EMI low speed before initial LPDDR.
      * This is special for LPDDR2.
      *
      ********/

    __EMI_SetEmiPllLowSpeed();


    /*********
      *
      * Initial LPDDR.
      *
      ********/

    __EMI_InitializeLPDDR();


    /*********
      *
      * Restore EMI Pll to high speed before data tracking tuning.
      *
      ********/

    __EMI_SetEmiPllHighSpeed();


    /*********
      *
      * Data training.
      *
      ********/

    ret = __EMI_EnableDataAutoTracking(&DATA_TRAIN_RESULT_REG);


    /*********
      *
      * Enable performance/power related module.      
      *
      ********/

    __EMI_EnablePerformancePowerControl();


    /*********
      *
      * Enable bandwidth limiter.
      *
      ********/
   
    __EMI_EnableBandwidthLimiter();



#if defined(__DBG_EVB_CHECK_FAIL)    
    /*********
      *
      * Detect EMI timing shift.
      *
      ********/

    dbg_is_evb_check_fail = __EMI_CheckTxDelayLevel();        

    /*********
      *
      * Record EMI register value after initialization.
      *
      ********/

    __EMI_RecordRegInitStatus();
#endif // __DBG_EVB_CHECK_FAIL

    return ret;    
}

#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_EnableDataAutoTracking()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))
 
int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG)
{
    int ret = 1;

    
    if( __EMI_DataAutoTrackingTraining(DATA_TRAIN_RESULT_REG ) == 0 )
    {
        /**
           * Data training fail. 
           */
        ret = 0; 
    }

    /**
       * Mask auto tracking initial value. 
       */
    *EMI_DQSB = DATA_TRAIN_RESULT_REG->EMI_DQSB_regval;   

#if defined(__EMI_DATA_AUTO_TRACKING_ENABLE)
   
    /**
        * Data Auto Tracking init value. 
        */
    *EMI_CALB = DATA_TRAIN_RESULT_REG->EMI_CALA_regval;     
    *EMI_CALF = DATA_TRAIN_RESULT_REG->EMI_CALE_regval;
    *EMI_CALJ = DATA_TRAIN_RESULT_REG->EMI_CALI_regval;    
    *EMI_CALP = DATA_TRAIN_RESULT_REG->EMI_CALP_regval;         

    /**
        * Enable auto data tracking. 
        */
    *EMI_CALP |= 0x1;                                       
    
#else
    
    /**
       * DQ-in delay. 
       */
    *EMI_IDLE = DATA_TRAIN_RESULT_REG->EMI_IDLE_regval;
    *EMI_IDLF = DATA_TRAIN_RESULT_REG->EMI_IDLF_regval;
    *EMI_IDLG = DATA_TRAIN_RESULT_REG->EMI_IDLG_regval;
    *EMI_IDLH = DATA_TRAIN_RESULT_REG->EMI_IDLH_regval;

    /** 
        * Enable 1/5 PLL. 
        */
    *EMI_CONN |= 0x00000100;    
        
    /**
       * Add new timing delay to meet new EMI timing constrain that after enabling 1/5 DLL.
       */
    __EMI_DelayLoop(0xfff);
        
#endif // __EMI_DATA_AUTO_TRACKING_ENABLE

    /** 
        * Setup HW EMI calibration for sleep mode resume.
        */
    *EMI_DQSE |= 0x1000FFFF;
               
    /**
       * Enable Dummy Read 
       */
#if defined(__SIP_RAM_SIZE__)
*(volatile kal_uint32*)EMI_DRCT=0x80007009;
#else
 *(volatile kal_uint32*)EMI_DRCT=0x8000F001;
#endif
  

    return ret;    
}


#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */






/*************************************************************************
* FUNCTION
*  __EMI_EnablePerformancePowerControl()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))
 
int __EMI_EnablePerformancePowerControl( void )
{
    /**
       * Setup Precharge & PDN delay 
       */
    *(volatile kal_uint32*)EMI_PPCT=0xFFFF0000;

    /** 
        * Disable all HI prio and enable R/W command flavor.
        */
#if (defined(MT6255) || defined(MT6922))
    // Disable RW_FAVOR_M1 for MM 
    *(volatile kal_uint32*)EMI_SLCT=0x00000000;
#else
    *(volatile kal_uint32*)EMI_SLCT=0x0000001F;
#endif

    /**
        * Setup 1/16 freq for HWDCM mode and enable arbitration controls 
        */ 
    *(volatile kal_uint32*)EMI_ABCT=0x00070010;

    __EMI_DelayLoop(100);

    return 0;    
}


#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_OutputTxWindow()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

#if defined(__DBG_EVB_CHECK_FAIL) 
int __EMI_OutputTxWindow( void )
{
    int tx_X_delay_level;
    int tx_Y_delay_level;
    int rx_X_delay_level;
    int rx_Y_delay_level;

    dbg_print("\n\r");
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0xF ;  tx_Y_delay_level++ )
    {
        for( tx_X_delay_level=0 ; tx_X_delay_level <= 0xF ;  tx_X_delay_level++ )
        {
            dbg_print("%d ",dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level]);
        }
        dbg_print("\n\r");
    }
    dbg_print("\n\r");

    for(rx_X_delay_level = 0 ; rx_X_delay_level < 95 ; rx_X_delay_level++ ){
        dbg_print("%d ",dbg_rx_wnd[rx_X_delay_level]);
    }
    dbg_print("\n\r");
    if( dbg_is_evb_check_fail == 1 )
    {
        dbg_print("[ERROR]:EVB EMI Timing Check FAIL!\n\n");
    } else
    {
        dbg_print("EVB EMI Timing Check Pass!\n\n");
    }

    return 0;    
}
#endif /*__DBG_EVB_CHECK_FAIL*/

#endif // #if defined(MT6255)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */




/*************************************************************************
* FUNCTION
*  __ARM_TimingWindow()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */



#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



/*************************************************************************
* FUNCTION
*  __EMI_CheckTxDelayLevel()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

#if defined(__DBG_EVB_CHECK_FAIL)
int __EMI_CheckTxDelayLevel( void )
{
    /**
        * Default 0 is PASS.
        */
    int result = 0; 
    int tx_X_delay_level;
    int tx_Y_delay_level;
    int rx_X_delay_level;
    int rx_Y_delay_level;
    unsigned long regbak_ODLA, regbak_ODLB, regbak_ODLC, regbak_ODLD; 
    unsigned long regbak_ODLE, regbak_ODLG;

    /**
        * Backup register.
        */
   // regbak_ODLA = *EMI_ODLA;
   // regbak_ODLB = *EMI_ODLB;
    regbak_ODLC = *EMI_ODLC;
    regbak_ODLD = *EMI_ODLD;
    regbak_ODLE = *EMI_ODLE;
    regbak_ODLG = *EMI_ODLG;
     
    /**
        * Check TX Delay Level.
        */
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0xF ;  tx_Y_delay_level++ )
    {        
      //  *EMI_ODLA = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
      //  *EMI_ODLB = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLC = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);
        *EMI_ODLD = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);

        /**
           * Factor3 - DQM_OUT_DEL.
           * Clear DQM_OUT_DEL first
           */
        *EMI_ODLE &= ~0xFFFF0000; 
        *EMI_ODLE |= ((tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16));
        
        
        for( tx_X_delay_level=0 ; tx_X_delay_level <= 0xF ;  tx_X_delay_level++ )
        {
            /**
               * Factor4 - DQS_OUT_DEL.
               * Clear DQS_OUT_DEL first
               */
            *EMI_ODLE &= ~0x0000FFFF;
            *EMI_ODLE |= ((tx_X_delay_level <<12) | (tx_X_delay_level <<8) |(tx_X_delay_level <<4) |(tx_X_delay_level <<0));

            /**
               * Factor5 - EDCLK_OUT_DEL.
               */
            *EMI_ODLG &= ~0x0000000F;
            *EMI_ODLG |= tx_X_delay_level;

            if( __EMI_DataAutoTrackingMbistTest() != 0 )
            {
                if( tx_X_delay_level == 0x9 ) 
                {
                    /**
                        * Test fail.
                        */
                    result = 1; 
                }
                dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level] = 0;
            } else
            {
                dbg_tx_wnd[tx_X_delay_level][tx_Y_delay_level] = 1;
            }
        }
    }

    
     /**
        * Check RX Delay Level.
        */
   
    
    for( tx_Y_delay_level=0 ; tx_Y_delay_level <= 0x6 ;  tx_Y_delay_level++ )
    {        
      //  *EMI_ODLA = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
      //  *EMI_ODLB = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);        
        *EMI_ODLC = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);
        *EMI_ODLD = (tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16) | (tx_Y_delay_level <<12) | (tx_Y_delay_level <<8) |(tx_Y_delay_level <<4) |(tx_Y_delay_level);

        /**
           * Factor3 - DQM_OUT_DEL.
           * Clear DQM_OUT_DEL first
           */
        *EMI_ODLE &= ~0xFFFF0000; 
        *EMI_ODLE |= ((tx_Y_delay_level <<28) | (tx_Y_delay_level <<24) |(tx_Y_delay_level <<20) |(tx_Y_delay_level <<16));
        
        for( tx_X_delay_level=0x0 ; tx_X_delay_level <= 0x6 ;  tx_X_delay_level++ )
        {
            /**
               * Factor4 - DQS_OUT_DEL.
               * Clear DQS_OUT_DEL first
               */
            *EMI_ODLE &= ~0x0000FFFF;
            *EMI_ODLE |= ((tx_X_delay_level <<12) | (tx_X_delay_level <<8) |(tx_X_delay_level <<4) |(tx_X_delay_level <<0));

            /**
               * Factor5 - EDCLK_OUT_DEL.
               */
            *EMI_ODLG &= ~0x0000000F;
            *EMI_ODLG |= tx_X_delay_level;
            for(rx_X_delay_level = 0 ; rx_X_delay_level < 95 ; rx_X_delay_level++ ){
                 _RX_EMI_Tuning_Factor_Set(rx_X_delay_level);
            if( __EMI_DataAutoTrackingMbistTest() != 0 )
             {
                dbg_rx_wnd[rx_X_delay_level] = 0;
             }
             else
              {
                dbg_rx_wnd[rx_X_delay_level] = 1;
                      count_rw_y[rx_Y_delay_level] += 1; 
              }
                      
                     
                  }
          
          }    
    }
    
       
    /**
        * Restore register.
        */
 //   *EMI_ODLA = regbak_ODLA;
 //   *EMI_ODLB = regbak_ODLB;
    *EMI_ODLC = regbak_ODLC;
    *EMI_ODLD = regbak_ODLD;
    *EMI_ODLE = regbak_ODLE;
    *EMI_ODLG = regbak_ODLG;

    return result;        
}
#endif // __DBG_EVB_CHECK_FAIL

#endif //#if defined(MT6255) || defined(MT6922)
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
/*************************************************************************
* FUNCTION
*  _RX_EMI_Tuning_Factor_Set()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if defined(__DBG_EVB_CHECK_FAIL)
void _RX_EMI_Tuning_Factor_Set( unsigned int l_i4DqDelay_V )
{
    unsigned long regbak_IDLA, regbak_IDLB, regbak_IDLC, regbak_IDLD; 
    unsigned long regbak_IDLE, regbak_IDLF, regbak_IDLG, regbak_IDLH, regbak_IDLI;
    unsigned long regbak_CALE, regbak_CALF, regbak_CALG, regbak_CALH;
    /**
        * Backup register.
        */
    regbak_IDLE = *EMI_IDLE;
    regbak_IDLF = *EMI_IDLF;
    regbak_IDLG = *EMI_IDLG;
    regbak_IDLH = *EMI_IDLH;
    regbak_IDLI = *EMI_IDLI;
    regbak_CALE = *EMI_CALE;
    regbak_CALF = *EMI_CALF;
    //Factor4 -DQ_IN_DEL, BYTE_DATA_SETUP and BYTE_DATA_DLYSEL
    if (l_i4DqDelay_V <= __DQIDLY_BOUNDARY)
    {
        //Factor4 -DQ_IN_DEL            
        l_i4DqDelay_V = (__DQIDLY_BOUNDARY - l_i4DqDelay_V); //Tuning sequence = 0x1f ~ 0x0
        *EMI_IDLE = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLF = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLG = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
        *EMI_IDLH = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V <<16) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;        

        //Factor4 - BYTE_DATA_SETUP
        *EMI_CALE = 0; 
        *EMI_CALF = 0; 
    
        //Factor4 - BYTE_DATA_DLY      
        *EMI_IDLI = 0;
    
    }
    else if (l_i4DqDelay_V <= (__DQIDLY_BOUNDARY*2+1))
    {            
        //Factor4 - BYTE_DATA_SETUP
        l_i4DqDelay_V -= (__DQIDLY_BOUNDARY+1); //Tuning sequence = 0x0 ~ 0x1f            
        *EMI_CALE= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_CALF= (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) |(l_i4DqDelay_V <<8) | l_i4DqDelay_V;        
 
    }
    else
    {
        //Factor4 - BYTE_DATA_DLY            
        l_i4DqDelay_V -= (__DQIDLY_BOUNDARY+1)*2; //Tuning sequence = 0x0 ~ 0x1f
        /* Mark Lin : please change to set DQSx_INDLY_SEL */
        *EMI_CALA = (l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_CALB = (l_i4DqDelay_V <<8) | l_i4DqDelay_V; 
        *EMI_IDLI = (l_i4DqDelay_V <<24) | (l_i4DqDelay_V << 16 ) | (l_i4DqDelay_V <<8) | l_i4DqDelay_V;
    }
    
    /**
        * Restore register.
        */
    *EMI_IDLE = regbak_IDLE;
    *EMI_IDLF = regbak_IDLF;
    *EMI_IDLG = regbak_IDLG;
    *EMI_IDLH = regbak_IDLH;
    *EMI_IDLI = regbak_IDLI;
    *EMI_CALE = regbak_CALE;
    *EMI_CALF = regbak_CALF;

}
#endif // __DBG_EVB_CHECK_FAIL

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_RecordRegInitStatus()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

#if defined(__DBG_EVB_CHECK_FAIL)
void __EMI_RecordRegInitStatus( void )
{
    __EMI_DataAutoTrackingRegRead( &debug_emi_initial_reg );
}
#endif

#endif //#if defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_RecordRegCrashStatus()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))

#if defined(__DBG_EVB_CHECK_FAIL)
void __EMI_RecordRegCrashStatus( void )
{
    __EMI_DataAutoTrackingRegRead( &debug_emi_crash_reg );
}
#endif

#endif //#if defined(MT6255)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



#endif /*(_NAND_FLASH_BOOTING_) || (__SIP_RAM_SIZE__)*/

/*************************************************************************
* FUNCTION
*  __EMI_SetRegValfromCMCP()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/



#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

void __EMI_SetRegValfromCMCP(void)
{
	 kal_uint32 i;
   MTK_EMI_Info *mem_info;

   mem_info = (MTK_EMI_Info *)&EMI_INFO_2.mem_info[CMCP_Index];

#if (defined(MT6255) || defined(MT6922))
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
   EMI_DRV_A_VAL = mem_info->EMI_DRVA_value;
   EMI_DRV_B_VAL = mem_info->EMI_DRVB_value;

   EMI_ODL_A_VAL = mem_info->EMI_ODLA_value;
   EMI_ODL_B_VAL = mem_info->EMI_ODLB_value;
   EMI_ODL_C_VAL = mem_info->EMI_ODLC_value;
   EMI_ODL_D_VAL = mem_info->EMI_ODLD_value;
   EMI_ODL_E_VAL = mem_info->EMI_ODLE_value;
   EMI_ODL_F_VAL = mem_info->EMI_ODLF_value;
   EMI_ODL_G_VAL = mem_info->EMI_ODLG_value;

   EMI_CONTROL_I_VAL = mem_info->EMI_CONI_value;
   EMI_CONTROL_J_VAL = mem_info->EMI_CONJ_value;
   EMI_CONTROL_K_VAL = mem_info->EMI_CONK_value;
   EMI_CONTROL_L_VAL = mem_info->EMI_CONL_value;
   EMI_CONTROL_N_VAL = mem_info->EMI_CONN_value;

   EMI_IODUTY_A_VAL = mem_info->EMI_DUTA_value;
   EMI_IODUTY_B_VAL = mem_info->EMI_DUTB_value;
   EMI_IODUTY_C_VAL = mem_info->EMI_DUTC_value;

   EMI_RXDUTY_A_VAL = mem_info->EMI_DUCA_value;
   EMI_RXDUTY_B_VAL = mem_info->EMI_DUCB_value;
   EMI_RXDUTY_E_VAL = mem_info->EMI_DUCE_value;
   
   EMI_IOMISC_L_VAL = mem_info->EMI_IOCL_value;
#else
    EMI_GENERAL_A_VAL = mem_info->EMI_GENA_value;
   
   EMI_CONA_ASYNC = mem_info->EMI_CONA_ASYNC_value;
   EMI_CONB_ASYNC = mem_info->EMI_CONB_ASYNC_value;

   EMI_CONA_BURST = mem_info->EMI_CONA_BURST_value;
   EMI_CONE_BURST = mem_info->EMI_CONE_BURST_value;
   
   EMI_CONB_BURST = mem_info->EMI_CONB_BURST_value;
   EMI_CONF_BURST = mem_info->EMI_CONF_BURST_value;

   EMI_IOCM_VAL = mem_info->EMI_IOCM_value;
   
  EMI_DRVA_VAL = mem_info->EMI_DRVA_value;
  EMI_DRVB_VAL = mem_info->EMI_DRVB_value;

   EMI_ODL_A_VAL = mem_info->EMI_ODLA_value;
   EMI_ODL_B_VAL = mem_info->EMI_ODLB_value;
   EMI_ODL_C_VAL = mem_info->EMI_ODLC_value;
   EMI_ODL_D_VAL = mem_info->EMI_ODLD_value;
   EMI_ODL_E_VAL = mem_info->EMI_ODLE_value;
   EMI_ODL_F_VAL = mem_info->EMI_ODLF_value;
   EMI_ODL_G_VAL = mem_info->EMI_ODLG_value;

   // Always BURST
   Sel_NOR_CMD_num = mem_info->EMI_NOR_CMD_num;
   
   for (i=0; i<Sel_NOR_CMD_num; i++) {
      EMI_NOR_BURST_OP[i] = mem_info->EMI_NOR_CMD_OP[i];
      EMI_NOR_BURST_ADDRESS[i] = mem_info->EMI_NOR_CMD_ADDR[i];
      EMI_NOR_BURST_DATA[i] = mem_info->EMI_NOR_CMD_DATA[i];
   }
   
   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_BURST_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_BURST_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_BURST_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }
#endif   
#endif //#if defined(MT6255)

   return;

}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */







/*************************************************************************
* FUNCTION
*  custom_setEMI()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 custom_setEMI(void)
{
	//kal_int32 index_offset;
  kal_int32 index_efuse;
  kal_int32 efuse;
  
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
   efuse = *EMI_EFUSE;

  index_efuse    = ((efuse >> 4) & 0x7);
  //index_offset   =  EMI_two_complement(index_efuse, 3);
  
	#if defined(__EMI_COMBO_EN)
   CMCP_Index = CMEM_EMIINIT_Index();
   #else
   CMCP_Index = index_efuse;
#endif
   __EMI_SetRegValfromCMCP();
   EMI_Read_EF();
  return 0;

#else
        *EMI_GENA |= 0x2;
        efuse = *EMI_EFUSE;

  index_efuse    = ((efuse >> 4) & 0x7);
  //index_offset   =  EMI_two_complement(index_efuse, 3);
  
	#if defined(__EMI_COMBO_EN)
   CMCP_Index = CMEM_EMIINIT_Index();
   #else
   CMCP_Index = index_efuse;
#endif
   __EMI_SetRegValfromCMCP();
   EMI_Read_EF();
     // __EMI_SetRegValfromCMCP();
       if ( EMI_CSConfiguration[0] != UNUSED )
   {
      *(EMI_CONA) = EMI_SettingOnCS[0];

      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * we should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
#if (defined(MT6255) || defined(MT6922))
      *EMI_CONE |= 0x00000400;
#endif /* MT6255 || MT6922*/
   }

   if ( EMI_CSConfiguration[1] != UNUSED )
   {
      *(EMI_CONB) = EMI_SettingOnCS[1];

      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * we should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
#if (defined(MT6255) || defined(MT6922))
      *EMI_CONF |= 0x00000400;
#endif /* MT6255 || MT6922*/
   }

   //*EMI_GEND  = EMI_GENERAL_D_VAL;
   *EMI_GENA = EMI_GENERAL_A_VAL;
 
    return 1;
#endif

   

}


#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  custom_InitDRAM()
*
* DESCRIPTION
*   This routine aims to set EMI and initialize LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

/**
  * On SRAM configuration, the custom_InitDRAM() will not be used.
  */

kal_int8 custom_InitDRAM(void)
{
   return -1;

}

/*************************************************************************
* FUNCTION
*  custom_ifLPSDRAM()
*
* DESCRIPTION
*  Query if the memory device is LPSDRAM
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: The memory device is LPSDRAM
*  KAL_FALSE: The memory device is not LPSDRAM
*
* GLOBALS AFFECTED
*
*************************************************************************/

//#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */

kal_bool
custom_ifLPSDRAM(void)
{
#if defined(DRAM_CS)
   return KAL_TRUE;
#else /* DRAM_CS */
   return KAL_FALSE;
#endif /* DRAM_CS */
}

//#endif //#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))



/*************************************************************************
* FUNCTION
*  custom_setAdvEMI()
*
* DESCRIPTION
*   This routine aims to set additional EMI
*   This is special for device which needs to set device configuration
*   register to turn-on special mode.
*
* PARAMETERS
*
* RETURNS
*  1:
*
* GLOBALS AFFECTED
*
*************************************************************************/

/**
  * On SRAM configuration, the old EMI init flow will perform Sync/Page EMI initialization at INTSRAM_ROCODE section, while 
  * the new EMI init flow will perform this flow at EMIINITCODE section.
  */
//#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 custom_setAdvEMI(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
   kal_int8    status = 0;
    kal_uint32   DRAM_Enable = DRAM_CS;
   volatile kal_uint32   delay;

/**
  *   Call CMEM_EMIINIT_Index to get the index
  */



   /* Add a delay loop for MT6235 to prevent modify EMI reg while EMI serving a request (pre-fetch). */
   for(delay=0; delay<255; delay++);

   if ( (DRAM_Enable != 0xFF) && (DRAM_Enable < 4) )
   {
      /* remapping if DRAM at CS1 */
      if ( DRAM_Enable == 1 )
      {
#if (defined(MT6255) || defined(MT6922))
         *EMI_GENA   &= 0xFFFFFFFC;
         *EMI_GENA   |= 0x3;

         /**
            * we assume customers only use one CS as their DRAM.
            */
         *EMI_GEND   &= 0xFFF0FFF0;
         *EMI_GEND   |= 0x0002000D;
#else
         *EMI_REMAP = 3;
#endif
      }
      else if ( DRAM_Enable == 0 )
      {
#if (defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6276) || defined(MT6256))
         /**
            * we assume DRAM at CS0.
            */
         *EMI_GENA   &= 0xFFFFFFFC;
         *EMI_GENA   |= 0x2;   

         /**
            * we assume customers only use one CS as their DRAM.
            */
         *EMI_GEND   &= 0xFFF0FFF0;
         *EMI_GEND   |= 0x0001000E;
#endif
      }
      else
      {
         /**
            * we do not support customers use those CS other than CS0 and CS1 as their booting regions.
            */
         ASSERT(0);
      }

#if (defined(MT6255) || defined(MT6922))

    __EMI_InitializationFlow();

#endif //#if defined(MT6276) || defined(MT6256) 

      return 1;
   }
   else
   {
      /**
         * trap directly.
         */
      ASSERT(0);
   }
#else
   kal_int8    status = 0;
   kal_int8    i;
	kal_int32	delay = 0xf;
	//volatile unsigned short *ptr16;
	unsigned short data;
	//kal_uint32 saved_cache_con, saved_prefetch_con;

	  /**
      * On ARM9 system, the core will perform pre-fetch in the background, we add a delay loop to prevent modify EMI reg 
      * while EMI serving a request (pre-fetch). 
      */
    for (delay=0; delay <0xff; delay++);


     /**
        * Setting EMI general control register and cache/prefetch size if necessary.
        */
        *EMI_GENA = EMI_GENERAL_A_VAL;

       /**
      * Switch NOR-Flash RCR into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
   /* ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_1);
    *ptr16 = EMI_NOR_BURST_DATA_1;
    for (delay=0; delay <0x0f; delay++);
    ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_2);
    *ptr16 = EMI_NOR_BURST_DATA_2;
    for (delay=0; delay <0x0f; delay++);
    ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_3);
    *ptr16 = EMI_NOR_BURST_DATA_3;
    for (delay=0; delay <0x0f; delay++);
    ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_4);
    *ptr16 = EMI_NOR_BURST_DATA_4;
    for (delay=0; delay <0x0f; delay++);
    ptr16 = (volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS_5);
    *ptr16 = EMI_NOR_BURST_DATA_5;
    for (delay=0; delay <0xff; delay++);*/
     for (i=0;i<Sel_NOR_CMD_num; i++) 
    {
        if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
        	  data = *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]);
        } else if (EMI_NOR_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(FLASH_BASE_ADDR | EMI_NOR_BURST_ADDRESS[i]) = EMI_NOR_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }

    /**
      * Switch PSRAM configuration (BCR/RCR) into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
   /* data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_1);
    for (delay=0; delay <0x0f; delay++);
    data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_2);
    for (delay=0; delay <0x0f; delay++);
    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_3) = EMI_PSRAM_BURST_DATA_3;
    for (delay=0; delay <0x0f; delay++);
    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_4) = EMI_PSRAM_BURST_DATA_4;
    for (delay=0; delay <0x0f; delay++);
    data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_5);
    for (delay=0; delay <0x0f; delay++);
    data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_6);
    for (delay=0; delay <0x0f; delay++);
    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_7) = EMI_PSRAM_BURST_DATA_7;
    for (delay=0; delay <0x0f; delay++);
    *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS_8) = EMI_PSRAM_BURST_DATA_8;
    for (delay=0; delay <0xff; delay++);*/

     for (i=0;i<Sel_PSRAM_CMD_num; i++) 
    {
        if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_RD) {
        	  data = *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]);
        } else if (EMI_PSRAM_BURST_OP[i] == MEM_CMD_OP_16BIT_WR) {
            *(volatile unsigned short *)(RAM_BASE_ADDR | EMI_PSRAM_BURST_ADDRESS[i]) = EMI_PSRAM_BURST_DATA[i];
        }
        for (delay=0; delay <0x0f; delay++) {
            #if defined(__RVCT__) && defined(__MTK_TARGET__)
            __nop()
            #endif
            ;
        }
    }
    for (delay=0; delay <0xff; delay++) {
        #if defined(__RVCT__) && defined(__MTK_TARGET__)
        __nop()
        #endif
        ;
    }
	  /**
          * Switch the EMI register into corresponding modes.
          */    	
        *EMI_CONA = EMI_CONA_BURST; 
        *EMI_CONE = EMI_CONE_BURST; 
        for (delay=0; delay <0xff; delay++);   
        *EMI_CONB = EMI_CONB_BURST; 
        *EMI_CONF = EMI_CONF_BURST;
        for (delay=0; delay <0xff; delay++);    	
    	
        /**
          * set SCLK_EN, SCLK_SEL(center-aligned for write)
          */
        //*EMI_GENA |= 0x00000C00;
        *EMI_GENA |= 0x00000C09;        /* ZW: Do REMAPPING HERE!! */
        for (delay=0; delay <0xff; delay++);

        /**
          * enable feedback clock
          */     
        *EMI_IOCL |= 0x00000400;       
        *EMI_IOCM= EMI_IOCM_VAL;
        for (delay=0; delay <0xff; delay++);           

        /**
          * set driving & delay 
          */
        *EMI_DRVA= EMI_DRVA_VAL;//EMI_DRV_A_VAL_MCP0;//drva
        *EMI_DRVB= EMI_DRVB_VAL;//EMI_DRV_B_VAL_MCP0;//drvb

		  /**
      * set EMI arbitrator:
      * 1. MCU EMI BW: 34%, soft mode.
      * 2. layer2 BUS EMI BW: 28.49%, soft mode.
      * 3. MCU EMI BW: 34%, soft mode.
      * 4. GMC1 EMI BW: 16.98%, soft mode.
      * 5. GMC2 EMI BW: 16.01%, soft mode.
      */
      __EMI_EnableBandwidthLimiter();
   // *EMI_ARBA = 0x0000582C;
   // *EMI_ARBB = 0x00005022;
   // *EMI_ARBC = 0x0000502C;
   // *EMI_ARBD = 0x00005015;
   // *EMI_ARBE = 0x00005014;

#endif
   return status;
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  custom_EMI_QueryFullSpeedClock()
*
* DESCRIPTION
*   This routine query EMI's full-speed clock rate (instead of the clock rate at query time).
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/




emi_clock_enum custom_EMI_QueryFullSpeedClock( void )
{
    /**
       * This function is only available after EMI is fully initialized, and we must not call this function at EMI init time since the code has not been initialized yet.
       */
    emi_clock_enum cur_emi_clk_rate = EMI_CLK_UNKNOWN;

#if (defined(MT6255) || defined(MT6922))

#if defined(__EMI_CLK_166MHZ__)
    cur_emi_clk_rate = EMI_CLK_166MHZ;
#elif defined(__EMI_CLK_200MHZ__) /* __EMI_CLK_166MHZ__ */
    cur_emi_clk_rate = EMI_CLK_200MHZ;
#elif defined(__EMI_CLK_156MHZ__) /* __EMI_CLK_166MHZ__ */
    cur_emi_clk_rate = EMI_CLK_156MHZ;
#else
    cur_emi_clk_rate = EMI_CLK_104MHZ;
#endif /* __EMI_CLK_166MHZ__ */

#endif //#if defined(MT6255) || defined(MT6922)

    return cur_emi_clk_rate;
}






/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_size()
*
* DESCRIPTION
*  Return predefined external SRAM size.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/



void
custom_get_EXTSRAM_size(kal_uint32 *size)
{
   *size = (kal_uint32)EMI_EXTSRAM_SIZE;
}





/*************************************************************************
* FUNCTION
*  custom_DynamicClockSwitch
*
* DESCRIPTION
*  This function dedicates to switch the system clock and adjust the EMI
*  according to the working system clock.
*
* PARAMETERS
*  clock    -    clock to switch
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/



#if defined(DCM_ENABLE) || defined(FEATURE_DCM_SSC)


#if defined(FEATURE_DCM_SSC)
#pragma arm section zidata="INTSRAM_ZI", rwdata="INTSRAM_RW"
#if defined( DCM_ENABLE )
static unsigned int SSC_DCM_Handle = 0xFFFFFFFF;
#endif /* DCM_ENABLE */
#pragma arm section zidata, rwdata
#endif /* FEATURE_DCM_SSC */

#pragma arm section code = "INTSRAM_ROCODE"

int custom_DynamicClockSwitch(mcu_clock_enum clock)
{

  // register kal_uint32 delay;

#if defined(FEATURE_DCM_SSC)
   unsigned int interruptMask;

#if defined( DCM_ENABLE )
   if(SSC_DCM_Handle==0xFFFFFFFF)
   {
       SSC_DCM_Handle = (unsigned int)DCM_GetHandle();
   }
#endif /* DCM_ENABLE */

#endif /* FEATURE_DCM_SSC */

#if (defined(MT6255) || defined(MT6922))
custom_SFIDynamicClockSwitch(clock);
custom_EMIDynamicClockSwitch(clock);   
#endif //#if defined(MT6255) || defined(MT6922)

   /* unsupported MCU clock */
   return -1;

 
}

#pragma arm section code

#pragma arm section code = "INTSRAM_ROCODE"

int custom_EMIDynamicClockSwitch(mcu_clock_enum clock)
{
	 
    register kal_uint32 delay;
	  #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
	     if (0 == EMI_DQSA_backup_done)
    {
        EMI_DQSA_166M = *EMI_DQSB;
        EMI_IDLE_166M = *EMI_IDLE;
        EMI_DQSA_backup_done = 1;

       
    }
    #endif
	    if (clock == MCU_26MHZ) {

        /*
         * ZW: It's a special mode for Low Power Audio, we'll switch EMI to 26MHz. 
         */
        
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

		/* block emi access */
        *EMI_CONM |= 0x001F;  
         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x2; //Disable DATA_CAL_EN0

        /* Make sure the CAL_EN is DISABLED */
        *EMI_CONN &= ~(0x00000100); //Disable CAL_EN, 1/5T DLL, Add by IvanTseng

         /* Disable DQSI auto tune when going from full speed to 26MHz */
        *EMI_DQSE &= ~(0x10000033);        /* Suggest by Fumin */

        /* poll the emi idle status */
        do {
            if ((*EMI_CONN) & 0x00000400) {
                break;
            }
        } while (1);

        /* enter SDRAM self-refresh mode */
        *EMI_CONN |= 0x00000020;
        do {
            if ((*EMI_CONN) & 0x00000080) {
                break;
            }
        } while (1);		
		/*------------------*/		
        #endif
         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Switch the EMI setting for 1x 13MHz */  //below setting from Fumin
        *EMI_CONJ = EMI_CONTROL_J_13_VAL;
        *EMI_CONK = EMI_CONTROL_K_13_VAL;
        *EMI_CONL = EMI_CONTROL_L_13_VAL;

        
        *EMI_DQSA = 0x00000808;
        *EMI_DQSB = 0x00000808;
        *EMI_DQSE = 0x00000000;

        #endif
        /* Set SW DCM mode */
        *EMI_ABCT |= 0x50; 

        //*PLL_CON6 = 0xF000; //enable dcm, div set
        //for(delay=0; delay<0x10; delay++); //wait switch, Remove by IvanTseng
        /* Switch EMI to 26MHz */
        *PLL_PLL_CON1 &= ~(0x0002); 
        
        for(delay = 0; delay<0xFF; delay++);

         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Enable DQSI auto tune */
        //*EMI_DQSE |= 0x10000003;

        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

         /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng
        
        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;

        #endif
				for(delay = 0; delay<0xFF; delay++);

				
        /* resume emi access */
        *EMI_CONM &= ~0x001F;

         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        #endif
        return 0;
   }else if (clock == MCU_416MHZ) {
        /*
         * ZW: It's a special mode for Low Power Audio, we'll switch EMI back to full speed
         */
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

        /* block emi access */
        *EMI_CONM |= 0x001F;
        
        #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x2; //Disable DATA_CAL_EN0

        /* Make sure the CAL_EN is DISABLED */
        *EMI_CONN &= ~(0x00000100); //Disable CAL_EN, 1/5T DLL, Add by IvanTseng

        /* Disable DQSI auto tune */
        *EMI_DQSE &= ~(0x10000033);        /* Suggest by Fumin */

        /* poll the emi idle status */
         do {
            if ((*EMI_CONN) & 0x00000400) {
                break;
            }
        } while (1);
        
        /* enter SDRAM self-refresh mode */
        *EMI_CONN |= 0x00000020;
        do {
            if ((*EMI_CONN) & 0x00000080) {
                break;
            }
        } while (1);		
        /*------------------*/	
        #endif
        //*PLL_CON1 &= ~0xC000; //SWDCM mode: clear HWDIV_MODE & HWDCM_MODE
        /* Switch EMI to EPLL */
        *PLL_CON1 |= (0x0002); 
        
        //for(delay = 0; delay<0xFF; delay++); //Remove by IvanTseng

         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Apply DDR 333 settings */
        *EMI_CONJ = EMI_CONTROL_J_166_VAL;
        *EMI_CONK = EMI_CONTROL_K_166_VAL;
        *EMI_CONL = EMI_CONTROL_L_166_VAL;
        
        *EMI_DQSA = EMI_DQSA_166M;
        *EMI_DQSB = EMI_DQSA_166M;

         /**
         * DQ-in delay. 
         */
        
         *EMI_IDLE = EMI_IDLE_166M;
         *EMI_IDLF = EMI_IDLE_166M;
         *EMI_IDLG = EMI_IDLE_166M;
         *EMI_IDLH = EMI_IDLE_166M;

        //*EMI_DQSE = 0x10000033;

        /* Enable DQSI auto tune and DQSI_DCM_AUTO_TUNE_EN (for self-refresh) */
        /* After exit DRAM self-refresh, send mass dummy read to auto-tune */
        *EMI_DQSE |= 0x10000033;    /* Suggested by Fumin */
        #endif
        /* Don't set SW DCM mode */
        *EMI_ABCT &= ~0x50; 
         
         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__) 
        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

        /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng

        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;
        
        #endif
        
        for(delay = 0; delay<0x4FF; delay++);
        
        /* resume emi access */
        *EMI_CONM &= ~0x001F;

         #if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        #endif
        
        return 0;
      }
  // #endif /*(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)*/
   return 0;
}

#pragma arm section code
#endif  /* DCM_ENABLE */



/*************************************************************************
* FUNCTION
*  custom_EMIDynamicClockSwitch_Init
*
* DESCRIPTION
*  This function is used to Init setting for DCM
*
* PARAMETERS
*
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/



int custom_EMIDynamicClockSwitch_Init(void)
{

#if defined(DCM_ENABLE) || defined(FEATURE_DCM_SSC)
#if defined(__SIP_RAM_SIZE__)
	kal_int32 index_offset;
  kal_int32 index_efuse;
  kal_int32 efuse;
   efuse = *EMI_EFUSE;

  index_efuse    = ((efuse >> 4) & 0x7);
      EMI_CONTROL_J_166_VAL = __EMI_DCM_control[index_efuse].EMI_CONJ_value;
      EMI_CONTROL_K_166_VAL = __EMI_DCM_control[index_efuse].EMI_CONK_value;
      EMI_CONTROL_L_166_VAL = __EMI_DCM_control[index_efuse].EMI_CONL_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[index_efuse].EMI_CONJ_13_value;
      EMI_CONTROL_K_13_VAL = __EMI_DCM_control[index_efuse].EMI_CONK_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[index_efuse].EMI_CONL_13_value;
  

#endif
#if defined(__EMI_COMBO_EN)
   if (__EMI_DCM_idx == __EMI_DCM_COMBO_INDEX_UND) 
   {  
      // We only query at the first time
      __EMI_DCM_idx = CMEM_Index();
   
#if defined(MT6256) 
      EMI_CONTROL_J_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_K_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_value;
      EMI_CONTROL_L_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_13_value;
      EMI_CONTROL_K_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_13_value;
#elif (defined(MT6255) || defined(MT6922))
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
       EMI_CONTROL_J_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_K_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_value;
      EMI_CONTROL_L_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_13_value;
      EMI_CONTROL_K_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_13_value;
#endif  
#endif  

   } 
   else
   { 
      ASSERT(0); // This init function should only be called once
   }
#endif /* __EMI_COMBO_EN */

#endif /* DCM_ENABLE || FEATURE_DCM_SSC */

    return 0;
}
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */


void EMI_Read_EF(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
   kal_int32 DQ_offset,CLK_offset,DQS_offset,OD_DQ_offset,OD_DQS_offset,MEM_DRV_offset;
   kal_int32 DQ_efuse,CLK_efuse,DQS_efuse,OD_DQ_efuse,OD_DQS_efuse,MEM_DRV_efuse;
   kal_int32 IO_DRV_DQ, IO_DRV_DQS, IO_DRV_CLK, OD_DQ, OD_DQS, MEM_DRV;
   kal_int32 efuse;
   //kal_int32 index_efuse, index_offset;
   efuse = *EMI_EFUSE;
   
   

  //index_efuse    = ((efuse >> 4) & 0x7);
  //index_offset   =  EMI_two_complement(index_efuse, 3); 
   	
		DQ_efuse       = ((efuse >> 7) & 0x7);
		CLK_efuse      = ((efuse >> 10) & 0x7);
		DQS_efuse      = ((efuse >> 13) & 0x7);
		OD_DQ_efuse    = ((efuse >> 16) & 0x7);
		OD_DQS_efuse   = ((efuse >> 19) & 0x7);
		MEM_DRV_efuse  = ((efuse >> 22) & 0x3);
	//	dbg_print("efuse index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_efuse,DQ_efuse,CLK_efuse,DQS_efuse,OD_DQ_efuse,OD_DQS_efuse,MEM_DRV_efuse);

    
    DQ_offset         =  EMI_two_complement(DQ_efuse, 3);
    CLK_offset        =  EMI_two_complement(CLK_efuse, 3); 
    DQS_offset        =  EMI_two_complement(DQS_efuse, 3); 
    OD_DQ_offset      =  EMI_two_complement(OD_DQ_efuse, 3); 
    OD_DQS_offset     =  EMI_two_complement(OD_DQS_efuse, 3); 
    MEM_DRV_offset    =  EMI_two_complement(MEM_DRV_efuse, 2); 
  //  dbg_print("offset index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,DQ_offset,CLK_offset,DQS_offset,OD_DQ_offset,OD_DQS_offset,MEM_DRV_offset);
    
    IO_DRV_DQ = (EMI_DRV_A_VAL & 0xF);
    IO_DRV_DQS = (EMI_DRV_A_VAL & 0xF);
    IO_DRV_CLK = ((EMI_DRV_B_VAL >> 16) & 0xF);
    OD_DQ = (EMI_ODL_D_VAL & 0xF);
    OD_DQS = (EMI_ODL_E_VAL & 0xF);
    MEM_DRV = (EMI_CONTROL_I_VAL >> 5) & 0x7;
    
 //   dbg_print("DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*calculate drv DQ result*/
    IO_DRV_DQ = IO_DRV_DQ + DQ_offset;
    if(IO_DRV_DQ > 15)
    {
    	IO_DRV_DQ = 15;
    }
    else if(IO_DRV_DQ <= 0)
{
  	IO_DRV_DQ = 0;
    }
    else
    {
    	
    } 
    
    /*calculate drv DQS result*/
    IO_DRV_DQS = IO_DRV_DQS + DQS_offset; 
     if(IO_DRV_DQS > 15)
    {
    	IO_DRV_DQS = 15;
    }
    else if(IO_DRV_DQS <= 0)
    {
    	IO_DRV_DQS = 0;
    }
    else
    {
    	
    } 
    
    /*calculate drv CLK result*/
    IO_DRV_CLK = IO_DRV_CLK + CLK_offset;
     if(IO_DRV_CLK > 15)
    {
    	IO_DRV_CLK = 15;
    }
    else if(IO_DRV_CLK <= 0)
    {
    	IO_DRV_CLK = 0;
    }
    else
    {
    	
    } 
    
    /*calculate output delay DQ result*/
    OD_DQ = OD_DQ + OD_DQ_offset;
     if(OD_DQ > 15)
    {
    	OD_DQ = 15;
    }
    else if(OD_DQ <= 0)
    {
    	OD_DQ = 0;
    }
    else
    {
    	
    } 
    
     /*calculate output delay DQS result*/
    OD_DQS = OD_DQS + OD_DQS_offset;
     if(OD_DQS > 15)
    {
    	OD_DQS = 15;
    }
    else if(OD_DQS <= 0)
    {
    	OD_DQS = 0;
    }
    else
    {
    	
    } 
    
     /*calculate memory driving result*/
    MEM_DRV = MEM_DRV + MEM_DRV_offset;
     if(MEM_DRV > 7)
    {
    	MEM_DRV = 7;
    }
    else if(MEM_DRV <= 0)
    {
    	MEM_DRV = 0;
    }
    else
    {
    	
    }     
    
  //  dbg_print("finally result index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*finally result*/
    EMI_DRV_A_VAL &= 0x00000000;
    EMI_DRV_A_VAL = (IO_DRV_DQ << 28) | (IO_DRV_DQ << 24) | (IO_DRV_DQS << 20) | (IO_DRV_DQS << 16) | (IO_DRV_DQ << 4) | (IO_DRV_DQ << 0);
    
    EMI_DRV_B_VAL &= 0x00000000;
    EMI_DRV_B_VAL = (IO_DRV_CLK << 20) | (IO_DRV_CLK << 16);
    
    EMI_ODL_C_VAL &= 0x00000000;
    EMI_ODL_C_VAL = (OD_DQ << 28) | (OD_DQ << 24) | (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQ << 12) | (OD_DQ << 8) | (OD_DQ << 4) | (OD_DQ << 0); 
    
    EMI_ODL_D_VAL &= 0x00000000;
    EMI_ODL_D_VAL = (OD_DQ << 28) | (OD_DQ << 24) | (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQ << 12) | (OD_DQ << 8) | (OD_DQ << 4) | (OD_DQ << 0); 
    
    EMI_ODL_E_VAL &= 0x00000000;
    EMI_ODL_E_VAL = (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQS << 4) | (OD_DQS << 0);
    
    EMI_ODL_G_VAL &= 0x00000000;
    EMI_ODL_G_VAL = (OD_DQ << 8) | (OD_DQS << 0);
     
    EMI_CONTROL_I_VAL &= 0xFFFFFF1F;
    EMI_CONTROL_I_VAL |= (MEM_DRV << 5);  
    
    //EMI_DRV_A_VAL = 0x7FFFFFF0;
    
  //  dbg_print("drva : %x drvb : %x odlc : %x odld : %x odle : %x odlg : %x coni : %x\n", EMI_DRV_A_VAL,EMI_DRV_B_VAL,EMI_ODL_C_VAL,EMI_ODL_D_VAL,EMI_ODL_E_VAL,EMI_ODL_G_VAL,EMI_CONTROL_I_VAL); 
  #else
    kal_int32 DQ_offset,CLK_offset,RDPR_offset,OD_DQ_offset,OD_DQS_offset;//MEM_DRV_offset;
   kal_int32 DQ_efuse,CLK_efuse,RDPR_efuse,OD_DQ_efuse,OD_DQS_efuse;//MEM_DRV_efuse;
   kal_int32 IO_DRV_DQ, IO_DRV_CLK, OD_DQ, OD_DQS, RDPR_Value;
   kal_int32 efuse;
   //kal_int32 index_efuse, index_offset;
   efuse = *EMI_EFUSE;
   
   

  //index_efuse    = ((efuse >> 4) & 0x7);
  //index_offset   =  EMI_two_complement(index_efuse, 3); 
   	
		DQ_efuse       = ((efuse >> 7) & 0x7);
		CLK_efuse      = ((efuse >> 10) & 0x7);
		//DQS_efuse      = ((efuse >> 13) & 0x7);
		OD_DQ_efuse    = ((efuse >> 16) & 0x7);
		OD_DQS_efuse   = ((efuse >> 19) & 0x7);
	//	MEM_DRV_efuse  = ((efuse >> 22) & 0x3);
		RDPR_efuse     = ((efuse >> 24) & 0x3);
	//	dbg_print("efuse index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_efuse,DQ_efuse,CLK_efuse,DQS_efuse,OD_DQ_efuse,OD_DQS_efuse,MEM_DRV_efuse);

    
    DQ_offset         =  EMI_two_complement(DQ_efuse, 3);
    CLK_offset        =  EMI_two_complement(CLK_efuse, 3); 
    //DQS_offset        =  EMI_two_complement(DQS_efuse, 3); 
    OD_DQ_offset      =  EMI_two_complement(OD_DQ_efuse, 3); 
    OD_DQS_offset     =  EMI_two_complement(OD_DQS_efuse, 3); 
   // MEM_DRV_offset    =  EMI_two_complement(MEM_DRV_efuse, 2);
    RDPR_offset       =  EMI_two_complement(RDPR_efuse   , 2);  
   // dbg_print("offset index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,DQ_offset,CLK_offset,DQS_offset,OD_DQ_offset,OD_DQS_offset,MEM_DRV_offset);
    
    IO_DRV_DQ  = (EMI_DRVA_VAL & 0xF);
    IO_DRV_CLK = ((EMI_DRVB_VAL >> 16) & 0xF);
    OD_DQ = (EMI_ODL_D_VAL & 0xF);
    OD_DQS = (EMI_ODL_E_VAL & 0xF);
  //  MEM_DRV = (EMI_CONTROL_I_VAL >> 5) & 0x7;
    RDPR_Value = (EMI_IOCM_VAL >> 16) & 0x3;
    
  //  dbg_print("DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*calculate drv DQ result*/
    IO_DRV_DQ = IO_DRV_DQ + DQ_offset;
    if(IO_DRV_DQ > 15)
    {
    	IO_DRV_DQ = 15;
    }
    else if(IO_DRV_DQ <= 0)
    {
    	IO_DRV_DQ = 0;
    }
    else
   	{

    } 
  
    
    /*calculate drv CLK result*/
    IO_DRV_CLK = IO_DRV_CLK + CLK_offset;
     if(IO_DRV_CLK > 15)
    {
    	IO_DRV_CLK = 15;
    }
    else if(IO_DRV_CLK <= 0)
    {
    	IO_DRV_CLK = 0;
    }
    else
    {
    	
    } 
    
    /*calculate output delay DQ result*/
    OD_DQ = OD_DQ + OD_DQ_offset;
     if(OD_DQ > 15)
    {
    	OD_DQ = 15;
    }
    else if(OD_DQ <= 0)
    {
    	OD_DQ = 0;
    }
    else
    {
    	
    } 
    
     /*calculate output delay DQS result*/
    OD_DQS = OD_DQS + OD_DQS_offset;
     if(OD_DQS > 15)
    {
    	OD_DQS = 15;
    }
    else if(OD_DQS <= 0)
    {
    	OD_DQS = 0;
    }
    else
    {
    	
    } 
    
    
     /*calculate read delay point reset result*/
    RDPR_Value = RDPR_Value + RDPR_offset;
     if(RDPR_Value > 3)
    {
    	RDPR_Value = 3;
    }
    else if(RDPR_Value <= 0)
    {
    	RDPR_Value = 0;
    }
    else
    {
    	
    }     
  //  dbg_print("finally result index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*finally result*/
    EMI_DRVA_VAL  &= 0x00000000;
    EMI_DRVA_VAL  = (IO_DRV_DQ << 28) | (IO_DRV_DQ << 24) |  (IO_DRV_DQ << 4) | (IO_DRV_DQ << 0);
    
    EMI_DRVB_VAL &= 0x00000000;
    EMI_DRVB_VAL = (IO_DRV_CLK << 20) | (IO_DRV_CLK << 16);
    
    EMI_ODL_C_VAL &= 0x00000000;
    EMI_ODL_C_VAL = (OD_DQ << 28) | (OD_DQ << 24) | (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQ << 12) | (OD_DQ << 8) | (OD_DQ << 4) | (OD_DQ << 0); 
    
    EMI_ODL_D_VAL &= 0x00000000;
    EMI_ODL_D_VAL = (OD_DQ << 28) | (OD_DQ << 24) | (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQ << 12) | (OD_DQ << 8) | (OD_DQ << 4) | (OD_DQ << 0); 
    
    EMI_ODL_E_VAL &= 0x00000000;
    EMI_ODL_E_VAL = (OD_DQ << 20) | (OD_DQ << 16) | (OD_DQS << 4) | (OD_DQS << 0);
    
    EMI_ODL_G_VAL &= 0x00000000;
    EMI_ODL_G_VAL = (OD_DQ << 8) | (OD_DQS << 0);
     
    EMI_IOCM_VAL &= 0xFFFCFFFF;
    EMI_IOCM_VAL |= (RDPR_Value << 5);  
 #endif
}
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
kal_int32 EMI_two_complement(kal_int32 offset, int bit_count)
{
	  int value;
   	if(bit_count == 2)
   	{
   		if(offset >= 2)
   		{
   			  value = offset - 2*2;
   		    return value;
   		}
   		else
   		{
   			   value = offset;
   		     return value;
   		}
   		
   	}
   	else if (bit_count == 3)
   	{
   		if(offset > 3)
   		{
   			  value = offset - 2*2*2;
   		    return value;
   		}
   		else
   		{
   			  value = offset;
   		    return value;
   		}
   		
   	}
   	else
   	{
   		ASSERT(0);
   	}
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_EnableBandwidthLimiter()
*
* DESCRIPTION
*   This routine aims to set EMI
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
/**
  * M0: ARM11             24.2%, hard
  * M1: MM SYS            46.8%, hard
  * M2: DMA                2.3%, soft
  * M3: MD2G + Peri SYS    7.0%, soft
  * M4: DSP                7.8%, hard
  * M5: Graphic           11.7%, hard
  *
  */
#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
#if defined(__EMI_CLK_166MHZ__)
#define EMI_ARB_A_VAL                           0x0000541D   // ARM I port, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x0000501D   // ARM D port
#define EMI_ARB_C_VAL                           0x00005014   // perl, DMA, 
#define EMI_ARB_D_VAL                           0x00001000   // NULL
#define EMI_ARB_E_VAL                           0x0000504F   // MM
//#define EMI_ARB_F_VAL                           0x0000100F   // Graphic, soft mode, sm_gnt_cnt=0
#else
#define EMI_ARB_A_VAL                           0x0000541B   // ARM I port, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x0000501B   // ARM D port
#define EMI_ARB_C_VAL                           0x00005012   // perl, DMA, 
#define EMI_ARB_D_VAL                           0x00001000   // NULL
#define EMI_ARB_E_VAL                           0x00005053   // MM
//#define EMI_ARB_F_VAL                           0x0000100F   // Graphic, soft mode, sm_gnt_cnt=0
#endif //defined(__EMI_CLK_166MHZ__)
#else
#if defined(MT6922)
#define EMI_ARB_A_VAL                           0x0000544F   // ARM I port, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x0000504F   // ARM D port
#define EMI_ARB_C_VAL                           0x00005014   // perl, DMA, 
#define EMI_ARB_D_VAL                           0x00001000   // NULL
#define EMI_ARB_E_VAL                           0x0000501D   // MM
#else
#define EMI_ARB_A_VAL                           0x0000542F   // ARM I port, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x0000502F   // ARM D port
#define EMI_ARB_C_VAL                           0x00005014   // perl, DMA, 
#define EMI_ARB_D_VAL                           0x00001000   // NULL
#define EMI_ARB_E_VAL                           0x0000503D   // MM
#endif
#endif

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

#if (defined(MT6255) || defined(MT6922))
 
int __EMI_EnableBandwidthLimiter( void )
{

     /* Set ARM I port BW*/
    *EMI_ARBA = EMI_ARB_A_VAL;

    /* Set ARM D port BW */
    *EMI_ARBB = EMI_ARB_B_VAL;

    /* Set DMA BW */
    *EMI_ARBC = EMI_ARB_C_VAL;

    /* NULL */
    *EMI_ARBD = EMI_ARB_D_VAL;

    /* Set MM sys BW */
    *EMI_ARBE = EMI_ARB_E_VAL;

    /* Set graphic BW */
//    *EMI_ARBF = EMI_ARB_F_VAL;
    // do nothing
  

    return 0;

}


#endif //#if  defined(MT6255) || defined(MT6922)

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
//#endif /* !__FUE__ && !__UBL__ */

#endif //#if defined(MT6256) && defined(__MTK_TARGET__)

