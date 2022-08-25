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
 * pcm4way.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM4WAY/PCM2WAY interface 
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
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "l1audio.h"
#include "am.h"
#include "speech_def.h"
#include "audio_def.h"
#include "afe_def.h"
#include "media.h"
#include "pcm4way.h"

#define DSP_PCM_EX_LEN 160
#define PCM4WAY_STATE 0x1 
#define PCM2WAY_STATE 0x2
#if DSP_DATA_CARD_INTERFACE_SUPPORT
#define DACA_STATE    0x4
#endif

#if defined(MT6268) || defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PCMNWAY_DM_ADDR(x)		DSP2_DM_ADDR(2, (x))
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define PCMNWAY_DM_ADDR(x)		DSP2_DM_ADDR(5, (x))
#elif defined(MT6235) || defined(MT6235B)
#define PCMNWAY_DM_ADDR(x)		DSP2_DM_ADDR(3, (x))
#else
#define PCMNWAY_DM_ADDR(x)		DSP_DM_ADDR(2, (x))
#endif

static PCM_Ex_Config pcmEx; 
   
//static kal_uint32 u4UlPcmLen = 0;
//static kal_uint32 u4DlPcmLen = 0;
//static kal_uint32 u4DspPcmExLen = 160;

#if DSP_DATA_CARD_INTERFACE_SUPPORT
void pcmEx_hisrDlHdlr(void *param) 
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    if (pcmEx.b_wait_ul_dl)
    {
        if (pcmEx.hisr_state == 0 || pcmEx.hisr_state == 2)
        {
            pcmEx.hisr_state = 2;
        }
        else if (pcmEx.hisr_state == 1)
        {
            pcmEx.hisr_state = 3;
            if (pcmEx.dl_hdlr)
            {
                pcmEx.dl_hdlr();
            }
            pcmEx.hisr_state = 0;
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        if (pcmEx.dl_hdlr)
        {
            pcmEx.dl_hdlr();
        }
    }
#else   // chip compile option
    if (pcmEx.dl_hdlr)
    {
        pcmEx.dl_hdlr();
    }
#endif  // chip compile option
    
    return;
}

void pcmEx_hisrUlHdlr(void *param) 
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    if (pcmEx.b_wait_ul_dl)
    {
        if (pcmEx.hisr_state == 0 || pcmEx.hisr_state == 1)
        {
            pcmEx.hisr_state = 1;
        }
        else if (pcmEx.hisr_state == 2)
        {
            pcmEx.hisr_state = 4;
            if (pcmEx.ul_hdlr)
            {
                pcmEx.ul_hdlr();
            }
            pcmEx.hisr_state = 0;
        }
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        if (pcmEx.ul_hdlr)
        {
            pcmEx.ul_hdlr();
        }
    }
#else   // chip compile option
    if (pcmEx.ul_hdlr)
    {
        pcmEx.ul_hdlr();
    }
#endif  // chip compile option
    
    return;
}
#endif  // DSP_DATA_CARD_INTERFACE_SUPPORT

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void PCMNWAY_Common_Start (void (*pcmnway_dl_hdlr)(void), void (*pcmnway_ul_hdlr)(void), uint32 state, uint32 type, uint32 cfgDL, uint32 cfgUL)
{
    pcmEx.aud_id = L1Audio_GetAudioID();
    L1Audio_SetFlag(pcmEx.aud_id);

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
    VIBR_Vibration_Deactivate();
#endif
    PcmSink_TerminateSound();

    pcmEx.hisr_state = 0;
    L1Audio_HookHisrHandler(DP_D2C_PCM_EX_DL,(L1Audio_EventHandler)pcmEx_hisrDlHdlr, 0);
    L1Audio_HookHisrHandler(DP_D2C_PCM_EX_UL,(L1Audio_EventHandler)pcmEx_hisrUlHdlr, 0);
    pcmEx.state           = state;
	pcmEx.app_type        = type;
    pcmEx.dl_hdlr         = pcmnway_dl_hdlr;
    pcmEx.ul_hdlr         = pcmnway_ul_hdlr;
    pcmEx.DL_M2D_on       = (kal_bool)((cfgDL & USE_M2D_PATH)          != 0);
	pcmEx.DL_D2M_on       = (kal_bool)((cfgDL & USE_D2M_PATH)          != 0);
	pcmEx.DL_is_after_enh = (kal_bool)((cfgDL & DATA_SELECT_AFTER_ENH) != 0);
	pcmEx.UL_M2D_on       = (kal_bool)((cfgUL & USE_M2D_PATH)          != 0);
	pcmEx.UL_D2M_on       = (kal_bool)((cfgUL & USE_D2M_PATH)          != 0);
	pcmEx.UL_is_after_enh = (kal_bool)((cfgUL & DATA_SELECT_AFTER_ENH) != 0);
    
    return;
}

