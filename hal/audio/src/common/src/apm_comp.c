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
 *   APM.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Post-Processing Manager to handle PCM bit-stream
 *
 * Author:
 * -------
 * -------
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
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "audio_def.h"
#include "speech_def.h"

#if APM_SUPPORT

#include <string.h>

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "med_smalloc.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "BesSound_exp.h"
#include "BesCF_exp.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "media.h"
#include "am.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "OMX_Core.h"                        
#include "OMX_Types.h"                      
#include "OMX_Index.h" 
#include "AudComUtil.h"
#include "AudCom.h"
#include "MedAdapt.h"
#include "apm_task.h"

#if defined(MT6255)
// To check ECO version
#include "init.h"
#endif

#if defined(__DEMAND_PAGING__)
#include "dpmgr.h"
#endif

#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
#include "BesSurround_exp.h"
#include "BesHeadPhone_exp.h"
#endif

#if defined(__BES_LOUDNESS_SUPPORT__) || defined(__BES_LOUDNESS_ON_I2S__)
#include "BesLoudness_exp.h"
#endif

#if defined(__BES_LIVE_SUPPORT__)
#include "BesLive_exp.h"
#endif

#if defined(__BES_EQ_SUPPORT__)
#include "BesEQ_exp.h"
#include "nvram_default_audio.h"
#endif

#if defined(__BES_BASS_SUPPORT__)
#include "BesBass_exp.h"
#endif

#define __APM_USE_STATIC_MEMORY__

//---- Static structure ----
// MaxInputBufSize must be larger than MaxTempBufSize
// For 3D Surround, it needs more buffer because the block of 3D Surround is 4096 words
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__) || defined(__BES_LIVE_SUPPORT__)
#define MaxSampleBufSize   4608 //12300
#elif !( defined(WMA_DECODE) || defined(AAC_PLUS_DECODE) || defined(AAC_PLUS_PS_DECODE) || defined(BSAC_DECODE) )
#define MaxSampleBufSize   4608 //6300
#else
#define MaxSampleBufSize   4608 //8200
#endif

#define MaxTempBufSize     2048
#define MaxTaskNum         32

// To smooth the start/stop, and prebuffer some samples
#define APM_BUFFERING_ENABLE   1
#define APM_BUFFERING_NUMBER   2048
#define APM_BUFFERING_For_TS   8192

#define APM_SMOOTH_STATE_NONE       0
#define APM_SMOOTH_STATE_ORI2PROC   1
#define APM_SMOOTH_STATE_PROC2ORI   2
#define APM_SMOOTH_STATE_PROC2PROC  3

// To handle the tone rampup or rampdown
#define APM_STATE_INIT     0
#define APM_STATE_OFF      1
#define APM_STATE_OFF2ON   2  
#define APM_STATE_ON       3
#define APM_STATE_ON2OFF   4

// To handle EOF, clear DSP buffer
#define APM_EOF_IDLE       0
#define APM_EOF_WAITING    1
#define APM_EOF_ENDING     2
#define APM_EOF_TAILING    3
#define APM_EOF_FINISH     4
#define APM_EOF_DONE       5
#define APM_EOF_DONE_END   6

#define APM_EOF_WAIT_FRAME 0

// To handle overloading
#define APM_OVERLOAD_TIMES    3
// The drop time in ms
#define APM_DROP_TIME      2000

#define APM_HDL_STATE_NONE  0
#define APM_HDL_STATE_READY 1
#define APM_HDL_STATE_PLAY  2

#define APM_MAX_DIGITAL_GAIN    0x7FFF

typedef struct APM_TaskNodeStruct {
   uint32     read;
   uint32     write;
   APM_TCM    tcm; 
   const APM_TASK_PARA *para;
   BS_Handle  *bsh;
   uint32     bsInitParSize;
   void       *bsInitPar;
   uint8      *tempBuf;
   uint32     bsRunTimeParSize;
   void       *bsRunTimePar;
} APM_NODE;

typedef struct {
   // Fields about APM control
   kal_bool   isTCMLoad;          // whether APM use TCM
   kal_bool   isRemainTCMOccupy;  // whether the remained TCM is occupied
   kal_bool   isRunning;          // whether APM is activated
   int32      aud_id;
   uint32     resumeTask;
   uint32     regTask;            // Bitwise, the registered task
   uint32     procTask;           // Bitwise, the task needed to process
   uint32     newTask;            // Bitwise, the new registered task
   uint32     delTask;            // Bitwise, the deleted task
   uint32     notifyRampdownTask; // Bitwise, the notify ramp down task
   uint32     exeRampdownTask;    // Bitwise, the ramping down task
   uint32     tcmTask;            // Bitwise, the task needed TCM
   uint32     rwTask;             // Bitwise, the task which is not Read Only
   uint32     regLevel;           // Bitwise, the level had been registered
   APM_Info   info;               // Information of sample (frequebcy, type, and frame size)
   
   // To control the remained TCM buffer
   APM_TCM    remainTCM;
   
   // Debug information
   kal_uint16 frameSize;          // The frame size returned from DSP
   kal_uint16 asp_type;           // The Audio Signal Process Type
   
   // Field to handle tone, reset, AV sync, sommth transition, and end of playback
   kal_bool   preBuffer;
   kal_bool   isReset;            // Whether the playback information is changed
   kal_bool   dropFlagInternal;
   kal_uint8  BesSound_disable;
   kal_uint8  dropCount;
   kal_uint16 dropFrame;
   kal_uint16 dropBoundary;
   kal_bool   rampUp;
   kal_uint8  toneType;
   kal_uint8  eofState;
   kal_uint8  eofWaitFrame;       // The number of frame had been waited
   kal_int8   eofLevel;
   kal_uint8  smoothState;
   int16      rampGain;           // Ramp up gain
   int16      numRemain;          // The number of remained samples at EOF
   uint32     delaySample;        // For AV sync
   void       *hdl;               // Handle of Audio driver
   void       (*EofHandle)(void *data, Media_Event event);   // Hooked EOF Handle for audio
   Media_Event event;

   // The read/write buffer pointer of each post-process
   kal_uint8  taskNum;
   kal_uint8  map[MaxTaskNum];    // The map from ID to level
   APM_NODE   task[MaxTaskNum];
   APM_NODE   *tail;
   
   // Fields about buffer control
   int32      read;
   int32      write;
   int32      rb_size;
   APM_Buffer bufInfo;
   int16      SampleBuf[MaxSampleBufSize];
   int16      tempInBuf[MaxTempBufSize];
   int16      tempOutBuf[MaxTempBufSize];
   
   // For Dual MAC DSP and component
   AudComHdl  *pSinkHandle;
   //keep apm handle in the structure
   AudComHdl  *phdl;
   
   kal_uint32 uPreload;
   kal_uint8  BesSound_disable_in_Video;
} apmstruct;

static apmstruct APM;

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );


// ***** Static functions for Audio Post-Processing Manager In Task Level *****



//-------- Buffer Operation --------

__inline int GetReadDataCount(int startPos, int endPos, int size)
{
   int count;

   count = endPos - startPos;
   if (count < 0) {
      count += size;
   }
   return count;
}

static void CopyDataWithGain(int16 *pDest, int16 *pSrc, int length, int16 gain )
{
   if (gain == 0x7FFF) {
      memcpy(pDest, pSrc, length*sizeof(int16));
   } else {
      int i;
      
      for (i=length-1; i>=0; i--) {
         int result;
         
         result = ((*pSrc++) * gain)>>15;
         *pDest++ = (int16) result;
      }
   }
}

// Get the successive data and place into APM.tempInBuf
static int GetReadDataToTempBuf(int startPos, int endPos, int bufSize, kal_int16 gain)
{
   int count, segment;
   int16 *pTemp;

   count = endPos - startPos;
   if (count < 0)
      count += bufSize;

   if (count > MaxTempBufSize)
      count = MaxTempBufSize;

   // Process the first segment
   pTemp = APM.tempInBuf;
   segment = bufSize - startPos;
   if (segment > count)
      segment = count;
   CopyDataWithGain(pTemp, APM.SampleBuf + startPos, segment, gain);
   pTemp += segment;

   // Process the second segment
   segment = count - segment;
   if (segment) {
      CopyDataWithGain(pTemp, APM.SampleBuf, segment, gain);
   }

   return count;
}

// Save the tempBuf into Input Buffer
// The data is the input data for the next task
static int PutWriteDataFromTempBuf( int startPos, int endPos, int bufSize, int dataLen)
{
   int count, segment;
   short *pTemp;

   count = endPos - startPos;
   if (count < 0)
      count += bufSize;

   if (count > dataLen) {
      count = dataLen;
      kal_trace(TRACE_GROUP_APM, APM_TRUNCATE);
   }

   // Process the first segment
   pTemp = APM.tempOutBuf;
   segment = bufSize - startPos;
   if (segment > count)
      segment = count;
   memcpy(APM.SampleBuf + startPos, pTemp, segment*sizeof(int16));
   pTemp += segment;

   // Process the second segment
   segment = count - segment;
   if (segment) {
      memcpy(APM.SampleBuf, pTemp, segment*sizeof(int16));
   }

   return count;
}

