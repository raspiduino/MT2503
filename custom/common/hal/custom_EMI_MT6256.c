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
 *   custom_EMI_MT6256.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(MT6256) && defined(__MTK_TARGET__)

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "reg_base.h"
#include "emi_hw.h"
#include "init.h"
#include "pll.h"
#include "MemoryDevice_TypeDef.h"
#include "custom_emi.h"
#include "config_hw.h"
#include "cache_hw_int.h"

#include "custom_EMI_release.h"

#include "dcm.h"

/** 
  *     CMEM_EMIINIT_Index() is defined in "combo_flash_init.h"
  *     it should be included at autoGen for Combo Memory !!
  *
  */
#include "combo_flash_init.h"

#include "cp15.h"

#include "custom_EMI_info.h"


/****************************************************************************
   *
   * Specify high-level feature option for EMI driver (internal usage).
   *
   ****************************************************************************/
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

#define __SUPPORT_156MHZ_EMI_CLOCK

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
    

/*************************************
  *
  * Imported APIs.
  *
  *************************************/

/**
  * We will use this function to retrieve the current NOR base address with corresponding L2 cache-bypass bit set so that 
  * we could issue switch command to NOR safely.
  */
extern kal_uint32 INT_RetrieveFlashBaseAddr(void);

/**
   * For auto tracking calibration 
   */
extern kal_int32 store_8word(kal_uint32,kal_uint32);
extern kal_int32 load_8word(kal_uint32,kal_uint32);

extern kal_int32 CMEM_EMIINIT_Index(void);
extern kal_int32 CMEM_Index(void);

extern SW_SECVERSION INT_SW_SecVersion(void);

/*************************************
  *
  * Global Variables.
  *
  *************************************/

#ifdef __MTK_TARGET__
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */


#if defined(__LOG_DATA_TRAIN_ERROR_INFO)
EMI_DATA_TRAIN_ERR_INFO_t emi_data_training_err_info = {1, 2, 3};
#endif 

#ifdef __MTK_TARGET__
#pragma arm section rwdata , rodata , zidata
#endif /* __MTK_TARGET__ */

kal_int8 __EMI_InitializationFlow(void);
int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG);
int __EMI_EnablePerformancePowerControl( void );
int __EMI_EnableBandwidthLimiter( void );


#if defined(__EMI_COMBO_EN)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/* Non-zero default value for EMI variable, avoid to use ZI for EMIINIT region.
   Note: since not all regions are initialized before EMI init flow,
         the using of EMIINITZI might corrupt data of other region which is still kept at load view
 */

#define __EMI_VAL_DEFUALT   0xFFFFFFFF

kal_int32 CMCP_Index = __EMI_DCM_COMBO_INDEX_UND; // Index of the MCP in list

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

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN */

/* Turn-off Combo Memory */
#if defined(__EMI_COMBO_DIS)

#define EMI_DRV_A_VAL       EMI_DRV_A_VAL_MCP0
#define EMI_DRV_B_VAL       EMI_DRV_B_VAL_MCP0

#define EMI_ODL_A_VAL       EMI_ODL_A_VAL_MCP0
#define EMI_ODL_B_VAL       EMI_ODL_B_VAL_MCP0
#define EMI_ODL_C_VAL       EMI_ODL_C_VAL_MCP0
#define EMI_ODL_D_VAL       EMI_ODL_D_VAL_MCP0
#define EMI_ODL_E_VAL       EMI_ODL_E_VAL_MCP0
#define EMI_ODL_F_VAL       EMI_ODL_F_VAL_MCP0
#define EMI_ODL_G_VAL       EMI_ODL_G_VAL_MCP0

#define EMI_CONTROL_I_VAL   EMI_CONTROL_I_VAL_MCP0
#define EMI_CONTROL_J_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_N_VAL   EMI_CONTROL_N_VAL_MCP0

#define EMI_IODUTY_A_VAL    EMI_IODUTY_A_VAL_MCP0
#define EMI_IODUTY_B_VAL    EMI_IODUTY_B_VAL_MCP0
#define EMI_IODUTY_C_VAL    EMI_IODUTY_C_VAL_MCP0

#define EMI_RXDUTY_A_VAL    EMI_RXDUTY_A_VAL_MCP0
#define EMI_RXDUTY_B_VAL    EMI_RXDUTY_B_VAL_MCP0
#define EMI_RXDUTY_E_VAL    EMI_RXDUTY_E_VAL_MCP0

#define EMI_IOMISC_L_VAL    EMI_IOMISC_L_VAL_MCP0  

#define EMI_CONTROL_J_166_VAL   EMI_CONTROL_J_VAL_MCP0
#define EMI_CONTROL_K_166_VAL   EMI_CONTROL_K_VAL_MCP0
#define EMI_CONTROL_L_166_VAL   EMI_CONTROL_L_VAL_MCP0
#define EMI_CONTROL_J_13_VAL   EMI_CONTROL_J_13_VAL_MCP0
#define EMI_CONTROL_K_13_VAL   EMI_CONTROL_K_13_VAL_MCP0
#define EMI_CONTROL_L_13_VAL   EMI_CONTROL_L_13_VAL_MCP0
#if defined(__SUPPORT_156MHZ_EMI_CLOCK)
#define EMI_CONTROL_J_156_VAL   EMI_CONTROL_J_156_VAL_MCP0
#define EMI_CONTROL_K_156_VAL   EMI_CONTROL_K_156_VAL_MCP0
#define EMI_CONTROL_L_156_VAL   EMI_CONTROL_L_156_VAL_MCP0
#endif
#endif /* __EMI_COMBO_DIS */


