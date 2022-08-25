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
 *   custom_EMI_MT6260.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(MT6260) && defined(__MTK_TARGET__)

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

#include "dcm.h"

/** 
  *     CMEM_EMIINIT_Index() is defined in "combo_flash_init.h"
  *     it should be included at autoGen for Combo Memory !!
  *
  */
#include "combo_flash_init.h"

#include "cp15.h"

#include "custom_EMI_info.h"

//#define BCR_RCR_DEBUG
//#define EMI_APPLY_E_FUSE

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
#if defined(_NAND_FLASH_BOOTING_) 

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

/*************************************
  *
  * Imported APIs.
  *
  *************************************/
  
extern SW_SECVERSION INT_SW_SecVersion(void);

/*************************************
  *
  * Global Variables.
  *
  *************************************/
#if defined(EMI_APPLY_E_FUSE)
void EMI_Read_EF(void);
kal_int32 EMI_two_complement(kal_int32 , int );
kal_int32 EMI_bound_setting(kal_int32 value, int bit_count);
#endif 

   /*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/
const ExtMemoryType_T   EMI_CSConfiguration[4] =
{
   UNUSED,
   RAM,
   UNUSED,
   UNUSED

};

 
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

/* Non-zero default value for EMI variable, avoid to use ZI for EMIINIT region.
   Note: since not all regions are initialized before EMI init flow,
         the using of EMIINITZI might corrupt data of other region which is still kept at load view
 */

   #define __EMI_VAL_DEFUALT   0xFFFFFFFF

   kal_int32 CMCP_Index = __EMI_DCM_COMBO_INDEX_UND; // Index of the MCP in list

   kal_uint32 EMI_CONB_ASYNC = __EMI_VAL_DEFUALT;
   
   kal_uint32 EMI_CONB_BURST = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_CONF_BURST = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_GENERAL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_RDCT_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_IDL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IDL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IDL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IDL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IDL_E_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_ODL_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_B_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_C_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_D_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_E_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_ODL_F_VAL = __EMI_VAL_DEFUALT; 

   kal_uint32 EMI_IO_A_VAL = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_IO_B_VAL = __EMI_VAL_DEFUALT;

   kal_uint32 EMI_DSRAM_VAL = __EMI_VAL_DEFUALT;

   // Always BURST
   kal_uint32 Sel_PSRAM_CMD_num = __EMI_VAL_DEFUALT;
   kal_uint32 EMI_PSRAM_BURST_OP[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_ADDRESS[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};
   kal_uint32 EMI_PSRAM_BURST_DATA[__EMI_PSRAM_CMD_NUM] = {__EMI_VAL_DEFUALT};

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  __EMI_GetDIDR()
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
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

// Address to be read DIDR
#define __EMI_DIDR_ADDRESS        EMI_PSRAM_BURST_ADDRESS_1_MCP0 //0x01FFFFFF

kal_uint32 __EMI_CurDIDR = 0; // will be also used in custom_setAdvEMI();

void __EMI_GetDIDR(void)
{
     kal_uint16 didr, data;
     kal_int32 delay;
     
   /** 
     * Suppose the command sequence to be R -> R -> W -> R/W 
     */
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }

   *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS) = 0x2;
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   didr = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   __EMI_CurDIDR = (kal_uint32)didr;
   
   return;
}

#ifdef BCR_RCR_DEBUG

kal_uint32 __EMI_CurBCR = 0x0100; // will be also used in custom_setAdvEMI();
kal_uint32 __EMI_CurRCR = 0x0200; // will be also used in custom_setAdvEMI();

void __EMI_GetBCR(void)
{
     kal_uint16 didr, data;
     kal_int32 delay;
     
   /** 
     * Suppose the command sequence to be R -> R -> W -> R/W 
     */
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }

   *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS) = 0x1;
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   didr = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   __EMI_CurBCR = (kal_uint32)didr;
   
   return;
}

