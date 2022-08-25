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
 *   emi_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Definition for CONFIG hardware registers
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __EMI_SW_H__
#define __EMI_SW_H__

/* RHR Add */
#include "kal_general_types.h"
#include "emi_hw.h"

#include "emi_sw_internal.h"


/******
   *
   * For SW to force EMI entering self-refresh mode before entering/existing sleep mode (some architecture does not support HW hand-shake, so SW has to take care of it explicitly).
   *
   *****/
#if defined(MT6235) || defined(MT6235B)

#define INT_DRAMSelfRefreshModeDIS()      \
    do {                                  \
      INT_DRAMSelfRefreshModeDisable();   \
    } while(0)

#define INT_DRAMSelfRefreshModeEN()       \
    do {                                  \
      INT_DRAMSelfRefreshModeEnable();    \
    } while(0)
    
#define INT_DoCalibrateEMI2xClock()       \
    do {                                  \
    } while(0)

#else   /* MT6235 || MT6235B */

#define INT_DRAMSelfRefreshModeDIS()      \
    do {                                  \
    } while(0)

#define INT_DRAMSelfRefreshModeEN()       \
    do {                                  \
    } while(0)
    
#define INT_DoCalibrateEMI2xClock()       \
    do {                                  \
    } while(0)

#endif  /* MT6235 || MT6235B */



/******
   *
   * For SW to perform dummy read to correct platform-defined address.
   *
   *****/
#if defined(__MTK_TARGET__)

#if defined(MT6255)

#if defined(_NAND_FLASH_BOOTING_) || defined(__SIP_RAM_SIZE__)
#define EMI_Dummy_Read()  \
        do {    \
                do { \
                  if (0 == ((*EMI_CONN) & 0x00000080)) { \
                  break;  \
                    }  \
                 } while (1);  \
        } while (0)
#else  //ADMUX
       #define EMI_Dummy_Read()
#endif

#elif defined(MT6261) || defined(MT2501) || defined(MT2502) 

      #define EMI_Dummy_Read()
#else  // #if defined(MT6255)

#define EMI_Dummy_Read()  \
        do {    \
            volatile kal_uint16 i;   \
            i = *(volatile kal_uint16 *)EMI_Dummy_Read_Base;  \
        } while (0)

#endif

#else /* __MTK_TARGET__ */

#define EMI_Dummy_Read()

#endif /* __MTK_TARGET__ */



/******
   *
   * Run-time switch GMC bandwidth allocation's soft/hard mode, it is used under lock-down IRQ duration currently.
   * This function is used for preventing MM soft mode affecting the rea-time APP's timing.
   *
   *****/
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)

#if defined(MT6236) || defined(MT6236B)

#define EMI_Set_GMCBW_SoftMode_NonReentrant()    \
        do {    \
           extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
              *EMI_ARBH |= 0x00004000;    \
              *EMI_ARBI |= 0x00004000; }   \
        } while (0)
#define EMI_Set_GMCBW_HardMode_NonReentrant()    \
        do {    \
	         extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
              *EMI_ARBH &= ~0x00004000;     \
              *EMI_ARBI &= ~0x00004000; }   \
           SET_EMI_ARB_HARD_MODE_CNT++;    \
        } while (0)
        
#elif defined(MT6256) 
 #define EMI_Set_GMCBW_SoftMode_NonReentrant()    \
        do {    \
                extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
                extern kal_uint32 Set_EMI_BW_Graphic_Mode;   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
                    if (0 != Set_EMI_BW_Graphic_Mode) { \
                     *EMI_ARBF |= 0x00004000; }}  \
        } while (0)
#define EMI_Set_GMCBW_HardMode_NonReentrant()    \
        do {    \
	         extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         extern kal_uint32 Set_EMI_BW_Graphic_Mode;   \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
                    Set_EMI_BW_Graphic_Mode = (*EMI_ARBF & 0x00004000); \
                    if ( 0 != Set_EMI_BW_Graphic_Mode) { \
	             *EMI_ARBF &= ~0x00005000; \
	             *EMI_ARBF |=  0x00001000;}}   \
                SET_EMI_ARB_HARD_MODE_CNT++;    \
        } while (0)

#elif defined(MT6255)

#define EMI_Set_GMCBW_SoftMode_NonReentrant()    \
        do {    \
                extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	            *EMI_ARBE |= 0x00004000;  }\
        } while (0)
