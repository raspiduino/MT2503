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
 *   ImageResParam.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of image resource population parameter
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
#include "OfflineResPopCAPI.h"


//////////////////////////////////////////////////////
// Implementation of Class : ImageResParam
//////////////////////////////////////////////////////

// Static member initialization
int ImageResParam::QUALITY_LOW = OFFLINE_IMAGE_PARAM_QUALITY_LOW;
int ImageResParam::QUALITY_HIGH = OFFLINE_IMAGE_PARAM_QUALITY_HIGH;
int ImageResParam::QUALITY_MEDIUM = OFFLINE_IMAGE_PARAM_QUALITY_MEDIUM; 


// Member function implementation

void ImageResParam::toString(string * result){
    stringstream oss;
    oss << this->idEnumValue<<'\t';
    oss << *(this->idEnumString)<<'\t';
    oss << *(this->description)<<'\t';
    oss << *(this->resFilePath)<<'\t';
    oss << this->noCompiling<<'\t';
    oss << this->isMultipleBin<<'\t';
    oss << this->forceType<<'\t';
    oss << *this->imageFilePath<<'\t';
    oss << this->isENFB<<'\t';
    oss << this->quality<<'\t';
    oss << *(this->appId)<<'\t';
	oss << this->isCompression<<'\t';
	

    *result =  oss.str();
}

ImageResParam::ImageResParam(){
    this->init();
}

// Implementation of StringResParam
ImageResParam::ImageResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling,int _isMultipleBin, int _forceType, string * _imageFilePath, int _isENFB, int _xmlSource){

    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setImageFilePath(_imageFilePath);
    this->setIsENFB(_isENFB);
    if(_xmlSource){
        //cout<<"before stringReplaceAll-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::pathCorrect(this->imageFilePath);
        //cout<<"after path correct-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::stringReplaceAll(this->imageFilePath,&DAOHelper::imagePathSlash,&DAOHelper::SLASH_ORIGINAL);
        //cout<<"after stringReplaceAll-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::stringReplaceAll(this->imageFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
        //cout<<"after stringReplaceAll2-->"<<*(this->imageFilePath)<<endl;

    }

}
ImageResParam::ImageResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling,int _isMultipleBin, int _forceType, char * _imageFilePath, int _isENFB, int _xmlSource){

    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setImageFilePath(_imageFilePath);
    this->setIsENFB(_isENFB);
    if(_xmlSource){
        //cout<<"before stringReplaceAll-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::pathCorrect(this->imageFilePath);
        //cout<<"after path correct-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::stringReplaceAll(this->imageFilePath,&DAOHelper::imagePathSlash,&DAOHelper::SLASH_ORIGINAL);
        //cout<<"after stringReplaceAll-->"<<*(this->imageFilePath)<<endl;
        DAOHelper::stringReplaceAll(this->imageFilePath,&DAOHelper::XML_QUOTE,&DAOHelper::IMAGE_PATH_QUOTE);
        //cout<<"after stringReplaceAll2-->"<<*(this->imageFilePath)<<endl;
        //cout<<*(this->imageFilePath)<<endl;
    }
}
// Implementation of StringResParam
ImageResParam::ImageResParam(int _idEnumValue, string * _idEnumString, string * _resFilePath,string * _description,int _noCompiling,int _isMultipleBin, int _forceType, string * _imageFilePath, int _isENFB){
    this->init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setImageFilePath(_imageFilePath);
    this->setIsENFB(_isENFB);

}
ImageResParam::ImageResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath, char * _description,int _noCompiling,int _isMultipleBin, int _forceType, char * _imageFilePath, int _isENFB){
    init();
    this->setIdEnumValue(_idEnumValue);
    this->setIdEnumString(_idEnumString);
    this->setDescription(_description);
    this->setResFilePath(_resFilePath);
    this->setNoCompiling(_noCompiling);
    this->setIsMultipleBin(_isMultipleBin);
    this->setForceType(_forceType);
    this->setImageFilePath(_imageFilePath);
    this->setIsENFB(_isENFB);
}

