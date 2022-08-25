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
 * l1audio_service.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Task / L1Audio Service 
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
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "intrCtrl.h"
#include "string.h"
#include "hisr_config.h"
#include "stack_config.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "audio_def.h"
#include "VMI.h"
#include "media.h"
#include "l1audio_trace.h"
#include "ddload.h"
#include "am.h"
#include "afe.h"
#include "common_def.h"
#include "speech_def.h"
#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#if defined( __CENTRALIZED_SLEEP_MANAGER__ ) && (defined(MT6260)|| defined(MT6261) || defined(MT2501) || defined(MT2502))
#include "RM_public.h"
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__)
#include "AudCom.h"
#include "AudComUtil.h"
#endif

#if defined(__AUDIO_DSP_LOWPOWER_V2__)
#include "audlp2_drv.h"
#endif

#if (defined( VR_CYBERON ) && defined( __BT_AUDIO_VIA_SCO__ )) || defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
#define  MAX_HISR_HANDLER        6
#else
#define  MAX_HISR_HANDLER        5
#endif

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );
void toneLoopbackRecInit( void );
extern void DisableIRQ(void);

#ifdef MTK_SLEEP_ENABLE
uint8    L1SM_GetHandle( void );
void     L1SM_SleepEnable( uint8 handle );
void     L1SM_SleepDisable( uint8 handle );
#define  GET_SLEEP_HANDLE()   {  l1audio.sleep_handle=L1SM_GetHandle();       }
#define  SLEEP_LOCK()         {  L1SM_SleepDisable( l1audio.sleep_handle );   }
#define  SLEEP_UNLOCK()       {  L1SM_SleepEnable( l1audio.sleep_handle );    }
#else /* MTK_SLEEP_ENABLE */
#define  GET_SLEEP_HANDLE()
#define  SLEEP_LOCK()
#define  SLEEP_UNLOCK()
#endif /* MTK_SLEEP_ENABLE */

#if defined(__VOICE_CHANGER_SUPPORT__)
extern void VCHG_Initialize();
#endif

extern uint32 L1I_GetTimeStamp( void );

#if (defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) )
#if defined(__AUDIO_POWERON_RESET_DSP__)
   extern unsigned short  L1D_Audio_RestartDSP( void );
   extern void            L1D_Audio_NoNeedDSP( void );
   extern void AFE_Init_status(kal_bool flag);
#else
   extern kal_uint8  L1SM_IntGetHandle( void );
      extern void       L1SM_Multi_SW_WakeUp(void); 
      extern void       L1SM_IntSleepDisable( kal_uint8 handle );
      extern void       L1SM_IntSleepEnable( kal_uint8 handle );
   extern kal_uint8  L1D_MD2G_PWD_GetHandle( void );
   extern      void  L1D_MD2G_PWD_Disable( kal_uint8 handle );
   extern      void  L1D_MD2G_PWD_Enable( kal_uint8 handle );
#endif
#endif

/* ------------------------------------------------------------------------------ */

static struct {
   uint32               runningState;
   uint32               disallowSleepState;
   kal_eventgrpid       aud_events;
   uint16               media_flag;
   uint16               d2c_itype;
   uint32               d2c_l1FN;
   uint32               retrieved_events;
   uint32               events_l1FN;
   kal_hisrid           hisr;

   L1Audio_EventHandler evHandler[MAX_AUDIO_FUNCTIONS];
   void                 *evData[MAX_AUDIO_FUNCTIONS];
   uint32               id_flag;
   uint32               event_flag;
   L1Audio_EventHandler hisrHandler[MAX_HISR_HANDLER];
   uint16               hisrMagicNo[MAX_HISR_HANDLER];
   void                 *hisrUserData[MAX_HISR_HANDLER];
   uint16               hisrMagicFlag;
   L1Audio_EventHandler postHisrHandler;
   uint8                sleep_handle;
   
   int8                dsp_slow_idle_counter;
   
   uint32               audio_cpd_count;
   uint16               debug_info[NUM_DEBUG_INFO];
   kal_uint8            md2g_pdn_handle;
   kal_uint8            l1sm_handle;
   kal_uint8            audio_cpd_count_current;
   kal_bool             isInitiated;
   kal_semid            sema;
} l1audio;

/* ------------------------------------------------------------------------------ */
#if defined(MT6250) || defined(MT6280) || defined(MT6583) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static void AUDIO_DELAY(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}
#endif

extern void L1D_DSP_EnableDspSlowIdle( void );
int8 L1Audio_Disable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    dis_check_counter; 

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter++;
   dis_check_counter = l1audio.dsp_slow_idle_counter;
   
   DP_SLOW_IDLE_CTRL = 0xFFFF;
   RestoreIRQMask( savedMask );

   return dis_check_counter;

}

int8 L1Audio_Enable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    en_check_counter;
   
   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter--;
   en_check_counter = l1audio.dsp_slow_idle_counter;
   
   if ( l1audio.dsp_slow_idle_counter == 0 )   
       L1D_DSP_EnableDspSlowIdle();      

   RestoreIRQMask( savedMask );   
   ASSERT( en_check_counter >= 0 );

   return en_check_counter;
}

kal_bool L1Audio_CheckAudioID( kal_uint16 audio_id )
{
   if( l1audio.id_flag & (1 << audio_id) )
      return true;
   return false;
}

uint16 L1Audio_GetAudioID( void )
{
   uint32 I;
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
      if( (l1audio.id_flag & (1<<I)) == 0 ) {
         l1audio.id_flag |= (1<<I);
         break;
      }
   }
   RestoreIRQMask( savedMask );

   ASSERT( (l1audio.runningState & (1 << I)) == 0 );
   ASSERT_REBOOT( I < MAX_AUDIO_FUNCTIONS );
   return (uint16)I;
}

