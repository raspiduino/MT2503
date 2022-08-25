/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   PostProcess.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of post-processing.
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

#ifndef POST_PROCESS_DOT_H
#define POST_PROCESS_DOT_H

#include "bessound_exp.h"

#include "l1audio.h"
#include "OMX_Types.h"
#include "OMX_Core.h"
#include "AudCom.h"

#define BES_MIN_PROCESS_LEN 1152 //word // fixed for ts

#define BES_TS_BUFNUM                 1
#define BES_TS_BUFSIZE                BES_MIN_PROCESS_LEN*2

#define APM_OUT_BUFNUM_MIXER          3
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define APM_OUT_BUFNUM                6
#define LOW_POWER_PCM_SINK_THRESHOLD  12*1024
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)   
#define APM_OUT_BUFNUM                10
#define LOW_POWER_PCM_SINK_THRESHOLD  20*1024
#else
#define APM_OUT_BUFNUM                13
#define LOW_POWER_PCM_SINK_THRESHOLD  24*1024
#endif
#define APM_OUT_BUFSIZE               2048

#define PCMROUTE_BUFNUM               2
#define PCMROUTE_BUFSIZE              8192

#define MIXEROUT_OUTPUT_BUFFER_NUMBER 3
#define MIXEROUT_OUTPUT_BUFFER_SIZE   2304

/*------------------------------------------------*/
/* Structure of BesSound effect.                  */
/*------------------------------------------------*/
typedef struct {
   APM_TaskID ppType;
   int (*SetHandle)(BS_Handle *pHandle);
   kal_uint32 (*GetInitParamSize)(void);
   kal_uint32 (*GetDataSize)(void);
} Bes_WrapFunc;

typedef struct {
   Bes_WrapFunc *pFunc;
   
   BS_Handle iBesHdl;
   kal_uint8 fIntBuf;
   kal_uint8 fTempBuf;
   char *pIntBuf;
   kal_uint32 uIntBufSize;
   char *pTempBuf;
   kal_uint32 uTempBufSize;

   void *pInitParam;
   void *pBesPrivate;
   
   kal_int16 TempInBuf[BES_MIN_PROCESS_LEN];
   kal_int16 TempOutBuf[BES_MIN_PROCESS_LEN];
   kal_uint32 uInRead;
   kal_uint32 uInWrite;
   kal_uint32 uOutSize;
   kal_uint32 uAccInputSample;
   kal_uint32 uAccOutputSample;
} Bes_CtrlData;


/*------------------------------------------------*/
/* Common function for BesSound effect.           */
/*------------------------------------------------*/
OMX_U32 BesSound_GetMemSize( Bes_WrapFunc *pFunc);
OMX_ERRORTYPE BesSound_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback,
   Bes_WrapFunc   *pFunc
);


#endif