ImageResParam::~ImageResParam(){
    delete this->idEnumString;
    delete this->description;
    delete this->resFilePath;
    delete this->imageFilePath;
    delete this->appId;
}



void ImageResParam::init(){
    ResPopParam::init();
    this->imageFilePath = new string("");
    this->noCompiling = 1; // Default Image resource is not need compilation
    this->quality = QUALITY_MEDIUM;
	this->isCompression = 1;
}



// Attribute Getter/Setter Functions:
// Do error check in Getter and Setter functions to
// ensure there is no unexpect attribute value to be set or
// get.

int ImageResParam::getIsMultipleBin(){
    return this->isMultipleBin;
}

int ImageResParam::getIsCompression(){
    return this->isCompression;
}

int ImageResParam::getForceType(){
    return this->forceType;
}

string * ImageResParam::getImageFilePath(){
    return this->imageFilePath;
}

int ImageResParam::getIsENFB(){
    return this->isENFB;
}

void ImageResParam::setIsMultipleBin(int _isMultipleBin){
    this->isMultipleBin = _isMultipleBin;
}

void ImageResParam::setIsCompression(int _isCompression){
    this->isCompression = _isCompression;
}

void ImageResParam::setForceType(int _forceType){
    this->forceType=_forceType;
}
void ImageResParam::setImageFilePath(string * _imageFilePath){
    this->imageFilePath->assign( *(_imageFilePath));
    DAOHelper::StringTrim(*(this->imageFilePath));
}
void ImageResParam::setImageFilePath(char * _imageFilePath){
    if (_imageFilePath==NULL){
        this->imageFilePath->assign( "");
    }else{

        this->imageFilePath->assign( _imageFilePath);
    }
    DAOHelper::StringTrim(*(this->imageFilePath));
}

void ImageResParam::setIsENFB(int _isENFB){
    this->isENFB = _isENFB;
}

void ImageResParam::setQuality(int _quality){
    this->quality = _quality;
}

int ImageResParam::getQuality(){
    return this->quality;
}

//////////////////////////////////////////////////////
// Implementation of Class : ImageParamTextFileDAO
//////////////////////////////////////////////////////
void ImageParamTextFileDAO::toSerializedString(ResPopParam * _param, string * strLine){
    string temp("");
    _param->toString(&temp);
    *strLine = temp;
}


ResPopParam * ImageParamTextFileDAO::parseResParam(string * strLine){
    ImageResParam * param= NULL;
    vector<string> tokens;
    unsigned int enumId = 0;
    int lIsNoCompiled = -1;
    int lIsMultipleBin = 0;
    int lForceType = -1;
    int lIsENFB = -1;
    int lQuality = ImageResParam::QUALITY_MEDIUM;
	
	int lCompression = 0;

    if(strLine == NULL || *strLine == ""){
        return NULL;
    }
    param = new ImageResParam();
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

    // Parser isENFB
    strStream.clear();
    strStream.str("");
    strStream<<tokens[8];
    strStream>>lIsENFB;

    // Parse quality

    strStream.clear();
    strStream.str("");
    strStream<<tokens[9];
    strStream>>lQuality;

	//Parse isCompression
    strStream.clear();
    strStream.str("");
    strStream<<tokens[11];
    strStream>>lCompression;
	

    param->setIdEnumValue(enumId);
    param->setIdEnumString(&tokens[1]);
    param->setAppId(&tokens[10]);
    param->setDescription(&tokens[2]);
    param->setResFilePath(&tokens[3]);
    param->setNoCompiling(lIsNoCompiled);
    param->setIsMultipleBin(lIsMultipleBin);
    param->setForceType(lForceType);
    param->setImageFilePath(&tokens[7]);
    param->setIsENFB(lIsENFB);
    param->setQuality(lQuality);
	param->setIsCompression(lCompression);
	

    return param;

}
