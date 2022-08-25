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
 *   custom_SFI.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SFI (serial flash interface) related setting.
 *
 * Author:
 * -------
 *   Chun-Hung Wu(mtk03818)   EMI auto generator V8.268
 *
 *   Memory Device database last modified on 2018/8/25
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_SFI__
#define __CUSTOM_SFI__

/*
 ****************************************************************************
 Specify the chip select configuration
 Possible choices, NOR_FLASH, RAM, LPSDRAM, UNUSED
 ****************************************************************************
*/

/*
 ****************************************************************************
 Specify RAM size in Bytes
 ****************************************************************************
*/


/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/

#define __SFI_CLK_104MHZ__

#define __SFI_DCM_COMBO_INDEX_UND   0xffffffff

#if defined(MT6252) || defined(MT6251)
typedef enum {
    SFC_MAC_CTL            = 0x0      // Write Enable Latch
   ,SFC_MISC_CTL_1         = 0x1      // Write Suspend Program Status
   ,SFC_DLY_CTL_1          = 0x2      // Security ID status (Once set by Lock Security ID (0x85h) it can not be reset)
   ,SFC_DR_CTL             = 0x3      // Write operation status (Write In Progress Bit)
   ,SFC_Driving_1          = 0x4      // Write operation status (Write In Progress Bit)
   ,SFC_Driving_2          = 0x5      // Write operation status (Write In Progress Bit)
   ,SFC_Reserved           = 0x6      // Write operation status (Write In Progress Bit)
   ,SFC_MISC_CTL_2         = 0x7      // Write Protection Lockdown Status (Resets to 0 after a power cycle)
   ,SFC_DLY_CTL_2          = 0x8      // Write operation status (Write In Progress Bit)
} SF_SFC_Control_Reg_Enum;

#elif defined(MT6255)
typedef enum {
    SFC_MAC_CTL            = 0x0      // Write Enable Latch
   ,SFC_DR_CTL             = 0x1      // Write Suspend Program Status
   ,SFC_MISC_CTL           = 0x2      // Security ID status (Once set by Lock Security ID (0x85h) it can not be reset)
   ,SFC_DLY_CTL2           = 0x3      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL3           = 0x4      // Write operation status (Write In Progress Bit)
   ,SFC_Driving            = 0x5      // Write operation status (Write In Progress Bit)
   ,SFC_Reserved           = 0x6      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL4           = 0x7      // Write operation status (Write In Progress Bit)
   ,SFC_DLY_CTL5           = 0x8      // Write operation status (Write In Progress Bit)
} SF_SFC_Control_Reg_Enum;

#elif defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef enum {
    SFC_MAC_CTL            = 0x0
   ,SFC_DR_CTL             = 0x1
   ,SFC_MISC_CTL           = 0x2
   ,SFC_MISC_CTL2          = 0x3
   ,SFC_DLY_CTL2           = 0x4
   ,SFC_DLY_CTL3           = 0x5
   ,SFC_Driving            = 0x6
   ,SFC_Reserved           = 0x7
   ,SFC_DLY_CTL4           = 0x8
   ,SFC_DLY_CTL5           = 0x9
} SF_SFC_Control_Reg_Enum;
#endif

#define ProcessID       ((volatile UINT32P)(EFUSE_base+0x0024))  /* Chip ID register 3 */

#if defined(MT6251)
#define ACIF_CON4       ((volatile UINT16P)(CONFIG_base+0x718))
#define ACIF_CON5       ((volatile UINT16P)(CONFIG_base+0x71C))
//#define SFI_CLOCK     78

#elif defined(MT6253L)||defined(MT6252)
#define ACIF_CON0       ((volatile UINT32P)(CONFIG_base+0x700))

#elif defined(MT6255)
#define IO_DRV2         ((volatile UINT32P)(CONFIG_base+0x508))
#define SFC_CTRL_SET    ((volatile UINT32P)(CONFIG_base+0x61C))
#define VSF_CON0        ((volatile UINT16P)(MIXED_base+0x700))
#define VSF_CON3        ((volatile UINT16P)(MIXED_base+0x70C))

#elif defined(MT6250)
#define GPIO_DRV0           ((volatile UINT16P)(GPIO_base+0x800))
#define SFC_EFUSE           ((volatile UINT32P)(EFUSE_base+0x108))
#define GPIO_SF2            (GPIO_base+0xC92)
#define GPIO_SF2_Enable     (0x00111117)

