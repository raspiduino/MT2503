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
 *  bl_SNAND_V2.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   NAND flash driver for NFI V3.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*-----------------------------------------------------
 * Included Header Files
 *-----------------------------------------------------*/

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)

#if defined(__SNAND_VERSION2__)

/*-----------------------------------------------------
 * Included header files for common APIs
 *-----------------------------------------------------*/
#include "kal_general_types.h"
#include "reg_base.h"
#include "NAND_MTD_FDM50_internal.h"
#include "SPI_NAND_MTD_FDM50_internal.h"
#include "us_timer.h"

/*-----------------------------------------------------
 * Global definitions
 *-----------------------------------------------------*/
#define SNAND_SECTOR_SIZE           (512)
#define SNAND_SECTOR_SHIFT		    (9)

#if defined(MT6260)
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
    #define SPI_NAND_GPIO_MODE8         ((SNAND_P_U32)(GPIO_base + 0xc80))
    #define SPI_NAND_GPIO_MODE9         ((SNAND_P_U32)(GPIO_base + 0xc90))
    #define SPI_NAND_GPIO_MODE8_CLR     (0x00000077) //Clear mode setting of GPIO 66 to 71
    #define SPI_NAND_GPIO_MODE9_CLR     (0x77777770) //Clear mode setting of GPIO 72
    #define SPI_NAND_GPIO67             (0x00001000) //SFSWP
    #define SPI_NAND_GPIO68             (0x00010000) //SFSCS0
    #define SPI_NAND_GPIO69             (0x00100000) //SFSCK
    #define SPI_NAND_GPIO70             (0x01000000) //SFSIN
    #define SPI_NAND_GPIO71             (0x10000000) //SFSOUT
    #define SPI_NAND_GPIO72             (0x00000001) //SFSHOLD
#else
    #error define Type definition for each chip.
#endif

/*-----------------------------------------------------
 * Global variables
 *-----------------------------------------------------*/
kal_bool    g_bl_snand_init = KAL_FALSE;
kal_uint32  g_bl_snand_RW_CONFIG_HW_MISC2;
kal_uint32  g_bl_snand_RW_CONFIG_PDN_COND2;
kal_uint32  g_bl_snand_RW_GPIO_MODE[2];

/*-----------------------------------------------------
 * Function Declarations
 *-----------------------------------------------------*/
void bl_SNAND_WaitUS(kal_uint32 timeout_us);

/*-----------------------------------------------------
 * API bodies
 *-----------------------------------------------------*/
kal_uint32 bl_SNAND_ReverseByteOrder(kal_uint32 num)
{
   kal_uint32 ret = 0;

   ret |= ((num >> 24) & 0x000000FF);
   ret |= ((num >> 8)  & 0x0000FF00);
   ret |= ((num << 8)  & 0x00FF0000);
   ret |= ((num << 24) & 0xFF000000);

   return ret;
}

kal_uint32 bl_SNAND_GPRAM_Write_C1A3(const kal_uint32 cmd, const kal_uint32 address)
{
    return ((bl_SNAND_ReverseByteOrder(address) & 0xFFFFFF00) | (cmd & 0xFF));
}

/**
 * @brief This funciton enables MAC mode for issuing commands to serial flash.
 *
 * @remarks: !NOTE! This function must be used with bl_SNAND_MacTrigger in pair!
 */
void bl_SNAND_MacEnable(SNAND_Mode mode)
{
    int mac;

    mac = *RW_SNAND_MAC_CTL;

    // SPI
    if (SNAND_SPI == mode)
    {
        mac &= ~SNAND_MAC_SIO_SEL;   // Clear SIO_SEL to send command in SPI style
        mac |= SNAND_MAC_EN;         // Enable Macro Mode
    }
    // QPI
    else
    {
        /*
         * SFI V2: QPI_EN only effects direct read mode, and it is moved into DIRECT_CTL in V2
         *         There's no need to clear the bit again.
         */
        mac |= (SNAND_MAC_SIO_SEL | SNAND_MAC_EN);  // Set SIO_SEL to send command in QPI style, and enable Macro Mode
    }

    *RW_SNAND_MAC_CTL = mac;
}

/**
 * @brief This funciton triggers SFI to issue command to serial flash, wait SFI until ready.
 *
 * @remarks: !NOTE! This function must be used with bl_SNAND_MacEnable in pair!
 */
void bl_SNAND_MacTrigger(void)
{
    kal_uint32 mac;

    mac = *RW_SNAND_MAC_CTL;

    // Trigger SFI: Set TRIG and enable Macro mode
    mac |= (SNAND_TRIG | SNAND_MAC_EN);

    *RW_SNAND_MAC_CTL = mac;

    /*
     * Wait for SFI ready
     * Step 1. Wait for WIP_READY becoming 1 (WIP register is ready)
     */
    while (!(*RW_SNAND_MAC_CTL & SNAND_WIP_READY));

    /*
     * Step 2. Wait for WIP becoming 0 (Controller finishes command write process)
     */
    while (*RW_SNAND_MAC_CTL & SNAND_WIP);


}

/**
 * @brief This funciton leaves Macro mode and enters Direct Read mode
 *
 * @remarks: !NOTE! This function must be used after bl_SNAND_MacTrigger
 */
void bl_SNAND_MacLeave(void)
{
    kal_uint32 mac;

    // clear SF_TRIG and leave mac mode
    mac = *RW_SNAND_MAC_CTL;

    /*
     * Clear following bits
     * SF_TRIG: Confirm the macro command sequence is completed
     * SNAND_MAC_EN: Leaves macro mode, and enters direct read mode
     * SNAND_MAC_SIO_SEL: Always reset quad macro control bit at the end
     */
    mac &= ~(SNAND_TRIG | SNAND_MAC_EN | SNAND_MAC_SIO_SEL);
    *RW_SNAND_MAC_CTL = mac;
}

void bl_SNAND_Dev_Command(const kal_uint32 cmd, kal_uint8 outlen)
{
    *RW_SNAND_GPRAM_DATA = cmd;
    *RW_SNAND_MAC_OUTL = outlen;
    *RW_SNAND_MAC_INL = 0;
    bl_SNAND_MacEnable(SNAND_SPI);
    bl_SNAND_MacTrigger();
    bl_SNAND_MacLeave();

    return;
}

void bl_SNAND_Dev_Command_Ext(SNAND_Mode mode, const kal_uint8 cmd[], kal_uint8 data[], const kal_uint32 outl, const kal_uint32 inl)
{
    kal_uint32   tmp;
    kal_uint32   i, j;
    SNAND_P_U8  p_data, p_tmp;

    p_tmp = (SNAND_P_U8)(&tmp);

    // Moving commands into SFI GPRAM
    for (i = 0, p_data = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA); i < outl; p_data += 4)
    {
        // Using 4 bytes aligned copy, by moving the data into the temp buffer and then write to GPRAM
        for (j = 0, tmp = 0; i < outl && j < 4; i++, j++)
        {
            p_tmp[j] = cmd[i];
        }

        *p_data = tmp;
    }

    *RW_SNAND_MAC_OUTL = outl;
    *RW_SNAND_MAC_INL = inl;
    bl_SNAND_MacEnable(mode);
    bl_SNAND_MacTrigger();
    bl_SNAND_MacLeave();

    // for NULL data, this loop will be skipped
    for (i = 0, p_data = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA + outl); i < inl; ++i, ++data, ++p_data)
    {
        *data = *p_data;
    }

    return;
}

