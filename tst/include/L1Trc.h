/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * L1Trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the variable declaraed and macr defined for layer 1 
 *		trace functionality.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(L1_CATCHER) && !defined(L1_SIM)

#ifndef TRACE_DEF_H
#define TRACE_DEF_H
 
#include "kal_general_types.h"

/********************/
/* Constant definition */
/********************/
#define	ISR_FRAME_MAGIC	0xA5
#define	ISR_FRAME_LMU_MAGIC	0xA6  //0xA6 Len(2) Checksum(1)
#define ISR_SKIP_MAGIC 0xFA //This char will be ignored by Catcher

#if defined(__UMTS_RAT__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GEMINI_GSM__
/* under construction !*/
#endif  //#ifdef __GEMINI_GSM__
/* under construction !*/
#ifdef __GEMINI_WCDMA__
/* under construction !*/
#endif  //#ifdef __GEMINI_WCDMA__
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
#ifdef TRC_C
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(MT6268T) || defined(MT6268H)
/* under construction !*/
#else	//#ifdef MT6268T
/* under construction !*/
#endif	//#ifdef MT6268T
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
#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)
/* under construction !*/
/* under construction !*/
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)
/* under construction !*/
/* under construction !*/
#if !defined(__SMART_PHONE_MODEM__) && defined(__AST_L1_LOGGING_IN_LISR__)
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
#endif
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
#if !defined(__SMART_PHONE_MODEM__) && defined(__AST_L1_LOGGING_IN_LISR__)
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else //#if defined(__UMTS_RAT__)
//for 2G L1

/*************************************/
/* Definition used in generated code */
/*************************************/
typedef void (*trc_setfilterfunc)(unsigned char *);
#define TRC_FILTER_FUNC_ARRAY		trc_filterfuncarray
#define TRC_NBR_MODULE				trc_filterfuncnbr
#define TRC_TASK_BUFFER				trc_taskbuf
#define TRC_TASK_BUFFER_PTR			trc_taskbufptr
#define TRC_ISR_BUFFER				trc_isrbuf
#define TRC_ISR_BUFFER_PTR			trc_isrbufptr
#define TRC_SET_FILTER_FUNC			trc_setfilterfunc	

#define TRC_START_FILL_TASK(NoBytes) \
    unsigned int TRC_LOCAL = trc_taskbufptr; \
    if (TRC_LOCAL + NoBytes > L1TRC_TASK_BUFFER_SIZE){ trc_taskLostTraces += 1; return; }\
    trc_taskbufok=0
    
#define TRC_END_FILL_TASK			trc_taskbufptr = TRC_LOCAL; trc_taskbufok=1
#define TRC_START_FILL_ISR(NoBytes) \
    unsigned int TRC_LOCAL = trc_isrbufptr; \
    if (TRC_LOCAL + NoBytes > L1TRC_ISR_BUFFER_SIZE) {trc_isrLostTraces += 1; return; } do{}while(0)
    
#define TRC_END_FILL_ISR   		trc_isrbufptr = TRC_LOCAL 

//LMU compatible definitions
#define TRC_END_FILL_TASK_0w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_1w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_2w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_3w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_4w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_5w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_6w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_7w TRC_END_FILL_TASK

#define TRC_END_FILL_ISR_0w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_1w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_2w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_3w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_4w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_5w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_6w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_7w TRC_END_FILL_ISR

/*******************/
/* Variable        */
/*******************/
#ifdef TRC_C
	#define TRC_EXT 
#else
	#define TRC_EXT extern
#endif

#if defined(__EGPRS_MODE__) || defined(L1D_TEST) || defined(__SAIC__)
#define L1TRC_TASK_BUFFER_SIZE 256
#define L1TRC_ISR_BUFFER_SIZE 256
#else
#define L1TRC_TASK_BUFFER_SIZE 128
#define L1TRC_ISR_BUFFER_SIZE 128
#endif

/* Record las framenumber and sbits */
#ifndef __GEMINI__
  #define L1_FN_RECORD_SIZ (1)
  #define TRC_FN_ARY_SIZE (36)
#else //#ifndef __GEMINI__
  #define L1_FN_RECORD_SIZ (GEMINI_PLUS)
  #define TRC_FN_ARY_SIZE (36+(GEMINI_PLUS-2)*16)
#endif  //#ifndef __GEMINI__

TRC_EXT kal_uint32	trc_lastframe[L1_FN_RECORD_SIZ];
TRC_EXT kal_uint16	trc_lastsbit[L1_FN_RECORD_SIZ];
TRC_EXT kal_uint32	trc_lastTimeStamp;

