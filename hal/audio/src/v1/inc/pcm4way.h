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
 * pcm4way.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __PCM4WAY_H
#define __PCM4WAY_H
#include "common_def.h"

typedef struct{
#if DSP_DATA_CARD_INTERFACE_SUPPORT
    void (*dl_hdlr)(void);
    void (*ul_hdlr)(void);
#endif	
    kal_uint16 aud_id;
    void (*hdlr)(void);
    kal_uint32 state;       // Identify P2W or P4W
    kal_uint32 bandInfo;    // Record the band information, please refer to PCMNWAY_BAND_INFO
    kal_uint32 am_type;
    kal_uint32 app_type;    // Applicatoin type
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    kal_bool UL_M2D_on;
	kal_bool UL_D2M_on;
	kal_bool UL_is_after_enh;
	kal_bool DL_M2D_on;
	kal_bool DL_D2M_on;
	kal_bool DL_is_after_enh;
	kal_bool b_wait_ul_dl;
    kal_uint32 hisr_state;  // 0: None
                            // 1: Receive UL interrupt
                            // 2: Receive DL interrupt
                            // 3: Receive UL interrupt first, then receive DL interrupt
                            // 4: Receive DL interrupt first, then receive UL interrupt
#else   // chip compile option
    kal_uint32 FSM[2];      // [0]->StateOn, set by MCU; [1]:StateReadyBit, change by DSP from StateOn      
#endif  // chip compile option
    kal_uint32 u4DspPcmExMicLen;
    kal_uint32 u4DspPcmExSpkLen;
} PCM_Ex_Config;

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define DACA_IN_PHONE_CALL 0x0001     
#define DACA_USE_NB        0x0002
#define DACA_USE_UL        0x0004
#define DACA_USE_DL        0x0008
#define DACA_UNDEFINED     0x8000

typedef enum {
  DACA_APP_TYPE_IDLE_UL_DL_NB        = DACA_USE_NB + DACA_USE_UL + DACA_USE_DL, 
  DACA_APP_TYPE_IDLE_UL_NB           = DACA_USE_NB + DACA_USE_UL, 
  DACA_APP_TYPE_IDLE_DL_NB           = DACA_USE_NB + DACA_USE_DL, 
  DACA_APP_TYPE_ACTIVE_UL_DL_NB      = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_UL + DACA_USE_DL, 
  DACA_APP_TYPE_ACTIVE_UL_NB         = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_UL, 
  DACA_APP_TYPE_ACTIVE_DL_NB         = DACA_IN_PHONE_CALL + DACA_USE_NB + DACA_USE_DL, 
  DACA_APP_TYPE_UNDEFINE             = DACA_UNDEFINED
}DACA_APP_TYPE;
#else // chip compile option
typedef enum {
  DACA_APP_TYPE_IDLE_UL_DL_NB = 0, //p2w acts as I/O to get/put pcm data under idle
  DACA_APP_TYPE_IDLE_UL_NB,        //p2w acts as I/O to get/put pcm data under idle
  DACA_APP_TYPE_IDLE_DL_NB,        //p2w acts as I/O to get/put pcm data under idle
  DACA_APP_TYPE_ACTIVE_UL_DL_NB,   //p2w acts as I/O to get/put pcm data under phone call/record
  DACA_APP_TYPE_ACTIVE_UL_NB,      //p2w acts as I/O to get/put pcm data under phone call/record
  DACA_APP_TYPE_ACTIVE_DL_NB,      //p2w acts as I/O to get/put pcm data under phone call/record  
  DACA_APP_TYPE_UNDEFINE     = 0xFFFF
}DACA_APP_TYPE;
#endif // chip compile option

typedef enum {
    P4W_APP_CTM = 0,
    P4W_APP_TYPE_UNDER_CALL, //p2w acts as I/O to get/put pcm data under idle
    P4W_APP_TYPE_WITHOUT_CALL,
    P4W_APP_TYPE_UNDEFINE = 0xFFFF
} P4W_APP_TYPE;

typedef enum {
    MCU_SET_P4W_OFF   = 0,  
    MCU_SET_P4W_ON    = 1,  
    DSP_SET_P4W_READY = 2
} P4W_CTRL_STATUS;

typedef enum {
    MCU_SET_P2W_OFF   = 0<<4,  
    MCU_SET_P2W_ON    = 1<<4,  
    DSP_SET_P2W_READY = 2<<4
} P2W_CTRL_STATUS;

void PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type);   
void PCM4WAY_Stop(uint32 type);           

void PCM4WAY_GetFromMic(uint16 *ul_buf);
void PCM4WAY_PutToSE(const uint16 *ul_data); 
void PCM4WAY_FillSE(uint16 value); 

void PCM4WAY_GetFromSD(uint16 *dl_buf);
void PCM4WAY_PutToSpk(const uint16 *dl_data); 
void PCM4WAY_FillSpk(uint16 value);

void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type);
void PCM2WAY_Stop(uint32 type);

void PCM2WAY_GetFromMic(uint16 *ul_buf);
void PCM2WAY_PutToSpk(const uint16 *dl_data);
void PCM2WAY_FillSpk(uint16 value);

void PCM2WAY_SetBufSize(uint32 size);
uint32 PCM2Way_GetFormat(void);

extern void PcmSink_TerminateSound(void);

void Extended_PCM2WAY_Start(void (*pcm2way_dl_hdlr)(void), void (*pcm2way_ul_hdlr)(void), uint32 type, uint32 cfgDL, uint32 cfgUL);
void Extended_PCM2WAY_Stop(uint32 type);

#endif 
