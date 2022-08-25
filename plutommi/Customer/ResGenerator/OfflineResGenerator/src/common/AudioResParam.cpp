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
 *   AudioResParam.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio resource population parameter objects implementation
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


#include "stdafx.h"

#include "OfflineResParam.h"
#include "OfflineResDAO.h"


// Member function implementation

void AudioResParam::toString(string * result){
    stringstream oss;
    oss << this->idEnumValue<<'\t';
    oss << *(this->idEnumString)<<'\t';
    oss << *(this->description)<<'\t';
    oss << *(this->resFilePath)<<'\t';
    oss << this->noCompiling<<'\t';
    oss << this->isMultipleBin<<'\t';
    oss << this->forceType<<'\t';
    oss << *this->audioFilePath<<'\t';
    oss<< *(this->appId)<<'\t';

    *result =  oss.str();
}

AudioResParam::AudioResParam(){
    this->init();
}


// Implementation of AudioResParam
AudioResParam::AudioResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling, int _isMultipleBin, int _forceType, string * _audioFilePath){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);    
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setAudioFilePath(_audioFilePath);
}

AudioResParam::AudioResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling, int _isMultipleBin, int _forceType, char * _audioFilePath){
    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setAudioFilePath(_audioFilePath);
}
// Implementation of AudioResParam
AudioResParam::AudioResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling, int _isMultipleBin, int _forceType, string * _audioFilePath, int _xmlSource){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);    
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setAudioFilePath(_audioFilePath);
    if(_xmlSource){
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash_5,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash_3,&DAOHelper::SLASH_ORIGINAL);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
    }

}

AudioResParam::AudioResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling, int _isMultipleBin, int _forceType, char * _audioFilePath,int _xmlSource){
    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setAudioFilePath(_audioFilePath);
    if(_xmlSource){
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash_5,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::xmlSlash_3,&DAOHelper::SLASH_ORIGINAL);
        DAOHelper::stringReplaceAll(this->audioFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
    }

}


AudioResParam::~AudioResParam(){
    delete this->idEnumString;
    delete this->description;
    delete this->resFilePath;
    delete this->audioFilePath;
    delete this->appId;
}



void AudioResParam::init(){
    ResPopParam::init();
    this->setNoCompiling(1); // Default audio resource is not need compilation
    this->audioFilePath = new string("");

}



// Attribute Getter/Setter Functions:
// Do error check in Getter and Setter functions to
// ensure there is no unexpect attribute value to be set or
// get.

int AudioResParam::getIsMultipleBin(){
    return this->isMultipleBin;
}

int AudioResParam::getForceType(){
    return this->forceType;
}

string * AudioResParam::getAudioFilePath(){
    return this->audioFilePath;
}


void AudioResParam::setIsMultipleBin(int _isMultipleBin){
    this->isMultipleBin = _isMultipleBin;
}


void AudioResParam::setForceType(int _forceType){
    this->forceType=_forceType;
}
void AudioResParam::setAudioFilePath(string * _audioFilePath){
    this->audioFilePath->assign( *(_audioFilePath));

}

void AudioResParam::setAudioFilePath(char * _audioFilePath){
    if(_audioFilePath == NULL){
        this->audioFilePath->assign("");
    }
    else{
        this->audioFilePath->assign(_audioFilePath);
    }

}



void AudioParamTextFileDAO::toSerializedString(ResPopParam * _param, string * strLine){
    string temp("");
    _param->toString(&temp);
    *strLine = temp;
}


ResPopParam * AudioParamTextFileDAO::parseResParam( string * strLine){

    AudioResParam * param= NULL;
    vector<string> tokens;
    unsigned int enumId = 0;
    int lIsNoCompiled = -1;
    int lIsMultipleBin = 0;
    int lForceType = -1;

    if(strLine == NULL || strLine->length()<=0){
        return NULL;
    }

    param = new AudioResParam();
    DAOHelper::stringTokenize(*strLine, tokens);

    std::stringstream strStream(tokens[0]);
    strStream>>enumId;
    // Parser isNoCompiled
    strStream.clear();
    strStream.str("");
    strStream<<tokens[4];
    strStream>>lIsNoCompiled;
    // Parse isMultipleBin
    strStream.clear();
    strStream.str("");
    strStream<<tokens[5];
    strStream>>lIsMultipleBin;
    // Parser forceType
    strStream.clear();
    strStream.str("");
    strStream<<tokens[6];
    strStream>>lForceType;

    param->setIdEnumValue(enumId);
    param->setIdEnumString(&tokens[1]);
    param->setAppId(&tokens[8]);
    param->setDescription(&tokens[2]);
    param->setResFilePath(&tokens[3]);
    param->setNoCompiling(lIsNoCompiled);
    param->setIsMultipleBin(lIsMultipleBin);
    param->setForceType(lForceType);
    param->setAudioFilePath(&tokens[7]);
    return param;

}
