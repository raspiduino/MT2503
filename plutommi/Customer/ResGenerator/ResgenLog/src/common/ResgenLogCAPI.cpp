/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *    ResgenLogCAPI.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resgen log broker for C language source
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/



#include "ResgenLogManager.h"
#include "ResgenLogCAPI.h"
#include "ResgenLogConfig.h"
#include <windows.h>
#include <process.h>

#define UNKNOWN_TAG_STR "Unknown"
#define UNKNOWN_TAG_WSTR L"Unknown"

////////////////////////////////////////////////////////
// Simple implemention log API for legacy C source
////////////////////////////////////////////////////////

// Currently log API for legacy resegn C program doesn't use Resgen C++ log framework
// since some lib in resgen mingw can't work normally now.
// So we provide the simple, thread-safe C API for legacy resgen C program.

static HANDLE ghMutex; 
static int cAPIMaxLevel = RES_LOG_LEVEL_DEBUG;
const char* DEFAULT_TAG_C_STR[4] = {"[DEBUG]", "[VERBOSE]","[WARN]","[ERR]"};

void resgen_logger_start(){
    ghMutex = CreateMutex( 
        NULL,              // default security attributes
        FALSE,             // initially not owned
        NULL);             // unnamed mutex

    if (ghMutex == NULL) 
    {
        cout<<"[ERROR][LOG]CreateMutex error: %d"<<GetLastError()<<endl;
    }

}

void resgen_logger_stop(){
    CloseHandle(ghMutex);

}

static int resgen_log_level_filter(int level){
    // Level Filtering
    if(level >= cAPIMaxLevel){
        return 0;
    }else{
        return 1;
    }
}

void resgen_log(const int level, const char *tag, const char *fmt,...){

    DWORD dwWaitResult = WAIT_ABANDONED;
    char tagDisplay[RES_LOG_DEFAULT_TAG_BUF_SIZE] = UNKNOWN_TAG_STR;
    DWORD threadId = 0;

    if(resgen_log_level_filter(level)==1){
        return;
    }

    if (ghMutex == NULL) 
    {
        cout<<"[ERROR][LOG]ghMutex can't be NULL"<<endl;
        return;
    }


    dwWaitResult = WaitForSingleObject( 
        ghMutex,    // handle to mutex
        INFINITE);  // no time-out interval


    if(dwWaitResult == WAIT_OBJECT_0){
        //cout<<"=THREAD START==============================="<<threadId<<endl;
        threadId = GetCurrentThreadId();

        va_list MyList;
        char nPrintableStr[RES_LOG_VSPRINTF_BUF_SIZE];
        // Null pointer check for log buffer
        if(nPrintableStr == NULL){
            return;
        }
        memset(nPrintableStr,0,sizeof(char) * RES_LOG_VSPRINTF_BUF_SIZE);

        va_start(MyList,fmt);
        vsnprintf(nPrintableStr,RES_LOG_VSPRINTF_BUF_SIZE-2,fmt,MyList);
        va_end(MyList);

        if(tag != NULL){
            memset(tagDisplay,0, sizeof(char) * RES_LOG_DEFAULT_TAG_BUF_SIZE);
            strncpy(tagDisplay,tag,RES_LOG_DEFAULT_TAG_BUF_SIZE-2);
        }

        if(level>=RES_LOG_LEVEL_DEBUG && level<= RES_LOG_LEVEL_ERR){
            cout<<DEFAULT_TAG_C_STR[level]<<"["<<tagDisplay<<"]"<<"[TID="<<threadId<<"]"<<nPrintableStr<<endl;
        }else{
            cout<<"[Unknown Level:"<<level<<"]["<<tagDisplay<<"]"<<"[TID="<<threadId<<"]"<<nPrintableStr<<endl;    
        }

        ReleaseMutex(ghMutex);

    }

}

// Please avoid from using resgen_wlog since it uses vswprintf
// which is not safe for c stirng processing.
void resgen_wlog(const int level, const char *tag, const wchar_t *fmt,...){
    DWORD threadId = 0;
    DWORD dwWaitResult = WAIT_ABANDONED;

    if(resgen_log_level_filter(level)==1){
        return;
    }

    dwWaitResult = WaitForSingleObject( 
        ghMutex,    // handle to mutex
        INFINITE);  // no time-out interval
    if(dwWaitResult == WAIT_OBJECT_0){
        threadId = GetCurrentThreadId();
        va_list MyList;
        wchar_t * nPrintableStr= new wchar_t[RES_LOG_VSPRINTF_BUF_SIZE];
        // Null pointer check for log buffer
        if(nPrintableStr == NULL){
            return;
        }

        memset(nPrintableStr,0,sizeof(wchar_t) * RES_LOG_VSPRINTF_BUF_SIZE);


        va_start(MyList,fmt);
        _vsnwprintf(nPrintableStr,(RES_LOG_VSPRINTF_BUF_SIZE)-2,fmt,MyList);
        va_end(MyList);


        wchar_t tag_buffer[RES_LOG_DEFAULT_TAG_BUF_SIZE];
        memset(tag_buffer,0,sizeof(wchar_t) * RES_LOG_DEFAULT_TAG_BUF_SIZE);
        int len = strlen(tag);

        if(tag == NULL || ( 0== MultiByteToWideChar( CP_ACP, MB_ERR_INVALID_CHARS, tag, len, tag_buffer, RES_LOG_DEFAULT_TAG_BUF_SIZE))){
            wcsncpy(tag_buffer,UNKNOWN_TAG_WSTR,RES_LOG_DEFAULT_TAG_BUF_SIZE-2);
        }
        // convert char tag to wchar tag

        if(level>=RES_LOG_LEVEL_DEBUG && level<= RES_LOG_LEVEL_ERR){
            wprintf(L"%ls[%ls][TID=%d]%ls",ResgenLog::DEFAULT_TAG_STR[level],tag_buffer,threadId,nPrintableStr);
            printf("\n");
        }else{
            wprintf(L"[Unknown Level%d][%ls][TID=%d]%ls",level,tag_buffer,threadId,nPrintableStr);
            printf("\n");
        }

        fflush(stdout);
        delete [] nPrintableStr;
        ReleaseMutex(ghMutex);
    }

}

