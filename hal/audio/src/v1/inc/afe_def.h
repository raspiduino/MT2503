/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * afe_def.h
 *
 * Project:
 * --------
 * Maui
 *
 * Description:
 * ------------
 *  This file defines all the AFE registers used in audio module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __AFE_DEF_H
#define __AFE_DEF_H

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter:  INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "l1audio.h"
#include "audio_def.h"
#include "am.h"
#include "eint.h"
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
#include "vibration_def.h"
#endif
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter:  Feature Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Sections: Immobile AFE Feature Definitions
//=============================================================================================
   #define __AFE_AudVoice_SingleClkSrc__ ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define __AFE_MULTIEPLE_DIE__ ( defined(MT6250) || defined(MT6260))
   #define __AFE_2ndG_DC_COUPLE__ ( defined(MT6251) || defined(MT6256) || defined(MT6255) )
   #define __AFE_2ndG_AC_COUPLE__ ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define __AFE_VOICE_AMP_AS_LOUDSPK__ ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) 
   #define __AFE_KARAOK_SUPPORT__ ( defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define __AFE_I2S_FOC_SUPPORT__ ( defined(MT6251) || defined(MT6256) )
   //FOC (I2S slave mode freq. compensation)
   #define __AFE_OC_DETECTION__ ( defined(MT6255) ||  defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   //Over current detect
   #define HW_MUTE_SUPPORT_PLATFORM 1
   //Currently all platform support HW mute
   #define __AFE_HW_PREDIST__    ( defined(MT6256) )
   #define __AFE_DIGITAL_MIC_SUPPORT__  ( defined(MT6255) || defined(MT6251) || defined(MT6256) )
   #define __AFE_ANALOG_GAIN_REVERSE_ORDER__  ( defined(MT6255) || defined(MT6251) || defined(MT6256) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define __AFE_SW_DC_COMPENSATION__ ( defined(MT6252H) || defined(MT6252) || defined(MT6236) || defined(MT6236B) )
   #define __AFE_HW_DC_COMPENSATION__ ( defined(MT6251) || defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define __AFE_EDI_DATA_SELECT__ ( !defined(MT6235) )
   #define __AFE_MIC_VOLUME_LOWER_BOUND__   ( defined(MT6252) || defined(MT6252H) )
   #define __AFE_ANALOG_GAIN_UPPER_BOUND__   ( defined(MT6252) || defined(MT6252H) )
   #define __AFE_ANALOG_GAIN_LOWER_BOUND__   ( defined(MT6255) || defined(MT6251) || defined(MT6256) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   //the bit of AFE_AMCU_CON2[6] support: audio data come from EDI or DSP select 

   #define __AFE_MD2G_PWDN_LOCK__   ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
   
//=============================================================================================
//                  Sections: Switchable AFE Feature Definitions
//=============================================================================================
   
   /*Analog gain with upper bound*/ 
   #define __AFE_ENABLE_HW_AGC__   ( defined(MT6252) || defined(MT6252H) || defined(MT6251) || defined(MT6235) || defined(MT6268) \
                                     || defined(MT6253) || defined(MT6235B) )
   
   #define __AFE_AUDIO_DELAY_OFF__ ( defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))

   #define __AFE_PA_DELAY_OFF__ 0           
   
   #define __AFE_HP_DC_CALIBRATION__       (defined(MT6260))// || defined(MT6261) || defined(MT2501) || defined(MT2502))
   #define HP_CHARGE_DELAY   600
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__) && (defined(MT6260) || defined(MT6261)) 
   #define __AFE_CURRENT_SENSOR_ENABLE__  1   
#if defined(VIBR_CALI_STEP_2HZ)
   #define AFE_VS_CALI_STEP  2
#elif defined(VIBR_CALI_STEP_3HZ)
   #define AFE_VS_CALI_STEP  3
#else
   #define AFE_VS_CALI_STEP  3
#endif
   #define AFE_VS_START_FREQ 130
   #define AFE_VS_END_FREQ   230
#endif 
#if defined(__CLASSK_CP_SUPPORT__) && (defined(MT6260) || defined(MT6261)) 
   #define __AFE_CLASSK_SUPPORT_INTERNAL__ 1 
   #if defined(MT6260)
   #define THERMAL_EINT 25 //125
   #elif defined(MT6261)
   #define THERMAL_EINT 41 //110
   #endif
