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
 * tone_debug.c
 *
 * Project:
 * --------
 * MTK Feature Phone
 *
 * Description:
 * ------------
 * For keytone debug use
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "dcl.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "common_def.h"
#include "l1audio.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "speech_def.h"
#include "audio_def.h"
#include "afe_def.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#include "bt_sco_app.h"
#endif

#ifdef __I2S_UNIT_TEST__
extern kal_uint16 Media_I2S_INPUT_MODE_SR_UT;
#endif

#ifdef BT_Loopback_Test
static kal_bool BT_PROCESS_END;
extern uint32 BT_Loopback_Start(void(*callback)( void ) , kal_char *play_filename , kal_char *record_filename);
extern void BtRadio_SetupPCMGpioPins(void);
void BT_Loopback_Callback(void)
{
   BT_PROCESS_END = true;
}
#define SPH_MODE_BT_CORDLESS 4
uint16 m_para[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif //#ifdef BT_Loopback_Test

#if defined(__KARAOKE_DVT_TEST__)
STFSAL            fWriter; 
static kal_uint16 file_count = 0;
#define RING_BUFFER_LEN 8*1024
kal_uint16 Ring_buf[RING_BUFFER_LEN];
kal_uint32 Total_Len = 0;
void record_callback(Media_Event event)
{
    kal_uint16* pwBuf;
    kal_uint32 uBufLenInTwoByteWord;
  
    switch (event){
        case MEDIA_TERMINATED:
            kal_prompt_trace(MOD_L1SP, "record_callback->MEDIA_TERMINATED");                          
            break;
        case MEDIA_DATA_NOTIFICATION:
        {
            Media_GetReadBuffer(&pwBuf, &uBufLenInTwoByteWord);
            Media_ReadDataDone(uBufLenInTwoByteWord);

            ASSERT( FSAL_OK == FSAL_Write( &fWriter, (kal_uint8 *) pwBuf, sizeof(int16)* uBufLenInTwoByteWord));  
            
            kal_prompt_trace(MOD_L1SP, "uBufLenInTwoByteWord = %d", uBufLenInTwoByteWord);
            break;
        }
    }
}
#endif

#if defined(KEYTONE_DEBUG)

static uint8 KeyFlags = 0;
static uint8 KeyCommand = 0;
static uint8 KeyFlags1 = 0;
static uint8 KeyCommand1 = 0;
static uint8 KeyFlags2 = 0;
static uint8 KeyCommand2 = 0;
static uint8 KeyFlags3 = 0;
static uint8 KeyCommand3 = 0;

void Key1Event( void )
{
#if defined(__KARAOKE_DVT_TEST__)	
   kal_wchar filename[40];
   kal_wsprintf( filename, "%c:\\test8k_%d.pcm", FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE ), file_count);
   if( FSAL_OK != FSAL_Open( &fWriter, filename, FSAL_WRITE ) ){
      kal_prompt_trace(MOD_L1SP, "Autorec: source file can't open\n");
      return ;
   }
      
   //Ring_buf  = (int16 *)med_alloc_aud_mem( RING_BUFFER_LEN * sizeof(int16) );

   Media_SetBuffer((kal_uint16*)Ring_buf, RING_BUFFER_LEN);
   Media_SetRBThreshold(200); 
   Media_Record(MEDIA_FORMAT_WAV, record_callback,NULL); 
#endif	
   
#ifdef BT_Loopback_Test
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
   L1SP_Speech_On(0);
#endif
#ifdef __I2S_UNIT_TEST__
   Media_I2S_INPUT_MODE_SR_UT = 32000;
   I2S_Open();
#endif
#ifdef __CVSD_LOOPBACK_TEST__
   CVSD_Loopback_Start("Tx.cvsd","Rx.cvsd");
#endif
   return;   
}

void Key2Event( void )
{
#if defined(__KARAOKE_DVT_TEST__)		
	Media_Stop();//stop record audio
  ASSERT( FSAL_OK == FSAL_Close( &fWriter ) );
  file_count++;
#endif   
	
#ifdef BT_Loopback_Test
   uint16 m_para_BT_Earphone[16] = {64,   223,     0,     30,    7,  20510,   400,     0,
                                    0,     0,     0,       0,    0,       0,    0,     0};
   
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone);
   L1SP_Speech_On(0);
#endif
#ifdef __I2S_UNIT_TEST__
   Media_I2S_INPUT_MODE_SR_UT = 44100;
   I2S_Open();
#endif
#ifdef __CVSD_LOOPBACK_TEST__
   CVSD_Loopback_Stop();
#endif
   return;   
}