//-------- Load / unload code ----
#if defined(__DEMAND_PAGING__)
static DPMGR_Region apm_MapFromIdToRegion(APM_TaskID apm_Id)
{
   DPMGR_Region reg;
   
   switch(apm_Id) {
      case APM_TASKID_REVERB:
         reg = DPMGR_BES_LIVE;
         break;
      case APM_TASKID_SURROUND_LSPK:
         reg = DPMGR_BES_SURROUND;
         break;
      case APM_TASKID_SURROUND_EARP:
         reg = DPMGR_BES_HEADPHONE;
         break;
      case APM_TASKID_LOUDNESS:
         reg = DPMGR_BES_LOUDNESS;
         break;
      case APM_TASKID_EQ:
         reg = DPMGR_BES_EQ;
         break;
      case APM_TASKID_BASS:
         reg = DPMGR_BES_BASS;
         break;
      case APM_TASKID_CF:
         reg = DPMGR_BES_CF;
         break;
      case APM_TASKID_TS:
         reg = DPMGR_BES_TS;
         break;
      default:
         reg = DPMGR_NOT_MATCH;
   }
   
   return reg;
}

static void apm_LoadCode( APM_TaskID apm_Id )
{
   DPMGR_Region reg;
   
   reg = apm_MapFromIdToRegion(apm_Id);
   if (reg != DPMGR_NOT_MATCH) {
      DPMGR_Load(reg);
   }
}

static void apm_UnloadCode( APM_TaskID apm_Id )
{
   DPMGR_Region reg;
   
   reg = apm_MapFromIdToRegion(apm_Id);
   if (reg != DPMGR_NOT_MATCH) {
      DPMGR_Unload(reg);
   }
}

#elif defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__) || defined(__DCM_WITH_COMPRESSION_AUDIO_BT__)

#include "dcmgr.h"

static kal_int32 apm_MapFromIdToDCM(APM_TaskID apm_Id)
{
   kal_int32 reg;
   
   switch(apm_Id) {
#if defined(__DCM_WITH_COMPRESSION_AUDIO_EFFECT__)
      case APM_TASKID_LOUDNESS:
         reg = DYNAMIC_CODE_COMPRESS_BESLOUDNESS;
         break;
#endif

      default:
         reg = DYNAMIC_CODE_COMPRESS_NONE;
   }
   
   return reg;
}

static void apm_LoadCode( APM_TaskID apm_Id )
{
   kal_int32 reg;
   
   reg = apm_MapFromIdToDCM(apm_Id);
   if (reg != DYNAMIC_CODE_COMPRESS_NONE) {
      DCM_Load(reg, 0, 0);
   }
}

static void apm_UnloadCode( APM_TaskID apm_Id )
{
   kal_int32 reg;
   
   reg = apm_MapFromIdToDCM(apm_Id);
   if (reg != DYNAMIC_CODE_COMPRESS_NONE) {
      DCM_Unload(reg);
   }
}

#else

static void apm_LoadCode( APM_TaskID apm_Id )
{

}

static void apm_UnloadCode( APM_TaskID apm_Id )
{

}
#endif

//-------- Flow Control --------
#if defined(__BES_SURROUND_LSPK__)
extern int D_Distance;
extern int D_Loudspeaker;
extern int SurroundLevelLoudspeaker;
BSRD_InitParam  BsrdInitParam;
#endif
#if defined(__BES_SURROUND_EARP__)
BHDP_InitParam  BhdpInitParam;
#endif
#if defined(__BES_LIVE_SUPPORT__)
BLIVE_InitParam BliveInitParam;
#endif
#if defined(__BES_BASS_SUPPORT__)
extern unsigned short BBAS_LoudspeakerCutoff;
BBAS_InitParam  BbassInitParam;
#endif
#if defined(__BES_EQ_SUPPORT__)
BEQ_InitParam   BeqInitParam;

#ifndef NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_INIT_SIZE
#define BES_EQ_FLEXIBLE_INIT_SIZE 1
#else
#define BES_EQ_FLEXIBLE_INIT_SIZE NVRAM_EF_AUDIO_BES_EQ_FLEXIBLE_INIT_SIZE
#endif

static kal_uint8  BES_EQ_INIT_DATA[BES_EQ_FLEXIBLE_INIT_SIZE] = {0};
kal_uint32 BES_EQ_Band_Num = 8;

kal_int16 Media_QueryBesEQMaxBandNum(void)
{
    return MAX_AUD_EQ_BAND_NUM;
}

void Media_SetBesEQInitParam(kal_uint8 *pBuf, kal_uint32 u4Len)
{
    kal_brief_trace( TRACE_GROUP_APM, FLEXIBLE_EQ_SET_INIT, u4Len);
    ASSERT(u4Len == BES_EQ_FLEXIBLE_INIT_SIZE);    
    memcpy(BES_EQ_INIT_DATA, pBuf, u4Len);   
    BEQ_Get_Band_Num ( (void *)BES_EQ_INIT_DATA, BES_EQ_FLEXIBLE_INIT_SIZE, &BES_EQ_Band_Num);
}

void Media_Equalizer_TransformMag_ToBarNum (kal_int8 *band_mag, kal_int8 *bar_mag, kal_uint32 bar_num)
{
    kal_int32 result = 0;
    kal_uint32 bar_num_tmp =  bar_num;
    kal_brief_trace( TRACE_GROUP_APM, FLEXIBLE_EQ_TRANSFORM, 0,bar_num);
    // force to 8 in current stage due to SWIP provide only 8.
    if ( bar_num_tmp != 8 ) bar_num_tmp = 8;
    result = BEQ_Transform_Mag_To_Bar_Num (
                (void *)BES_EQ_INIT_DATA, 
                BES_EQ_FLEXIBLE_INIT_SIZE, 
                band_mag, 
                bar_mag, 
                bar_num_tmp);
}

void Media_Equalizer_TransformMag_ToBandNum (kal_int8 *bar_mag, kal_int8 *band_mag, kal_uint32 bar_num)
{
    kal_int32 result;    
    kal_uint32 bar_num_tmp =  bar_num;
    kal_brief_trace( TRACE_GROUP_APM, FLEXIBLE_EQ_TRANSFORM, 1,bar_num);
    // force to 8 in current stage due to SWIP provide only 8.
    if ( bar_num_tmp != 8 ) bar_num_tmp = 8;
    result = BEQ_Transform_Mag_To_Band_Num (
                (void *)BES_EQ_INIT_DATA, 
                BES_EQ_FLEXIBLE_INIT_SIZE, 
                bar_mag,
                band_mag,
                bar_num_tmp);
}

#endif

#if defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)

BLOUD_InitParam BloudInitParam;
static kal_bool fBloud_HSF_AVAILABLE = KAL_FALSE;

static void BLOUD_Set_FixFreq(kal_uint32 sampling_rate, BLOUD_FilterCoef_NvramFreq *p_nvram, BLOUD_FilterCoef_FixFreq *p_fix)
{
    kal_int32 sr_idx;
    kal_int32 idx_Q5p27 = 0;
    kal_int32 idx_Q2p14 = 0;
    kal_int32 i;
    
    memset(p_fix, 0, sizeof(BLOUD_FilterCoef_FixFreq));
    
    switch(sampling_rate)
    {
        case 48000: sr_idx = 0; break;
        case 44100: sr_idx = 1; break;
        case 32000: sr_idx = 2; break;
        case 24000: sr_idx = 3; break;
        case 22050: sr_idx = 4; break;
        case 16000: sr_idx = 5; break;
        case 12000: sr_idx = 6; break;
        case 11025: sr_idx = 7; break;
        default:    sr_idx = 8; break;
    }
    
    {
        // HPF
        for (i = 0; i < 2; i++)
        {
            memcpy(&p_fix->q5p27[idx_Q5p27++], p_nvram->HPF_COEF[i][sr_idx], sizeof(BLOUD_Coef_Q5p27));
        }
    }
    
    if (sr_idx < 6)
    {
        // BPF
        for (i = 0; i < 6; i++)
        {
            memcpy(&p_fix->q2p14[idx_Q2p14++], p_nvram->BPF_COEF[i][sr_idx], sizeof(BLOUD_Coef_Q2p14));
        }
        
        // LPF
        {
            memcpy(&p_fix->q2p14[idx_Q2p14++], p_nvram->LPF_COEF[sr_idx], sizeof(BLOUD_Coef_Q2p14));
        }
    }

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
    {
        // Vibration Filter
        for (i = 0; i < 2; i++)
        {
            memcpy(&p_fix->q2p14[idx_Q2p14++], VIBR_NVRAM_DATA.VIBR_NVRAM_LOUD_FILTER_COEF[i][sr_idx], sizeof(BLOUD_Coef_Q2p14));
        }
    }
#endif
    
    return;
}

#if defined( __BES_LOUDNESS_SUPPORT__ )

extern const unsigned char Loudness_Ringtone_Mode;
extern const unsigned char Loudness_NonRingtone_Mode;

static BLOUD_FilterCoef_NvramFreq BESLOUDNESS_SPK_FILTER_DATA;
static BLOUD_CustomParam BESLOUDNESS_CUSTOM_DATA;
static BLOUD_FilterCoef_FixFreq BESLOUDNESS_SPK_FIXFREQ;

kal_uint32 Media_QueryBesLoudnessVersion(void)
{
    return BES_LOUDNESS_VERSION;
}

void Media_SetBesLoudnessCustomCoeff(kal_uint32 *hsf_coeffs, kal_uint32 *bpf_coeffs)
{
    // Set other fields to zero
    // Clear the headphone setting since there was no headphone compensation filter
    memset(&BESLOUDNESS_CUSTOM_DATA    , 0, sizeof(BLOUD_CustomParam));
    memset(&BESLOUDNESS_SPK_FILTER_DATA, 0, sizeof(BLOUD_FilterCoef_NvramFreq));
    
    {   // Copy filter coefficients to the assigned "loudspeaker" setting fields
        kal_int32 i;
        for (i = 0; i < 9; i++)
        {
            memcpy(BESLOUDNESS_SPK_FILTER_DATA.HPF_COEF[0][i], hsf_coeffs, 4*sizeof(kal_uint32));
            hsf_coeffs += 4;
        }
        memcpy(BESLOUDNESS_SPK_FILTER_DATA.BPF_COEF, bpf_coeffs, 4*6*3*sizeof(kal_uint32));
    }
    
    BESLOUDNESS_CUSTOM_DATA.Filter_First = 1;
    if (BESLOUDNESS_SPK_FILTER_DATA.HPF_COEF[0][0][0] != 0)
    {
        fBloud_HSF_AVAILABLE = KAL_TRUE;
    }
}