#endif    
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Sections:  Feature Dependency
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if __AFE_HW_DC_COMPENSATION__
 #if !defined(__AUDIO_DC_CALIBRATION_SUPPORT__)
   #error should add __AUDIO_DC_CALIBRATION_SUPPORT__ define in HW DC calibration supported platform
 #endif
 #define __SPK_DC_COMPENSATION__ 0   
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter:  Customer Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#if __AFE_PA_DELAY_OFF__
   #define AFE_PA_DELAY_NUM 5
#endif


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter:  Register Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Sections: Register Audio Front End Hardware Control Register
//=============================================================================================
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define  AFE_MCU_CON0   ((APBADDR)(AFE_base+0x0210)) 
   #define  AFE_MCU_CON1   ((APBADDR)(AFE_base+0x0214))    
   #define  AFE_VMCU_CON0  ((APBADDR)(AFE_base+0x0000))       
   #define  AFE_VMCU_CON1  ((APBADDR)(AFE_base+0x000C))       
   #define  AFE_VMCU_CON2  ((APBADDR)(AFE_base+0x0010))       
   #define  AFE_VMCU_CON3  ((APBADDR)(AFE_base+0x001C)) 
   #define  AFE_VMCU_CON4  ((APBADDR)(AFE_base+0x01A0))
   #define  AFE_VMCU_CON6  ((APBADDR)(AFE_base+0x01A8))                  
   #define  AFE_VDB_CON    ((APBADDR)(AFE_base+0x0014))       
   #define  AFE_VLB_CON    ((APBADDR)(AFE_base+0x0018))       
   #define  AFE_AMCU_CON0  ((APBADDR)(AFE_base+0x0020))       
   #define  AFE_AMCU_CON1  ((APBADDR)(AFE_base+0x0024)) 
   #define  AFE_AMCU_CON2  ((APBADDR)(AFE_base+0x002C))
   #define  AFE_AMCU_CON3  ((APBADDR)(AFE_base+0x0038)) 
   #define  AFE_AMCU_CON4  ((APBADDR)(AFE_base+0x003C))      
   #define  AFE_AMCU_CON5  ((APBADDR)(AFE_base+0x0180))
   #define  AFE_AMCU_CON6  ((APBADDR)(AFE_base+0x0184))
   #define  AFE_AMCU_CON7  ((APBADDR)(AFE_base+0x0188))
   #define  AFE_EDI_CON    ((APBADDR)(AFE_base+0x0028))             
   #define  AFE_DAC_TEST   ((APBADDR)(AFE_base+0x0030))       
   #define  AFE_VAM_SET    ((APBADDR)(AFE_base+0x0034))   