void bl_SNAND_GPRAM_Write(kal_uint32 gpram_offset, void* buff, kal_int32 length)
{
    kal_uint32 i;
    kal_uint8 *p_data=(kal_uint8*)buff;
    SNAND_Uint tmp;

    gpram_offset += (kal_uint32)RW_SNAND_GPRAM_DATA;

    // source address is 4-byte aligned, and gpram_offset is 4-bytes aligned, too
    if (0 == ((kal_uint32)buff & 0x3))    {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            SNAND_WriteReg32(gpram_offset, *(kal_uint32*)p_data);
        }
    }
    // source address is 2-byte aligned
    else if (0 == ((kal_uint32)p_data & 0x1))     {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            tmp.u16[0]=*(kal_uint16*)p_data;
            tmp.u16[1]=*((kal_uint16*)p_data + 1);
            SNAND_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
    // source data is NOT 2-byte aligned
    else    {
        for (;length > 0; gpram_offset+=4, length-=4)  {
            for (i=0; i<4 && i<length; i++) {
                tmp.u8[i]=*p_data++;
            }
            SNAND_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
}

kal_uint32 bl_SNAND_Util_GetTimeUS(void)
{
    return ust_get_current_time();
}

kal_bool bl_SNAND_Util_IsTimeout(kal_uint32 start_us, kal_uint32 timeout_us)
{
    register kal_uint32 cur_us;

    // get current tick
    cur_us = bl_SNAND_Util_GetTimeUS();

    // check if timeout
    if (ust_get_duration(start_us, cur_us) >= timeout_us)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void bl_SNAND_Reset(kal_uint32 rst_flag)
{
    kal_uint8       cmd = SNAND_CMD_SW_RESET;
    kal_bool        bTimeout;
    kal_uint32      reg;
    kal_uint32      start_tick;

    if (rst_flag & SNAND_RST_WAIT_READY)
    {
        // wait for NFI Master Status being cleared

        start_tick = bl_SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            reg = *RW_NFI_MASTERSTA;

            if (0 == (reg & NFI_MASTERSTA_MASK))
            {
                break;
            }

            bTimeout = bl_SNAND_Util_IsTimeout(start_tick, NFI_MAX_RESET_US);
        }
    }
    else if (rst_flag & SNAND_RST_CON)    // include NFI & SNF
    {
        //------ Part 1. NFI

        // 1-1. wait for NFI Master Status being cleared

        start_tick = bl_SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            reg = *RW_NFI_MASTERSTA;

            if (0 == (reg & NFI_MASTERSTA_MASK))
            {
                break;
            }

            bTimeout = bl_SNAND_Util_IsTimeout(start_tick, NFI_MAX_RESET_US);
        }

        // 1-2. reset NFI State Machine and Clear FIFO Counter

        *RW_NFI_CON = (NFI_FIFO_FLUSH | NFI_RST);

        // 1-3. wait for NAND Interface & NFI Internal FSM being reset

        start_tick = bl_SNAND_Util_GetTimeUS();

        while (1)
        {
            reg = *RW_NFI_STA;

            if (0 == (reg & (NFI_STA_NFI_FSM_MASK | NFI_STA_NAND_FSM_MASK)))
            {
                break;
            }

            bTimeout = bl_SNAND_Util_IsTimeout(start_tick, NFI_MAX_RESET_US);
        }

        //------ Part  2. SNF: trigger SW_RST bit to reset state machine

        reg = *RW_SNAND_MISC_CTL;
        reg |= SNAND_SW_RST;
        *RW_SNAND_MISC_CTL = reg;
        reg &= ~SNAND_SW_RST;
        *RW_SNAND_MISC_CTL = reg;
    }
    else if (rst_flag & SNAND_RST_DEV)
    {
        // issue SW RESET command to device
        bl_SNAND_Dev_Command_Ext(SNAND_SPI, &cmd, NULL, 1, 0);

        // wait for awhile, then polling status register (required by spec)
        bl_SNAND_WaitUS(SPI_NAND_RESET_LATENCY_US);

        // polling status register
        start_tick = bl_SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            bl_SNAND_MacEnable(SNAND_SPI);
            bl_SNAND_MacTrigger();
            bl_SNAND_MacLeave();

            cmd = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

            if (0 == (cmd & SNAND_STATUS_OIP))
            {
                break;
            }

            bTimeout = bl_SNAND_Util_IsTimeout(start_tick, SPI_NAND_RESET_LATENCY_US);
        }
    }
}

kal_uint8 bl_SNAND_GPIO_Setting(void)
{
    kal_uint8 CS_num = 1;

    #if defined(MT6260)
    {
        // GPIO registers
        #define SPI_NAND_GPIO_MODE8         ((SNAND_P_U32)(GPIO_base + 0xc80))
        #define SPI_NAND_GPIO_MODE9         ((SNAND_P_U32)(GPIO_base + 0xc90))
        #define SPI_NAND_GPIO_MODE8_CLR     (0x00000077) //Clear mode setting of GPIO 66 to 71
        #define SPI_NAND_GPIO_MODE9_CLR     (0x77777770) //Clear mode setting of GPIO 72
        #define SPI_NAND_GPIO67             (0x00001000) //SFSWP
        #define SPI_NAND_GPIO68             (0x00010000) //SFSCS0
        #define SPI_NAND_GPIO69             (0x00100000) //SFSCK
        #define SPI_NAND_GPIO70             (0x01000000) //SFSIN
        #define SPI_NAND_GPIO71             (0x10000000) //SFSOUT
        #define SPI_NAND_GPIO72             (0x00000001) //SFSHOLD

        // B-1. SPI_NAND_GPIO_MODE8
        *SPI_NAND_GPIO_MODE8 = (*SPI_NAND_GPIO_MODE8 & SPI_NAND_GPIO_MODE8_CLR) | SPI_NAND_GPIO67 | SPI_NAND_GPIO68 | SPI_NAND_GPIO69 | SPI_NAND_GPIO70 | SPI_NAND_GPIO71;

        // B-2. SPI_NAND_GPIO_MODE9
        *SPI_NAND_GPIO_MODE9 = (*SPI_NAND_GPIO_MODE9 & SPI_NAND_GPIO_MODE9_CLR) | SPI_NAND_GPIO72;
    }
    #else
        #error "Please define bl_SNAND_GPIO_Setting!"
    #endif

    return CS_num;
}

