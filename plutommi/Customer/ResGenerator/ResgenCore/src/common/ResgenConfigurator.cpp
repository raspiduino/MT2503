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
 *   ResgenConfigurator.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of Resgen Configurator
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "ResgenConfigurator.h"
#include "ResgenLogCAPI.h"

#define RESGEN_CONFIG_LOG_TAG "RESGENCONFIGURATOR"

// For GCC
#define RESCONG_LOG_D(format, args...) RES_LOG_D((RESGEN_CONFIG_LOG_TAG), (format) , ##args)
#define RESCONG_LOG_V(format, args...) RES_LOG_V((RESGEN_CONFIG_LOG_TAG), (format) , ##args)
#define RESCONG_LOG_W(format, args...) RES_LOG_W((RESGEN_CONFIG_LOG_TAG), (format) , ##args)
#define RESCONG_LOG_E(format, args...) RES_LOG_E((RESGEN_CONFIG_LOG_TAG), (format) , ##args)

// For VC++
// #define RESCONG_LOG_D(format, ...) RES_LOG_D((RESGEN_CONFIG_LOG_TAG), (format) , ##__VA_ARGS__)
// #define RESCONG_LOG_V(format, ...) RES_LOG_V((RESGEN_CONFIG_LOG_TAG), (format) , ##__VA_ARGS__)
// #define RESCONG_LOG_W(format, ...) RES_LOG_W((RESGEN_CONFIG_LOG_TAG), (format) , ##__VA_ARGS__)
// #define RESCONG_LOG_E(format, ...) RES_LOG_E((RESGEN_CONFIG_LOG_TAG), (format) , ##__VA_ARGS__)


/////////////////////////////////////////////////////////////////////
//  Class ResgenConfigurator Implementation
/////////////////////////////////////////////////////////////////////

// static members
ResgenConfigurator* ResgenConfigurator::instance = NULL;
const char* DEBUG_LEVEL_CONFIG_CSTR[4]={"debug","verbose","warn","error"};
const char * ResgenConfigurator::DEFAULT_CONFIG_FILE="resgen_default.cfg";
const char * ResgenConfigurator::KEY_MAX_THREAD_NUMBER="max_thread_number";
const char * ResgenConfigurator::KEY_DEBUG_LEVEL="debug_level";
const int ResgenConfigurator::DEFAULT_MAX_THREAD_NUMBER=6;
const int ResgenConfigurator::DEFAULT_DEBUG_LEVEL=RES_LOG_LEVEL_VERBOSE;

// The loadConfiguration is only for the level of ResgenConfigurator
// It is speficialized for configurtion file (not for DB and networking)
int ResgenConfigurator::loadConfiguration(const char * configFileName){
    ResgenConfiguratorPlainTextFileDAO* daoObj = new ResgenConfiguratorPlainTextFileDAO();
    daoObj->setConfigurationFile(configFileName);
    int result = loadConfiguration(daoObj);
    delete daoObj;
    return result;
}

// Common load function
int ResgenConfigurator::loadConfiguration(IResgenConfiguratorDAO * daoObj){
    if(daoObj!=NULL){
        return daoObj->loadConfiguration(this);
    }else{
        return 0;
    }
}

// ResgenConfigurator is a singleton, the constructor is not allowed to
// to use outside ResgenConfigurator.
// There is only one ResgenConfigurator object for all resgen obecjts
ResgenConfigurator *ResgenConfigurator::getInstance(){
    if(ResgenConfigurator::instance ==NULL){
        ResgenConfigurator::instance=new ResgenConfigurator();
    }
    return instance;
}

void ResgenConfigurator::release(){
    if(ResgenConfigurator::instance!=NULL){
        delete ResgenConfigurator::instance;
    }
}

ResgenConfigurator::ResgenConfigurator(){
    this->attributeMap = new map<string,string>();
}

ResgenConfigurator::~ResgenConfigurator(){
    delete this->attributeMap;
}

int ResgenConfigurator::getIntAttribute(const char* key, int defaultValue){
    const char * attr = this->getAttribute(key);
    if(attr == NULL){
        RESCONG_LOG_W("ResgenConfigurator::getIntAttribute(), KEY:%s not found",key);
        return defaultValue;
    }
    string strAttr(attr);
    stringstream ss;
    ss.clear();
    ss.str(attr);
    int intAttr = defaultValue;
    try{
        ss>>intAttr;
    }catch(...){
        RESCONG_LOG_W("ResgenConfigurator::getIntAttribute, %s is not a number, return default value %d", attr,defaultValue);
        intAttr = defaultValue;
    }
    return intAttr;
}

int ResgenConfigurator::getMaxThreadNumber(){
    int threadCount = getIntAttribute(KEY_MAX_THREAD_NUMBER,DEFAULT_MAX_THREAD_NUMBER);
    if(threadCount< 1){
        return 1;
    }else{
        return threadCount;
    }
}

void ResgenConfigurator::setMaxThreadNumber(int maxThreadNumber){
    this->setAttribute(KEY_MAX_THREAD_NUMBER,maxThreadNumber);
}

