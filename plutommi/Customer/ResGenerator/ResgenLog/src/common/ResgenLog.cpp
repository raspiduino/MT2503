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
 *    ResgenLog.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Domain object of Resgen log
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "ResgenLogConfig.h"
#include "ResgenLogManager.h"
#include "windows.h"
#include <process.h>

#define WSTR_FATAL_ERROR_START L"[FATAL ERR]========================================[START]"
#define WSTR_FATAL_ERROR_END L"[FATAL ERR]==========================================[END]"


//////////////////////////////////////////////////////////
// Class: IResgenLog
//////////////////////////////////////////////////////////

// Static member declaration
const wchar_t* IResgenLog::DEFAULT_TAG_STR[4] = {L"[D]", L"[V]",L"[W]",L"[E]"};
const int IResgenLog::LEVEL_DEBUG=RES_LOG_LEVEL_DEBUG;
const int IResgenLog::LEVEL_VERBOSE=RES_LOG_LEVEL_VERBOSE;
const int IResgenLog::LEVEL_WARN=RES_LOG_LEVEL_WARN;
const int IResgenLog::LEVEL_ERR=RES_LOG_LEVEL_ERR;

//////////////////////////////////////////////////////////
// Class: ResgenLog
//////////////////////////////////////////////////////////

// Construction members
ResgenLog::ResgenLog(IResgenLogger* source, const char* tag, const char * msg, const int level){
    this->setMessage(msg);
    this->init(source, tag,level);
}


ResgenLog::ResgenLog(IResgenLogger* source, const char* tag, const wchar_t * msg, const int level){
    this->setMessage(msg);
    this->init(source, tag, level);
}

void ResgenLog::init(IResgenLogger* source, const char* tag, const int level){
    // init object memmbers
    this->level = level;
    this->source = source;
    this->setTag(tag);
    this->threadId =   GetCurrentThreadId();
    this->timeStamp = time(NULL);
    time (&(this->timeStamp));

}

const wchar_t* ResgenLog::toString(wchar_t* buffer,unsigned int bufferSizeInWcharT){

    tm * timeinfo = localtime (&(this->timeStamp));

    if(level >= IResgenLog::LEVEL_DEBUG && level<=IResgenLog::LEVEL_ERR){
        _snwprintf(buffer, bufferSizeInWcharT, L"%ls[%02d:%02d:%02d][TID:%d][%ls]%ls",IResgenLog::DEFAULT_TAG_STR[level],timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,
            this->threadId,this->tag,this->message);

    }else{
        _snwprintf(buffer, bufferSizeInWcharT, L"[UNKNOWN_LEVEL:%d][%02d:%02d:%02d][TID:%d][%ls]%ls",level,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,
            this->threadId,this->tag,this->message);
    }
    return buffer;
}


int ResgenLog::getLevel(){
    return this->level;
}

IResgenLogger* ResgenLog::getSource(){
    return this->source;
}

time_t ResgenLog::getTimeStamp(){
    return this->timeStamp;
}

const wchar_t* ResgenLog::getTag(){
    return this->tag;
}

const wchar_t* ResgenLog::getMessage(){
    return this->message;
}


DWORD ResgenLog::getThreadId(){
    return this->threadId;
}
void ResgenLog::setThreadId(DWORD lThreadId){
    this->threadId = lThreadId;
}

