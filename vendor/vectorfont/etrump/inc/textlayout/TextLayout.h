/////////////////////////////////////////////////////////////////////////
/// \file TextLayout.h
/// \brief to support script languages on the basis of FreeType
/// \details
/// <br><br>
/// \author etrump
/// \version 1.00
/// \date 2008/11/27
///
/////////////////////////////////////////////////////////////////////////
#ifndef   __TEXT_LAYOUT_H__
#define   __TEXT_LAYOUT_H__

/* for OTTB 2012-04-01 */
#define OTTB_OFFSET_SUPPORT

/// The maximun string length.
#define   MAX_STR_LENGTH    4096
#include  <ft2build.h>
#include  FT_FREETYPE_H

/// boundary type
typedef enum
{        
	Grapheme,
	Word,
	Line,
	Sentence
}FT_Boundary_Type;

#ifdef    __cplusplus
extern "C" {
#endif

typedef struct 
{
    FT_F26Dot6 x; ///<F26Dot6[26.6]
    FT_F26Dot6 y; ///<F26Dot6[26.6]
}OT_Offset;

typedef struct 
{
	FT_UInt32   num_glyphs;        ///< glyphs used   
	FT_UInt32   *glyph_indices;    ///< glyph index   
	FT_F26Dot6  *advances;         ///< glyph advance 
	OT_Offset   *offsets;          ///< glyph offset  
}FT_ShaperOut;

#define ET_UNICODE_REGION_MAX  8
typedef struct 
{
	FT_UInt32  count;
	FT_UInt16  start[ET_UNICODE_REGION_MAX];
	FT_UInt16  end[ET_UNICODE_REGION_MAX];
}FT_UniRegion;

/// The pointer to the text bounary.
typedef struct FT_Boundary  *FT_Bound;
/// The pointer to the shape object.
typedef struct FT_ShaperRec *FT_Shaper;
/// The pointer to the layout object.
typedef struct FT_LayoutRec *FT_Layout;
/// The pointer to the text layout.
typedef struct FT_Text_LayoutRec *FT_TextLayout;

// add for mtk
typedef struct MT_OTInfoRec* MT_OTInfo;
typedef struct MT_Cluster_InfoRec* MT_Cluster_Info;
typedef struct ET_OTInfoRec* ET_OTInfo;


/////////////////////////////////////////////////////////////////////////
/// \brief Load Open Type Layout table (GDEF/GPOS/GPOS) from font
/// \param[in] face ::A handle to a face object
/// \param[out] playout ::A handle to a layout object
/// \return 1 means success and 0 means error
///////////////////////////////////////////////////////////////////////
FT_Bool  FT_Load_Layout_Table( FT_Face face,  FT_Layout *playout );
//////////////////////////////////////////////////////////////////////
/// \brief Destroy a layout object created by FT_Load_Layout_Table
/// \param[in] layout ::A handle to a layout object
/// \return N/A
/////////////////////////////////////////////////////////////////////
void     FT_Done_Layout_Table( FT_Layout layout );

/////////////////////////////////////////////////////////////////////
/// \brief Create a shape object used to shape script to glyph item
/// \param[in] layout ::A handle to a layout object
/// \param[out] pshape ::A handle to a shape object
/// \return 1 means success and 0 means error
/////////////////////////////////////////////////////////////////////
FT_Bool  FT_Shaper_Create( FT_Shaper *pshaper, FT_Layout layout );
////////////////////////////////////////////////////////////////////
/// \brief Destroy a shape object created by FT_Shaper_Create
/// \param[in] shaper ::A handle to a shape object
/// \return N/A
///////////////////////////////////////////////////////////////////
void     FT_Shaper_Delete( FT_Shaper shaper );

//////////////////////////////////////////////////////////////////
/// \brief Create the texts boundary.
/// \param[in] chars ::The string to process.
/// \param[in] length ::The string length.
/// \param[in] type ::Which type of boundary will be created.
/// \return The created text boundary.
///////////////////////////////////////////////////////////////////
FT_Bound FT_Boundary_New( const FT_UInt16 *chars, int length, FT_Boundary_Type type );
///////////////////////////////////////////////////////////////////
/// \brief Get the next text that split by the boundary.
/// \param[in] bound ::A handle to a text boundary.
/// \return The start position of the next text.
///////////////////////////////////////////////////////////////////
int      FT_Boundary_Get_Next( FT_Bound bound );
///////////////////////////////////////////////////////////////////
/// \brief Get the previous text that split by the boundary.
/// \param[in] bound ::A handle to a text boundary.
/// \return The start position of the previous text.
///////////////////////////////////////////////////////////////////
int      FT_Boundary_Get_Previous( FT_Bound bound );
///////////////////////////////////////////////////////////////////
/// \brief Destroy the text boundary created by the function of FT_Boundary_New.
/// \param[in] bound ::A handle to a text boundary.
/// \return N/A.
///////////////////////////////////////////////////////////////////
void     FT_Boundary_Free( FT_Bound bound );
///////////////////////////////////////////////////////////////////
/// \brief Shape a script to glyph item.
/// \param[in] shaper ::A handle to a shape object.
/// \param[in] str ::The string to process.
/// \param[in] length ::The string length.
/// \param[out] shaper ::A handle to a shape object.
/// \return if successful return 1, if failed return 0.
//////////////////////////////////////////////////////////////////
FT_Bool  FT_Layout_Shape_Grapheme( FT_Shaper shaper, const FT_UInt16 *str, FT_UInt32 length );
//////////////////////////////////////////////////////////////////
/// \brief Get the result of the function FT_Layout_Shape_Grapheme.
/// \param[in] shaper ::A handle to a shape object.
/// \param[out] shape_result ::A hanldle to a shape result object.
/// \return if successful return 1, if failed return 0.
//////////////////////////////////////////////////////////////////
FT_Bool  FT_Shaper_Get_Result( FT_Shaper shaper, FT_ShaperOut *shape_result );

typedef struct FT_GlyphItemRec
{
    FT_Face   face;
	FT_UInt16 glyph;           ///< glyph index   
	FT_Fixed  advance;         ///< glyph advance 
	OT_Offset offset;          ///< glyph offset  
}FT_GlyphItem; ///< Glyph item object.

//////////////////////////////////////////////////////////////////////////
/// \brief Convert the bidi-levels to visual orders.
/// \param[in] levels ::The bidi-levels.
/// \param[in] num_level ::The num levels.
/// \param[out] visual_orders ::The visual order result.
/// \return N/A.
/////////////////////////////////////////////////////////////////////////
void FT_Bidi_Level_To_Visual_Order( const FT_Byte *levels, int num_level, int *visual_orders );


//////////////////////////////////////////////////////////////////
/// \brief Create a text layout object to process string (script analysis/bi-direction).
/// \param[in] bRight2Left ::Align mode is right-to-left or left-to-right.
/// \param[in] text ::The string to process
/// \param[in] length ::The string length.
/// \param[out] text_layout ::A handle to a text layout object
/// \return N/A
/////////////////////////////////////////////////////////////////
void FT_Text_Layout_Create( FT_TextLayout *text_layout, int bRight2Left, FT_UInt16 *text, FT_UInt32 length );

//////////////////////////////////////////////////////////////////
/// \brief Shape the text by shape.
/// Get the glyph information for each script item.
/// \param[in] text_layout ::A handle to a text layout object.
/// \param[out] text_layout ::A handle to a text layout object.
/// \return N/A
////////////////////////////////////////////////////////////////
void FT_Text_Layout_Shape_Text( FT_TextLayout text_layout, FT_Shaper shaper );

////////////////////////////////////////////////////////////////
/// \brief Split text into a number of lines to draw within a given rectangle
/// \param[in] text_layout ::A handle to a layout object.
/// \param[in] shaper ::A handle to a shape object.
/// \param[in] boldWidth ::Specify the added width value if font style is bold.
/// \param[in] tabWidth ::Specify the tab width value if neccessary.
/// \param[in] fontHeight ::Specify the font height.
/// \param[in] rWidth ::The width of the bound rectangle.
/// \param[in] rHeight ::The height of the bound rectangle.
/// \param[in] byWord ::calculate line wrapper by word.
/// \param[out] text_layout ::A handle to a text layout object.
/// \return the line number.
///////////////////////////////////////////////////////////////
int FT_Text_Layout_Text_Lines( FT_TextLayout text_layout, FT_Shaper shaper, int boldWidth, int tabWidth, int fontheight, int rWidth,  int rHeight, int widthGap, int heightGap, int byWord );

///////////////////////////////////////////////////////////////
/// \brief Get the line number in a rectangle after FT_Text_Layout_Text_Lines is called.
/// \param[in] text_layout ::A handle to a text layout object.
/// \return The line number.
//////////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Line_Count( FT_TextLayout text_layout );

//////////////////////////////////////////////////////////////
/// \brief Get the first and last item in the current line and return.
/// \param[in] text_layout ::A handle to a text layout object.
/// \param[in] cur_line ::Current line number.
/// \param[out] first_item ::the first item.
/// \param[out] last_item ::the last item.
/// \return The item count.
/////////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Line_Items( FT_TextLayout text_layout, int cur_line, int *first_item, int *last_item );

/////////////////////////////////////////////////////////////
/// \brief Get the bidi-levels array, the range is [from_item, last_item].
/// \param[in] text_layout ::A handle to a text layout object.
/// \param[in] from_item ::The first item.
/// \param[in] last_item ::The last item.
/// \param[out] levels ::The bidi-leves result.
/// \return if successful return (last_item - from_item + 1), if failed return 0.
//////////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Levels( FT_TextLayout text_layout, int from_item, int last_item, FT_Byte *levels );

/////////////////////////////////////////////////////////////
/// \brief Get the glyph item by its index
/// \param[in] text_layout ::A handle to a layout object.
/// \param[in] item ::The given item.
/// \param[in] glyph_item ::A handle to a glyph item.
/// \param[out] glyph_item ::The glyph item result.
/// \return The number of glyph item.
////////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Glyph_Item( FT_TextLayout text_layout, int item, FT_GlyphItem **glyph_item );

////////////////////////////////////////////////////////////
/// \brief Get the flags of the current item.
/// \param[in] text_layout ::A handle to a text layout object.
/// \param[in] item ::The given item.
/// \return The item flag.
///////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Item_Flag( FT_TextLayout text_layout, int item );

//////////////////////////////////////////////////////////
/// \brief Get the level of the current item. This functions has same functions as FT_Text_Layout_Get_Levels.
/// \param[in] text_layout ::A handle to a layout object.
/// \param[in] item ::The given item.
/// \return The bide level.
////////////////////////////////////////////////////////
int FT_Text_Layout_Get_Level( FT_TextLayout text_layout, int item );

////////////////////////////////////////////////////////////////
/// \brief Destroy a text layout created by FT_Text_Layout_Create
/// \param[in] text_layout ::A handle to a layout object.
/// \return N/A
///////////////////////////////////////////////////////////////
void FT_Text_Layout_Delete( FT_TextLayout text_layout );

FT_GlyphItem* FT_Text_Layout_Get_Glyphs (FT_TextLayout layout);
int FT_Text_Layout_Get_Uni_Num(FT_TextLayout layout);
int FT_Text_Layout_Get_Glyph_Num (FT_TextLayout layout);

int FT_Text_Layout_Get_Item_Count( FT_TextLayout text_layout );
int FT_Text_Layout_Get_Item_Text(FT_TextLayout text_layout, int item, int *start);

int FT_Text_Layout_Item_Get_Glyph_Offset(FT_TextLayout layout, int item);
int FT_Text_Layout_Get_Syllable_Info(FT_TextLayout layout, int *glyph_cluster_start);
void FT_Text_Layout_Get_Offset_Info(FT_TextLayout layout, int tabWidth, int widthGap,
                                    int *glyph_start_offset, int *glyph_end_offset, int *glyphLen);

int FT_Text_Layout_Get_Offset( FT_TextLayout layout, int cursor, int tabWidth, int widthGap);
int FT_Text_Layout_Get_Cursor( FT_TextLayout layout, int offset, int tabWidth, int widthGap);

int FT_Text_Layout_Prev_Cursor( FT_TextLayout layout, int cursor );
int FT_Text_Layout_Next_Cursor( FT_TextLayout layout, int cursor );

void FT_Text_Layout_Support_Multiple_Faces(int support);

// add for mtk
int FT_Shape_OpenType_Info( FT_Layout layout, FT_UInt16* text, int len, int bR2L, MT_Cluster_Info cluster );
int FT_Face_Get_Unicode_Region( FT_Face face, FT_UniRegion* region );

// for spreadtrum
int FT_Text_Layout_Paragraph_Direction(FT_UInt16* wstr, int len);
int FT_Text_Layout_Line_Direction(FT_UInt16* wstr, int len);

#ifdef    __cplusplus
}
#endif
#endif //< __TEXT_LAYOUT_H__ 