/* The following information will be used in custom_DynamicClockSwitch() for Combo Memory */
#if defined(__EMI_COMBO_EN)

kal_uint32 __EMI_DCM_idx = __EMI_DCM_COMBO_INDEX_UND;

/** 
   *  The following data structure is placed at INTSRAM, but not EMIINIT,
   *  and will be used in Dynamic Clock Switch
   */

#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#if defined(MT6256)
kal_uint32 EMI_CONTROL_J_166_VAL;
kal_uint32 EMI_CONTROL_K_166_VAL;
kal_uint32 EMI_CONTROL_L_166_VAL;
kal_uint32 EMI_CONTROL_J_13_VAL;
kal_uint32 EMI_CONTROL_K_13_VAL;
kal_uint32 EMI_CONTROL_L_13_VAL;
#if defined(__SUPPORT_156MHZ_EMI_CLOCK)
kal_uint32 EMI_CONTROL_J_156_VAL;
kal_uint32 EMI_CONTROL_K_156_VAL;
kal_uint32 EMI_CONTROL_L_156_VAL;
#endif
#endif
#pragma arm section rwdata , rodata , zidata

#endif /* __EMI_COMBO_EN */

//#if defined(DCM_ENABLE) 
/** 
   *  The following data structure is placed at INTSRAM, but not EMIINIT,
   *  and will be used in Dynamic Clock Switch, for restore DQSA from 13M to 166/200M
   */
#pragma arm section rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
kal_uint32 EMI_DQSA_166M;
kal_uint32 EMI_IDLE_166M;
static kal_uint32 EMI_DQSA_backup_done = 0;

  /** 
   *  The following data structure is placed at INTSRAM, but not EMIINIT,
   *  and will be used in Dynamic Clock Switch, for restore 156M DQSA & IDL 
   */
kal_uint8  EMI_Auto_Training_Result[2];
kal_uint32 EMI_DQSA_156M;
kal_uint32 EMI_IDLE_156M;
#pragma arm section rwdata , rodata , zidata
//#endif //#if defined(DCM_ENABLE) 

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */
kal_uint8  EMI_Auto_Training_Data[2];
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_StoreEmiData()
*
* DESCRIPTION
*   This function provide bootloader store EMI data, then MUAI can use these stored data
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

void __EMI_StoreEmiData(kal_uint8 *emi_data)
{
     *emi_data = EMI_Auto_Training_Data[0];
     *(emi_data+1) = EMI_Auto_Training_Data[1];  
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */



/*************************************************************************
* FUNCTION
*  __EMI_SetEmiPllLowSpeed()
*
* DESCRIPTION
*   This routine aims to set low speed EMI clock
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

void __EMI_SetEmiPllLowSpeed( void )
{
    /**
       * Restore EMIPLL to slow clock
       */
    *PLL_CON1 &= ~(0x2); //Disable EMPLLSEL, bypass PLL, use CLKSQ(26MHz)

    __EMI_DelayLoop(200);
     
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_SetEmiPllHighSpeed()
*
* DESCRIPTION
*   This routine aims to set high speed EMI clock
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

void __EMI_SetEmiPllHighSpeed( void )
{
    /**
       * Enable EMIPLL to fast clock
       */
#if defined(__EMI_CLK_200MHZ__)
    *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x1D;// EPLL clock(2X EMI) = 13Mhz x (0x1D+1) = 390
#else
    *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x18;
#endif

    *EPLL_CON3 = *EPLL_CON3 | 0x0003;
    *EPLL_CON3 = *EPLL_CON3 & 0xfffe;
    *PLL_CON1 |= 0x2; //Enable EMPLLSEL, select from EMIPLLSEL
    
    __EMI_DelayLoop(200);
}

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

void __EMI_InitializeLPDDR( void )
{
    volatile int i;
    kal_uint32 dram_rank = DRAM_CS;
    
    /**
       * Disable Dummy Read.
       */
    *EMI_DRCT=0x0;

    /* Apply output delay */
    *EMI_ODLA=EMI_ODL_A_VAL;
    *EMI_ODLB=EMI_ODL_B_VAL;
    *EMI_ODLC=EMI_ODL_C_VAL;
    *EMI_ODLD=EMI_ODL_D_VAL;
    *EMI_ODLE=EMI_ODL_E_VAL;
    *EMI_ODLF=EMI_ODL_F_VAL;    // only for LPDDR2, 2x CMD
    *EMI_ODLG=EMI_ODL_G_VAL;
    
    /* Apply IO duty */
    *EMI_DUTA=EMI_IODUTY_A_VAL;
    *EMI_DUTB=EMI_IODUTY_B_VAL;
    *EMI_DUTC=EMI_IODUTY_C_VAL;

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
#if defined(__EMI_DEVICE_LPDDR1__)
    *EMI_IOCL |= 0x03000000;
#elif defined(__EMI_DEVICE_LPDDR2__)
    *EMI_IOCL &= ~(0x10000000); /* IOCL = 0 (EMI_IOCL[28]=0, use O1 path) */
    *EMI_IOCL |= 0x05000000;
#else
    #error
#endif

#if defined(__EMI_DEVICE_LPDDR2__)
    /**
      * Enable ZQ Calibration
      */
    *EMI_DDRV = ( 1 << ( DRAM_CS + 4 ) );    
#endif

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
#elif defined(__EMI_DEVICE_LPDDR2__) /* __EMI_DEVICE_LPDDR1__ */
    /**
       * [Initial Flow 1]:Power Ramp
       */
    
    /**
       * [Initial Flow 2]:CKE and clock
       * Enable Clock ( DRAM clk out / delay-line HCLKX2_CK/ SRAM clk center-align /CKE_EN )
       */
    // *EMI_GENA |= 0x00000B10;  
    *EMI_GENA |= 0x00000310;
    
    /**
       * [Initial Flow 3]:Reset Command
       */    
    *EMI_CONI = 0x003F0000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901
    __EMI_DelayLoop(0xfff);
        
    /**
       * [Initial Flow 4]:Mode Registers Reads and Device Auto-Initialization (DAI) polling
       */
    *EMI_CONI = 0x00000000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x40000000; //0x40950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901
    __EMI_DelayLoop(0xfff);

    /**
       * [Initial Flow 5]:ZQ Calibration
       */
    *EMI_CONI = 0xFF0A0000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);
    
    /**
      * Set Device Feature
      */   
    // Set Device Feature1 - nWR=3, WC=Wrap, BT=sequential, BL=4
    *EMI_CONI = 0x22010000;
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);

    *EMI_CONI = 0x01020000;

    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //0x20950901;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //0x00950901;
    __EMI_DelayLoop(0xfff);

    // add for LPDDR2 DRAM driving setting
    *EMI_CONI = EMI_CONTROL_I_VAL; // 0x02030000
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1 | 0x20000000; //|= MRW_EN;
    __EMI_DelayLoop(0xfff);
    *EMI_CONN = EMI_CONTROL_N_VAL | 0x1; //&= ~MRW_EN;
    __EMI_DelayLoop(0xfff);
    
    // Clear Initial Bits
    *EMI_CONN &= ~0xFF000000;