void ResgenLog::setTag(const char* tag){
    ResgenUtility::secureCharToWChar(this->tag,RES_LOG_DEFAULT_TAG_BUF_SIZE,tag,RES_LOG_DEFAULT_TAG_BUF_SIZE);
}
void ResgenLog::setMessage(const char * msg){
    ResgenUtility::secureCharToWChar(this->message,RES_LOG_DEFAULT_MSG_BUF_SIZE,msg,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

void ResgenLog::setTag(const wchar_t* tag){
    ResgenUtility::secureStringCopy(this->tag,RES_LOG_DEFAULT_TAG_BUF_SIZE,tag,RES_LOG_DEFAULT_TAG_BUF_SIZE);
}

void ResgenLog::setMessage(const wchar_t * msg){
    ResgenUtility::secureStringCopy(this->message,RES_LOG_DEFAULT_MSG_BUF_SIZE,msg,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

//////////////////////////////////////////////////////////
// Class: ResgenFatalErrorLog
//////////////////////////////////////////////////////////
ResgenFatalErrorLog::ResgenFatalErrorLog(IResgenLogger* source, const char* tag, const char * message,const int level,const char* detail, const char* suggestion):ResgenLog(source,tag,message,level){
    this->setDetailedMessage(detail);
    this->setSuggestion(suggestion);

}

ResgenFatalErrorLog::ResgenFatalErrorLog(IResgenLogger* source, const char* tag, const wchar_t * message, const int level,const wchar_t* detail, const wchar_t* suggestion):ResgenLog(source,tag,message,level){
    this->setDetailedMessage(detail);
    this->setSuggestion(suggestion);
}

const wchar_t * ResgenFatalErrorLog::getDetailedMessage(){
    return this->detailMessage;
}
const wchar_t * ResgenFatalErrorLog::getSuggestion(){
    return this->suggestion;
}
void ResgenFatalErrorLog::setDetailedMessage(const wchar_t * detail){
    ResgenUtility::secureStringCopy(this->detailMessage,RES_LOG_DEFAULT_MSG_BUF_SIZE,detail,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

void ResgenFatalErrorLog::setDetailedMessage(const char * detail){
    ResgenUtility::secureCharToWChar(this->detailMessage,RES_LOG_DEFAULT_MSG_BUF_SIZE,detail,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

void ResgenFatalErrorLog::setSuggestion(const wchar_t * suggestion){
    ResgenUtility::secureStringCopy(this->suggestion,RES_LOG_DEFAULT_MSG_BUF_SIZE,suggestion,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

void ResgenFatalErrorLog::setSuggestion(const char * suggestion){
    ResgenUtility::secureCharToWChar(this->suggestion,RES_LOG_DEFAULT_MSG_BUF_SIZE,suggestion,RES_LOG_DEFAULT_MSG_BUF_SIZE);
}

const wchar_t* ResgenFatalErrorLog::toString(wchar_t* buffer,unsigned int bufferSizeInWcharT){

    if(level >= IResgenLog::LEVEL_DEBUG && level<=IResgenLog::LEVEL_ERR){
        _snwprintf(buffer, bufferSizeInWcharT, L"%ls\n%ls[%ls]%ls\n[DETAIL]:\n%ls\n[SUGGESTION]:\n%ls\n%ls",WSTR_FATAL_ERROR_START,IResgenLog::DEFAULT_TAG_STR[level],this->tag,this->message,this->detailMessage,this->suggestion,WSTR_FATAL_ERROR_END);

    }else{
        _snwprintf(buffer, bufferSizeInWcharT, L"%ls\n[UNKNOWN_LEVEL:%d][%ls]%ls\n[DETAIL]:\n%ls\n[SUGGESTION]:\n%ls\n%ls",WSTR_FATAL_ERROR_START,this->level,this->tag,this->message,this->detailMessage,this->suggestion,WSTR_FATAL_ERROR_END);

    }
    return buffer;
}


//////////////////////////////////////////////////////
// Class ResgenUtility implementation
//////////////////////////////////////////////////////
int ResgenUtility::secureStringCopy(char* dest, unsigned int destSizeLimit, const char* source, unsigned int sourceSizeLimit){
    char * tempBuffer = dest;

    int result = 0;

    if(destSizeLimit>=sourceSizeLimit && tempBuffer!=NULL){
        // Mingw dones't support strnlen so I have to use memcpy to make sure the string operation is safe
        memset(tempBuffer, 0, sizeof(char)* destSizeLimit);
        // To make sure the message has a null end character
        strncpy(tempBuffer, source, sourceSizeLimit-2);
        result = 1;
    }

    return result;
}
int ResgenUtility::secureStringCopy(wchar_t* dest, unsigned int destSizeLimit, const wchar_t* source, unsigned int  sourceSizeLimit){
    wchar_t *buffer = dest;
    int result = 0;
    if(destSizeLimit>=sourceSizeLimit && buffer!=NULL){
        memset(buffer, 0, sizeof(wchar_t) * destSizeLimit);
        wcsncpy(buffer,source,sourceSizeLimit-2);
        result =1;
    }
    return result;
}

// Convert char string to wcahr_t string
// return value:
//       1: success
//       0: failed
int ResgenUtility::secureCharToWChar(wchar_t* dest, unsigned int destSizeLimit, const char* source, unsigned int sourceSizeLimit){
    wchar_t * buffer = dest;
    char * tempBuffer = new char[sourceSizeLimit];

    int result = 0;
    if(destSizeLimit>=sourceSizeLimit && buffer!=NULL && tempBuffer!=NULL){
        // Mingw dones't support strnlen so I have to use memcpy to make sure the string operation is safe
        memset(buffer, 0, sizeof(wchar_t)* destSizeLimit);
        ResgenUtility::secureStringCopy(tempBuffer,destSizeLimit,source,sourceSizeLimit-2);
        int len = strlen(tempBuffer);
        //    For VC, we can use the following way to convert char to wchar_t
        //    But resgen's mingw environment doesn't support this way
        //    use_facet< ctype<wchar_t> >(locale()).widen(tempBuffer,tempBuffer+len+1,buffer);
        result = MultiByteToWideChar( CP_ACP, MB_ERR_INVALID_CHARS, tempBuffer, len, buffer, destSizeLimit );
    }
    delete [] tempBuffer;

    return result;
}