int ResgenConfigurator::getDebugLevel(){
    const char * levelCStr = getAttribute(KEY_DEBUG_LEVEL);
    
    if(levelCStr==NULL){
        return ResgenConfigurator::DEFAULT_DEBUG_LEVEL;
    }

    string levelStr(levelCStr);
    int returnLevel=ResgenConfigurator::DEFAULT_DEBUG_LEVEL;
    for(int i = RES_LOG_LEVEL_DEBUG;i<=RES_LOG_LEVEL_ERR; i++){
        if(levelStr==DEBUG_LEVEL_CONFIG_CSTR[i]){
            returnLevel = i;
        }
    }
    return returnLevel;
}

void ResgenConfigurator::setDebugLevel(int level){
    if(level>=RES_LOG_LEVEL_DEBUG && level <=RES_LOG_LEVEL_ERR){
        this->setAttribute(KEY_DEBUG_LEVEL,DEBUG_LEVEL_CONFIG_CSTR[level]);
    }
}


const char* ResgenConfigurator::getAttribute(const char * key){
    string trimIdStr(key);
    DAOHelper::StringTrim(trimIdStr);

    map<string, string>::iterator iterator;
    iterator = this->attributeMap->find(trimIdStr);

    if(iterator != this->attributeMap->end()){
        return (iterator->second).c_str();
    }else{
        return NULL;
    }
}

void ResgenConfigurator::setAttribute(const char * key, const char* value){
    //NULL Pointer check
    if(key==NULL || value ==NULL){
        RESCONG_LOG_W("ResgenConfigurator::setAttribute error, key and value can't be NULL");
        return;
    }
    string strKey(key);
    string strValue(value);
    this->attributeMap->operator[](strKey) = strValue;    
    /* The above copy behavior may be changed as following one
    map<int,string>::iterator i = this->attributeMap->find( strKey );
    if( i != this->attributeMap->end() )
    {
    this->attributeMap->remove( i );
    this->attributeMap->insert( make_pair( strKey, strValue ) ); 
    } */

}

void ResgenConfigurator::setAttribute(const char * key, int value){
    stringstream ss;
    ss<<value;
    this->setAttribute(key, ss.str().c_str());
}

/////////////////////////////////////////////////////////////////////
//  Class ResgenConfiguratorPlainTextFileDAO Implementation
/////////////////////////////////////////////////////////////////////

string ResgenConfiguratorPlainTextFileDAO::PATTERN_COMMENT="#";

const char * ResgenConfiguratorPlainTextFileDAO::getConfigurationFile(){
    return this->configurationFile.c_str();
}

void ResgenConfiguratorPlainTextFileDAO::setConfigurationFile(const char * file){
    configurationFile = file;
}

int ResgenConfiguratorPlainTextFileDAO::isComment(string * str){
    string skipChars(" \r\n");
    if(str == NULL){
        return 0;
    }

    int start = str->find_first_not_of(skipChars);
    int patternLen = ResgenConfiguratorPlainTextFileDAO::PATTERN_COMMENT.length();
    int strLineLen = str->length();

    if(start!=string::npos &&  start<strLineLen && str->compare(start,patternLen,ResgenConfiguratorPlainTextFileDAO::PATTERN_COMMENT)==0){
        return 1;
    }else{
        return 0;
    }
}

// Load the configuration from file
// Return 1: success
// Return 0: failed
int ResgenConfiguratorPlainTextFileDAO::loadConfiguration(IResgenConfigurator * configurator){

    int result = 0;
    string * strLine = new string("");
    int paramIndex = 0;
    char oneline[1024];
    string delimiters = "=";
    vector<string> tokens;
    if(configurator== NULL){
        RESCONG_LOG_W("ResgenConfiguratorPlainTextFileDAO::loadConfiguration, configurator can't be NULL");
        return 0;
    }

    RESCONG_LOG_V("Load configuration from %s",this->configurationFile.c_str());

    ifstream inFile(this->configurationFile.c_str());  

    try{
        while (inFile)
        {

            inFile.getline(oneline, 1024);
            *strLine=oneline;
            *strLine = DAOHelper::StringTrim(*strLine);
            tokens.clear();
            //get a ID form the line
            if(strLine->length()>0 && (1 != isComment(strLine))){
                DAOHelper::stringTokenizeWithLast(*strLine, tokens,delimiters);
                std::stringstream strStream;
                if(tokens.size() >= 2 ){
                    string strKey= DAOHelper::StringTrim(tokens[0]);
                    string strValue= DAOHelper::StringTrim(tokens[1]);
                    // parse the id string representation
                    configurator->setAttribute(strKey.c_str(),strValue.c_str());
                    RESCONG_LOG_V("%s=%s",strKey.c_str(),strValue.c_str());
                }
                RESCONG_LOG_D("Parsing: %s",oneline);
            }
        }
    }catch(...){
        RESCONG_LOG_W("ResgenConfiguratorPlainTextFileDAO::loadConfiguration, file %s parsing error",this->configurationFile.c_str());
        return 0;
    }
    delete strLine;
    result = 1;
    inFile.close();
    return result;
}