#endif  /* __EMI_DEVICE_LPDDR1__ */ 

    /**
       * Enable auto-refresh, fixed-clock (for auto-refresh), and pdn.
       */        
   *EMI_CONN |=  0x00000016;

    __EMI_DelayLoop(0xff);      
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataTrackingMbistTestCore()
*
* DESCRIPTION
*   Run MBIST core
*
* PARAMETERS
*
* RETURNS
*  -1 : fail
*   0 : successful 
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

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
    
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataAutoTrackingMbistTest()
*
* DESCRIPTION
*   Run MBIST 
*
* PARAMETERS
*
* RETURNS
*  -1 : fail
*    0 : successful 
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int32 __EMI_DataAutoTrackingMbistTest(void)
{
    kal_int32 algo_sel, data_scramble_sel;
    kal_uint32 EMI_DRCT_bakval;

    /**
       * Backup dummy read control. 
       */
    EMI_DRCT_bakval = *EMI_DRCT;

    /**
       * Disable dummy read before testing MBIST (must). 
       */
    *EMI_DRCT &= ~(0x1);
        
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

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataAutoTrackingRegRead()
*
* DESCRIPTION
*   Backup current EMI cotroller register
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

void __EMI_DataAutoTrackingRegRead( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        pREG->EMI_DLLV_regval = *EMI_DLLV;
        pREG->EMI_DQSV_regval = *EMI_DQSV;
        pREG->EMI_CONN_regval = *EMI_CONN;        
        pREG->EMI_DQSA_regval = *EMI_DQSA;
        pREG->EMI_DQSE_regval = *EMI_DQSE;        
        pREG->EMI_IDLA_regval = *EMI_IDLA;
        pREG->EMI_IDLB_regval = *EMI_IDLB;
        pREG->EMI_IDLC_regval = *EMI_IDLC;
        pREG->EMI_IDLD_regval = *EMI_IDLD;
        pREG->EMI_IDLE_regval = *EMI_IDLE;
        pREG->EMI_IDLF_regval = *EMI_IDLF;
        pREG->EMI_IDLG_regval = *EMI_IDLG;
        pREG->EMI_IDLH_regval = *EMI_IDLH;
        pREG->EMI_IDLI_regval = *EMI_IDLI;        
        pREG->EMI_CALA_regval = *EMI_CALA;
        pREG->EMI_CALE_regval = *EMI_CALE;
        pREG->EMI_CALI_regval = *EMI_CALI;
        pREG->EMI_CALP_regval = *EMI_CALP;
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
*  __EmiDataTrainRegWrite()
*
* DESCRIPTION
*   Set EMI controller register
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

/*static*/ void __EmiDataTrainRegWrite( EMI_DATA_TRAIN_REG_t* pREG )
{
    if( pREG != 0 )
    {
        *EMI_CONN = pREG->EMI_CONN_regval;
                 
        *EMI_DQSA = pREG->EMI_DQSA_regval;
        *EMI_DQSE = pREG->EMI_DQSE_regval;
                    
        *EMI_IDLA = pREG->EMI_IDLA_regval;
        *EMI_IDLB = pREG->EMI_IDLB_regval;
        *EMI_IDLC = pREG->EMI_IDLC_regval;
        *EMI_IDLD = pREG->EMI_IDLD_regval;
        *EMI_IDLE = pREG->EMI_IDLE_regval;
        *EMI_IDLF = pREG->EMI_IDLF_regval;
        *EMI_IDLG = pREG->EMI_IDLG_regval;
        *EMI_IDLH = pREG->EMI_IDLH_regval;
        *EMI_IDLI = pREG->EMI_IDLI_regval;
                    
        *EMI_CALA = pREG->EMI_CALA_regval;
        *EMI_CALE = pREG->EMI_CALE_regval;
        *EMI_CALI = pREG->EMI_CALI_regval;
        *EMI_CALP = pREG->EMI_CALP_regval;
    }
    
}
    
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_DataAutoTrackingTraining()
*
* DESCRIPTION
*   This routine aims to execute auto-tracking(find DQ input delay and DQSA & B setting)
*
* PARAMETERS
*
* RETURNS
*  1 : windown found
*  0 : window not found
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

int __EMI_DataAutoTrackingTraining( EMI_DATA_TRAIN_REG_t* pResult )
{    
#define ___EMIDATATRAIN_MBIST_DATATRAIN__
#define DEBUG_MODE 0

    kal_int32 value;
    kal_int32 bytex_dly_mod, bytex_setup_mod, dqy_in_del, dqsix_dlysel;
    kal_int32 bytex_dly_mod_start = 0, bytex_setup_mod_start = 0, dqy_in_del_start = 0;
    kal_int32 prev_emi_dqsa = 0;
    kal_int32 prev_emi_idl = 0, prev_emi_cala = 0, prev_emi_cale = 0, prev_emi_cali = 0;
    kal_int32 prev_dwnd_size = 0, dwnd_size;
    kal_int32 lbound_finding;
    
    kal_uint32 DQSI_center = 0x0, DQSI_start = 0x00, DQSI_end = 0xFF; //Use to record the DQSI start and end value
    
    kal_int32 test_result;
    kal_int32 DATA_TUNING_STEP = 2;
    kal_int32 DQSI_TUNING_STEP = 4;    
    kal_int32 WINDOW_SIZE_THRESHOLD = 6;
    kal_int32 DQSI_TUNING_WINDOW_SIZE_THRESHOLD = 6;

    int b_wnd_found = 0;
    EMI_DATA_TRAIN_REG_t REG_BAK;
    
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
    *EMI_CALP &= ~0xFFFF0001;
    *EMI_DQSE &= ~0xFFFF;
    
    for(dqsix_dlysel=0x0; dqsix_dlysel<=0x7F; dqsix_dlysel+=DQSI_TUNING_STEP/* 8 */)
    {
        #ifdef RTC_DEBUG
            dbg_print("DQSA = 0x%x\n\r", dqsix_dlysel);
        #endif 
        /*Mask Auto Tracking Init Value*/
        *EMI_DQSA = dqsix_dlysel<<24 | dqsix_dlysel<<16 | dqsix_dlysel<<8 | dqsix_dlysel;

        lbound_finding = 1;

        /*byte_delay = 0*/
        bytex_dly_mod = 0;
        *EMI_IDLI = 0;

        /*byte_setup = 0*/
        bytex_setup_mod = 0;
        *EMI_CALE = 0;

        /*Reset CALA/CALI*/
        *EMI_CALA = 0;
        *EMI_CALI = 0;

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
            if(lbound_finding==1 && test_result == 0 )
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
            
            *EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

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
        *EMI_CALE = bytex_setup_mod<<24 | bytex_setup_mod<<16 | bytex_setup_mod<<8 | bytex_setup_mod;

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
            
            *EMI_DQSA = prev_emi_dqsa;
            
            *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl;
            *EMI_CALA = prev_emi_cala;
            *EMI_CALE = prev_emi_cale;
            *EMI_CALI = prev_emi_cali;

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
            
            *EMI_DQSA = prev_emi_dqsa;
            
            *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl;
            *EMI_CALA = prev_emi_cala;
            *EMI_CALE = prev_emi_cale;
            *EMI_CALI = prev_emi_cali;

            
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
        prev_emi_dqsa = *EMI_DQSA;

        /*Align "DQS riging" & "data out"*/
        //value = (dqy_in_del_start > (dwnd_size/2)) ? (dqy_in_del_start-dwnd_size/2) : 0;
        //value<<24 | value<<16 | value<<8 | value;
        *EMI_IDLE = *EMI_IDLF = *EMI_IDLG = *EMI_IDLH = prev_emi_idl =        
        dqy_in_del_start<<24 | dqy_in_del_start <<16 | dqy_in_del_start <<8 | dqy_in_del_start;

        /*Byte Data Delay*/
        value = (bytex_setup_mod_start+(dwnd_size/2))>31? (bytex_setup_mod_start+(dwnd_size/2))-31:0;
        //value = (bytex_setup_mod_start+(dwnd_size/2))<31? (bytex_setup_mod_start+(dwnd_size/2)):31; //CLS
        *EMI_CALA = prev_emi_cala = value<<24 | value<<16 | value<<8 | value;
        
        /*Byte Data Setup*/
        value = (bytex_setup_mod_start+(dwnd_size/2))<31? (bytex_setup_mod_start+(dwnd_size/2)):31;
        //value = (bytex_setup_mod_start+(dwnd_size/2))>31? (bytex_setup_mod_start+(dwnd_size/2))-31:0; //CLS      
        *EMI_CALE = prev_emi_cale = (value<<24 | value<<16 | value<<8 | value);

        /*byte Data Hold*/
        value = ( dwnd_size/2 > 31 ) ? 31 : dwnd_size/2;
        *EMI_CALI = prev_emi_cali = value<<24 | value<<16 | value<<8 | value;

        /*Go next mask setting*/
        
    }

    /* IvanTseng : Get the proper DQSI value here */
    DQSI_center = (DQSI_start + DQSI_end)/2;
    *EMI_DQSA = DQSI_center<<24 | DQSI_center<<16 | DQSI_center<<8 | DQSI_center;
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

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  __EMI_InitializationFlow()
*
* DESCRIPTION
*   This routine aims to execute EMI initial (include EMI controller¡BDRAM¡Bauto-tracking) 
*
* PARAMETERS
*
* RETURNS
*    0 : fail
*    1 : successful 
*
* GLOBALS AFFECTED
*
*************************************************************************/

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


    return ret;    
}

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
*  1 : successful
*  0 : fail
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

int __EMI_EnableDataAutoTracking( EMI_DATA_TRAIN_REG_t* DATA_TRAIN_RESULT_REG)
{
    int ret = 1;

    volatile SW_SECVERSION sw_sec_version;

    #if defined(MT6276)
    int adjust_dqi;
    #endif

    // the output delay must be applied before DDR init 
    /*
    *EMI_ODLA=EMI_ODL_A_VAL;
    *EMI_ODLB=EMI_ODL_B_VAL;
    *EMI_ODLC=EMI_ODL_C_VAL;
    *EMI_ODLD=EMI_ODL_D_VAL;
    *EMI_ODLE=EMI_ODL_E_VAL;
    *EMI_ODLG=EMI_ODL_G_VAL;
    */
    
#if defined(__SUPPORT_156MHZ_EMI_CLOCK)
     sw_sec_version = INT_SW_SecVersion();

    if (sw_sec_version == SW_SEC_0)  //MT6256 E2 ~ E4
    {
    /*********** Switch EPLL 166Mhz **************/

    /* block emi access */
    *EMI_CONM |= 0x003F;

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

    *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x18; //switch EPLL 166Mhz
   
    __EMI_DelayLoop(200);

    /* exit SDRAM self-refresh mode */
    *EMI_CONN &= ~0x00000020;
        
      __EMI_DelayLoop(255);
        
     /* resume emi access */
    *EMI_CONM &= ~0x003F;

    /******************************************/

    if( __EMI_DataAutoTrackingTraining(DATA_TRAIN_RESULT_REG ) == 0 )
    {
        /**
           * Data training fail. 
           */
        ASSERT(0);   
        ret = 0; 
    }

    EMI_Auto_Training_Data[0] = (kal_uint8)(DATA_TRAIN_RESULT_REG->EMI_DQSA_regval & 0xFF);     
    EMI_Auto_Training_Data[1] = (kal_uint8)(DATA_TRAIN_RESULT_REG->EMI_IDLE_regval & 0xFF);

    /*********** Switch EPLL normal EMI operation clock (166/200 Mhz) **************/

    /* block emi access */
    *EMI_CONM |= 0x003F;

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

#if defined(__EMI_CLK_200MHZ__)
    *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x1D;// EPLL clock(2X EMI) = 13Mhz x (0x1D+1) = 390
#else
    *EPLL_CON2 = (*EPLL_CON2 & 0xff80) | 0x18;
#endif

    __EMI_DelayLoop(200);

    /* exit SDRAM self-refresh mode */
    *EMI_CONN &= ~0x00000020;
        
      __EMI_DelayLoop(255);
        
     /* resume emi access */
    *EMI_CONM &= ~0x003F;

    }
#endif /* #if defined(__SUPPORT_156MHZ_EMI_CLOCK) */

    if( __EMI_DataAutoTrackingTraining(DATA_TRAIN_RESULT_REG ) == 0 )
    {
        /**
           * Data training fail. 
           */
        ASSERT(0);   
        ret = 0; 
    }

    /**
       * Mask auto tracking initial value. 
       */
    *EMI_DQSA = DATA_TRAIN_RESULT_REG->EMI_DQSA_regval;     

#if defined(__EMI_DATA_AUTO_TRACKING_ENABLE)
   
    /**
        * Data Auto Tracking init value. 
        */
    *EMI_CALA = DATA_TRAIN_RESULT_REG->EMI_CALA_regval;     
    *EMI_CALE = DATA_TRAIN_RESULT_REG->EMI_CALE_regval;
    *EMI_CALI = DATA_TRAIN_RESULT_REG->EMI_CALI_regval;    
    *EMI_CALP = DATA_TRAIN_RESULT_REG->EMI_CALP_regval;    

    /**
        * Enable auto data tracking. 
        */
    *EMI_CALP |= 0x1;                                       
    
#else
    
    #if defined(MT6276)
    /* The variation of timing window on L/R boundary is un-balance under different corner case;
       It will be better to apply some adjusting */
    adjust_dqi = DATA_TRAIN_RESULT_REG->EMI_IDLA_regval & 0x1f;
    adjust_dqi = adjust_dqi + 3;
    if (adjust_dqi > 0x1f) adjust_dqi = 0x1f;
    
    DATA_TRAIN_RESULT_REG->EMI_IDLA_regval = DATA_TRAIN_RESULT_REG->EMI_IDLB_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLC_regval = DATA_TRAIN_RESULT_REG->EMI_IDLD_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLE_regval = DATA_TRAIN_RESULT_REG->EMI_IDLF_regval = 
    DATA_TRAIN_RESULT_REG->EMI_IDLG_regval = DATA_TRAIN_RESULT_REG->EMI_IDLH_regval
             = (adjust_dqi << 24) | (adjust_dqi << 16) | (adjust_dqi << 8) | adjust_dqi;
    #endif
    
    /**
       * DQ-in delay. 
       */
    *EMI_IDLA = DATA_TRAIN_RESULT_REG->EMI_IDLA_regval;     
    *EMI_IDLB = DATA_TRAIN_RESULT_REG->EMI_IDLB_regval;
    *EMI_IDLC = DATA_TRAIN_RESULT_REG->EMI_IDLC_regval;
    *EMI_IDLD = DATA_TRAIN_RESULT_REG->EMI_IDLD_regval;
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
   *(volatile kal_uint32*)EMI_DRCT=0x8000F001;

    return ret;    
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
#define EMI_ARB_A_VAL                           0x0000541F   // ARM11, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x0000103C   // MM SYS
#define EMI_ARB_C_VAL                           0x00005003   // DMA, soft mode, sm_gnt_cnt=0
#define EMI_ARB_D_VAL                           0x00005009   // MD2G + Peri SYS, soft mode, sm_gnt_cnt=0
#define EMI_ARB_E_VAL                           0x0000500A   // DSP
#define EMI_ARB_F_VAL                           0x0000100F   // Graphic, soft mode, sm_gnt_cnt=0


#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

int __EMI_EnableBandwidthLimiter( void )
{

    /* Set ARM BW*/
    *EMI_ARBA = EMI_ARB_A_VAL;

    /* Set MMSYS BW */
    *EMI_ARBB = EMI_ARB_B_VAL;

    /* Set DMA BW */
    *EMI_ARBC = EMI_ARB_C_VAL;

    /* Set MD2G/Peri. BW */
    *EMI_ARBD = EMI_ARB_D_VAL;

    /* Set DSP BW */
    *EMI_ARBE = EMI_ARB_E_VAL;

    /* Set graphic BW */
    *EMI_ARBF = EMI_ARB_F_VAL;

    return 0;

}

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

 
int __EMI_EnablePerformancePowerControl( void )
{
    /**
       * Setup Precharge & PDN delay 
       */
    *(volatile kal_uint32*)EMI_PPCT=0xFFFF0000;

    /** 
        * Disable all HI prio and enable R/W command flavor.
        */

    // Disable RW_FAVOR_M1 for MM 
    *(volatile kal_uint32*)EMI_SLCT=0x0000003D;

    /**
        * Setup 1/16 freq for HWDCM mode and enable arbitration controls 
        */ 
    *(volatile kal_uint32*)EMI_ABCT=0x00070010;

    __EMI_DelayLoop(100);

    return 0;    
}


#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  evb_fail_detection()
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

int evb_fail_detection( void )
{

    return 0;
}


#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

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

#if defined(__EMI_COMBO_EN)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

void __EMI_SetRegValfromCMCP(void)
{
   MTK_EMI_Info *mem_info;

   mem_info = (MTK_EMI_Info *)&EMI_INFO_2.mem_info[CMCP_Index];

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
   
   return;

}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#endif /* __EMI_COMBO_EN */

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
*   1 : successful
*  -1: fail
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int8 custom_setEMI(void)
{
   kal_uint32   DRAM_Enable = DRAM_CS;
   volatile kal_uint32   delay;

/**
  *   Call CMEM_EMIINIT_Index to get the index
  */
#if defined(__EMI_COMBO_EN)
   CMCP_Index = CMEM_EMIINIT_Index();
   __EMI_SetRegValfromCMCP();
#endif

   /* Add a delay loop for MT6235 to prevent modify EMI reg while EMI serving a request (pre-fetch). */
   for(delay=0; delay<255; delay++);

   if ( (DRAM_Enable != 0xFF) && (DRAM_Enable < 4) )
   {
      /* remapping if DRAM at CS1 */
      if ( DRAM_Enable == 1 )
      {
         *EMI_GENA   &= 0xFFFFFFFC;
         *EMI_GENA   |= 0x3;

         /**
            * we assume customers only use one CS as their DRAM.
            */
         *EMI_GEND   &= 0xFFF0FFF0;
         *EMI_GEND   |= 0x0002000D;
      }
      else if ( DRAM_Enable == 0 )
      {
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
      }
      else
      {
         /**
            * we do not support customers use those CS other than CS0 and CS1 as their booting regions.
            */
         ASSERT(0);
      }

    __EMI_InitializationFlow();

      return 1;
   }
   else
   {
      /**
         * trap directly.
         */
      ASSERT(0);
   }

   return -1;

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

#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))
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

#endif //#if (( !defined(__UBL__) && !defined(__FUE__) ) || defined(__EMMC_BOOTING__))



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
#if ( !defined(__UBL__) && !defined(__FUE__) )
  /* __FUE__ , __UBL__ compile option is used for FOTA or USB Bootloader build
   * add this compile option to avoid compiling functions other than custom_setEMI()
   * The Bootloader will perform Sync/Page EMI initialization at the new EMI init flow, so we must be careful about 
   * the wrapping option so that Bootloader could reference this function.
   */

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE"
#endif /* __MTK_TARGET__ */

kal_int8 custom_setAdvEMI(void)
{
   kal_int8    status = 0;

   return status;
}

#ifdef __MTK_TARGET__
#pragma arm section code
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

#if defined(__EMI_CLK_166MHZ__)
    cur_emi_clk_rate = EMI_CLK_166MHZ;
#elif defined(__EMI_CLK_200MHZ__) /* __EMI_CLK_166MHZ__ */
    cur_emi_clk_rate = EMI_CLK_200MHZ;
#endif /* __EMI_CLK_166MHZ__ */

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

//#if defined(DCM_ENABLE) 

#pragma arm section code = "INTSRAM_ROCODE"

int custom_DynamicClockSwitch(mcu_clock_enum clock)
{

   register kal_uint32 delay;

    if (0 == EMI_DQSA_backup_done)
    {
        EMI_DQSA_166M = *EMI_DQSA;
        EMI_IDLE_166M = *EMI_IDLE;
        EMI_DQSA_backup_done = 1;

        /* Get EMI auto-tracking result which stored on bootloader */
        INT_GetSysStaByCmd(SYS_CMD_GET_EMI_PARAM,(void *)EMI_Auto_Training_Result);
        EMI_DQSA_156M = (kal_uint32)(EMI_Auto_Training_Result[0]<<24 | EMI_Auto_Training_Result[0]<<16 | EMI_Auto_Training_Result[0]<<8 | EMI_Auto_Training_Result[0]);
        EMI_IDLE_156M =  (kal_uint32)(EMI_Auto_Training_Result[1]<<24 | EMI_Auto_Training_Result[1]<<16 | EMI_Auto_Training_Result[1]<<8 | EMI_Auto_Training_Result[1]);
    }

    if (clock == MCU_26MHZ) {

        /*
         * ZW: It's a special mode for Low Power Audio, we'll switch EMI to 26MHz. 
         */
        
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

        /* block emi access */
        *EMI_CONM |= 0x003F;  
        
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x1; //Disable DATA_CAL_EN0

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

        /* Switch the EMI setting for 1x 13MHz */  //below setting from Fumin
        *EMI_CONJ = EMI_CONTROL_J_13_VAL;
        *EMI_CONK = EMI_CONTROL_K_13_VAL;
        *EMI_CONL = EMI_CONTROL_L_13_VAL;

        *EMI_DQSA = 0x00000808;
        *EMI_DQSB = 0x00000808;
        *EMI_DQSE = 0x00000000;

        /* Set SW DCM mode */
        *EMI_ABCT |= 0x40; 

        //*PLL_CON6 = 0xF000; //enable dcm, div set
        //for(delay=0; delay<0x10; delay++); //wait switch, Remove by IvanTseng
        /* Switch EMI to 26MHz */
        *PLL_CON1 &= ~(0x0002); 
        
        for(delay = 0; delay<0xFF; delay++);

        /* Enable DQSI auto tune */
        //*EMI_DQSE |= 0x10000003;

        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

         /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng
        
        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;

				for(delay = 0; delay<0x6FF; delay++); //Should > 1 auto-refresh period (7.8us) for 1/5 DLL update¡A10~15 us is better

        /* resume emi access */
        *EMI_CONM &= ~0x003F;

        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        
        return 0;
   }else if (clock == MCU_520MHZ) {
        /*
         * ZW: It's a special mode for Low Power Audio, we'll switch EMI back to full speed
         */
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

        /* block emi access */
        *EMI_CONM |= 0x003F;
        
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x1; //Disable DATA_CAL_EN0

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

        //*PLL_CON1 &= ~0xC000; //SWDCM mode: clear HWDIV_MODE & HWDCM_MODE
        /* Switch EMI to EPLL */
        *PLL_CON1 |= (0x0002); 
        
        //for(delay = 0; delay<0xFF; delay++); //Remove by IvanTseng

        /* Apply DDR 333 settings */
        *EMI_CONJ = EMI_CONTROL_J_166_VAL;
        *EMI_CONK = EMI_CONTROL_K_166_VAL;
        *EMI_CONL = EMI_CONTROL_L_166_VAL;
        
        *EMI_DQSA = EMI_DQSA_166M;
        *EMI_DQSB = EMI_DQSA_166M;

         /**
         * DQ-in delay. 
         */
         *EMI_IDLA = EMI_IDLE_166M;     
         *EMI_IDLB = EMI_IDLE_166M;
         *EMI_IDLC = EMI_IDLE_166M;
         *EMI_IDLD = EMI_IDLE_166M;
         *EMI_IDLE = EMI_IDLE_166M;
         *EMI_IDLF = EMI_IDLE_166M;
         *EMI_IDLG = EMI_IDLE_166M;
         *EMI_IDLH = EMI_IDLE_166M;

        //*EMI_DQSE = 0x10000033;

        /* Enable DQSI auto tune and DQSI_DCM_AUTO_TUNE_EN (for self-refresh) */
        /* After exit DRAM self-refresh, send mass dummy read to auto-tune */
        *EMI_DQSE |= 0x10000003;    /* Suggested by Fumin */

        /* Don't set SW DCM mode */
        *EMI_ABCT &= ~0x40; 
         
        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

        /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng

        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;
        
        for(delay = 0; delay<0x6FF; delay++); //Should > 1 auto-refresh period (7.8us) for 1/5 DLL update¡A10~15 us is better
        
        /* resume emi access */
        *EMI_CONM &= ~0x003F;

        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        
        return 0;
   }
#if defined(__SUPPORT_156MHZ_EMI_CLOCK)
   else if (clock == SSC_EMI_NON_EPLL) 
   {
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

        /* block emi access */
        *EMI_CONM |= 0x003F;
        
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x1; //Disable DATA_CAL_EN0

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

        *PLL_MISC_CON |= 0x800;   // switch EPLL to UPLL/2
        
        for(delay = 0; delay<0xFF; delay++); 
        
        /* Apply DDR 333 settings */
        *EMI_CONJ = EMI_CONTROL_J_156_VAL;
        *EMI_CONK = EMI_CONTROL_K_156_VAL;
        *EMI_CONL = EMI_CONTROL_L_156_VAL;

        *EMI_DQSA = EMI_DQSA_156M;
        *EMI_DQSB = EMI_DQSA_156M;

         /**
         * DQ-in delay. 
         */
         *EMI_IDLA = EMI_IDLE_156M;
         *EMI_IDLB = EMI_IDLE_156M;
         *EMI_IDLC = EMI_IDLE_156M;
         *EMI_IDLD = EMI_IDLE_156M;
         *EMI_IDLE = EMI_IDLE_156M;
         *EMI_IDLF = EMI_IDLE_156M;
         *EMI_IDLG = EMI_IDLE_156M;
         *EMI_IDLH = EMI_IDLE_156M;

        //*EMI_DQSE = 0x10000033;

        /* Enable DQSI auto tune and DQSI_DCM_AUTO_TUNE_EN (for self-refresh) */
        /* After exit DRAM self-refresh, send mass dummy read to auto-tune */
        *EMI_DQSE |= 0x10000003;    /* Suggested by Fumin */

        /* Don't set SW DCM mode */
        *EMI_ABCT &= ~0x40; 
         
        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

        /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng

        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;
        
        for(delay = 0; delay<0x6FF; delay++); //Should > 1 auto-refresh period (7.8us) for 1/5 DLL update¡A10~15 us is better
        
        /* resume emi access */
        *EMI_CONM &= ~0x003F;

        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        
        return 0;
   }
   else if (clock == SSC_EMI_EPLL) 
   {
        /*
         * ZW: It's a special mode for Low Power Audio, we'll switch EMI back to full speed
         */
        /* Disable EMI dummy read */
        *EMI_DRCT &= ~1; //Add by IvanTseng

        /* block emi access */
        *EMI_CONM |= 0x003F;
        
        /* Disable data auto-tracking */
        *EMI_CALP &= ~0x1; //Disable DATA_CAL_EN0

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

        *PLL_MISC_CON &= ~(0x800);   // switch to EPLL

        for(delay = 0; delay<0xFF; delay++);

        /* Apply DDR 333 settings */
        *EMI_CONJ = EMI_CONTROL_J_166_VAL;
        *EMI_CONK = EMI_CONTROL_K_166_VAL;
        *EMI_CONL = EMI_CONTROL_L_166_VAL;
        
        *EMI_DQSA = EMI_DQSA_166M;
        *EMI_DQSB = EMI_DQSA_166M;

         /**
         * DQ-in delay. 
         */
         *EMI_IDLA = EMI_IDLE_166M;     
         *EMI_IDLB = EMI_IDLE_166M;
         *EMI_IDLC = EMI_IDLE_166M;
         *EMI_IDLD = EMI_IDLE_166M;
         *EMI_IDLE = EMI_IDLE_166M;
         *EMI_IDLF = EMI_IDLE_166M;
         *EMI_IDLG = EMI_IDLE_166M;
         *EMI_IDLH = EMI_IDLE_166M;

        //*EMI_DQSE = 0x10000033;

        /* Enable DQSI auto tune and DQSI_DCM_AUTO_TUNE_EN (for self-refresh) */
        /* After exit DRAM self-refresh, send mass dummy read to auto-tune */
        *EMI_DQSE |= 0x10000003;    /* Suggested by Fumin */

        /* Don't set SW DCM mode */
        *EMI_ABCT &= ~0x40; 
         
        /* Make sure the CAL_EN is ENABLED */
        *EMI_CONN |= (0x00000100); //Enable CAL_EN, 1/5T DLL, Add by IvanTseng

        /* Enable auto data tracking*/
        //*EMI_CALP |= 1; //Remove by IvanTseng

        /* exit SDRAM self-refresh mode */
        *EMI_CONN &= ~0x00000020;
        
        for(delay = 0; delay<0x6FF; delay++); //Should > 1 auto-refresh period (7.8us) for 1/5 DLL update¡A10~15 us is better
        
        /* resume emi access */
        *EMI_CONM &= ~0x003F;

        /* Enable EMI dummy read */
        *EMI_DRCT |= 1;
        
        return 0;
   }
#endif  // #if defined(__SUPPORT_156MHZ_EMI_CLOCK)

   /* unsupported MCU clock */
   return -1;

 
}

#pragma arm section code

//#endif  /* DCM_ENABLE */



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

//#if defined(DCM_ENABLE) 

#if defined(__EMI_COMBO_EN)
   if (__EMI_DCM_idx == __EMI_DCM_COMBO_INDEX_UND) 
   {  
      // We only query at the first time
      __EMI_DCM_idx = CMEM_Index();
   
      EMI_CONTROL_J_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_value;
      EMI_CONTROL_K_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_value;
      EMI_CONTROL_L_166_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_value;
      EMI_CONTROL_J_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_13_value;
      EMI_CONTROL_K_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_13_value;
      EMI_CONTROL_L_13_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_13_value;
#if defined(__SUPPORT_156MHZ_EMI_CLOCK)
       EMI_CONTROL_J_156_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONJ_156_value;
       EMI_CONTROL_K_156_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONK_156_value;
       EMI_CONTROL_L_156_VAL = __EMI_DCM_control[__EMI_DCM_idx].EMI_CONL_156_value;;
#endif
   } 
   else
   { 
      return -1; //return error code instead ASSERT(0); // This init function should only be called once
   }
#endif /* __EMI_COMBO_EN */

    //EMI_DQSA_166M = *EMI_DQSA;

//#endif /* DCM_ENABLE */

    return 0;
}



#endif /* !__FUE__ && !__UBL__ */

#endif //#if defined(MT6256) && defined(__MTK_TARGET__)