void L1Audio_FreeAudioID( uint16 aud_id )
{
   uint32 savedMask;
   uint32 retrieved_events;
   kal_retrieve_eg_events(l1audio.aud_events,(1<<aud_id),KAL_OR_CONSUME,&retrieved_events,0);
   ASSERT( (l1audio.runningState & (1 << aud_id)) == 0 );
   ASSERT( l1audio.id_flag & (1<<aud_id) );
   savedMask = SaveAndSetIRQMask();
   l1audio.id_flag &= ~(1<<aud_id);
   l1audio.retrieved_events &= ~(1<<aud_id);
   RestoreIRQMask( savedMask );
}

void L1Audio_SetEventHandler( uint16 audio_id, L1Audio_EventHandler handler )
{
   l1audio.evHandler[audio_id] = handler;
}

void L1Audio_SetEvent( uint16 audio_id, void *data )
{
   l1audio.evData[audio_id] = data;
   kal_set_eg_events( l1audio.aud_events, 1 << audio_id, KAL_OR );      /* Activate L1Audio Task */
}

void L1Audio_LSetEvent( uint16 audio_id, void *data )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   l1audio.evData[audio_id] = data;
   l1audio.event_flag |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_activate_hisr( l1audio.hisr );                                   /* Activate L1Audio HISR */
}

bool L1Audio_CheckFlag( uint16 audio_id )      /* return true if error happens */
{
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   if( l1audio.runningState & (1 << audio_id) )
      return true;
   return false;
}

bool L1Audio_CheckFlag_MD2G( uint16 audio_id )      /* return true if error happens */
{
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   if( l1audio.disallowSleepState & (1 << audio_id) )
      return true;
   return false;
}

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

#define MCU_TOPSM_SM_SW_WAKEUP                   ((APBADDR32)(MCU_TOPSM_base+0x08A0))  //32bit
#define MCU_TOPSM_SM_REQ_MASK                    ((APBADDR32)(MCU_TOPSM_base+0x08B0))  //32bit
#define MCU_TOPSM_SM_MAS_RDY_STA                 ((APBADDR32)(MCU_TOPSM_base+0x08F0))  //32bit

#define SHARE_D2M_WAKEUP_CTL                     ((APBADDR)(SHARE_base + 0x0078))   //16bit
#define SHARE_D2M_WAKEUP_STA                     ((APBADDR)(SHARE_base + 0x007C))   //16bit

void Audio_DSP_Wakeup_Eevent_Setting(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint16 reg_value;

   savedMask = SaveAndSetIRQMask();

   reg_value  = *SHARE_D2M_WAKEUP_CTL;
   if(flag){
      reg_value |= (0x1 << 0);
   }
   else{
      reg_value &= ~(0x1 << 0);
   }
   *SHARE_D2M_WAKEUP_CTL = reg_value;
   RestoreIRQMask( savedMask );
}

void Audio_DSP_Wakeup_Eevent_clean(void)
{
   *SHARE_D2M_WAKEUP_STA = 1;
}
#endif //defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
void Audio_SW_CPD_Event_Setting(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint32 reg_value;

   savedMask = SaveAndSetIRQMask();

   reg_value  = *MCU_TOPSM_SM_REQ_MASK;

   if(flag)
      reg_value &= ~(0x00000002);                //bit[1]: mask for sw request

   *MCU_TOPSM_SM_REQ_MASK = reg_value;
   RestoreIRQMask( savedMask );
}

void Audio_SW_CPD_Eevent_ChangeMode(kal_bool flag)
{
   kal_uint32 savedMask;
   kal_uint32 reg_value;

   if(flag){
      savedMask = SaveAndSetIRQMask();
   	  reg_value  = *MCU_TOPSM_SM_SW_WAKEUP;
      reg_value |= (0x1 << 0);                 //bit[0]: request to md2gsys
      *MCU_TOPSM_SM_SW_WAKEUP = reg_value;
      RestoreIRQMask( savedMask );
      
//This only needs to be applied to these three chips due to CPD HW status bug
#if defined(MT6250) || defined(MT6280) || defined(MT6583) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      AUDIO_DELAY(33);
#endif
      while(!(*MCU_TOPSM_SM_MAS_RDY_STA & 0x00000001));
   }
   else{
      savedMask = SaveAndSetIRQMask();
   	  reg_value  = *MCU_TOPSM_SM_SW_WAKEUP;
      reg_value &= ~(0x1 << 0);
      *MCU_TOPSM_SM_SW_WAKEUP = reg_value;
      RestoreIRQMask( savedMask );
   }
}
#else
//for other chip, this CPD control was moved to L1C : RM_Resource_Control()
#endif //defined(MT6250)

#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
static void Audio_Wake_DSP(uint16 audio_id, kal_bool flag)
{
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
   if(flag)
   {
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      RM_Resource_Control (RM_MODEM_DSP_1, flag);
#else
      Audio_SW_CPD_Event_Setting(flag);
      Audio_SW_CPD_Eevent_ChangeMode(flag);
#endif

#if defined(MTK_SLEEP_ENABLE)
#if defined(__AUDIO_POWERON_RESET_DSP__)
        {
            extern void AFE_RegisterStore(void);
            AFE_RegisterStore();                               //restore AFE register
        }
      {
         unsigned short DSP_status;     
         DSP_status = L1D_Audio_RestartDSP();
         ASSERT(!DSP_status);
      }
   #else
      L1SM_IntSleepDisable( l1audio.l1sm_handle );
      L1SM_Multi_SW_WakeUp();
      L1D_MD2G_PWD_Disable(l1audio.md2g_pdn_handle);
      L1SM_IntSleepEnable( l1audio.l1sm_handle );
   #endif
#endif
      Audio_DSP_Wakeup_Eevent_Setting(flag);      
      
      l1audio.audio_cpd_count++;
      l1audio.audio_cpd_count_current++;
   } else {
      Audio_DSP_Wakeup_Eevent_Setting(flag);

#if defined(MTK_SLEEP_ENABLE)
   #if defined(__AUDIO_POWERON_RESET_DSP__)
      L1D_Audio_NoNeedDSP();
      AFE_RegisterBackup();                         //Backup AFE register
   #else
      L1D_MD2G_PWD_Enable(l1audio.md2g_pdn_handle);
   #endif
#endif

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
      RM_Resource_Control (RM_MODEM_DSP_1, flag);
#else
      Audio_SW_CPD_Eevent_ChangeMode(flag);
#endif
      l1audio.audio_cpd_count_current--;
#if __DSP_WAKEUP_EVENT__
      Audio_DSP_Wakeup_Eevent_clean();
#endif
   }
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
}
#endif // defined( __CENTRALIZED_SLEEP_MANAGER__ )


