///////////////////////////////////////////////////////////////////////
/// \file       et_errors.h
/// \brief      errors definitions
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
#ifndef __ET_ERRORS_H__
#define __ET_ERRORS_H__

#include "et_types.h"
#include "et_modules.h"


#define ET_ERR_LVL_OK       (0)     ///< should not be regarded as error
#define ET_ERR_LVL_ERROR    (0x80)  ///< error level
#define ET_ERR_LVL_WARNING  (0x40)

/// utility to define an error code
#define ET_MAKE_ERROR_CODE(lvl, mod, code) \
    ( ( (ET_UINT32)((ET_UINT8)(lvl)) << 24) \
    | ( (ET_UINT32)((ET_UINT8)(mod)) << 16) \
    | (ET_UINT32)((ET_UINT16)(code)) )

/// error type
typedef enum
{
    /// success, no error
    ET_ERR_OK           = 0,

//-------------------- error definition --------------------
    /// generic error, unknown reason
    ET_ERR_FAIL         = ET_MAKE_ERROR_CODE(ET_ERR_LVL_ERROR, ET_MOD_GENERIC, 1),
    /// resource has already be initialized
    ET_ERR_INIT_TWICE,
    /// resource has not been initialized
    ET_ERR_NOT_INITIALIZED,
    /// bad parameter(s)
    ET_ERR_BAD_PARAM,
    /// function has not been implemented
    ET_ERR_NOT_IMPLEMENTED,
    /// out of resource
    ET_ERR_OUT_OF_RES,

    /// cache system has already be initialized
    ET_ERR_CACHE_INIT_TWICE = ET_MAKE_ERROR_CODE(ET_ERR_LVL_ERROR, ET_MOD_CACHE, 1),
    /// bad parameter(s)
    ET_ERR_CACHE_BAD_PARAM,
    /// not enough cache resource
    ET_ERR_CACHE_OUT_OF_RES,
    /// status error
    ET_ERR_CACHE_STATUS_ERROR,

    /// ime has already be initialized
    ET_ERR_IME_INIT_TWICE = ET_MAKE_ERROR_CODE(ET_ERR_LVL_ERROR, ET_MOD_IME, 1),


//-------------------- warning definition --------------------
    /// generic warning, unknown reason
    ET_ERR_WARNING              = ET_MAKE_ERROR_CODE(ET_ERR_LVL_WARNING, ET_MOD_GENERIC, 1),

    /// not found
    ET_ERR_WARN_CACHE_NOT_FOUND = ET_MAKE_ERROR_CODE(ET_ERR_LVL_WARNING, ET_MOD_CACHE, 1)

}ET_ERROR;


#endif
