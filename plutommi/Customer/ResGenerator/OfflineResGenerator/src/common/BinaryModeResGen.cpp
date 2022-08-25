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
 *   BinaryModeResGen.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Binary mode resource population parameter objects implementation
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "BinaryModeResGen.h"
#include "OfflineResHelper.h"

/////////////////////////////////////////////////////////
//  Class: ResFileGenParam
/////////////////////////////////////////////////////////

const int ResFileGenParam::UNKNOWN_TYPE=0;
const int ResFileGenParam::IMAGE_TYPE=1;
const int ResFileGenParam::AUDIO_TYPE=2;
const int ResFileGenParam::FONT_TYPE=3;

void ResFileGenParam::init(){
    this->type = ResFileGenParam::UNKNOWN_TYPE;
    this->srcPath = new string("");
    this->destPath = new string("");
}

ResFileGenParam::ResFileGenParam(){
    init();
}

ResFileGenParam::ResFileGenParam(int _type, char * _srcPath, char * _destPath){
    init();
    this->setType(_type);
    this->setSrcPath(_srcPath);
    this->setDestPath(_destPath);
}

ResFileGenParam::ResFileGenParam(int _type, string * _srcPath, string * _destPath){
    init();
    this->setType(_type);
    this->setSrcPath(_srcPath);
    this->setDestPath(_destPath);
}

ResFileGenParam::~ResFileGenParam(){
    delete srcPath;
    delete destPath;
}

int ResFileGenParam::getType(){
    return this->type;
}

void ResFileGenParam::setType(int _type){
    this->type= _type;
}

string * ResFileGenParam::getSrcPath(){
    return this->srcPath;
}

void ResFileGenParam::setSrcPath(string * _srcPath){
    if(_srcPath!=NULL){
        (*this->srcPath) = *_srcPath;
    }
}
void ResFileGenParam::setSrcPath(char * _srcPath){
    if(_srcPath!=NULL){
        (*this->srcPath) = _srcPath;
    }
}

string * ResFileGenParam::getDestPath(){
    return this->destPath;

}

void ResFileGenParam::setDestPath(string * _destPath){
    if(_destPath!=NULL){
        (*this->destPath) = *_destPath;
    }
}

void ResFileGenParam::setDestPath(char * _destPath){
    if(_destPath!=NULL){
        (*this->destPath) = _destPath;
    }
}

void ResFileGenParam::toString(string * result){
    stringstream oss;

    if(this->type == ResFileGenParam::IMAGE_TYPE){
        oss <<"I"<<'\t';
    }else if(this->type == ResFileGenParam::AUDIO_TYPE){
        oss <<"A"<<'\t';
    }else if(this->type == ResFileGenParam::FONT_TYPE){
        oss <<"F"<<'\t';
    }else{
        oss <<"U"<<'\t';
    }

    oss << *(this->srcPath)<<'\t';
    oss << *(this->destPath)<<'\t';
    *result =  oss.str();
}


/////////////////////////////////////////////////////////
//  Class: ResFileGenParamModel
/////////////////////////////////////////////////////////

string * ResFileGenParamModel::getRepositoryFileName(){
    return this->repositoryFileName;
}

void ResFileGenParamModel::setRepositoryFileName(char * repository){
    if( repository!=NULL ){
        *this->repositoryFileName = repository;
    }
}



// The primary index is EnumId
void ResFileGenParamModel::addResParam(ResFileGenParam * resPopParam){
    if(resPopParam!=NULL && this->orderedParams !=NULL ){

        this->orderedParams->push_back(resPopParam);
    }else{
        cout<<"[ERROR] resPopParam can't be NULL in ResFileGenParamModel::addResParam"<<endl;
    }
}

vector<ResFileGenParam *> * ResFileGenParamModel::getAllResFileGenParam(){
    return this->orderedParams;
}


void ResFileGenParamModel::show(){
    string tmp("");
    cout<<"=================== ResFileGenParamModel Dump ========================="<<endl;
    for(unsigned int i=0;i<this->orderedParams->size();i++){
        if((*(this->orderedParams))[i]!=NULL){
            (*(this->orderedParams))[i]->toString(&tmp);
            cout <<tmp<<endl;
        }

    }

}

void ResFileGenParamModel::flush(){
    ResFileGenParamTextFileDAO * daoObj = new ResFileGenParamTextFileDAO();
    if(this->orderedParams!=NULL && this->repositoryFileName!=NULL){
        daoObj->saveToFile(this->repositoryFileName,this->orderedParams);
    }else{
        cout<< "[ERROR]: ResFileGenParamModel::flush(), param can't be NULL"<<endl;
    }

}