void L1Audio_SetFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.runningState);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.runningState);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.runningState & (1 << audio_id)) == 0 );

   if( (l1audio.runningState == 0) && (l1audio.disallowSleepState == 0) ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id, KAL_TRUE);
#endif
   }

   if (l1audio.runningState == 0)
      SLEEP_LOCK();

   savedMask = SaveAndSetIRQMask();
   l1audio.runningState |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}


void L1Audio_ClearFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.runningState);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.runningState);
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.runningState & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.runningState &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   if(l1audio.runningState == 0 ) {
      SLEEP_UNLOCK();
   }
   
   if( (l1audio.runningState == 0) && (l1audio.disallowSleepState == 0) ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id, KAL_FALSE);
#endif
  }
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_SetFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.runningState);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.runningState);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.disallowSleepState & (1 << audio_id)) == 0 );

   if( (l1audio.runningState == 0) && (l1audio.disallowSleepState == 0) ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_TRUE);
#endif
   }

   savedMask = SaveAndSetIRQMask();
   l1audio.disallowSleepState |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_ClearFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.runningState);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.runningState);
      
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.disallowSleepState & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.disallowSleepState &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   
   if( (l1audio.runningState == 0) && (l1audio.disallowSleepState == 0) ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_FALSE);
#endif
   }
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_AllowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;
   
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.runningState & (1 << audio_id) );
   
   savedMask = SaveAndSetIRQMask();
   l1audio.disallowSleepState &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   
   if( (l1audio.runningState & l1audio.disallowSleepState) == 0 )
      SLEEP_UNLOCK();
}

void L1Audio_DisallowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;
   
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.runningState & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.disallowSleepState |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   
   if( (l1audio.runningState & l1audio.disallowSleepState) )
      SLEEP_LOCK();
}

void L1Audio_EnterDedicatedMode( void )
{
}

void L1Audio_LeaveDedicatedMode( void )
{
}
/* ------------------------------------------------------------------------------ */
/*  L1Audio HISR                                                                  */
/* ------------------------------------------------------------------------------ */

void L1Audio_HISR( void )
{
   uint32 savedMask;
   L1Audio_Disable_DSPSlowIdle();

   if( l1audio.hisrMagicFlag ) {
      int32  I;
      kal_uint16 temp;
      temp = *AUDIO_DBG_SHERIF;
      for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
         if( l1audio.hisrMagicFlag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.hisrMagicFlag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            kal_brief_trace( TRACE_GROUP_DSPDEBUG, DSPDEBUG_CTRLFLOW, temp, I);
            l1audio.hisrHandler[I]( l1audio.hisrUserData[I] );
            if( l1audio.postHisrHandler != (L1Audio_EventHandler)0 )
               l1audio.postHisrHandler( (void*)l1audio.hisrMagicNo[I] );
         }
      }
   }
#if !defined( MED_MODEM )
//special case when MED_MODEM( of MED_PROFILE ) is defined, all Media_Play, Media_record
//do not exist, then mediaHisr could be removed to reduce memory size.
//In the future, when old interface are not used, mediaHisr should be removed officially.
   if( l1audio.media_flag != 0 ) {        /* Audio File Playback/Recording */
#ifndef __L1_STANDALONE__ // avoid link error
#if defined(MT6250)
      mediaHisr( l1audio.media_flag );
#else
      // Do nothing
#endif
#endif
      if( l1audio.postHisrHandler != (L1Audio_EventHandler)0 )
         l1audio.postHisrHandler( (void*)l1audio.media_flag );
      l1audio.media_flag = 0;
   }
#endif
   if( l1audio.event_flag ) {
      int16 I;
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( l1audio.event_flag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.event_flag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            L1Audio_SetEvent( I, l1audio.evData[I] );
         }
      }
   }

   // To restore slow idle ctrl for DSP
   L1Audio_Enable_DSPSlowIdle();
}

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
void L1Audio_TrigD2CHisr(uint16 magicNo)
{
    int32 I;
    
    for (I = 0; I < MAX_HISR_HANDLER; I++)
    {
        if (magicNo == l1audio.hisrMagicNo[I])
        {
            l1audio.hisrMagicFlag |= (1<<I);
            kal_activate_hisr(l1audio.hisr);
            return;
        }
    }
}
#else   // chip compile option
#endif  // chip compile option

void L1SP_D2C_LISR( uint16 itype )
{
   l1audio.d2c_itype = itype;
   l1audio.d2c_l1FN = L1I_GetTimeStamp();
   L1Audio_Msg_DSP_INT( itype );

#if __DSP_WAKEUP_EVENT__
   Audio_DSP_Wakeup_Eevent_clean();
#endif

#if defined(MT6268) //work around in 3G, there is DP_D2C_SE_DONE int. There might be error operate especially when InterRAT HO
   if( itype == DP_D2C_SE_DONE && AM_IsSpeechOn() )
      return;
#endif
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if(itype == D2C_DSP_DEAD_INT_ID){
#ifndef  L1D_TEST 
      {
         ASSERT_DUMP_PARAM_T dump_param;
         dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);    
         dump_param.len[0]  = 70*2;
         dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);  
         dump_param.len[1]  = 180*2;
         dump_param.addr[2] = 0;    //End of dump param
         EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
      }
