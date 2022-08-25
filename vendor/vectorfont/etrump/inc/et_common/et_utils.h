///////////////////////////////////////////////////////////////////////
/// \file       et_utils.h
/// \brief      utilities definition
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
#ifndef __ET_UTILS_H__
#define __ET_UTILS_H__

#include "et_log.h"

/// maximum of \b _a and \b _b
#define ET_MAX(_a,_b)     ((_a) > (_b) ? (_a) : (_b))
/// minimal of \b _a and \b _b
#define ET_MIN(_a,_b)     ((_a) < (_b) ? (_a) : (_b))

////////////////////////////////////////////////////////////////////////
/// \brief get certain bits of value
/// \details bits (offset + count - 1) ~ (offset) will be returned
/// \param[in] value
/// \param[in] bit_offset
/// \param[in] bit_count
/// \return 
////////////////////////////////////////////////////////////////////////
#define ET_GET_BITS(value, bit_offset, bit_count) \
    ((((ET_UINT32)(value)) >> (bit_offset)) & (((ET_UINT32)1 << (bit_count)) - 1))

////////////////////////////////////////////////////////////////////////
/// \brief get offset of a member in structure
/// \details
/// \param[in] s -- structure type
/// \param[in] m -- sturcture member
/// \return 
////////////////////////////////////////////////////////////////////////
#define ET_OFFSETOF(s,m)    (size_t)&(((s *)0)->m)

#ifdef ET_DEBUG
#define ET_CHECK_TRACE_ERROR(_error) \
    if(ET_GET_BITS(_error, 24, 8) == ET_ERR_LVL_ERROR) \
    { \
        ET_TRACE_ERROR("error code : "#_error" = %08x\n", _error); \
    }
#else // ET_DEBUG
#define ET_CHECK_TRACE_ERROR(_error)
#endif // ET_DEBUG

/// \brief
/// expression check macro
/// \details
/// _exp should be true, or raise _error and go to clean up <br>
/// assumptions: <br>
/// err is a variable that defines as ET_ERROR <br>
/// finish is a label that refers to function clean up code <br>
#define ET_CHECK(_exp, _error)  \
    if (!(_exp)) \
    { \
        err = _error; \
        ET_CHECK_TRACE_ERROR(_error); \
        goto finish; \
    }

#endif