#define GPIO_DRV0_OFFSET            (8)
#define GPIO_DRV0_SIZE              (3)
#define GPIO_DRV0_MASK              (0x0700)
#define SFIFO_WR_EN_DLY_SEL_OFFSET  (24)

#define SFC_DRIVING_OFFSET          (0)
#define SFC_DRIVING_SIZE            (3)
#define SFC_INPUT0_DLY_OFFSET       (3)
#define SFC_INPUT0_DLY_SIZE         (2)
#define SFC_INPUT1_DLY_OFFSET       (5)
#define SFC_INPUT1_DLY_SIZE         (2)
#define SFC_INPUT2_DLY_OFFSET       (7)
#define SFC_INPUT2_DLY_SIZE         (2)
#define SFC_INPUT3_DLY_OFFSET       (9)
#define SFC_INPUT3_DLY_SIZE         (2)
#define SFC_SAMPLECLK_DLY_OFFSET    (11)
#define SFC_SAMPLECLK_DLY_SIZE      (6)

#define SFC_GET_EfuseBits(offset, size)         ((*SFC_EFUSE <<(32 - (offset+size))) >> (32-size))
#define SFC_IS_NEGATIVE(number, size)           (number &(1<<(size-1)))
#define SFC_NEGATIVE_TO_POSITIVE(number, size)  ((1<<size)-number)

#elif defined(MT6260)
/* SFC clock registers */
#define PDN_COND2           (CONFIG_base + 0x308)
#define PDN_SETD2           (CONFIG_base + 0x318)
#define PDN_CLRD2           (CONFIG_base + 0x328)
#define RG_SFC_SW_CG        (0x0800)

/* SFC pad switch register */
#define HW_MISC2            (CONFIG_base + 0x230)
#define PAD_SWITCH          (0x0001)

/* SF GPIO registers*/
#define SF_GPIO_MODE8       (GPIO_base + 0xc80)
#define SF_GPIO_MODE9       (GPIO_base + 0xc90)
#define SF_GPIO_MODE8_CLR   (0x00000077) //Clear mode setting of GPIO 66 to 71
#define SF_GPIO_MODE9_CLR   (0x77777770) //Clear mode setting of GPIO 72
#define SF_GPIO66           (0x00000100) //SFSCS1 not use in BootROM
#define SF_GPIO67           (0x00001000) //SFSWP
#define SF_GPIO68           (0x00010000) //SFSCS0
#define SF_GPIO69           (0x00100000) //SFSCK
#define SF_GPIO70           (0x01000000) //SFSIN
#define SF_GPIO71           (0x10000000) //SFSOUT
#define SF_GPIO72           (0x00000001) //SFSHOLD
#define GPIO_RESEN1         (GPIO_base + 0xb10)
#define GPIO_RESEN2         (GPIO_base + 0xb20)
#define GPIO_RESEN4         (GPIO_base + 0xb40)
#define GPIO_RESEN5         (GPIO_base + 0xb50)

#define SF_SLT_MODE_R0_R1_SET           (0x1F80) //GPIO_R1[12:7] and GPIO_R4[12:7]
#define SF_NORMAL_MODE_R0_R1_SET1       (0xE000) //GPIO_R1[15:13] and GPIOR4[15:13]
#define SF_NORMAL_MODE_R0_R1_Dual_SET   (0x2000) //GPIO_R1[13] and GPIOR4[13]
#define SF_NORMAL_MODE_R0_R1_SET2       (0x000F) //GPIO_R2[3:0] and GPIO_R5[3:0]


/* SFC Driving registers */
#define GPIO_DRV0           ((volatile UINT16P)(GPIO_base+0x800))


/* SFC Dual SF registers */
#define GPIO_SF2_Enable     (0x00000100)

/* SFC SLT registers */
#define SF_NORMAL_MODE      (0x00000001)
#define SF_SLT_MODE         (0x00000002)
#define SF_SLT_MODE_MASK    (0x00000007)


/* SFC foundry porting registers */
#define SFC_EFUSE           ((volatile UINT32P)(EFUSE_base+0x108))

#define GPIO_DRV0_OFFSET            (8)
#define GPIO_DRV0_SIZE              (3)
#define GPIO_DRV0_MASK              (0x0700)
#define SFIFO_WR_EN_DLY_SEL_OFFSET  (24)