void Media_SetBesLoudnessCustomCoeff_v3(void *pBuf, kal_uint32 uLen)
{
    if (uLen == sizeof(BLOUD_NVRAM_Param_V4))
    {
        BLOUD_NVRAM_Param_V4 *pTmp = (BLOUD_NVRAM_Param_V4 *)pBuf;
        memcpy(&BESLOUDNESS_SPK_FILTER_DATA, &pTmp->spk_flt_param, sizeof(BLOUD_FilterCoef_NvramFreq));
        memcpy(&BESLOUDNESS_CUSTOM_DATA,     &pTmp->custom_param,  sizeof(BLOUD_CustomParam));
    }
    else if (uLen == sizeof(BLOUD_CustomParam_V3))
    {
        BLOUD_CustomParam_V3 *p_cust_v3 = (BLOUD_CustomParam_V3 *)pBuf;
        
        // Clear the fields
        memset(&BESLOUDNESS_CUSTOM_DATA    , 0, sizeof(BLOUD_CustomParam));
        memset(&BESLOUDNESS_SPK_FILTER_DATA, 0, sizeof(BLOUD_FilterCoef_NvramFreq));
        
        {   // Copy the filter coefficients to the "loudspeaker" setting
            kal_int32 i;
            for (i = 0; i < 9; i++)
            {
                memcpy(BESLOUDNESS_SPK_FILTER_DATA.HPF_COEF[0][i], p_cust_v3->HSF_Coeff[i], 4*sizeof(kal_uint32));
            }
            
            memcpy(BESLOUDNESS_SPK_FILTER_DATA.BPF_COEF, p_cust_v3->BPF_Coeff, 4*6*3*sizeof(kal_uint32));
        }
        
        // Copy other custom data from v3 data structure to the current data structure
        BESLOUDNESS_CUSTOM_DATA.WS_Gain_Max  = p_cust_v3->WS_Gain_Max;
        BESLOUDNESS_CUSTOM_DATA.WS_Gain_Min  = p_cust_v3->WS_Gain_Min;
        BESLOUDNESS_CUSTOM_DATA.Filter_First = p_cust_v3->Filter_First;
        memcpy(BESLOUDNESS_CUSTOM_DATA.Gain_Map_In , p_cust_v3->Gain_Map_In , 5*sizeof(kal_int8));
        memcpy(BESLOUDNESS_CUSTOM_DATA.Gain_Map_Out, p_cust_v3->Gain_Map_Out, 5*sizeof(kal_int8));
    }
    else
    {
        ASSERT(0);
    }
}
#endif

#if defined(__BES_LOUDNESS_ON_I2S__)
static BLOUD_CustomParam BESLOUDNESS_I2S_DATA;
static BLOUD_FilterCoef_NvramFreq BESLOUDNESS_I2S_FILTER_DATA;
static BLOUD_FilterCoef_FixFreq BESLOUDNESS_I2S_FIXFREQ;
void Media_SetBesLoudnessCustomCoeff_I2S(kal_uint32 *hsf_coeffs)
{
    // Clear the parameters
    memset(&BESLOUDNESS_I2S_DATA       , 0, sizeof(BLOUD_CustomParam));
    memset(&BESLOUDNESS_I2S_FILTER_DATA, 0, sizeof(BLOUD_FilterCoef_NvramFreq));
    
    {   // Copy the filter coefficients to the "I2S" setting
        kal_int32 i;
        for (i = 0; i < 9; i++)
        {
            memcpy(BESLOUDNESS_I2S_FILTER_DATA.HPF_COEF[0][i], hsf_coeffs, 4*sizeof(kal_uint32));
            hsf_coeffs += 4;
        }
    }

    BESLOUDNESS_I2S_DATA.Filter_First = 0;
}
#endif //defined(__BES_LOUDNESS_ON_I2S__)

#endif //defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)

#if defined(__BES_CF_SUPPORT__)
BCF_InitParam   BcfInitParam;
#endif

static void apm_SetInitParam( APM_NODE *pTask, APM_TaskID apm_Id )
{
   switch (apm_Id) {
#if defined(__BES_SURROUND_LSPK__)
      case APM_TASKID_SURROUND_LSPK:
         {
            BsrdInitParam.Level       = SurroundLevelLoudspeaker;
            BsrdInitParam.uiDistance1 = D_Loudspeaker;
            BsrdInitParam.uiDistance2 = D_Distance;
            BsrdInitParam.SampleRate  = APM.info.sampleFreq;
            BsrdInitParam.IsStereo    = (kal_int32)APM.info.isStereo;
            pTask->bsInitParSize      = sizeof( BSRD_InitParam );
            pTask->bsInitPar          = (void *)&BsrdInitParam;
            break;
         }
#endif
#if defined(__BES_SURROUND_EARP__)
      case APM_TASKID_SURROUND_EARP:
         {
            BhdpInitParam.SampleRate  = APM.info.sampleFreq;
            BhdpInitParam.IsStereo    = (kal_int32)APM.info.isStereo;
            pTask->bsInitParSize      = sizeof( BHDP_InitParam );
            pTask->bsInitPar          = (void *)&BhdpInitParam;
            break;
         }
#endif
#if defined(__BES_LIVE_SUPPORT__)
      case APM_TASKID_REVERB:
         {
            BliveInitParam.IsStereo   = (kal_int32)APM.info.isStereo;
            BliveInitParam.SampleRate = APM.info.sampleFreq;
            pTask->bsInitParSize      = sizeof( BLIVE_InitParam );
            pTask->bsInitPar          = (void *)&BliveInitParam;
            break;
         }
#endif
#if defined(__BES_BASS_SUPPORT__)
      case APM_TASKID_BASS:
         {
            /*only 400, 500, 600 is valid setting*/
            if( BBAS_LoudspeakerCutoff != 600 && BBAS_LoudspeakerCutoff != 500 && BBAS_LoudspeakerCutoff != 400)
               BbassInitParam.CutoffFreq = 600;
            else
               BbassInitParam.CutoffFreq = (kal_int32)BBAS_LoudspeakerCutoff;
            BbassInitParam.StereoFlag = (kal_int32)APM.info.isStereo;
            BbassInitParam.SampleRate = APM.info.sampleFreq;
            pTask->bsInitParSize      = sizeof( BBAS_InitParam );
            pTask->bsInitPar          = (void *)&BbassInitParam;
            break;
         }
#endif
#if defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)
      case APM_TASKID_LOUDNESS:
         {
            kal_uint32 loudness_mode;
            
            BloudInitParam.Channel_Num = (APM.info.isStereo == KAL_TRUE)? 2 : 1;
            BloudInitParam.Sample_Rate = APM.info.sampleFreq;
            loudness_mode = AudioPP_Loudness_GetMode();
            kal_brief_trace(TRACE_FUNC, L1AUDIO_LOUDNESS_INIT_PARAM, loudness_mode, fBloud_HSF_AVAILABLE);
#if defined(__BES_LOUDNESS_SUPPORT__)
            BLOUD_Set_FixFreq(BloudInitParam.Sample_Rate, &BESLOUDNESS_SPK_FILTER_DATA, &BESLOUDNESS_SPK_FIXFREQ);
            BloudInitParam.pFilter_Coef = &BESLOUDNESS_SPK_FIXFREQ;
            BloudInitParam.pCustom_Param = &BESLOUDNESS_CUSTOM_DATA;
#endif
#if defined(__BES_LOUDNESS_ON_I2S__)
            BLOUD_Set_FixFreq(BloudInitParam.Sample_Rate, &BESLOUDNESS_I2S_FILTER_DATA, &BESLOUDNESS_I2S_FIXFREQ);
#if defined(__BES_LOUDNESS_SUPPORT__)
            if(loudness_mode == BESLOUDNESS_I2S_MODE_LOUDSPEAKER)
            {
               loudness_mode = Loudness_NonRingtone_Mode;
               if(fBloud_HSF_AVAILABLE == KAL_FALSE || Loudness_NonRingtone_Mode == 3)
               {
                  BloudInitParam.pFilter_Coef = &BESLOUDNESS_I2S_FIXFREQ;
                  BloudInitParam.pCustom_Param = &BESLOUDNESS_I2S_DATA;
                  if(Loudness_NonRingtone_Mode == 3 || Loudness_NonRingtone_Mode == 5)
                  {
                     loudness_mode = 5;
                  }
                  else
                  {
                     loudness_mode = 4;
                  }
               }
            }
            else if(loudness_mode == BESLOUDNESS_I2S_MODE_EARPHONE)
            {
               BloudInitParam.pFilter_Coef = &BESLOUDNESS_I2S_FIXFREQ;
               BloudInitParam.pCustom_Param = &BESLOUDNESS_I2S_DATA;
               loudness_mode = 4;
            }
#else
            if(loudness_mode == BESLOUDNESS_I2S_MODE_LOUDSPEAKER || loudness_mode == BESLOUDNESS_I2S_MODE_EARPHONE)
            {
               BloudInitParam.pFilter_Coef = &BESLOUDNESS_I2S_FIXFREQ;
               BloudInitParam.pCustom_Param = &BESLOUDNESS_I2S_DATA;
               loudness_mode = 4;
            }
#endif
#endif
            kal_brief_trace(TRACE_FUNC, L1AUDIO_LOUDNESS_FILTER, loudness_mode, BloudInitParam.pFilter_Coef->q5p27[0].k[0], BloudInitParam.pFilter_Coef->q2p14[0].k[0]);
            switch(loudness_mode)
            {
            case 0:     /* basic mode */
               BloudInitParam.Filter_Mode   = 2;
               BloudInitParam.Loudness_Mode = 1;
               break;
            case 1:     // enhance mode 1 
               BloudInitParam.Filter_Mode   = 2;
               BloudInitParam.Loudness_Mode = 2;
               break;
            case 2:     // enhance mode 2 
               BloudInitParam.Filter_Mode   = 2;
               BloudInitParam.Loudness_Mode = 3;
               break;
            case 3:     // lite mode 
               BloudInitParam.Filter_Mode   = 0;
               BloudInitParam.Loudness_Mode = 1;
               break;
            case 4:     // ACF
               BloudInitParam.Filter_Mode   = 1;
               BloudInitParam.Loudness_Mode = 0;
               break;  
            case 5:     // ACF+DRC
               BloudInitParam.Filter_Mode   = 1;
               BloudInitParam.Loudness_Mode = 1;
               break;
            default:
               ASSERT(0);
               break;
            }
            pTask->bsInitParSize      = sizeof( BLOUD_InitParam );
            pTask->bsInitPar          = (void *)&BloudInitParam;
            break;
         }
#endif
#if defined(__BES_EQ_SUPPORT__)
      case APM_TASKID_EQ:
         {
            BeqInitParam.IsStereo     = (kal_int32)APM.info.isStereo;
            BeqInitParam.SampleRate   = APM.info.sampleFreq;
            BeqInitParam.p_init       = (void *)BES_EQ_INIT_DATA;
            BeqInitParam.ui_init_size = BES_EQ_FLEXIBLE_INIT_SIZE;
            pTask->bsInitParSize      = sizeof( BEQ_InitParam );
            pTask->bsInitPar          = (void *)&BeqInitParam;
            break;
         }
#endif
#if defined(__BES_CF_SUPPORT__)
      case APM_TASKID_CF:
         {
            BcfInitParam.StereoFlag   = (kal_int32)APM.info.isStereo;
            BcfInitParam.SamplingRate = APM.info.sampleFreq;
            BcfInitParam.FilterTap    = 45;
            pTask->bsInitParSize      = sizeof( BCF_InitParam );
            pTask->bsInitPar          = (void *)&BcfInitParam;
            break;
         }
#endif
      default:
         ASSERT(0);   // Unknown
   }
}

