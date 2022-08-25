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
 *   BinaryResParam.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of binary resource population parameter object
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


// To offline save the binary population resource
//    #define ADD_APPLICATION_BINARY(res_id, filename, type, display)                                  \
//    RES_PRINT_INFO("ADD BINARY\t(%s [%d])...\n", __FILE__, __LINE__);                       \
//    SetBinaryWithBuffer(res_id, filename, #res_id, type);   \
//    RES_PRINT_INFO("\tdone.\n");

#include "stdafx.h"

#include "OfflineResParam.h"
#include "OfflineResDAO.h"


// Member function implementation

void BinaryResParam::toString(string * result){
    stringstream oss;
    oss << this->idEnumValue<<'\t';
    oss << *(this->idEnumString)<<'\t';
    oss << *(this->description)<<'\t';
    oss << *(this->resFilePath)<<'\t';
    oss << this->noCompiling<<'\t';
    oss << this->binaryType<<'\t';
    oss << *this->binaryFilePath<<'\t';
    oss << *(this->appId)<<'\t';

    *result =  oss.str();
}

BinaryResParam::BinaryResParam(){
    this->init();
}


// Implementation of BinaryResParam
BinaryResParam::BinaryResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling, int _binaryType, string * _binaryFilePath){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);    
    this->setBinaryType(_binaryType);
    this->setBinaryFilePath(_binaryFilePath);
}

BinaryResParam::BinaryResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling, int _binaryType, char * _binaryFilePath){
    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setBinaryType(_binaryType);
    this->setBinaryFilePath(_binaryFilePath);
}
// Implementation of BinaryResParam
BinaryResParam::BinaryResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling, int _binaryType, string * _binaryFilePath, int _xmlSource){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);    
    this->setBinaryType(_binaryType);
    this->setBinaryFilePath(_binaryFilePath);
    if(_xmlSource){
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash_5,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash_3,&DAOHelper::SLASH_ORIGINAL);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
    }

}

BinaryResParam::BinaryResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling, int _binaryType, char * _binaryFilePath,int _xmlSource){
    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setBinaryType(_binaryType);
    this->setBinaryFilePath(_binaryFilePath);
    if(_xmlSource){
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash_5,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash,&DAOHelper::imagePathSlash);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::xmlSlash_3,&DAOHelper::SLASH_ORIGINAL);
        DAOHelper::stringReplaceAll(this->binaryFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
    }

}


BinaryResParam::~BinaryResParam(){
    delete this->idEnumString;
    delete this->description;
    delete this->resFilePath;
    delete this->binaryFilePath;
    delete this->appId;
}



void BinaryResParam::init(){
    ResPopParam::init();
    this->setNoCompiling(1); // Default binary resource is not need compilation
    this->binaryFilePath = new string("");

}



// Attribute Getter/Setter Functions:
// Do error check in Getter and Setter functions to
// ensure there is no unexpect attribute value to be set or
// get.


int BinaryResParam::getBinaryType(){
    return this->binaryType;
}

string * BinaryResParam::getBinaryFilePath(){
    return this->binaryFilePath;
}


void BinaryResParam::setBinaryType(int _binaryType){
    this->binaryType=_binaryType;
}
void BinaryResParam::setBinaryFilePath(string * _binaryFilePath){
    this->binaryFilePath->assign( *(_binaryFilePath));

}

void BinaryResParam::setBinaryFilePath(char * _binaryFilePath){
    if(_binaryFilePath == NULL){
        this->binaryFilePath->assign("");
    }
    else{
        this->binaryFilePath->assign(_binaryFilePath);
    }

}



void BinaryParamTextFileDAO::toSerializedString(ResPopParam * _param, string * strLine){
    string temp("");
    _param->toString(&temp);
    *strLine = temp;
}


ResPopParam * BinaryParamTextFileDAO::parseResParam( string * strLine){

    BinaryResParam * param= NULL;
    vector<string> tokens;
    unsigned int enumId = 0;
    int lIsNoCompiled = -1;
    int lIsMultipleBin = 0;
    int lBinaryType = -1;

    if(strLine == NULL || strLine->length()<=0){
        return NULL;
    }

    param = new BinaryResParam();
    DAOHelper::stringTokenize(*strLine, tokens);

    std::stringstream strStream(tokens[0]);
    strStream>>enumId;
    // Parser isNoCompiled
    strStream.clear();
    strStream.str("");
    strStream<<tokens[4];
    strStream>>lIsNoCompiled;

    // Parser binaryType
    strStream.clear();
    strStream.str("");
    strStream<<tokens[5];
    strStream>>lBinaryType;

    param->setIdEnumValue(enumId);
    param->setIdEnumString(&tokens[1]);
    param->setAppId(&tokens[7]);
    param->setDescription(&tokens[2]);
    param->setResFilePath(&tokens[3]);
    param->setNoCompiling(lIsNoCompiled);
    param->setBinaryType(lBinaryType);
    param->setBinaryFilePath(&tokens[6]);
    return param;

}
