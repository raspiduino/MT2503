#include "stdafx.h"
#include "FontClass.h"
#include "assert.h"
#include "FontHWCompress.h"
#include "zlib.h"


#ifdef    TEST_DECODE
#pragma comment(lib, "BFDec.lib")
#include "bmp_font_decode.h"

char *glyph_buffer = NULL;
#endif


FontEngine::~FontEngine()
{
    if(m_bdf_parser != NULL)
    {
        delete m_bdf_parser;
    }
    if(m_file_gen != NULL)
    {
        delete m_file_gen;
    }

    vector<sMCTCustFontData> *pvctr = &m_fontdata_list; 
    vector<sMCTCustFontData>::iterator it;
    for ( it = pvctr->begin(); it < pvctr->end(); it++)
    {
        if(it->pWidthArray != NULL)
            delete[] it->pWidthArray;
        if(it->pWidthArray != NULL)
            delete[] it->pDWidthArray;

        if(it->pOffsetArray != NULL)
            delete[] it->pOffsetArray;

        if(it->pDataArray != NULL)
            delete[] it->pDataArray;

        if(it->pRange != NULL)
            delete[] it->pRange;
        if(it->pRangeDetails != NULL)
        {
            if(it->pRangeDetails->pRangeData != NULL)
            {
                delete[] it->pRangeDetails->pRangeData;
            }
            if(it->pRangeDetails->pGroupData != NULL)
            {
                delete[] it->pRangeDetails->pGroupData;
            }
            delete it->pRangeDetails;
        }
        if(it->pUnicodeData != NULL)
            delete[] it->pUnicodeData;  
        if(it->pBBX1 != NULL)
            delete[] it->pBBX1;
        if(it->pBBX2 != NULL)
            delete[] it->pBBX2;
        if(it->pBBX3 != NULL)
            delete[] it->pBBX3;
        if(it->pBBX4 != NULL)
            delete[] it->pBBX4;

        if(it->pDataArrayCompression != NULL)
            delete[] it->pDataArrayCompression;
        if(it->pBlockIndexArrayCompression != NULL) 
            delete[] it->pBlockIndexArrayCompression;
        
        if(IsUseHWFontCompression())
        {
            if(it->pHWCompressionData != NULL)
            {
                delete[] it->pHWCompressionData;
            }
            if(it->pHWCompressionDataOffset != NULL)
            {
                delete[] it->pHWCompressionDataOffset;
            }
        }
    }
    
}



/*****************************************************************************
 * FUNCTION
 *  AddNewLanguage
 * DESCRIPTION
 *  This function is used to make ready to input or add the language to list.
 * PARAMETERS
 *  NONE
 * RETURNS
 *  addfont(, , , ,,);
******************************************************************************/
void FontEngine::AddNewLanguage(string *language_name, string *str_langid, string *str_code)
{

/*
	CString csSpecialChars(_T("~!@#$%^&*()-+=\\|{[}]:\";'<>,.?/ `"));

	if (bdf_filename->findoneOf(csSpecialChars)!=-1)
	{
		MessageBox(_T("Special characters are not allowed!"),_T("Font Customizer"),MB_ICONWARNING);
		return;
	}	 
*/	
	if (language_name->length() > 29)
	{
		//MessageBox(_T("The name is too long!"),_T("Font Customizer"),MB_ICONWARNING);
		return;
	}
/*
	if(CheckIfExist(str_langname))
	{
		MessageBox(_T("The name Already Exists!"),_T("Font Customizer"),MB_ICONWARNING);
		return;
	}
*/
	CreateLanguage(language_name);

    strcpy((char *)m_pstruCurrMctLangNode->language.name ,language_name->c_str());
    strcpy((char *)m_pstruCurrMctLangNode->language.aLangSSC, str_langid->c_str());
    strcpy((char *)m_pstruCurrMctLangNode->language.nLangCountryCode ,str_code->c_str());

}

