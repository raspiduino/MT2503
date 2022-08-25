///////////////////////////////////////////////////////////////////////
/// \file       et_memory.h
/// \brief      memory management
/// \details    thread safe
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       November 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_MEMORY_H__
#define __ET_MEMORY_H__

#include "et_types.h"

////////////////////////////////////////////////////////////////////////
/// \brief allocate memory
/// \details 
/// \param[in] size
/// \return ET_VOID*
////////////////////////////////////////////////////////////////////////
#ifdef ET_DEBUG
#define ET_MALLOC(size) __et_malloc(size, __FILE__, __LINE__)
ET_API ET_VOID* __et_malloc(ET_UINT32 IN size, ET_CHAR* IN file, ET_UINT32 IN line);
#else
ET_API ET_VOID* ET_MALLOC(ET_UINT32 IN size);
#endif

////////////////////////////////////////////////////////////////////////
/// \brief reallocate memory
/// \details 
/// \param[in] p
/// \param[in] size
/// \return ET_VOID*
////////////////////////////////////////////////////////////////////////
#ifdef ET_DEBUG
#define ET_REALLOC(p, size) __et_realloc(p, size, __FILE__, __LINE__)
ET_API ET_VOID* __et_realloc(ET_VOID* IN p, ET_UINT32 IN size, ET_CHAR* IN file, ET_UINT32 IN line);
#else
ET_API ET_VOID* ET_REALLOC(ET_VOID* IN p, ET_UINT32 size);
#endif

////////////////////////////////////////////////////////////////////////
/// \brief free memory
/// \details 
/// \param[in] p
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
ET_API ET_VOID ET_FREE(ET_VOID* IN p);

////////////////////////////////////////////////////////////////////////
/// \brief dump memory status
/// \details debug and internal use only
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
#ifdef ET_DEBUG
ET_API ET_VOID __et_mem_dumpStatus();
#else
#define __et_mem_dumpStatus()
#endif

#endif
