#include "stdafx.h"
#include "FontResFile.h"
#include "FontClass.h"
#include "FontHWCompress.h"




/*****************************************************************************
 * FUNCTION
 *  font_16HexStringToInt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
int font_16HexStringToInt(string *str)
{
    string hexstr = *str;
    char num = 0;
    int res = 0;
    int bit = 1;
    for(int i = hexstr.length() - 1; i >= 0; i--)
    {
        if((hexstr[i] >= '0') && (hexstr[i] <= '9'))
        {
            num = hexstr[i] - '0';
        }
        else if((hexstr[i] >= 'A') && (hexstr[i] <= 'F'))
        {
            num = hexstr[i] - 'A' + 10;
        }
        else if((hexstr[i] >= 'a') && (hexstr[i] <= 'f'))
        {
            num = hexstr[i] - 'a' + 10;
        }
        else
        {
            return 0;
        }
        res = res + num * bit;
        bit = bit * 16;
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  font_AddLanguageFlagToString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool font_AddLanguageFlagToString(string * str, char lang_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    string hexstr;
    char temp[9] = {0};
    int num = font_16HexStringToInt(&hexstr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(((*str)[0] == '0') && (((*str)[1] == 'x') || ((*str)[1] == 'X')))
    {
       hexstr = str->substr(2);
    }

    num |= (1 << (lang_flag - 1));
    sprintf(temp, "0X%08X", num);
    *str = (char *)temp;
    return true;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontResFile
 * DESCRIPTION
 *  This function is used to create FontRes.c file.
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
void FontGenFile::GenerateFontResFile(FontEngine *font_engine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    string str;
    char cTemp[100] ={0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(pFile = fopen(string(m_outputPath + ("\\") + FONT_RES_FILENAME).c_str(), ("w")))
	{	
		fputs(_T("#include \"FontRes.h\"\n"),pFile);
		fputs(_T("#include \"MMI_features.h\"\n"),pFile);
		fputs(_T("#include \"vector_font_lang_memory_card_config.h\"\n"),pFile);
		
		fputs(_T("\n#ifndef NULL\n"),pFile);
		fputs(_T("#define NULL  (void *)0           /*  NULL    :   Null pointer */\n"),pFile);
		fputs(_T("#endif\n"),pFile);
		
    	fputs(_T("\n#ifdef  __IOT__\n"), pFile);

		fputs(_T("\n#define  MAX_LANGUAGES     1\n"), pFile);

    	fputs(_T("\n#else\n"), pFile);

		fputs(_T("\n#define  MAX_LANGUAGES     30\n"), pFile);

     
		/* include font data file */
        if(font_engine != NULL)
        {
            for(int i = 0; i < MCT_MAX_FONT_TYPES; i++)
            {
                vector<FontData_Info> *pvctr = &(font_engine->m_font_family[i].fontData_contain); 
                vector<FontData_Info>::iterator it;
                for (it = pvctr->begin(); it < pvctr->end(); it++)
                {
                    if(font_engine->CompareInFontFamily(it) != 2)
                    {
                        fputs("\n#include \"", pFile);
                        fputs(it->gen_hfile_name.c_str(), pFile);
                        fputs("\"", pFile);
                    }
                }
            } 
        }

        fputs("\n", pFile);
        GenerateFontResFile_GroupData(font_engine, pFile);

        sprintf(cTemp, "\nconst U8 g_fontfamily_count = %d ;\n", MCT_MAX_FONT_TYPES);
        str = (char *)cTemp;
        fputs(cTemp,pFile);
            
	    fputs(("\n"),pFile);	

        if(IsUseFontCompression())
        {
            GenerateCompressionInfo(font_engine, pFile);
        }

        if(IsUseHWFontCompression()) 
        {
            FontHWCompressWriteLVTableToFile(pFile,
                                LV1Size, LV2Size,
                                &LV1Dict1, &LV1Dict2,
                                lv1_table_name,
                                lv2_table_name); 
        }
        
    	fputs(_T("\n#endif  /*__IOT__*/\n"), pFile);

        GenerateFontResLanguageTable(&string(""), pFile);

        fclose(pFile);
        
	}
	
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontResFile
 * DESCRIPTION
 *  This function is used to create FontRes.c file.
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
void FontGenFile::GenFontGroupString(FontEngine *font_engine, U8 font_size, FILE *p_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    string str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    font_group_struct *pgroup = &(font_engine->m_font_family[font_size]);
    if(pgroup->nTotalFonts == 0)
    {
        str = "NULL\n";
        fputs(str.c_str(), p_file);
    }
    else
    {
        for(int i = 0; i < pgroup->nTotalFonts; i++)
        {
            str = "&" + pgroup->fontData_contain[i].font_data_name;
            if(i != pgroup->nTotalFonts - 1)
            {
                str += ",\n";
            }
            else
            {
                str += "\n";
            }
                fputs(str.c_str(), p_file);
        }
    }

     
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontResFile
 * DESCRIPTION
 *  This function is used to create FontRes.c file.
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
void FontGenFile::GenerateFontResFile_GroupData(FontEngine *font_engine, FILE *pFile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char cTemp[100] = {0};
    int i = 0;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MCT_MAX_FONT_TYPES; i++)
    {    
        fputs(("\n"),pFile);
        switch(i)
        {
            case MCT_ALPHA_SMALL_FONT:
            {
                fputs(("const sCustFontData * const g_small_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile); 
                break;
            }
            case MCT_ALPHA_MEDIUM_FONT:
            {
                fputs(("const sCustFontData * const g_medium_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile);  
                break;
            }
            case MCT_ALPHA_LARGE_FONT:
            {
                fputs(("const sCustFontData * const g_large_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile); 
                break;
                
            }
            case MCT_ALPHA_SUBLCD_FONT:
            {
                fputs(("const sCustFontData * const g_sublcd_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile); 
                break;
            }
            case MCT_ALPHA_DIALER_FONT:
            {
                fputs(("const sCustFontData * const g_dialling_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile);  
                break;
            }
            case MCT_ALPHA_NUMBER1_FONT:
            {
                fputs(("const sCustFontData * const g_number1_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile);  
                break;
            }
            case MCT_ALPHA_NUMBER2_FONT:
            {
                fputs(("const sCustFontData * const g_number2_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile);  
                break;
            }
            case MCT_ALPHA_TOUCH_SCREEN_FONT:
            {
                fputs(("const sCustFontData * const g_touchscreen_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile); 
                break;
            }
            case MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT:
            {
                fputs(("const sCustFontData * const g_touchscreen_large_font_data_array[] = {\n"),pFile);
                GenFontGroupString(font_engine, i, pFile);
                fputs(("}; \n"),pFile);  
                break;
            }
                                                                        
        }
        
    }
    
    fputs(("\nconst font_group_struct g_fontfamily[MAX_FONT_SIZE] = {\n"),pFile);
    for(i = 0; i < MCT_MAX_FONT_TYPES; i++)
    {
        switch(i)
        {
            case MCT_ALPHA_SMALL_FONT:
            {
                sprintf((char *)cTemp, "{%d, g_small_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
            case MCT_ALPHA_MEDIUM_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_medium_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
            case MCT_ALPHA_LARGE_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_large_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
                
            }
            case MCT_ALPHA_SUBLCD_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_sublcd_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
            case MCT_ALPHA_DIALER_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_dialling_font_data_array},", font_engine->m_font_family[i].nTotalFonts);  
                break;
            }
            case MCT_ALPHA_NUMBER1_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_number1_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
            case MCT_ALPHA_NUMBER2_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_number2_font_data_array},", font_engine->m_font_family[i].nTotalFonts);  
                break;
            }
            case MCT_ALPHA_TOUCH_SCREEN_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_touchscreen_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
            case MCT_ALPHA_TOUCH_SCREEN_LAREG_FONT:
            {
                fputs(("\n"),pFile); 
                sprintf((char *)cTemp, "{%d, g_touchscreen_large_font_data_array},", font_engine->m_font_family[i].nTotalFonts);
                break;
            }
        }     
        fputs(cTemp, pFile);
    }
    fputs(("\n};"),pFile);    
         
}

/*****************************************************************************
 * FUNCTION
 *  GenerateCompressionInfo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool FontGenFile::GenerateCompressionInfo(FontEngine *font_engine, FILE *pFile)
{
    FILE *compress_info_file = NULL;
    char	temp[100] = {0};
    
    if(IsUseFontCompression())
    {
        if(compress_info_file = fopen(string(font_engine->m_outputPath + "\\" +  FONT_COMPRESSION_INFO_NAME).c_str(), ("r")))
        {
            fprintf(pFile,_T("\n\n#if defined(__MMI_FONT_COMPRESSION__)"));
            fputs(_T("\nconst mmi_font_compress_info mtk_font_compress_info[] = {"),pFile);
            while ( fgets(temp, 100, compress_info_file ) != NULL)
            {
               fprintf(pFile,_T("%s"), temp);  
            }
            fprintf(pFile,_T("\n  {NULL, 0, NULL, 0}\n")); 
            fprintf(pFile, _T("};\n"));
            fprintf(pFile,_T("\n#endif\n"));
            fclose(compress_info_file);
            return true;
        } 
    }
    return false;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontDataFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool FontGenFile::GenerateFontDataFile(sMCTCustFontData *font_data)
{
    U32 iCount = 0;  
    FILE*		pFile = NULL;
    FILE* 		pFile_data = NULL;
    if((font_data == NULL))
    {
        return false;
    }
    if(pFile = fopen(string(m_outputPath + "\\" + font_data->gen_hfile_name).c_str(), ("w")))
    {
        
        if(IsUseFontCompression())
        {
            fprintf(pFile,_T("\n#if defined(__MMI_FONT_COMPRESSION__)\n"));

            if((font_data->nEquiDistant) == false)
            {                                
                /* font data width array */
                fprintf(pFile, _T("\nconst U8 %s[%ld]= {"),font_data->fontWidthName, font_data->m_nTotalChars);
                for( iCount = 0 ; iCount < font_data->m_nTotalChars; iCount++)
                { 
                    if (iCount%16 == 0)
                    {
                        fprintf(pFile, _T("\n"));
                    }    
                    fprintf(pFile, _T("0x%-2X,"), font_data->pWidthArray[iCount]);        
                }
                fprintf(pFile,_T("};\n"));
                
                /* font data Dwidth array */
                if(font_data->is_dwidth)
                {
                    fprintf(pFile, ("\nconst U8 %s[%ld]= {"), font_data->fontDWidthName,font_data->m_nTotalChars);
                    for( iCount = 0 ; iCount < font_data->m_nTotalChars; iCount++)
                    {
                        if (iCount%16 == 0)
                        {
                            fprintf(pFile, _T("\n"));               
                        }                    
                        fprintf(pFile, _T("0x%-2X,"), font_data->pDWidthArray[iCount]);        
                    }
                    fprintf(pFile,_T("};\n"));
                }

                /* font data index array (offset)  */
                fprintf(pFile, _T("\nconst U8 %s[%ld]= {"),font_data->fontOffsetName, font_data->m_nTotalChars + 1);
                for( iCount = 0 ; iCount < font_data->m_nTotalChars + 1; iCount++)
                {
                    if (iCount%16 == 0)
                    {
                       fprintf(pFile,_T("\n"));   
                    }  
                    
                    /* Split to several block per 64k, so adjust value data offset table.  */
                    char a[10];
                    int index_value = font_data->pOffsetArray[iCount];
                    index_value = index_value % FONT_ENGINE_DATA_BLOCK_SIZE;  
                    sprintf(a,_T("0x%02X,"), index_value);

                    fprintf(pFile, a);
                }
                fprintf(pFile,_T("};\n"));
                
            }

            /* range offset */
            fprintf(pFile, _T("\nconst U16 %s[%ld]= {"),
                                font_data->pRangeDetails->rangeOffsetName, 
                                font_data->pRangeDetails->nNoOfRanges);
             
            U32 tempvalue;
            for( iCount = 0 ; iCount < font_data->pRangeDetails->nNoOfRanges; iCount++)
            {
                if (iCount%16 == 0)
                {
                    fprintf(pFile, _T("\n"));     
                }                            
                char a[10];
                tempvalue = font_data->pRange[iCount];      
                sprintf(a,_T("%ld,"),  tempvalue);
                fprintf(pFile, a);
            }
            fprintf(pFile,_T("};\n"));  


            /* Font Data */           
            fprintf(pFile,_T("\nconst U8  %s[%ld]= {"), 
                font_data->fontCompressedDataName,
                font_data->nDataArrayCompressionSize);
            for( iCount = 0 ; iCount < font_data->nDataArrayCompressionSize; iCount++)
            {
                if (iCount%16 == 0)
                {
                    fprintf(pFile, ("\n"));  
                }
                fprintf(pFile, ("0x%X,"), font_data->pDataArrayCompression[iCount]);
            }
            fprintf(pFile, ("};\n"));

            fprintf(pFile,_T("\n#if !defined(__MMI_BDF_SW_COMPRESSION__) \n"));
            
            /* RangeBlockIndex */
            if(font_data->nEquiDistant == false)
            { 
                
                fprintf(pFile,_T("\nconst U16 %s[%ld]= {"),
                    font_data->pRangeDetails->fontRangeBlockIndexArrayName,
                    font_data->nBlockIndexArrayCompressionSize+1);
                //{264},       // <= how many character are involved in the block and its previous block
                for(iCount=0; iCount<= font_data->nBlockIndexArrayCompressionSize; iCount++)
                {
                    if(iCount%16 ==0)
                    {
                        fprintf(pFile, _T("\n")); 
                    }
                    fprintf(pFile, _T("%ld,"), font_data->pBlockIndexArrayCompression[iCount]);
                }
                fprintf(pFile,_T("\n};\n"));
            }
            
            /* mmi font range offset struct */
            fprintf(pFile, _T("\nconst mmi_font_range_offset_struct %s = {"),  
                  font_data->pRangeDetails->fontRangeOffsetStructName);
            
            
            if(font_data->nEquiDistant== false)
            {
                //1,           // <= how many block that the data is devided into blocks with size 64KB
                int block_number = font_data->nDataArraySize;
                if(block_number % FONT_ENGINE_DATA_BLOCK_SIZE)  
                {
                    block_number = block_number / FONT_ENGINE_DATA_BLOCK_SIZE + 1;                                    
                }
                else
                {
                    block_number = block_number / FONT_ENGINE_DATA_BLOCK_SIZE;
                }
                fprintf(pFile,_T("\n%d,\n"), block_number); 
                //2
                fprintf(pFile, _T("%s,\n"),font_data->pRangeDetails->fontRangeBlockIndexArrayName);    
            }
            else
            {
                fprintf(pFile,_T("\n0,\n"));
                fprintf(pFile,_T("NULL,\n"));
            }
            
            //3
            fprintf(pFile, _T("%s,\n"),font_data->pRangeDetails->rangeOffsetName);   
            fprintf(pFile,_T("};\n"));

            fprintf(pFile,_T("\n#endif  /* endif of  !defined(__MMI_BDF_SW_COMPRESSION__ */\n"));
            
            //empty array
            fprintf(pFile,_T("\nU8  %s[%ld];"), 
                font_data->fontDataName,
                font_data->nDataArraySize);  
           

            fprintf(pFile,_T("\n#else\n"));

        }

        /* uncompression data */

        if((font_data->nEquiDistant) == false)
        {                                
            /* font data width array */
            fprintf(pFile, _T("\nconst U8 %s[%ld]= {"),font_data->fontWidthName, font_data->m_nTotalChars);
            for( iCount = 0 ; iCount < font_data->m_nTotalChars; iCount++)
            { 
                if (iCount%16 == 0)
                {
                    fprintf(pFile, _T("\n"));
                }    
                fprintf(pFile, _T("0x%-2X,"), font_data->pWidthArray[iCount]);        
            }
            fprintf(pFile,_T("};\n"));
            
            /* font data Dwidth array */
            if(font_data->is_dwidth)
            {
                fprintf(pFile, ("\nconst U8 %s[%ld]= {"), font_data->fontDWidthName,font_data->m_nTotalChars);
                for( iCount = 0 ; iCount < font_data->m_nTotalChars; iCount++)
                {
                    if (iCount%16 == 0)
                    {
                        fprintf(pFile, _T("\n"));               
                    }                    
                    fprintf(pFile, _T("0x%-2X,"), font_data->pDWidthArray[iCount]);        
                }
                fprintf(pFile,_T("};\n"));
            }

        }

        /* If hardware compress, Data offset is necessary. */
        if(IsUseHWFontCompression())
        {
            /* font data index array (offset)  */
            fprintf(pFile,_T("\n#if defined(__MMI_BDF_SW_COMPRESSION__)\n"));
            
            fprintf(pFile, _T("\nconst U8 %s[%ld]= {"),font_data->fontOffsetName, font_data->m_nTotalChars + 1);
            for( iCount = 0 ; iCount < font_data->m_nTotalChars + 1; iCount++)
            {
                if (iCount%16 == 0)
                {
                   fprintf(pFile,_T("\n"));   
                }  
                
                /* Split to several block per 64k, so adjust value data offset table.  */
                char a[10];
                int index_value = font_data->pOffsetArray[iCount];
                index_value = index_value % FONT_ENGINE_DATA_BLOCK_SIZE;  
                sprintf(a,_T("0x%02X,"), index_value);

                fprintf(pFile, a);
            }
            fprintf(pFile,_T("};\n"));
            fprintf(pFile, "\n#endif\n");
        }
        else if(font_data->nEquiDistant == false)
        {
            /* font data index array (offset)  */
            fprintf(pFile, _T("\nconst U32 %s[%ld]= {"), font_data->fontOffsetName,  font_data->m_nTotalChars + 1);
            for( iCount = 0 ; iCount < font_data->m_nTotalChars+1; iCount++)
            {
                if (iCount%16 == 0)
                {
                    fprintf(pFile,_T("\n"));    
                }                             
                char a[10];
                sprintf(a, _T("0x%04X,"),  font_data->pOffsetArray[iCount]);
                fprintf(pFile, a);
            }
            fprintf(pFile,_T("};\n"));    
        }

        /* RangeOffset */
        fprintf(pFile, _T("\nconst U16 %s[%ld]= {"),
                            font_data->pRangeDetails->rangeOffsetName, 
                            font_data->pRangeDetails->nNoOfRanges);
        
        for( iCount = 0 ; iCount < font_data->pRangeDetails->nNoOfRanges; iCount++)
        {
            if (iCount%16 == 0)
            {
                fprintf(pFile, _T("\n"));  
            }
                                               
            char a[10];
            sprintf(a,_T("%ld,"),  font_data->pRange[iCount]);
            fprintf(pFile, a);
        }                
        fprintf(pFile,_T("};\n"));

        /* Font data */
		pFile_data = fopen(string(m_outputPath + ("\\") + FONT_DATA_FILENAME).c_str(), ("a"));
		if(IsUseFontGroupCompression())
		{
			fprintf(pFile,("\nextern const U8 %s[];\n"), font_data->fontDataName);
			if(pFile_data)
			{
				fprintf(pFile_data,("\nconst unsigned char %s[%ld]= {"), font_data->fontDataName,font_data->nDataArraySize);
		        for( iCount = 0 ; iCount < font_data->nDataArraySize; iCount++)
		        {
		            if (iCount%16 == 0)
		            {
		                fprintf(pFile_data, ("\n"));  
		            }
		            fprintf(pFile_data, _T("0x%X,"), font_data->pDataArray[iCount]);
		        }
		        fprintf(pFile_data, ("};\n"));
			}
		}
		else
		{
        fprintf(pFile,("\nconst U8  %s[%ld]= {"), font_data->fontDataName,font_data->nDataArraySize);
        for( iCount = 0 ; iCount < font_data->nDataArraySize; iCount++)
        {
            if (iCount%16 == 0)
            {
                fprintf(pFile, ("\n"));  
            }
            fprintf(pFile, _T("0x%X,"), font_data->pDataArray[iCount]);
        }
        fprintf(pFile, ("};\n"));   
		}
		if(pFile_data)
			fclose(pFile_data);

        if(IsUseFontCompression())
        {
             fprintf(pFile, "\n#endif\n");
        }

        if((IsUseFontCompression()) && (IsUseHWFontCompression()) && (font_data->nEquiDistant == true))
        {
            /* font data index array (offset)  */
            fprintf(pFile,_T("\n#if defined(__MMI_BDF_SW_COMPRESSION__)\n"));
            
            fprintf(pFile, _T("\nconst U8 %s[%ld]= {"),font_data->fontOffsetName, font_data->m_nTotalChars + 1);
            for( iCount = 0 ; iCount < font_data->m_nTotalChars + 1; iCount++)
            {
                if (iCount%16 == 0)
                {
                   fprintf(pFile,_T("\n"));   
                }  
                
                /* Split to several block per 64k, so adjust value data offset table.  */
                char a[10];
                int index_value = font_data->pOffsetArray[iCount];
                index_value = index_value % FONT_ENGINE_DATA_BLOCK_SIZE;  
                sprintf(a,_T("0x%02X,"), index_value);

                fprintf(pFile, a);
            }
            fprintf(pFile,_T("};\n"));
            fprintf(pFile, "\n#endif\n");
        }
        
        if(IsUseHWFontCompression())
        {
            fprintf(pFile,_T("\n#if defined(__MMI_BDF_SW_COMPRESSION__) \n"));
             /* RangeBlockIndex */
            fprintf(pFile,_T("\nconst U16 %s[%ld]= {"),
                font_data->pRangeDetails->fontRangeBlockIndexArrayName,
                font_data->nBlockIndexArrayCompressionSize+1);
            
            for(iCount=0; iCount<= font_data->nBlockIndexArrayCompressionSize; iCount++)
            {
                if(iCount%16 ==0)
                {
                    fprintf(pFile, _T("\n")); 
                }
                fprintf(pFile, _T("%ld,"), font_data->pBlockIndexArrayCompression[iCount]);
            }
            fprintf(pFile,_T("\n};\n"));
            
            /* compression range offset & block struct  */
            fprintf(pFile, _T("\nconst mmi_font_range_offset_struct %s = {"),  
                  font_data->pRangeDetails->fontRangeOffsetStructName);
           
            int block_number;

	    if(IsUseFontGroupCompression())
		block_number = font_data->nDataArrayCompressionSize;
	    else
		block_number = font_data->nDataArraySize;
			
            if(block_number % FONT_ENGINE_DATA_BLOCK_SIZE)  
            {
                block_number = block_number / FONT_ENGINE_DATA_BLOCK_SIZE + 1;                                    
            }
            else
            {
                block_number = block_number / FONT_ENGINE_DATA_BLOCK_SIZE;
            }
            fprintf(pFile,_T("\n%d,\n"), block_number); 
            //2
            fprintf(pFile, _T("%s,\n"),font_data->pRangeDetails->fontRangeBlockIndexArrayName);    

            fprintf(pFile, _T("%s,\n"),font_data->pRangeDetails->rangeOffsetName);   
            fprintf(pFile,_T("};\n"));

            fprintf(pFile, "#endif\n");  
        }
       
        /* Range Data and Range Details */
        GenerateFontResFile_RangeInfo(font_data, pFile);
        if(IsUseFontGroupCompression())
            GenerateFontResFile_GroupInfo(font_data, pFile);

        /* sCustFontData */
        if(IsUseFontCompression())
        {
            fprintf(pFile,_T("\n#if (defined(__MMI_FONT_COMPRESSION__) && !defined(__MMI_BDF_SW_COMPRESSION__)) \n"));
              
            GenerateFontResFile_CustFontData(font_data, pFile, 1);

            fprintf(pFile,_T("\n#else\n"));
        } 

        if(IsUseHWFontCompression())
        {
            GenerateFontResFile_CustFontData(font_data, pFile, 2);  
        }
        else
        {
            GenerateFontResFile_CustFontData(font_data, pFile, 0);  
        }
                            

        if(IsUseFontCompression())
        { 
            fprintf(pFile,_T("\n#endif\n"));
        } 
        
        /* Generate temp file for compression info file */
        if(IsUseFontCompression())
        {
            GenerateCompressionInfoFile(font_data);
        } 
        fclose(pFile); 
        return true;
    }
    return false;     
}


void FontGenFile::GenerateFontResFile_RangeInfo(sMCTCustFontData *font_data, FILE *p_file)
{
    /* Range data */
    fprintf(p_file, ("\nconst RangeData %s[%ld]={\n"), 
            font_data->pRangeDetails->rangeDataName, 
            font_data->pRangeDetails->nNoOfRanges);
        
    for(int k = 0; k < font_data->pRangeDetails->nNoOfRanges; k++ )
    {
        if(k%10==0 && k!=0)
        {
            fputs(_T("\n"), p_file);
        }
        fprintf(p_file,
            "{%ld,%ld},",
            font_data->pRangeDetails->pRangeData[k].nMin,
            font_data->pRangeDetails->pRangeData[k].nMax);
        
    }
    
    fputs(_T("};\n"),p_file);

    /* Range details */
    fprintf(p_file, _T("\nconst RangeDetails %s={\n%ld,\n%s\n};\n"), 
        font_data->pRangeDetails->rangeInfoName, 
        font_data->pRangeDetails->nNoOfRanges, 
        font_data->pRangeDetails->rangeDataName);
     
}


void FontGenFile::GenerateFontResFile_CustFontData(sMCTCustFontData *font_data, FILE *p_file, U8 compress_flag)
{

    /*  CustFontData  */
    fprintf(p_file, _T("\nconst sCustFontData %s = {\n"), font_data->name);
    
    /*  PLUTO_MMI  */
    fprintf(p_file, _T("%ld, %ld,\n#ifdef PLUTO_MMI\n%ld, %ld,\n#endif \n%ld, %ld, %ld,"),
        font_data->nHeight, font_data->nBoxMaxWidth,
        font_data->nAscent, font_data->nDescent,        //Ascent and Descent for baseline
        font_data->nEquiDistant, font_data->nCharBytes, font_data->nMaxChars);
    
    /*  PLUTO_MMI  */
    if(font_data->nEquiDistant == false)
    {
        if(font_data->is_dwidth)
        {
            fprintf(p_file, _T("\n(U8*)%s"), font_data->fontDWidthName);
        }
        else
        {
            fprintf(p_file, _T("\n(U8*)%s"), font_data->fontWidthName);
        }

        if(compress_flag)
        {
            fprintf(p_file, _T(", (U8*)%s, (U8*)%s, (U8*)%s, (mmi_font_range_offset_struct*)&%s,"), 
                font_data->fontWidthName, font_data->fontOffsetName, 
                font_data->fontDataName,  font_data->pRangeDetails->fontRangeOffsetStructName);
        }
        else
        {
            fprintf(p_file, _T(", (U8*)%s, (U32*)%s, (U8*)%s, (U16*)%s,"), 
                font_data->fontWidthName, font_data->fontOffsetName, 
                font_data->fontDataName,  font_data->pRangeDetails->rangeOffsetName);   
        }     
    }       
    else
    {
        if(compress_flag == 1)
        {
            fprintf(p_file, _T("\n(U8*)NULL, (U8*)NULL, (U8*)NULL, (U8*)%s, (mmi_font_range_offset_struct*)&%s,"),
                font_data->fontDataName, font_data->pRangeDetails->fontRangeOffsetStructName);
        }
        else if(compress_flag == 2)
        {
            /* Should add compile option. */
            fprintf(p_file, _T("\n(U8*)NULL, (U8*)NULL, (U8*)%s, (U8*)%s, (mmi_font_range_offset_struct*)&%s,"),
                font_data->fontOffsetName,
                font_data->fontDataName, font_data->pRangeDetails->fontRangeOffsetStructName);
        }
        else 
        {
            fprintf(p_file, _T("\n(U8*)NULL, (U8*)NULL, (U32*)NULL, (U8*)%s, (U16*)%s,"),
                font_data->fontDataName, font_data->pRangeDetails->rangeOffsetName);  
        }
    }    
    fprintf(p_file, ("\n&%s,"), font_data->pRangeDetails->rangeInfoName);
    
    if(IsUseFontGroupCompression())
        fprintf(p_file, ("\n&%s,"), font_data->pRangeDetails->groupInfoName);
    
    MapLanguageWithFontDataFile(font_data, p_file); 

    fprintf(p_file, "\n};\n\n");


}

void FontGenFile::GenerateFontResFile_GroupInfo(sMCTCustFontData *font_data, FILE *p_file)
{
    /* Range data */
    fprintf(p_file, ("\nconst GroupData %s[%ld]={\n"), 
            font_data->pRangeDetails->groupDataName, 
            font_data->pRangeDetails->nNoOfGroup);
        
    for(int k = 0; k < font_data->pRangeDetails->nNoOfGroup; k++ )
    {
        if(k%10==0 && k!=0)
        {
            fputs(_T("\n"), p_file);
        }
        fprintf(p_file,
            "{%ld,%ld},",
            font_data->pRangeDetails->pGroupData[k].nOffset,
            font_data->pRangeDetails->pGroupData[k].nSize);
        
    }
    
    fputs(_T("};\n"),p_file);

    /* Range details */
    fprintf(p_file, _T("\nconst GroupDetails %s={\n%ld,\n%s\n};\n"), 
        font_data->pRangeDetails->groupInfoName, 
        font_data->pRangeDetails->nNoOfGroup, 
        font_data->pRangeDetails->groupDataName);
     
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontDataFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool FontGenFile::GenerateCompressionInfoFile(sMCTCustFontData *font_data)
{
    U32 iCount = 0;  
    FILE*		pFile = NULL;
    if((font_data == NULL))
    {
        return false;
    }
    if(IsUseFontCompression())
    {
        if(pFile = fopen(string(m_outputPath + "\\" + FONT_COMPRESSION_INFO_NAME).c_str(), ("a+")))       
        {
            fprintf(pFile, _T("\n {%s, %d,%s, %d}, "),
                font_data->fontDataName,
                font_data->nDataArraySize,
                font_data->fontCompressedDataName,
                font_data->nDataArrayCompressionSize); 
            fclose(pFile);
            return true;           
        }      
    }
    return false;
}


/*****************************************************************************
 * FUNCTION
 *  MapLanguageWithFontDataFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool FontGenFile::MapLanguageWithFontDataFile(sMCTCustFontData *font_data, FILE *p_file)
{
    fprintf(p_file, ("\n0X%08X,"), font_data->Language_flags);
    return true;
}


/*****************************************************************************
 * FUNCTION
 *  GenerateFontResLanguageTable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outputPath [IN]
 * RETURNS
 *  
******************************************************************************/
bool FontGenFile::GenerateFontResLanguageTable(string *readfile_path, FILE *pFile)
{
    FILE *read_file = NULL;
    char temp[FONT_LINE_CHAR] = {0};
    
    if(read_file = fopen(string(FONT_LANGUAGE_TABLE_FILENAME).c_str(), ("r")))       
    {
        printf("[Dependency] %s\n", string(FONT_LANGUAGE_TABLE_FILENAME).c_str());
        while (fgets(temp, FONT_LINE_CHAR, read_file) != NULL)
        {
            fprintf(pFile, temp);
        }
        fclose(read_file);
        return true;           
    }    
    return false;
}



