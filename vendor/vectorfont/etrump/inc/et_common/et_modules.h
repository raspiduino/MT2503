///////////////////////////////////////////////////////////////////////
/// \file       et_modules.h
/// \brief      modules definitions
/// \details
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       October 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_MODULES_H__
#define __ET_MODULES_H__

/// module type
typedef enum
{
    /// generic, does not belong to any specific module
    ET_MOD_GENERIC = 0,
    /// cache system
    ET_MOD_CACHE,
    /// freetype auto cache
    ET_MOD_FT_AUTOCACHE,
    /// etrump interface
    ET_MOD_ETRUMP_INTERFACE,
    /// etrump ime
    ET_MOD_IME
}ET_MODULE;

#endif
