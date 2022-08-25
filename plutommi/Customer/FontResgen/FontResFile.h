#if !defined(MMI_FONT_RES_FILE_H)
#define MMI_FONT_RES_FILE_H

#include "font_resgen_data_struct.h"

class FontEngine;

class FontGenFile
{
public:
    string m_outputPath;
    FontGenFile(string *outputPath) {m_outputPath = *outputPath;}   
    void GenerateFontResFile(FontEngine *font_engine);
    void GenerateFontResFile_GroupData(FontEngine *font_engine, FILE *p_file);
    void GenFontGroupString(FontEngine *font_engine, U8 font_size, FILE *p_file);
    
    bool GenerateFontDataFile(sMCTCustFontData *font_data);
    void GenerateFontResFile_RangeInfo(sMCTCustFontData *font_data, FILE *p_file);
    void GenerateFontResFile_CustFontData(sMCTCustFontData *font_data, FILE *p_file, U8 compress_flag);
    void GenerateFontResFile_GroupInfo(sMCTCustFontData *font_data, FILE *p_file);
    
    bool GenerateCompressionInfo(FontEngine *font_engine, FILE *pFile);
    bool GenerateCompressionInfoFile(sMCTCustFontData *font_data);

    bool MapLanguageWithFontDataFile(sMCTCustFontData *font_data, FILE *p_file);

    bool GenerateFontResLanguageTable(string *readfile_path, FILE *pFile);

    bool GenerateHWCompressionData();
};

#endif