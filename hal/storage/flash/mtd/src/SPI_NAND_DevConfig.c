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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  NAND_DevConfig.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash and GPIO configuration file.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_general_types.h"
#include "reg_base.h"
#include "NAND_MTD_FDM50_internal.h"
#include "SPI_NAND_MTD_FDM50_internal.h"
#include "SPI_NAND_DevConfig.h"
#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"
#include "dcl.h"
#include "nld_central_ctrl.h"

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
   #include <assert.h>
   #define ASSERT    assert
   #define EXT_ASSERT(e, x, y, z)  assert(e)
   #define NAND_LOGGING
    #define kal_mem_set  memset
    #define kal_mem_cpy memcpy
    #define kal_mem_cmp memcmp
    #define NAND_GPIO_ReturnMode(a) (user_def_cs_num)
    extern kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    extern  kal_uint8 user_def_cs_num;
#endif

#if defined(__SPI_NAND_SUPPORT__) && defined(__NAND_FDM_50__)

#if !defined(__UBL__)

/*single page cache support, usually apply to old type NAND*/
NAND_MTD_SUB_DRIVER MTK_SPI_NAND_SUB_DRIVER_1 =
{
    single_Page_Program,    /*ProgramPage*/
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
    single_Block_Erase,     /*EraseBlock*/
    NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase*/
    NULL, /*TwoDieTwoPlaneErase*/
#ifdef __SECURITY_OTP__
	SNAND_OTPAccess,
	SNAND_OTPQueryLength,
#else // __SECURITY_OTP__
	NULL,
	NULL,
#endif // __SECURITY_OTP__
};

#else  // __UBL__

// For Bootloader case, only need to include read routines.
NAND_MTD_SUB_DRIVER MTK_SPI_NAND_SUB_DRIVER_1 =
{
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(__EMULATE_NFB_BIT_ERROE__) ) || ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Page_Program,    /*ProgramPage*/
#else
    NULL,    /*ProgramPage*/
#endif
    single_Page_Read,       /*ReadPage*/
    NULL,                   /*CopyPage*/
#if ( defined(__UBL_NAND_FULL_DRIVER__) )
    single_Block_Erase,     /*EraseBlock*/
#else // ( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL,     /*EraseBlock*/
#endif //( defined(__UBL_NAND_FULL_DRIVER__) )
    NULL, /*TwoPlaneProgram*/
    NULL, /*TwoDieProgram*/
    NULL, /*FourPlaneProgram*/
    NULL, /*TwoDieTwoPlaneProgram*/
    NULL, /*CacheProgram*/
    NULL, /*TwoPlaneCacheProgram*/
    NULL, /*TwoDieCacheProgram*/
    NULL, /*FourPlaneCacheProgram*/
    NULL, /*TwoDieTwoPlaneCacheProgram*/
    NULL, /*TwoPlaneErase*/
    NULL, /*TwoDieErase*/
    NULL, /*FourPlaneErase*/
    NULL, /*TwoDieTwoPlaneErase*/
	NULL,
	NULL,
};

#endif  // !defined(__UBL__)
/*******************************************************************************
 *  Global variable
 *******************************************************************************/
#define NFI_EVENT   0x1

flash_list Default_ID_Table =
      { simu_NAND_1/*DevName_enum*/, {'D','E','F','A','U','L','T',0xFF}/*ID_info*/,
        {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}/*ID_valid_mask*/, AUTO_NAND_DETECT/*IOWidth*/, AUTO_NAND_DETECT/*address_cycle*/,
        AUTO_NAND_DETECT/*planeNum*/, AUTO_NAND_DETECT/*dieNum*/, AUTO_NAND_DETECT/*pageSize*/,AUTO_NAND_DETECT/*spareSize*/,AUTO_NAND_DETECT/*blockPage*/,AUTO_NAND_DETECT/*deviceSize (MByte)*/,
        AUTO_NAND_DETECT/*supportMPType*/, AUTO_NAND_DETECT/*supportMEType*/, AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/};

