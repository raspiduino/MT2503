#include "stdafx.h"
#include "bdf_operation.h"
#include "FontHWCompress.h"
//#include "zlib_forfont.h"
#include "zlib.h"


CBdfOperation::CBdfOperation(string *language_name, U8 fontDataIndex, bool isfixed, string *pbdf_file, U8 is_dwidth)
{


	m_strLanguageName = *language_name;
    m_fontDataIndex = fontDataIndex;
    m_isfixed = isfixed;
    m_bdf_filepath = *pbdf_file;
    m_bGenerateDWidth = is_dwidth;

	m_nTotalChars = MAX_NUM_CHARS;
	m_nIndexArray = 0;
	

	//Ascent and Descent
	m_nAscent = m_nDescent = 0;

	memset(&m_struFontInfo, 0, sizeof(m_struFontInfo));
}

CBdfOperation::~CBdfOperation()
{
    
}

/*****************************************************************************
 * FUNCTION
 *  parsing_bdf_file
 * DESCRIPTION
 *  This function is used scan the bdf file and save the character information to the array
 * PARAMETERS
 *  bdf_file [IN]
 *  fontDataIndex [IN]
 * RETURNS
 *  bool
******************************************************************************/
bool CBdfOperation::parsing_bdf_file(string *pbdf_file, U8 fontDataIndex, bool isfixed)
{
   FILE	*stream;
	int		bbx1, bbx2;
	U64	bitmap_stream[100];		//for font bigger than 64
	char	temp[100] = {0};
	char	nStartChar[20];
	U32	encoding1;
	int     nCount=0;
	int     nCountCompression=0;
	// reinit the index offset array, otherwise secondly load the bdf will fail
	m_nIndexArray = 0;

   
	if( (stream  = fopen(pbdf_file->c_str(), _T("r"))) == NULL )
	{
		return 0;
	}
	printf("[Dependency] %s\n", pbdf_file->c_str());
	while ( fgets(temp, 100, stream ) != NULL)
	{
		if (strncmp(temp,"ENDFONT", strlen("ENDFONT"))==0)
		{
			if(nCount>=(int)m_nTotalChars)
			{
				m_nTotalChars = --nCount;
			}
			break;
		}
			
		//Ascent and Descent for baseline
		if (strncmp(temp,"FONT_ASCENT", strlen("FONT_ASCENT"))==0)
		{
			sscanf(temp, "FONT_ASCENT %d\n", &m_nAscent);
		}
		if (strncmp(temp,"FONT_DESCENT", strlen("FONT_DESCENT"))==0)
		{
			sscanf(temp, "FONT_DESCENT %d\n", &m_nDescent);
		}

		if (strncmp(temp,"FONTBOUNDINGBOX", strlen("FONTBOUNDINGBOX"))==0)
		{			
					
			//create the new data
			sscanf(temp, "FONTBOUNDINGBOX %d %d %d %d \n", &m_nWidth,&m_nHeight,&m_nOrgWidthOffset,&m_nOrgHtOffset);
			m_nOrgWidthOffset<0?m_nOrgWidthOffset= -m_nOrgWidthOffset:NULL;
			if(m_nOrgHtOffset<0)m_nOrgHtOffset= -m_nOrgHtOffset;
			int nSize = (m_nWidth)*(m_nHeight);
			m_nByteArraySize = nSize/8;
			if(nSize%8) ++m_nByteArraySize;
			m_struFontInfo.nSize = m_nByteArraySize*m_nTotalChars;
			m_struFontInfo.pFontData = new U8[m_struFontInfo.nSize];
			memset(m_struFontInfo.pFontData,0,m_struFontInfo.nSize); 
			m_struFontInfo.pIndexArray = new U32[m_nTotalChars+1];
			memset(m_struFontInfo.pIndexArray,0,sizeof(U32)*(m_nTotalChars+1));
			m_struFontInfo.pWidthArray = new U32[m_nTotalChars];
			memset(m_struFontInfo.pWidthArray,0,sizeof(U32)*(m_nTotalChars));
			m_struFontInfo.pDWidthArray = new U32[m_nTotalChars];
			memset(m_struFontInfo.pDWidthArray,0,sizeof(U32)*(m_nTotalChars));
			
			///new added
			m_struFontInfo.pFontDataCompression = new U8[m_struFontInfo.nSize];
			memset(m_struFontInfo.pFontDataCompression,0,m_struFontInfo.nSize);

 			m_struFontInfo.pBlockIndexArrayCompression = new U32[200 *100];
            m_struFontInfo.nBlockIndexArrayCompressionSize = 0;
			///

			m_struFontInfo.pUnicodeData = new U32[m_nTotalChars];
			memset(m_struFontInfo.pUnicodeData,0,sizeof(U32)*(m_nTotalChars));
			m_struFontInfo.pBBX1 = new U32[m_nTotalChars];
			memset(m_struFontInfo.pBBX1,0,sizeof(U32)*(m_nTotalChars));
			m_struFontInfo.pBBX2 = new U32[m_nTotalChars];
			memset(m_struFontInfo.pBBX2,0,sizeof(U32)*(m_nTotalChars));
			m_struFontInfo.pBBX3 = new U32[m_nTotalChars];
			memset(m_struFontInfo.pBBX3,0,sizeof(U32)*(m_nTotalChars));
			m_struFontInfo.pBBX4 = new U32[m_nTotalChars];
			memset(m_struFontInfo.pBBX4,0,sizeof(U32)*(m_nTotalChars));
			m_nBoxMaxWidth = m_nWidth;
			m_struFontInfo.nHeight = m_nHeight;
			m_struFontInfo.nTotalChars = m_nTotalChars;
            
		}
		else if (strncmp(temp,"STARTCHAR", strlen("STARTCHAR"))==0)
		{
			sscanf(temp,"STARTCHAR %s\n", nStartChar);
			fscanf(stream, "ENCODING %d\n", &encoding1);
			
			fscanf(stream, "SWIDTH %d %d\n", &m_iswidth1, &m_iswidth2);
			fscanf(stream, "DWIDTH %d %d\n", &m_idwidth1, &m_idwidth2);
			fscanf(stream, "BBX %d %d %d %d\n", &bbx1, &bbx2, &m_nBBox, &m_nBBoy);
			fscanf(stream, "%s\n", temp);
			memset(bitmap_stream, 0, sizeof (bitmap_stream) );
			for (int idx=0; idx<bbx2; idx++)
			{
				unsigned int iCount=0,jCount=0;
				if (bbx1>32)
					fscanf(stream, _T("%08X%08X\n"), &iCount,&jCount);
				else
					fscanf(stream, _T("%08X\n"), &iCount);
				
				bitmap_stream[idx]=iCount;
				if (bbx1>32)
				{
					int nSize=bbx1/8;
					if (bbx1%8) nSize++;
					nSize=(nSize-4)*8;
					
					bitmap_stream[idx]=bitmap_stream[idx]<<nSize;
					bitmap_stream[idx]|=jCount;
				}
			}


			fscanf(stream, "%s\n", temp);		 /* read ENDCHAR */
			m_struFontInfo.pBBX1[nCount] = bbx1;
			m_struFontInfo.pBBX2[nCount] = bbx2;
			m_struFontInfo.pBBX3[nCount] = m_nBBox;
			m_struFontInfo.pBBX4[nCount] = m_nBBoy;
			
			font_convert(encoding1, bbx1, bbx2, &m_struFontInfo, bitmap_stream, nCount, nCountCompression);
			 
            
			//add for revise:  when 
			if(m_struFontInfo.nWidth > m_nBoxMaxWidth
			   && isfixed )
			{
				m_nBoxMaxWidth = m_struFontInfo.nWidth;
			}
 
			nCount++;
			//nCountCompression++;
			m_struFontInfo.nTotalChars = nCount;
		}
	} 

	///new added
	/* Last element of pIndexArray[] is the total count of raw data. */
    if(m_struFontInfo.pIndexArray == NULL)
    {
        return 0;
    }
    int datalength = m_struFontInfo.pIndexArray[m_struFontInfo.nTotalChars];
    unsigned long destlen=m_struFontInfo.nSize;
    int result=-100;
    

	if (nCount == 0)
	{
		// No char find

		if (NULL != m_struFontInfo.pFontData)
		{
			delete [] m_struFontInfo.pFontData;
			m_struFontInfo.pFontData = NULL;
		}

		if (NULL != m_struFontInfo.pIndexArray)
		{
			delete [] m_struFontInfo.pIndexArray;
			m_struFontInfo.pIndexArray = NULL;
		}

		if (NULL != m_struFontInfo.pWidthArray)
		{
			delete [] m_struFontInfo.pWidthArray;
			m_struFontInfo.pWidthArray  = NULL;
		}

		if (NULL != m_struFontInfo.pDWidthArray)
		{
			delete [] m_struFontInfo.pDWidthArray;
			m_struFontInfo.pDWidthArray = NULL;
		}

		if (NULL != m_struFontInfo.pUnicodeData)
		{
			delete [] m_struFontInfo.pUnicodeData;
			m_struFontInfo.pUnicodeData = NULL;
		}

		if (NULL != m_struFontInfo.pBBX1)
		{
			delete [] m_struFontInfo.pBBX1;
			m_struFontInfo.pBBX1 = NULL;
		}

		if (NULL != m_struFontInfo.pBBX2)
		{
			delete [] m_struFontInfo.pBBX2;
			m_struFontInfo.pBBX1 = NULL;
		}

		if (NULL != m_struFontInfo.pBBX3)
		{
			delete [] m_struFontInfo.pBBX3;
			m_struFontInfo.pBBX1 = NULL;
		}

		if (NULL != m_struFontInfo.pBBX4)
		{
			delete [] m_struFontInfo.pBBX4;
			m_struFontInfo.pBBX1 = NULL;
		}	
        
		fclose( stream );
		return false;

	}

	fclose( stream );
	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  LoadBDFFile
 * DESCRIPTION
 *  This function is used to Load Bdf file.
 * PARAMETERS
 *  fontDataIndex [IN]
 *  *pMemo [IN]
 *  *pEditFileName [IN]
 *  *pEditWidth [IN]
 *  *pEditHeight [IN]
 *  isfixed [IN]
 * RETURNS
 *  bool
******************************************************************************/
bool CBdfOperation::LoadBDFFile(sMCTCustFontData *font_data)
{
    /* string *languane_name, U8 fontDataIndex, bool isfixed, U8 lang_type, string *pbdf_filepath = NULL */
    if(m_bdf_filepath.c_str() == NULL)
    {
        return false;
    }

    m_bdf_filename = m_bdf_filepath.substr(m_bdf_filepath.find_last_of('\\') + 1);
    string str_temp;
    char t[256] = {0};
    
	if (parsing_bdf_file(&m_bdf_filepath, m_fontDataIndex, m_isfixed) == false)
	{			
		return false;
    } 

	if(font_data != NULL)
	{ 
        string str = m_strLanguageName;
		switch(m_fontDataIndex)
		{
            
		    case MCT_ALPHA_SMALL_FONT/* or MCT_IDEOG_SMALL_FONT*/:
                str += "_small"; 
                strcpy((char *)font_data->name,str.c_str());

                break;
		    case MCT_ALPHA_MEDIUM_FONT /* or MCT_IDEOG_TOUCH_SCREEN_FONT*/:
                str += "_medium"; 
				strcpy((char *)font_data->name,str.c_str());	
			    break;
		    case MCT_ALPHA_LARGE_FONT /* or  MCT_IDEOG_TOUCH_SCREEN_LAREG*/:
                str += "_large"; 
				strcpy((char *)font_data->name,str.c_str());
			    break;

		    case MCT_ALPHA_SUBLCD_FONT:
                str += "_sublcd"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
		    case MCT_ALPHA_DIALER_FONT:
                str += "_dialling"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
		    case MCT_ALPHA_NUMBER1_FONT:
                str += "number1"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
		    case MCT_ALPHA_NUMBER2_FONT:
                str += "number2"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
		    case MCT_ALPHA_TOUCH_SCREEN_FONT:
                str += "_virtual_keyboard"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
		    case MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT:
                str += "_touch_screen_large"; 
			    strcpy((char *)font_data->name,str.c_str());
			    break;
        }	
    }
    else
    {
        return false;
    }
    
	font_data->strFilePath = m_bdf_filepath;
	font_data->strfilename = m_bdf_filename;
    
    font_data->is_dwidth = m_bGenerateDWidth;
    
	
	font_data->nHeight = m_struFontInfo.nHeight;
	font_data->nWidth = m_struFontInfo.nWidth;

	//Ascent and Descent for baseline
	font_data->nAscent = m_nAscent;
	font_data->nDescent = m_nDescent;

	font_data->nBoxMaxWidth = m_nBoxMaxWidth;  

    font_data->gen_hfile_name = "L_" + string((char *)font_data->name) + ".h";

    /* Calculate glyph char count. */

	font_data->nEquiDistant = m_isfixed;
    if(IsUseHWFontCompression())
    {
        font_data->nCharBytes = m_struFontInfo.nWidth / 8;
        if(m_struFontInfo.nWidth % 8)
        {
            font_data->nCharBytes++;
        }
        font_data->nCharBytes *= m_struFontInfo.nHeight;
    }
    else
    {
        font_data->nCharBytes = ((m_struFontInfo.nHeight)*(m_struFontInfo.nWidth))/8;
        if(((m_struFontInfo.nHeight)*(m_struFontInfo.nWidth))%8)
        {
            font_data->nCharBytes ++;
        } 
    }
	

    font_data->font_size = m_fontDataIndex;
    
	font_data->nMaxChars = 500;
	font_data->pWidthArray = m_struFontInfo.pWidthArray;
	font_data->pDWidthArray = m_struFontInfo.pDWidthArray;

	font_data->pOffsetArray = m_struFontInfo.pIndexArray;
	font_data->pDataArray = m_struFontInfo.pFontData;
	font_data->pUnicodeData= m_struFontInfo.pUnicodeData;

	font_data->pDataArrayCompression = m_struFontInfo.pFontDataCompression;
    font_data->nBlockIndexArrayCompressionSize = m_struFontInfo.nBlockIndexArrayCompressionSize;
    font_data->pBlockIndexArrayCompression = m_struFontInfo.pBlockIndexArrayCompression;
	

    font_data->pBBX1= m_struFontInfo.pBBX1 ;
	font_data->pBBX2= m_struFontInfo.pBBX2 ;
	font_data->pBBX3= m_struFontInfo.pBBX3 ;
	font_data->pBBX4= m_struFontInfo.pBBX4 ;
	font_data->m_nTotalChars = m_struFontInfo.nTotalChars;
	
    font_data->nDataArraySize = m_struFontInfo.pIndexArray[m_struFontInfo.nTotalChars];

    font_data->nDataArrayCompressionSize = m_struFontInfo.nFontDataCompressionSize;

    string csBdfFileName = m_bdf_filename.substr(0, m_bdf_filename.length() - 4);	
	csBdfFileName = ("A") + csBdfFileName;

	str_temp = csBdfFileName + "_Width";
	strcpy((char *)font_data->fontWidthName, str_temp.c_str());
	str_temp = csBdfFileName + "_DWidth";
	strcpy((char *)font_data->fontDWidthName, str_temp.c_str());

	str_temp = csBdfFileName + "_Offset";
	strcpy((char *)font_data->fontOffsetName, str_temp.c_str());
	str_temp = csBdfFileName + "_Data";
	strcpy((char *)font_data->fontDataName, str_temp.c_str());

	str_temp = csBdfFileName + "_CompressedData";
    
	strcpy((char *)font_data->fontCompressedDataName, str_temp.c_str());
	
	//show range information on screen and fill into sMCTCustFontData

    m_struFontInfo.range =          new U32[m_nTotalChars];
    m_struFontInfo.rangeDetails =   new sMCTRangeDetails;
    m_struFontInfo.rangeDetails->pRangeData = new sMCTRangeData[m_nTotalChars];
    m_struFontInfo.rangeDetails->pGroupData = new sMCTGroupData[m_nTotalChars];

    font_data->pRange = m_struFontInfo.range;
    font_data->pRangeDetails = m_struFontInfo.rangeDetails;

    font_data->nSize = m_struFontInfo.nSize;

    if(IsUseHWFontCompression())
    {
        font_data->pHWCompressionData = new U8[font_data->nSize];
        memset(font_data->pHWCompressionData, 0, font_data->nSize);
        font_data->pHWCompressionDataOffset = new U32[m_nTotalChars+1];
        memset(font_data->pHWCompressionDataOffset, 0, sizeof(U32)*(m_nTotalChars+1));
    }

	GetRangesFromBDF(&m_bdf_filepath,
		&(font_data->pRange),
		&(font_data->pRangeDetails),
		csBdfFileName,
		csBdfFileName,
		csBdfFileName,
    	csBdfFileName,
		font_data->nEquiDistant,
		font_data->nCharBytes);

    return true;
}

/*****************************************************************************
 * FUNCTION
 *  GetRangesFromBDF
 * DESCRIPTION
 *  This function is used scan the character information array and get the range, and save data to structure
 * PARAMETERS
 *  bdf_file [IN]
 *  *Memo [IN/OUT]
 *  **pRange [IN/OUT
 *  **pRangeDetails [IN/OUT]
 *  rangeInfoName [IN]
 *  rangeDataName [IN]
 *  rangeOffsetName [IN]
 *  fixWidth [IN]
 *  charU8s [IN]
 * RETURNS
 *  
******************************************************************************/
void CBdfOperation::GetRangesFromBDF(string *bdf_file, U32 **pRange, 
										   sMCTRangeDetails **pRangeDetails, 
										   string rangeInfoName, 
										   string rangeDataName, 
										   string rangeOffsetName, 
										   string fontRangeOffsetStructName,
										   bool fixWidth, U8 charU8s)
{
	char	aStream[100];
	FILE	*fp	=	NULL;
	int		nCode	=	0;
	string str_int;
	U32		nEncoding;
	U32		nPrevChar	=	-1;
	U32		nMin = -1;
	U32		nMax = -1;
	U32     totalCharacter = 0;
    string rangeblockIndexArrayName = fontRangeOffsetStructName;
	string groupInfoArrayName = fontRangeOffsetStructName;
	string groupDataArrayName = fontRangeOffsetStructName;

	(*pRangeDetails)->nNoOfRanges = 0;
	rangeInfoName = rangeInfoName + "_RangeInfo";
	rangeDataName = rangeDataName  + "_RangeData";
	rangeOffsetName = rangeOffsetName + "_RangeOffset";

    
	fontRangeOffsetStructName = fontRangeOffsetStructName + "_pRange";  
	rangeblockIndexArrayName = rangeblockIndexArrayName + "_RangeBlockIndex";
	groupInfoArrayName = groupInfoArrayName + "_GroupInfo";
	groupDataArrayName = groupDataArrayName + "_GroupData";

    strcpy((char *)(*pRangeDetails)->rangeInfoName, rangeInfoName.c_str());
	strcpy((char *)(*pRangeDetails)->rangeDataName, rangeDataName.c_str());
	strcpy((char *)(*pRangeDetails)->rangeOffsetName, rangeOffsetName.c_str());

	///new added
	strcpy((char *)(*pRangeDetails)->fontRangeOffsetStructName, fontRangeOffsetStructName.c_str());
	strcpy((char *)(*pRangeDetails)->fontRangeBlockIndexArrayName, rangeblockIndexArrayName.c_str());
	strcpy((char *)(*pRangeDetails)->groupInfoName, groupInfoArrayName.c_str());
	strcpy((char *)(*pRangeDetails)->groupDataName, groupDataArrayName.c_str());
    ///new added
    if((fp  = fopen( bdf_file->c_str(), _T("r") )) != NULL )
	{
		printf("[Dependency] %s\n", bdf_file->c_str());
		while ( fgets(aStream, 100, fp ) != NULL)
		{
			if (strncmp(aStream,"STARTCHAR", strlen("STARTCHAR"))==0)
			{
				fscanf(fp, "ENCODING %d\n", &nEncoding);
				if(nMin == (U32)-1)
				{
					nMin = nEncoding;
					nMax = nEncoding;
				}
				if(nPrevChar == (U32)-1)
					nPrevChar = nEncoding;
				else
				{
					if(nEncoding != nPrevChar+1)
					{
						(*pRangeDetails)->pRangeData[(*pRangeDetails)->nNoOfRanges].nMin = nMin;
						(*pRangeDetails)->pRangeData[(*pRangeDetails)->nNoOfRanges].nMax = nMax;

                        /* Fill each element range offset  of table */
                        /* For fixed width font, charU8s is fix byte count. */
					
						(*pRange)[(*pRangeDetails)->nNoOfRanges] = totalCharacter;

						(*pRangeDetails)->nNoOfRanges++;
						totalCharacter += (nMax - nMin + 1);
						nPrevChar=nMax= nMin = nEncoding;						
					}
					else
					{
						nPrevChar = nEncoding;
						nMax = nEncoding;
					}
				}				
			}
		}
		//save the last range
		if(nMin != (U32)-1)
		{
			(*pRangeDetails)->pRangeData[(*pRangeDetails)->nNoOfRanges].nMin = nMin;
			(*pRangeDetails)->pRangeData[(*pRangeDetails)->nNoOfRanges].nMax = nMax;
		
            (*pRange)[(*pRangeDetails)->nNoOfRanges] = totalCharacter;

			(*pRangeDetails)->nNoOfRanges++;
			totalCharacter += (nMax - nMin + 1);			
		}
		fclose(fp);
	}
}


/*****************************************************************************
 * FUNCTION
 *  font_convert
 * DESCRIPTION
 *  This function is used to save the character information to structure.
 * PARAMETERS
 *  encoding1 [IN]
 *  bbx1 [IN]
 *  bbx2 [IN]
 *  *pMMIFont [IN]
 *  *stream [IN]
 *  nCount [IN]
 *  nCountCompression [IN]
 * RETURNS
 *  int
******************************************************************************/
int CBdfOperation::font_convert(int encoding1, int bbx1, int bbx2, MCTFontInfo *pMMIFont,
									  U64 *stream, int nCount, int nCountCompression)
{
	U16		nEquiCheck	=	0;
	U16		nInitialDWidth;
	S32 out_len = 0;
    int i = 0;

	if(!nEquiCheck)
	{
		nInitialDWidth = m_idwidth1;
		nEquiCheck = 1;
	}
	if((m_nBBox+m_nOrgWidthOffset))	// if the left padding is required
	{
        /* Font width = dwidth +  m_nOrgWidthOffset */
		pMMIFont->nWidth = ((m_idwidth1)+m_nOrgWidthOffset);
		m_nWidth = ((m_idwidth1)+m_nOrgWidthOffset);
	}
	else
	{
        /* Font width = bbx1 */
		m_nWidth=pMMIFont->nWidth  = bbx1;
		m_nWidth = ((m_idwidth1)+m_nOrgWidthOffset);
	}
	
	pMMIFont->pUnicodeData[nCount] = encoding1; // recode the UCS2 value
	pMMIFont->pIndexArray[nCount] = m_nIndexArray;
	pMMIFont->pWidthArray[nCount] = pMMIFont->nWidth;
	
	pMMIFont->pDWidthArray[nCount] = m_idwidth1;
	
	m_nCurrCharHt = bbx2;
	m_nCurrCharWidth = bbx1;

    int tempSize = 0;
    if(IsUseHWFontCompression())
    {
        tempSize = pMMIFont->pWidthArray[nCount] / 8;
        if(pMMIFont->pWidthArray[nCount] % 8)
        {
            tempSize++;
        }
        tempSize = tempSize * m_nHeight;
        m_nIndexArray += tempSize; 
    }
    else
    {
        int nSize = (pMMIFont->pWidthArray[nCount])*(m_nHeight);
        tempSize = nSize/8;
        if(nSize%8) ++tempSize;
        m_nIndexArray+=tempSize;  
    }
	
	pMMIFont->pIndexArray[nCount+1] = m_nIndexArray;
	parsing_stream(stream,pMMIFont,pMMIFont->pIndexArray[nCount],bbx1, tempSize);
     
	return tempSize;
}


/*****************************************************************************
 * FUNCTION
 *  parsing_stream
 * DESCRIPTION
 *  This function is used to convert the character data to stream.
 * PARAMETERS
 *  *pStream [IN]
 *  *pMMIFont [IN]
 *  nIndex [IN]
 *  nSize [IN]
 * RETURNS
 *  
******************************************************************************/
void CBdfOperation::parsing_stream(U64 *pStream, MCTFontInfo *pMMIFont, int nIndex, int nSize, int charsize)
{
	const U64 nCOUNT=1;
	U64	nMask=	nCOUNT;
	U64				bU8;
	unsigned char	nBitsCopied	=	0;
	U64	nLeftshift	=	0;
	U64				nCurrent;
	int				nSourceBitsCopied	=	0;
	int				nPadding = 0;
	unsigned char	nTemp;
	int				nCount		=	0;
	int				nTempPadding=0;
    int				based_indx = nIndex;

	int nLeftPadding = m_nBBox+m_nOrgWidthOffset;// get the offset in x where the font shd be displayed so get it as the left padding

	if(nLeftPadding>0)
	{
		U64		nNewChar;
		if(nSize%8) nPadding = 8-(nSize%8);  /* pPadding is bit count of need left moving . */
		if(m_nWidth%8) nTempPadding = 8-(m_nWidth%8);
		for( nCount = 0;nCount<m_nCurrCharHt;++nCount)
		{
			nNewChar = pStream[nCount]>>nPadding;
			nNewChar = ReverseBitOrdering(nNewChar,nSize);

			pStream[nCount] = nNewChar<<nLeftPadding;
			nNewChar = ReverseBitOrdering(pStream[nCount],m_nWidth);
			pStream[nCount] = nNewChar<<nTempPadding;
		}
        nSize = m_nWidth;               /*  nSize is font real width */
        m_nCurrCharWidth = m_nWidth;    /* m_nCurrCharWidth is font real width */
	}

	if(nSize%8)    /* nSize == font real width */
		nPadding = 8-(nSize%8);
	else
		nPadding = 0;

	int	nHeightOffset = m_nOrgHtOffset+m_nBBoy+m_nCurrCharHt;
	nHeightOffset = m_nHeight-nHeightOffset;
    if(IsUseHWFontCompression())
    {
        int tempSize = m_nCurrCharWidth / 8;
        if(m_nCurrCharWidth % 8)
        {
            tempSize++;
        }
        nIndex += tempSize * nHeightOffset;
    }
    else
    {
        if(nHeightOffset>0)
        {
            int nNoOfU8s = nHeightOffset*(nSize);
            unsigned short nU8s  = nNoOfU8s/8;
            nIndex+= nU8s;
            nBitsCopied = nNoOfU8s%8;
        } 
    }


	for( nCount = 0;nCount<m_nCurrCharHt;++nCount)
	{
		nSourceBitsCopied = 0;
		nCurrent = pStream[nCount];
        
        /* For hardware compression, it hope we pass integrated byte, and glyph should start from left. */
        if(!IsUseHWFontCompression())
        {
		    nCurrent=nCurrent>>nPadding;     /* this sentence remove font right blank byte.  */
        }
        if(!IsUseHWFontCompression())   /* Reverse font */  
        {
            nCurrent=ReverseBitOrdering(nCurrent,nSize);      /* Reverse font */ 
        }
		nMask = nCOUNT<<nSourceBitsCopied;    /* nMask note which bit is copied currently */

        /* For hardware compression, it hope we pass integrated byte, and glyph should start from left. */
        if(IsUseHWFontCompression())
        {
            int tempSize = m_nCurrCharWidth / 8;
            int i = 0;
            if(m_nCurrCharWidth % 8)
            {
                tempSize++;
            }
            m_nCurrCharWidth = tempSize * 8;
            
            U8 * pdata = (U8 *)&pStream[nCount];
            for(i = 0; i < tempSize; i++)
            {
                pMMIFont->pFontData[nIndex + i] = pdata[i];
            }
            nIndex += tempSize;
        }
        else
        {
		    for(int nWidth = 0;nWidth<m_nCurrCharWidth;++nWidth)
		    {
			    bU8 = (nCurrent)&nMask;    /* the bit value, get each bit of width data */
			    bU8 > 0? bU8=0x01:bU8 = 0x00;

			    bU8 = bU8<<nBitsCopied;       /*Adjust to filled bit position. */
			    nTemp = (unsigned char)bU8;
			    pMMIFont->pFontData[nIndex]|=(unsigned char)nTemp;
			    ++nBitsCopied;          /* Note the count of current font data byte bit */
			    ++nSourceBitsCopied;    /* Note the count of current width bit */
			    nMask = nMask<<1;
			    if(nBitsCopied>=8)
			    {
				    ++nIndex;

				    nCurrent = pStream[nCount];
				        
                    if(!IsUseHWFontCompression())
                    {                
                        nCurrent=nCurrent>>nPadding;             
				        nCurrent=ReverseBitOrdering(nCurrent,nSize);
                    }
				    nMask=	nCOUNT<<nSourceBitsCopied;
				    nLeftshift = 0;
				    nBitsCopied = 0;
			    }
		    }
            if(IsUseHWFontCompression())
            {
            }
            else if(nBitsCopied>=8)
    		{
    			++nIndex;
    			nCurrent = pStream[nCount];
    			nCurrent=nCurrent>>nPadding;
                if(!IsUseHWFontCompression())
                {
    			    nCurrent=ReverseBitOrdering(nCurrent,nSize);
                }
    			nBitsCopied = 0;
    			nMask=	nCOUNT<<nSourceBitsCopied;
    		}
	    }
		
	}
}


/*****************************************************************************
 * FUNCTION
 *  ReverseBitOrdering
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  nNumber [IN]
 *  nSize [IN]
 * RETURNS
 *  int
******************************************************************************/
U64 CBdfOperation::ReverseBitOrdering(U64 nNumber, int nSize)
{
	U64		nNewNo			=	1;
	U64		nRightMask	=	nNewNo;
	U64		nLeftMask	=(U64)(nNewNo<<(nSize-1));
	
	nNewNo=0;
	
	U64	nTempNo1	=	0;
	U64	nTempNo2	=	0;
	unsigned long	nShift			=	nSize-1;

	if(nNumber)
	{
		for(U16 nCount =0;nCount<nSize/2;++nCount)
		{
			nTempNo1 = nNumber&nRightMask;
			nTempNo2 = nNumber&nLeftMask;

			nTempNo1 =nTempNo1<<nShift;
			nTempNo2 =nTempNo2>>nShift;
			nTempNo1 = nTempNo1|nTempNo2;
			nNewNo = nNewNo|nTempNo1;
			nShift-=2;
			nRightMask=nRightMask<<1;
			nLeftMask = nLeftMask>>1;
		}
		if(nSize%2)
		{
			nTempNo1 = nNumber&nRightMask;
			nNewNo = nNewNo|nTempNo1;
		}
	}

	return nNewNo;
}