static void Config_and_Check_PCMEx_Start_State (kal_bool is_DACA)
{
    AM_PCM_EX_On((uint32)(&pcmEx));
    
    if (!is_DACA)
    {
        Pseudo_SAL_PcmEx_SetStateDL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_ON);
        Pseudo_SAL_PcmEx_SetStateUL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_ON);
    }
    
    {
        uint32 I = 0;
        kal_bool DL_on               = (kal_bool)(is_DACA ? pcmEx.app_type & DACA_USE_DL : pcmEx.DL_M2D_on | pcmEx.DL_D2M_on);
        kal_bool UL_on               = (kal_bool)(is_DACA ? pcmEx.app_type & DACA_USE_UL : pcmEx.UL_M2D_on | pcmEx.UL_D2M_on);
        Pseudo_Sal_PcmEx_Type_t type = is_DACA ? PSEUDO_SAL_PCMEX_TYPE_DACA : PSEUDO_SAL_PCMEX_TYPE_PNW;
        
        do
        {
            kal_bool is_ready = true;
        
            if (   DL_on && !Pseudo_SAL_PcmEx_CheckStateDL(type, PSEUDO_SAL_PCMEX_RDY)
                || UL_on && !Pseudo_SAL_PcmEx_CheckStateUL(type, PSEUDO_SAL_PCMEX_RDY)
               )
            {
                is_ready = false;
            }
            
            if (is_ready)
            {
                break;
            }
            
#ifndef L1D_TEST
            ASSERT(I < 22);  // wait 200ms  
            kal_sleep_task(2);
#endif
            I++;
        } while(1);
    }
    
    return;
}

static void PCMNWAY_Common_Stop (uint32 type)
{
    ASSERT(type == pcmEx.app_type);
	ASSERT(Pseudo_SAL_PcmEx_CheckStateUL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_OFF) || Pseudo_SAL_PcmEx_CheckStateUL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_RDY));
	ASSERT(Pseudo_SAL_PcmEx_CheckStateDL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_OFF) || Pseudo_SAL_PcmEx_CheckStateDL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_RDY));
    
    Pseudo_SAL_PcmEx_SetStateUL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_OFF);
    Pseudo_SAL_PcmEx_SetStateDL(PSEUDO_SAL_PCMEX_TYPE_PNW, PSEUDO_SAL_PCMEX_OFF);
    
    AM_PCM_EX_Off((uint32)(&pcmEx));
    
    L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX_DL);
    L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX_UL);
    pcmEx.dl_hdlr  = NULL;
    pcmEx.ul_hdlr  = NULL;
    pcmEx.state    = 0;
    pcmEx.app_type = P2W_APP_TYPE_UNDEFINE;
    pcmEx.am_type  = AM_PCMEX_TYPE_UNDEF;
    pcmEx.bandInfo = PSEUDO_SAL_PCM_NARROWBAND;
    
    L1Audio_ClearFlag(pcmEx.aud_id);
    L1Audio_FreeAudioID(pcmEx.aud_id);
    
    return;
}

void Extended_PCM4WAY_Start(void (*pcm4way_dl_hdlr)(void), void (*pcm4way_ul_hdlr)(void), uint32 type, uint32 cfgDL, uint32 cfgUL)
{
    PCMNWAY_Common_Start(pcm4way_dl_hdlr, pcm4way_ul_hdlr, PCM4WAY_STATE, type, cfgDL, cfgUL);
	
	// Map the pcm4way applicatoin type to am type
	// Setup the band informtion
	pcmEx.bandInfo = PSEUDO_SAL_PCM_NARROWBAND;
	switch (type)
	{
        case P4W_APP_CTM:
        case P4W_APP_TYPE_UNDER_CALL:
            pcmEx.am_type = AM_PCMEX_TYPE_DEDICATION;
            break;
        case P4W_APP_TYPE_WITHOUT_CALL:
            pcmEx.am_type = AM_PCMEX_TYPE_IDLE_WO_ENH;
            break;
        default:
            ASSERT(0);
            break;
	}
	
    // Configurate & check P4W start state
    Config_and_Check_PCMEx_Start_State(false);
    
    return;
}

void Extended_PCM4WAY_Stop(uint32 type)
{
    PCMNWAY_Common_Stop(type);
    
    return;
}

