///////////////////////////////////////////////////////////////////////
/// \file       et_log.h
/// \brief      log utilities definition
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
#ifndef __ET_LOG_H__
#define __ET_LOG_H__

#include "et_types.h"

#if (defined(_MSC_VER) && _MSC_VER < 1400) || !defined(ET_DEBUG)
// vc6 does not support ... in macro
// always disable log utility on vc6
#define ET_LogSetLevel
#define ET_Log
#define ET_LOG_ERROR
#define ET_LOG_WARNING
#define ET_LOG_INFO
#define ET_LOG_DEBUG
#define ET_TRACE_ERROR
#define ET_TRACE_WARNING
#define ET_TRACE_INFO
#define ET_TRACE_DEBUG
#else

////////////////////////////////////////////////////////////////////////
/// \brief set log output level
/// \details
/// set global log level, only the log level <= lvl will be outputed
/// \param[in] lvl
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
#define ET_LogSetLevel(lvl)    __et_logsetlevel(lvl)
ET_API ET_VOID __et_logsetlevel(ET_SINT32 IN lvl);

////////////////////////////////////////////////////////////////////////
/// \brief log information
/// \details
/// output log message
/// \param[in] fmt
/// \param[in] ...
/// \return ET_VOID
////////////////////////////////////////////////////////////////////////
#define ET_Log(fmt, ...)       __et_log(fmt, ##__VA_ARGS__)
ET_API ET_VOID __et_log(ET_CHAR* IN fmt, IN ...);

#define ET_LOG_LVL_ERROR    "<0>"
#define ET_LOG_LVL_WARNING  "<1>"
#define ET_LOG_LVL_INFO     "<2>"
#define ET_LOG_LVL_DEBUG    "<3>"

/// log error macro
#define ET_LOG_ERROR(fmt, ...) \
    ET_Log(ET_LOG_LVL_ERROR fmt, ##__VA_ARGS__)
/// log warning macro
#define ET_LOG_WARNING(fmt, ...) \
    ET_Log(ET_LOG_LVL_WARNING fmt, ##__VA_ARGS__)
/// log info macro
#define ET_LOG_INFO(fmt, ...) \
    ET_Log(ET_LOG_LVL_INFO fmt, ##__VA_ARGS__)
/// log debug message macro
#define ET_LOG_DEBUG(fmt, ...) \
    ET_Log(ET_LOG_LVL_DEBUG fmt, ##__VA_ARGS__)

/// source position output format
#define ET_LOG_WHERE_FMT    "%s(%d) : %s : "
/// source position parameters
#define ET_LOG_WHERE_ARG    __FILE__,__LINE__,__FUNCTION__

/// trace error macro
#define ET_TRACE_ERROR(fmt, ...) \
    ET_LOG_ERROR(ET_LOG_WHERE_FMT fmt, ET_LOG_WHERE_ARG, ##__VA_ARGS__)
/// trace warning macro
#define ET_TRACE_WARNING(fmt, ...) \
    ET_LOG_WARNING(ET_LOG_WHERE_FMT fmt, ET_LOG_WHERE_ARG, ##__VA_ARGS__)
/// trace info macro
#define ET_TRACE_INFO(fmt, ...) \
    ET_LOG_INFO(ET_LOG_WHERE_FMT fmt, ET_LOG_WHERE_ARG, ##__VA_ARGS__)
/// trace debug message macro
#define ET_TRACE_DEBUG(fmt, ...) \
    ET_LOG_DEBUG(ET_LOG_WHERE_FMT fmt, ET_LOG_WHERE_ARG, ##__VA_ARGS__)

#endif

#endif