//  To reset the read/write pointer
static void apm_ResetPtr( void )
{
   int i;
   APM_NODE *pTask;

   pTask = APM.task;
   for (i=APM.taskNum-1; i>=0; i--) {
      pTask->read = pTask->write = 0;
      pTask++;
   }
   
   kal_brief_trace(TRACE_GROUP_APM, APM_CLEARBUFFER);
}

// To activate the new tasks
static void apm_ActivateTask(kal_bool enableOLA)
{
   int i;
   uint32 newTaskCache;
   APM_NODE *pTask;

   kal_trace(TRACE_GROUP_APM, APM_ACTIVATE_INFO, APM.newTask, APM.info.sampleFreq, 1+(int)APM.info.isStereo);

   pTask = APM.task;
   newTaskCache = APM.newTask;
   for (i=APM.taskNum-1; i>=0; i--) {
      if ( (1<<pTask->para->apm_Id) & newTaskCache ) {
#if defined( BESSOUND_SUPPORT )
         if (pTask->para->SetHandle != NULL) {//Use BesSound Interface
            uint32 InternalBufferSize, TempBufferSize;
            
            pTask->bsh = get_ctrl_buffer(sizeof(BS_Handle));
            pTask->para->SetHandle( pTask->bsh );
            pTask->bsh->GetBufferSize( pTask->bsh, &InternalBufferSize, &TempBufferSize );

            if( InternalBufferSize > 0 && pTask->tcm.tcmBuf == 0)
            {
               //use external memory as internal buffer
               //kal_prompt_trace(MOD_L1SP,"[wn_apm]InternalBufferSize: ID: %d, memory alloc: %d", pTask->para->apm_Id, InternalBufferSize);
               pTask->tcm.tcmBuf = (uint32 *)audio_alloc_mem( InternalBufferSize );
               ASSERT(pTask->tcm.tcmBuf);
               memset(pTask->tcm.tcmBuf, 0, InternalBufferSize);
            }

            if( TempBufferSize > 0 && pTask->tempBuf == 0) 
            {
               //kal_prompt_trace(MOD_L1SP,"[wn_apm]TempBufferSize: ID: %d, memory alloc: %d", pTask->para->apm_Id, TempBufferSize);
               pTask->tempBuf = (uint8 *)audio_alloc_mem( TempBufferSize );
               ASSERT(pTask->tempBuf != NULL);
               memset(pTask->tempBuf, 0, TempBufferSize);
            }
            apm_SetInitParam( pTask, pTask->para->apm_Id );
            pTask->bsh->Open( pTask->bsh, (void *)pTask->tcm.tcmBuf, pTask->bsInitParSize, pTask->bsInitPar, enableOLA );
            if( pTask->bsRunTimeParSize != 0 )
               pTask->bsh->SetParameters( pTask->bsh, pTask->bsRunTimeParSize, pTask->bsRunTimePar); // set run time parameters
            kal_trace(TRACE_GROUP_APM, APM_ACTIVATING, pTask->para->apm_Id);
         } else 
#endif
         if (pTask->para->Activate != NULL) //non-BesSound
         {
            if(pTask->tcm.tcmBufLen != 0 && pTask->tcm.tcmBuf == NULL)
            {
               //kal_prompt_trace(MOD_L1SP,"[wn_apm]InternalBufferSize: ID: %d, memory alloc: %d", pTask->para->apm_Id, pTask->tcm.tcmBufLen);
               pTask->tcm.tcmBuf = (uint32 *)audio_alloc_mem( pTask->tcm.tcmBufLen );
               ASSERT(pTask->tcm.tcmBuf);
               memset(pTask->tcm.tcmBuf, 0, pTask->tcm.tcmBufLen );
               if(pTask->para->Init)
               {
                  pTask->para->Init(&pTask->tcm);
               }
            }
            kal_trace(TRACE_GROUP_APM, APM_ACTIVATING, pTask->para->apm_Id);
            pTask->para->Activate(&APM.info);
         }
      }
      pTask++;
   }
   APM.newTask &= ~newTaskCache;
}

// To de-activate the del tasks
static void apm_DeActivateTask(void)
{
   int i;
   uint32 delTaskCache;
   APM_NODE *pTask;

   kal_trace(TRACE_GROUP_APM, APM_DEACTIVATE_INFO, APM.delTask);

   pTask = APM.task;
   delTaskCache = APM.delTask;
   for (i=APM.taskNum-1; i>=0; i--) {
      if ( (1<<pTask->para->apm_Id) & delTaskCache ) {
#if defined( BESSOUND_SUPPORT )
         if (pTask->para->SetHandle != NULL) {//BesSound Interface
            if( pTask->bsh != NULL ){
               free_ctrl_buffer( pTask->bsh );

               if( pTask->tcm.tcmBuf != NULL ){
                  //use external memory as internal buffer
                  audio_free_mem( (void**)&(pTask->tcm.tcmBuf) );
                  pTask->tcm.tcmBuf = NULL;
               }

               if( pTask->tempBuf != NULL )
                  audio_free_mem( (void**)&pTask->tempBuf );
               pTask->bsh = NULL;
            }
            //
            kal_trace(TRACE_GROUP_APM, APM_DEACTIVATING, pTask->para->apm_Id);
         }
#endif
         if (pTask->para->Deactivate != NULL) {
            kal_trace(TRACE_GROUP_APM, APM_DEACTIVATING, pTask->para->apm_Id);
            pTask->para->Deactivate();

            if( pTask->tcm.tcmBuf != NULL )
            {
               audio_free_mem( (void**)&(pTask->tcm.tcmBuf) );
               pTask->tcm.tcmBuf = NULL;
            }
         }
      }
      pTask++;
   }
   APM.delTask &= ~delTaskCache;
}

// To update the EOF level
// Set as the next registered level
static void apm_UpdateEofLevel(void)
{
   int i;

   for (i=APM.eofLevel+1; i<32; i++) {
      if ( APM.regLevel & (1<<i) )
         break;
   }
   APM.eofLevel = i;
}