#else
   #define  AFE_VMCU_CON   ((APBADDR)(AFE_base+0x0000))        /* AFE MCU Control Register               */
   #define  AFE_VMCU_CON0  ((APBADDR)(AFE_base+0x0000))        /* AFE MCU Control Register               */
   #define  AFE_VMCU_CON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
   #define  AFE_VMCU_CON2  ((APBADDR)(AFE_base+0x0010))        /* AFE Voice Analog Circuit Control Register 2   */
   #define  AFE_VMCU_CON3  ((APBADDR)(AFE_base+0x001C))        /* AFE Voice Analog Circuit Control Register 3   */
   #define  AFE_VMCU_CON5  ((APBADDR)(AFE_base+0x01AC))        /* AFE Voice Analog Circuit Control Register 3   */ //Scott110512
   #define  AFE_VAC_DCON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
   #define  AFE_VDB_CON    ((APBADDR)(AFE_base+0x0014))        /* AFE Voice DAI Blue Tooth Control Register     */
   #define  AFE_VLB_CON    ((APBADDR)(AFE_base+0x0018))        /* AFE Voice Loop-back Mode Control Register     */
   #define  AFE_AMCU_CON0  ((APBADDR)(AFE_base+0x0020))        /* AFE Audio MCU Control Register 0gister        */
   #define  AFE_AMCU_CON1  ((APBADDR)(AFE_base+0x0024))        /* AFE Audio Control Register 1                  */
   #define  AFE_AMCU_CON5  ((APBADDR)(AFE_base+0x0180))        /* AFE Audio Control Register 5                  */
   #define  AFE_EDI_CON    ((APBADDR)(AFE_base+0x0028))        /* AFE Audio EDI(I2S , EIAJ) Control Register    */
   #define  AFE_AMCU_CON2  ((APBADDR)(AFE_base+0x002C))        /* AFE Audio Control Register 2                  */
   #define  AFE_DAC_TEST   ((APBADDR)(AFE_base+0x0030))        /* AUDIO/VOICE sinewave generator and others     */
   #define  AFE_VAM_SET    ((APBADDR)(AFE_base+0x0034))        /* Audio/Voice Interactive Mode Setting          */
   #define  AFE_AMCU_CON3  ((APBADDR)(AFE_base+0x0038))        /* AFE Audio Control Register 3                  */
   #define  AFE_EQCOEF     ((APBADDR)(AFE_base+0x0040))        /* AFE Audio EQ Coefficients                     */
   #define  AFE_VAGC_CON0  ((APBADDR)(AFE_base+0x0100))        /* AFE Audio AGC Control Register 0              */
   #define  AFE_VAGC_CON1  ((APBADDR)(AFE_base+0x0104))        /* AFE Audio AGC Control Register 1              */
   #define  AFE_VAGC_CON2  ((APBADDR)(AFE_base+0x0108))        /* AFE Audio AGC Control Register 2              */
   #define  AFE_VAGC_CON3  ((APBADDR)(AFE_base+0x010c))        /* AFE Audio AGC Control Register 3              */
   #define  AFE_VAGC_CON4  ((APBADDR)(AFE_base+0x0110))        /* AFE Audio AGC Control Register 4              */
   #define  AFE_VAGC_CON5  ((APBADDR)(AFE_base+0x0114))        /* AFE Audio AGC Control Register 5              */
   #define  AFE_VAGC_CON6  ((APBADDR)(AFE_base+0x0118))        /* AFE Audio AGC Control Register 6              */
   #define  AFE_VAGC2_CON0 ((APBADDR)(AFE_base+0x0120))        /* AFE Audio AGC2 Control Register 0             */
   #define  AFE_VAGC2_CON1 ((APBADDR)(AFE_base+0x0124))        /* AFE Audio AGC2 Control Register 1             */
   #define  AFE_VAGC2_CON2 ((APBADDR)(AFE_base+0x0128))        /* AFE Audio AGC2 Control Register 2             */
   #define  AFE_VAGC2_CON3 ((APBADDR)(AFE_base+0x012c))        /* AFE Audio AGC2 Control Register 3             */
   #define  AFE_VAGC2_CON4 ((APBADDR)(AFE_base+0x0130))        /* AFE Audio AGC2 Control Register 4             */
   #define  AFE_VAGC2_CON5 ((APBADDR)(AFE_base+0x0134))        /* AFE Audio AGC2 Control Register 5             */
   #define  AFE_VAGC2_CON6 ((APBADDR)(AFE_base+0x0138))        /* AFE Audio AGC2 Control Register 6             */
   #define  AFE_FOC_CON    ((APBADDR)(AFE_base+0x0150))        /* AFE I2S Control Register 0                    */
   #define  AFE_STATUS     ((APBADDR)(AFE_base+0x0174))        /* AFE Status                                    */   
   #define  AFE_VMCU_CON4  ((APBADDR)(AFE_base+0x01a0))
   #define  AFE_AMCU_CON6  ((APBADDR)(AFE_base+0x0184))
   #define  AFE_AMCU_CON7  ((APBADDR)(AFE_base+0x0188))
   #define  AFE_VMCU_CON6  ((APBADDR)(AFE_base+0x01A8))
   #define  AFE_PC_1X_IDX  ((APBADDR)(AFE_base+0x01EC)) 
#endif

//#if !defined(MT6250) && !defined(MT6260) && !defined(MT6261) && !defined(MT2501) && !defined(MT2502)
//#define  ACIF_AC_HW_VER ((APBADDR)(MIXED_base+0x0004))      /* Mix-signal Chip Version Control               */
//#define  WR_PATH        ((APBADDR)(MIXED_base+0x000C))      /* Mix-signal Chip Version Control               */
//#define  AFE_VAG_CON    ((APBADDR)(MIXED_base+0x0100))      /* AFE Voice Analog Gain Control Register        */
//#define  AFE_VAC_CON0   ((APBADDR)(MIXED_base+0x0104))      /* AFE Voice Analog-Circuit Control Register 0   */
//#define  AFE_VAC_CON1   ((APBADDR)(MIXED_base+0x0108))      /* AFE Voice Analog-Circuit Control Register 1   */
//#define  AFE_VAPDN_CON  ((APBADDR)(MIXED_base+0x010C))      /* AFE Voice Analog Power Down Control Register  */
//#define  AFE_VAGC_CON   ((APBADDR)(MIXED_base+0x0110))      /* AFE Voice AGC Control Register  */
//#define  AFE_VAC_CON2   ((APBADDR)(MIXED_base+0x0110))      /* AFE Voice Analog-Circuit Control Register 2   */
//#define  AFE_AAG_CON    ((APBADDR)(MIXED_base+0x0200))      /* AFE Audio Analog Gain Control Register        */
//#define  AFE_AAC_CON    ((APBADDR)(MIXED_base+0x0204))      /* AFE Audio Analog-Circuit Control Register     */
//#define  AFE_AAPDN_CON  ((APBADDR)(MIXED_base+0x0208))      /* AFE Audio Analog Power Down Control Register  */
//#define  AFE_AAC_NEW    ((APBADDR)(MIXED_base+0x020C))      /* Enhanced Audio AFE Control and Parameters     */
//#define  AFE_AAC_CON1   ((APBADDR)(MIXED_base+0x0210))      /* AFE Audio Analog-Circuit Control Register 1   */
//#endif

