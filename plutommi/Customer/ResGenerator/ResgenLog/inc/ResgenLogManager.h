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
 *    ResgenLogManager.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Log Management API for Resgen tool chain
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


#ifndef __RESGEN_LOG_MANAGER_H__
#define __RESGEN_LOG_MANAGER_H__

#include <ctime> 
#include <vector>
#include <string>
#include <iostream>
#include "ResgenLogConfig.h"
#include <windows.h>

class IResgenLogger;
class IResgenLog;
class IResgenLogFilter;
class IResgenLogHandler;

using namespace std;

/////////////////////////////////////////////////////////////
// IResgenLog is the basic type of Resgen log, all log messgae
// handled in Resgen system must Implement this class
////////////////////////////////////////////////////////////
class IResgenLog{

public:
    // From which logger
    virtual IResgenLogger* getSource()=0;
    virtual time_t getTimeStamp()=0;
    virtual DWORD getThreadId()=0;
    virtual void setThreadId(DWORD threadId)=0;
    virtual void setTag(const char* tag)=0;
    virtual void setMessage(const char * message)=0;
    virtual void setTag(const wchar_t* tag)=0;
    virtual void setMessage(const wchar_t * message)=0;
    virtual const wchar_t* getTag()=0;
    virtual const wchar_t* getMessage()=0;
    virtual const wchar_t * toString(wchar_t* buffer, unsigned int bufferSizeInWcharT)=0;
    virtual int getLevel()=0;

    const static int LEVEL_ERR;
    const static int LEVEL_WARN;
    const static int LEVEL_VERBOSE;
    const static int LEVEL_DEBUG;
    const static wchar_t* DEFAULT_TAG_STR[4];
};

/////////////////////////////////////////////////////////////
// ResgenLog is the default adaptor of IResgenLog, providing
// simple and basic implementation.
// Please check the GOF design pattern "Default Adaptor." 
// for the detail
////////////////////////////////////////////////////////////
class ResgenLog: public IResgenLog{
protected:
    time_t timeStamp;
    // Don't use wstring in resgen mingw gcc environment (11B)
    // since the wmemset in the lib may cuase invalied memory access system exception
    // So we have to use low level wchar_t string to record log messages
    wchar_t tag[RES_LOG_DEFAULT_TAG_BUF_SIZE];
    wchar_t message[RES_LOG_DEFAULT_MSG_BUF_SIZE];
    DWORD threadId;
    IResgenLogger* source;
    int level;
    virtual void init(IResgenLogger* source, const char* tag, const int level);

public:
    ResgenLog(IResgenLogger* source, const char* tag, const char * msg, const int level);
    ResgenLog(IResgenLogger* source, const char* tag, const wchar_t * msg, const int level);

    virtual time_t getTimeStamp();
    // From which logger
    virtual IResgenLogger* getSource();
    virtual const wchar_t* getTag();
    virtual const wchar_t* getMessage();
    virtual void setTag(const char* tag);
    virtual void setMessage(const char * message);
    virtual void setTag(const wchar_t* tag);
    virtual void setMessage(const wchar_t * message);
    virtual const wchar_t * toString(wchar_t* buffer, unsigned int bufferSizeInWcharT);
    virtual int getLevel();
    virtual DWORD getThreadId();
    virtual void setThreadId(DWORD threadId);
};

/////////////////////////////////////////////////////////////
// A resgen log record the fatal log and its detail
// When sending log, it means that resgen may stop becaused of 
// the error
////////////////////////////////////////////////////////////
class ResgenFatalErrorLog: public ResgenLog{
protected:
    // Don't use wstring in resgen mingw gcc environment (11B)
    // since the wmemset in the lib may cuase invalied memory access system exception
    // So we have to use low level wchar_t string to record log messages
    wchar_t detailMessage[RES_LOG_DEFAULT_MSG_BUF_SIZE];
    wchar_t suggestion[RES_LOG_DEFAULT_MSG_BUF_SIZE];

public:
    ResgenFatalErrorLog(IResgenLogger* source, const char* tag, const char * message, const int level, const char* detail, const char* suggestion);
    ResgenFatalErrorLog(IResgenLogger* source, const char* tag, const wchar_t * message, const int level, const wchar_t* detail, const wchar_t* suggestion);
    virtual void setDetailedMessage(const wchar_t * detail);
    virtual void setSuggestion(const wchar_t * suggestion);
    virtual void setDetailedMessage(const char * detail);
    virtual void setSuggestion(const char * suggestion);
    virtual const wchar_t * getDetailedMessage();
    virtual const wchar_t * getSuggestion();
    virtual const wchar_t * toString(wchar_t* buffer, unsigned int bufferSizeInWcharT);
};