static void apm_ProcessTask(void)
{
   APM_NODE *pTask;
   int readBND;         // The boundary of available read data from task's view
   int count, bufSize;
   int i;
   kal_uint32 uProcessTasks = (APM.procTask & (~APM.newTask)) | APM.exeRampdownTask;

   //---- Process Input Buffer ----
   pTask = APM.task;
   readBND = APM.write;
   bufSize = APM.rb_size;
   // Process each task
   
   if(APM.taskNum==0)
   {
   	  pTask->read = pTask->write = readBND; 
   }

   for (i=APM.taskNum-1; i>=0; i--) {
      if (APM.dropFlagInternal)
         break;
      
      if ( (1<<pTask->para->apm_Id) & uProcessTasks ) {
         /* The process is enabled */
         kal_bool fContinue;
         
         // Check EOF
         APM.info.isEOF = false;
         fContinue = true;
         count = GetReadDataCount(pTask->read, readBND, bufSize);

         if (pTask->para->level < APM.eofLevel) {
            // Skip the post-process
            fContinue = false;
            APM.procTask &= ~(1<<pTask->para->apm_Id);
            pTask->write = readBND;
         }
         
         do{
            uint32 oriInLen, incCount;
            kal_int16 gain = APM_MAX_DIGITAL_GAIN;
            
            if((!fContinue) || APM.dropFlagInternal){
               break;
            }
            
            if(pTask->para->property == APM_PROPERTY_READ_ONLY)
            {
               gain = AFE_GetAudioDigiGain(KAL_FALSE);
            }
            if(APM_TASKID_I2S_RECORD == pTask->para->apm_Id)
            {
               gain = APM_MAX_DIGITAL_GAIN;
            }
            oriInLen = GetReadDataToTempBuf(pTask->read, readBND, bufSize, gain); //do not apply digigain for recording
            APM.bufInfo.inBufLen = APM.bufInfo.outBufLen = oriInLen & 0xFFFFFFFE;
            APM.bufInfo.inBuf = APM.tempInBuf;
            APM.bufInfo.outBuf = APM.tempOutBuf;
            
            // EOF checking
            if ( (pTask->para->level==APM.eofLevel) && (count<=MaxTempBufSize) )
               APM.info.isEOF = true;

            // Process the data in APM.tempInBuf
            {
               kal_bool fEOF;
#if defined( BESSOUND_SUPPORT )
               if( pTask->para->SetHandle != NULL ){//BesSound Interface
                  if (pTask->bsh) {
                     pTask->bsh->Process( pTask->bsh,
                                          (char *)pTask->tempBuf,
                                          (const short *)APM.bufInfo.inBuf,
                                          (kal_int32 *)&(APM.bufInfo.inBufLen),
                                          APM.bufInfo.outBuf,
                                          (kal_int32 *)&(APM.bufInfo.outBufLen) );
                     if (APM.exeRampdownTask & (1<<pTask->para->apm_Id)) {
                        if ( (APM.bufInfo.inBufLen) ||
                        	   ( Media_IsDSPDec() && !Media_IsAlwaysRoute() &&
                        	     !(APM.rwTask & (APM.regTask & ~(1<<pTask->para->apm_Id)) ) )
                        	 )
                        {
                           APM.exeRampdownTask &= ~(1<<pTask->para->apm_Id);
                           APM.delTask |= (1<<pTask->para->apm_Id);
                        }
                     }
                     
                     fEOF = KAL_TRUE;//EOF
                  } else {
                     pTask->read = pTask->write = readBND;
                     break;
                  }
               } else 
#endif
               {
                  fEOF = pTask->para->Process(&APM.bufInfo, &APM.info);
               }
               
               // Update the EOF level if the process finished the tail of playback
               if ( (fEOF) && (pTask->para->level==APM.eofLevel) ) {
                  APM.procTask &= ~(1<<pTask->para->apm_Id);
                  apm_UpdateEofLevel();
               }
            }
            
            // Check the number of produced/consumed data is legal
            ASSERT(oriInLen >= APM.bufInfo.inBufLen);
            if (APM.eofState >= APM_EOF_ENDING) {
               if (APM.bufInfo.outBufLen >= APM.bufInfo.inBufLen)
                  incCount = APM.bufInfo.outBufLen;
               else
                  incCount = APM.bufInfo.inBufLen;
            } else {
               // Check the amount of produced and consumed data
               if ( pTask->para->property != APM_PROPERTY_READ_ONLY ) {
                  ASSERT(APM.bufInfo.inBufLen == APM.bufInfo.outBufLen);
               }
               incCount = APM.bufInfo.inBufLen;
            }
            
            if ( !APM.dropFlagInternal ) {
               // Update the number of remained data, and check whether continue to feed data
               count -= (int)incCount;
               fContinue = (incCount == 0)? false : true;
             
               // Update task read / write pointer
               // Save the result to APM.InputBuf as the input of next task
               pTask->read += incCount;    // APM.bufInfo.inBufLen
               if (pTask->read >= bufSize)
                  pTask->read -= bufSize;
               
               if ( pTask->para->property != APM_PROPERTY_READ_ONLY ) {
                  PutWriteDataFromTempBuf(pTask->write, pTask->read, bufSize, APM.bufInfo.outBufLen);
               }
               
               pTask->write += incCount;   // APM.bufInfo.outBufLen
               if (pTask->write >= bufSize)
                  pTask->write -= bufSize;
            }
         } while ( (fContinue) && (count || APM.info.isChange) && (!APM.dropFlagInternal) ) ;
         // Update the boundary of read pointer of source data for the next task
         readBND = pTask->write;
      } else {
         // The process doesn't enable, we only have to update the pointer
         pTask->read = pTask->write = readBND;
      }

      pTask++;
   }
}

static void apm_NotifyRampDown(void)
{
   int i;
   uint32 rampdownTaskCache;
   APM_NODE *pTask;

   pTask = APM.task;
   rampdownTaskCache = APM.notifyRampdownTask;
   for (i=APM.taskNum-1; i>=0; i--) {
      if ( (1<<pTask->para->apm_Id) & rampdownTaskCache ) {
#if defined( BESSOUND_SUPPORT )
         if (pTask->para->SetHandle != NULL) {
            if( pTask->bsh != NULL ){
               pTask->bsh->Close( pTask->bsh, true );
               APM.exeRampdownTask |= (1<<pTask->para->apm_Id);
            } else {
               APM.delTask |= (1<<pTask->para->apm_Id);
            }
         }
         else
#endif
         {
            APM.delTask |= (1<<pTask->para->apm_Id);
         }
      }
      
      pTask++;
   }
   
   APM.notifyRampdownTask &= ~rampdownTaskCache;
}


/*
 *  ------------------------------------------------
 *  |          Input Buffer                         |
 *  ------------------------------------------------
 *     |       |                   |            |
 *     |    PP write            PP read         |
 *  witePos                                 readBND (the boundary of source data)
 *
 *  To control flow of function call and feed PCM to each post-process
 *  (1) Activate the new post-processes
 *  (2) Process the registered post-processes
 *  (3) Deactivate the del post-processes (un-registered)
 */

static void AudioPP_Manager( void *data )
{
   kal_bool enableOLA = KAL_TRUE;

   // Reset the initial state of task if needed
   if (APM.isReset) {
      enableOLA = KAL_FALSE;
      apm_ResetPtr();
      APM.isReset = false;
   }

   // To Activate the registered task
   if (APM.notifyRampdownTask) {
      apm_NotifyRampDown();
      apm_ProcessTask();
   }

   // To deactivate the registered task
   if (APM.delTask)
      apm_DeActivateTask();

   // To Activate the registered task
   if (!APM.notifyRampdownTask && !APM.exeRampdownTask) {
      if (APM.newTask)
         apm_ActivateTask(enableOLA);
   }
   
   apm_ProcessTask();

   if ( APM.dropFlagInternal &&
   	    ((APM.eofState==APM_EOF_WAITING) || (APM.eofState==APM_EOF_ENDING)) )
   {
      APM.eofState = APM_EOF_FINISH;
   }

   // EOF handling
   if ( ((APM.regTask==0)||(APM.eofLevel==32)) &&
   	    ((APM.eofState==APM_EOF_WAITING) || (APM.eofState==APM_EOF_ENDING)) ) {
      int dataCnt;
      
      dataCnt = APM.tail->write - APM.read;
      if (dataCnt < 0)
         dataCnt += MaxSampleBufSize;
      
      APM.eofState = APM_EOF_TAILING;
      APM.numRemain = dataCnt;
   }

   APM.info.isChange = false;
   
   if (APM.dropFlagInternal) {
      APM.dropFrame++;
      if (APM.dropFrame == 1) {
         int i;
         APM_NODE *pTask;   
         uint32 savedMask;

         // To deactivate all registered tasks
         savedMask = SaveAndSetIRQMask();
         APM.read = APM.write = 0;
         RestoreIRQMask( savedMask );

         pTask = APM.task;
         for (i=APM.taskNum-1; i>=0; i--) {
            pTask->read = pTask->write = 0;
            pTask++;
         }
      } else if (APM.dropFrame > APM.dropBoundary) {
         APM.preBuffer = true;
         APM.dropCount = 0;
         APM.dropFrame = 0;
         APM.dropFlagInternal = false;
      }
   }
}

//-------- L1audio Internal Use --------

/*
 *  Initialize the state and data of PCM Route
 *  Link all post process in the linked list
 */
