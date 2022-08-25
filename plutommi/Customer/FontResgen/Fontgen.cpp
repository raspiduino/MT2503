// Font_Resgen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FontClass.h"
#include "FontgenGprot.h"
#include "FontHWCompress.h"

FontEngine Font_app;
bool g_is_compression;
bool g_is_hw_compression;
bool g_is_group_compression;


/*****************************************************************************
 * FUNCTION
 *  IsUseFontCompression
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool IsUseFontCompression(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_compression;
}

/*****************************************************************************
 * FUNCTION
 *  IsUseHWFontCompression
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool IsUseHWFontCompression(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_hw_compression;
}

/*****************************************************************************
 * FUNCTION
 *  IsUseFontGroupCompression
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool IsUseFontGroupCompression(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_is_group_compression;
}

/*****************************************************************************
 * FUNCTION
 *  InitialFontEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
void InitialFontEngine(char * outputPath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Font_app.m_outputPath = outputPath;

#ifdef __MMI_FONT_COMPRESSION__	
    g_is_compression = 1;
#else 
    g_is_compression = 0;
#endif

    remove(string(Font_app.m_outputPath + "\\" + FONT_COMPRESSION_INFO_NAME).c_str()); 

#ifdef  __MMI_BDF_SW_COMPRESSION__   
    bfEncInitEncoder(&g_encoder);
    g_is_hw_compression = 1;
#else
    g_is_hw_compression = 0;
#endif

#ifdef  __MMI_FONT_GROUP_COMPRESSION__   
    g_is_group_compression = 1;
#else
    g_is_group_compression = 0;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  InitialFontEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
void DeinitialFontEngine()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    remove(string(Font_app.m_outputPath + "\\" + FONT_COMPRESSION_INFO_NAME).c_str());
    
#ifdef  __MMI_BDF_SW_COMPRESSION__   
	bfEncDeInitEncoder(&g_encoder);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  InitialFontEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool AddFont(
        char *language_name, 
        char *str_langid, 
        char *str_code,
        char *pbdf_filepath,
        U16 fontDataIndex,
        bool is_fixed = 0, 
        U8 is_dwidth = 1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 font_size = 0;
    const FontData_Info *font_info = NULL;
    string str_language_name =  " ";
    string str_language_id = " ";
    string str_language_code = " ";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* font_size is the smallest font size. */
    for(font_size = 0; font_size < MCT_MAX_FONT_TYPES; font_size++)
    {
        if((fontDataIndex & (1 << font_size)) != 0)
        {
            break;
        }
    }
    
    if(language_name != NULL)
    {
        str_language_name = language_name;
    }
    if(str_langid != NULL)
    {
        str_language_id = str_langid;
    }
   if(str_code != NULL)
    {
        str_language_code = str_code;
    }

    Font_app.AddNewLanguage(&str_language_name, &str_language_id, &str_language_code); 

    
    Font_app.m_bdf_parser = new CBdfOperation(&str_language_name, font_size, is_fixed, &string(pbdf_filepath), is_dwidth);
    Font_app.m_file_gen = new FontGenFile(&(Font_app.m_outputPath));

    /* Should initiate this stack variable? Be careful. */
    sMCTCustFontData fontdata;
    ResetFontDataValue(&fontdata);

    /* Check whether the font is added in font family by bdf file path */
    if((font_info = Font_app.FontDataIsAdded(&string(pbdf_filepath))) == NULL)
    {
        if(Font_app.ParserBDFFile(&fontdata) == false)
        {
            return false;
        }
        Font_app.AddFontDataToList(&fontdata);
    }
    else
    {
        Font_app.SetFontDataInfo(&fontdata, font_info);
    }

    Font_app.SetLanguageWithFontData(&str_language_code, &fontdata);
    
    /* Add this font to all selected font list */
    for(font_size = 0; font_size < MCT_MAX_FONT_TYPES; font_size++)
    {
        if((fontDataIndex & 1 << font_size) != 0)
        {
            Font_app.AddNewFontData(&fontdata, font_size);
        }
    }
    
    return true;  
}


/*****************************************************************************
 * FUNCTION
 *  InitialFontEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
bool GenerateFontResFile()
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Font_app.m_file_gen = new FontGenFile(&(Font_app.m_outputPath));

    Font_app.GenerateHWCompressionData();
    
    
    if(Font_app.GenerateFontDataFile() == false)
    {
        return false;
    }

    Font_app.GenerateFontResFile();

    delete Font_app.m_file_gen;
    Font_app.m_file_gen = NULL;
    return true;
}

/*****************************************************************************
 * FUNCTION
 *  InitialFontEngine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  void
******************************************************************************/
static void ResetFontDataValue(sMCTCustFontData *fontdata)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Must */
    fontdata->Language_flags = 0;
    fontdata->nHWCompressionDataSize = 0;

    /* Best to have */
    fontdata->nSize = 0;
    fontdata->is_dwidth = 0;
    fontdata->m_nTotalChars = 0;
}



