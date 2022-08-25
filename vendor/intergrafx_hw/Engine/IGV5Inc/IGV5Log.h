#ifndef IGV5_LOG_H
#define IGV5_LOG_H

#include <stdio.h>
#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum 
{
	IG_LOG_NONE = 0,
	IG_LOG_TO_FILE,
	IG_LOG_TO_STDOUT,
	IG_LOG_TO_STDERR
} eLogType;

void IGLOG_Start(eLogType type, char *file);
void IGLOG_end();
void IGLOG_Printf(char *format, ...);
eLogType IGLOG_GetLogType(void);

void IGLOG_SetLastError(IGV5Err error_code, char *msg);
IGV5Err IGLOG_GetLastError(void);
const char *IGLOG_GetLAstErrorMessage(void);

#ifdef __cplusplus
}
#endif


#endif //IGV5_LOG_H