void bl_SNAND_Init_Custom(kal_bool enable)
{
#if defined(MT6260)
    {
        kal_uint32 reg;

        if (KAL_TRUE == enable)
        {
            //-- 1. disable clock gating (turn-on SPI-NAND controller)
            g_bl_snand_RW_CONFIG_PDN_COND2 = *RW_CONFIG_PDN_COND2;

            if (1 == (g_bl_snand_RW_CONFIG_PDN_COND2 & PDN_SPI_NAND_CG))   // if clock is gated-off originally, turn-on the clock, else do nothing
            {
                *RW_CONFIG_PDN_CLRD2 = PDN_SPI_NAND_CG;
            }

            //-- 2. config pad macro
            reg = g_bl_snand_RW_CONFIG_HW_MISC2 = *RW_CONFIG_HW_MISC2;
            reg = (reg & ~CONFIG_PAD_MACRO) | CONFIG_PAD_MACRO_SNAND;
            *RW_CONFIG_HW_MISC2 = reg;

            //-- 3. config GPIO

            // A. Keep original GPIO modes
            g_bl_snand_RW_GPIO_MODE[0] = *SPI_NAND_GPIO_MODE8;
            g_bl_snand_RW_GPIO_MODE[1] = *SPI_NAND_GPIO_MODE9;

            // B. Set GPIO to SPI-NAND

            // B-1. SPI_NAND_GPIO_MODE8
            *SPI_NAND_GPIO_MODE8 = (g_bl_snand_RW_GPIO_MODE[0] & SPI_NAND_GPIO_MODE8_CLR) | SPI_NAND_GPIO67 | SPI_NAND_GPIO68 | SPI_NAND_GPIO69 | SPI_NAND_GPIO70 | SPI_NAND_GPIO71;

            // B-2. SPI_NAND_GPIO_MODE9
            *SPI_NAND_GPIO_MODE9 = (g_bl_snand_RW_GPIO_MODE[1] & SPI_NAND_GPIO_MODE9_CLR) | SPI_NAND_GPIO72;
        }
        else
        {
            // 3. restore GPIO
            *SPI_NAND_GPIO_MODE8 = g_bl_snand_RW_GPIO_MODE[0];
            *SPI_NAND_GPIO_MODE9 = g_bl_snand_RW_GPIO_MODE[1];

            // 2. restore pad macro
            *RW_CONFIG_HW_MISC2 = g_bl_snand_RW_CONFIG_HW_MISC2;

            // 1. restore clock gating (turn-off SPI-NAND controller)
            reg = *RW_CONFIG_PDN_SETD2;

            if (1 == (g_bl_snand_RW_CONFIG_PDN_COND2 & PDN_SPI_NAND_CG))   // if clock is gated-off originally, turn-off the clock, else do nothing
            {
                reg = *RW_CONFIG_PDN_SETD2;
                reg |= PDN_SPI_NAND_CG;
                *RW_CONFIG_PDN_SETD2 = reg;
            }
        }
    }
#else
    #error Please define bl_SNAND_Init_Custom() function!
#endif

}

void bl_SNAND_WaitUS(kal_uint32 timeout_us)
{
    ust_busy_wait(timeout_us);
}

void bl_SNAND_Init()
{
    if (KAL_TRUE == g_bl_snand_init)
    {
        return;
    }

    // wait for NFI ready
    bl_SNAND_Reset(SNAND_RST_WAIT_READY);

    // reset controller
    bl_SNAND_Reset(SNAND_RST_CON);

    // init custom configurations
    bl_SNAND_Init_Custom(KAL_TRUE);

    // Ignore turn-on device ECC because device ECC should be enabled by BootROM before

    // reset device
    bl_SNAND_Reset(SNAND_RST_DEV);

    bl_SNAND_Reset(SNAND_RST_CON);

    g_bl_snand_init = KAL_TRUE;
}

void bl_SNAND_COMMON_ReadID(kal_uint8 id[])
{
    kal_uint8 cmd = SNAND_CMD_READ_ID;

    bl_SNAND_Dev_Command_Ext(SNAND_SPI, &cmd, id, 1, SNAND_FLASH_ID_LENGTH + 1);
}



#if defined(__NFI_SHARED_DRV__)

/*-----------------------------------------------------
 * Definitions
 *-----------------------------------------------------*/
/* Macros for register read/write */
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg16(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))

/**********************************************************
Description : NFI_ReadID
Remark      : content in
              NFI_PAGEFMT, NFI_CNFG, NFI_ADDRNOB, NFI_CON,
              NFI_COLADDR, and NFI_ROWADDR will be changed
***********************************************************/
void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data)
{
    kal_uint8  id_data_local[SNAND_FLASH_ID_LENGTH + 1];

    bl_SNAND_Init();

    // read ID
    bl_SNAND_COMMON_ReadID(id_data_local);

    id_data[0] = id_data_local[1];
    id_data[1] = id_data_local[2];
    id_data[2] = 0;
    id_data[3] = 0;
    id_data[4] = 0;
    id_data[5] = 0;
    id_data[6] = 0;
    id_data[7] = 0;
}
#else //__USE_NFI_SHARED_DRV__

#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"
#include <bl_loader.h>
#include "sw_types.h"
#include "nfb_header.h"
#include "fs_errcode.h"

/* Macros for register read/write */
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg16(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)             (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)              (*(volatile kal_uint8 *)(addr))

typedef enum {
   ECC_DEC_DETECT,
   ECC_DEC_LOCATE,
   ECC_DEC_CORRECT,
   ECC_DEC_NONE
} ECC_Decode_Type_t;

typedef enum {
   ECC_4_BITS,
   ECC_6_BITS,
   ECC_8_BITS,
   ECC_10_BITS,
   ECC_12_BITS,
   NUM_OF_ECC
} ECC_Level_t;

typedef enum
{
   NFI_ECC_CORRECTED      = 0xD0,
   NFI_OPERATION_SUCCESS  = 0xE0,
   NFI_BAD_BLOCK          = 0xF0,
   NFI_ECC_UNCORRECT      = 0xF1,
   NFI_ECC_TIMEOUT        = 0xF2,
   NFI_CMD_TIMEOUT        = 0xF3,
   NFI_ADDR_TIMEOUT       = 0xF4,
   NFI_DATA_TIMEOUT       = 0xF5,
   NFI_PROG_TIMEOUT       = 0xF6,
   NFI_BLOCKERASE_TIMEOUT = 0xF7,
   NFI_READ_TIMEOUT       = 0xF8,
   NFI_RESET_TIMEOUT      = 0xF9,
   NFI_PROG_FAILED        = 0xFA,
   NFI_BLOCKERASE_FAILED  = 0xFB
} NFI_Error_Code;

typedef struct {
   bool   nfi_hw_ecc;
   bool   nfi_auto_fmt;
   bool   nfi_ahb_mode;
   kal_uint32    nfi_page_size;
   kal_uint32    nfi_spare_size;
   kal_uint32    nfi_block_size;   /* in pages, 32, 64, 128 */
   kal_uint32    nfi_fdm_size;
   kal_uint32    nfi_sector_num;
   kal_uint32    nfi_data_sectors;
   kal_uint32    nfi_col_num;
   kal_uint32    nfi_row_num;
   kal_uint32    nfi_io_width;
} NFI_Config_st;

typedef struct {
   ECC_Decode_Type_t ecc_dec_op;
   ECC_Level_t       ecc_level;
   kal_uint32               ecc_msg_size; /* in bits */
} ECC_conf_st;

#define NAND_MAX_SECOTR_NUM        (8)
#define NAND_MAX_ERROR_LOCATION   (6)

NFI_Config_st 	BL_nfi_cfg;
ECC_conf_st   	BL_ecc_cfg;
kal_uint32  			nfi_meta_val[2];
kal_uint32  			nfi_ecc_err_location[NAND_MAX_SECOTR_NUM][NAND_MAX_ERROR_LOCATION];

extern BOOTL_HEADER  BLHeader;

/**********************************************************
Description : BL_NFI_Reset
Remark      :
***********************************************************/
void BL_NFI_Reset(void)
{
    bl_SNAND_Reset(SNAND_RST_CON);
}