#else
      {
         extern void  L1DTest_AssertFail(void);
         L1DTest_AssertFail();
      }
#endif
   }
#endif // #if defined(MT6236) || defined(MT6236B) || defined(MT6256)

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    {
        bool dsp_ok = false;
        uint32 sph_int = 0;
        bool from_sph = Pseudo_SAL_DSPINT_Resolve(itype, &sph_int);
        
        if (from_sph)
        {
            {
                kal_int16 i;
                for (i = 1; i < PSEUDO_SAL_DSPINT_PRIO_MAX; i++)
                {
                    if (sph_int & (1 << i))
                    {
#if !defined(__VAD_SUPPORT__)
                        if (PSEUDO_SAL_DSPINT_PRIO_3G_DL == i)
                        {
    		    			// Do nothing. Don't trigger LISR here. 3G driver will trigger HISR by it's timing
                        }
                        else
#endif
                        {
                            L1Audio_TrigD2CHisr(DP_D2C_INT_MAPPING_BASIC + i);
                        }
                        dsp_ok |= true;
                    }
                }
            }
            
            // After DSP send D2C and turn on bit in DP_D2C_SPEECH_UL_INT, but MCU does not receive D2C.
            // Handover causes VBI reset which will clean DP_D2C_SPEECH_UL_INT
            if (sph_int != 0)
            {
                if (!dsp_ok)
                {
                    extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
                    DisableIRQ();
                    L1D_WIN_DisableAllEvents(0);    // disable all TDMA events
                    ASSERT_REBOOT(0);
                }
            }
            
            return;
        } 
    }
    
    L1Audio_TrigD2CHisr(itype);
    
#else   // chip compile option
#if defined(MT6236) || defined(MT6236B) || defined(MT6256_S00) || defined(MT6256_S01) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H) || defined(MT6255) || defined(MT6250)
   if(itype == D2C_INT6_MAGIC){
      bool dsp_ok = false;
#else
   if(itype == D2C_DSP_DEAD_INT_ID){
      bool dsp_ok = false;
      itype = *DSP_DEAD_INTERRUPT;
      if( itype == D2C_DSP_DEAD_INT_ID ) {
         extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
         DisableIRQ();
         *DP_D2C_TASK1 = 0;            /* freeze DSP */
         L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
#ifndef  L1D_TEST 
         {
            ASSERT_DUMP_PARAM_T dump_param;
         
            /* Write DSP debug info to exception record */
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6251)
            dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);    
            dump_param.len[0]  = 70*2;
            dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);  
            dump_param.len[1]  = 180*2;
            dump_param.addr[2] = 0;    //End of dump param
#else          
            dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x130*2);  
            dump_param.len[0]  = 250*2;
            dump_param.addr[1] = 0;    //End of dump param
#endif         
            EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
         }
#else
         {
            extern void  L1DTest_AssertFail(void);
            L1DTest_AssertFail();
         }
#endif//#ifndef  L1D_TEST 
      }
#endif // #if defind(MT6236)|| defined(MT6256)

#if defined(MT6250)
      itype = *DSP_DACA_UL_INT;
      if(itype == DP_D2C_DACA_REQ_UL){      	
         *DSP_DACA_UL_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;         
      }
      itype = *DSP_DACA_DL_INT;
      if(itype == DP_D2C_DACA_REQ_DL){
         *DSP_DACA_DL_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;         
      }
#endif
      itype = *DSP_PCM_REC_INT;
      if( itype == D2C_UL_DL_PCM_REC_INT_ID || itype == D2C_WAV_REC_REQ_ID )
      {
         *DSP_PCM_REC_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
      itype = *DSP_SOUND_EFFECT_INT;
      if( itype == D2C_SOUND_EFFECT_INT_ID )
      {
         *DSP_SOUND_EFFECT_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
#if defined( __BT_AUDIO_VIA_SCO__ ) && !defined(__CVSD_CODEC_SUPPORT__)
      itype = *DP_AUDIO_VIA_8KBT_INT;
      if( itype == D2C_AUDIO_VIA_8KBT_ID )
      {
         *DP_AUDIO_VIA_8KBT_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
#endif
#if _SPE_FOR_TEST_SIM_
      itype = *DP2_ADAPT_VOL_INT;
      if( itype == DP_D2C_ADAPT_VOL )
      {
         *DP2_ADAPT_VOL_INT = 0;
         L1SP_D2C_LISR(itype);
         dsp_ok |= true;
      }
#endif
      if (!dsp_ok) {
         extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
         DisableIRQ();
#if !defined(MT6256_S01) && !defined(MT6255) && !defined(MT6250) && !defined(MT6260) && !defined(MT6261) && !defined(MT2501) && !defined(MT2502) 
         *DP_D2C_TASK1 = 0;            /* freeze DSP */
#endif         
         L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
         ASSERT_REBOOT(0);
      }
      return;
   }

   if( (itype == DP_D2C_SE_SD_DONE) && (!AM_IsSpeechOn()) ) // when idle 16kPCM, AMR/AWB/VM record, the driver expects the D2C_SE_DONE interrupt triggered by DSP. If System's doing SMS, howerver, DSP triggers the D2C_SE_SD_DONE to MCU. Even if in this case, because the data provided by DSP is also available, the drive just easily modifies the interrupt ID to access data provide by DSP. 
      itype = DP_D2C_SE_DONE;

    {
        int32  I;
        for (I = 0; I < MAX_HISR_HANDLER; I++)
        {
            if (itype == l1audio.hisrMagicNo[I])
            {
                l1audio.hisrMagicFlag |= (1<<I);
                kal_activate_hisr(l1audio.hisr);
                return;
            }
        }
    }
#endif  // chip compile option
   
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   if (itype == DP_D2C_AVSYNC) {
      Media_A2V_LISR();
   } else
#endif
   {
      l1audio.media_flag = itype;
      kal_activate_hisr(l1audio.hisr);
   }
}

void L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == 0 ) {
         l1audio.hisrMagicNo[I] = magic_no;
         l1audio.hisrHandler[I] = handler;
         l1audio.hisrUserData[I] = userData;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );
}