void Key3Event( void )
{
#if defined(__KARAOKE_DVT_TEST__)		
      Media_SetKaraoke(KAL_TRUE);
#endif 
#ifdef BT_Loopback_Test
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
#endif
#ifdef __I2S_UNIT_TEST__
   Media_I2S_INPUT_MODE_SR_UT = 48000;
   I2S_Open();
#endif
#ifdef __CVSD_LOOPBACK_TEST__
   BT_SCO_LoopbackPath_ON();
#endif
   return;   
}

void Key4Event( void )
{
#if defined(__KARAOKE_DVT_TEST__)	
   	  Media_SetKaraoke(KAL_FALSE);   
#endif 
#ifdef BT_Loopback_Test
      uint16 m_para_BT_Earphone[16] = {64,   223,     0,     30,    7,  20510,   400,     0,
                                       0,     0,     0,       0,    0,       0,    0,     0};
      
      L1SP_Speech_Off();
      L1SP_SetOutputDevice(L1SP_SPEAKER1);
      L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone); 
      BtRadio_SetupPCMGpioPins();  
#endif         
#ifdef __I2S_UNIT_TEST__
   I2S_Close();
#endif         
#ifdef __CVSD_LOOPBACK_TEST__
   BT_SCO_Disable_All_APP();
#endif
   return;   
}

void Key5Event( void )
{    
#if defined(__KARAOKE_DVT_TEST__)	
   kal_wchar filename[40];
   kal_wsprintf( filename, "%c:\\test16k_%d.pcm", FS_GetDrive( FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE ), file_count);
   if( FSAL_OK != FSAL_Open( &fWriter, filename, FSAL_WRITE ) ){
      kal_prompt_trace(MOD_L1SP, "Autorec: source file can't open\n");
      return ;
   }
      
   //Ring_buf  = (int16 *)med_alloc_aud_mem( RING_BUFFER_LEN * sizeof(int16) );

   Media_SetBuffer((kal_uint16*)Ring_buf, RING_BUFFER_LEN);
   Media_SetRBThreshold(200); 
   Media_Record(MEDIA_FORMAT_PCM_16K, record_callback,NULL); 
#endif	
   return;   
}

void Key6Event( void )
{  
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"1.wav","BTout1.pcm");    
#endif
   return;   
}

void Key7Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"2.wav","BTout2.pcm");    
#endif
   return;   
}

void Key8Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"3.wav","BTout3.pcm");     
#endif
   return;   
}

void Key9Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"4.wav","BTout4.pcm");  
#endif
   return;   
}

//===================================================================

void Key11Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"5.wav","BTout5.pcm"); 
#endif
   return;   
}

void Key12Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"6.wav","BTout6.pcm"); 
#endif
   return;   
}

void Key13Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"7.wav","BTout7.pcm"); 
#endif
   return;   
}

void Key14Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"8.wav","BTout8.pcm"); 
#endif
   return;   
}

void Key15Event( void )
{    
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"9.wav","BTout9.pcm"); 
#endif
   return;   
}

void Key16Event( void )
{  
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"10.wav","BTout10.pcm");    
#endif
   return;   
}

void Key17Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"11.wav","BTout11.pcm");  
#endif
   return;   
}

void Key18Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"12.wav","BTout12.pcm");     
#endif
   return;   
}

void Key19Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"13.wav","BTout13.pcm");   
#endif
   return;   
}

//===================================================================
void Key21Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"14.wav","BTout14.pcm");  
#endif
   return;   
}

void Key22Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"15.wav","BTout15.pcm");  
#endif
   return;   
}

void Key23Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"16.wav","BTout16.pcm");  
#endif
   return;   
}

void Key24Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"17.wav","BTout17.pcm");  
#endif
   return;   
}

void Key25Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"18.wav","BTout18.pcm");  
#endif
   return;   
}

void Key26Event( void )
{  
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"19.wav","BTout19.pcm");     
#endif
   return;   
}

void Key27Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"20.wav","BTout20.pcm");   
#endif
   return;   
}

void Key28Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"21.wav","BTout21.pcm");      
#endif
   return;   
}

void Key29Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"22.wav","BTout22.pcm");    
#endif
   return;   
}
//===================================================================
void Key31Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"23.wav","BTout23.pcm");  
#endif
   return;   
}

void Key32Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"24.wav","BTout24.pcm");  
#endif
   return;   
}

void Key33Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"25.wav","BTout25.pcm");  
#endif
   return;   
}

void Key34Event( void )
{   
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"26.wav","BTout26.pcm");  
#endif
   return;   
}

void Key35Event( void )
{ 
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"27.wav","BTout27.pcm");  
#endif
   return;   
}

void Key36Event( void )
{  
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"28.wav","BTout28.pcm");     
#endif
   return;   
}

void Key37Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"29.wav","BTout29.pcm");   
#endif
   return;   
}

void Key38Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"30.wav","BTout30.pcm");      
#endif
   return;   
}

void Key39Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"31.wav","BTout31.pcm");   
#endif
   return;   
}
//===================================================================