/**********************************************************
Description : NFI_Config
***********************************************************/
void NFI_Config(const NFI_MENU *input, const NFI_SUBMENU* sub_para)
{
    U16 reg_val = 0;

    switch(input->pageSize)
    {
        case 2048:
            BL_nfi_cfg.nfi_col_num = 2;
            BL_nfi_cfg.nfi_row_num = input->addressCycle-2;
            reg_val |= PAGEFMT_2K;
            break;
    }

    BL_nfi_cfg.nfi_page_size = input->pageSize;
    BL_nfi_cfg.nfi_sector_num = BL_nfi_cfg.nfi_page_size >> SNAND_SECTOR_SHIFT;
    BL_nfi_cfg.nfi_block_size = sub_para->blockSize;
}

/**********************************************************
Description : NFI_Read
Remark      : Must be page alignment.
***********************************************************/

NFI_Error_Code NFI_Read(kal_uint32 row_addr, kal_uint32 col_addr, P_U32 main_buff, P_U32 spare_buff)
{
    NFI_Error_Code  status          = NFI_OPERATION_SUCCESS;
    kal_uint32             polling_times;
    kal_uint32             reg;
    kal_uint32             col_addr_local;
    P_U8            pSpareSrc, pSpareDst;
    kal_uint32             len_to_read;
    U8              cmd_random_read;
    U8              snf_data_read_mode;

    len_to_read = BL_nfi_cfg.nfi_page_size + BL_nfi_cfg.nfi_spare_size * BL_nfi_cfg.nfi_data_sectors;

    cmd_random_read = SNAND_CMD_RANDOM_READ_SPIQ;

    snf_data_read_mode = SNAND_DATA_READ_MODE_X4;

    //------ SNF Part ------

    // set PAGE READ command & address
    reg = (SNAND_CMD_PAGE_READ << SNAND_PAGE_READ_CMD_OFFSET) | (row_addr & SNAND_PAGE_READ_ADDRESS_MASK);
    *RW_SNAND_RD_CTL1 = reg;

    // set DATA READ dummy cycle and command (use default value, ignored)
    reg = *RW_SNAND_RD_CTL2;
    reg &= ~SNAND_DATA_READ_CMD_MASK;
    reg |= cmd_random_read & SNAND_DATA_READ_CMD_MASK;
    *RW_SNAND_RD_CTL2 = reg;

    // set DATA READ address
    *RW_SNAND_RD_CTL3 = (col_addr_local & SNAND_DATA_READ_ADDRESS_MASK);

    // set SNF data length
    reg = len_to_read | (len_to_read << SNAND_PROGRAM_LOAD_BYTE_LEN_OFFSET);
    *RW_SNAND_MISC_CTL2 = reg;

    // set SNF timing
    reg = *RW_SNAND_MISC_CTL;

    reg &= ~SNAND_FIFO_RD_LTC_MASK;
    reg |= ((SNAND_FIFO_RD_LTC_0 << SNAND_FIFO_RD_LTC_OFFSET) & SNAND_FIFO_RD_LTC_MASK);

    reg &= ~SNAND_DATA_READ_MODE_MASK;
    reg |= (snf_data_read_mode << SNAND_DATA_READ_MODE_OFFSET);

    reg &= ~SNAND_PG_LOAD_X4_EN;    // dummy operation?

    *RW_SNAND_MISC_CTL = reg;

    //------ NFI Part ------

    // reset NFI
    bl_SNAND_Reset(SNAND_RST_CON);

    // set NFI page format
    reg = NFI_PAGE_SIZE_2K;
    SNAND_WriteReg16(RW_NFI_PAGEFMT, reg);

    reg = NFI_SPIDMA_SEC_EN | (len_to_read & NFI_SPIDMA_SEC_SIZE_MASK);
    *RW_NFI_SPIDMA = reg;

    // set NFI buffer address
    *RW_NFI_STRADDR = (kal_uint32)main_buff;

    // set NFI configurations
    reg = (NFI_OP_MODE_CUSTOM_PROCESS << NFI_OP_MODE_OFFSET) | NFI_DMA_MODE | NFI_DMA_BURST_EN | (NFI_READ_MODE_FLASH_TO_RAM << NFI_READ_MODE_OFFSET);
    *RW_NFI_CNFG = reg;

    // set dummy command to trigger NFI enter custom mode
    *RW_NFI_CMD = NFI_CMD_DUMMY_RD;

    // trigger data transfer
    reg = *RW_NFI_CON;
    reg = (1 << NFI_SEC_NUM_OFFSET) | NFI_BRD;
    *RW_NFI_CON = reg;

    for (polling_times = 1;;polling_times++)
    {
        reg = *RW_SNAND_STA_CTL1;

        if ((reg & SNAND_AUTO_READ) == 0)
        {
            continue;
        }
        else
        {
            reg = *RW_SNAND_GF_CTL1 & SNAND_GF_STATUS_MASK;

            if (SNAND_STATUS_TOO_MANY_ERROR_BITS == (reg & SNAND_STATUS_ECC_STATUS_MASK))
            {
                status = NFI_ECC_UNCORRECT;
            }

            break;
        }
    }

    // clear trigger bit
    reg = *RW_NFI_CON;
    reg &= ~NFI_BRD;
    *RW_NFI_CON = reg;

    // set 1 then set 0 to clear done flag
    reg = *RW_SNAND_STA_CTL1;
    *RW_SNAND_STA_CTL1 = SNAND_AUTO_READ;
    *RW_SNAND_STA_CTL1 = 0;

    // handle spare area (FDM data)
    if (spare_buff)
    {
        pSpareSrc = (P_U8)(main_buff + (BL_nfi_cfg.nfi_page_size / sizeof(kal_uint32)));
        pSpareDst = (P_U8)spare_buff;

        for (polling_times = 0; polling_times < BL_nfi_cfg.nfi_data_sectors; polling_times++)
        {
            for(reg = 0; reg < BL_nfi_cfg.nfi_fdm_size; reg++)
            {
                *(pSpareDst + polling_times * BL_nfi_cfg.nfi_fdm_size + reg) = *(pSpareSrc + polling_times * BL_nfi_cfg.nfi_spare_size + reg);
            }
        }
    }

    return status;
}

NFI_Error_Code  NFI_SectorRead(kal_uint32 page_index, kal_uint32 offset, kal_uint32 sectors, P_U32 sector_buff, P_U32 spare_buff, bool ahb_mode, bool hw_ecc, bool auto_fmt)
{
    NFI_Error_Code      status      = NFI_OPERATION_SUCCESS;

    BL_nfi_cfg.nfi_data_sectors = sectors;

    status = NFI_Read(page_index, offset, sector_buff, spare_buff);

    return status;
}

/**********************************************************
Description : NFI_PageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
#ifdef __EXT_BOOTLOADER__

_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length,
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize,
                       kal_bool ECC, kal_bool continous)
{
    kal_uint32 block;
    kal_uint32 page;
    kal_int32 retVal;

    if (BLHeader.NFIinfo.addressCycle > 4)
    {
        block = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))/BLHeader.pagesPerBlock;
        page = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))%BLHeader.pagesPerBlock;
    }
    else
    {
        block = (addr1>>(BLHeader.pageShift))/BLHeader.pagesPerBlock;
        page = (addr1>>(BLHeader.pageShift))%BLHeader.pagesPerBlock;
    }

    if (length == pageSize)
    {
        retVal = NFB_ReadPhysicalPage(block, page, destination);
    }
    else
    {
        dbg_print("[Error] NFI_PageRead with length != pageSize\n\r");
        retVal = -1;
    }

    if (retVal >= 0)
        return NFI_SUCCESS;
    else
        return NFI_GENERAL_ERR;

}

#endif /* __EXT_BOOTLOADER__ */

