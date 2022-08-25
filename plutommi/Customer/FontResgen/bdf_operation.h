
#if !defined(MMI_FONT_BDF_OPERATION_H)
#define MMI_FONT_BDF_OPERATION_H

#include "font_resgen_data_struct.h"
 

class CBdfOperation
{
public:
	//bool		m_bEquiDistant;
    MCTFontInfo m_struFontInfo;
    S32		    m_nBBox;
	S32		    m_nBBoy;
	S32		    m_nOrgHtOffset;
	S32		    m_nOrgWidthOffset;
	int			m_iswidth1, m_iswidth2;
	int			m_idwidth1, m_idwidth2;
	U32		    m_nDWidth;
	U32		    m_nByteArraySize;	
	U32		    m_nTotalChars ;
	U32		    m_nWidth;
	U32		    m_nHeight;
	S32		    m_nCurrCharHt;
	S32		    m_nCurrCharWidth;
	U32		    m_nIndexArray;      /* raw data byte count */
    
	S32		    m_nBoxMaxWidth;

	//Ascent and Descent
	int			m_nAscent;
	int			m_nDescent;
   
    string  m_strLanguageName;
    string  m_bdf_filename;
    string  m_bdf_filepath;
    
    U8      m_fontDataIndex;
    bool    m_isfixed;
    U8      m_bGenerateDWidth;

	bool parsing_bdf_file(string *bdf_file, U8 fontDataIndex, bool isfixed);
	bool LoadBDFFile(sMCTCustFontData *font_data);
    void GetRangesFromBDF(string *bdf_file, U32 **pRange, 
										   sMCTRangeDetails **pRangeDetails, 
										   string  rangeInfoName, 
										   string  rangeDataName, 
										   string  rangeOffsetName, 
										   string  fontRangeOffsetStructName,
										   bool fixWidth, U8 charBytes);
    int font_convert(int encoding1, int bbx1, int bbx2, MCTFontInfo *pMMIFont,
									  U64 *stream, int nCount, int nCountCompression);
    void parsing_stream(U64 *pStream, MCTFontInfo *pMMIFont, int nIndex, int nSize, int charsize);
    U64  ReverseBitOrdering(U64 nNumber, int nSize);
    bool release_parsing_bdf_file_alloc_buffer(U8 fontDataIndex);
    
    CBdfOperation(string *language_name, U8 fontDataIndex, bool isfixed, string *pbdf_file, U8 is_dwidth);
    ~CBdfOperation();
};





#endif