///////////////////////////////////////////////////////////////////////
/// \file       et_platform.h
/// \brief      platform related settings
/// \details
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       November 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_PLATFORM_H__
#define __ET_PLATFORM_H__

#include "et_types.h"

////////////////////////////////////////////////////////////////////////
/// \brief function pointer, print string
/// \details 
/// \param[in] str -- string to be printed
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
typedef ET_VOID (*ET_PLATFORM_PRINT)(ET_CHAR* IN str);
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, allocate memory
/// \details 
/// \param[in] sz
/// \return ET_VOID* -- pointer to allocated memory block
////////////////////////////////////////////////////////////////////////
typedef ET_VOID* (*ET_PLATFORM_ALLOC)(ET_UINT32 IN sz);
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, free memory
/// \details 
/// \param[in] p -- pointer to the memory block needs to be free
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
typedef ET_VOID (*ET_PLATFORM_FREE)(ET_VOID* IN p);
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, create mutex
/// \details 
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
typedef ET_VOID* (*ET_PLATFORM_MUTEX_CREATE)();
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, destroy mutex
/// \details 
/// \param[in] mutex -- mutex to be destroyed
/// \return ET_SINT32 -- 0 means success
////////////////////////////////////////////////////////////////////////
typedef ET_SINT32 (*ET_PLATFORM_MUTEX_DESTROY)(ET_VOID* IN mutex);
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, lock mutex
/// \details 
/// \param[in] mutex -- mutex to be locked
/// \return ET_SINT32 -- 0 means success
////////////////////////////////////////////////////////////////////////
typedef ET_SINT32 (*ET_PLATFORM_MUTEX_LOCK)(ET_VOID* IN mutex);
////////////////////////////////////////////////////////////////////////
/// \brief function pointer, unlock mutex
/// \details 
/// \param[in] mutex -- mutex to be unlocked
/// \return ET_SINT32 -- 0 means success
////////////////////////////////////////////////////////////////////////
typedef ET_SINT32 (*ET_PLATFORM_MUTEX_UNLOCK)(ET_VOID* IN mutex);

/// struct that contains important platform relegated functions
typedef struct
{
    ET_PLATFORM_PRINT           print;

    ET_PLATFORM_ALLOC           alloc;
    ET_PLATFORM_FREE            free;

    ET_PLATFORM_MUTEX_CREATE    mutexCreate;
    ET_PLATFORM_MUTEX_DESTROY   mutexDestroy;
    ET_PLATFORM_MUTEX_LOCK      mutexLock;
    ET_PLATFORM_MUTEX_UNLOCK    mutexUnlock;
}ET_Platform;


////////////////////////////////////////////////////////////////////////
/// \brief initialize the platform functions
/// \details can only be called once<br>
/// it will tried to initialize a default platform
/// if no one calls this initialization function<br>
/// it will also tried to initialized a default one
/// if a certain platform function is set to NULL
/// \param[in] memory
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Platform_Initialize(ET_Platform* IN platform);

#endif