/*****************************************************************************
 * FUNCTION
 *  CreateLanguage
 * DESCRIPTION
 *  This function is used to create the new language and insert to the language list.
 * PARAMETERS
 *  langName [IN]
 * RETURNS
 *  
******************************************************************************/
void FontEngine::CreateLanguage(string *langName)
{
 
	U8 wt_langname[MCT_LANGUAGE_NAME] = {0};
    //convert the char to wide char
    mbstowcs((wchar_t*)wt_langname, langName->c_str(), 2 * strlen(langName->c_str()));

	sMCTLanguageList *newMctLang = m_pstruMctLangList;  
    
	while(newMctLang != NULL)
	{
        if(wcscmp((wchar_t *)newMctLang->language.name, (wchar_t *)wt_langname) == 0)
        {
            return ;
        }
        newMctLang = newMctLang->next;
	}
    
	newMctLang = new sMCTLanguageList;
	
	memset((wchar_t *)newMctLang->language.name,0,MCT_LANGUAGE_NAME);
	memset((wchar_t *)newMctLang->language.aLangSSC,0,MCT_SSC_SIZE);
	wcsncpy((wchar_t *)newMctLang->language.name, (wchar_t *)wt_langname, wcslen((wchar_t *)wt_langname));	
	
	newMctLang->next = NULL;
	if (m_pstruMctLangList == NULL)
	{
		newMctLang->previous = NULL;
		m_pstruMctLangList = newMctLang;
		m_pstruCurrMctLangNode = m_pstruMctLangList;
		m_pstruLastMctLangNode = m_pstruMctLangList;
	} 
	else 
	{
		newMctLang->previous = m_pstruLastMctLangNode;
		m_pstruLastMctLangNode->next = newMctLang;
		m_pstruLastMctLangNode = newMctLang;
		m_pstruCurrMctLangNode = newMctLang;
	}
}