void L1Audio_UnhookHisrHandler( kal_uint16 magic_no )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == magic_no ) {
         l1audio.hisrMagicNo[I] = 0;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );

}

void L1Audio_SetPostHisrHandler( L1Audio_EventHandler handler )
{
   ASSERT( l1audio.postHisrHandler == (L1Audio_EventHandler)0 );
   l1audio.postHisrHandler = handler;
}

void L1Audio_ResetPostHisrHandler( void )
{
   ASSERT( l1audio.postHisrHandler != (L1Audio_EventHandler)0 );
   l1audio.postHisrHandler = (L1Audio_EventHandler)0;
}

void L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO])
{
   memcpy(l1audio.debug_info, debug_info, NUM_DEBUG_INFO*sizeof(uint16));
}

void L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info )
{
   l1audio.debug_info[index] = debug_info;
}

kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index )
{
   ASSERT( index < NUM_DEBUG_INFO );
   return l1audio.debug_info[index];   
}

/* ------------------------------------------------------------------------------ */
/*  Debug functions used to verify the data written to DSP                        */
/* ------------------------------------------------------------------------------ */
#if VERIFY_DATA_TO_DSP
#include   "fat_fs.h"
kal_uint8  bDSPBuffer[8192];
kal_uint16 uDSPBufferRead;
kal_uint16 uDSPBufferWrite;
kal_uint32 uDSPBufferSize;
kal_uint16 fname[12] = { 'E', ':', '\\', 'D', 'A', 'T', 'A', '.', 'D', 'A', 'T', 0x00 };
FS_HANDLE  fs_handle = 0;

void VERIFY_DATA_TO_DSP_START( void )
{
   if( fs_handle )
      FS_Close( fs_handle );
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_CREATE_ALWAYS );
   ASSERT( fs_handle > 0 );
   uDSPBufferSize = 8192;
   uDSPBufferRead = 0;
   uDSPBufferWrite = 0;
}

void VERIFY_DATA_TO_DSP_RESUME( void )
{
   kal_uint32 uFileSize;
   kal_int32  ret;
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_READ_WRITE|FS_CREATE );
   ASSERT( fs_handle > 0 );
   if(FS_GetFileSize(fs_handle, &uFileSize) < 0)
     ASSERT(0);
   if(FS_Seek(fs_handle, uFileSize, FS_FILE_BEGIN) < 0) 
     ASSERT(0);
   uDSPBufferSize = 8192;
}

void VERIFY_DATA_TO_DSP_STOP( void )
{
   if( fs_handle )
   {
   	  if (FS_Close( fs_handle ) != 0)
         ASSERT(0);
      fs_handle = 0;
   }
}

void VERIFY_DATA_TO_DSP_WRITE_DATA( const kal_uint16 *buf, int32 len )
{
   kal_uint32 uDSPBufferFree;
   if( uDSPBufferWrite < uDSPBufferRead )
   {  /// DDDDWxxxxxxxRDD
      uDSPBufferFree = uDSPBufferRead - uDSPBufferWrite - 1;
      ASSERT( len*2 <= uDSPBufferFree );
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, len*2);
      uDSPBufferWrite += len*2;
   }
   else
   {  /// xxxRDDDDDDWxxxx
      kal_uint32 free_1, free_2, write_count;
      free_1 = uDSPBufferSize - uDSPBufferWrite;
      free_2 = uDSPBufferRead - 1;
      uDSPBufferFree = free_1 + free_2;
      ASSERT( len*2 <= uDSPBufferFree );
      write_count = ( len*2 > free_1 )? free_1 : len*2;
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
      if( uDSPBufferWrite==uDSPBufferSize )
         uDSPBufferWrite = 0;
      write_count = len*2 - write_count;
      if( write_count )
         memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
   }
}

void VERIFY_DATA_TO_DSP_SAVE_DATA( void )
{
   if( fs_handle != 0 && uDSPBufferRead != uDSPBufferWrite )
   {
      kal_uint32 uDSPBufferUsed;
      kal_uint32 uDataSaved;
      if( uDSPBufferRead < uDSPBufferWrite )
      {  /// xxxRDDDDDDWxxxx
         uDSPBufferUsed = uDSPBufferWrite - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, uDSPBufferUsed, &uDataSaved );
         ASSERT( uDSPBufferUsed == uDataSaved );
         uDSPBufferRead += uDataSaved;
      }
      else
      {  /// DDDDWxxxxxxxRDD
         kal_uint32 used_1, used_2, write_count;
         used_1 = uDSPBufferSize - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, used_1, &uDataSaved );
         ASSERT( used_1 == uDataSaved );
         used_2 = uDSPBufferWrite;
         FS_Write( fs_handle, bDSPBuffer, used_2, &uDataSaved );
         ASSERT( used_2 == uDataSaved );
         uDSPBufferRead = uDataSaved;
      }
   }
}
#endif

/* ------------------------------------------------------------------------------ */
/*  L1Audio Task                                                                  */
/* ------------------------------------------------------------------------------ */
void L1Audio_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;
   uint16 tempID;

   l1audio.aud_events = kal_create_event_group("L1Audio");
   l1audio.hisr = kal_init_hisr(L1AUDIO_HISR);
   
   GET_SLEEP_HANDLE();
   
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) && !defined(__AUDIO_POWERON_RESET_DSP__) )
   l1audio.md2g_pdn_handle = L1D_MD2G_PWD_GetHandle();
   l1audio.l1sm_handle = L1SM_IntGetHandle();