void Extended_PCM2WAY_Start(void (*pcm2way_dl_hdlr)(void), void (*pcm2way_ul_hdlr)(void), uint32 type, uint32 cfgDL, uint32 cfgUL)
{
    PCMNWAY_Common_Start(pcm2way_dl_hdlr, pcm2way_ul_hdlr, PCM2WAY_STATE, type, cfgDL, cfgUL);
    
    // Map the pcm2way applicatoin type to am type
    ASSERT(pcmEx.bandInfo != PSEUDO_SAL_PCM_UNDEFINED);  // Should use PCM2Way_SetFormat() to set format before P2W start
    
    // Setup the band informtion
    if (type == P2W_APP_TYPE_UNDER_CALL)
    {
        pcmEx.am_type = AM_PCMEX_TYPE_DEDICATION;
    }
    else if (type == P2W_APP_TYPE_WHITOUT_CALL)
    {
        pcmEx.am_type = AM_PCMEX_TYPE_IDLE_WO_ENH;
    }
    else if (type == P2W_APP_TYPE_VOIP)
    {
        pcmEx.am_type = AM_PCMEX_TYPE_IDLE;
    }
    else
    {
        ASSERT(0);
    }
    
    // Setup buffer size
    {
        P2W_Format format = PCM2Way_GetFormat() == PCMNWAY_BAND_INFO_WB ? P2W_FORMAT_WB_NORMAL : P2W_FORMAT_NORMAL;
        PCM2WAY_QueryBufSize(format, &pcmEx.u4DspPcmExMicLen, &pcmEx.u4DspPcmExSpkLen);
    }
    
    // Configurate & check P2W start state
    Config_and_Check_PCMEx_Start_State(false);
    
    return;
}  
   
void Extended_PCM2WAY_Stop(uint32 type)
{
    PCMNWAY_Common_Stop(type);
    
    PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
    
    return;
}

#else   // chip compile option

void pcmEx_hisrHdlr(void *param) 
{
   if(DP_PCM_EX_CTRL == 0) 
      return;
      
   if(pcmEx.state == PCM4WAY_STATE)
   {   
      ASSERT(DP_PCM_EX_CTRL == 0x102);    
   }
   else if(pcmEx.state == PCM2WAY_STATE) 
   {
      ASSERT(DP_PCM_EX_CTRL == 0x120);
   }   
   else 
      ASSERT(false);      

#if 0   
/* under construction !*/
/* under construction !*/
#else
   //u4UlPcmLen = DP_PCM_EX_UL_LEN;
   //u4DlPcmLen = DP_PCM_EX_DL_LEN; 
   //ASSERT(u4UlPcmLen == u4DspPcmExLen);
#endif
   pcmEx.hdlr();   
}

#endif  // chip compile option
//************** PCM 4-WAY *******************

void PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    pcmEx.b_wait_ul_dl = true;
    Extended_PCM4WAY_Start
    (
        pcm4way_hdlr,   // DL interrupt handler
        pcm4way_hdlr,   // UL interrupt handler
        type, 
        PNW_ENBLE + USE_D2M_PATH + USE_M2D_PATH                         + MCU_SET_P4W_ON,   // DL config
        PNW_ENBLE + USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH + MCU_SET_P4W_ON    // UL config
    );
#else   // chip compile option
   uint32 I;

   pcmEx.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmEx.aud_id );/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();

   pcmEx.am_type = pcmEx.app_type = type;   
   AM_PCM_EX_On(type);
   
   ASSERT(DP_PCM_EX_CTRL == 0); 
   
   L1Audio_HookHisrHandler(DP_D2C_PCM_EX,(L1Audio_EventHandler)pcmEx_hisrHdlr, 0);
   pcmEx.hdlr = pcm4way_hdlr; 
   pcmEx.state = PCM4WAY_STATE;
   DP_PCM_EX_CTRL = 0x101; 
   for(I = 0; ;I ++)
   {
      if(DP_PCM_EX_CTRL == 0x102)
         break;
#ifndef L1D_TEST
      ASSERT_REBOOT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
#endif
   }                          
            
#endif  // chip compile option
    
    return;
}

void PCM4WAY_Stop(uint32 type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    Extended_PCM4WAY_Stop(type);
    pcmEx.b_wait_ul_dl = false;
#else   // chip compile option
   ASSERT(DP_PCM_EX_CTRL == 0x102);   
   DP_PCM_EX_CTRL = 0;         
   AM_PCM_EX_Off(type);
   L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX); 
   L1Audio_ClearFlag( pcmEx.aud_id );
   L1Audio_FreeAudioID( pcmEx.aud_id );
   pcmEx.hdlr = NULL;
   pcmEx.state = 0;  
   pcmEx.app_type = P2W_APP_TYPE_UNDEFINE;
   pcmEx.am_type  = 0xFFFF;   
   pcmEx.FSM[0]    = pcmEx.FSM[1] = 0xFFFF;           
#endif  // chip compile option
    
    return;
}

////////////////////////////////////////////////////////////////////////////////