void Keytone_Debug_Entry( uint16 freq1, uint16 freq2)
{
   uint8 pressed_key;   
   
   pressed_key = 0;
   
   switch(freq1) {
      case 697:
         pressed_key = 1;
         break;
      case 770:
         pressed_key = 4;
         break;
      case 852:
         pressed_key = 7;
         break;
      case 941:
         pressed_key = 10;  //*
         break;
   }
   switch(freq2) {
      case 1209:
         pressed_key += 0;
         break;
      case 1336:
         pressed_key += 1;
         break;
      case 1477:
         pressed_key += 2;
         break;
   }

//===================================================================
	
   if(pressed_key == 10)  // * 
      KeyFlags = 0x1;
   else if(pressed_key == 12)  // #   
   {
      if(KeyFlags == 0x3)
      {
         switch(KeyCommand)
         {
            case 1:  
               Key1Event();
               break;
            case 2:
               Key2Event();               
               break;
            case 3:               
               Key3Event();   
               break;
            case 4:             
               Key4Event();                             
               break;
            case 5:  
               Key5Event();                      
               break;            
            case 6: 
               Key6Event();             
               break;   
            case 7: 
               Key7Event();                     
               break;            
            case 8:
               Key8Event();                            
               break; 
            case 9:                            
               Key9Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags = 0;                           
   }
   else 
   {
      if(KeyFlags == 0x1)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand = pressed_key;      
               KeyFlags = 0x3;
               break;
            default:
               KeyCommand = 0;
               KeyFlags = 0;
         }
      }
      else 
         KeyFlags = 0;
   }
   
//===================================================================
   
   if(pressed_key == 12)  // # 
      KeyFlags1 = 0x11;
   else if(pressed_key == 10)  // *   
   {
      if(KeyFlags1 == 0x31)
      {
         switch(KeyCommand1)
         {
            case 1:  
               Key11Event();
               break;
            case 2:
               Key12Event();               
               break;
            case 3:               
               Key13Event();   
               break;
            case 4:             
               Key14Event();                             
               break;
            case 5:  
               Key15Event();                      
               break;            
            case 6: 
               Key16Event();             
               break;   
            case 7: 
               Key17Event();                     
               break;            
            case 8:
               Key18Event();                            
               break; 
            case 9:                            
               Key19Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags1 = 0;                           
   }
   else 
   {
      if(KeyFlags1 == 0x11)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand1 = pressed_key;      
               KeyFlags1 = 0x31;
               break;
            default:
               KeyCommand1 = 0;
               KeyFlags1 = 0;
         }
      }
      else 
         KeyFlags1 = 0;
   }   

//===================================================================
   if(pressed_key == 10)  // * 
      KeyFlags2 = 0x21;
   else if(pressed_key == 11)  // 0
   {
      if(KeyFlags2 == 0x32)
      {
         switch(KeyCommand2)
         {
            case 1:  
               Key21Event();
               break;
            case 2:
               Key22Event();               
               break;
            case 3:               
               Key23Event();   
               break;
            case 4:             
               Key24Event();                             
               break;
            case 5:  
               Key25Event();                      
               break;            
            case 6: 
               Key26Event();             
               break;   
            case 7: 
               Key27Event();                     
               break;            
            case 8:
               Key28Event();                            
               break; 
            case 9:                            
               Key29Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags2 = 0;                           
   }
   else 
   {
      if(KeyFlags2 == 0x21)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand2 = pressed_key;      
               KeyFlags2 = 0x32;
               break;
            default:
               KeyCommand2 = 0;
               KeyFlags = 0;
         }
      }
      else 
         KeyFlags2 = 0;
   }     

//===================================================================
   if(pressed_key == 12)  // #
      KeyFlags3 = 0x31;
   else if(pressed_key == 11)  // 0
   {
      if(KeyFlags3 == 0x33)
      {
         switch(KeyCommand3)
         {
            case 1:  
               Key31Event();
               break;
            case 2:
               Key32Event();               
               break;
            case 3:               
               Key33Event();   
               break;
            case 4:             
               Key34Event();                             
               break;
            case 5:  
               Key35Event();                      
               break;            
            case 6: 
               Key36Event();             
               break;   
            case 7: 
               Key37Event();                     
               break;            
            case 8:
               Key38Event();                            
               break; 
            case 9:                            
               Key39Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags3 = 0;                           
   }
   else 
   {
      if(KeyFlags3 == 0x31)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand3 = pressed_key;      
               KeyFlags3 = 0x33;
               break;
            default:
               KeyCommand3 = 0;
               KeyFlags3 = 0;
         }
      }
      else 
         KeyFlags3 = 0;
   }        
}

#else

void Keytone_Debug_Entry( uint16 freq1, uint16 freq2)
{

}

#endif