//=============================================================================================
//                  Sections: Register Audio Front End Hardware Control Register - New Naming 
//=============================================================================================
#if defined(MT6251) || defined(MT6256) 
   #define  AFUNC_AUD_CON     ((APBADDR)(PLL_base+0x1008)) 
   #define  VOICE_CON0     ((APBADDR)(PLL_base+0x1100))      /* AFE Voice Control register 0                  */
   #define  VOICE_CON1     ((APBADDR)(PLL_base+0x1104))      /* AFE Voice Control register 1                  */
   #define  VOICE_CON2     ((APBADDR)(PLL_base+0x1108))      /* AFE Voice Control register 2                  */
   #define  VOICE_CON3     ((APBADDR)(PLL_base+0x110C))      /* AFE Voice Control register 3                  */
   #define  VOICE_CON4     ((APBADDR)(PLL_base+0x1110))      /* AFE Voice Control register 4                  */
   #define  VOICE_CON5     ((APBADDR)(PLL_base+0x1114))      /* AFE Voice Control register 5                  */
   #define  AUDIO_CON0     ((APBADDR)(PLL_base+0x1200))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON1     ((APBADDR)(PLL_base+0x1204))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON2     ((APBADDR)(PLL_base+0x1208))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON3     ((APBADDR)(PLL_base+0x120c))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON4     ((APBADDR)(PLL_base+0x1210))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON5     ((APBADDR)(PLL_base+0x1214))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON6     ((APBADDR)(PLL_base+0x1218))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON7     ((APBADDR)(PLL_base+0x121c))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON8     ((APBADDR)(PLL_base+0x1220))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON9     ((APBADDR)(PLL_base+0x1224))      /* AFE Audio Control register 0                  */
   #define  VAUDN_CON0     ((APBADDR)(PLL_base+0x1280))      /* VAUDN control register 0                      */
   #define  VAUDN_CON1     ((APBADDR)(PLL_base+0x1284))      /* VAUDN control register 1                      */
   #define  VAUDP_CON0     ((APBADDR)(PLL_base+0x1290))      /* VAUDP control register 0                      */
   #define  VAUDP_CON1     ((APBADDR)(PLL_base+0x1294))      /* VAUDP control register 1                      */
