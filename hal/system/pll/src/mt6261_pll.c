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
 *   pll.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   pll init flow
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "reg_base.h"
#include "config_hw.h"
#include "drv_comm.h"
#include "pll.h"
#include "init.h"
#include "intrCtrl.h"
#include "drvpdn.h"
#include "flash_sfi_release.h"

#if defined(MT2501)
#define BT_APP 1
#endif //#if defined(MT2501)

#ifdef __MTK_TARGET__ /* should NOT be compiled on MODIS */

extern ECO_VERSION eco_version; /* only used in PLL setup */

/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  INT_SetPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetPLL(pll_init_mode mode)
{

        volatile kal_uint32 i, reg_val, loop_1us, tmp;
    
        if (mode == PLL_MODE_MAUI) {
                /* do nothing */
        }
        else if (mode == PLL_MODE_USB_META) {
                // switch back to 26MHz 
                *PLL_CLK_CONDC = 0x8008; // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider
                //read CLK_CONDC //CLK_CONDC[1] will change as 0->1->0 . 
                // a dummy read here so that we don’t poll 1st 0 and exit, 
                // polling until CLK_CONDC[1]==0 , or 1us  
                tmp = *PLL_CLK_CONDC;
                tmp = *PLL_CLK_CONDC;
                if (tmp & 0x0002) {
                        // 0xA001_0108, bit 15 set to 0 to disable digital frequency divider
                        *PLL_CLK_CONDC = 0x0008;  
                } else {
                        //wait 1us to make sure clock switch to 26MHz
                        gpt4_busy_wait_us(1); 
                        // 0xA001_0108, bit 15 set to 0 to disable digital frequency divider 
                        *PLL_CLK_CONDC = 0x0008;  
                } 
        }

        // enable HW mode TOPSM control and clock CG of PLL control 
        *PLL_PLL_CON2 = 0x0000; // 0xA0170048, bit 12, 10 and 8 set to 0 to enable TOPSM control 
        // bit 4, 2 and 0 set to 0 to enable clock CG of PLL control
        *PLL_PLL_CON3 = 0x0000; // 0xA017004C, bit 12 set to 0 to enable TOPSM control

        // enable delay control 
        *PLL_PLLTD_CON0= 0x0000; //0x A0170700, bit 0 set to 0 to enable delay control

        //wait for 1us for TOPSM and delay (HW) control signal stable
        gpt4_busy_wait_us(1);

        //enable and reset UPLL
        tmp = *PLL_UPLL_CON0;
        tmp  |= 0x0001;
        *PLL_UPLL_CON0 = tmp; // 0xA0170140, bit 0 set to 1 to enable UPLL and generate reset of UPLL
     
        //select MPLL frequency
#ifdef BT_APP
        *PLL_MPLL_CON0  = 0x1800; // 0xA0170100, set MPLL = 624M
        *PLL_MPLL_CON1  = 0x0000; // 0xA0170104, set post divider = /1
#else
        *PLL_MPLL_CON0  = 0x1400; // 0xA0170100, set MPLL = 520M
        *PLL_MPLL_CON1  = 0x0000; // 0xA0170104, set post divider = /1
#endif

        //enable MDDS
        *PLL_MDDS_CON0 = 0x0001; //0x A0170640, bit 0 set to 1 to enable MDDS

        //enable and reset MPLL
        tmp = *PLL_MPLL_CON0;
        tmp  |= 0x0001;
        *PLL_MPLL_CON0  = tmp; //0xA0170100, bit 0 set to 1 to enable MPLL and generate reset of MPLL

        //wait 50us for PLL and DDS settle
        gpt4_busy_wait_us(50);

        //Disable DDS LDO PG detector to save power
        tmp = *PLL_PLL_CON4;
        tmp  &= 0xFFFB;
        *PLL_PLL_CON4 = tmp; //0xA0170050, bit 2 set to 0


        // Sequence to switch to PLL clocks as below: 
#ifdef BT_APP
        *PLL_CLK_CONDA |= 0x8100; //0xA001_0100, disables MPLL/5.5, enables MPLL/6 and UPLL/2 clock divider
#else
        *PLL_CLK_CONDA |= 0x0100; //0xA001_0100, enables MPLL/6 and UPLL/2 clock divider
#endif


#ifdef BT_APP
//sets DSP_MUX_SEL, BSI_MUX_SEL, SLCD_MUX_SEL and SFC_MUX_SEL
#if defined (__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH = 0xDA12; // 0xA001_011C, SFC_MUX_SEL = 3'b010
#elif defined (__SFI_CLK_133MHZ__)
        *PLL_CLK_CONDH = 0xDA11; // 0xA001_011C, SFC_MUX_SEL = 3'b001
#elif defined (__SFI_CLK_78MHZ__)
        *PLL_CLK_CONDH = 0xDA14; // 0xA001_011C, SFC_MUX_SEL = 3'b100
#else 
        *PLL_CLK_CONDH = 0xDA12; // 0xA001_011C, SFC_MUX_SEL = 3'b010
#endif //#ifdef __SFI_CLK_104MHZ__

#ifdef ARM_156M
        *PLL_CLK_CONDH = (*PLL_CLK_CONDH & 0xF9FF) | 0x0400; // DSP_MUX_SEL= 2’b10
        *PLL_CLK_CONDA |=0x2000; //0xA001_0100, ARM sets to 156M
#else //#ifdef ARM_156M
        *PLL_CLK_CONDA |=0x1000; //0xA001_0100, ARM sets to 208M
#endif //#ifdef ARM_156M

#else //#ifdef BT_APP
#if defined (__SFI_CLK_104MHZ__)
        *PLL_CLK_CONDH = 0xD001; // 0xA001_011C, SFC_MUX_SEL = 3'b001
#elif defined(__SFI_CLK_133MHZ__)
        *PLL_CLK_CONDH = 0xD000; // 0xA001_011C, SFC_MUX_SEL = 3'b000
#elif defined(__SFI_CLK_78MHZ__)
        *PLL_CLK_CONDH = 0xD003; // 0xA001_011C, SFC_MUX_SEL = 3'b011
#else 
        *PLL_CLK_CONDH = 0xD001; // 0xA001_011C, SFC_MUX_SEL = 3'b001
#endif //#ifdef __SFI_CLK_104MHZ__
#endif ////#ifdef BT_APP


        *PLL_CLK_CONDC = 0x8008;   // 0xA001_0108, bit 15 set to 1 to enable digital frequency divider
        // wait for 2us to enable divider
        gpt4_busy_wait_us(2);

#if defined(__SERIAL_FLASH_STT_EN__) || defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) || defined(__SPI_NAND_SUPPORT__)
        // 0xA001_0108, 
        // sfc_gfmux_sel = 1'b0
        // arm_gfmux_sel = 3'b100,
        // dsp_gfmux_sel = 1'b1,
        // x4g_gfmux_sel = 1'b1, 
        // rg_pllck_sel  = 1'b1
        *PLL_CLK_CONDC = 0xB620; 
#else
        // 0xA001_0108, sets gfmux
        // sfc_gfmux_sel = 1'b1, 
        // arm_gfmux_sel = 3'b100,
        // dsp_gfmux_sel = 1'b1,
        // x4g_gfmux_sel = 1'b1, 
        // rg_pllck_sel  = 1'b1
        *PLL_CLK_CONDC = 0xB621; 
#endif  //#if defined(__SERIAL_FLASH_STT_EN__) || defined(__SERIAL_FLASH_INIT_IN_EXTBOOTLOADER__) || defined(__SPI_NAND_SUPPORT__)

}