extern const APM_TASK_PARA *apmTaskList[];
#if defined(__APM_USE_STATIC_MEMORY__)
void APM_Init( void )
{
   int i;
   int level;
   uint32 validTcmSize;
   uint32 *TcmBuf;
   uint32 levelSize[32];   // The maximal TCM size in each level

   memset(&APM, 0, sizeof(APM));
   APM.rb_size = MaxSampleBufSize;
   APM.bufInfo.inBuf = APM.tempInBuf;
   APM.bufInfo.outBuf = APM.tempOutBuf;
   APM.BesSound_disable = 0;

   //-- Two phase pass
   // Phase 1: to check the argument, and find out the maximal TCM size in each level
   level = 0;
   memset(levelSize, 0, 32*sizeof(uint32));
   for (i=0; apmTaskList[i]!=NULL; i++) {
      uint8 tempID, tempLevel;
      
      // The maximal number is 32
      ASSERT(i<32);
      
      tempID = apmTaskList[i]->apm_Id;
      tempLevel = apmTaskList[i]->level;
      ASSERT(tempID<32);
      ASSERT(tempLevel<32);
      ASSERT(level <= tempLevel);
      // Hook task
      APM.task[i].para = apmTaskList[i];
      APM.map[tempID] = tempLevel;
      level = tempLevel;
      
      if (apmTaskList[i]->property == APM_PROPERTY_READ_WRITE)
         APM.rwTask |= (1<<tempID);
      
      if (apmTaskList[i]->tcmSize > levelSize[tempLevel])
         levelSize[tempLevel] = apmTaskList[i]->tcmSize;
   }
   APM.taskNum = i;
   if (i>0) {
      APM.tail = &APM.task[i-1];
   } else {
      APM.tail = &APM.task[0];
   }
   
   // For time stretch
   APM.rwTask |= (1<<APM_TASKID_TS);
   
   // Phase 2: to assign TCM and initialize
   TcmBuf = NULL;
   validTcmSize = 0;
   level = apmTaskList[0]->level;

   TcmBuf = NULL;
   validTcmSize = 0;
   //Media_GetShareMem(&TcmBuf, &validTcmSize);

   for (i=0; apmTaskList[i]!=NULL; i++) {
      uint8 tempLevel;
      uint32 tempSize;

      // Update TCM buffer and size
      tempLevel = apmTaskList[i]->level;
      if (level != tempLevel) {
         tempSize = (levelSize[level]+3)>>2;
         level = tempLevel;
         TcmBuf += tempSize;
         validTcmSize -= (tempSize<<2);
      }

      APM.task[i].tcm.tcmBuf = NULL;
      APM.task[i].tcm.tcmBufLen = levelSize[tempLevel];
   }

   APM.remainTCM.tcmBuf = NULL;
   APM.remainTCM.tcmBufLen = 0;

   APM.aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( APM.aud_id, AudioPP_Manager );
}
#endif

/*
 *  Activate DSP to route PCM data to MCU
 *  Set the value of the related sherif
 */
void APM_Activate( kal_int16 channel, kal_int16 freqInd)
{
   int freq;
   
   // To preload all
   {
      kal_uint32 uID;
      
      APM.uPreload = APM.regTask;
      
      for (uID=0; uID<32; uID++) {
         if ( (1<<uID) & APM.uPreload ) {
            apm_LoadCode( (APM_TaskID)uID );
         }
      }
   }
   
   // Convert frequency index to frequency
   // Keep the information to notify task in future
   switch (freqInd) {
      case 0x00:  freq =  8000;  break;
      case 0x11:  freq = 11025;  break;
      case 0x12:  freq = 12000;  break;
      case 0x20:  freq = 16000;  break;
      case 0x21:  freq = 22050;  break;
      case 0x22:  freq = 24000;  break;
      case 0x40:  freq = 32000;  break;
      case 0x41:  freq = 44100;  break;
      case 0x42:  freq = 48000;  break;
      default:
         freq = 0;    // Avoid compile warning
         ASSERT(0);   // Unknown
   }
   
   APM.info.sampleFreq = freq;
   if (channel == 1)
      APM.info.isStereo = false;
   else
      APM.info.isStereo = true;
   
   APM.isRunning = true;

   APM.newTask = APM.regTask;
   APM.procTask = APM.regTask;
   APM.notifyRampdownTask = 0;
   APM.exeRampdownTask = 0;
   APM.eofLevel = -1;
   APM.delaySample = 0;

   APM.isReset = true;
   APM.dropFlagInternal = false;
   APM.dropCount = 0;
   APM.dropFrame = 0;
   APM.dropBoundary = 0;
   APM.rampUp = false;
   APM.rampGain = 0;
   APM.eofState = APM_EOF_IDLE;
   APM.eofWaitFrame = 0;
   APM.hdl = NULL;
   APM.EofHandle = NULL;
   APM.read = APM.write = 0;
   APM.tail->write = 0;
   APM.info.isChange = true;
   
   APM.smoothState = APM_SMOOTH_STATE_NONE;
   APM.preBuffer = true;
}

/*
 *  Deactivate DSP to route PCM data to MCU
 *  Clear the value of the related sherif
 *  The work of deactivating all post-process is done in L1Audio task in later time
 */
void APM_Deactivate(void)
{
   uint32 savedMask;
   // To deactivate all registered tasks
   APM.isRunning = false;
   
   savedMask = SaveAndSetIRQMask();
   APM.newTask = 0;
   APM.procTask = 0;
   APM.delTask |= APM.regTask;
   APM.eofState = APM_EOF_DONE;
   APM.read = APM.write = 0;
   APM.tail->write = 0;
   APM.dropFlagInternal = false;
   APM.dropCount = 0;
   APM.dropFrame = 0;
   RestoreIRQMask( savedMask );
   
   // Notify APM to deactivate all post process
   L1Audio_SetEvent( APM.aud_id, (void *) 0 );
   // To unload all
   {
      kal_uint32 uID;
      
      for (uID=0; uID<32; uID++) {
         if ( (1<<uID) & APM.uPreload ) {
            apm_UnloadCode( (APM_TaskID)uID );
         }
      }
      APM.uPreload = 0;
   }
   mhdlUnHookPcmRut(); 
}

/*
 *  To clear all buffer of APM when the speed is changed by Time Stretch
 */
void APM_ClearBuffer(void)
{
   uint32 savedMask;
   int i;
   APM_NODE *pTask;   
   
   savedMask = SaveAndSetIRQMask();
   APM.read = APM.write = 0;
   pTask = APM.task;
   for (i=APM.taskNum-1; i>=0; i--) {
      pTask->read = pTask->write = 0;
      pTask++;
   }
   RestoreIRQMask( savedMask );
}

// For AV-Sync
kal_int32 APM_AV_DelayCount(void)
{
   int numInt, tempSample;
   
   tempSample = APM.delaySample;
   numInt = tempSample / 6;
   APM.delaySample = tempSample - (numInt*6);
   
   return numInt;
}

void APM_AV_ConsumeDelay(kal_int32 numInt)
{
   numInt = numInt*6;
   if (APM.delaySample >= numInt)
      APM.delaySample -= (numInt*6);
   else
      APM.delaySample = 0;
}

void APM_NOTIFY_MEDIA_END(void (*HookFunc)(void *data, Media_Event event), void *data, kal_bool isNew, Media_Event event)
{
   ASSERT(0);
}

kal_bool APM_IsMediaEnd(void)
{
   if ( APM.isRunning && (APM.EofHandle != NULL) ) {
      return true;
   }
   
   return false;
}

kal_bool APM_IsLoudnessOn(void)
{
    if(APM.regTask & (1<<APM_TASKID_LOUDNESS))
    {	
    	return KAL_TRUE;
    }
    return KAL_FALSE;	
}

void APM_EXECUTE_END_HANDLER(void)
{
   if (APM.eofState == APM_EOF_DONE_END)
      return;

   if (APM.EofHandle != NULL) {
      APM.eofState = APM_EOF_DONE_END;
      APM.EofHandle(APM.hdl, APM.event);
   }
}

void APM_NotifyDropFrame(kal_bool isDrop)
{
   uint32 savedMask;

   (void) isDrop;

   if (!APM.dropFlagInternal) {
      savedMask = SaveAndSetIRQMask();
      APM.dropFlagInternal = true;
      APM.dropCount = 0;
      RestoreIRQMask( savedMask );
   }
}

/*
 *  To assign the remained TCM buffer
 *  Only one block of memory is provided
 *  Return:
 *	    the buffer address, if the size is enough
 *	    NULL, otherwise
 */
kal_uint8 *APM_Allocate_Buffer(uint32 bufSize)
{
   return NULL;
}

/*
 *  To release the remained TCM buffer
 */
void APM_Release_Buffer(void)
{
   APM.isRemainTCMOccupy = false;
}

// ***** API for HOST Post-Process *****
/*
 *  To registry process ID to APM
 *    Then APM wil be activated, and APM will feed data to the post-process
 *  The goal of registry is to reduce data movement and to save power consumption
 *  If there is no registered process, APM doesn't need to move data from/to DSP
 */
void HOST_APM_Register(APM_TaskID taskID)
{
   uint32 savedMask;

   kal_brief_trace(TRACE_GROUP_APM, APM_REGISTER, taskID, APM.regTask);
   
   ASSERT( taskID<32 );
   
   // Preload
   if (APM.isRunning) {
      if ( 0 == ( (1<<taskID) & APM.uPreload ) ) {
         APM.uPreload |= (1<<taskID);
         apm_LoadCode(taskID);
      }
   }

   if ( (APM.regTask == 0) && (APM.isRunning))
   {
      if(taskID & ~APM.rwTask)
      {
         mhdlHookPcmRut(); 
      }
      else if(APM.BesSound_disable || (APM.BesSound_disable_in_Video && AudioPP_IsDisableInVideo(taskID)))
      {
      }
      else
      {
         mhdlHookPcmRut();
      }
   }
   
   if ( (APM.regTask & (1<<taskID))==0 ) {
      if (taskID != APM_TASKID_TS)
         ASSERT( (APM.regLevel & (1<<APM.map[taskID])) == 0);
      
      savedMask = SaveAndSetIRQMask();

      if (APM.rwTask & (1<<taskID))
      {
         APM.resumeTask |= (1<<taskID);
         if(APM.BesSound_disable)
         {
            RestoreIRQMask( savedMask );
            return;
         }
         if(APM.BesSound_disable_in_Video && AudioPP_IsDisableInVideo(taskID))
         {
            RestoreIRQMask( savedMask );
            return;
         }
      }
  
      if ( APM.rwTask & (1<<taskID) ) {
         if ( APM.isRunning && !(APM.regTask & APM.rwTask) ) {
            if ( Media_IsDSPDec() && !Media_IsAlwaysRoute() ) {
               APM.read = APM.write = 0;
               APM.tail->write = 0;
               APM.isReset = true;
               APM.smoothState = APM_SMOOTH_STATE_ORI2PROC;
            } else {
               APM.smoothState = APM_SMOOTH_STATE_PROC2PROC;
            }
         }
      }
      APM.preBuffer = true;
      APM.regTask |= (1<<taskID);
      APM.procTask |= (1<<taskID);
      APM.newTask |= (1<<taskID);
//      APM.delTask &= ~(1<<taskID);
      if (taskID != APM_TASKID_TS)
         APM.regLevel |= (1<<APM.map[taskID]);
      
      RestoreIRQMask( savedMask );
   }
}