/**********************************************************
Description : NFI_BitOneCount
Input         : NFI_MENU, baseaddr must be page alignment
Output        : kal_uint32 return data
***********************************************************/
kal_uint32 NFI_BitOneCount(kal_uint32 val, kal_uint32 len)
{
    kal_uint32  idx = 0;
    kal_uint32  num = 0;

    for(idx = 0 ; idx < len ; idx++)
    {
        if( (val>>idx) & 0x1 )
            num++;
    }

    return num;
}

/**********************************************************
Description : NFI_CheckGoodBlock
Input         : NFI_MENU, baseaddr must be page alignment
Output        : kal_uint32 return data
                +--------------------+---+----------+
                | Sector (512 bytes) | B | 15 bytes |
                +--------------------+---+----------+
***********************************************************/
#define MAX_SPARE_SIZE 8
#define NAND_BAD_MARK_SPARE_OFFSET (0)
#define NAND_GOOD_BLOCK_THRESHOLD  (7)

kal_uint32 block_check_page_buff[SNAND_SECTOR_SIZE >> 2];

NFI_Error_Code NFI_CheckGoodBlock(kal_uint32 block_no)
{
    kal_uint32            block_check_tmp_spare[MAX_SPARE_SIZE];
    kal_uint32            page_idx = 0;
    kal_uint32            tmp_val  = 0;
    P_U8           byte_ptr = (P_U8)block_check_tmp_spare;
    NFI_Error_Code status = NFI_OPERATION_SUCCESS;

    /* check 1st and 2nd page */
    for(page_idx = 0 ; page_idx < 2 ; page_idx++)
    {
        for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_sector_num ; tmp_val++)
        {
            status = NFI_SectorRead(page_idx+block_no*BL_nfi_cfg.nfi_block_size, tmp_val*(SNAND_SECTOR_SIZE+BL_nfi_cfg.nfi_spare_size), 1, block_check_page_buff, block_check_tmp_spare, KAL_FALSE, KAL_TRUE, KAL_TRUE);

            if(status > NFI_ECC_TIMEOUT)
            {
                break;
            }

            if(NFI_BitOneCount(byte_ptr[NAND_BAD_MARK_SPARE_OFFSET], 8) < NAND_GOOD_BLOCK_THRESHOLD)
            {
                return NFI_BAD_BLOCK;
            }
        }
    }

    return status;
}


/**********************************************************
Description : NFIReconfigure
Input       : NO
Output      : NO
***********************************************************/
void NFIReconfigure(void)
{
    bl_SNAND_Init();

	BL_NFI_Reset();
}

/**********************************************************
Description : GoodBlockChecking
Input       : NFI_MENU, NFIReadPtr must be page alignment
Output      : TRUE, good block, FALSE, bad block
***********************************************************/
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2)
{
	kal_uint32 block_no;

    if ( input->addressCycle > 4) {
        block_no = ((addr2<<16)|(addr1>>(BLHeader.pageShift)))/BLHeader.pagesPerBlock;
    } else {
        block_no = (addr1>>(BLHeader.pageShift))/BLHeader.pagesPerBlock;
    }

	if (NFI_CheckGoodBlock(block_no) != NFI_BAD_BLOCK) {
		return KAL_TRUE;
	} else {
		return KAL_FALSE;
	}
}

#ifdef __EXT_BOOTLOADER__

void NFIReconfigure2(void)  // init API for ext-bootloader
{
    kal_int32 NFBStatus = -1;

    NFBStatus = DAL_init();

    if ( NFBStatus != FS_NO_ERROR )
    {
        dbg_print("[NFIReconfigure] DAL_init fail\n");
        while (1);
    }
}

#endif /* __EXT_BOOTLOADER__ */

// Return value :
//	 0 - Good block.
//	-1 - Bad block
kal_int32 NFB_CheckGoodBlock_NoTT(kal_uint32 Block)
{
	if (NFI_CheckGoodBlock(Block) != NFI_BAD_BLOCK) {
		return 0;
	} else {
		return -1;
	}
}

/**********************************************************
Description : NFI_PhyPageRead
Input       : .......
Output      : _RET_CODE
Remark      : Must be page alignment
***********************************************************/
_RET_CODE NFI_PhyPageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length,
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize,
                       kal_bool ECC, kal_bool continous)
{
    kal_uint32 row_addr;
    NFI_Error_Code  status        = NFI_OPERATION_SUCCESS;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        row_addr = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        row_addr = addr1 >> (BLHeader.pageShift);
    }

	status = NFI_Read(row_addr, 0, destination, parity);

    if(status>NFI_OPERATION_SUCCESS)
    {
    	return NFI_GENERAL_ERR;
    }
    else
    {
        return NFI_SUCCESS;
    }
}

kal_int32 NFB_ReadPhysicalPageWithSpare_NoTT(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint32 *Data, kal_uint32 *Spare)
{
   	kal_uint32 addr1, addr2;

	PhyPage += (PhyBlock << (BLHeader.blockShift - PAGE_SHIFT));
	addr1 = (kal_uint32)(PhyPage << PAGE_SHIFT);
	addr2 = 0;

	if (BLHeader.NFIinfo.addressCycle>4) {
		// Seems only in 2KB page size case.
		addr2 = (kal_uint32)(PhyPage >> PAGE_SHIFT);
   	}

	return NFI_PhyPageRead(Data, Spare, BLHeader.NFIinfo.pageSize, BLHeader.NFIinfo.addressCycle, addr1, addr2,
			BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_FALSE);
}

/**********************************************************
Description : NFI_ReadID
Remark      : content in
              NFI_PAGEFMT, NFI_CNFG, NFI_ADDRNOB, NFI_CON,
              NFI_COLADDR, and NFI_ROWADDR will be changed
***********************************************************/
void NFI_ReadID(kal_uint32 id_num, kal_uint8* id_data)
{
    kal_uint8  id_data_local[SNAND_FLASH_ID_LENGTH + 1];

    NFIReconfigure();

    // read ID
    bl_SNAND_COMMON_ReadID(id_data_local);

    id_data[0] = id_data_local[1];
    id_data[1] = id_data_local[2];
    id_data[2] = 0;
    id_data[3] = 0;
    id_data[4] = 0;
    id_data[5] = 0;
    id_data[6] = 0;
    id_data[7] = 0;
}

#if defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)

// TODO: Need porting this test APIs
/**********************************************************
Description : NFI_ReadStatus
Input       : None
Output      : None
***********************************************************/
U8 NFI_ReadStatus(void)
{
    U8     status  = 0xFF;
    kal_uint32    timeout = NORMAL_BUSY_PERIOD;

    BL_NFI_Reset();

    DRV_WriteReg(NFI_CNFG, BL_SRD_CNFG);

    DRV_WriteReg(NFI_CMD, RD_STATUS_CMD);
    while ( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout));

    if(timeout)
    {
        DRV_WriteReg(NFI_CON, (1 << CON_NFI_NOB_SHIFT)|CON_NFI_SRD);

        while ( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout));

        if(timeout)
        {
            status = DRV_Reg32(NFI_DATAR);
        }
        /* clear NOB */
        DRV_WriteReg(NFI_CON, 0);
    }

    return status;
}

