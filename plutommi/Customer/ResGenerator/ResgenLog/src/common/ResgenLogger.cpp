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
 *    ResgenLogger.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resgen logger implementation
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

#include "ResgenLogConfig.h"
#include "ResgenLogManager.h"
#include "ResgenLogCAPI.h"


//////////////////////////////////////////////////
// Class ResgenLogger Implementation
//////////////////////////////////////////////////

void ResgenLogger::launchHandlers(IResgenLog *log){
    int totalHandlers = this->handlers.size();
    if(log == NULL){
        return;
    }
    for(int i = 0;i < totalHandlers; i++){
        handlers[i]->handle(log);
    }
}

void ResgenLogger::handleLog(IResgenLog* log){
    int totalFilter = filters.size();
    int isFiltered = 0;

    if(log == NULL){
        return;
    }


    for(unsigned int i = 0; i< filters.size();i++){
        isFiltered|=filters[i]->isFilter(log);
    }

    if(isFiltered==0){
        launchHandlers(log);
    }
}



string& ResgenLogger::getName(){
    return this->name;
}

void ResgenLogger::setName(string& name){
    this->name = name;
}

void ResgenLogger::addLogFilter(IResgenLogFilter *logFilter){
    if(logFilter!= NULL){
        filters.push_back(logFilter);
    }
}

void ResgenLogger::addHandler(IResgenLogHandler * handler){
    if(handler!= NULL){
        handlers.push_back(handler);
    }
}

void ResgenLogger::log(const char* tag, const wchar_t * msg, const int level){
    IResgenLog *logObj = new ResgenLog(this,tag,msg,level);
    if( logObj!=NULL){
        this->log(logObj);
    }
    delete logObj; 
}

void ResgenLogger::log(const char* tag, const char * msg, const int level){
    IResgenLog *logObj = new ResgenLog(this,tag,msg,level);
    if( logObj!=NULL){
        this->log(logObj);
    }
    delete logObj;
}


void ResgenLogger::log(IResgenLog *logObj){
    if( logObj!=NULL){
        this->handleLog(logObj);
    }
}

//////////////////////////////////////////////////
// Class ResgenPendingLogger Implementation
//////////////////////////////////////////////////

vector<IResgenLog*> peddingLogs;
// Override Log, just push the log object to queue and not invoke hanlder immediately
void ResgenPendingLogger::log(IResgenLog *logObj){
    if(logObj!=NULL){
        this->peddingLogs.push_back(logObj);
    }
}
void ResgenPendingLogger::flushPendingLogs(){
    while(!this->peddingLogs.empty()){
        IResgenLog *logObj = this->peddingLogs.back();
        if(logObj!=NULL){
            this->handleLog(logObj);
        }
        this->peddingLogs.pop_back();
        delete logObj;
    }
}
int ResgenPendingLogger::hasPendingLogs(){
    return (!this->peddingLogs.empty());
}