/*
 *  To un-registry process ID to APM
 *  The goal of registry is to reduce data movement and to save power consumption
 *  If there is no registered process, APM doesn't need to move data from/to DSP
 */
void HOST_APM_UnRegister(APM_TaskID taskID)
{
   uint32 savedMask;
   
   kal_brief_trace(TRACE_GROUP_APM, APM_UNREGISTER, taskID, APM.regTask);

   ASSERT( taskID<32 );
   
   savedMask = SaveAndSetIRQMask();
   if (APM.rwTask & (1<<taskID))
      APM.resumeTask &= ~(1<<taskID);

   if (APM.regTask & (1<<taskID)) {
      APM.regTask &= ~(1<<taskID);
      APM.procTask &= ~(1<<taskID);
      APM.newTask &= ~(1<<taskID);
      //APM.delTask |= (1<<taskID);
      APM.notifyRampdownTask |= (1<<taskID);
      if (taskID != APM_TASKID_TS)
         APM.regLevel &= ~(1<<APM.map[taskID]);

      if ( APM.rwTask & (1<<taskID) ) {
         if ( APM.isRunning && !(APM.regTask & APM.rwTask) ) {
            APM.smoothState = APM_SMOOTH_STATE_PROC2ORI;
         }
      }
   }
   RestoreIRQMask( savedMask );

   // In order to deactivate the post-process, Unload TCM, and Close Audio Playback (if needed)
   // This is necessary to Unload TCM immediately
   // However, it is not timing critical to load TCM in HOST_APM_Register
   if ( APM.notifyRampdownTask && APM.isRunning ) {
      L1Audio_SetEvent( APM.aud_id, (void *) 0 );
   }
   
   if ( (APM.regTask == 0) && (APM.isRunning)){
   	  // when AAC SBR decode enable, must not stop pcmrut HISR   	  
   	  if ( Is_PutPcmrutOn() && !Media_IsAlwaysRoute() )
   	      mhdlUnHookPcmRut();
   }   

   // Unload
   if (APM.isRunning) {
      if ( (1<<taskID) & APM.uPreload ) {
         APM.uPreload &= ~(1<<taskID);
         apm_UnloadCode(taskID);
      }
   }
}
#if defined( BESSOUND_SUPPORT )
void APM_SetPP_Param( APM_TaskID apm_Id, uint32 runTimeParamSize, void *pRuntimeParam, uint32 bsInitParSize, void *bsInitPar )
{
   kal_int32 i;
   for (i=APM.taskNum-1; i>=0; i--) {
      if( APM.task[i].para->apm_Id == apm_Id ){
         if( runTimeParamSize != 0){
            APM.task[i].bsRunTimeParSize = runTimeParamSize;
            APM.task[i].bsRunTimePar = pRuntimeParam;
         }
         if( bsInitParSize != 0){
            APM.task[i].bsInitParSize = bsInitParSize;
            APM.task[i].bsInitPar = bsInitPar;
         }
         if( APM.task[i].bsh != NULL && runTimeParamSize != 0 )
            APM.task[i].bsh->SetParameters( APM.task[i].bsh, runTimeParamSize, pRuntimeParam);
         break;
      }
   }
}

/*assert porting for BesSound engine*/
void BES_ASSERT(int expression)
{
   ASSERT( expression );
}

#endif


/*------------------------------------------------*/
/* The private member functions of APM component. */
/*------------------------------------------------*/
static OMX_ERRORTYPE APMCom_Start(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   APM_ComData *pAPMData = (APM_ComData *)ihdl->pPrivateData;
   kal_int16 index = 0;
   
   ihdl->isEOF = KAL_FALSE;
   APM.phdl = hdl;
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY) {
      return OMX_ErrorIncorrectStateOperation;
   }

   switch (pAPMData->uSamplingFreq) {
      case  8000:  index = 0x00;  break;
      case 11025:  index = 0x11;  break;
      case 12000:  index = 0x12;  break;
      case 16000:  index = 0x20;  break;
      case 22050:  index = 0x21;  break;
      case 24000:  index = 0x22;  break;
      case 32000:  index = 0x40;  break;
      case 44100:  index = 0x41;  break;
      case 48000:  index = 0x42;  break;     
      default:
         ASSERT(0);   // Unknown
   }

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_APM, ihdl->mediaStatus,pAPMData->uSamplingFreq,0,0,0);
   APM_Activate( pAPMData->uChannelNum , index);
   pAPMData->uPreSilence = 0;   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   ACU_SendProcessCommandl( (AudComHdlInt *)hdl );
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE APMCom_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   APM_ComData *pAPMData = (APM_ComData *)ihdl->pPrivateData;

   switch (index) {
      case OMX_IndexParamMediaTekSetPCMInfo:
      case OMX_IndexParamMediaTekAPMParam:
         {
            SinkParam *pParam = (SinkParam *)pStruct;
            pAPMData->uSamplingFreq = pParam->uSamplingFreq;
            pAPMData->uChannelNum = pParam->uChannelNum;
         }
         break;
      default:
         return OMX_ErrorNotImplemented;
   }

   return OMX_ErrorNone;
}

static OMX_ERRORTYPE APMCom_Stop(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   APM_Deactivate();
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_STOP, MTKAUD_APM, ihdl->mediaStatus,ihdl->endStatus,0,0,0);
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE APMCom_Deinit(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   
   ACU_FlushBufferQueue(hdl);
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEINIT, MTKAUD_APM, ihdl->mediaStatus,ihdl->endStatus,0,0,0);
   
   return OMX_ErrorNone;
}

static void apm_GetInternalWriteBuffer(kal_int16 **pBuf, kal_uint32 *uLen)
{
   kal_uint32 segment;
   
   if (APM.read > APM.write) {
      segment = APM.read - APM.write - 1;
   } else if (APM.read == 0) {
      segment = APM.rb_size - APM.write - 1;
   } else {
      segment = APM.rb_size - APM.write;
   }
   
   *pBuf = APM.SampleBuf + APM.write;
   *uLen = segment;
}

static void apm_GetInternalReadBuffer(kal_int16 **pBuf, kal_uint32 *uLen)
{
   kal_uint32 segment;
   
   if (APM.tail->write >= APM.read) {
      segment = APM.tail->write - APM.read;
   } else {
      segment = APM.rb_size - APM.read;
   }
   
   *pBuf = APM.SampleBuf + APM.read;
   *uLen = segment;
}

static void apm_UpdateInternalWritePointer(kal_uint32 uLen)
{
   APM.write += uLen;
   if (APM.write >= APM.rb_size)
      APM.write = 0;
}

static void apm_UpdateInternalReadPointer(kal_uint32 uLen)
{
   APM.read += uLen;
   if (APM.read >= APM.rb_size)
      APM.read = 0;
}

static kal_int32 apm_GetFreeCount(void)
{
   kal_int32 count = 0;
   
   if (APM.read > APM.write) {
      count = APM.read - APM.write - 1;
   } else {
      count = APM.rb_size - APM.write + APM.read - 1;
   }
   
   return count;
}

static void apmCom_MoveDataFromInputQueue(AudComHdl *hdl)
{
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_uint32 sizeQueue8, sizeQueue16, sizeInternal16;
   kal_int16 *pBufInternal;
   OMX_U8 *pBufQueue;
   kal_uint32 amount;
   kal_uint32 uFreeCount;
   
   while (1) {
      // Get the data amount of queue
      ACU_GetReadBuffer(hdl, &pBufQueue, &sizeQueue8);
      sizeQueue16 = sizeQueue8 >> 1;
      if (sizeQueue16 == 0 || ihdl->isEOF) {
         ACU_ReadDataDone(hdl, 0);
         
         if ((ihdl->isEOF) && (APM.eofState != APM_EOF_ENDING)) 
         {
            APM.eofState = APM_EOF_ENDING;
            APM.eofLevel = 0;
            apm_UpdateEofLevel();
         }
         break;
      }
      
      uFreeCount = (kal_uint32)apm_GetFreeCount();
      if (uFreeCount < sizeQueue16)
      {	
         sizeQueue16 = uFreeCount;
      }
      
      // Get the size of APM internal sample buffer
      apm_GetInternalWriteBuffer(&pBufInternal, &sizeInternal16);
      if (sizeInternal16 == 0) {
         break;
      }
      
      // Compare the amount
      if (sizeInternal16 > sizeQueue16) {
         amount = sizeQueue16;
      } else {
         amount = sizeInternal16;
      }
      
      // Copy data
      memcpy(pBufInternal, pBufQueue, amount*sizeof(kal_uint16));
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_APM_IN, MTKAUD_APM, sizeInternal16*2, sizeQueue16*2, amount*2,0,0,0);

      // Update pointer
      ACU_ReadDataDone(hdl, amount*2);
      apm_UpdateInternalWritePointer(amount);
   };
}

