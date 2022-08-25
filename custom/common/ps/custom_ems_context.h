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
 * custom_ems_context.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the EMS maximum segment number.
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
 *==============================================================================
 *******************************************************************************/

#ifndef _CUSTOM_EMS_CONTEXT_H
#define _CUSTOM_EMS_CONTEXT_H

/*========================================================================
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *
 *  Please DO NOT modify below setting.
 *
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *======================================================================= */

#include "ems.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

#if defined(PLUTO_MMI)

#define EMS_MAX_EMS_DATA (3)

#else

#if defined(__EMS_NON_STD_7BIT_CHAR__) || defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__)
#define EMS_MAX_EMS_DATA (3)
#else
#define EMS_MAX_EMS_DATA (2)
#endif

#endif

#if ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))

typedef kal_uint16 (*EMS_CONCAT_MSG_REF_FUNCTION)(void);
typedef kal_uint16 (*EMS_CONVERT_NON_STD_CHARS_CALLBACK)(kal_uint8, kal_uint8);
typedef kal_uint16 (*EMS_CONVERT_NL_TO_UCS2_CALLBACK)(EMSNationalLanguage lang,
                                                      kal_uint8  *input,
                                                      kal_uint8  *output,
                                                      kal_uint16 len,
                                                      kal_uint8  SegNum);

typedef kal_uint16 (*EMS_CONVERT_UCS2_TO_NL_CALLBACK)(EMSNationalLanguage lang,
                                                      kal_uint8  *input,
                                                      kal_uint8  *output,
                                                      kal_uint16 len,
                                                      kal_uint8  SegNum);

/*The following two pointer is for EMS Compression to alloc/free the temporary buffer.
So if the caller of EMSLib, in return the caller should supply EMS method to get temporary buffer */
typedef void *(*EMS_COMPRESS_MEM_ALLOC)(kal_uint32 mem_size);
typedef void (*EMS_COMPRESS_MEM_FREE)(void *mem_ptr);


/* Following are used for the IE which may cross segment,  */
/* i.e. Compression or Extended Object.                      */

/* For MT case: */
/* If it occurs missed segment condition, all pending variables  */
/* and buffer will be freed. The IE will be ignored.            */

/* For MO case: */
/* The buffer is used as temp buffer of extended object before compression or packed. */

#ifndef __ULC_SLIM_EMS__     

typedef struct
{
   kal_bool    BufType;   /* Is there pending IE existed.  */
   kal_uint16  BufLen;    /* MT: IE(buffer) length. Get from IE information. */
                          /* MO: total extend IE length in buffer */
   kal_uint16  BufOffset; /* MT: existed data length in buffer */
                          /* MO: data length already packed */

   kal_uint8   *BufPtr;   /* Buffer for IE data */
}EMSPendingBuff;

typedef struct 
{
   kal_uint32      footer;
}EMSPduBuffFooter;     


typedef struct EMSPduBuffMB_struct
{
   struct EMSPduBuffMB_struct  *next;
   EMSObject                   *obj;
   kal_uint16                  buff_size;
   kal_uint8                   ref_count;
   kal_uint8                   padding;
}EMSPduBuffMB;     


typedef struct
{
   kal_uint16            pool_size;   /* pool size */
   kal_uint8            *pool_ptr;    /* start of pool */

   kal_uint8            *end_ptr;     /* end ptr of block buffer */
   kal_uint8            *free_ptr;    /* start ptr of free buffer */

   struct EMSPduBuffMB_struct  *head;        /* head of used buffer */
   struct EMSPduBuffMB_struct  *tail;        /* tail of used buffer */

}EMSPduMemPool;   

#endif