const kal_uint8 ID_512_Mask[8] = {0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const kal_uint8 ID_2K_Mask[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x00, 0x00, 0x00};

/*[Notice] g_snand_id_table should sort by
1. manufacture ID group;
2 ID valid bite (from large -> small)*/
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
flash_list g_snand_id_table[] =
#else
const flash_list g_snand_id_table[] =
#endif
{
    // Fake SPI_NAND for simulation
    { simu_SPI_NAND_0/*DevName_enum*/,{'0','1','F','A','K','E',0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00}/*ID_valid_mask*/, 8/*IOWidth*/, 4/*address_cycle*/,
       1/*planeNum*/,  1/*dieNum*/, 2048/*pageSize*/,64/*spareSize*/,32/*blockPage*/,64/*deviceSize (MByte)*/,0/*supportMPType*/,0/*supportMEType*/,AUTO_NAND_DETECT/*CopyBackType*/, (NAND_MTD_SUB_DRIVER*)AUTO_NAND_DETECT/*driverSet*/},

    // Last one
    { MAX_SPI_NAND_NAME/*DevName_enum*/,{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}/*ID_info*/,
      {0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00}/*ID_valid_mask*/, 0, 0, 0,  0, 0,0,0,0,0,0,NULL}   // End of ID Table
};

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    extern kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    #define NAND_GPIO_ReturnMode(a) (user_def_cs_num)
#endif

kal_uint8 SNAND_GPIO_Setting(void)
{
    kal_uint8   CS_num = 1;
    kal_uint32  reg;

    #if defined(MT6260)
    {
        // pad macro switch registers
        #define RW_CONFIG_HW_MISC2          ((SNAND_P_U16)(CONFIG_base + 0x0230))

        #define CONFIG_PAD_MACRO            (0x00000001)
        #define CONFIG_PAD_MACRO_SNOR       (1) // SFI (default)
        #define CONFIG_PAD_MACRO_SNAND      (0) // SPI-NAND

        // clock registers
        #define RW_CONFIG_PDN_COND2         ((SNAND_P_U16)(CONFIG_base + 0x308))
        #define RW_CONFIG_PDN_SETD2         ((SNAND_P_U16)(CONFIG_base + 0x318))
        #define RW_CONFIG_PDN_CLRD2         ((SNAND_P_U16)(CONFIG_base + 0x328))
        #define PDN_SPI_NAND_CG             (0x1000)

        // GPIO registers
        #define SPI_NAND_GPIO_MODE8         ((volatile UINT32P)(GPIO_base + 0xc80))
        #define SPI_NAND_GPIO_MODE9         ((volatile UINT32P)(GPIO_base + 0xc90))
        #define SPI_NAND_GPIO_MODE8_CLR     (0x00000077) //Clear mode setting of GPIO 66 to 71
        #define SPI_NAND_GPIO_MODE9_CLR     (0x77777770) //Clear mode setting of GPIO 72
        #define SPI_NAND_GPIO67             (0x00001000) //SFSWP
        #define SPI_NAND_GPIO68             (0x00010000) //SFSCS0
        #define SPI_NAND_GPIO69             (0x00100000) //SFSCK
        #define SPI_NAND_GPIO70             (0x01000000) //SFSIN
        #define SPI_NAND_GPIO71             (0x10000000) //SFSOUT
        #define SPI_NAND_GPIO72             (0x00000001) //SFSHOLD

        //-- A. disable clock gating (turn-on SPI-NAND controller)
        reg = *RW_CONFIG_PDN_COND2;

        if (1 == (reg & PDN_SPI_NAND_CG))   // if clock is gated-off originally, turn-on the clock, else do nothing
        {
            *RW_CONFIG_PDN_CLRD2 = PDN_SPI_NAND_CG;
        }

        //-- B. config pad macro
        reg = *RW_CONFIG_HW_MISC2;
        reg = (reg & ~CONFIG_PAD_MACRO) | CONFIG_PAD_MACRO_SNAND;
        *RW_CONFIG_HW_MISC2 = reg;

        //-- C. config GPIO

        // C-1. SPI_NAND_GPIO_MODE8
        *SPI_NAND_GPIO_MODE8 = (*SPI_NAND_GPIO_MODE8 & SPI_NAND_GPIO_MODE8_CLR) | SPI_NAND_GPIO67 | SPI_NAND_GPIO68 | SPI_NAND_GPIO69 | SPI_NAND_GPIO70 | SPI_NAND_GPIO71;

        // C-2. SPI_NAND_GPIO_MODE9
        *SPI_NAND_GPIO_MODE9 = (*SPI_NAND_GPIO_MODE9 & SPI_NAND_GPIO_MODE9_CLR) | SPI_NAND_GPIO72;
    }
    #else
        #error "Please define SNAND_GPIO_Setting!"
    #endif

    return CS_num;
}

void set_nfi_driving_current(kal_uint32 driving)
{
    // do nothing
}

#endif  // __SPI_NAND_SUPPORT__ && __NAND_FDM_50__