void __EMI_GetRCR(void)
{
     kal_uint16 didr, data;
     kal_int32 delay;
     
   /** 
     * Suppose the command sequence to be R -> R -> W -> R/W 
     */
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   data = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }

   *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS) = 0x0;
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   didr = *(volatile unsigned short *)(RAM_BASE_ADDR | __EMI_DIDR_ADDRESS);
   for (delay=0; delay <0x0f; delay++) {
       #if defined(__RVCT__) && defined(__MTK_TARGET__)
       __nop()
       #endif
       ;
   }
   
   __EMI_CurRCR = (kal_uint32)didr;
   
   return;
}

#endif 

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
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

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

void __EMI_SetRegValfromCMCP(void)
{
   MTK_EMI_Info *mem_info;
   kal_uint32  i;

   mem_info = (MTK_EMI_Info *)&EMI_INFO_2.mem_info[CMCP_Index];

   EMI_CONB_ASYNC = mem_info->EMI_CONB_ASYNC_value;
   
   EMI_CONB_BURST = mem_info->EMI_CONB_BURST_value;
   EMI_CONF_BURST = mem_info->EMI_CONF_BURST_value;

   EMI_GENERAL_A_VAL = mem_info->EMI_GENA_value;
   EMI_RDCT_VAL = mem_info->EMI_RDCT_value;

   EMI_IDL_A_VAL = mem_info->EMI_IDL_A_value;
   EMI_IDL_B_VAL = mem_info->EMI_IDL_B_value;
   EMI_IDL_C_VAL = mem_info->EMI_IDL_C_value;
   EMI_IDL_D_VAL = mem_info->EMI_IDL_D_value;
   EMI_IDL_E_VAL = mem_info->EMI_IDL_E_value;

   EMI_ODL_A_VAL = mem_info->EMI_ODL_A_value;
   EMI_ODL_B_VAL = mem_info->EMI_ODL_B_value;
   EMI_ODL_C_VAL = mem_info->EMI_ODL_C_value;
   EMI_ODL_D_VAL = mem_info->EMI_ODL_D_value;
   EMI_ODL_E_VAL = mem_info->EMI_ODL_E_value;
   EMI_ODL_F_VAL = mem_info->EMI_ODL_F_value;

   EMI_IO_A_VAL = mem_info->EMI_IO_A_value;
   EMI_IO_B_VAL = mem_info->EMI_IO_B_value;

   EMI_DSRAM_VAL = mem_info->EMI_DSRAM_value;

   // Always BURST   
   Sel_PSRAM_CMD_num = mem_info->EMI_PSRAM_CMD_num;
   
   for (i=0; i<Sel_PSRAM_CMD_num; i++) {
      EMI_PSRAM_BURST_OP[i] = mem_info->EMI_PSRAM_CMD_OP[i];
      EMI_PSRAM_BURST_ADDRESS[i] = mem_info->EMI_PSRAM_CMD_ADDR[i];
      EMI_PSRAM_BURST_DATA[i] = mem_info->EMI_PSRAM_CMD_DATA[i];
   }
          
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
#if defined(EMI_APPLY_E_FUSE)
    kal_int32 index_efuse;
    kal_int32 efuse;
#endif 

   CMCP_Index = 0;

#if defined(EMI_APPLY_E_FUSE)
    efuse = *EMI_EFUSE;
    index_efuse    = ((efuse >> 4) & 0x7);
     CMCP_Index = index_efuse;
#endif     

   __EMI_SetRegValfromCMCP();

   *EMI_CONB = EMI_CONB_ASYNC;

      /**
        * RD_DEL_SEL must be h01 under asyn mode
        * we should keep this value maintenance in the database, here we just set it to prevent any potential MVG setting error.
        */
   *EMI_CONF |= 0x00000400;

    //*EMI_GEND  = EMI_GENERAL_D_VAL;
   *EMI_GENA = EMI_GENERAL_A_VAL; 
   *BOOT_CON = 0x02;  //set external boot , remap control change to Bus 
   
    return 0;
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
#if defined( __EMI_CLK_166MHZ__)
/**
  * M0: MCU            39.10%, soft
  * M1: DMA            7.03%, soft
  * M2: GMC            53.90%, soft
  */

#define EMI_ARB_A_VAL                           0x00005426   // ARM  port, filter-length=1024 (max=4096)
#define EMI_ARB_B_VAL                           0x00005009   // DMA port
#define EMI_ARB_C_VAL                           0x00005051   // MM

#else  //130Mhz
/**
  * M0: MCU            39.10%, soft
  * M1: DMA            7.03%, soft
  * M2: GMC            53.14%, soft
  */

//#define EMI_ARB_A_VAL                           0x00005432   // ARM  port, filter-length=1024 (max=4096)
//#define EMI_ARB_B_VAL                           0x00005009   // DMA port
//#define EMI_ARB_C_VAL                           0x00005044   // MM 

#endif

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
 
int __EMI_EnableBandwidthLimiter( void )
{

     /* Set ARM port BW*/
    *EMI_ARBA = EMI_ARB_A_VAL;

    /* Set DMA port BW */
    *EMI_ARBB = EMI_ARB_B_VAL;

    /* Set GMC port BW */
    *EMI_ARBC = EMI_ARB_C_VAL;

    return 0;

}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */
//#endif /* !__FUE__ && !__UBL__ */

//#if defined((__EMI_CLK_130MHZ__) || (__EMI_CLK_166MHZ__)) //Tk-pSRAM mode

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

kal_int32 TestCase_MBIST(void)
{
	kal_uint32 mbist_src, mbist_len, mbist_data[2] = {0x5AA5, 0xFFFF};
	kal_uint32 i, bist_data_inv, bist_trans_len, bist_data_random; 
	
	mbist_src = 0x200000;
	mbist_len = 0x4000;
//	mbist_data[0] = 0x5AA5;
//	mbist_data[1] = 0x5AA5;	
	
	*EMI_MBISTA = 0x0;
	for(bist_data_inv=0; bist_data_inv<=1; bist_data_inv++) 
	  for(i=0; i<=1; i++)
	    for(bist_data_random=0;bist_data_random<=1;bist_data_random++)
	      {
	      	// need to reset mbist everytime
			*EMI_MBISTA = 0x0;	
			// config mbist source address and test length
			*EMI_MBISTB = ((mbist_src >> 8)<<16) | (( mbist_len >> 8)-1);
			// config mbist data pattern, data inverse, burst length and width
			*EMI_MBISTA = (mbist_data[i] << 16) | (bist_data_inv << 12)  | (bist_data_random << 13);
			*EMI_MBISTA |= 0x325; // enable MBIST, write and read mode, 4 byte trans size, burst length = 16 byte
			// check if mbist finished
			while((*EMI_MBISTD & 0x2) == 0x0);
			// check mbist result
			if((*EMI_MBISTD & 0x1) != 0) return -1;
		  }	

	return 0;
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */


#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int32 __EMI_DataAutoTrackingMbistTest(void)
{
       if ( TestCase_MBIST() != 0 )
       {
           return -1;
        }

        return 0;
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
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI", rwdata = "EMIINITRW"
#endif /* __MTK_TARGET__ */

#define DATA_TUNING_STEP 1

void  __EMI_EnableDataAutoTracking(void)
{
        kal_int32 dqy_in_del = 0x1F;
        kal_int32 dqs_in_del = 0;

        for(dqy_in_del=0x1F; dqy_in_del>=0; dqy_in_del-=DATA_TUNING_STEP)
        {
            *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD =
            dqy_in_del<<24 | dqy_in_del<<16 | dqy_in_del<<8 | dqy_in_del;

            if (0 ==  __EMI_DataAutoTrackingMbistTest())
            {
                 break;
            }
         }

         if (dqy_in_del < 0)  //DQ_IN_DELAY can't find window
         {
            for(dqs_in_del=0x1; dqs_in_del<=0x1F; dqs_in_del+=DATA_TUNING_STEP)
            {
                *EMI_IDLE = dqs_in_del<<24 | dqs_in_del<<16 ;
    
                if (0 ==  __EMI_DataAutoTrackingMbistTest())
                {
                     break;
                }
            }
         }
#if 1
		if (dqy_in_del >= 0 ) dqy_in_del += 1;
		else if (dqs_in_del <= 1) 
		{
			dqy_in_del = 1 - dqs_in_del;
			dqs_in_del = 0;			
		}
		else 
		{
			dqy_in_del = 0;
			dqs_in_del -= 1;
		}

        *EMI_IDLA = *EMI_IDLB = *EMI_IDLC = *EMI_IDLD =
        dqy_in_del<<24 | dqy_in_del<<16 | dqy_in_del<<8 | dqy_in_del;

        *EMI_IDLE = dqs_in_del<<24 | dqs_in_del<<16 ;
#endif
    return;    
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata, rwdata
#endif /* __MTK_TARGET__ */

//#endif //#if defined((__EMI_CLK_130MHZ__) || (__EMI_CLK_166MHZ__)) //Tk-pSRAM mode

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

#define __EMI_DIDR_APTIC_MASK     0x0000001F
#define __EMI_DIDR_APTIC_VID      0x0000994D
//#if defined(__EMI_CLK_130MHZ__)
#define __EMI_DIDR_APTIC_BCRVAL   0x00002B33
//#else  //TK-PSRAM
//#define __EMI_DIDR_APTIC_BCRVAL   0x00002333
//#endif

kal_int8 custom_setAdvEMI(void)
{
       kal_int8    status = 0;
	kal_int32	delay = 0xf;
	volatile unsigned short *ptr16;
	unsigned short data;
	kal_uint32 saved_cache_con, saved_prefetch_con;
       kal_uint32  i;

      /**
      * On ARM9 system, the core will perform pre-fetch in the background, we add a delay loop to prevent modify EMI reg 
      * while EMI serving a request (pre-fetch). 
      */
      for (delay=0; delay <0xff; delay++);  
      //Disable cache  //[CM's question 20120106]

      /**
         * Setting EMI general control register and cache/prefetch size if necessary.
         */
     *EMI_GENA = EMI_GENERAL_A_VAL;  
     *BOOT_CON = 0x02;  //set external boot , remap control change to Bus 


       /**
      *  Work-around for MT6250 SIP with APTIC PSRAM
      *  Adjust the driving to 1/8 !
      */
      __EMI_GetDIDR();

      if ((__EMI_CurDIDR & __EMI_DIDR_APTIC_MASK) == (__EMI_DIDR_APTIC_VID & __EMI_DIDR_APTIC_MASK)) {
           /* overwrite the BCR configuration value */
         if ((EMI_PSRAM_BURST_DATA[2]& 0x0000ffff)== 0x01) {
            EMI_PSRAM_BURST_DATA[3] = __EMI_DIDR_APTIC_BCRVAL;
         } else if ((EMI_PSRAM_BURST_DATA[6]& 0x0000ffff)== 0x01) {
            EMI_PSRAM_BURST_DATA[7] = __EMI_DIDR_APTIC_BCRVAL;
         }
      }   
#if defined(EMI_APPLY_E_FUSE)
      EMI_Read_EF();
#endif
     /**
      * Switch PSRAM configuration (BCR/RCR) into corresponding modes.
      * This part is not part of the auto-gen template and is compile-time generated.
      */
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

#ifdef BCR_RCR_DEBUG

       __EMI_GetBCR();
       while (__EMI_CurBCR != EMI_PSRAM_BURST_DATA[3]);

       __EMI_GetRCR();

//#if defined(__EMI_CLK_104MHZ__)   
//       while (__EMI_CurRCR != EMI_PSRAM_BURST_DATA[7]);  //RCR bit.11 = 1 for TK-pSRAM
//#else
       while (__EMI_CurRCR != (EMI_PSRAM_BURST_DATA[7] | 0x1000));  //RCR bit.12 = 1 for TK-pSRAM
//#endif //#if defined(__EMI_CLK_104MHZ__)   
      
#endif  //#ifdef BCR_RCR_DEBUG
    
	  /**
          * Switch the EMI register into corresponding modes.
          */    	
        *EMI_CONB = EMI_CONB_BURST; 
        *EMI_CONF = EMI_CONF_BURST;
        for (delay=0; delay <0xff; delay++);    	
    	
        /**
          * set SCLK_EN, SCLK_SEL(center-aligned for write)
          */
        *EMI_GENA |= 0x00000400;        
        *BOOT_CON |= 0x01;  //Remap, remap control change to Bus 

        for (delay=0; delay <0xff; delay++);
     
        *EMI_RDCT = EMI_RDCT_VAL;

        *EMI_DSRAM = EMI_DSRAM_VAL; 

        /**
          * set driving & delay 
          */
         *EMI_IDLA = EMI_IDL_A_VAL;
         *EMI_IDLB = EMI_IDL_B_VAL;
         *EMI_IDLC = EMI_IDL_C_VAL;
         *EMI_IDLD = EMI_IDL_D_VAL;
         *EMI_IDLE = EMI_IDL_E_VAL;

         *EMI_ODLA = EMI_ODL_A_VAL;
         *EMI_ODLB = EMI_ODL_B_VAL;
         *EMI_ODLC = EMI_ODL_C_VAL;
         *EMI_ODLD = EMI_ODL_D_VAL;
         *EMI_ODLE = EMI_ODL_E_VAL;
         *EMI_ODLF = EMI_ODL_F_VAL;

         *EMI_IOA= EMI_IO_A_VAL;
         *EMI_IOB= EMI_IO_B_VAL;

         for (delay=0; delay <0xff; delay++);           

//#if defined((__EMI_CLK_130MHZ__) || (__EMI_CLK_166MHZ__)) //Tk-pSRAM mode
	  /**
          * Calibrate DQ in delay.
          */    
        __EMI_EnableDataAutoTracking();

	  /**
          * Enable 1/5 DLL
          */    	
          *EMI_DLLV= 0x300f0000; //dll_cal_init = 1
          while(((*EMI_DLLV & 0x80 ) >> 7) != 1); //wait_cal_done = 1
          *EMI_DLLV= 0x700f0000; // enable dll soft update
          while(((*EMI_DLLV & 0x80 ) >> 7) != 0); //wait_cal_done = 0
          *EMI_DLLV= 0x100f0000; //initialization finish

//#endif

          __EMI_EnableBandwidthLimiter();

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

#if defined(__EMI_CLK_166MHZ__)
    cur_emi_clk_rate = EMI_CLK_166MHZ;
#elif  defined(__EMI_CLK_130MHZ__) /* __EMI_CLK_130MHZ__ */
    cur_emi_clk_rate = EMI_CLK_130MHZ;
#else  /* __EMI_CLK_130MHZ__ */
    cur_emi_clk_rate = EMI_CLK_104MHZ;

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



#if defined(DCM_ENABLE) 

#pragma arm section code = "INTSRAM_ROCODE"

int custom_DynamicClockSwitch(mcu_clock_enum clock)
{

   register kal_uint32 delay;

#if 0
/* under construction !*/
/* under construction !*/
#endif

   /* unsupported MCU clock */
   return -1;

 
}

#pragma arm section code

#pragma arm section code = "INTSRAM_ROCODE"

int custom_EMIDynamicClockSwitch(mcu_clock_enum clock)
{
    return 1;
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

#if defined(DCM_ENABLE) 


#endif /* DCM_ENABLE */

    return 0;
}

#if defined(EMI_APPLY_E_FUSE)

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */


void EMI_Read_EF(void)
{

   kal_int32 DQ_offset,CLK_offset,DQS_offset,OD_DQ_offset,OD_DQS_offset,MEM_DRV_offset, WP_RST_offset;
   kal_int32 DQ_efuse,CLK_efuse,DQS_efuse,OD_DQ_efuse,OD_DQS_efuse,MEM_DRV_efuse, WP_RST_efuse;
   kal_int32 IO_DRV_DQ, IO_DRV_DQS, IO_DRV_CLK, OD_DQ, OD_DQS, MEM_DRV, WP_RST_Ext, DQS_WP_RST;
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
		WP_RST_efuse   = ((efuse >> 24) & 0x3);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
	//	dbg_print("efuse index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_efuse,DQ_efuse,CLK_efuse,DQS_efuse,OD_DQ_efuse,OD_DQS_efuse,MEM_DRV_efuse);

    
    DQ_offset         =  EMI_two_complement(DQ_efuse, 3);
    CLK_offset        =  EMI_two_complement(CLK_efuse, 3); 
    DQS_offset        =  EMI_two_complement(DQS_efuse, 3); 
    OD_DQ_offset      =  EMI_two_complement(OD_DQ_efuse, 3); 
    OD_DQS_offset     =  EMI_two_complement(OD_DQS_efuse, 3); 
    MEM_DRV_offset    =  EMI_two_complement(MEM_DRV_efuse, 2);
    WP_RST_offset    =  EMI_two_complement(WP_RST_efuse, 2); 
  //  dbg_print("offset index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,DQ_offset,CLK_offset,DQS_offset,OD_DQ_offset,OD_DQS_offset,MEM_DRV_offset);
    
    IO_DRV_DQ =  (EMI_IO_A_VAL & 0x7);
    IO_DRV_DQS = ((EMI_IO_B_VAL >> 16)& 0x7);
    IO_DRV_CLK = ((EMI_IO_A_VAL >> 16) & 0x7);
    OD_DQ = (EMI_ODL_D_VAL & 0x1F);
    OD_DQS = ((EMI_ODL_E_VAL >> 16)& 0x1F);
    MEM_DRV = (EMI_PSRAM_BURST_DATA[3] >> 4) & 0x3;
    DQS_WP_RST  = (EMI_RDCT_VAL) & 0x7;//EMI_RDCT 
    WP_RST_Ext  = (EMI_RDCT_VAL >> 14) & 0x7;//EMI_RDCT 
    
 //   dbg_print("DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*calculate drv DQ result*/
    IO_DRV_DQ = IO_DRV_DQ + DQ_offset;
    IO_DRV_DQ = EMI_bound_setting(IO_DRV_DQ, 3);
    
    /*calculate drv DQS result*/
    IO_DRV_DQS = IO_DRV_DQS + DQS_offset; 
    IO_DRV_DQS = EMI_bound_setting(IO_DRV_DQS, 3);
    
    /*calculate drv CLK result*/
    IO_DRV_CLK = IO_DRV_CLK + CLK_offset;
    IO_DRV_CLK = EMI_bound_setting(IO_DRV_CLK, 3);
    
    /*calculate output delay DQ result*/
    OD_DQ = OD_DQ + OD_DQ_offset;
    OD_DQ = EMI_bound_setting(OD_DQ, 5);
    
     /*calculate output delay DQS result*/
    OD_DQS = OD_DQS + OD_DQS_offset;
    OD_DQS = EMI_bound_setting(OD_DQS, 5);
    
     /*calculate memory driving result*/
    MEM_DRV = MEM_DRV + MEM_DRV_offset;
    MEM_DRV = EMI_bound_setting(MEM_DRV, 2);
    	
     /*calculate Macro Write Pointer Reset result*/
    WP_RST_Ext = WP_RST_Ext + WP_RST_offset;
    WP_RST_Ext = EMI_bound_setting(WP_RST_Ext, 2);
    	
    DQS_WP_RST = DQS_WP_RST + WP_RST_offset;
    DQS_WP_RST = EMI_bound_setting(DQS_WP_RST, 2);
    
  //  dbg_print("finally result index: %d, DQ: %d, CLK: %d, DQS:%d, OD_DQ: %d, OD_DQS:%d, MEM_DRV:%d\n", index_offset,IO_DRV_DQ,IO_DRV_CLK,IO_DRV_DQS,OD_DQ,OD_DQS,MEM_DRV);
    /*finally result*/
    EMI_IO_A_VAL &= 0xFFFFFFF8;
    EMI_IO_A_VAL |= IO_DRV_DQ ;
    
    EMI_IO_A_VAL &= 0xFFF8FFFF;
    EMI_IO_A_VAL |= (IO_DRV_CLK << 16);
    
    EMI_IO_B_VAL &= 0xFFFFFFF8;
    EMI_IO_B_VAL |= IO_DRV_DQ ;
    
    EMI_IO_B_VAL &= 0xFFF8FFFF;
    EMI_IO_B_VAL |= (IO_DRV_DQS << 16);
    
    EMI_ODL_A_VAL =  EMI_ODL_B_VAL = EMI_ODL_C_VAL = EMI_ODL_D_VAL = (OD_DQ << 24) | (OD_DQ << 16) | (OD_DQ << 8) | (OD_DQ << 0); 
    
    EMI_ODL_E_VAL &= 0xFFFF0000;
    EMI_ODL_E_VAL |= (OD_DQ << 8) | (OD_DQ << 0);
    
    EMI_ODL_F_VAL &= 0xFFFF00FF;
    EMI_ODL_F_VAL |= (OD_DQ << 8);
    
    EMI_ODL_E_VAL &= 0x0000FFFF;
    EMI_ODL_E_VAL |= (OD_DQS << 24) | (OD_DQS << 16);
    
    EMI_ODL_F_VAL &= 0xFFFFFF00;
    EMI_ODL_F_VAL |= OD_DQS;
     
    EMI_PSRAM_BURST_DATA[3] &= 0xFFCF;
    EMI_PSRAM_BURST_DATA[3] |= (MEM_DRV << 4);  
    
    EMI_RDCT_VAL &= 0xFFFF3FFC;
    EMI_RDCT_VAL |= (WP_RST_Ext << 14) | (DQS_WP_RST);
    
    //EMI_DRV_A_VAL = 0x7FFFFFF0;
    
  //  dbg_print("drva : %x drvb : %x odlc : %x odld : %x odle : %x odlg : %x coni : %x\n", EMI_DRV_A_VAL,EMI_DRV_B_VAL,EMI_ODL_C_VAL,EMI_ODL_D_VAL,EMI_ODL_E_VAL,EMI_ODL_G_VAL,EMI_CONTROL_I_VAL); 
 
}
#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE", rodata = "EMIINITCONST", zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */

kal_int32 EMI_bound_setting(kal_int32 value, int bit_count)
   	{
    if (value >= (1<< bit_count))
   		{
         value = (1<< bit_count) - 1;
   		}
    else if (value <= 0)
   		{
         value = 0;
   		}
   		
   		    return value;
   		}
   		
kal_int32 EMI_two_complement(kal_int32 offset, int bit_count)
{
         if (offset >= (1 << (bit_count-1)))
   	{
                offset = offset - (1 << bit_count);
   	}

         return offset;
}

#ifdef __MTK_TARGET__
#pragma arm section code, rodata, zidata
#endif /* __MTK_TARGET__ */

#endif // #if defined(EMI_APPLY_E_FUSE)

//#endif /* !__FUE__ && !__UBL__ */

#endif //#if defined(MT6260) && defined(__MTK_TARGET__)