void PCM4WAY_GetFromMic(uint16 *ul_buf)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_UL1);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_UL1);
    if (AM_IsULSpeechMuted())
    {
        while(I-- > 0)
        {
            *ul_buf++ = 0;
        }
    }
    else
    {
        while(I-- > 0)
        {
            *ul_buf++ = *ptr++;
        }
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR);
   if( AM_IsULSpeechMuted() ){
      for( I = DSP_PCM_EX_LEN; I > 0; I-- )
         *ul_buf++ = 0;
   } else {
      *ul_buf = *ptr;   // dummy read
      for( I = DSP_PCM_EX_LEN; I > 0; I-- )    
          *ul_buf++ = *ptr++;
   }
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}
  
void PCM4WAY_PutToSE(const uint16 *ul_data)  
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_UL2);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_UL2);
    while(I-- > 0)
    {
        *ptr++ = *ul_data++;
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = *ul_data++;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = *ul_data++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

void PCM4WAY_FillSE(uint16 value)  
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_UL2);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_UL2);
    while(I-- > 0)
    {
        *ptr++ = value;
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   *ptr++ = value;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

void PCM4WAY_GetFromSD(uint16 *dl_buf)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_DL1);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_DL1);
    while(I-- > 0)
    {
        *dl_buf++ = *ptr++;
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 640);
   *dl_buf = *ptr;   // dummy read
   for( I = DSP_PCM_EX_LEN; I > 0; I-- )
      *dl_buf++ = *ptr++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

void PCM4WAY_PutToSpk(const uint16 *dl_data)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    while(I-- > 0)
    {
        *ptr++ = *dl_data++;
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 960);
   *ptr++ = *dl_data++;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = *dl_data++;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

void PCM4WAY_FillSpk(uint16 value)  
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16* ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    while(I-- > 0)
    {
        *ptr++ = value;
    }
#else   // chip compile option
   uint32 I;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 960);
   *ptr++ = value;
   for( I = DSP_PCM_EX_LEN - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

//************** PCM 2-WAY *******************

/**
Query the buffer size using in pcm2way
@format: type is P2W_Format, please privide the value for query
@mic_bufsize: return value of microphone buffer size in word(16-bit unit)
@spk_bufsize: return value of speaker buffer size in word(16-bit unit)
*/
void PCM2WAY_QueryBufSize(P2W_Format format, kal_uint32 *mic_bufsize, kal_uint32 *spk_bufsize)
{
   switch((kal_uint32)format){
      case P2W_FORMAT_NORMAL://SPH_P2W_UNDEF:
   	   *mic_bufsize = *spk_bufsize = 160;
   	   break;
	   
      case P2W_FORMAT_VOIP://SPH_P2W_VOIP:
         *mic_bufsize = *spk_bufsize = 160;
         break;
		 
#if defined(__DUAL_MIC_SUPPORT__)  
      case P2W_FORMAT_CAL://SPH_P2W_ENH_CAL:
         *spk_bufsize = 160;
         *mic_bufsize = 322; //160*2 +2;
         break;
		 
#if defined(__AMRWB_LINK_SUPPORT__) // + __DUAL_MIC_SUPPORT__
	  case P2W_FORMAT_WB_CAL://SPH_P2W_ENH_CAL for WB:
         *spk_bufsize = 320;
         *mic_bufsize = 642; //320*2 +2;
         break;
		 
#endif //__AMRWB_LINK_SUPPORT__ (+ __DUAL_MIC_SUPPORT__) 
#endif //__DUAL_MIC_SUPPORT__

	  case P2W_FORMAT_WB_NORMAL:
	  	 *mic_bufsize = *spk_bufsize = 320;
		 break;
		 
      default:
         ASSERT(0);
   }
}

uint32 PCM2Way_GetFormat(void)
{
   return pcmEx.bandInfo;    
}

void PCM2Way_SetFormat(uint32 format) //for caller, it's WB or NB
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    kal_uint32 bandInfo;
    
    switch (format)
    {
        case P2W_FORMAT_NORMAL:
        case P2W_FORMAT_VOIP:
#if defined(__DUAL_MIC_SUPPORT__)
        case P2W_FORMAT_CAL:
#endif
            bandInfo = PSEUDO_SAL_PCM_NARROWBAND;
            break;
        case P2W_FORMAT_WB_NORMAL:
#if defined(__DUAL_MIC_SUPPORT__) && defined(__AMRWB_LINK_SUPPORT__)
        case P2W_FORMAT_WB_CAL:
#endif
            bandInfo = PSEUDO_SAL_PCM_WIDEBAND;
            break;
        default:
            bandInfo = PSEUDO_SAL_PCM_UNDEFINED;
            break;
    }
    
    pcmEx.bandInfo = bandInfo;
    
    return;
#else
    kal_uint32 bandInfo;
    
    switch (format)
    {
        case P2W_FORMAT_NORMAL:
        case P2W_FORMAT_VOIP:
#if defined(__DUAL_MIC_SUPPORT__)
        case P2W_FORMAT_CAL:
#endif
            bandInfo = PCMNWAY_BAND_INFO_NB;
            break;
        case P2W_FORMAT_WB_NORMAL:
#if defined(__DUAL_MIC_SUPPORT__) && defined(__AMRWB_LINK_SUPPORT__)
        case P2W_FORMAT_WB_CAL:
#endif
            bandInfo = PCMNWAY_BAND_INFO_WB;
            break;
        default:
            bandInfo = PCMNWAY_BAND_INFO_UNSET;
            break;
    }
    
    pcmEx.bandInfo = bandInfo;
    
    return;
#endif
}