#endif

   l1audio.runningState        = 0;
   l1audio.disallowSleepState  = 0;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = 0;
   l1audio.media_flag   = 0;
   l1audio.postHisrHandler = (L1Audio_EventHandler)0;
   l1audio.sema = kal_create_sem( "Aud_Sema", 1 );  

   l1audio.hisrMagicFlag = 0;
   for( I = 0; I < MAX_HISR_HANDLER; I++ )
      l1audio.hisrMagicNo[I] = 0;

   tempID = L1Audio_GetAudioID();
   L1Audio_SetFlag(tempID);

   DSP_DynamicDownload_Init();

#ifndef  L1D_TEST
   /// Dynamic download for A/V sync
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
   DSP_DynamicDownload( DDID_WAVETABLE );
#endif
#endif
   AM_Init();

#if APM_SUPPORT
   APM_Init();
#endif

   /// AFE_Init will invoke L1Audio_GetAudioID
   /// and expect to get the id 0 to make sure
   /// it has the highest priority in the event group
   AFE_Init();

#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined( MED_MODEM )   
   AVsync_Init();
#endif   
   
#if defined(__AUDIO_POWERON_RESET_DSP__)
   {
      uint32 _savedMask;
      _savedMask = SaveAndSetIRQMask();
      AFE_Init_status(KAL_TRUE);
      AFE_RegisterBackup();
      RestoreIRQMask(_savedMask);
   }
#endif

   L1SP_Init();

   ktInit( L1Audio_GetAudioID() );
   toneInit( L1Audio_GetAudioID() );
   mediaInit( L1Audio_GetAudioID() );
#if defined(VR_CYBERON)
   vrsdInit();
#elif defined(VRSI_CYBERON)
   vrsiInit();
#endif

   toneLoopbackRecInit();

#if ( defined(__BT_A2DP_PROFILE__) || defined(SBC_UNIT_TEST) ) //&& !(APM_SUPPORT)
   SBC_Init();
#endif

#if defined(__BES_TS_SUPPORT__)
   AudioPP_TS_Init();
#endif

#ifdef __CTM_SUPPORT__
   l1ctm_init();
#endif

#ifdef __TWOMICNR_SUPPORT__
   Two_Mic_NR_chip_Init();	
#endif


#if VMI_SUPPORT || defined(VORTP_UNIT_TEST)
   VMI_Init();
#endif

#if VORTP_SUPPORT || defined(VORTP_UNIT_TEST)
   VoRTP_Init();
#endif

#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS)
   ttsInit();
#endif
#if defined( DSP_WT_SYN ) && !defined(__AUDIO_COMPONENT_SUPPORT__)
   DSPSYN_HW_Init();
#endif

#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   I2S_init();
#endif

#if defined(__ATV_SUPPORT__)
   I2S_Input_GPIO_TurnOff();
#endif

#if defined(__VOICE_CHANGER_SUPPORT__)
   VCHG_Initialize();
#endif

#if defined(__AUDIO_COMPONENT_SUPPORT__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
   // KH : for audio component
   ACU_Init();
#endif
#if defined(__KARAOKE_SUPPORT__)
  {
     extern void Karaoke_Init(void);
     Karaoke_Init();
  }
#endif

#if defined(__VAD_SUPPORT__)
   VAD_Init();
#endif

#if defined(__KARAOKE_SUPPORT__)
   Remix_Init();
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
    {
        extern void BT_SCO_Init(void);
        BT_SCO_Init();
    }
#endif

#if defined(__PCM_CLOCK_SWITCH_SUPPORT__) || defined(__AUDIO_AT_CMD__)
    PCM_CLK_Init();
#endif  // defined(__PCM_CLOCK_SWITCH_SUPPORT__)

   memset( &(l1audio.debug_info), 0, sizeof(l1audio.debug_info) );
   AFE_TurnOnFIR( L1SP_SPEECH );
   AFE_TurnOnFIR( L1SP_VOICE );

   L1Audio_ClearFlag(tempID);
   L1Audio_FreeAudioID(tempID);

   l1audio.isInitiated = KAL_TRUE;

   while( 1 ) {
#if VERIFY_DATA_TO_DSP
      VERIFY_DATA_TO_DSP_SAVE_DATA();
#endif
      kal_retrieve_eg_events(l1audio.aud_events,0xFFFF,KAL_OR_CONSUME,&retrieved_events,KAL_SUSPEND);
      l1audio.retrieved_events = retrieved_events;
      l1audio.events_l1FN = L1I_GetTimeStamp();
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if ( l1audio.retrieved_events & (1<<I) ) {
            l1audio.evHandler[I]( l1audio.evData[I] );
         }
      }
      //if( (l1audio.runningState & l1audio.disallowSleepState) == 0 )
      if( l1audio.runningState == 0 )
         SLEEP_UNLOCK();
   }
}

kal_bool L1Audio_IsInitiated(void)
{
   return l1audio.isInitiated;
}

uint32 L1Audio_GetEventGroup( void )
{
   uint32 retrieved_events;
   kal_retrieve_eg_events( l1audio.aud_events, 0xFFFF, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND );
   return retrieved_events;
}

void L1Audio_ExeEventHandler( uint32 event )
{
   ASSERT_REBOOT( event < MAX_AUDIO_FUNCTIONS );
   l1audio.evHandler[event]( l1audio.evData[event] );
}

void L1Audio_ResetDevice(void)
{
   //AFE_Init();
   if(l1audio.isInitiated) //Before task initialized, don't call AFE_SwitchExtAmplifier in case that it can't be run
      AFE_SwitchExtAmplifier(false);
   AFE_RegisterBackup();
}
/* ------------------------------------------------------------------------------ */

static char *_get_next_arg(char **ppstring)
{
   char *pstring = *ppstring, *pstring_t;
   kal_uint8 ch;

   if( *pstring=='\0' )
      return NULL;

   while(1)
   { // find start
      ch = *pstring;
      if( ch!=' ' && ch!='\t' )
         break;
      pstring++;
   }

   pstring_t = pstring;

   while(1)
   {
      ch = *pstring;
      if( ch=='\0' )
         break;
      else if( ch==' ' || ch=='\t' )
      {
         *pstring = '\0';
         pstring++;
         break;
      }
      pstring++;
   }

   *ppstring = (char *)pstring;

   return pstring_t;
}