#elif defined(MT6255)
   #define  AFUNC_AUD_CON  ((APBADDR)(ABBSYS_base+0x8008)) 
   #define  VOICE_CON0     ((APBADDR)(ABBSYS_base+0x8100))      /* AFE Voice Control register 0                  */
   #define  VOICE_CON1     ((APBADDR)(ABBSYS_base+0x8104))      /* AFE Voice Control register 1                  */
   #define  VOICE_CON2     ((APBADDR)(ABBSYS_base+0x8108))      /* AFE Voice Control register 2                  */
   #define  VOICE_CON3     ((APBADDR)(ABBSYS_base+0x810C))      /* AFE Voice Control register 3                  */
   #define  VOICE_CON4     ((APBADDR)(ABBSYS_base+0x8110))      /* AFE Voice Control register 4                  */
   #define  VOICE_CON5     ((APBADDR)(ABBSYS_base+0x8114))      /* AFE Voice Control register 5                  */
   #define  AUDIO_CON0     ((APBADDR)(ABBSYS_base+0x8200))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON1     ((APBADDR)(ABBSYS_base+0x8204))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON2     ((APBADDR)(ABBSYS_base+0x8208))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON3     ((APBADDR)(ABBSYS_base+0x820c))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON4     ((APBADDR)(ABBSYS_base+0x8210))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON5     ((APBADDR)(ABBSYS_base+0x8214))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON6     ((APBADDR)(ABBSYS_base+0x8218))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON7     ((APBADDR)(ABBSYS_base+0x821c))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON8     ((APBADDR)(ABBSYS_base+0x8220))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON9     ((APBADDR)(ABBSYS_base+0x8224))      /* AFE Audio Control register 0                  */
   #define  AUDIO_CON15    ((APBADDR)(ABBSYS_base+0x823c))
   #define  VAUDN_CON0     ((APBADDR)(ABBSYS_base+0x8280))      /* VAUDN control register 0                      */
   #define  VAUDN_CON1     ((APBADDR)(ABBSYS_base+0x8284))      /* VAUDN control register 1                      */
   #define  VAUDP_CON0     ((APBADDR)(ABBSYS_base+0x8290))      /* VAUDP control register 0                      */
   #define  ABB_RSV3       ((APBADDR)(ABBSYS_base+0x8f8c))
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define  ABBA_WR_PATH0      ((APBADDR)(ABBSYS_SD_base+0x0000))
   #define  ABBA_VBITX_CON0    ((APBADDR)(ABBSYS_SD_base+0x0050))
   #define  ABBA_VBITX_CON1    ((APBADDR)(ABBSYS_SD_base+0x0054))
   #define  ABBA_VBITX_CON2    ((APBADDR)(ABBSYS_SD_base+0x0058))
   #define  ABBA_VBITX_CON3    ((APBADDR)(ABBSYS_SD_base+0x005C))
   #define  ABBA_VBITX_CON4    ((APBADDR)(ABBSYS_SD_base+0x0060)) 
   #define  ABBA_VBITX_CON5    ((APBADDR)(ABBSYS_SD_base+0x0064)) 
   #define  ABBA_AUDIODL_CON0  ((APBADDR)(ABBSYS_SD_base+0x0080)) 
   #define  ABBA_AUDIODL_CON1  ((APBADDR)(ABBSYS_SD_base+0x0084)) 
   #define  ABBA_AUDIODL_CON2  ((APBADDR)(ABBSYS_SD_base+0x0088))
   #define  ABBA_AUDIODL_CON3  ((APBADDR)(ABBSYS_SD_base+0x008C)) 
   #define  ABBA_AUDIODL_CON4  ((APBADDR)(ABBSYS_SD_base+0x0090)) 
   #define  ABBA_AUDIODL_CON5  ((APBADDR)(ABBSYS_SD_base+0x0094)) 
   #define  ABBA_AUDIODL_CON6  ((APBADDR)(ABBSYS_SD_base+0x0098))  
   #define  ABBA_AUDIODL_CON7  ((APBADDR)(ABBSYS_SD_base+0x009C)) 
   #define  ABBA_AUDIODL_CON8  ((APBADDR)(ABBSYS_SD_base+0x00A0)) 
   #define  ABBA_AUDIODL_CON9  ((APBADDR)(ABBSYS_SD_base+0x00A4)) 
   #define  ABBA_AUDIODL_CON10 ((APBADDR)(ABBSYS_SD_base+0x00A8))
   #define  ABBA_AUDIODL_CON11 ((APBADDR)(ABBSYS_SD_base+0x00AC))
   #define  ABBA_AUDIODL_CON12 ((APBADDR)(ABBSYS_SD_base+0x00B0))
   #define  ABBA_AUDIODL_CON13 ((APBADDR)(ABBSYS_SD_base+0x00B4))
   #define  ABBA_AUDIODL_CON14 ((APBADDR)(ABBSYS_SD_base+0x00B8))
   #define  ABBA_AUDIODL_CON15 ((APBADDR)(ABBSYS_SD_base+0x00BC))
   #define  ABBA_AUDIODL_CON16 ((APBADDR)(ABBSYS_SD_base+0x00C0))
   #define  ABBA_AUDIODL_CON17 ((APBADDR)(ABBSYS_SD_base+0x00C4))
   #define  ABBA_AUDIODL_CON18 ((APBADDR)(ABBSYS_SD_base+0x00C8))
#endif

//#if !defined(MT6255) && !defined(MT6250) && !defined(MT6260) && !defined(MT6261) && !defined(MT2501) && !defined(MT2502)
//   #define  AFE_AUDIO_CON5 ((APBADDR)(MIXED_base+0x0214))      /* AFE Audio Analog-Circuit Control Register 1   */
//   #define  PMIC_CLASS_D_CTR  ((APBADDR)(MIXED_base+0x08BC))      /* PMIC Class-D Control   */
//   #define  PMIC_CLASS_D_CTR0 ((APBADDR)(MIXED_base+0x08B0))      /* PMIC Class-D Control   */
//   #define  PMIC_CLASS_D_CTR2 ((APBADDR)(MIXED_base+0x08B8))      /* PMIC Class-D Control   */
//   #define  PMIC_CLASSAB_CON0 ((APBADDR)(MIXED_base+0x09D0))      /* PMIC Class-D Control   */ 
//#endif