/**********************************************************
Description : NFI_PageWrite
Remark      : Must be page alignment.
              Both HW_ECC and AUTO_FMT have to be set to
              append ECC parity
***********************************************************/
NFI_Error_Code NFI_PageWrite(kal_uint32 page_index, kal_uint32 col_addr, P_U32 main_buff, P_U32 spare_buff, kal_bool hw_ecc, kal_bool auto_fmt, kal_bool ahb_mode)
{
    NFI_Error_Code  status     = NFI_OPERATION_SUCCESS;
    kal_uint32              idx       = 0;
    kal_uint32             reg_val   = 0;
    kal_uint32             tmp_val   = 0;
    kal_uint32             timeout   = 0;
    P_U8            byte_ptr  = NULL;
    P_U8            spare_ptr = NULL;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;
    BL_nfi_cfg.nfi_hw_ecc = hw_ecc;
    BL_nfi_cfg.nfi_auto_fmt = auto_fmt;
    BL_nfi_cfg.nfi_ahb_mode = ahb_mode;

    BL_NFI_Reset();

    reg_val = BL_WRITE_CNFG;

    /* copy FDM neta data */
    if(spare_buff)
        spare_ptr = (P_U8)spare_buff;
    else
        spare_ptr = (P_U8)((kal_uint32)main_buff+BL_nfi_cfg.nfi_page_size);

    if(BL_nfi_cfg.nfi_auto_fmt)
    {
        byte_ptr  = (P_U8)nfi_meta_val;
        for(tmp_val = 0 ; tmp_val < BL_nfi_cfg.nfi_sector_num ; tmp_val++)
        {
            for(idx = 0 ; idx < BL_nfi_cfg.nfi_fdm_size ; idx++)
            {
                *(byte_ptr+idx) = *(spare_ptr+idx+BL_nfi_cfg.nfi_fdm_size*tmp_val);
            }
            for(; idx < (8-BL_nfi_cfg.nfi_fdm_size) ; idx++)
            {
                *(byte_ptr+idx) = 0xFF;
            }
            DRV_WriteReg32(NFI_FDM0L+(tmp_val<<1), nfi_meta_val[0]);
            DRV_WriteReg32(NFI_FDM0L+(tmp_val<<1)+1, nfi_meta_val[1]);
        }
    }

    /* configure data source address */
    DRV_WriteReg32(NFI_STRADDR, (kal_uint32)main_buff);

    /* configure ECC */
    /* NOTE: only following setting are supported
     *       spare size    ECC capability
     *          16 bytes      8 bit
     *          26 bytes     12 bit
     */
    if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
    {
        timeout = NORMAL_BUSY_PERIOD;
        reg_val |= CNFG_HW_ECC_EN;
        /* enable ECC encoder */
        tmp_val = DRV_Reg32(ECC_ENCCNFG);
        tmp_val |= ECC_CNFG_NFI;
        DRV_WriteReg32(ECC_ENCCNFG, tmp_val);
        //WAIT_ENC_READY
        //START_ECC_ENC
        WAIT_ENC_READY_WITH_TIMEOUT(timeout);
        STOP_ECC_ENC
        START_ECC_ENC
    }

    /* data size to be transfered and AUTO_FMT setting */
    tmp_val = BL_nfi_cfg.nfi_data_sectors<<NAND_SECTOR_SHIFT;
    if(!BL_nfi_cfg.nfi_auto_fmt)
        tmp_val += BL_nfi_cfg.nfi_spare_size*BL_nfi_cfg.nfi_data_sectors;
    else
        reg_val |= CNFG_AUTO_FMT_EN;

    if(BL_nfi_cfg.nfi_ahb_mode)
        reg_val |= CNFG_AHB;

    if(tmp_val&0x3)
    {
        reg_val |= CNFG_BYTE_RW;
    }
    else
    {
        tmp_val >>= 2;
    }

    DRV_WriteReg(NFI_CNFG, reg_val);

    /* issue data input command and address cycles */
    DRV_WriteReg(NFI_CMD, INPUT_DATA_CMD);
    timeout = NORMAL_BUSY_PERIOD;
    while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );

    if(timeout)
    {
        DRV_WriteReg32(NFI_COLADDR, col_addr);
        DRV_WriteReg32(NFI_ROWADDR, page_index);
        reg_val = BL_nfi_cfg.nfi_col_num|(BL_nfi_cfg.nfi_row_num << ADDR_ROW_NOB_SHIFT);
        DRV_WriteReg(NFI_ADDRNOB, reg_val);
        timeout = NORMAL_BUSY_PERIOD;
        while( (DRV_Reg32(NFI_STA) & STA_ADDR_STATE) && (--timeout));

        if(timeout)
        {
            /* transfer data */
            reg_val = CON_NFI_BWR | (BL_nfi_cfg.nfi_data_sectors << CON_NFI_SEC_SHIFT);
            DRV_WriteReg(NFI_CON, reg_val);
            if(BL_nfi_cfg.nfi_ahb_mode)
            {
                timeout = DATA_TRANSFER_PERIOD;
                while( (ADDRCNTR_CNTR(DRV_Reg(NFI_ADDRCNTR)) < BL_nfi_cfg.nfi_data_sectors) && (--timeout));
            }
            else
            {
                if(DRV_Reg(NFI_CNFG) & CNFG_BYTE_RW)
                {
                    byte_ptr = (P_U8)main_buff;
                    for(idx = 0 ; idx < tmp_val ; idx++)
                    {
                        timeout = NORMAL_BUSY_PERIOD;
                        while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
                        if(timeout)
                        {
                            DRV_WriteReg32(NFI_DATAW, *(byte_ptr++));
                        }
                        else
                            break;
                    }
                }
                else
                {
                    for(idx = 0 ; idx < tmp_val ; idx++)
                    {
                        timeout = NORMAL_BUSY_PERIOD;
                        while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
                        if(timeout)
                        {
                            DRV_WriteReg32(NFI_DATAW, *(main_buff++));
                        }
                        else
                            break;
                    }
                }
                if(timeout)
                {
                    timeout = NORMAL_BUSY_PERIOD;
                    NFI_WAIT_TRANSFER_DONE(BL_nfi_cfg.nfi_data_sectors, timeout);
                }
            }

            /* stop ECC encoder */
            if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
            {
               if(timeout)
               {
                  timeout = NORMAL_BUSY_PERIOD;
                  WAIT_ENC_READY_WITH_TIMEOUT(timeout);
               }
               //reg_val = CON_FIFO_FLUSH;
               //DRV_WriteReg(NFI_CON, reg_val);
               if(timeout)
               {
                   timeout = NORMAL_BUSY_PERIOD;
                   while( !FIFO_PIO_READY(*NFI_PIO_DIRDY) && (--timeout) );
               }
               STOP_ECC_ENC
            }

            if(timeout)
            {
                /* issue program command */
                DRV_WriteReg(NFI_CMD, PROG_DATA_CMD);
                timeout = NORMAL_BUSY_PERIOD;
                while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout));

                if(timeout)
                {
                    /* wait for device returning ready */
                    timeout = PROG_BUSY_PERIOD;
                    do
                    {
                        tmp_val = NFI_ReadStatus();
                        if(tmp_val&DEVICE_READY)
                            break;
                        else
                            timeout--;
                    }while(timeout);
                    if(0 == timeout)
                        status = NFI_PROG_TIMEOUT;
                }
                else
                    status = NFI_CMD_TIMEOUT;
            }
            else
            {
                status = NFI_DATA_TIMEOUT;
            }
        }
        else
        {
            status = NFI_ADDR_TIMEOUT;
        }
    }
    else
    {
        status = NFI_CMD_TIMEOUT;
    }

    /* stop ECC encoder */
    if(BL_nfi_cfg.nfi_hw_ecc & BL_nfi_cfg.nfi_auto_fmt)
    {
        if( (NFI_CMD_TIMEOUT == status) || (NFI_ADDR_TIMEOUT == status) )
           STOP_ECC_ENC
    }

    /* check operation status */
    if( (NFI_OPERATION_SUCCESS == status) && (tmp_val&OPERATION_FAIL) )
        status = NFI_PROG_FAILED;

    return status;
}

