///////////////////////////////////////////////////////////////////////
/// \file       et_mempool.h
/// \brief      memory pool based memory management
/// \details    the returned function pointer is NOT thread safe
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       January 2011
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_MEMPOOL_H__
#define __ET_MEMPOOL_H__

#include "et_platform.h"

////////////////////////////////////////////////////////////////////////
/// \brief initialize memory pool
/// \details use the the returned function pointer to initialized platform <br>
/// but do NOT use them directly <br>
/// \param[in] pBase
/// \param[in] size
/// \param[out] pAlloc -- function pointer to allocate memory from memory pool
/// \param[out] pFree  -- function pointer to free memory from memory pool
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Mempool_Initialize(ET_VOID* IN pBase,
                                      ET_UINT32 IN size,
                                      ET_PLATFORM_ALLOC* OUT pAlloc,
                                      ET_PLATFORM_FREE* OUT pFree);
#ifdef ET_DEBUG_
ET_VOID mempool_dump ();
#else
#define mempool_dump() 
#endif
#endif