//=============================================================================================
//                  Sections: Register Audio Front End Hardware Control Register - For Multiple Die
//=============================================================================================
#if __AFE_MULTIEPLE_DIE__
#if defined(MT6250)
   //A Die
   #define ABBA_WR_PATH4         ((APBADDR)(ABBSYS_SD_base + 0x0010))
   #define ABBA_AA_CON0          ((APBADDR)(ABBSYS_SD_base + 0x0020))
   #define ABBA_AUDIO_CON0       ((APBADDR)(ABBSYS_SD_base + 0x0030))
   #define ABBA_AUDIO_CON1       ((APBADDR)(ABBSYS_SD_base + 0x0034))
   #define ABBA_AUDIO_CON2       ((APBADDR)(ABBSYS_SD_base + 0x0038))
   #define ABBA_AUDIO_CON3       ((APBADDR)(ABBSYS_SD_base + 0x003C))
   #define ABBA_AUDIO_CON4       ((APBADDR)(ABBSYS_SD_base + 0x0040))
   #define ABBA_AUDIO_CON5       ((APBADDR)(ABBSYS_SD_base + 0x0044))
   #define ABBA_AUDIO_CON6       ((APBADDR)(ABBSYS_SD_base + 0x0048))
   #define ABBA_VOICE_CON0       ((APBADDR)(ABBSYS_SD_base + 0x004C))
   #define ABBA_VOICE_CON1       ((APBADDR)(ABBSYS_SD_base + 0x0050))
   #define ABBA_VOICE_CON2       ((APBADDR)(ABBSYS_SD_base + 0x0054))
   #define ABBA_VOICE_CON3       ((APBADDR)(ABBSYS_SD_base + 0x0058))
   #define ABBA_VOICE_CON4       ((APBADDR)(ABBSYS_SD_base + 0x005C))
   #define ABBA_VOICE_CON5       ((APBADDR)(ABBSYS_SD_base + 0x0060))
   #define ABBA_APC_CON0         ((APBADDR)(ABBSYS_SD_base + 0x0070))
   #define ABBA_APC_CON1         ((APBADDR)(ABBSYS_SD_base + 0x0074))
   #define ABBA_AUX_CON0         ((APBADDR)(ABBSYS_SD_base + 0x0080))
   #define ABBA_AUX_CON1         ((APBADDR)(ABBSYS_SD_base + 0x0084))
   #define ABBA_AUX_CON2         ((APBADDR)(ABBSYS_SD_base + 0x0088))
   #define ABBA_AUX_CON3         ((APBADDR)(ABBSYS_SD_base + 0x008C))
   #define ABBA_AUX_CON4         ((APBADDR)(ABBSYS_SD_base + 0x0090))
   #define ABBA_AUX_CON5         ((APBADDR)(ABBSYS_SD_base + 0x0094))
   #define ABBA_AUX_CON6         ((APBADDR)(ABBSYS_SD_base + 0x0098))
   //D Die                       
   #define ABB_ABB_RSV_CON1      ((APBADDR)(ABB_D_SD_base + 0x0004))            
   #define ABB_AFUNC_DIN_CON0    ((APBADDR)(ABB_D_SD_base + 0x0010))
   #define ABB_WR_PATH0          ((APBADDR)(ABB_D_SD_base + 0x0010))
   #define ABB_WR_PATH2          ((APBADDR)(ABB_D_SD_base + 0x0018))
   #define ABB_WR_PATH3          ((APBADDR)(ABB_D_SD_base + 0x001C))
#if !defined(ABB_DD_WR_PATH0)
   #define ABB_DD_WR_PATH0       ((APBADDR)(ABB_D_SD_base + 0x0020))
#endif
   #define ABB_AUDIO_CON0        ((APBADDR)(ABB_D_SD_base + 0x0024))
   #define ABB_AUX_CON0          ((APBADDR)(ABB_D_SD_base + 0x0028))
   #define ABB_APC_CON0          ((APBADDR)(ABB_D_SD_base + 0x002C))