void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize)
{
	kal_uint8 BitNo, Sector, Mask;
	kal_uint32 Offset, MagicNum;
	kal_bool EmulatedBitError;
	kal_uint8 *Ptr = (kal_uint8 *)destination;
	kal_uint32 page_index;
    NFI_Error_Code  NFIStatus = NFI_OPERATION_SUCCESS;
    kal_uint32 row_addr, reg_val;

    BL_nfi_cfg.nfi_data_sectors = BL_nfi_cfg.nfi_sector_num;
    BL_nfi_cfg.nfi_hw_ecc = KAL_TRUE;
    BL_nfi_cfg.nfi_auto_fmt = KAL_FALSE;
    BL_nfi_cfg.nfi_ahb_mode = KAL_FALSE;

    reg_val = DRV_Reg32(ECC_DECCNFG);
    if(BL_nfi_cfg.nfi_ahb_mode)
    {
        /* configure ECC to do correction */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_CORRECT;
    }
    else
    {
        /* configure ECC to output error location */
        reg_val &= ~(DEC_CNFG_TYPE_MASK);
        reg_val |= DEC_CNFG_EL;
    }
    DRV_WriteReg32(ECC_DECCNFG, reg_val);

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        row_addr = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        row_addr = addr1 >> (BLHeader.pageShift);
    }

	NFIStatus = NFI_Read(row_addr, 0, destination, parity);

	if (NFIStatus != NFI_OPERATION_SUCCESS) {
		dbg_print(" Original data has error. No need to emulate bit error. status=%x \n\r", NFIStatus);
		return;
	}

	for(Sector=0; Sector<(pageSize/0x200); Sector++) {
		EmulatedBitError = KAL_FALSE;
		if(pageSize < 1024) {
			MagicNum = (addr1>>16) ^ (addr1>>8);
		} else {
			MagicNum = (addr1>>16) ^ (addr1>>24);
		}
		for(Offset=(MagicNum & 0x1ff); Offset<0x200; Offset++) {
			Mask = 0x01;
			for(BitNo=0; BitNo<8; BitNo++) {
				if(Ptr[Sector*0x200+Offset] & Mask) {
					dbg_print("***[Emulate] Offset = %x, Original data = %x", addr1+(Sector*0x200)+Offset, Ptr[Sector*0x200+Offset]);
					Ptr[Sector*0x200+Offset] = Ptr[Sector*0x200+Offset] & (~Mask);
					dbg_print(" New data  = %x \n\r", Ptr[Sector*0x200+Offset]);
					EmulatedBitError = KAL_TRUE;
					break;
				}
				Mask = Mask << 1;
			}
			if(EmulatedBitError==KAL_TRUE) {
				break;
			}
		}
	}

    if ( BLHeader.NFIinfo.addressCycle > 4) {
        page_index = (addr2<<16) | (addr1>>(BLHeader.pageShift));
    } else {
        page_index = addr1 >> (BLHeader.pageShift);
    }

	NFI_PageWrite(page_index, 0, destination, parity, KAL_FALSE, KAL_FALSE, KAL_FALSE);

	return;
}

#if defined(BL_NFI_TEST)

/**********************************************************
Description : NFI_BlockErase
Remark      : Must be page alignment.
***********************************************************/
NFI_Error_Code NFI_BlockErase(kal_uint32 block_index)
{
    kal_uint32              tmp_val = 0;
    kal_uint32              timeout = 0;
    NFI_Error_Code  status  = NFI_OPERATION_SUCCESS;

    BL_NFI_Reset();

    DRV_WriteReg(NFI_CNFG, BL_ERASE_CNFG);

    /* issue data output command and address cycles */
    DRV_WriteReg(NFI_CMD, BLOCK_ERASE1_CMD);
    timeout = NORMAL_BUSY_PERIOD;
    while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );

    if(timeout)
    {
        DRV_WriteReg32(NFI_COLADDR, 0);
        DRV_WriteReg32(NFI_ROWADDR, block_index*BL_nfi_cfg.nfi_block_size);
        tmp_val = BL_nfi_cfg.nfi_row_num << ADDR_ROW_NOB_SHIFT;
        DRV_WriteReg(NFI_ADDRNOB, tmp_val);
        timeout = NORMAL_BUSY_PERIOD;
        while( (DRV_Reg32(NFI_STA) & STA_ADDR_STATE) && (--timeout) );

        if(timeout)
        {
            /* erase confirm command */
            DRV_WriteReg(NFI_CMD, BLOCK_ERASE2_CMD);
            timeout = NORMAL_BUSY_PERIOD;
            while( (DRV_Reg32(NFI_STA) & STA_CMD_STATE) && (--timeout) );

            if(timeout)
            {
                timeout = ERASE_BUSY_PERIOD;
                do
                {
                    tmp_val = NFI_ReadStatus();
                    if(tmp_val&DEVICE_READY)
                        break;
                    else
                        timeout--;
                }while(timeout);
                if(0 == timeout)
                    status = NFI_BLOCKERASE_TIMEOUT;
            }
            else
            {
                status = NFI_CMD_TIMEOUT;
            }
        }
        else
        {
                status = NFI_ADDR_TIMEOUT;
        }
    }
    else
    {
        status = NFI_CMD_TIMEOUT;
    }

    /* check operation status */
    if( (NFI_OPERATION_SUCCESS == status) && (tmp_val&OPERATION_FAIL) )
        status = NFI_BLOCKERASE_FAILED;

    return status;
}




struct NAND_DeviceTable {
    NFI_MENU    info;
    U8          id[8];
};

U8   device_id[8];
kal_uint32  device_idx = 8;
struct NAND_DeviceTable  NFI_Test_Device[] =
{   //advance high address cycle test
    { {IO_8BITS,  4096, 5}, { 0x98, 0xD5, 0x94, 0xBA, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_16BITS, 2048, 4}, { 0xAD, 0xC1, 0x80, 0x5D, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,  2048, 5}, { 0xEC, 0xDA, 0x10, 0x95, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,  2048, 5}, { 0xAD, 0xD3, 0x14, 0xA5, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_16BITS,  512, 3}, { 0xAD, 0x55, 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00 } },
    { {IO_8BITS,   512, 4}, { 0xAD, 0x76, 0xAD, 0x76, 0x00, 0x00, 0x00, 0x00 } }
};

