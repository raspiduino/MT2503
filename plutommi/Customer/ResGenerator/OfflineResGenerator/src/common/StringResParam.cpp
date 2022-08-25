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
 *    StringResParam.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   String resource population parameter object implementaion
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


//////////////////////////////////////////////////////
// Implementation of Class : StringResParam
//////////////////////////////////////////////////////

// Member function implementation
void StringResParam::toString(string * result){
    stringstream oss;
    string tmpString = *(this->defaultString);
    DAOHelper::stringEscapeNewLine(&tmpString);

    oss << this->idEnumValue<<'\t';
    oss << *(this->idEnumString)<<'\t';
    oss << *(this->description)<<'\t';
    oss << *(this->resFilePath)<<'\t';
    oss << this->noCompiling<<'\t';
    oss <<tmpString<<'\t';
    oss << *(this->appId) <<'\t';

    *result =  oss.str();
}

StringResParam::StringResParam(){
    this->init();
}

// Implementation of StringResParam
StringResParam::StringResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling, string * _defaultString){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setDefaultString(_defaultString);
}

// Implementation of StringResParam
StringResParam::StringResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
}
StringResParam::StringResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling,  char * _defaultString){
	//cout<<"create: "<<_idEnumString<<endl;
    init();
	//cout<<"setIdEnumValue: "<<_idEnumValue<<endl;
	this->setIdEnumValue(_idEnumValue);
	//cout<<"setIdEnumString: "<<_idEnumString<<endl;
    this->setIdEnumString(_idEnumString);
    //cout<<"setDescription: "<<_description<<endl;
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    //cout<<"setDefaultString: "<<_defaultString<<endl;
    this->setDefaultString(_defaultString);
    //cout<<"Finished StringResParam creation"<<endl;
}

StringResParam::~StringResParam(){
    delete this->idEnumString;
    delete this->description;
    delete this->resFilePath;
    delete this->defaultString;
    delete this->appId;
}



void StringResParam::init(){
    ResPopParam::init();
    this->defaultString = new string("");
    this->noCompiling = 1;
}

string * StringResParam::getDefaultString(){
    return this->defaultString;
}

void StringResParam::setDefaultString(string * _defaultString){
    *(this->defaultString) = *(_defaultString);
}
void StringResParam::setDefaultString(char * _defaultString){
    *(this->defaultString) = _defaultString;
}


//////////////////////////////////////////////////////
// Implementation of Class : StringParamTextFileDAO
//////////////////////////////////////////////////////

void StringParamTextFileDAO::toSerializedString(ResPopParam * _param, string * strLine){
    string temp("");
    _param->toString(&temp);
    *strLine = temp;
}

ResPopParam* StringParamTextFileDAO::parseResParam(string * strLine){
    if(strLine == NULL || *strLine == ""){
        return NULL;
    }

    StringResParam * param= new StringResParam();
    vector<string> tokens;
    unsigned int enumId = 0;
    int isNoCompiled = -1;
    DAOHelper::stringTokenize(*strLine, tokens);

    std::stringstream strStream(tokens[0]);
    strStream>>enumId;
    strStream.clear();
    strStream.str("");
    strStream<<tokens[4];
    strStream>>isNoCompiled;
    param->setIdEnumValue(enumId);
    param->setIdEnumString(&tokens[1]);
    param->setAppId(&tokens[6]);
    param->setDescription(&tokens[2]);
    param->setResFilePath(&tokens[3]);
    param->setNoCompiling(isNoCompiled);
    //if(tokens.size()>5){
    DAOHelper::stringRecoverEscapedNewLine(&tokens[5]);
    //}
    param->setDefaultString(&tokens[5]);
    return param;

}
