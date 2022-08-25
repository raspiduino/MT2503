///////////////////////////////////////////////////////////////////////
/// \file       autocache.h
/// \brief      FreeType2 module "autocache" interface definition
/// \details    code to query interface: (AC_Service)FT_Get_Module_Interface( library, "autocache" )
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       January 2011
///
///////////////////////////////////////////////////////////////////////

#ifndef __AUTOCACHE_H__
#define __AUTOCACHE_H__

#include <ft2build.h>
#include FT_INTERNAL_DRIVER_H

FT_BEGIN_HEADER

typedef struct AC_Interface_
{
    FT_Slot_LoadFunc load_glyph;
    void (*save_glyph)( FT_GlyphSlot glyph_slot );
}AC_Interface, *AC_Service;

FT_END_HEADER

#endif
