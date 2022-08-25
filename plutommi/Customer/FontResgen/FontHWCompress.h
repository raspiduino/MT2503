#if !defined(MMI_FONT_HW_COMPRESS_H)
#define MMI_FONT_HW_COMPRESS_H

#include "Font_resgen_data_struct.h"
#include "bmp_font_encode.h"

extern  BF_ENC_STRUCT g_encoder;
extern S32 LV1Size;
extern S32 LV2Size;
extern BF_LEVEL1_TABLE_STRUCT  LV1Dict1;
extern BF_LEVEL2_TABLE_STRUCT  LV1Dict2;

extern const char *lv1_table_name ;
extern const char *lv2_table_name ;

kal_int32 FontHWCompressgenProfileInfo(BF_ENC_STRUCT *pEncoder, 
                                        kal_uint8 *pSrcData,
                                        kal_int32 glyphWidth, 
                                        kal_int32 glyphHeight, 
                                        U32 font_count);

bool FontHWCompressgenProfileInfo(BF_ENC_STRUCT *pEncoder,
                                        U8 *pSrcData, 
                                        U8 width,
                                        U8 height, 
                                        U32 font_count);

bool FontHWCompressEncodeGlyph(BF_ENC_STRUCT *pEncoder, 
                                U8 *pSrcData, U8* w_table, U8 height, 
                                int font_count, U8 *output_data, 
                                int *out_data_len, U8 *output_offset);

BF_ENC_STATUS_ENUM FontHWCompressQueryDictionary( BF_ENC_STRUCT *pEncoder, 
                                    S32 *LV1Size,
                                    S32 *LV2Size,
                                    BF_LEVEL1_TABLE_STRUCT  *LV1Dict,
                                    BF_LEVEL2_TABLE_STRUCT  *LV2Dict);

bool FontHWCompressWriteLVTableToFile(FILE *pFile,
                                    S32 LV1Size,
                                    S32 LV2Size,
                                    BF_LEVEL1_TABLE_STRUCT  *LV1Dict,
                                    BF_LEVEL2_TABLE_STRUCT  *LV2Dict,
                                    const char *lv1_table_name,
                                    const char *lv2_table_name);

int FontLzmaCompress(unsigned char *dest, 
                        size_t *destLen, 
                        const unsigned char *src, 
                        size_t srcLen);

U32 FontLzmaGroupSplitter(U8 *pDataArray, 
                            U32 *pOffsetArray, 
                            U32 nTotalChars, 
                            U8 *pDataArrayCompressed, 
                            S32 *nCompressTotalLen, 
                            sMCTGroupData *sGroupData);

//kal_int32 startEncodeGlyph(BF_ENC_STRUCT *pEncoder, );
#endif