/**

@type: please refer to P2W_App_Type. 
	0 for pcm4way CTM, 
	1 for pcm2way Voice, 
	2 for pcm2way Voip, 
 	3 for pcm2Way record only(calibration used), 
 	4 for pcm2Way record&playback(calibration used)
*/
void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    pcmEx.b_wait_ul_dl = true;
    PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
    Extended_PCM2WAY_Start
    (
        pcm2way_hdlr,   // DL handler
        pcm2way_hdlr,   // UL handler
        type,
        PNW_ENBLE + USE_M2D_PATH                                        + MCU_SET_P2W_ON,   // DL config
        PNW_ENBLE                + USE_D2M_PATH + DATA_SELECT_AFTER_ENH + MCU_SET_P2W_ON    // UL config
    );
#else   // chip compile option
   uint32 I;

   pcmEx.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmEx.aud_id );/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/
   
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Deactivate();
#endif
   PcmSink_TerminateSound();

   // type checking
   //ASSERT(type==1 || type==2);   
   ASSERT(type==P2W_APP_TYPE_WHITOUT_CALL || type==P2W_APP_TYPE_VOIP 
#if defined(__DUAL_MIC_SUPPORT__)  
   || type==P2W_APP_TYPE_REC_ONLY_CAL || P2W_APP_TYPE_REC_PLAY_CAL==type
#endif //__DUAL_MIC_SUPPORT__
   );
   pcmEx.am_type = pcmEx.app_type = type;

#if defined(__DUAL_MIC_SUPPORT__)   
   if(type == P2W_APP_TYPE_REC_ONLY_CAL || type == P2W_APP_TYPE_REC_PLAY_CAL) {
   	
   	   ASSERT(pcmEx.bandInfo != PCMNWAY_BAND_INFO_UNSET); //calibration need to call PCM2Way_SetFormat() before PCM2WAY_Start()

	   //setting DSP sherif ==> DP_AUDIO_PAR for WB or NB and band information
	   if(PCMNWAY_BAND_INFO_NB == pcmEx.bandInfo){
	   	
	   	   PCM2WAY_QueryBufSize(P2W_FORMAT_CAL, 
		   		&(pcmEx.u4DspPcmExMicLen), &(pcmEx.u4DspPcmExSpkLen));
	  
		   *DP_AUDIO_PAR &= ~0x0008; //bit 3 = 0 is NB 
	   } else if (PCMNWAY_BAND_INFO_WB == pcmEx.bandInfo){
	   
	   	   PCM2WAY_QueryBufSize(P2W_FORMAT_WB_CAL, 
		   		&(pcmEx.u4DspPcmExMicLen), &(pcmEx.u4DspPcmExSpkLen));
		   
		   *DP_AUDIO_PAR |= 0x0008; //bit 3 = 1 is WB 
	   }   

	   pcmEx.u4DspPcmExMicLen -= 2; //AGC is put in the sherif instead of buffer
	   

	   //setting 
	   *DP_DMNR_CONTROL |= 0x0010; //bit4 of IO

	   //enable enhancement total power. --> request by Daniel
	   *DP_EC_SUPP |= 2; // bit 1 #define  FLAG_DDL_UL_ENTRY    2
	   
   }  else 
#endif //__DUAL_MIC_SUPPORT__
   {
   		PCM2WAY_QueryBufSize(P2W_FORMAT_NORMAL, 
		   		&(pcmEx.u4DspPcmExMicLen), &(pcmEx.u4DspPcmExSpkLen));
   }
      
   AM_PCM_EX_On(type); //AGC is on when 8k turn on
   
   ASSERT(DP_PCM_EX_CTRL == 0); 
   
   L1Audio_HookHisrHandler(DP_D2C_PCM_EX, (L1Audio_EventHandler)pcmEx_hisrHdlr, 0);
   pcmEx.hdlr = pcm2way_hdlr;
   pcmEx.state = PCM2WAY_STATE; 
   DP_PCM_EX_CTRL = 0x110; 
   for(I = 0; ;I ++)
   {
      if(DP_PCM_EX_CTRL == 0x120)
         break;
      ASSERT_REBOOT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
   }              
   pcmEx.FSM[0]    = pcmEx.FSM[1] = 0xFFFF;                                              
#endif  // chip compile option
    
    return;
}