static void apmCom_MoveDataToOutputQueue(AudComHdl *hdl)
{
   kal_uint32 sizeQueue8, sizeQueue16, sizeInternal16;
   kal_int16 *pBufInternal;
   OMX_U8 *pBufQueue;
   kal_uint32 amount;

   while (1) {
      // Get the size of APM internal sample buffer
      apm_GetInternalReadBuffer(&pBufInternal, &sizeInternal16);
      if (sizeInternal16 == 0) {
         break;
      }
      
      // Get the data amount of queue
      ACU_GetWriteBuffer(hdl, &pBufQueue, &sizeQueue8);
      sizeQueue16 = sizeQueue8 >> 1;
      if (sizeQueue16 == 0)
         break;
      
      // Compare the amount
      if (sizeInternal16 > sizeQueue16)
         amount = sizeQueue16;
      else
         amount = sizeInternal16;
      // Copy data
      memcpy(pBufQueue, pBufInternal, amount*sizeof(kal_uint16));         

      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_APM_OUT, MTKAUD_APM, sizeInternal16*2, sizeQueue16*2, amount*2,0,0,0);

      // Update pointer
      ACU_WriteDataDone(hdl, amount*2);
      apm_UpdateInternalReadPointer(amount);
   };
}

static void apmCom_FillSilencToOutputQueue(AudComHdl *hdl)
{
   while (1) 
   {
      kal_uint32 sizeQueue8;
      OMX_U8 *pBufQueue;
      ACU_GetWriteBuffer(hdl, &pBufQueue, &sizeQueue8);
      if (sizeQueue8 == 0)
      {
         return;
      }
      memset(pBufQueue, 0, sizeQueue8*sizeof(kal_uint8));
      ACU_WriteDataDone_ImmediateCallback(hdl, sizeQueue8);
   };
}


static OMX_ERRORTYPE APMCom_Process(AudComHdl *hdl)
{

   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   APM_ComData *pAPMData = (APM_ComData *)ihdl->pPrivateData;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_APM, ihdl->mediaStatus, APM.eofState,0,0,0,0);

   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY)
   {
      return OMX_ErrorNone;
   }

   if(APM.eofState == APM_EOF_DONE  || APM.eofState == APM_EOF_DONE_END) 
   {
      return OMX_ErrorNone;
   }

   if(pAPMData->uPreSilence)
   {
      apmCom_FillSilencToOutputQueue(hdl); 
      pAPMData->uPreSilence = 0;
   }
   
   if(APM.eofState != APM_EOF_TAILING && APM.eofState != APM_EOF_FINISH) 
   {
      // Move data from input queue to internal buffer
      apmCom_MoveDataFromInputQueue(hdl);

      // Process data
      AudioPP_Manager( (void *)hdl );
   }
   
   // Move the processed data from internal buffer to output queue
   apmCom_MoveDataToOutputQueue(hdl);
   
   if (APM.eofState == APM_EOF_TAILING || APM.eofState == APM_EOF_FINISH ) 
   {
      OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader( hdl, 1);
      if (pBufHdr != NULL) 
      {
         APM.eofState = APM_EOF_DONE;
         ihdl->Decode_EOF = KAL_TRUE; 
         ACU_SetEOS(hdl);
         ACU_WriteDataDone_ImmediateCallback(hdl, 0);
      }
   } 
   else if (APM.eofState == APM_EOF_ENDING) 
   {
   	  OMX_BUFFERHEADERTYPE *pBufHdr;
      pBufHdr = ACU_GetBufferHeader( hdl, 1);
      if (pBufHdr != NULL) 
      {
         ACU_WriteDataDone_ImmediateCallback(hdl, 0);
      }
   }
   return OMX_ErrorNone;
}

/*------------------------------------------------*/
/* The public functions of APM component.         */
/*------------------------------------------------*/
OMX_U32 APMCom_GetMemSize( void )
{
   OMX_U32 uTempSize, uReqSizeTotal;

   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;

   // The memory for AAC private data
   uTempSize = (sizeof(APM_ComData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for APM for multiple instance
#if defined(__APM_SUPPORT_MULTIPLE_INSTANCE__)
   uTempSize = (sizeof(apmstruct) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
#endif

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_GETMEMSIZE, MTKAUD_APM, uReqSizeTotal,0,0,0,0,0);
   return uReqSizeTotal;
}

OMX_ERRORTYPE APMCom_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
)
{
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = APMCom_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   // Wrapper of BesSound
   ihdl->pPrivateData = (void *)pBuffer8;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   // Overwrite the member functions
   ihdl->basic.Start = APMCom_Start;
   ihdl->basic.Stop = APMCom_Stop;
   ihdl->basic.Deinit = APMCom_Deinit;
   ihdl->basic.Process = APMCom_Process;
   ihdl->basic.SetParameter = APMCom_SetParameter;

   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_APM, ihdl->mediaStatus,0,0,0,0);

   return OMX_ErrorNone;
}

void APM_HOOK_Sink_Handler(AudComHdl *hdl)
{
   APM.pSinkHandle = hdl;
}

void APM_UNHOOK_Sink_Handler(AudComHdl *hdl)
{
   if(APM.pSinkHandle == hdl)
   {
      APM.pSinkHandle = NULL;
   }
}

#if defined(__BES_TS_SUPPORT__)

void APM_TS_SetParam(void)
{
   AudioDrain_SetTSParam();
}


#else

void APM_TS_SetParam(void)
{

}

#endif

#endif



void AudioPP_DisableBesSound()
{
#if APM_SUPPORT
   kal_int32 taskID;
   kal_uint32 resumeTask_t;
   kal_uint32 i;

   APM.BesSound_disable++;
   if(APM.BesSound_disable>1)
      return;
   resumeTask_t = APM.resumeTask;

   kal_trace(TRACE_GROUP_APM, APM_BS_DISABLE);
   for(i=0; i<APM.taskNum; i++)
   {
      taskID = apmTaskList[i]->apm_Id;
      if( ((1<<taskID)&APM.regTask)&&((1<<taskID)&APM.rwTask ) )
         HOST_APM_UnRegister( (APM_TaskID)taskID );
   }
   APM.resumeTask = resumeTask_t;
#endif
}

void AudioPP_EnableBesSound()
{
#if APM_SUPPORT
   kal_int32 taskID;
   kal_uint32 i;
   if(APM.BesSound_disable>0)
      APM.BesSound_disable--;
   if(APM.BesSound_disable>0)
     return;
   kal_trace(TRACE_GROUP_APM, APM_BS_ENABLE);
   for(i=0; i<APM.taskNum; i++)
   {
      taskID = apmTaskList[i]->apm_Id;
      if( ((1<<taskID)&APM.resumeTask)&& ((1<<taskID)&APM.rwTask ) )
      {
         if(APM.BesSound_disable_in_Video==0)
         {
            HOST_APM_Register( (APM_TaskID)taskID );   
         }
         else if(!AudioPP_IsDisableInVideo((APM_TaskID)taskID))
         {
            HOST_APM_Register( (APM_TaskID)taskID );   
         }
      }
   }
#endif
}

void AudioPP_DisableBesSoundinVideo()
{
#if APM_SUPPORT
   kal_int32 taskID;
   kal_uint32 resumeTask_t;
   kal_uint32 i;

   APM.BesSound_disable_in_Video++;
   if(APM.BesSound_disable_in_Video>1)
      return;
   resumeTask_t = APM.resumeTask;

   kal_trace(TRACE_GROUP_APM, APM_BS_DISABLE_VIDEO);
   for(i=0; i<APM.taskNum; i++)
   {
      taskID = apmTaskList[i]->apm_Id;
      if( ((1<<taskID)&APM.regTask)&&((1<<taskID)&APM.rwTask ) )
      {
         if( AudioPP_IsDisableInVideo((APM_TaskID)taskID) )
         {
            HOST_APM_UnRegister( (APM_TaskID)taskID );
         }
      }
   }
   APM.resumeTask = resumeTask_t;
#endif
}

void AudioPP_EnableBesSoundinVideo()
{
#if APM_SUPPORT
   kal_int32 taskID;
   kal_uint32 i;
   if(APM.BesSound_disable_in_Video>0)
      APM.BesSound_disable_in_Video--;
   if(APM.BesSound_disable_in_Video>0 || APM.BesSound_disable>0)
     return;
   kal_trace(TRACE_GROUP_APM, APM_BS_ENABLE_VIDEO);
   for(i=0; i<APM.taskNum; i++)
   {
      taskID = apmTaskList[i]->apm_Id;
      if( ((1<<taskID)&APM.resumeTask)&& ((1<<taskID)&APM.rwTask ) )
         HOST_APM_Register( (APM_TaskID)taskID );   
   }
#endif
}

void APM_Hook_PcmRut(void)
{
#if APM_SUPPORT
   if (APM.regTask){
   	  mhdlHookPcmRut();
   }
#endif 
}

void APM_SendProcess(void)
{
#if APM_SUPPORT
	 if ( APM.isRunning && APM.phdl) {
      //L1Audio_SetEvent( APM.aud_id, (void *) 0 );
      AudComHdlInt *ihdl = (AudComHdlInt *)APM.phdl;
      ACU_SendProcessCommandl(ihdl);
   }
#endif 
}

void HOST_APM_RequestProcess(void)
{
#if APM_SUPPORT
   L1Audio_SetEvent( APM.aud_id, (void *) 0 );
#endif
}
kal_bool APM_IsRWtaskRuning(void)
{
#if APM_SUPPORT
   if(APM.rwTask & APM.regTask)
   {
      return KAL_TRUE;
   }
   else
#endif
   {
      return KAL_FALSE;
   }
}