/////////////////////////////////////////////////////////////
// IResgenLogFilter determines whether the log must be handler
////////////////////////////////////////////////////////////

class IResgenLogFilter{
public:
    virtual int isFilter(IResgenLog * logMsg) = 0;
};

/////////////////////////////////////////////////////////////
// IResgenLogHandler handle the log and output to the destation
////////////////////////////////////////////////////////////
class IResgenLogHandler{
public:
    virtual void handle(IResgenLog* log)=0;
};

/////////////////////////////////////////////////////////////
// IResgenLoggger define the interface to handle a specified 
// component's log message.
// All logger design in Resgen framework must implement this
// interface
////////////////////////////////////////////////////////////
class IResgenLogger{
public:
    virtual string& getName()=0;
    virtual void setName(string& name)=0;
    virtual void addLogFilter(IResgenLogFilter *logFilter)=0;
    virtual void addHandler(IResgenLogHandler * handler)=0;
    virtual void log(IResgenLog *log)=0;
};

/////////////////////////////////////////////////////////////
// A resgen Logger handle a specified component's log message
////////////////////////////////////////////////////////////
class ResgenLogger: public IResgenLogger{
protected:
    string name;
    vector<IResgenLogFilter *> filters;
    vector<IResgenLogHandler *> handlers;
    void launchHandlers(IResgenLog *log);
    void handleLog(IResgenLog* log);

public:
    virtual string& getName();
    virtual void setName(string& name);
    virtual void addLogFilter(IResgenLogFilter *logFilter);
    virtual void addHandler(IResgenLogHandler * handler);
    virtual void log(const char* tag, const wchar_t * msg, const int level);
    virtual void log(const char* tag, const char * msg, const int level);
    virtual void log(IResgenLog *log);

};

/////////////////////////////////////////////////////////////
// A resgen Logger supporting pendding log functionality
////////////////////////////////////////////////////////////
class ResgenPendingLogger: public ResgenLogger{
protected:
    vector<IResgenLog*> peddingLogs;
public:
    virtual void log(IResgenLog *log); // Override Log, just push the log object to queue and not invoke hanlder immediately
    virtual void flushPendingLogs();
    virtual int hasPendingLogs();
};

////////////////////////////////////////////////////
// Default Implementation of IResgenLogFilter
////////////////////////////////////////////////////
class LevelLogFilter:public IResgenLogFilter{
private:
    int maxLevel;
public:
    LevelLogFilter(int _maxLevel);
    int getMaxLevel();
    void setMaxLevel(int maxLevel);
    virtual int isFilter(IResgenLog * logMsg);
};


////////////////////////////////////////////////////
// Default log handler, Output the log to stdout
////////////////////////////////////////////////////

class DefaultResgenLogHandlerAdaptor:public IResgenLogHandler{
protected:
    HANDLE stdMutex; 
public:
    DefaultResgenLogHandlerAdaptor();
    ~DefaultResgenLogHandlerAdaptor();
    virtual void handle(IResgenLog* log);
};



////////////////////////////////////////////////////
// Res log manager service
////////////////////////////////////////////////////

class ResgenLogManager{
private:
    static ResgenLogManager * instance;
    IResgenLogger* defaultLogger;
    IResgenLogger* fatalErrorPendingLogger;

    IResgenLogHandler* defaultHandler;
    IResgenLogFilter* defaultLogFilter;
    ResgenLogManager();

public:
    static ResgenLogManager* getInstance();
    static IResgenLogger* getDefaultLogger();
    static IResgenLogger* getFatalErrorPendingLogger();
    static void setDefaulFilterLevel(int level);
    void start();
    void stop();
};

////////////////////////////////////////////////////
// ResgenLog Utility Class
////////////////////////////////////////////////////
class ResgenUtility{
public:
    static int secureStringCopy(wchar_t* dest, unsigned int destSizeLimit, const wchar_t* source, unsigned int sourceSizeLimit);
    static int secureStringCopy(char* dest, unsigned int destSizeLimit, const char* source, unsigned int  sourceSizeLimit);
    static int secureCharToWChar(wchar_t* dest, unsigned int destSizeLimit, const char* source, unsigned int sourceSizeLimit);
};

#endif