void PCM2WAY_Stop(uint32 type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    Extended_PCM2WAY_Stop(type);
    pcmEx.b_wait_ul_dl = false;
#else   // chip compile option
   //ASSERT(type==1 || type==2);   
   ASSERT(type==P2W_APP_TYPE_WHITOUT_CALL || type==P2W_APP_TYPE_VOIP 
#if defined(__DUAL_MIC_SUPPORT__)   
   || type==P2W_APP_TYPE_REC_ONLY_CAL || P2W_APP_TYPE_REC_PLAY_CAL==type
#endif //__DUAL_MIC_SUPPORT__ 
   );
   
   ASSERT(DP_PCM_EX_CTRL == 0x120);      
   DP_PCM_EX_CTRL = 0;         
   AM_PCM_EX_Off(type);    
   L1Audio_UnhookHisrHandler(DP_D2C_PCM_EX); 

#if defined(__DUAL_MIC_SUPPORT__)
   if(type == P2W_APP_TYPE_REC_ONLY_CAL || type == P2W_APP_TYPE_REC_PLAY_CAL) {
       //reset to default
	   *DP_AUDIO_PAR &= ~0x0008; //bit 3 = 0 is NB 
	   
	   *DP_DMNR_CONTROL &= ~0x0010; 
	   //L1SP_SetULAGC(false); // AGC is defuault enable, so keeping the same

	   //disable enhancement total power. --> request by Daniel
	   *DP_EC_SUPP &= ~2; // bit 1 #define  FLAG_DDL_UL_ENTRY    2
	   
   }
#endif
   L1Audio_ClearFlag( pcmEx.aud_id );
   L1Audio_FreeAudioID( pcmEx.aud_id );
   
   PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
   
   pcmEx.hdlr = NULL ;
   pcmEx.state = 0;        
   pcmEx.bandInfo = PCMNWAY_BAND_INFO_UNSET;
   pcmEx.app_type = P2W_APP_TYPE_UNDEFINE;
   pcmEx.am_type  = 0xFFFF;
#endif  // chip compile option
    
    return;
}

/**
@deprecated. 

*/
void PCM2WAY_SetBufSize(uint32 size)
{
    pcmEx.u4DspPcmExMicLen = size;
	pcmEx.u4DspPcmExSpkLen = size;
}

void PCM2WAY_GetFromMic(uint16 *ul_buf)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_PNW_BUF_UL1);
    uint32 I = pcmEx.u4DspPcmExMicLen;
    if (AM_IsULSpeechMuted())
    {
        while (I-- > 0)
        {
            *ul_buf++ = 0;
        }
    }
    else
    {
        while (I-- > 0)
        {
            *ul_buf++ = *ptr++;
        }
    }
#else   // chip compile option
   uint32 I;
   int32 bufLength;

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR);

   bufLength = pcmEx.u4DspPcmExMicLen;

#if defined(__DUAL_MIC_SUPPORT__) //every buffer is contain only one mic WHEN CALIBRATION
   if(P2W_APP_TYPE_REC_ONLY_CAL == pcmEx.app_type || P2W_APP_TYPE_REC_PLAY_CAL == pcmEx.app_type) {
      bufLength >>= 1;
   }
#endif


   if( AM_IsULSpeechMuted() ){
      for( I = bufLength; I > 0; I-- )
         *ul_buf++ = 0;
   } else {
      *ul_buf = *ptr;   // dummy read
      for( I = bufLength; I > 0; I-- )    
          *ul_buf++ = *ptr++;
   }

#if defined(__DUAL_MIC_SUPPORT__) //every buffer is contain only one mic WHEN CALIBRATION, process the second one
   if(P2W_APP_TYPE_REC_ONLY_CAL == pcmEx.app_type || P2W_APP_TYPE_REC_PLAY_CAL == pcmEx.app_type)
   { 
      //ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + bufLength*2);
      ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + pcmEx.u4DspPcmExMicLen); // i.e. DP_PCM_EX_PTR + bufLength *2
      if( AM_IsULSpeechMuted() ){
         for( I = bufLength; I > 0; I-- )
            *ul_buf++ = 0;
      } else {
         *ul_buf = *ptr;   // dummy read
         for( I = bufLength; I > 0; I-- )    
            *ul_buf++ = *ptr++;
      }

   	  *ul_buf++ = *DP_AGC_SW_GAIN1;
	  *ul_buf++ = *DP_AGC_SW_GAIN2;
   }
#endif //__DUAL_MIC_SUPPORT__

   
#else             
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
} 

void PCM2WAY_PutToSpk(const uint16 *dl_data)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    uint32 I = pcmEx.u4DspPcmExSpkLen;
    while (I-- > 0)
    {
        *ptr++ = *dl_data++;
    }
#else   // chip compile option
   uint32 I;      