/* Record the time when mobile station handover */
TRC_EXT kal_uint32 	trc_handovertime;
TRC_EXT kal_uint32 	trc_handoverFramenumber;
/* Task level buffer */
TRC_EXT kal_uint8	trc_taskbuf[L1TRC_TASK_BUFFER_SIZE];
/* Pointer of task level buffer */
TRC_EXT kal_uint8	trc_taskbufptr;
/* Indicate if a complete task level message is filled */
TRC_EXT kal_uint8	trc_taskbufok;
/* Indicate number of lost task traces */
TRC_EXT kal_uint8	trc_taskLostTraces;
/* Isr level buffer */
TRC_EXT kal_uint8	trc_isrbuf[L1TRC_ISR_BUFFER_SIZE];
/* Pointer of isr level buffer */
TRC_EXT kal_uint8	trc_isrbufptr;
/* Indicate number of lost isr traces */
TRC_EXT kal_uint8	trc_isrLostTraces;
/* Buffer that contains framenumber and time */
TRC_EXT kal_uint8	trc_framenumber[TRC_FN_ARY_SIZE];
/* Pointer of framenumber buffer */
TRC_EXT kal_uint8	trc_framenumberptr;
/* Check sum */
TRC_EXT kal_uint8	trc_checksum;

#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)
TRC_EXT kal_uint32  trc_lga_start;
TRC_EXT kal_uint32  trc_lga_end;
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)

/************/
/*Functions */
/************/
void Trc_Init(void);
void trc_trigger_multiple(kal_uint32 framenumber[], kal_uint16 ebit[], kal_uint32 sim_number, kal_uint32 timestamp);

void trc_handover(kal_uint32 handovertime, kal_uint32 framenumber);
void trc_setfilter(kal_uint8 *setting, kal_uint32 len);
kal_int32 trc_getfilter(kal_uint8 *buffer, kal_int32 len);

/*******************************/
/* Macro for retrieving values */
/*******************************/
/* TRC_MAKE_CHAR */
#define TRC_MAKE_CHAR(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_BYTE */
#define TRC_MAKE_BYTE(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_UBYTE */
#define TRC_MAKE_UBYTE(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_SHORT */
#define TRC_MAKE_SHORT(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>8) & 0xFF; \
			*(buffer+offset+1) = value & 0xFF; \
			offset += 2;\
		} while(0)
		
/* TRC_MAKE_USHORT */
#define TRC_MAKE_USHORT(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>8) & 0xFF; \
			*(buffer+offset+1) = value & 0xFF; \
			offset += 2;\
		} while(0)
		
/* TRC_MAKE_LONG */
#define TRC_MAKE_LONG(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>24) & 0xFF; \
			*(buffer+offset+1) = ((value)>>16) & 0xFF; \
			*(buffer+offset+2) = ((value)>>8 ) & 0xFF; \
			*(buffer+offset+3) = ((value)) & 0xFF; \
			offset += 4;\
		} while(0)
		
/* TRC_MAKE_ULONG */
#define TRC_MAKE_ULONG(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>24) & 0xFF; \
			*(buffer+offset+1) = ((value)>>16) & 0xFF; \
			*(buffer+offset+2) = ((value)>>8 ) & 0xFF; \
			*(buffer+offset+3) = ((value)) & 0xFF; \
			offset += 4;\
		} while(0)
		
/* TRC_MAKE_FN */
#define TRC_MAKE_FN(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>16) & 0xFF; \
			*(buffer+offset+1) = ((value)>>8) & 0xFF; \
			*(buffer+offset+2) = ((value) ) & 0xFF; \
			offset += 3;\
		} while(0)

#endif /* MTK 2G or 3G L1 */

//For LMU related macros compatible
#define TRC_MAKE_CHAR_0c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_1c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_2c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_3c TRC_MAKE_CHAR

#define TRC_MAKE_SHORT_0c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_1c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_2c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_3c TRC_MAKE_SHORT

#define TRC_MAKE_FN_0c TRC_MAKE_FN
#define TRC_MAKE_FN_1c TRC_MAKE_FN
#define TRC_MAKE_FN_2c TRC_MAKE_FN
#define TRC_MAKE_FN_3c TRC_MAKE_FN

#define TRC_MAKE_LONG_0c TRC_MAKE_LONG
#define TRC_MAKE_LONG_1c TRC_MAKE_LONG
#define TRC_MAKE_LONG_2c TRC_MAKE_LONG
#define TRC_MAKE_LONG_3c TRC_MAKE_LONG

#define TRC_PAD_CHAR(...)
#define TRC_PAD_SHORT(...)
#define TRC_PAD_FN(...)

#define TRC_ISR_BUFFER_FULL(...)
#define TRC_TASK_BUFFER_FULL(...)