static void dispatcher(char **ppstring, int (*entry_main)(int argc, char **argv))
{
   int argc = 0;
   char *argv[16];

   while(1)
   {
      char *args = _get_next_arg( ppstring );

      if( args==NULL )
      {
         entry_main( argc, argv );
         break;
      }
      else if( strcmp( args, "|" )==0 )
      {
         argv[argc] = NULL;
         entry_main( argc, argv );
         argc = 0;
      }
      else
         argv[argc++] = args;
   }
}

#if defined(VORTP_UNIT_TEST)
extern int VoRTP_main(int argc, char **argv);
#endif

void l1audio_console(kal_uint8 index, kal_char *string)
{
   int (*entry_main)(int argc, char **argv);
   char *pstring = (char *)string;

   entry_main = NULL;
   switch(index)
   {
      case 99: /* VoRTP unit test */
      {
#if defined(VORTP_UNIT_TEST)
         entry_main = VoRTP_main;
#endif
         break;
      }
      default:
         break;
   }
   if( entry_main!=NULL )
      dispatcher(&pstring, entry_main);
}


void l1audio_console_handler(kal_char *string)
{
#if defined(__ENABLE_AUDIO_DVT__)
    l1audio_consoleDVT(string);
#else
    (void)string;
#endif
}

/* ----------------------------------------------------------------------------- */
/*  Function ptr prototype [HAL rule]                                            */ 
/* ----------------------------------------------------------------------------- */
//[MED]
static fp_audio_alloc_aud_mem      audio_alloc_aud_mem = NULL;
static fp_audio_alloc_aud_mem      audio_alloc_aud_mem_cacheable= NULL;
static fp_audio_free_aud_mem       audio_free_aud_mem = NULL;
static fp_send_proc_call_req       send_proc_call_req = NULL;
static fp_send_proc_call_req       send_proc_call_req2 = NULL;
static fp_audio_set_path_volume    audio_set_path_vol = NULL;
static fp_audio_get_active_mode    audio_get_active_mode = NULL;
static fp_get_meta_data_file       audio_get_meta_file = NULL;
static fp_get_meta_data_array      audio_get_meta_array = NULL;

#if defined(__CLASSK_CP_SUPPORT__)
static fp_get_vbat_value           audio_get_vbat_value = NULL;
static fp_send_classk_state        audio_send_vbat_detect_freq = NULL;
#endif	
#ifdef __VIBRATION_SPEAKER_SUPPORT__
static  fp_send_vib_spk_is_calib    audio_send_vib_spk_is_calib=NULL;
#endif

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void Audio_MedFuncReg(Media_Func_Reg_Type *func){
	    audio_alloc_aud_mem           = (fp_audio_alloc_aud_mem)  func->alloc_mem;
	 	  audio_alloc_aud_mem_cacheable = (fp_audio_alloc_aud_mem)  func->alloc_mem_cacheable;
	 	  audio_free_aud_mem            = (fp_audio_free_aud_mem)   func->free_mem;	 
	 	  audio_set_path_vol            = (fp_audio_set_path_volume)func->set_path_volume;
	 	  audio_get_active_mode         = (fp_audio_get_active_mode)func->get_active_mode;
	 	  send_proc_call_req            = (fp_send_proc_call_req)   func->send_proc_call;
	 	  send_proc_call_req2           = (fp_send_proc_call_req)   func->send_proc_call2;
	 	  audio_get_meta_file           = (fp_get_meta_data_file)   func->get_meta_file;
	 	  audio_get_meta_array          = (fp_get_meta_data_array)  func->get_meta_array;
   #if defined(__CLASSK_CP_SUPPORT__)
      audio_get_vbat_value          = (fp_get_vbat_value)       func->get_vbat_value;
      audio_send_vbat_detect_freq   = (fp_send_classk_state)    func->send_classk_state;
   #endif	 	  
   #ifdef __VIBRATION_SPEAKER_SUPPORT__
   	  audio_send_vib_spk_is_calib   = (fp_send_vib_spk_is_calib) func->send_vib_spk_is_calib;
   #endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#ifdef __VIBRATION_SPEAKER_SUPPORT__
void audio_vib_spk_is_calib()
{
	audio_send_vib_spk_is_calib();

}
#endif
void *audio_alloc_ext_mem(kal_int32 size, char* file_p, long line_p){
	 void *ptr = NULL; 	 	 
	 if (size == 0){
        return NULL;
     }    
	 ptr = (void*) audio_alloc_aud_mem(size,file_p,line_p);
	 if(ptr){
        memset(ptr, 0, size);
	 }
	 kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d, ptr=%x, %d", file_p, line_p, ptr, size);
	 return ptr;
}

void *audio_alloc_ext_mem_cacheable(kal_int32 size, char* file_p, long line_p){
	 void *ptr = NULL; 	 	 
	 if (size == 0){
        return NULL;
   } 
	 ptr = (void*) audio_alloc_aud_mem_cacheable(size,file_p,line_p);
	 if(ptr){
        memset(ptr, 0, size);
	 }
	 kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d, ptr=%x, %d", file_p, line_p, ptr, size);
	 return ptr;
}

void audio_free_ext_mem(void **ptr, char* file_p, long line_p)
{
   kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] free buffer from: %s, %d, ptr=%x", file_p, line_p, *ptr);
	 audio_free_aud_mem(ptr,file_p,line_p);
}

void *audio_alloc_ext_mem_simplified(kal_uint32 size)
{
   return audio_alloc_mem(size);
}

void *audio_alloc_ext_mem_cacheable_simplified(kal_uint32 size)
{
    return audio_alloc_mem_cacheable(size);
}