void ResFileGenParamModel::clear(){
    if(this->orderedParams!=NULL){
        for(unsigned int i = 0;i < this->orderedParams->size();i++){
            if((*this->orderedParams)[i] != NULL){
                delete (*this->orderedParams)[i];
            }
        }
    }
    this->orderedParams->clear();
}
void ResFileGenParamModel::loadFromRepository(ResFileGenParamTextFileDAO * daoObj){
    if(this->repositoryFileName!=NULL && this->repositoryFileName->c_str()!=NULL){

        vector<ResFileGenParam*> * tmp = new vector<ResFileGenParam*>();
        // Read All Params
        daoObj->getResFileGenParams(this->repositoryFileName->c_str(), tmp);
        // Add params to Model
        for(unsigned int i=0;i< tmp->size();i++){
            if( (*tmp)[i] != NULL){
                this->addResParam((*tmp)[i]);
            }
        }
        delete tmp;
    }

}

ResFileGenParamModel::ResFileGenParamModel(){
    this->repositoryFileName = new string("default.text");
    this->orderedParams = new vector<ResFileGenParam *>();
}

ResFileGenParamModel::~ResFileGenParamModel(){
    delete this->repositoryFileName;
    delete this->orderedParams;
}




//////////////////////////////////////////////////////
// Class: ResFileGenParamTextFileDAO
/////////////////////////////////////////////////////
int ResFileGenParamTextFileDAO::getResFileGenParams(const char * fileName, vector<ResFileGenParam *> * params){

    string * strLine = new string("");
    int paramIndex = 0;
    char oneline[1024];

    if( params==NULL || fileName ==NULL){
        return -1;
    }

    ifstream inFile(fileName);  

    while (inFile)
    {
        ResFileGenParam * paramItem = NULL;
        inFile.getline(oneline, 1024);
        *strLine=oneline;
        paramItem = this->parseResParam(strLine);
        if( paramItem !=NULL ){
            params->push_back(paramItem);
        }

    }

    inFile.close();


    return 0;
}


int ResFileGenParamTextFileDAO::saveToFile(const char * fileName, vector<ResFileGenParam *> * params){
    unsigned int i = 0;

    if( params==NULL || fileName ==NULL){
        return -1;
    }
    ofstream outfile;
    outfile.open(fileName);

    string tmp("");

    for(i=0;i<params->size();i++){
        if((*params)[i]!=NULL){
            (*params)[i]->toString(&tmp);
            outfile<<tmp<<'\n';
        }

    }
    outfile.close();
    return 0;
}

int ResFileGenParamTextFileDAO::saveToFile(string * fileName, vector<ResFileGenParam *> * params){

    if( params==NULL || fileName ==NULL|| fileName->length()==0){
        return -1;
    }

    return this->saveToFile(fileName->c_str(),params);
}

//////////////////////////////////////////////////////
// Implementation of Class : ImageParamTextFileDAO
//////////////////////////////////////////////////////
void ResFileGenParamTextFileDAO::toSerializedString(ResFileGenParam * _param, string * strLine){
    string temp("");
    _param->toString(&temp);
    *strLine = temp;
}


ResFileGenParam * ResFileGenParamTextFileDAO::parseResParam(string * strLine){
    ResFileGenParam * param= NULL;
    vector<string> tokens;
    unsigned int enumId = 0;
    int type = ResFileGenParam::UNKNOWN_TYPE;


    if(strLine == NULL || *strLine == ""){
        return NULL;
    }
    param = new ResFileGenParam();
    DAOHelper::stringTokenize(*strLine, tokens);

    std::stringstream strStream(tokens[0]);
int test =tokens[0].compare("A");
    if(tokens[0].compare("A")==0 || tokens[0].compare("a")==0){
        type = ResFileGenParam::AUDIO_TYPE;
    }else if(tokens[0].compare("I")==0 || tokens[0].compare("i")==0){
        type = ResFileGenParam::IMAGE_TYPE;
    }else if(tokens[0].compare("F")==0 || tokens[0].compare("f")==0){
        type = ResFileGenParam::FONT_TYPE;
    }else{
        type = ResFileGenParam::UNKNOWN_TYPE;
    }

    param->setType(type);
    param->setSrcPath(&tokens[1]);
    param->setDestPath(&tokens[2]);

    return param;
}
