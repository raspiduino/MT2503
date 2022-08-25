#if !defined(MMI_FONT_CLASS_H)
#define MMI_FONT_CLASS_H

#include "font_resgen_data_struct.h"
#include "bdf_operation.h"
#include "FontResFile.h"

class FontEngine
{
public:
    sMCTLanguageList *m_pstruMctLangList;
	sMCTLanguageList *m_pstruCurrMctLangNode;
	sMCTLanguageList *m_pstruLastMctLangNode;
    
    font_group_struct m_font_family[MCT_MAX_FONT_TYPES];

    vector<sMCTCustFontData> m_fontdata_list;
    
    CBdfOperation *m_bdf_parser;
    FontGenFile *m_file_gen;
    
    string m_outputPath;            /* Path of .c & .h file */
    
    bool ParserBDFFile(sMCTCustFontData *font_data);

    void AddNewLanguage(string *language_name, string *str_langid, string *str_code);
    void CreateLanguage(string *langName);
    void RemoveLanguage(string *langName);
    sMCTLanguageList* GetLanguageNodeByName(U8 *langname);
    U8   GetLanguageCount();
    bool LanguageIsAdded(U8 *langname);

    const FontData_Info* FontDataIsAdded(string *strFilePath);
    const FontData_Info* FontDataIsAdded(sMCTCustFontData *font_data);
    const FontData_Info* FontDataIsAdded(sMCTCustFontData *font_data, U8 font_size);

    void AddFontDataToList(sMCTCustFontData *font_data);
    
    U8 CompareInFontFamily(vector<FontData_Info>::iterator &it);
    void SetFontDataInfo(sMCTCustFontData *font_data, const FontData_Info *font_info);
    
    void AddNewFontData(sMCTCustFontData *font_data, U8 font_size);

    bool SetLanguageWithFontData(string *contry_code, const sMCTCustFontData *font_data);
    bool MapLanguageWithFontDataFile(string *contry_code, sMCTCustFontData *font_data);
        
    void GenerateFontResFile();
    bool GenerateFontDataFile();

    bool GenerateHWCompressionData();

    ~FontEngine();
};

#endif