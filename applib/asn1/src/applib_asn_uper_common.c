/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * applib_asn_uper_common.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is intends for UPER function for AGPS project.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


//#include "kal_release.h"
#include "applib_asn_memory.h"
#include "applib_asn_common.h"
#include "applib_asn_uper_Common.h"


///add for RHR
#include "applib_mtkasn_global.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
///

/************************************************************************/
/*         UPER    Encode   Tools  Function                             */
/************************************************************************/

extern void applib_UperPutSmallNumber(applib_AsnContext *pContext, U32 uNum)
{
	if (uNum < 64)
	{
		applib_putShortBits(pContext, 1, 0);
		applib_putShortBits(pContext, 6, uNum);
	}
	else
	{
		applib_putShortBits(pContext, 1, 1);
		applib_UperPutSemiConstraintNumber(pContext, 0, uNum);
	}
}

extern U32 applib_UperGetSmallNumber(applib_AsnContext *pContext)
{
	U32 uNum;

	if (0 ==  applib_getShortBits(pContext, 1))
	{
		uNum = applib_getShortBits(pContext, 6);
	}
	else
	{
		uNum = 	applib_UperGetSemiConstraintNumber(pContext, 0);
	}

	return uNum;
}

extern U32 applib_UperPutLengthValue(applib_AsnContext *pContext, U32 lBound, U32 uBound, U32 uLen)
{
	U32 uDistance;
	ASSERT(uBound >= lBound);

	uDistance = uBound - lBound;
	if ((0 == uDistance) & (uDistance <= 65535))
	{
		// Need Not to encode;
		return 0;
	}
	if (uBound < 65536)
	{
		applib_UperPutWholeConstraintNumber(pContext, lBound, uBound, uLen);
	}
	else if (uBound >= 65536)
	{
		if (uLen <= 127)
		{
			applib_putShortBits(pContext, 1, 0);
			applib_putShortBits(pContext, 7, uLen);
		}
		else if (uLen >127 && uLen<=16383)
		{
			applib_putShortBits(pContext, 2, 0x02);
			applib_putShortBits(pContext, 14, uLen);
		}
		else if (uLen>16383)
		{
			//....
		}
	}
	return 0;
}

extern U32 applib_UperGetLengthValue(applib_AsnContext *pContext, U32 lBound, U32 uBound)
{
	U32 ulen = 0, uDistance = uBound - lBound;
	ASSERT(uBound >= lBound);

	if ((0 == uDistance) & (uDistance <= 65535))
	{
		// Need Not to encode;
		return lBound;	
	}

	if (uBound < 65536)
	{
		ulen = applib_UperGetWholeConstraintNumber(pContext, lBound, uBound);
	}
	else if (uBound >= 65536)
	{
		if (0 == applib_testGetShortBits(pContext, 1))
		{
			// Len < 127
			ulen = applib_getShortBits(pContext, 8);
		}
		else if (0x20 == applib_testGetShortBits(pContext, 2))
		{
			// uLen >127 && uLen<=16383
			applib_getShortBits(pContext, 2);
			ulen = applib_getShortBits(pContext, 14);
		}
		else
		{
			// uLen>16383  ...
		}
	}
	return ulen;
}

extern  void applib_UperPutWholeConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uBound, U32 uNum)
{	
	U32		range, bits, temp, i;
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else
	{
		temp = 0;
		i = 32;

		while (0 == temp)
		{
			temp = range & 1<<(i-1);
			i--;
		}
		bits = i+1;
		applib_putBits(pContext, bits, (uNum-lBound));
	}
}

extern U32	applib_UperGetWholeConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uBound)
{
	U32		range, bits, temp, i, uNum = 0;
	ASSERT(uBound >= lBound);
	range = uBound - lBound;

	if (0 == range)
	{
		// put no bit 
	}
	else
	{
		temp = 0;
		i = 32;
		while (0 == temp)
		{
			temp = range & 1<<(i-1);
			i--;
		}

		bits = i+1;

		uNum = applib_getShortBits(pContext, bits) + lBound;
	}
	return uNum;
}

extern void  applib_UperPutSemiConstraintNumber(applib_AsnContext *pContext, S32 lBound, S32 uNum)
{	
	U32		distance, nByte ;

	if ((lBound > 0 && uNum > 0) || (lBound < 0 && uNum < 0))
	{
		distance = uNum - lBound;
	}
	else
	{
		distance = uNum - lBound;
	}

	nByte = applib_GetNumberOctetLength(distance);
	applib_UperPutLengthValue(pContext, 0, ASN_MAX, nByte);
	applib_putBits(pContext, nByte * 8, distance);
}

extern S32 applib_UperGetSemiConstraintNumber(applib_AsnContext *pContext, S32 lBound)
{	
	U32	sNum, nByte;
	nByte = applib_UperGetLengthValue(pContext, 0, ASN_MAX);

	if (nByte != 0 )
	{
		sNum = applib_getBits(pContext, nByte * 8);
	}
	else
	{
		sNum = 0;
	}

	return sNum;
}

extern void applib_UperPutNonConstraintNumber(applib_AsnContext *pContext,  S32 uNum)
{
	int		ulen, nByte, temp;
	ulen = 0;
	temp = 0;

	if (uNum > 0)
	{
		nByte = applib_GetNumberOctetLength(uNum);

		switch(nByte)
		{
		case 1:
			temp = uNum & 0x00000080;
			break;
		case 2:
			temp = uNum & 0x00008000;
			break;
		case 3:
			temp = uNum & 0x00800000;
		    break;
		case 4:
			temp = uNum & 0x80000000;
		    break;
		default:
		    break;
		}

		if (0 != temp)
		{
			ulen = 1;
			applib_putShortBits(pContext, 8, 0);
		}

		ulen += nByte;
		applib_putShortBits(pContext, applib_GetNumberOctetLength(ulen) * 8, ulen);	//Put length


		if (0 != temp)
		{
			applib_putShortBits(pContext, 8, 0);
		}

		applib_putShortBits(pContext, nByte * 8, uNum);
	}
	else
	{
		nByte = applib_GetNumberOctetLength(-uNum);

		uNum = -uNum;
		uNum = ~uNum;
		uNum += 1;

		if (nByte == 1){
			uNum &= 0x000000FF;
		}
		else if (nByte == 2){
			uNum &= 0x0000FFFF;
		}
		else if (nByte == 3){
			uNum &= 0x00FFFFFF;
		}

		applib_putShortBits(pContext, applib_GetNumberOctetLength(nByte) * 8, nByte);	//Put length
		applib_putShortBits(pContext, nByte * 8, uNum);
	}
}

extern S32 applib_UperGetNonConstraintNumber(applib_AsnContext *pContext)
{
	int		nByte;
	S32		uNum = 0;

	nByte = applib_getShortBits(pContext, 8);	//Get lenght

	if (0 == applib_testGetShortBits(pContext, 1))
	{
		// positive
		if (0 == applib_testGetShortBits(pContext, 8))
		{
			applib_getShortBits(pContext, 8);	
			uNum =  applib_getShortBits(pContext, 8 * (nByte-1));
		}
		else
		{
			uNum =  applib_getShortBits(pContext, 8 * nByte);
		}	
	}
	else
	{
		// negetive
		uNum =  applib_getShortBits(pContext, (8 * nByte));
		uNum--;
		uNum = ~uNum;
		uNum = -uNum;

		if (nByte == 1){
			uNum |= 0xFFFFFF00;
		}
		else if (nByte == 2){
			uNum |= 0xFFFF0000;
		}
		else if (nByte == 3){
			uNum |= 0xFF000000;
		}
	}
	return uNum;
}

extern void applib_UperEncodeOpenType(applib_AsnContext *pContext,  U8 * pData, U32 uSize)
{
	if (uSize > 0)
	{
		applib_UperPutLengthValue(pContext, 0, ASN_MAX, uSize);
		applib_putLongBits(pContext, uSize*8, pData);
	}
}

extern U32 applib_UperDecodeOpenTypeLength(applib_AsnContext *pContext)
{
	return applib_UperGetLengthValue(pContext, 0, ASN_MAX);
}

extern U32 applib_UperDecodeOpenType(applib_AsnContext *pContext,  U8 * pData, U32 uSize)
{
	U32		   uLen;
	applib_AsnContext TempContext = *pContext;

	uLen = applib_UperGetLengthValue(pContext, 0, ASN_MAX);
	if (NULL == pData)
	{
		*pContext = TempContext;
		return uLen;
	}

	applib_getLongBits(pContext, 8 * asn_min(uLen, uSize),  pData);

	// return decode length (by byte)
	return asn_min(uLen, uSize);
}

static void applib_UperEncodeOIDItem(applib_AsnContext *pContext,  U32  uData)
{
	ASSERT(uData < 2097152);
	if (uData < 128)
	{
		applib_putShortBits(pContext,  8, uData);
	}
	else if (uData < 16384)
	{
		// First Octet
		applib_putShortBits(pContext,  1, 1);
		applib_putShortBits(pContext,  7, (uData - uData%128)/128);

		// Second Octet
		applib_putShortBits(pContext,  1, 0);
		applib_putShortBits(pContext,  7, uData%128);
	}
	else if (uData < 2097152)
	{
		// First Octet
		applib_putShortBits(pContext,  1, 1);
		applib_putShortBits(pContext,  7, (uData - uData%16384)/16384);

		// Second Octet
		applib_putShortBits(pContext,  1, 1);
		applib_putShortBits(pContext,  7, ((uData - uData%128)%16384)/128);

		// Third Octet
		applib_putShortBits(pContext,  1, 0);
		applib_putShortBits(pContext,  7, uData%128);
	}
}

static U32 applib_UperDecodeOIDItem(applib_AsnContext *pContext,  U8 **ppData)
{
	U32		uNum = 0;
	U8		uData = **ppData;

	if (uData <= 0x7F)
	{
		uNum = uData;
		(*ppData)++;
	}
	else if (*(*ppData+1)  <= 0x7F)
	{
		// First Octet
		uData &= 0x7F;
		uNum = uData;
		uNum *= 128;

		(*ppData)++;
		uData = **ppData;

		// Second Octet
		uData &= 0x7F;
		uNum += uData;
		(*ppData)++;
	}
	else if (*(*ppData+2) <= 0x7F)
	{
		// First Octet
		uData &= 0x7F;
		uNum = uData;
		uNum *= 128;

		(*ppData)++;
		uData = **ppData;

		// Second Octet
		uData &= 0x7F;
		uNum += uData;
		uNum *= 128; 

		(*ppData)++;
		uData = **ppData;

		// Third Octet
		uData &= 0x7F;
		uNum += uData;

		(*ppData)++;
	}
	else
	{
		UA1_ERROR(10);
	}
	return uNum;
}

extern void applib_UperEncodeOID(applib_AsnContext *pContext, applib_OID *pOid)
{
	U32		ulen, i;
	U8 * pTemp = NULL;

	BEGIN_PRE_ENCODE
	applib_putShortBits(pContext,  8, ((*pOid->value)*40 + (* (pOid->value + 1))));

	for(i=2; i<pOid->valueLen; i++)
	{
		applib_UperEncodeOIDItem(pContext, *(pOid->value + i));
	}

	END_PRE_ENCODE
	applib_UperEncodeOpenType(pContext, (U8 *)pTemp, ulen);

   if (pContext->pMemFreeFunc != NULL)
   {
      pContext->pMemFreeFunc((void **)&pTemp);
   }
   else
   {
	  applib_asnMemFree((void **)&pTemp);
   }
}

extern void applib_UperDecodeOID(applib_AsnContext *pContext, applib_OID *pOid)
{	
	U32	 ulen, i, *pItemOrg;
	U8 * pBuf;// , * pBufOrg;

	ulen = applib_UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	applib_AsnDecodeAlloc(pContext, (void **)&pBuf, ulen);

	//pBufOrg = pBuf;
	applib_UperDecodeOpenType(pContext, (U8 *)pBuf, ulen);

	//Got object Identify Item count
	for (i=1, pOid->valueLen=2; i<ulen; i++)
	{
		if (*(pBuf+i) <= 0x7F )
		{
			(pOid->valueLen)++;
		}
	}

	applib_AsnDecodeAlloc(pContext, (void **)&(pOid->value), (pOid->valueLen)*4);

	pItemOrg = pOid->value;

	if ((*pBuf) <= 39)
	{
		*pOid->value = 0;
	}
	else if ((*pBuf) <= 79)
	{
		*pOid->value = 1;
	}
	else
	{
		*pOid->value = 2;
	}

	*(pOid->value+1) = (*pBuf)%40;
	pBuf++;
	pOid->value += 2;

	for (i=2; i<pOid->valueLen; i++, pOid->value++)
	{
		*pOid->value = applib_UperDecodeOIDItem(pContext, &pBuf);
	}
	pOid->value = pItemOrg;
}

//////////////////////////////////////////////////////////////////////////
// String Encode
//////////////////////////////////////////////////////////////////////////
static  applib_UperEncodeTwoByteString(applib_AsnContext *pContext,  applib_TwoByteString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;

	applib_UperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	for(i = 0; i < pStr->valueLen; i++){
		applib_putShortBits(pContext, 8,  GET_U16_HIGH(*(pStr->value+i)) );
		applib_putShortBits(pContext, 8,  GET_U16_LOW(*(pStr->value+i)) );
	}
}

static  applib_UperDecodeTwoByteStringA(applib_AsnContext *pContext,  applib_TwoByteString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet *pAlphabet)
{
	// If No Constraint 
	U32		i;
	U16		uHigh, uLow;

	pStr->valueLen = applib_UperGetLengthValue(pContext, minSize, maxSize);
	applib_AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen * 2);

	for(i = 0; i < pStr->valueLen; i++){
		uHigh = applib_getShortBits(pContext, 8);
		uLow  = applib_getShortBits(pContext, 8);
		*(pStr->value + i) = MAKE_U16(uHigh, uLow);
	}
}

//////////////////////////////////////////////////////////////////////////
// Numeric String
extern  void applib_UperEncodeNumericString(applib_AsnContext *pContext,  applib_asn_NumericString *pStr, U32 minSize, U32 maxSize, applib_ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;
	applib_UperPutLengthValue(pContext, minSize, maxSize, pStr->valueLen);
	for(i = 0; i < pStr->valueLen; i++){
		applib_putShortBits(pContext, 4,  *(pStr->value+i) - 47);
	}
}

extern  void applib_UperDecodeNumericStringA(applib_AsnContext *pContext,  applib_asn_NumericString *pStr, U32 minSize, U32 maxSize, applib_ASN_OneByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	U32		i;

	pStr->valueLen = applib_UperGetLengthValue(pContext, minSize, maxSize);
	applib_AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);

	for(i = 0; i < pStr->valueLen; i++){
		*(pStr->value+i) = applib_getShortBits(pContext, 4) + 47;
	}
}

//////////////////////////////////////////////////////////////////////////
// BMP String
extern  void applib_UperEncodeBMPString(applib_AsnContext *pContext,  applib_asn_BMPString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	applib_UperEncodeTwoByteString(pContext, pStr, minSize, maxSize, pAlphabet);
}

extern  void applib_UperDecodeBMPStringA(applib_AsnContext *pContext,  applib_asn_BMPString *pStr, U32 minSize, U32 maxSize, applib_ASN_TwoByteAlphabet *pAlphabet)
{
	// ... ?  Check Characters ?
	applib_UperDecodeTwoByteStringA(pContext, pStr, minSize, maxSize, pAlphabet);
}

//////////////////////////////////////////////////////////////////////////
// General String
extern  void applib_UperEncodeGeneralString(applib_AsnContext *pContext,  applib_asn_GeneralString *pStr)
{
	applib_UperEncodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern  void applib_UperDecodeGeneralStringA(applib_AsnContext *pContext,  applib_asn_GeneralString *pStr)
{
	pStr->valueLen = applib_UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	applib_AsnDecodeAlloc(pContext, (void **)&pStr->value, pStr->valueLen);

	applib_UperDecodeOpenType(pContext, (U8 *)pStr->value, pStr->valueLen);
}

extern	void applib_UperDecodeChoiceUnKnowItem(applib_AsnContext *pContext, applib_ChoiceUnKnow *pUnKnowItem)
{
	applib_ChoiceUnKnow	*pUnKnow;
	// In the extension

	applib_AsnDecodeAlloc(pContext, (void **)&pUnKnow, sizeof(applib_ChoiceUnKnow));
	pUnKnow->uIndex =  applib_UperGetSmallNumber(pContext); // Index

	pUnKnow->valueLen = applib_UperDecodeOpenType(pContext, (U8 *)NULL, 0);
	applib_AsnDecodeAlloc(pContext, (void **)&(pUnKnow->value), pUnKnow->valueLen);
	applib_UperDecodeOpenType(pContext, (U8 *)pUnKnow->value, pUnKnow->valueLen);

	pUnKnowItem = pUnKnow;
	
	NOT_USED(pUnKnowItem); //add for clear warning
}

extern void	applib_UperDecodeSequcenceUnKnowItem(applib_AsnContext *pContext,  applib_UnKnowExtensionItemArray *pArray, U32 uSize, Bool  *pIsItemExist)
{
	U32	i, uUnKonwSize;
	U8 *pData;

	applib_AsnDecodeAlloc(pContext, (void **)&(pArray->value), sizeof(applib_UnKnowExtensionItem) * uSize);
	memset(pArray->value, 0, sizeof(applib_UnKnowExtensionItem) * uSize);

	for (i=0; i<uSize; i++)
	{
		if (*(pIsItemExist+i))
		{
			uUnKonwSize = applib_UperDecodeOpenType(pContext, (U8 *)NULL, 0);
			applib_AsnDecodeAlloc(pContext, (void **)&pData, uUnKonwSize);
			applib_UperDecodeOpenType(pContext, (U8 *)pData, uUnKonwSize);
			(pArray->value + i)->valueLen = uUnKonwSize;
			(pArray->value + i)->value = pData;
			pArray->valueLen++;
		}
		else
		{
			(pArray->value + i)->valueLen = 0;
			(pArray->value + i)->value = NULL;
			pArray->valueLen++;
		}
	}
}

extern int	applib_GetPresentBitsNum(unsigned long data)
{
	int		iNum,i;

	for (i=0 , iNum=0; i<32; i++)
	{
		if ((data & 0x00000001) == 1)
		{
			iNum++;
		}
		data >>= 1;
		data &= 0x7FFFFFFF;
	}
	return  iNum;
}
