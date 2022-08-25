/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   DraExport.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  The header file of DRA decoder
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**********************************************************************
 * DraExport.h, DRA decoder header file
 **********************************************************************/
/**********************************************************************
 * Copyright (C) 2007, Digital Wave Technology. All rights reversed
 *
 * These software programs are available to the user under NDA. Without
 * the prior writen permission from Digital Rise Technology, neither the
 * whole nor any part of these programs may be disclosed to any third
 * party.
 **********************************************************************/

#ifndef _DRAEXPORT_H_
#define _DRAEXPORT_H_

#ifdef __cplusplus
extern "C" {
#endif


#ifdef DRADECDLL_EXPORTS
#define DRA_API __declspec(dllexport)
#else
#define DRA_API
#endif
/**************************************************************
 *                    Macro Definitions
 **************************************************************/
//Dowmmixing mode
#define DXMODE_UNUSE    0      // Without downmixing
#define DXMODE_10       1      // Multi-channel to 1/0 channel output
#define DXMODE_20       2      // Multi-channel to 2/0 channel output
#define DXMODE_LtRt     3      // Multi-channel to LtRt output
#define DXMODE_321      4      // Multi-channel to 3/2/1 channel output

//Dra decode error message
enum DRADEC_ERRMSG
{
   DRADECSUCCESS,
   DRADECERR,
   DRADECERR_INVALIDBUF,
   DRADECERR_INVALIDSAMPLERATE,
   DRADECERR_INVALIDCHNUM,
   DRADECERR_NOSYNCWORD,
   DRADECERR_INVALIDPOINTER,
   DRADECERR_MEMOVERFLOW,
   DRADECERR_NOTINIT,
   DRADECERR_AUDIOPARAMETERCHANGED,
   DRADECERR_INVALIDSTREAM,
   DRADECERR_LIMIT
};

/**************************************************************
 *                    Type Definitions
 **************************************************************/


/***************************************************************
 * DRA frame information structure, outputed by DRA_DecodeFrame()
 * function after decoding.
****************************************************************/
typedef struct
{
   long nSampleRate;      // Sampling rate
   int  nChannelNormal;   // Number of normal channels
   int  nChannelLfe;      // Number of LFE channel
   long fInstantBitrate;  // Bitrate of this frame
} dra_frame_info;

/**************************************************************
 * DRA initilize structure
 **************************************************************/
typedef struct
{
  int initMode;           // 0: initialize by input channel;  1: initialize by the frist frame
  int channel;            // channel for initialize mode 0
  int byteOrder;          // 0: Windows byte order;  1:network byte order
} dra_cfg;


/**************************************************************
 * Audio information structure
 **************************************************************/
typedef struct
{
   int SampleRate;        // Sampling rate
   int nChannelNormal;    // Number of normal channels
   int nChannelLfe;       // Number of LFE channel
   int JIC;               // Joint intensity code used flag
   int SumDiff;           // sum difference code used flag
} dra_audio_info;


/**********************************************************************
 *                 Interface functions
 **********************************************************************/

/****************************************************
 * DRA_InitDecode: Initialize decoding, must be executed
 * once and only once at the beginnging of a decoder
 * application.
 *
 * Output parameters:
 *    pAudioInfo:
 *       Structure contains information of the
 *       input frame, these information maybe needed
 *       for player applications.Only use in mode 1.
 *
 * Input parameters:
 *    ppvDraDecoder:
 *       Point to the object of DRA decoder.
 *    pDraCfg:
 *       The structure contains setting for initializing.
 *    pInBuf:
 *       Point to the buffer stores one DRA frame data
 *       for Initialize decoder.Only use in mode 1.
 *    nInlength:
 *       Length of input DRA frame data.Only use in mode 1.
 *
 * Return Values:
 *    If  decoder Initialize  successfully,the return value is zero,
 *    or else,it means fails.

 *******************************************************/
 /****************************************************/
DRA_API int DRA_InitDecode(
   void           **ppvDraDecoder,
   dra_cfg        *pDraCfg,
   unsigned char  *pDraFrameBuf,
   int            nLength,
   dra_audio_info *pAudioInfo
);


/****************************************************
 * DRA_Release: Realse decoder resoure,must be called
 *
 * Input parameters:
 *    ppvDraDecoder:
 *       Point to  the object of DRA decoder.
 *
 * Return Values:
 *    If  decoder realse  successfully,the return value is zero,
 *    or else,it means fails.
 ****************************************************/
DRA_API int DRA_Release(void **ppvDraDecoder);

/****************************************************
 * DRA_DecodeFrame: Decode one and only one DRA frame, must
 * be called for each frame.
 *
 * Output parameters:
 *    pOutBuf:
 *       Buffer stores PCM data after decoding arranged
 *       in the Microsoft WAVEFORMATEXTENSIBLE style,
 *       he size of this buffer must >=  1024 * number
 *       of channels * 2 bytes (or 3bytes)  , for a DRA
 *       frame contains 1024 samples, and the output
 *       PCM samples are 16-bits(2 bytes) formatted,
 *       or 24-bits(3bytes)formatted.
 *    pOutLength:
 *       Length of output PCM data.
 *    pFrameInfo:
 *       Structure contains information of the
 *       current frame, these information maybe needed
 *       for player applications.
 *
 * Input parameters:
 *    ppvDraDecoder:
 *       The object of DRA decoder.
 *    pInBuf:
 *       Point to the buffer stores one DRA frame data
 *       begin with a DRA sync_word.
 *    nInlength:
 *       Length of input DRA frame data.
 *    DownMixMode:
 *       Down mix mode setting,
 *       0: disable; 1: 1.0; 2: 2.0; 3: Lt/Rt
 *    nBitPcm:
 *       PCM precision setting, only 16bit or 24bit valid.
 *
 * Return Values:
 *    If  DRA frame decode  successfully,the return value is zero,
 *    or else,it means decode fails.
 *******************************************************/
DRA_API int DRA_DecodeFrame(
   void           *ppvDraDecoder,
   unsigned char  *pInBuf,
   long           nInlength,
   unsigned char  *pOutBuf,
   long           *pOutLength,
   int            DownMixMode,
   int            nBitPcm,
   dra_frame_info *pFrameInfo
);


DRA_API int DRA_GetMemSize(
   int Channel,
   int DownMixMode
);



#ifdef __cplusplus
}
#endif

#endif
