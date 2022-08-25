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
 *    ResgenLogManager.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resgen log manager implementation
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
#include "ResgenLogCAPI.h"

////////////////////////////////////////////////
// Class ResgenLogManager Implementation
////////////////////////////////////////////////
ResgenLogManager* ResgenLogManager::instance = NULL;

ResgenLogManager::ResgenLogManager(){
    defaultLogger = NULL;
    fatalErrorPendingLogger = NULL;
    defaultLogFilter =NULL;
    defaultHandler =NULL;
}

ResgenLogManager* ResgenLogManager::getInstance(){

    if(instance==NULL){
        instance=new ResgenLogManager();
    }
    return instance;
}

IResgenLogger* ResgenLogManager::getDefaultLogger(){
    IResgenLogger *tmp = getInstance()->defaultLogger;
    if(tmp == NULL){
        cout<<"[ERROR][LOG] Please invoke start() before ResgenLogManager::getDefaultLogger"<<endl;
    }
    return tmp;
}

IResgenLogger* ResgenLogManager::getFatalErrorPendingLogger(){

    IResgenLogger *tmp = getInstance()->fatalErrorPendingLogger;
    if(tmp == NULL){
        cout<<"[ERROR][LOG] Please invoke start() before ResgenLogManager::getFatalErrorPendingLogger"<<endl;
    }
    return tmp;
}
void ResgenLogManager::setDefaulFilterLevel(int level){
    IResgenLogFilter *tmp = getInstance()->defaultLogFilter;
    if(tmp == NULL){
        cout<<"[ERROR][LOG] Please invoke start() before ResgenLogManager::setDefaulFilterLevel"<<endl;
    }else{
        ((LevelLogFilter *)tmp)->setMaxLevel(level);
    }
}

void ResgenLogManager::start(){
    defaultLogger = new ResgenLogger();
    fatalErrorPendingLogger = new ResgenPendingLogger();
    defaultHandler = new DefaultResgenLogHandlerAdaptor();
    defaultLogger->addHandler(defaultHandler);
    defaultLogFilter = new LevelLogFilter(ResgenLog::LEVEL_VERBOSE);
    defaultLogger->addLogFilter(defaultLogFilter);
    fatalErrorPendingLogger->addHandler(defaultHandler);
}
void ResgenLogManager::stop(){
    delete defaultLogger;
    defaultLogger = NULL;
    delete fatalErrorPendingLogger;
    fatalErrorPendingLogger = NULL;
    delete defaultLogFilter;
    defaultLogFilter =NULL;
    delete defaultHandler;
    defaultHandler =NULL;
}