/****************************************************************************
 * FUNCTION
 *  GetLanguageNodeByName
 * DESCRIPTION
 *  This function is used to find the language in language list by language name.
 * PARAMETERS
 *  *langname [IN]
 * RETURNS
 *  sMCTLanguageList
******************************************************************************/
sMCTLanguageList * FontEngine::GetLanguageNodeByName(U8 *langname)
{
    sMCTLanguageList *langlist;
	langlist = m_pstruMctLangList;

	while(langlist != NULL)
	{
		if(!wcscmp((wchar_t *)langlist->language.name, (wchar_t *)langname))
		{
			return langlist;
		}
		langlist = langlist->next;
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
U8 FontEngine::GetLanguageCount()
{
    U8 language_count = 0;
    sMCTLanguageList *langlist;
	langlist = m_pstruMctLangList;

	while(langlist != NULL)
	{
        language_count++;
		langlist = langlist->next; 
	}
	return language_count;
}

/*****************************************************************************
 * FUNCTION
 *  LanguageIsAdded
 * DESCRIPTION
 *  This function is used to find the language in language list by language name.
 * PARAMETERS
 *  *langname [IN]
 * RETURNS
 *  sMCTLanguageList
******************************************************************************/
bool FontEngine::LanguageIsAdded(U8 *langname)
{
    if(GetLanguageNodeByName(langname) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ParserBDFFile
 * DESCRIPTION
 *  This function is used to find the language in language list by language name.
 * PARAMETERS
 *  *langname [IN]
 * RETURNS
 *  sMCTLanguageList
******************************************************************************/
bool FontEngine::ParserBDFFile(sMCTCustFontData *font_data)
{
    return (this->m_bdf_parser->LoadBDFFile(font_data));
}


/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
const FontData_Info* FontEngine::FontDataIsAdded(string *strFilePath)
{
    if(strFilePath != NULL)
    {
        for(int i = 0; i < MCT_MAX_FONT_TYPES; i++)
        {
            vector<FontData_Info> *pvctr = &(m_font_family[i].fontData_contain); 
            vector<FontData_Info>::iterator it;
            for ( it = pvctr->begin(); it < pvctr->end(); it++)
            {
                if(it->strFilePath == *strFilePath)
                {
                    return &(*it);
                }
            }
        } 
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  FontDataIsAdded
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
const FontData_Info* FontEngine::FontDataIsAdded(sMCTCustFontData *font_data)
{
    if(font_data != NULL)
    {
        return FontDataIsAdded(&(font_data->strFilePath));
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
const FontData_Info* FontEngine::FontDataIsAdded(sMCTCustFontData *font_data, U8 font_size)
{
    if(font_data != NULL)
    {
        vector<FontData_Info> *pvctr = &(m_font_family[font_size].fontData_contain); 
        vector<FontData_Info>::iterator it;
        for ( it = pvctr->begin(); it < pvctr->end(); it++)
        {
            if(it->strFilePath == font_data->strFilePath)
            {
                return &(*it);
            }
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
void FontEngine::SetFontDataInfo(sMCTCustFontData *font_data, const FontData_Info *font_info)
{
    if((font_data != NULL) && (font_info != NULL))
    {
        font_data->strFilePath = font_info->strFilePath; 
        font_data->strfilename = font_info->strfilename; 
        font_data->gen_hfile_name = font_info->gen_hfile_name; 
        font_data->font_size = font_info->font_size;
        strcpy((char *)font_data->name, font_info->font_data_name.c_str());    
    }
}


/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
U8 FontEngine::CompareInFontFamily(vector<FontData_Info>::iterator &it)
{
    for(int i = 0; i < MCT_MAX_FONT_TYPES; i++)
    {
        vector<FontData_Info> *pvctr = &(m_font_family[i].fontData_contain); 
        vector<FontData_Info>::iterator array_it;
        for ( array_it = pvctr->begin(); array_it < pvctr->end(); array_it++)
        {
            if(it == array_it)
            {
                continue;
            }
            if((it->strFilePath == array_it->strFilePath) && (it->font_size == array_it->font_size))
            {
                assert(0);
            }
            else if((it->strFilePath == array_it->strFilePath))
            {
                if(it->font_size < array_it->font_size)
                {
                    return 1;
                }
                else if(it->font_size > array_it->font_size)
                {
                    return 2;   
                }
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
void FontEngine::AddNewFontData(sMCTCustFontData *font_data, U8 font_size)
{
    vector<FontData_Info> *pvctr = &(m_font_family[font_size].fontData_contain); 
    const FontData_Info *p_font_data = NULL;
    FontData_Info font_data_info;
    
    /* Check whether this font is added in same font size list. */
    if((p_font_data = FontDataIsAdded(font_data, font_size)) == NULL)
    {
        font_data_info.font_data_name = string((char *)font_data->name);
        font_data_info.font_size = font_size;
        font_data_info.strFilePath = font_data->strFilePath;
        font_data_info.strfilename = font_data->strfilename;
        font_data_info.gen_hfile_name = font_data->gen_hfile_name; 
        pvctr->push_back(font_data_info);
        m_font_family[font_size].nTotalFonts ++;
        return;
    }
}



/*****************************************************************************
 * FUNCTION
 *  AddNewFontData
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
void FontEngine::AddFontDataToList(sMCTCustFontData *font_data)
{
    m_fontdata_list.push_back(*font_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
void FontEngine::GenerateFontResFile()
{
    m_file_gen->GenerateFontResFile(this);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
bool FontEngine::GenerateFontDataFile()
{
    vector<sMCTCustFontData> *pvctr = &m_fontdata_list; 
    vector<sMCTCustFontData>::iterator it;
    for ( it = pvctr->begin(); it < pvctr->end(); it++)
    {
        if(m_file_gen->GenerateFontDataFile(&(*it)) == false)
        {
            return false;   
        }
    }
    return true;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
bool FontEngine::SetLanguageWithFontData(string *contry_code,  const sMCTCustFontData *font_data)
{
    vector<sMCTCustFontData> *pvctr = &m_fontdata_list; 
    vector<sMCTCustFontData>::iterator it;
    for ( it = pvctr->begin(); it < pvctr->end(); it++)
    {
        if(it->strFilePath == font_data->strFilePath)
        {
            int i = 0;
            for(i = 0; i < sizeof(mtk_gLanguageArray) / sizeof(sMCTLanguageDetails); i++)
            {
                if(strcmp(contry_code->c_str(), (char *)mtk_gLanguageArray[i].nLangCountryCode) == 0)
                {
                    it->Language_flags |= (1 << i); 
                    return true;
                }
            } 
        }
    }
    return false;
}


U8* reverseDataOrder(U8  *pData,
                     int width,
                     int height)
{
    static int size  = 0;
    static U8  *pWork = NULL;

    U8  *pSrc;
    U8  *pDst;
    int pitch;
    int xIndex;
    int yIndex;

    pitch = ((width + 7) & ~7) / 8;

    if (size < (pitch * height))
    {
        if (NULL != pWork)
        {
            free(pWork);
            pWork = NULL;
        }
        pWork = (U8*)malloc(pitch * height);
        size  = pitch * height;
    }

    if (pWork != NULL)
    {
        memset(pWork, 0x0, size);
    }
    else
    {
        return NULL;
    }

    for (yIndex = 0; yIndex < height; yIndex++)
    {
        pSrc = &(pData[pitch * yIndex]);
        pDst = &(pWork[pitch * yIndex]);
        for (xIndex = 0; xIndex < pitch; xIndex++)
        {
            pDst[xIndex] = pSrc[pitch - xIndex - 1];
        }
    }

    return pWork;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
******************************************************************************/
bool FontEngine::GenerateHWCompressionData()
{
    vector<sMCTCustFontData> *pvctr = &m_fontdata_list; 
    vector<sMCTCustFontData>::iterator it;
    int glyph_index = 0;

    if(IsUseHWFontCompression())
    {
        for (it = pvctr->begin(); it < pvctr->end(); it++)
        {
            glyph_index = 0;
            for(glyph_index = 0; glyph_index < it->m_nTotalChars; glyph_index++)
            {
            	U8* pReal;
             	pReal = reverseDataOrder(&it->pDataArray[it->pOffsetArray[glyph_index]],
                                          it->pWidthArray[glyph_index],
                                          it->nHeight);
                bfEncGenProfileInfo(&g_encoder,
                            pReal,
                            it->pWidthArray[glyph_index],
                            it->nHeight);
            }
        }
        for (it = pvctr->begin(); it < pvctr->end(); it++)
        {
            int out_len = 0;
            int datalength = it->pOffsetArray[it->m_nTotalChars];
            unsigned long destlen = it->nSize;
            int result = -100;
            U8* pReal;
            for(glyph_index = 0; glyph_index < it->m_nTotalChars; glyph_index++)
            {
                 pReal = reverseDataOrder(&it->pDataArray[it->pOffsetArray[glyph_index]],
                                          it->pWidthArray[glyph_index],
                                          it->nHeight);
                 bfEncEncodeGlyph(&g_encoder, 
                            pReal,
                            it->pWidthArray[glyph_index],
                            it->nHeight, 
                            &(it->pHWCompressionData[it->nHWCompressionDataSize]), 
                            255,
                            &out_len);
                 
                /* pMMIFont->pHWCompressionDataOffset[0] = 0; */
                it->pHWCompressionDataOffset[glyph_index] = it->nHWCompressionDataSize;
                it->nHWCompressionDataSize += out_len; 
                it->pHWCompressionDataOffset[glyph_index + 1] = it->nHWCompressionDataSize;
            }
            
            memset(it->pDataArray, 0, datalength);
            memset(it->pOffsetArray, 0, sizeof(U32*) * (it->m_nTotalChars + 1));

            datalength = it->pHWCompressionDataOffset[it->m_nTotalChars];
        
            it->nDataArraySize  = datalength;
               
            memcpy(it->pDataArray, it->pHWCompressionData, datalength);
            memcpy(it->pOffsetArray, it->pHWCompressionDataOffset, sizeof(U32*) * (it->m_nTotalChars + 1));

            for(glyph_index = 0; glyph_index < it->m_nTotalChars; glyph_index++)
            {
                /* Start from 1 */
                it->pBlockIndexArrayCompression[it->nBlockIndexArrayCompressionSize] = glyph_index + 1;

                if(it->pOffsetArray[glyph_index+1] >= FONT_ENGINE_DATA_BLOCK_SIZE * (it->nBlockIndexArrayCompressionSize+1) && (glyph_index + 1) != it->m_nTotalChars)
                { 
                    it->nBlockIndexArrayCompressionSize++;
                }
            }
            
            if(IsUseFontCompression())
            {
               	result = compress2(it->pDataArrayCompression, &destlen, it->pDataArray, datalength, Z_BEST_COMPRESSION); 	
            	it->nDataArrayCompressionSize = destlen;
            }
            else if(IsUseFontGroupCompression())
            {
            	it->nDataArrayCompressionSize = it->nDataArraySize;
                it->pRangeDetails->nNoOfGroup = FontLzmaGroupSplitter(it->pDataArray, it->pOffsetArray, it->m_nTotalChars, it->pDataArrayCompression, &datalength, it->pRangeDetails->pGroupData);
                memset(it->pDataArray, 0, datalength);
                memcpy(it->pDataArray, it->pDataArrayCompression, datalength);
                it->nDataArraySize  = datalength;
            }
        
        }

        FontHWCompressQueryDictionary(&g_encoder,
                        &LV1Size, &LV2Size,
                        &LV1Dict1, &LV1Dict2); 


#ifdef    TEST_DECODE
    S32 x_offset = 0, y_offset = 0;

	glyph_buffer = (char *)malloc(1024 * 1024 * sizeof(short));
	
    BF_DEC_STRUCT  g_decoder;
    bfDecInitDecoder(&g_decoder);
    bfDecSetDictionary(&g_decoder, &LV1Dict1, &LV1Dict2);

	bfDecSetAttribute(&g_decoder, BF_DEC_STYLE_NORMAL, 0xFFFF, 0xF800);

    bfDecSetCanvas(&g_decoder,
                    glyph_buffer,
                    1024,
                    2048,
                    1024,
                    BF_DEC_RGB_FORMAT_RGB565);


    for (it = pvctr->begin(); it < pvctr->end(); it++)
    {
        x_offset = 10;
        y_offset = 10;
        memset(glyph_buffer, 0x0, 1024 * 1024 * 2);
        for(glyph_index = 0; glyph_index < it->m_nTotalChars; glyph_index++)
        {
            bfDecDrawGlyph(&g_decoder, 
                &(it->pHWCompressionData[it->pHWCompressionDataOffset[glyph_index]]),
                it->pWidthArray[glyph_index], it->nHeight, 
                x_offset, y_offset);
			x_offset += it->pWidthArray[glyph_index] + 10;
			if(x_offset >= 1000)
			{
				y_offset += 50;
				x_offset = 10;
			}
			if (y_offset >= 1000)
            {
				break;
            }
        }
        {
            FILE *pFile;
            string str;
            str = str + (char *)it->fontDataName + "testResult.bin";
            pFile = fopen(str.c_str(), "wb");

            fwrite(glyph_buffer, 1024 * 1024 * 2, 1, pFile);

            fclose(pFile);
        }
    }
    
#endif

    }
    else
    {
        for (it = pvctr->begin(); it < pvctr->end(); it++)
        {
            int datalength = it->pOffsetArray[it->m_nTotalChars];
            unsigned long destlen = it->nSize;
            int result = -100;
            
            for(glyph_index = 0; glyph_index < it->m_nTotalChars; glyph_index++)
            {
                /* Start from 1 */
                it->pBlockIndexArrayCompression[it->nBlockIndexArrayCompressionSize] = glyph_index + 1;

                if(it->pOffsetArray[glyph_index+1] >= FONT_ENGINE_DATA_BLOCK_SIZE * (it->nBlockIndexArrayCompressionSize+1) )
                { 
                    it->nBlockIndexArrayCompressionSize++;
                }
            }
            
            if(IsUseFontCompression())
            {
               	result = compress2(it->pDataArrayCompression, &destlen, it->pDataArray, datalength, Z_BEST_COMPRESSION); 	
            	it->nDataArrayCompressionSize = destlen;
            } 
        }
    }
    
   return true;
}

