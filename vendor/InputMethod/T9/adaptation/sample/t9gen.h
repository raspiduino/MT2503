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
 *    T9Engine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 * Adaptation layer for T9 Core for Alphabetic & Phonetic ambiguous & multitap inputs
 * for T9 Version 7 and 7.4
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#define PAGESIZE    1024
#define BLOCKSIZE 15360 

#include "t9api.h"
#include "IMERes.h"
extern T9ChineseData const T9FARDATA gT9TRChineseLDB;
extern T9ChineseData const T9FARDATA gT9SMChineseLDB;
extern const sIMELDBDetails* gIMELDBArray;
/*---------------------------------------------------------------------------
 *
 *  Function: T9ReadLdbData
 *                                 
 *  Synopsis: Callback from T9Core to access a non-Chinese language database
 *                                           
 *     Input: T9FieldInfo *pFieldInfo -- Field info struct that holds database number
 *            T9U32 dwOffset - byte offset from LDB start to read from
 *            T9FARPOINTER *ppbDst - Ptr to a ptr to the data cache.
 *            T9U32 *pdwStart - Ptr to offset of start of data.
 *            T9NUM nSize    - number of bytes desired (but only 1 is required)
 *            T9NUM mCacheIndex - cache number (igored for compiled in LDBs)
 * 
 *    Return: Number of bytes available at *pdwStart
 *                                                                            
 *---------------------------------------------------------------------------*/
T9U32 T9FARCALL T9ReadLdbData(T9FieldInfo *pFieldInfo, T9U32 dwOffset, T9FARPOINTER *ppbDst, T9U32 *pdwStart, T9UINT nSize, T9MINOR mCacheIndex)
{
	const T9LdbMemData* CurLang;
	T9U32 i;
        T9U32 data_size = 0;

	/* Find the  LDB block in imerest9.h */
	for (i = 0;; i++) 
	{
		if (gIMELDBArray[i].wLdbNum == (T9U16)(pFieldInfo->nLdbNum & T9PIDMASK)) 
		{
			CurLang = &gIMELDBArray[i];
			break;
		}
		else if ((T9U16)(0xFF)==gIMELDBArray[i].wLdbNum) 
		{
			return 0;
		}
	}

/* find  point from where within a block reading will start */
    *pdwStart = dwOffset - (dwOffset % BLOCKSIZE);

	/* find  read ldb block*/
	for(i=1;i<CurLang->nNumFullBlk+2;i++)
	{
	    if ( dwOffset <  BLOCKSIZE*i )
            {
                *ppbDst = (T9FARPOINTER) CurLang->dwLdbDataBlk[i-1];
	        if( i == CurLang->nNumFullBlk+1)
	        data_size = CurLang->dwLastBlkSize;
                else
                data_size =  BLOCKSIZE;
                break;
            }
            else
            data_size = 0;
	}
	return data_size;	
}

/*---------------------------------------------------------------------------
 *
 *  Function: T9CCLoadLdb
 *
 *  Synopsis: Callback from T9Core to load the Chinese language database
 *
 *     Input: pCCFieldInfo   -- T9 Chinese Fieldinfo structure
 *            pT9CCLdbHeader -- Pointer to the buffer that the callback
 *                              function loads the LDB data to.
 *
 *    Return: T9STATNONE if the loading succeeds;
 *            T9STATLOADLDBFAIL if the language ID in the T9 FieldInfo
 *            structure is not valid.
 *
 *---------------------------------------------------------------------------*/
T9STATUS T9FARCALL T9CCLoadLdb(T9CCFieldInfo *pCCFieldInfo, T9ChineseData T9FARDATA *pT9CCLdbHeader)
{
    T9ChineseData const T9FARDATA *pLdbHeader;
    T9UINT i;

    switch (pCCFieldInfo->G.nLdbNum) {

        /* Load Traditional Chinese LDB */
#if defined  (__MMI_T9_TR_CHINESE__) || defined (__MMI_T9_HK_CHINESE__)
        case (1 * 256 + 4):
            pLdbHeader = &gT9TRChineseLDB;
            break;
#endif

        /* Load Simplified Chinese LDB */
#ifdef __MMI_T9_SM_CHINESE__
        case (2 * 256 + 4):
            pLdbHeader = &gT9SMChineseLDB;
            break;
#endif

        default :
            return T9STATLOADLDBFAIL;
    }

    /* Copy the header part */
    for (i = 0; i < T9CCLdbHeaderSize; i++)
        pT9CCLdbHeader->bHeader[i] = pLdbHeader->bHeader[i];

    /* Copy block pointers */
    for (i = 0; i < T9CCLDBBLOCKCOUNT; i++)
        pT9CCLdbHeader->pBlockPointers[i] = pLdbHeader->pBlockPointers[i];

    return T9STATNONE;
}