#define SFC_DRIVING_OFFSET          (0)
#define SFC_DRIVING_SIZE            (3)
#define SFC_INPUT0_DLY_OFFSET       (3)
#define SFC_INPUT0_DLY_SIZE         (2)
#define SFC_INPUT1_DLY_OFFSET       (5)
#define SFC_INPUT1_DLY_SIZE         (2)
#define SFC_INPUT2_DLY_OFFSET       (7)
#define SFC_INPUT2_DLY_SIZE         (2)
#define SFC_INPUT3_DLY_OFFSET       (9)
#define SFC_INPUT3_DLY_SIZE         (2)
#define SFC_SAMPLECLK_DLY_OFFSET    (11)
#define SFC_SAMPLECLK_DLY_SIZE      (6)

#define SFC_GET_EfuseBits(offset, size)         ((*SFC_EFUSE <<(32 - (offset+size))) >> (32-size))
#define SFC_IS_NEGATIVE(number, size)           (number &(1<<(size-1)))
#define SFC_NEGATIVE_TO_POSITIVE(number, size)  ((1<<size)-number)

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
/* SF GPIO registers*/
#define SFIO_CFG0           (CONFIG_base + 0x600)
#define SFIO_CFG1           (CONFIG_base + 0x604)
#define SFIO_CFG2           (CONFIG_base + 0x608)
#define SF_NORMAL_HIGHZ     (0xFFCFFFCF)
#define GPIO_RESEN0_1       (GPIO_base + 0xb10)
#define GPIO_RESEN1_1       (GPIO_base + 0xb30)
#define SF_SLT_HIGHZ        (0xFFF81FFF)
#define GPIO_DRV1           (GPIO_base + 0x810)
#define SF_SLT_DRIVING_CLR  (0xFF3FFFFF)
#define SF_SLT_DRIVING_12mA (0xFF8FFFFF)

/* SFC Driving registers */
#define SFIO_CFG0_DRV       ((volatile UINT32P)(CONFIG_base+0x600))
#define SFIO_CFG1_DRV       ((volatile UINT32P)(CONFIG_base+0x604))
#define SFIO_CFG2_DRV       ((volatile UINT32P)(CONFIG_base+0x608))


/* SFC SLT registers */
#define SF_NORMAL_MODE      (0x00000001)
#define SF_SLT_MODE         (0x00000002)
#define SF_SLT_MODE_MASK    (0x00000007)


#elif defined(MT6280)
#define GPIO_DRV6           ((volatile UINT16P)(GPIO_base+0x3500))
#define GPIO84_MODE_SFIO2   (2)
#define GPIO85_MODE_SFIO1   (2)
#define GPIO86_MODE_SFIO0   (2)
#define GPIO87_MODE_SFCS    (2)
#define GPIO88_MODE_SFCLK   (2)
#define GPIO89_MODE_SFIO3   (2)

#define GPIO_MODE_BASE          (GPIO_base + 0x1000)
#define GPIO_GET_MODE(_n)       *(U16 *)(GPIO_MODE_BASE + (_n >> 2) * 0x100)
#define GPIO_SET_MODE(_n, mode) *(U16 *)(GPIO_MODE_BASE + (_n >> 2) * 0x100) =  
                                (*(U16*)(GPIO_MODE_BASE + (_n >> 2) * 0x100) & (~(0xF << (4 * (_n & 0x3))))) | (mode << (4 * (_n & 0x3)))
#endif


static const CMEMEntrySFIList_dcm combo_mem_hw_list_dcm = {   // (to be renamed by SFI owner)

    //COMBO_SFI_VER,           // SFI structure version
    //COMBO_MEM_ENTRY_COUNT,   // defined in custom_Memorydevice.h
    {

        {   // KH25U6439FZNI_10G
            {   // HW config 104Mhz Start
                0x52F80010,  // SFI_MISC_CTL
                0x0,  // SFI_DLY_CTL_2
                0x15000015,  // SFI_DLY_CTL_3
                0,  // SFI_DLY_CTL_4
                0,  // SFI_DLY_CTL_5
            },  // HW config END
            {   // HW config 26Mhz Start
                0x52F80000,  // SFI_MISC_CTL
                0x0,  // SFI_DLY_CTL_2
                0x0,  // SFI_DLY_CTL_3
            }  // HW config END
        }

    }
};

/*
 ****************************************************************************
 Specify the related EMI Setting
 ****************************************************************************
*/

/*
 ****************************************************************************
 Specify additional information
 ****************************************************************************
*/

#endif /* __CUSTOM_SFI__ */