#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */

#ifndef __FUE__

/*************************************************************************
* FUNCTION
*  INT_SwitchMCUClock
*
* DESCRIPTION
*   This function intended for switching MCU clock.
* Be very careful that, before this function is called, user must ensure
* that there is very save EMI setting.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if 0 //// deprecated in 11C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //// deprecated in 11C

#if defined(MT6250)
/*************************************************************************
* FUNCTION
*  mt6250_fm_force_upll_on
*
* DESCRIPTION
*   This function intended for MT6250 FM issue ONLY.
* According to the conclusion of issue discussion, this function is only 
* used by FM driver in MT6250.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void mt6250_fm_force_upll_on(kal_bool force_on)
{
    if(force_on)
    {
        /* keep 26Mhz and UPLL forced on */
        *PLL_DPM_CON0 |= 0x22;
    }
    else
    {
        /* remove 26Mhz and UPLL forced on */
        *PLL_DPM_CON0 &= ~(0x22);
    }
    *PLL_DPM_CON0;
}
#endif /* MT6250 */

#endif

#if (!defined(__UBL__) && !defined(__FUE__)) && defined(__MTK_TARGET__)

#ifdef __MTK_TARGET__
#pragma arm section code = "INTSRAM_ROCODE", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */

extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);

#if defined(MT6256_S01)
__align(8) kal_uint32 PLL_Stack_Pool_Init[PLL_SWITCH_STACK_SIZE>>2];
volatile kal_bool  pll_dds_off = KAL_FALSE;
volatile kal_uint32  pll_dds_switch_cycles;
#endif /* MT6256_S01 */

#if 0 // deprecated in 11C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // deprecated in 11C

#ifdef __MTK_TARGET__
#pragma arm section code, rwdata, rodata, zidata
#endif /* __MTK_TARGET__ */

#else
#if 0 // deprecated in 11C
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // deprecated in 11C
#endif /* !__UBL__ && !__FUE__ */

#endif /* should NOT be compiled on MODIS */