void audio_free_ext_mem_simplified(void *ptr)
{
   audio_free_mem( &ptr );
}

void L1Audio_InProcCall2(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_NOT_PRESENT
   send_proc_call_req2(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

void L1Audio_InProcCall(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
#ifndef MED_NOT_PRESENT
   send_proc_call_req(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

void aud_set_volume_internal(kal_uint8 audio_mode){
	 audio_set_path_vol(audio_mode);
}

kal_uint8 aud_get_mode_internal(void){
	return audio_get_active_mode();
}

#if defined(__CLASSK_CP_SUPPORT__)
void audio_send_vbat_detect_rate(kal_bool classk_state)
{
	 audio_send_vbat_detect_freq(classk_state);
}

kal_uint32 audio_query_vbat_value(void)
{
	 return audio_get_vbat_value();
}
#endif

/*
kal_bool aud_get_meta_file(kal_wchar *filename, aud_info_struct *aud_info_p){
	return audio_get_meta_file(filename, aud_info_p);
}

kal_bool aud_get_meta_array(kal_char *ptr, kal_uint32 size, aud_info_struct *aud_info_p){
	return audio_get_meta_array(ptr, size, aud_info_p);
}
*/
//[BT]
static fp_a2dp_set_br_from_qos_init   set_br_from_qos_init = NULL;
static fp_a2dp_set_br_from_qos        set_br_from_qos = NULL;

void Audio_BTFuncReg(BT_Func_Reg_Type *func){
	    set_br_from_qos_init           = (fp_a2dp_set_br_from_qos_init)func->a2dp_set_br_init;
	 	  set_br_from_qos                = (fp_a2dp_set_br_from_qos)     func->a2dp_set_br;
}

void a2dp_set_br_init_internal(kal_uint32 bit_rate_cur){
	 set_br_from_qos_init(bit_rate_cur);
}

kal_uint32 a2dp_set_br_internal(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32)){
	 return set_br_from_qos(qos, bit_rate_prev, (*SetCodecBitRate));
}

#if defined(DSP_DEBUG_LOG_AND_DUMP)

#pragma arm section code="SECONDARY_ROCODE"
#define SHERIF_DUMP_LENGTH 200
kal_uint32 uSherifWriteCount = 0;
kal_uint32 uSherifWriteIndex = 0;
kal_uint32 SHERIF_DUMP_ADDR[SHERIF_DUMP_LENGTH];
kal_uint16 SHERIF_DUMP_VALUE[SHERIF_DUMP_LENGTH];
kal_uint32 SHERIF_DUMP_COUNT[SHERIF_DUMP_LENGTH];

void sherif_write_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p)
{
   uint32 savedMask;
   if(!kal_if_lisr())
   {
      kal_wap_trace(MOD_L1SP, TRACE_INFO, "[SHERIF][%d]Write [*%x]=%x, at: %s, line: %d",uSherifWriteCount, pAddr, uValue, file_p, line_p);
   }
   *pAddr = uValue;
   savedMask = SaveAndSetIRQMask();
   SHERIF_DUMP_ADDR[uSherifWriteIndex] = (kal_uint32)pAddr;
   SHERIF_DUMP_VALUE[uSherifWriteIndex] = *pAddr;
   SHERIF_DUMP_COUNT[uSherifWriteIndex++] = uSherifWriteCount++;
   if(uSherifWriteIndex>=SHERIF_DUMP_LENGTH)
   {
      uSherifWriteIndex = 0;
   }
   RestoreIRQMask(savedMask);
}

void sherif_and_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p)
{
   uint32 savedMask;
   if(!kal_if_lisr())
   {
      kal_wap_trace(MOD_L1SP, TRACE_INFO, "[SHERIF][%d]And=  [*%x]=%x, at: %s, line: %d",uSherifWriteCount, pAddr, uValue, file_p, line_p);
   }
   *pAddr &= uValue;
   savedMask = SaveAndSetIRQMask();
   SHERIF_DUMP_ADDR[uSherifWriteIndex] = (kal_uint32)pAddr;
   SHERIF_DUMP_VALUE[uSherifWriteIndex] = *pAddr;
   SHERIF_DUMP_COUNT[uSherifWriteIndex++] = uSherifWriteCount++;
   if(uSherifWriteIndex>=SHERIF_DUMP_LENGTH)
   {
      uSherifWriteIndex = 0;
   }
   RestoreIRQMask(savedMask);
}

void sherif_or_dump(kal_uint16* pAddr, kal_uint16 uValue, char* file_p, long line_p)
{
   uint32 savedMask;
   if(!kal_if_lisr())
   {
      kal_wap_trace(MOD_L1SP, TRACE_INFO, "[SHERIF][%d]or=   [*%x]=%x, at: %s, line: %d",uSherifWriteCount, pAddr, uValue, file_p, line_p);
   }
   *pAddr |= uValue;
   savedMask = SaveAndSetIRQMask();
   SHERIF_DUMP_ADDR[uSherifWriteIndex] = (kal_uint32)pAddr;
   SHERIF_DUMP_VALUE[uSherifWriteIndex] = *pAddr;
   SHERIF_DUMP_COUNT[uSherifWriteIndex++] = uSherifWriteCount++;
   if(uSherifWriteIndex>=SHERIF_DUMP_LENGTH)
   {
      uSherifWriteIndex = 0;
   }
   RestoreIRQMask(savedMask);
}

void sherif_assert_dump()
{
   kal_int32 i;
   for(i=0;i<SHERIF_DUMP_LENGTH;i++)
   {
      kal_wap_trace(MOD_L1SP, TRACE_INFO, "[SHERIF][ASSERT][%d]Write [*%x]=%x",SHERIF_DUMP_COUNT[i],SHERIF_DUMP_ADDR[i],SHERIF_DUMP_VALUE[i]);
   }
}

#pragma arm section 
#endif