#elif defined(MT6260) 
   //Analog
   #define ABBA_WR_PATH4         ((APBADDR)(ABBSYS_SD_base + 0x0010))//0xA0720010
   #define ABBA_AUDIO_CON0       ((APBADDR)(ABBSYS_SD_base + 0x0030)) 
   #define ABBA_AUDIO_CON1       ((APBADDR)(ABBSYS_SD_base + 0x0034))
   #define ABBA_AUDIO_CON2       ((APBADDR)(ABBSYS_SD_base + 0x0038))
   #define ABBA_AUDIO_CON3       ((APBADDR)(ABBSYS_SD_base + 0x003C))
   #define ABBA_AUDIO_CON4       ((APBADDR)(ABBSYS_SD_base + 0x0040))
   #define ABBA_AUDIO_CON5       ((APBADDR)(ABBSYS_SD_base + 0x0044))
   #define ABBA_AUDIO_CON6       ((APBADDR)(ABBSYS_SD_base + 0x0048))
   #define ABBA_VOICE_CON0       ((APBADDR)(ABBSYS_SD_base + 0x004C))
   #define ABBA_VOICE_CON1       ((APBADDR)(ABBSYS_SD_base + 0x0050))
   #define ABBA_VOICE_CON2       ((APBADDR)(ABBSYS_SD_base + 0x0054))
   #define ABBA_VOICE_CON3       ((APBADDR)(ABBSYS_SD_base + 0x0058))
   #define ABBA_VOICE_CON4       ((APBADDR)(ABBSYS_SD_base + 0x005C))
   #define ABBA_VOICE_CON5       ((APBADDR)(ABBSYS_SD_base + 0x0060))
   //D2D
   #define D2D_A_AUD_CON0        ((APBADDR)(D2D_A_SD_base + 0x0010)) //0xA07A0010
   #define D2D_D_AUD_CON0        ((APBADDR)(D2D_D_SD_base + 0x0010)) //0xA0160010
   #define D2D_D_AUD_CON1        ((APBADDR)(D2D_D_SD_base + 0x0014))
#endif
#endif

//=============================================================================================
//                  Sections: Register Speaker Amp
//=============================================================================================
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define SPEAKER_base      PMU_base
#else
   #define SPEAKER_base      MIXED_base
#endif

#if defined(MT6252) || defined(MT6252H)
   #define PMIC_CLASSAB_CON0   ((APBADDR)(SPEAKER_base + 0x09D0))
   #define PMIC_CLASSAB_CON1   ((APBADDR)(SPEAKER_base + 0x09D4))
#else
   #define SPK_CON0            ((APBADDR)(SPEAKER_base + 0x0D00))
   #define SPK_CON3            ((APBADDR)(SPEAKER_base + 0x0D0C))
   #define SPK_CON4            ((APBADDR)(SPEAKER_base + 0x0D10))   
   #define SPK_CON6            ((APBADDR)(SPEAKER_base + 0x0D18))
   #define SPK_CON7            ((APBADDR)(SPEAKER_base + 0x0D1C))
   #if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #define SPK_CON8            ((APBADDR)(SPEAKER_base + 0x0D20)) // calibration
   #define SPK_CON9            ((APBADDR)(SPEAKER_base + 0x0D24)) // current sensor register
   
   #if defined(MT6261) || defined(MT2501) || defined(MT2502)
   //boost register
   #define VSBST_CON0          ((APBADDR)(SPEAKER_base + 0x0D28)) 
   #define VSBST_CON1          ((APBADDR)(SPEAKER_base + 0x0D2C)) 
   #define VSBST_CON2          ((APBADDR)(SPEAKER_base + 0x0D30)) 
   #define VSBST_CON3          ((APBADDR)(SPEAKER_base + 0x0D34)) 
   #define VSBST_CON4          ((APBADDR)(SPEAKER_base + 0x0D38)) 
   #define VSBST_CON5          ((APBADDR)(SPEAKER_base + 0x0D3C))
   #define VSBST_CON5          ((APBADDR)(SPEAKER_base + 0x0D40))
   #endif
   
   #if defined(MT6260)
      //charge pump
      #define CP_CON0             ((APBADDR)(SPEAKER_base + 0x0D50)) 
      #define CP_CON2             ((APBADDR)(SPEAKER_base + 0x0D58)) 
      #define CP_CON3             ((APBADDR)(SPEAKER_base + 0x0D5C)) 
   #endif
   #endif
#endif

#if defined(MT6260)
   #define HW_MISC_REG         ((volatile uint32*)(CONFIG_base+0x0240)) 
#endif
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: Function Prototypes
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