//For LMU logging
#ifdef __TST_LMU_LOGGING__
  #include "L1Trc_lmu.h"
#endif  //#ifdef __TST_LMU_LOGGING__

#endif /* TRACE_DEF_H */

#elif defined(L1_SIM) /* #if defined(L1_CATCHER) && !defined(L1_SIM) */
//For L1 Sime evironment
#ifndef __L1TRC_L1SIM_H__
#define __L1TRC_L1SIM_H__

#include "kal_release.h"

#if defined(__UMTS_RAT__)
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
/* under construction !*/
/* under construction !*/
#ifdef __GEMINI_GSM__
/* under construction !*/
#endif  //#ifdef __GEMINI_GSM__
/* under construction !*/
#ifdef __GEMINI_WCDMA__
/* under construction !*/
#endif  //#ifdef __GEMINI_WCDMA__
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
/* under construction !*/
/* under construction !*/
#else //#if defined(__UMTS_RAT__)
//for 2G L1

/*************************************/
/* Definition used in generated code */
/*************************************/
typedef void (*trc_setfilterfunc)(unsigned char *);

#define TRC_SET_FILTER_FUNC			trc_setfilterfunc	
extern TRC_SET_FILTER_FUNC TRC_FILTER_FUNC_ARRAY[];
extern unsigned short TRC_NBR_MODULE;
#define TRC_TASK_BUFFER				trc_taskbuf
#define TRC_TASK_BUFFER_PTR			trc_taskbufptr
#define TRC_ISR_BUFFER				trc_isrbuf
#define TRC_ISR_BUFFER_PTR			trc_isrbufptr
#define TRC_SET_FILTER_FUNC			trc_setfilterfunc	

#define TRC_START_FILL_TASK(NoBytes) \
    unsigned int TRC_LOCAL = trc_taskbufptr; \
    if (TRC_LOCAL + NoBytes > L1TRC_TASK_BUFFER_SIZE){ trc_taskLostTraces += 1; return; }\
    trc_taskbufok=0
    
#define TRC_END_FILL_TASK			trc_taskbufptr = TRC_LOCAL; trc_taskbufok=1
#define TRC_START_FILL_ISR(NoBytes) \
    unsigned int TRC_LOCAL = trc_isrbufptr; \
    if (TRC_LOCAL + NoBytes > L1TRC_ISR_BUFFER_SIZE) {trc_isrLostTraces += 1; return; } do{}while(0)
    
#define TRC_END_FILL_ISR   		trc_isrbufptr = TRC_LOCAL 

//LMU compatible definitions
#define TRC_END_FILL_TASK_0w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_1w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_2w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_3w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_4w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_5w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_6w TRC_END_FILL_TASK
#define TRC_END_FILL_TASK_7w TRC_END_FILL_TASK

#define TRC_END_FILL_ISR_0w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_1w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_2w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_3w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_4w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_5w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_6w TRC_END_FILL_ISR
#define TRC_END_FILL_ISR_7w TRC_END_FILL_ISR

/*******************/
/* Variable        */
/*******************/
#ifdef TRC_C
	#define TRC_EXT 
#else
	#define TRC_EXT extern
#endif

//For L1Sim 2G
#define L1TRC_TASK_BUFFER_SIZE 4096
#define L1TRC_ISR_BUFFER_SIZE 4096
#define L1TRC_TIME_INFO_BUFFER_SIZE 128

//SE2_CS2 ChuYan's request
#ifndef GEMINI_PLUS
  #define GEMINI_PLUS 4
#endif  //GEMINI_PLUS

/* Record las framenumber and sbits */
#ifndef __GEMINI__
  #define L1_FN_RECORD_SIZ (1)
  #define TRC_FN_ARY_SIZE (36)
#else //#ifndef __GEMINI__
  #define L1_FN_RECORD_SIZ (GEMINI_PLUS)
  #define TRC_FN_ARY_SIZE (36+(GEMINI_PLUS-2)*16)
#endif  //#ifndef __GEMINI__

TRC_EXT kal_uint32	trc_lastframe[L1_FN_RECORD_SIZ];
TRC_EXT kal_uint16	trc_lastsbit[L1_FN_RECORD_SIZ];
TRC_EXT kal_uint32	trc_lastTimeStamp;