#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   //volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + u4DspPcmExLen*2);
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + pcmEx.u4DspPcmExMicLen*2);

   *ptr++ = *dl_data++;
   for( I = pcmEx.u4DspPcmExSpkLen - 1 ; I > 0; I-- )
      *ptr++ = *dl_data++;
#else   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}


void PCM2WAY_FillSpk(uint16 value)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf(PSEUDO_SAL_PCMEX_PNW_BUF_DL2);
    uint32 I = pcmEx.u4DspPcmExSpkLen;
    while (I-- > 0)
    {
        *ptr++ = value;
    }
#else   // chip compile option
   uint32 I;   
#if 1    // Use address mode to prevent idma being interrupted by other ISR, ie. L1D.
   //volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + 320);
   volatile uint16* ptr = PCMNWAY_DM_ADDR(DP_PCM_EX_PTR + pcmEx.u4DspPcmExMicLen*2); //Mic buffer is pin-pon,
   *ptr++ = value;
   for( I = pcmEx.u4DspPcmExSpkLen - 1 ; I > 0; I-- )
      *ptr++ = value;
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif  // chip compile option
    
    return;
}

#if DSP_DATA_CARD_INTERFACE_SUPPORT

void DACA_Start(void (*daca_dl_hdlr)(void), void (*daca_ul_hdlr)(void), DACA_APP_TYPE app_type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    pcmEx.aud_id = L1Audio_GetAudioID();
    L1Audio_SetFlag(pcmEx.aud_id);
    
    PcmSink_TerminateSound();
    
    pcmEx.state        = DACA_STATE;
    pcmEx.b_wait_ul_dl = false;
    pcmEx.hisr_state   = 0;
    L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_DL,(L1Audio_EventHandler)pcmEx_hisrDlHdlr, 0);
    L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_UL,(L1Audio_EventHandler)pcmEx_hisrUlHdlr, 0);
    pcmEx.dl_hdlr  = daca_dl_hdlr;
    pcmEx.ul_hdlr  = daca_ul_hdlr;
    pcmEx.app_type = app_type;
    pcmEx.am_type  = app_type & DACA_IN_PHONE_CALL ? AM_PCMEX_TYPE_DACA_DEDICATION : AM_PCMEX_TYPE_DACA_IDLE_WO_ENH;
    pcmEx.bandInfo = app_type & DACA_USE_NB ? PSEUDO_SAL_PCM_NARROWBAND : PSEUDO_SAL_PCM_WIDEBAND;
    
    if (app_type & DACA_USE_UL)
    {
        Pseudo_SAL_PcmEx_SetStateUL(PSEUDO_SAL_PCMEX_TYPE_DACA, PSEUDO_SAL_PCMEX_ON);
    }
    
    if (app_type & DACA_USE_DL)
    {
        Pseudo_SAL_PcmEx_SetStateDL(PSEUDO_SAL_PCMEX_TYPE_DACA, PSEUDO_SAL_PCMEX_ON);
    }
    
    // Configurate & check DACA state
    Config_and_Check_PCMEx_Start_State(true);
#else   // chip compile option
   uint32 I;
   PcmSink_TerminateSound();
   pcmEx.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmEx.aud_id );
   pcmEx.app_type = app_type;
   switch(app_type){
   case DACA_APP_TYPE_ACTIVE_UL_DL_NB:    
      pcmEx.am_type =100;  
      pcmEx.FSM[0]= 0x11;
      pcmEx.FSM[1]= 0x22;
      break;
   case DACA_APP_TYPE_ACTIVE_UL_NB:
      pcmEx.am_type =100;
      pcmEx.FSM[0]= 0x1;
      pcmEx.FSM[1]= 0x2;      
      break;
   case DACA_APP_TYPE_ACTIVE_DL_NB:
      pcmEx.am_type =100;
      pcmEx.FSM[0]= 0x10;
      pcmEx.FSM[1]= 0x20;      
      break;        
   case DACA_APP_TYPE_IDLE_UL_DL_NB:      
      pcmEx.am_type =101;
      pcmEx.FSM[0]= 0x11;
      pcmEx.FSM[1]= 0x22;      
      break;
   case DACA_APP_TYPE_IDLE_UL_NB:
      pcmEx.am_type =101;
      pcmEx.FSM[0]= 0x1;
      pcmEx.FSM[1]= 0x2;       
      break;
   case DACA_APP_TYPE_IDLE_DL_NB:
      pcmEx.am_type =101;
      pcmEx.FSM[0]= 0x10;
      pcmEx.FSM[1]= 0x20;       
      break;  
   default:
      ASSERT(0);                        
   }   
   AM_PCM_EX_On(pcmEx.am_type);   
   //ASSERT(DP_PCM_EX_CTRL == 0); 
      
   L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_DL,(L1Audio_EventHandler)pcmEx_hisrDlHdlr, 0);
   L1Audio_HookHisrHandler(DP_D2C_DACA_REQ_UL,(L1Audio_EventHandler)pcmEx_hisrUlHdlr, 0);
   pcmEx.dl_hdlr = daca_dl_hdlr; 
   pcmEx.ul_hdlr = daca_ul_hdlr;  

   pcmEx.state = DACA_STATE; 
   DSP_DACA_CTRL = pcmEx.FSM[0]; 
   for(I = 0; ;I ++)
   {
      if((DSP_DACA_CTRL == pcmEx.FSM[1]))
         break;
      ASSERT(I < 22);  // wait 200ms  
      kal_sleep_task(2);
   }    
