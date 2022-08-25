#if !defined(MMI_FONT_GEN_GPROT_H)
#define MMI_FONT_GEN_GPROT_H
#include <stdio.h>
#include "font_resgen_data_struct.h"

void InitialFontEngine(char * outputPath);
void DeinitialFontEngine();
bool AddFont(
    char *language_name, 
    char *str_langid, 
    char *str_code,
    char *pbdf_filepath,
    U16 fontDataIndex,
    bool is_fixed, 
    U8 is_dwidth
    );

bool GenerateFontResFile();

static void ResetFontDataValue(sMCTCustFontData *fontdata);

#endif