typedef struct
{
#ifndef __ULC_SLIM_EMS__  	
   /* used when packing EMS data into TP-UD(s)  */
   kal_uint16  totalTxtFmtOctet;  /* total text fmt object octet number */
   kal_uint16  totalObjOctet;     /* total object octet number, exclude extended object */
   kal_uint16  totalExtObjOctet;  /* total Extended Object octet number */
   kal_uint8   numOfEMSObject;
   kal_uint8   numOfExtObject;
#endif
   kal_uint8   MaxLenPerSeg;/* 160 if dcs is GSM7-bit; 
						           * 140 otherwise */   
   kal_uint8   MaxUsableLen;/* exclude concatenated ie */
   kal_uint8   ConcatHdrLen;

   kal_uint8   CurrentConcatMsgRef; 
	
   kal_uint16  baseTextOffset;
   kal_uint16  textOffset;   	
   kal_uint8   numSegment;
   kal_uint8   SetEditSegment;

#ifndef __ULC_SLIM_EMS__  
   kal_uint8   NumFinishedObject;
   kal_bool    notFinishedObjectNeedProcessed;
   void        *notFinishedObject;
#endif

   kal_uint8   **TPUD;
   kal_uint8   *TPUDLen; 
   kal_uint8   *UDHL;

#ifdef __EMS_REL5__
   kal_uint16  CompressIELen;   /* The Compress IE length, include 3 byte header info. */
   kal_bool    needReCompress;  /* Is there pending IE existed.  */
   kal_bool    forceCompress;   /* force to compress.  */

   /* used when unpacking EMS data from TP_UD */
   kal_uint8   UnpackSegNum;    /* Buffer for IE data */
   kal_bool    MissSegInCrossIE;/* does missing segment occur in cross segment IE.  */

   kal_uint8   ObjDistIndCount;
   kal_uint8   ExtObjRefNum;

   kal_bool    isObjSwitched; 
   kal_uint8   RefNumOfSwitchObj;

   EMSPendingBuff PBuff;
#endif

   kal_uint8   error; /* ref to EMSTATUS */
   
} EMSInternalData;

typedef struct
{
   EMSInternalData   internalData[EMS_MAX_EMS_DATA]; /* internal Data */

#ifndef __ULC_SLIM_EMS__  
   EMSPduMemPool     pdu_mem_pool[EMS_MAX_EMS_DATA];
   kal_bool          pdu_mem_footer;       
#endif
      
   kal_bool          isInit;         /* initialize or not */   
#ifndef __ULC_SLIM_EMS__     
   kal_bool          isCompressSupp; /* Support Compress or not */      
#endif      
   kal_uint8         activeEMSDataID; /* store active EMS Data id */
   kal_bool          isEMSDataUsed[EMS_MAX_EMS_DATA]; /* record which EMS Data is used */
   kal_uint8         max_seg_num;
   kal_uint8         max_ems_data;
   kal_uint16        concat_msg_ref;
#ifndef __ULC_SLIM_EMS__  
   kal_uint16        max_obj_num;
#endif 
   kal_uint8         *textBuffer[EMS_MAX_EMS_DATA]; /* text buffer */
   kal_uint8         *oridcs[EMS_MAX_EMS_DATA]; /* oridcs buffer */  
#ifndef __ULC_SLIM_EMS__  
   void              *mem_pool_buff[EMS_MAX_EMS_DATA]; 
#endif
   EMS_CONCAT_MSG_REF_FUNCTION concat_msg_ref_func;
   EMS_CONVERT_NON_STD_CHARS_CALLBACK non_std_char_callback;

   EMS_CONVERT_NL_TO_UCS2_CALLBACK convert_NL_to_UCS2;
   EMS_CONVERT_UCS2_TO_NL_CALLBACK convert_UCS2_to_NL;

#ifdef __EMS_REL5__
   EMS_COMPRESS_MEM_ALLOC ems_mem_alloc;
   EMS_COMPRESS_MEM_FREE  ems_mem_free;
#endif

#ifndef __ULC_SLIM_EMS__  
#ifndef EMS_ON_WIN32
   KAL_ADM_ID        EMSPoolID[EMS_MAX_EMS_DATA];
#endif
#endif

} EMSContext;


extern EMSContext ems_cntx_g;


/* =========================================== */
extern kal_bool  ems_is_support_non_std_char(void);
extern kal_uint8 ems_max_ems_data(void);
extern kal_uint8 ems_max_seg_num(void);
extern kal_uint16 ems_obj_buff_size_per_seg(void);
extern kal_uint8 *ems_get_miss_seg_str(kal_uint16 *str_len);


extern kal_uint8 *ems_get_text_buff_ptr(kal_uint8 ems_id);
extern kal_uint8 *ems_get_oridcs_buff_ptr(kal_uint8 ems_id);
extern kal_uint8 *ems_get_TPUDLen_ptr(kal_uint8 ems_id);
extern kal_uint8 *ems_get_UDHL_ptr(kal_uint8 ems_id);

/* EMS buffer pool                                            */
/* !! VERY IMPORTANT:  user pointer shall 4-byte alignment !! */
#ifndef __SLIM_EMS__
#ifdef __EMS_REL5__
extern void *ems_get_pdu_mem_pool_info(kal_uint8 ems_id, kal_uint16 *size);
#endif 
extern void *ems_get_mem_pool_ptr(kal_uint8 ems_id);
#endif /* __SLIM_EMS__ */ 

#endif /* ( !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 

#endif /* _CUSTOM_EMS_CONTEXT_H */ 