void BL_NFI_Test(kal_uint32 *Buffer)
{
	kal_uint8 *BufPtr = (kal_uint8 *)Buffer;
	kal_uint8 *RBufPtr = BufPtr+3072;
	kal_uint32 BlockIndex, PageIndex, Offset, Addr[2];
    NFI_SUBMENU sub_menu;
    kal_bool Pass = KAL_TRUE;
    NFI_Error_Code RetCode;

#if defined(MT6276)
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6256))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6255))
	DRV_WriteReg16(MCU_CG_CLR1, 0x1000);
#elif (defined(MT6280))
	DRV_WriteReg32(APMCU_CG_CLR, 0x20);
#elif defined(MT6573)
    DRV_WriteReg32(APMCU_CG_CLR1, 0x80);
#endif

    // auto detect NAND flash device
    memset(device_id, 0, sizeof(device_id));
    NFI_ReadID(sizeof(device_id), device_id);
    for(device_idx=0; device_idx<sizeof(NFI_Test_Device)/sizeof(struct NAND_DeviceTable); device_idx++) {
        if(!memcmp(NFI_Test_Device[device_idx].id, device_id, 4)) {
            goto __device_found;
        }
    }

    // device not found!
	dbg_print("Device not found %x %x %x %x~~\n\r", device_id[0], device_id[1], device_id[2], device_id[3]);
    while(1);

__device_found:

	if (NFI_Test_Device[device_idx].info.pageSize == 512) {
		sub_menu.blockSize = 32;
		BLHeader.pageShift = 8;
		BLHeader.blockShift = 5;
	} else {
		sub_menu.blockSize = 64;
		BLHeader.pageShift = 16;
		BLHeader.blockShift = 6;
	}
	sub_menu.spareSize = 16;
	NFI_Config(&NFI_Test_Device[device_idx].info, &sub_menu);
	BLHeader.NFIinfo.addressCycle = NFI_Test_Device[device_idx].info.addressCycle;
	BLHeader.NFIinfo.IOInterface = NFI_Test_Device[device_idx].info.IOInterface;
	BLHeader.NFIinfo.pageSize = NFI_Test_Device[device_idx].info.pageSize;
	BLHeader.spareSize = sub_menu.spareSize;
	BLHeader.pagesPerBlock = sub_menu.blockSize;


	for (BlockIndex=0; BlockIndex<0x100; BlockIndex++) {
		Addr[0] = (BlockIndex * BLHeader.pagesPerBlock) << BLHeader.pageShift;
		Addr[1] = (BlockIndex * BLHeader.pagesPerBlock) >> (32 - BLHeader.pageShift);
		if (GoodBlockChecking(&NFI_Test_Device[device_idx].info, Addr[0], Addr[1] )==KAL_FALSE) {
			dbg_print("Block %x is bad..\n\r", BlockIndex);
			continue;
		}
		RetCode = NFI_BlockErase(BlockIndex);
		if (RetCode > NFI_OPERATION_SUCCESS) {

			dbg_print("Block %x erase failed..\n\r", BlockIndex);
			continue;
		}
		for (PageIndex=0; PageIndex<BLHeader.pagesPerBlock; PageIndex++) {
			Addr[0] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) << BLHeader.pageShift;
			Addr[1] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) >> (32 - BLHeader.pageShift);

			RetCode = NFI_PhyPageRead((kal_uint32 *)RBufPtr, (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle,
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}

			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if (RBufPtr[Offset] != 0xff) {
					dbg_print("[Error] Data not empty. BlockIndex %x PageIndex %x Offset %x value %x\n\r",
						BlockIndex, PageIndex, Offset, RBufPtr[Offset]);
					Pass = KAL_FALSE;
				}
			}
		}
	}

	if(Pass==KAL_FALSE) {
		dbg_print("Test failed..\n\r");
		while(1);
	}

	for (BlockIndex=0; BlockIndex<0x100; BlockIndex++) {
		Addr[0] = (BlockIndex * BLHeader.pagesPerBlock) << BLHeader.pageShift;
		Addr[1] = (BlockIndex * BLHeader.pagesPerBlock) >> (32 - BLHeader.pageShift);
		if (GoodBlockChecking(&NFI_Test_Device[device_idx].info, Addr[0], Addr[1] )==KAL_FALSE) {
			dbg_print("Block %x is bad..\n\r", BlockIndex);
			continue;
		}

		for (PageIndex=0; PageIndex<BLHeader.pagesPerBlock; PageIndex++) {
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				BufPtr[Offset] = (kal_uint8) (BlockIndex+PageIndex+Offset);
			}
			RetCode = NFI_PageWrite(BlockIndex*BLHeader.pagesPerBlock+PageIndex, 0, (kal_uint32 *)BufPtr, (kal_uint32 *)&(BufPtr[NFI_Test_Device[device_idx].info.pageSize]), KAL_TRUE, KAL_TRUE, KAL_FALSE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("Block %x program failed..\n\r", BlockIndex);
				continue;
			}

			Addr[0] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) << BLHeader.pageShift;
			Addr[1] = (BlockIndex * BLHeader.pagesPerBlock + PageIndex) >> (32 - BLHeader.pageShift);

			RetCode = NFI_PhyPageRead((kal_uint32 *)RBufPtr, (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle,
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r",
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("Test failed..\n\r");
				while(1);
			}
			memset(RBufPtr, 0, 4096);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 0, 1, (kal_uint32 *)&(RBufPtr[0]), (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 528, 1, (kal_uint32 *)&(RBufPtr[512]), (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize+3]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			NFI_SectorRead(BlockIndex * BLHeader.pagesPerBlock + PageIndex, 1056, 2, (kal_uint32 *)&(RBufPtr[1024]), (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize+6]), KAL_FALSE, KAL_TRUE, KAL_TRUE);
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r",
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("NFI_SectorRead compare failed..\n\r");
				while(1);
			}
			EmulateBitError((kal_uint32 *)RBufPtr, (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), BLHeader.NFIinfo.addressCycle, Addr[0], Addr[1], BLHeader.NFIinfo.pageSize);
			memset(RBufPtr, 0, 4096);
			RetCode = NFI_PhyPageRead((kal_uint32 *)RBufPtr, (kal_uint32 *)&(RBufPtr[NFI_Test_Device[device_idx].info.pageSize]), 1, BLHeader.NFIinfo.addressCycle,
				Addr[0], Addr[1], BLHeader.NFIinfo.pageSize, KAL_TRUE, KAL_TRUE);
			if (RetCode > NFI_OPERATION_SUCCESS) {

				dbg_print("NFI_PhyPageRead failed.. Block %x Page %x RetCode=%x\n\r", BlockIndex, PageIndex, RetCode);
				while(1);
			}
			for (Offset=0; Offset<(NFI_Test_Device[device_idx].info.pageSize+(BL_nfi_cfg.nfi_sector_num*BL_nfi_cfg.nfi_fdm_size)); Offset++) {
				if(RBufPtr[Offset] != BufPtr[Offset]) {
					dbg_print("[Error] Data mismatch. BlockIndex %x PageIndex %x Offset %x write value=%x read value=%x\n\r",
						BlockIndex, PageIndex, Offset, BufPtr[Offset], RBufPtr[Offset]);
					Pass = KAL_FALSE;
				}
			}
			if (Pass==KAL_FALSE) {
				dbg_print("EmulateBitError compare failed..\n\r");
				while(1);
			}

		}
	}
}

#endif // defined(BL_NFI_TEST)

#endif  // defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)

#endif // __USE_NFI_SHARED_DRV__
#endif // defined(__NFI_VERSION3_1__)

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ */
