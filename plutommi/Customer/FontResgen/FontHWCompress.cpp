#include "stdafx.h"
#include "FontHWCompress.h"
#include "LzmaLib.h"

BF_ENC_STRUCT   g_encoder;

S32 LV1Size;
S32 LV2Size;
BF_LEVEL1_TABLE_STRUCT  LV1Dict1;
BF_LEVEL2_TABLE_STRUCT  LV1Dict2;

const char *lv1_table_name = "g_hw_compression_lv1_table";
const char *lv2_table_name = "g_hw_compression_lv2_table";

#if 0 
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
#endif

/*****************************************************************************
 * FUNCTION
 *  FontHWCompressQueryDictionary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
BF_ENC_STATUS_ENUM FontHWCompressQueryDictionary( BF_ENC_STRUCT *pEncoder, 
                                    S32 *LV1Size,
                                    S32 *LV2Size,
                                    BF_LEVEL1_TABLE_STRUCT  *LV1Dict,
                                    BF_LEVEL2_TABLE_STRUCT  *LV2Dict)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return bfEncGetDictionary(pEncoder,
                           (U8 *)LV1Dict,
                           LV1Size,
                           (U8 *)LV2Dict,
                           LV2Size);
    
}

/*****************************************************************************
 * FUNCTION
 *  queryDictionary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool FontHWCompressWriteLVTableToFile(FILE *pFile,
                                    S32 LV1Size,
                                    S32 LV2Size,
                                    BF_LEVEL1_TABLE_STRUCT  *LV1Dict,
                                    BF_LEVEL2_TABLE_STRUCT  *LV2Dict,
                                    const char *lv1_table_name,
                                    const char *lv2_table_name)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 iCount = 0; 
    unsigned char *pchar = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(IsUseHWFontCompression() && (pFile != NULL))
    {
        //fprintf(pFile,_T("\n#if defined(__MMI_BDF_SW_COMPRESSION__)\n"));

        pchar = (unsigned char *)&LV1Dict->entry[0];
        fprintf(pFile, _T("\nconst U8 %s[%ld]= {"), lv1_table_name, LV1Size);
        for( iCount = 0 ; iCount < LV1Size; iCount++)
        { 
            if (iCount%15 == 0)
            {
                fprintf(pFile, _T("\n"));
            }    
            fprintf(pFile, _T("0x%-2X,"), pchar[iCount]);        
        }
        fprintf(pFile,_T("};\n"));

        pchar = (unsigned char *)&LV2Dict->entry[0][0];
        fprintf(pFile, _T("\nconst U8 %s[256][15]= {"), lv2_table_name);
        for( iCount = 0 ; iCount < LV2Size; iCount++)
        { 
            if (iCount%15 == 0)
            {
                fprintf(pFile, _T("\n"));
            }    
            fprintf(pFile, _T("0x%-2X,"), pchar[iCount]);        
        }
        fprintf(pFile, ("};\n"));
        
       // fprintf(pFile, "#endif\n");
    }
    return true;
}

int FontLzmaCompress(unsigned char *dest, size_t *destLen, const unsigned char *src, size_t srcLen)
{
	#define DICTSIZE (1<<16)
	//unsigned char props[LZMA_PROPS_SIZE] = {0};
	unsigned int propSize = LZMA_PROPS_SIZE;
	int status;
	
	status = LzmaCompress(
				dest+propSize, destLen, src, srcLen, dest, &propSize,
				0,	/* 0 <= level <= 9, default = 5 */
				DICTSIZE,	/* default = (1 << 24) */
				3,	/* 0 <= lc <= 8, default = 3  */
				0,	/* 0 <= lp <= 4, default = 0  */
				2,	/* 0 <= pb <= 4, default = 2  */
				32,	/* 5 <= fb <= 273, default = 32 */
				1	/* 1 or 2, default = 2 */
				);

	return status;
}

int FontLzmaUncompress(unsigned char * dest,size_t * destLen,const unsigned char * src,SizeT * srcLen)
{
	int status;
	
	status = LzmaUncompress(dest, destLen, src+LZMA_PROPS_SIZE, srcLen, src, LZMA_PROPS_SIZE);

	return status;
}

U32 FontLzmaGroupSplitter(U8 *pDataArray, U32 *pOffsetArray, U32 nTotalChars, U8 *pDataArrayCompressed, S32 *nCompressTotalLen, sMCTGroupData *sGroupData)
{
	#define KSIZE (1<<10)
	#define GROUP_MAX_SIZE (10*KSIZE)
	//#define COMPRESSLEN ((GROUP_MAX_SIZE)+(GROUP_MAX_SIZE/10)+(16*KSIZE))

	U32 iCount = 0; 
	U32 blockIdx = 0;
	U32 offsetSize = 0, offsetSizeTmp = 0;
	U8* pData = pDataArray;
	U32 groupNum = 0;
	U32 boundarySize = 0;
	U8 compressBuf[GROUP_MAX_SIZE];
	U32 compressLen = GROUP_MAX_SIZE, compressTotalLen = 0;
	//U8 uncompressBuf[GROUP_MAX_SIZE];
	//U32 uncompressLen = GROUP_MAX_SIZE;
					
    for(iCount=1; iCount < nTotalChars+1; iCount++)
    {
		if(pOffsetArray[iCount-1] > pOffsetArray[iCount])
			blockIdx++;
    	      
		offsetSize = (blockIdx<<8) + pOffsetArray[iCount];
    	  
		if(iCount < nTotalChars)
		{
			if(pOffsetArray[iCount] > pOffsetArray[iCount+1])
				boundarySize = ((blockIdx+1) << 8) + pOffsetArray[iCount+1] - offsetSizeTmp;
			else
				boundarySize = (blockIdx << 8) + pOffsetArray[iCount+1] - offsetSizeTmp;
		}

		if (boundarySize > (GROUP_MAX_SIZE-5) || (iCount) == nTotalChars)
		{
		    compressLen = (GROUP_MAX_SIZE-5);
		    FontLzmaCompress(compressBuf, &compressLen, pData, offsetSize-offsetSizeTmp);
		    //uncompressLen = (offsetSize-offsetSizeTmp);
		    //FontLzmaUncompress(uncompressBuf, &uncompressLen, compressBuf, &compressLen);
		    memcpy(&pDataArrayCompressed[compressTotalLen], compressBuf, compressLen+5);
		    sGroupData->nOffset = offsetSizeTmp;
		    sGroupData->nSize = compressLen+5;
		    compressTotalLen += (compressLen+5);
		    offsetSizeTmp = offsetSize;
		    pData = &(pDataArray[offsetSizeTmp]); 
		    groupNum++;
		    sGroupData++;
        }
    }
	sGroupData->nOffset = offsetSizeTmp;
	sGroupData->nSize = 0;
	groupNum++;

	*nCompressTotalLen = compressTotalLen;

	return groupNum;
}