#define EMI_Set_GMCBW_HardMode_NonReentrant()    \
        do {    \
                extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	            *EMI_ARBE |= 0x00004000;  }\
        } while (0)
#elif defined(MT6250)
#define EMI_Set_GMCBW_SoftMode_NonReentrant()    \
        do {    \
                extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	            *EMI_ARBC |= 0x00004000;  }\
        } while (0)
#define EMI_Set_GMCBW_HardMode_NonReentrant()    \
        do {    \
	         extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	         *EMI_ARBC &= ~0x00004000;} \
              SET_EMI_ARB_HARD_MODE_CNT++;    \
        } while (0)        
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define EMI_Set_GMCBW_SoftMode_NonReentrant()    \
        do {    \
                extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
                if( SET_EMI_ARB_HARD_MODE_CNT > 0 ) {   \
	         SET_EMI_ARB_HARD_MODE_CNT--;    \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	            *EMI_ARBC |= 0x00004000;  }\
                	}\
        } while (0)
#define EMI_Set_GMCBW_HardMode_NonReentrant()    \
        do {    \
	         extern kal_uint32 SET_EMI_ARB_HARD_MODE_CNT;   \
	         if( SET_EMI_ARB_HARD_MODE_CNT == 0 ) {   \
	         *EMI_ARBC &= ~0x00004000;} \
              SET_EMI_ARB_HARD_MODE_CNT++;    \
        } while (0)             
#else
#define EMI_Set_GMCBW_SoftMode_NonReentrant()
#define EMI_Set_GMCBW_HardMode_NonReentrant()

#endif /* MT6236 | MT6236B */

#define EMI_Set_GMCBW_SoftMode()    \
        do {    \
                extern kal_uint32 LockIRQ(void);   \
                extern void RestoreIRQ(kal_uint32);   \
                kal_uint32 saveMask;   \
                saveMask = LockIRQ();   \
	              EMI_Set_GMCBW_SoftMode_NonReentrant();    \
	              RestoreIRQ(saveMask);  \
        } while (0)
#define EMI_Set_GMCBW_HardMode()    \
        do {    \
                extern kal_uint32 LockIRQ(void);   \
                extern void RestoreIRQ(kal_uint32);   \
                kal_uint32 saveMask;   \
                saveMask = LockIRQ();   \
	              EMI_Set_GMCBW_HardMode_NonReentrant();    \
	              RestoreIRQ(saveMask);  \
        } while (0)    
        
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */


#if defined(MT6252H) || defined(MT6252) || defined(MT6253E) || defined(MT6253L)

/**
  * Temp solution, on MT6252D, we use this macro to pull down EMI ED pin, when enter sleep mode.
  * and disable EMI ED pin pull down, when exit sleep mode
  */
#define EMI_Mask_PullDownED()    \
        do {    \
   			while ((*LYR2_EMPTY & 0x8000) == 0x8000);  \
   			*LYR2_EMPTY_EN = *LYR2_EMPTY_EN | 0x0001;  \
   			while ((*LYR2_EMPTY & 0x0001) == 0x0);  \
   			*(volatile unsigned int*)0x20000000;  \
   			*EMI_IOB |= 0x00000020;  \
        } while (0)
#define EMI_Unmask_NonPullED()    \
        do {    \
			*EMI_IOB &= ~0x00000020;  \
			*LYR2_EMPTY_EN = *LYR2_EMPTY_EN & 0xfffe;  \
        } while (0)
#endif /* MT6253E | MT6253L */
/*********************************************
 *
 * Exposed APIs.
 *
 ********************************************/
 
extern kal_int32 INT_DisableDataCache(void);
extern void INT_RestoreDataCache(kal_uint32 restore_value);
extern kal_int32 INT_DisableCodePrefetch(void);
extern void INT_RestoreCodePrefetch(kal_uint32 restore_value);
extern void INT_DRAMSelfRefreshModeDisable(void);
extern void INT_DRAMSelfRefreshModeEnable(void);
extern kal_int32 EMI_QueryIsRemapped(void);

extern kal_int32 EMI_QueryCurSetting(void* emi_setting);
#define EMI_RUNTIME_Info_Size (sizeof(EMI_RUNTIME_Info))

#endif  /* !__EMI_SW_H__ */

