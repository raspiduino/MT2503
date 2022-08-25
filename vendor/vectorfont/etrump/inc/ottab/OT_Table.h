/********************************************************************
	created:	2009/11/11
	created:	11:11:2009   15:46
	filename: 	OTTab\OT_Table.h
	file path:	OTTab
	file base:	OT_Table
	file ext:	h
	author:		etrump
	
	purpose:	API for OpenType Table
*********************************************************************/
#ifndef  __OT_TABLE_H__
#define  __OT_TABLE_H__

/* for OTTB 2012-04-01 */
#define OTTB_OFFSET_SUPPORT

#ifndef  FALSE
#define  FALSE 0
#endif

#ifndef  TRUE
#define  TRUE  1
#endif

#ifndef  NULL
#ifdef   __cplusplus
#define  NULL    0
#else
#define  NULL    ((void *)0)
#endif
#endif

#ifdef   __cplusplus
extern "C" {
#endif

typedef char           OT_CHAR;
typedef unsigned char  OT_UCHAR;
typedef short          OT_SHORT;
typedef unsigned short OT_USHORT;
typedef int            OT_INT;
typedef unsigned int   OT_UINT;

typedef int            OT_BOOL;
typedef OT_UINT        OT_GLYPH;
typedef OT_INT         OT_FIXED; /* 26.6 */
typedef OT_INT         OT_16D16; /* 16.16 */

typedef void*          OT_HANDLE;
typedef OT_UINT        OT_TAG;

typedef enum 
{
	OT_Err_Ok = 0,
	OT_Err_Invalid_Stream_Operation,
	OT_Err_Invalid_Argument,
	OT_Err_Out_Of_Memory,
	OT_Err_Invalid_Face_Handle, 
	OT_Err_Table_Missing,
	OT_Err_Invalid_SubTable_Format      = 0x1000,
	OT_Err_Invalid_SubTable             = 0x1001,
	OT_Err_Not_Covered                  = 0x1002,
	OT_Err_Too_Many_Nested_Contexts     = 0x1003,
	OT_Err_No_MM_Interpreter            = 0x1004,
	OT_Err_Empty_Script                 = 0x1005,
	OT_Err_Invalid_GSUB_SubTable_Format = 0x1010,
	OT_Err_Invalid_GSUB_SubTable        = 0x1011,
	OT_Err_Invalid_GPOS_SubTable_Format = 0x1020,
	OT_Err_Invalid_GPOS_SubTable        = 0x1021,
	OT_Err_Invalid_GDEF_SubTable_Format = 0x1030,
	OT_Err_Invalid_GDEF_SubTable        = 0x1031,
	OT_Err_Read_Error                   = 0x6EAD
}OT_Error;

typedef struct 
{
    OT_FIXED x;
    OT_FIXED y;
}OT_Point;

typedef struct 
{
	OT_UINT     gindex;
	OT_UINT     properties;
	OT_UINT     cluster;
	OT_USHORT   component;
	OT_USHORT   ligID;
	OT_USHORT   gproperties;
}OT_GlyphItem;

typedef struct 
{
	OT_FIXED     x_pos;
	OT_FIXED     y_pos;
	OT_FIXED     x_advance;
	OT_FIXED     y_advance;
	OT_USHORT    back;            /* number of glyphs to go back for drawing current glyph   */
	OT_BOOL      new_advance;     /* if set, the advance width values are absolute, i.e., they won't be added to the original glyph's value but rather replace them.*/
	OT_SHORT     cursive_chain;   /* character to which this connects, may be positive or negative; used only internally */
}OT_Position;


typedef struct
{
	OT_UINT    allocated;

	OT_UINT    in_length;
	OT_UINT    out_length;
	OT_UINT    in_pos;
	OT_UINT    out_pos;

	OT_GlyphItem  *in_string;
	OT_GlyphItem  *out_string;
	OT_Position   *positions;
	OT_USHORT      max_ligID;
}OT_Buffer;

OT_Error OT_Buffer_New( OT_Buffer **buffer );

OT_Error OT_Buffer_Swap( OT_Buffer *buffer );

OT_Error OT_Buffer_Free( OT_Buffer *buffer );

OT_Error OT_Buffer_Clear( OT_Buffer *buffer );

OT_Error OT_Buffer_Add_Glyph( OT_Buffer *buffer, OT_UINT glyph_index, OT_UINT properties, OT_UINT cluster );

OT_Error OT_Buffer_Add_Output_Glyphs( OT_Buffer *buffer, OT_USHORT  num_in, OT_USHORT  num_out, OT_USHORT *glyph_data, OT_USHORT  component, OT_USHORT  ligID );

OT_Error OT_Buffer_Add_Output_Glyph( OT_Buffer *buffer, OT_UINT glyph_index, OT_USHORT component, OT_USHORT ligID );

OT_Error OT_Buffer_Copy_Output_Glyph( OT_Buffer *buffer );

OT_USHORT OT_Buffer_Allocate_Ligid( OT_Buffer *buffer );

/*************************************************************************
	implementation needs to make sure to load a scaled glyph, so /no/ FT_LOAD_NO_SCALE
	OUT *xpos = outline.points[point].x;
	OUT *ypos = outline.points[point].y;
	return OT_Err_Invalid_GPOS_SubTable or OT_Err_Ok
*************************************************************************/
typedef struct
{
	OT_USHORT  x_ppem;
	OT_USHORT  y_ppem;
	OT_FIXED   x_scale;
	OT_FIXED   y_scale;
	void      *get_point;
}OT_Font;

typedef OT_Error (*OT_Get_Point_In_Outline_Func)( OT_Font *font, OT_UINT glyph_index, OT_UINT point, OT_FIXED *xpos, OT_FIXED *ypos );


/*************************************************************************
	如果在OT_Memory.h中没有定义OT_SYSTEM_MEMORY;
	则表示不适用系统函数，调用该引擎时请实现下面三个函数。
*************************************************************************/
void*     OT_MALLOC( OT_UINT sz );
void*     OT_REALLOC( void *p, OT_UINT oldsz, OT_UINT sz );
void      OT_FREE( void *p );

#ifdef    FT_FREETYPE_H
typedef   FT_Stream            OT_Stream;
#else
struct OT_StreamRec
{
	OT_UCHAR  *base;
	OT_UINT   length;
	/* private: */
	OT_UINT   offset;
}OT_StreamRec, *OT_Stream;
#endif/* FT_FREETYPE_H */
OT_UINT OT_Stream_Pos( OT_Stream stream );

OT_Error OT_Stream_Seek( OT_Stream stream, OT_UINT pos );

OT_CHAR OT_Stream_Read_Char( OT_Stream stream, OT_Error *error );

OT_UCHAR OT_Stream_Read_Byte( OT_Stream stream, OT_Error *error );

OT_SHORT OT_Stream_Read_Short( OT_Stream stream, OT_Error *error );

OT_USHORT OT_Stream_Read_UShort( OT_Stream stream, OT_Error *error );

OT_INT OT_Stream_Read_Int32( OT_Stream stream, OT_Error *error );

OT_UINT OT_Stream_Read_UInt32( OT_Stream stream, OT_Error *error );

/************************************************************************/
/*              API for GDEF Table                                      */
/************************************************************************/
typedef struct OT_GDEFTabRec *OT_GDEF;
OT_Error  OT_Load_GDEF_Table( OT_Stream stream, OT_GDEF *gdef );

OT_Error  OT_Done_GDEF_Table( OT_GDEF gdef );

/************************************************************************/
/*              API for GSUB Table                                      */
/************************************************************************/
typedef struct OT_GSUBTabRec *OT_GSUB;
OT_Error  OT_Load_GSUB_Table( OT_GDEF gdef, OT_Stream stream, OT_GSUB *gsub );

OT_Error  OT_Done_GSUB_Table( OT_GSUB gsub );

#ifndef   OTTB_OFFSET_SUPPORT

	OT_Error  OT_GSUB_Select_Script( OT_GSUB  gsub, OT_UINT script_tag, OT_USHORT *script_index );

	OT_Error  OT_GSUB_Select_Feature( OT_GSUB gsub, OT_UINT feature_tag, OT_USHORT script_index, OT_USHORT language_index, OT_USHORT *feature_index );

	OT_Error  OT_GSUB_Query_Features( OT_GSUB gsub, OT_USHORT script_index, OT_USHORT language_index, OT_UINT **feature_tag_list );

	OT_Error  OT_GSUB_Add_Feature( OT_GSUB gsub, OT_USHORT feature_index, OT_UINT property );

	OT_Error  OT_GSUB_Clear_Features( OT_GSUB gsub );

	OT_Error  OT_GSUB_Apply_String( OT_GSUB gsub, OT_Buffer *buffer );

#else   /*OTTB_OFFSET_SUPPORT*/
	
	OT_Error  OT_GSUB_Select_Script( OT_GSUB  gsub, OT_UINT script_tag, OT_USHORT *script_index, OT_INT ottb_offset );

	OT_Error  OT_GSUB_Select_Feature( OT_GSUB gsub, OT_UINT feature_tag, OT_USHORT script_index, OT_USHORT language_index, OT_USHORT *feature_index, OT_INT ottb_offset );

	OT_Error  OT_GSUB_Query_Features( OT_GSUB gsub, OT_USHORT script_index, OT_USHORT language_index, OT_UINT **feature_tag_list, OT_INT ottb_offset );

	OT_Error  OT_GSUB_Add_Feature( OT_GSUB gsub, OT_USHORT feature_index, OT_UINT property, OT_INT ottb_offset );

	OT_Error  OT_GSUB_Clear_Features( OT_GSUB gsub, OT_INT ottb_offset );

	OT_Error  OT_GSUB_Apply_String( OT_GSUB gsub, OT_Buffer *buffer, OT_INT ottb_offset );

#endif  /*OTTB_OFFSET_SUPPORT*/

/************************************************************************/
/*              API for GPOS Table                                      */
/************************************************************************/
typedef struct OT_GPOSTabRec *OT_GPOS;
OT_Error  OT_Load_GPOS_Table( OT_GDEF gdef, OT_Stream stream, OT_GPOS *gpos );

OT_Error  OT_Done_GPOS_Table( OT_GPOS gpos );

#ifndef   OTTB_OFFSET_SUPPORT
	OT_Error  OT_GPOS_Select_Script( OT_GPOS gpos, OT_UINT script_tag, OT_USHORT *script_index );

	OT_Error  OT_GPOS_Select_Feature( OT_GPOS gpos, OT_UINT feature_tag, OT_USHORT script_index, OT_USHORT language_index, OT_USHORT *feature_index );

	OT_Error  OT_GPOS_Query_Features( OT_GPOS gpos, OT_USHORT script_index, OT_USHORT language_index, OT_UINT **feature_tag_list );

	OT_Error  OT_GPOS_Add_Feature( OT_GPOS gpos, OT_USHORT feature_index, OT_UINT property );

	OT_Error  OT_GPOS_Clear_Features( OT_GPOS gpos );

	OT_Error  OT_GPOS_Apply_String( OT_Font *font, OT_GPOS gpos, OT_USHORT load_flags, OT_Buffer *buffer, OT_BOOL dvi, OT_BOOL r2l );

#else   /*OTTB_OFFSET_SUPPORT*/
	
	OT_Error  OT_GPOS_Select_Script( OT_GPOS gpos, OT_UINT script_tag, OT_USHORT *script_index, OT_INT ottb_offset );

	OT_Error  OT_GPOS_Select_Feature( OT_GPOS gpos, OT_UINT feature_tag, OT_USHORT script_index, OT_USHORT language_index, OT_USHORT *feature_index, OT_INT ottb_offset );

	OT_Error  OT_GPOS_Query_Features( OT_GPOS gpos, OT_USHORT script_index, OT_USHORT language_index, OT_UINT **feature_tag_list, OT_INT ottb_offset );

	OT_Error  OT_GPOS_Add_Feature( OT_GPOS gpos, OT_USHORT feature_index, OT_UINT property, OT_INT ottb_offset );

	OT_Error  OT_GPOS_Clear_Features( OT_GPOS gpos, OT_INT ottb_offset );

	OT_Error  OT_GPOS_Apply_String( OT_Font *font, OT_GPOS gpos, OT_USHORT load_flags, OT_Buffer *buffer, OT_BOOL dvi, OT_BOOL r2l, OT_INT ottb_offset );

#endif  /*OTTB_OFFSET_SUPPORT*/

void  OTTB_Delete_GSUB_Table( OT_GSUB gsub ); /* for OTTB, 2012/04/01 */

OT_Error  OTTB_Create_GSUB_Table( OT_GSUB *retptr, OT_GSUB origin ); /* for OTTB, 2012/04/01 */

void  OTTB_Delete_GPOS_Table( OT_GPOS gpos ); /* for OTTB, 2012/04/01 */

OT_Error  OTTB_Create_GPOS_Table( OT_GPOS *retptr, OT_GPOS origin ); /* for OTTB, 2012/04/01 */

#ifdef   __cplusplus
}
#endif
#endif /*__OT_TABLE_H__*/