void resgen_log_set_max_level(int level){
    cAPIMaxLevel = level;
}

/////////////////////////////////////////////////////////////////////
// C++ Resgen log adaptor APIs
/////////////////////////////////////////////////////////////////////
// The adaptor APIs should not be used in current legacy resource c programs
// It is for resgen extension in the future

void reslog_adaptor_log(const int level, const char *tag, const char *fmt,...){

    va_list MyList;
    char * nPrintableStr = new char[RES_LOG_VSPRINTF_BUF_SIZE];
    // Null pointer check for log buffer
    if(nPrintableStr == NULL){
        return;
    }
    memset(nPrintableStr,0,sizeof(char) * RES_LOG_VSPRINTF_BUF_SIZE);

    va_start(MyList,fmt);
    vsnprintf(nPrintableStr,RES_LOG_VSPRINTF_BUF_SIZE-2,fmt,MyList);
    va_end(MyList);
    ResgenLogger * logger = (ResgenLogger*) ResgenLogManager::getDefaultLogger();
    if(logger!=NULL){
        logger->log(tag, nPrintableStr, level);
    }
    delete [] nPrintableStr;
}

// Please avoid from using resgen_wlog since it uses vswprintf
// which is not safe for c stirng processing.
void reslog_adaptor_wlog(const int level, const char *tag, const wchar_t *fmt,...){

    va_list MyList;
    wchar_t * nPrintableStr= new wchar_t[RES_LOG_VSPRINTF_BUF_SIZE];
    // Null pointer check for log buffer
    if(nPrintableStr == NULL){
        return;
    }

    memset(nPrintableStr,0,sizeof(wchar_t) * RES_LOG_VSPRINTF_BUF_SIZE);


    va_start(MyList,fmt);
    _vsnwprintf(nPrintableStr,(RES_LOG_VSPRINTF_BUF_SIZE)-2,fmt,MyList);
    va_end(MyList);

    ResgenLogger * logger = (ResgenLogger*) ResgenLogManager::getDefaultLogger();
    if(logger!=NULL){
        logger->log(tag, nPrintableStr, level);
    }
    delete [] nPrintableStr;
}

void reslog_adaptor_set_max_level(int level){
    ResgenLogManager::setDefaulFilterLevel(level);
}

void reslog_adaptor_fatal_error_pending_wlog(const int level, const char* tag,const wchar_t * msg, const wchar_t *detail, const wchar_t *sugestion){
    ResgenPendingLogger * logger = (ResgenPendingLogger*) ResgenLogManager::getFatalErrorPendingLogger();
    if(logger!=NULL){
        logger->log(new ResgenFatalErrorLog(logger,tag, msg, level, detail, sugestion));
    }
}

void reslog_adaptor_fatal_error_pending_log(const int level, const char* tag,const char * msg,  const char *detail, const char *sugestion){
    ResgenPendingLogger * logger = (ResgenPendingLogger*) ResgenLogManager::getFatalErrorPendingLogger();
    if(logger!=NULL){
        logger->log(new ResgenFatalErrorLog(logger,tag, msg, level,detail, sugestion));
    }
}

int reslog_adaptor_has_pending_fatal_error(){
    ResgenPendingLogger * logger = (ResgenPendingLogger*) ResgenLogManager::getFatalErrorPendingLogger();
    if(logger!=NULL){
        return logger->hasPendingLogs();
    }else{
        return 0;
    }
}

void reslog_adaptor_flush_pending_fatal_error(){
    ResgenPendingLogger * logger = (ResgenPendingLogger*) ResgenLogManager::getFatalErrorPendingLogger();
    if(logger!=NULL){
        logger->flushPendingLogs();
    }
}


void reslog_adaptor_start_service(){
    ResgenLogManager::getInstance()->start();
}

void reslog_adaptor_stop_service(){
    ResgenLogManager::getInstance()->stop();
}