#endif  // chip compile option
    
    return;
}

void DACA_Stop(DACA_APP_TYPE app_type)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    ASSERT(pcmEx.app_type == app_type && pcmEx.state == DACA_STATE);
    ASSERT(Pseudo_SAL_PcmEx_CheckStateUL(PSEUDO_SAL_PCMEX_TYPE_DACA, pcmEx.app_type & DACA_USE_UL ? PSEUDO_SAL_PCMEX_RDY : PSEUDO_SAL_PCMEX_OFF));
    ASSERT(Pseudo_SAL_PcmEx_CheckStateDL(PSEUDO_SAL_PCMEX_TYPE_DACA, pcmEx.app_type & DACA_USE_DL ? PSEUDO_SAL_PCMEX_RDY : PSEUDO_SAL_PCMEX_OFF));
    
	Pseudo_SAL_PcmEx_SetStateUL(PSEUDO_SAL_PCMEX_TYPE_DACA, PSEUDO_SAL_PCMEX_OFF);
	Pseudo_SAL_PcmEx_SetStateDL(PSEUDO_SAL_PCMEX_TYPE_DACA, PSEUDO_SAL_PCMEX_OFF);
    
    AM_PCM_EX_Off((uint32)&pcmEx);
    
    L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_DL);
    L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_UL);
    pcmEx.dl_hdlr  = NULL;
    pcmEx.ul_hdlr  = NULL;
    pcmEx.state    = 0;
    pcmEx.app_type = DACA_APP_TYPE_UNDEFINE;
    pcmEx.am_type  = AM_PCMEX_TYPE_UNDEF;
    pcmEx.bandInfo = PSEUDO_SAL_PCM_UNDEFINED;
    
    L1Audio_ClearFlag(pcmEx.aud_id);
    L1Audio_FreeAudioID(pcmEx.aud_id);
#else   // chip compile option
   ASSERT((pcmEx.app_type == app_type) && (pcmEx.state == DACA_STATE) && (DSP_DACA_CTRL == pcmEx.FSM[1]));   
   DSP_DACA_CTRL = 0;         
   AM_PCM_EX_Off(pcmEx.am_type);    
   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_DL); 
   L1Audio_UnhookHisrHandler(DP_D2C_DACA_REQ_UL); 
   pcmEx.dl_hdlr   = pcmEx.ul_hdlr = NULL;
   pcmEx.state     = 0; 
   pcmEx.app_type  = DACA_APP_TYPE_UNDEFINE; 
   pcmEx.am_type   = 0xFFFF;
   pcmEx.FSM[0]    = pcmEx.FSM[1] = 0xFFFF;         
   L1Audio_ClearFlag( pcmEx.aud_id );
   L1Audio_FreeAudioID( pcmEx.aud_id );
#endif  // chip compile option
    
    return;
}

void DACA_GetFromSD(uint16 *dl_buf)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_DACA_BUF_DL);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_DACA_BUF_DL);
    while (I-- > 0)
    {
        *dl_buf++ = *ptr++;
    }
#else   // chip compile option
   uint32 I;

   volatile uint16* ptr = PCMNWAY_DM_ADDR(DSP_DACA_PTR_DL);
   *dl_buf = *ptr;   // dummy read
   for( I = 160 ; I > 0; I-- )
      *dl_buf++ = *ptr++;

#endif  // chip compile option
    
    return;
}

void DACA_PutToSE(const uint16 *ul_data)  
{ 
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    volatile uint16 *ptr = Pseudo_SAL_PcmEx_GetBuf   (PSEUDO_SAL_PCMEX_DACA_BUF_UL);
    uint32 I             = Pseudo_SAL_PcmEx_GetBufLen(PSEUDO_SAL_PCMEX_DACA_BUF_UL);
    while (I-- > 0)
    {
        *ptr++ = *ul_data++;
    }
#else   // chip compile option
   uint32 I;

   volatile uint16* ptr = PCMNWAY_DM_ADDR(DSP_DACA_PTR_UL);
   for( I = 160; I > 0; I-- )
      *ptr++ = *ul_data++;

#endif  // chip compile option
    
    return;
}

#endif