void AFE_TurnOnSpeaker( kal_uint8 aud_func );
void AFE_TurnOffSpeaker( kal_uint8 aud_func );
void AFE_FastCloseSpk(void);
void AFE_TurnOnMicrophone( kal_uint8 aud_func );
void AFE_TurnOffMicrophone( kal_uint8 aud_func );
kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func );
void AFE_TurnOnBluetooth( kal_uint16 param );
void AFE_TurnOffBluetooth( void );
void AFE_TurnOnDAI( void );
void AFE_TurnOffDAI( void );

void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle );
void AFE_TurnOffEDI( void );
kal_bool AFE_IsEDIOn( void );
void AFE_TurnOnFIR( kal_uint8 aud_func );
void AFE_TurnOffFIR( kal_uint8 aud_func );
void AFE_TurnOnAGC(void);
void AFE_TurnOffAGC(void);
kal_bool AFE_IsAGCOn(void);

void AFE_TurnOn8K(void);
void AFE_TurnOff8K(void);

kal_uint8 AFE_TurnOnMicBias( void );
void AFE_TurnOffMicBias(void);
void AFE_SetSidetoneVolume( kal_uint8 sidetone_volume );
kal_uint8 AFE_GetSidetoneVolume( void );
void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device );
void AFE_SetInputSource( kal_uint8 src );
kal_uint8 AFE_GetInputSource( void );
kal_bool AFE_IsAudioLoudSpk( void );
kal_bool AFE_IsAudioEarphone( void );
void AFE_EnableToneLoopBackFlag( kal_bool param );

void AFE_SetOutputGainControl(uint8 aud_func, uint32 total_gain);
void AFE_GetExtPGAInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number);
void AFE_GetExtPGAGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map);
void AFE_GetPGAGainMap(AFE_BUFFER_T eBuffer, kal_uint16 u2TotalLevel, kal_int8 *pPGA_Map);
kal_uint32 AFE_GetOutputGainControl(kal_uint8 aud_func);
void AFE_SetOutputGainControlDualPath( kal_uint8 aud_func, kal_uint32 ext_amp_gain );
void AFE_EnableVolumeProtection(kal_bool enable);
void AFE_Vibrate(bool enable);

void AFE_SetDigitalMute( kal_bool mute );
kal_uint16 AFE_GetDigiGain(void);
void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level );
void AFE_SetMicrophoneVolume( kal_uint8 mic_volume );
kal_uint8 AFE_GetMicrophoneVolume( void );
void AFE_MuteMicrophone( kal_bool mute );
kal_bool AFE_IsMicrophoneMuted( void );

void AFE_GetPathUsage(kal_uint8 u1AudFunc, PHONE_MODE_T ePhoneMode, AFE_BUFFER_T *peBuffer);
void AFE_GetPGAGainInfo(AFE_BUFFER_T eBuffer, kal_int16 *pi2MaxGain, 
                        kal_uint16 *pu2Step, kal_uint16 *pu2TotalLevel);
kal_bool AFE_GetNVRAMDigitalGainSupport(void);
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index );
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level);
void  AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index );
void AFE_Mute( kal_bool mute );
void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute );
void AFE_SetSidetone( kal_bool ec );
void AFE_Set_AudPlay_Flag(bool enable);
kal_bool AFE_IsInDelayOff(void);
kal_uint8 AFE_Disable_IdleOffDelay(void);
kal_bool AFE_IsKaraok(void);
void AFE_SetKaraoke(kal_bool enable);
void Audio_DelayCloseHandler(void* para);
void Audio_DelayCloseHandler(void* para);
kal_uint16 AFE_GetAudioDigiGain( kal_bool isAPM);
void AFE_AUDIO_BUF_PDN(void);
void AFE_SetGainFastRamp(kal_bool enable);
kal_uint8 AFE_GetAfeSate(void);

void AFE_SetHardwareMute(bool mute);
void AFE_EnableHardwareMuteSleep(bool isEnable);
kal_bool AFE_GetLoopbackStatus( void );
void AFE_DC_Calibration(kal_uint16* pwdc_offset, void(*DC_Calibration_CallBack)(kal_uint16 *pwdc_offset));
void AFE_RegisterBackup(void);
void AFE_AudAccDetInit(void);

void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index );
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level);

void AFE_Stop_and_Wait_DelayOff(kal_uint8 aud_func, kal_uint32 asp_fs);
void AFE_WaitReleaseVoltage(void);
void AFE_Force_Turnoff_CP(void);

#endif //__AFE_DEF_H