/* Record the time when mobile station handover */
TRC_EXT kal_uint32 	trc_handovertime;
TRC_EXT kal_uint32 	trc_handoverFramenumber;
/* Task level buffer */
TRC_EXT kal_uint8	trc_taskbuf[L1TRC_TASK_BUFFER_SIZE];
/* Pointer of task level buffer */
TRC_EXT kal_uint32	trc_taskbufptr;
/* Indicate if a complete task level message is filled */
TRC_EXT kal_uint8	trc_taskbufok;
/* Indicate number of lost task traces */
TRC_EXT kal_uint8	trc_taskLostTraces;
/* Isr level buffer */
TRC_EXT kal_uint8	trc_isrbuf[L1TRC_ISR_BUFFER_SIZE];
/* Pointer of isr level buffer */
TRC_EXT kal_uint32 trc_isrbufptr;
/* Indicate number of lost isr traces */
TRC_EXT kal_uint8	trc_isrLostTraces;
/* Buffer that contains framenumber and time */
TRC_EXT kal_uint8	trc_framenumber[TRC_FN_ARY_SIZE];
/* Pointer of framenumber buffer */
TRC_EXT kal_uint8	trc_framenumberptr;
/* Check sum */
TRC_EXT kal_uint8	trc_checksum;

//allocate a buffer for time information
TRC_EXT kal_uint8	trc_timeinfobuf[L1TRC_TIME_INFO_BUFFER_SIZE];
TRC_EXT kal_uint8	trc_timeinfobufptr;

/************/
/*Functions */
/************/
void Trc_Init(void);
void trc_trigger_multiple(kal_uint32 framenumber[], kal_uint16 ebit[], kal_uint32 sim_number, kal_uint32 timestamp);
void trc_handover(kal_uint32 handovertime, kal_uint32 framenumber);

/*******************************/
/* Macro for retrieving values */
/*******************************/
/* TRC_MAKE_CHAR */
#define TRC_MAKE_CHAR(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_BYTE */
#define TRC_MAKE_BYTE(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_UBYTE */
#define TRC_MAKE_UBYTE(buffer, offset, value) \
		do { \
			*(buffer+offset) = value; \
			offset += 1;\
		} while(0)

/* TRC_MAKE_SHORT */
#define TRC_MAKE_SHORT(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>8) & 0xFF; \
			*(buffer+offset+1) = value & 0xFF; \
			offset += 2;\
		} while(0)
		
/* TRC_MAKE_USHORT */
#define TRC_MAKE_USHORT(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>8) & 0xFF; \
			*(buffer+offset+1) = value & 0xFF; \
			offset += 2;\
		} while(0)
		
/* TRC_MAKE_LONG */
#define TRC_MAKE_LONG(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>24) & 0xFF; \
			*(buffer+offset+1) = ((value)>>16) & 0xFF; \
			*(buffer+offset+2) = ((value)>>8 ) & 0xFF; \
			*(buffer+offset+3) = ((value)) & 0xFF; \
			offset += 4;\
		} while(0)
		
/* TRC_MAKE_ULONG */
#define TRC_MAKE_ULONG(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>24) & 0xFF; \
			*(buffer+offset+1) = ((value)>>16) & 0xFF; \
			*(buffer+offset+2) = ((value)>>8 ) & 0xFF; \
			*(buffer+offset+3) = ((value)) & 0xFF; \
			offset += 4;\
		} while(0)
		
/* TRC_MAKE_FN */
#define TRC_MAKE_FN(buffer, offset, value) \
		do { \
			*(buffer+offset) = ((value)>>16) & 0xFF; \
			*(buffer+offset+1) = ((value)>>8) & 0xFF; \
			*(buffer+offset+2) = ((value) ) & 0xFF; \
			offset += 3;\
		} while(0)

#endif  //#if defined(__UMTS_RAT__) 

//For LMU related macros compatible
#define TRC_MAKE_CHAR_0c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_1c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_2c TRC_MAKE_CHAR
#define TRC_MAKE_CHAR_3c TRC_MAKE_CHAR

#define TRC_MAKE_SHORT_0c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_1c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_2c TRC_MAKE_SHORT
#define TRC_MAKE_SHORT_3c TRC_MAKE_SHORT

#define TRC_MAKE_FN_0c TRC_MAKE_FN
#define TRC_MAKE_FN_1c TRC_MAKE_FN
#define TRC_MAKE_FN_2c TRC_MAKE_FN
#define TRC_MAKE_FN_3c TRC_MAKE_FN

#define TRC_MAKE_LONG_0c TRC_MAKE_LONG
#define TRC_MAKE_LONG_1c TRC_MAKE_LONG
#define TRC_MAKE_LONG_2c TRC_MAKE_LONG
#define TRC_MAKE_LONG_3c TRC_MAKE_LONG  

#define TRC_ISR_BUFFER_FULL
#define TRC_TASK_BUFFER_FULL

#endif  //__L1TRC_L1SIM_H__

#endif /* #if defined(L1_CATCHER) && !defined(L1_SIM) */
