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
 *   GeneralResParamModel.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of model objects for offline resource population parameters 
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

#include "stdafx.h"

#include "OfflineResParamModel.h"
#include "OfflineResDAO.h"


//////////////////////////////////////////////////////////
// Public Static Variable
//////////////////////////////////////////////////////////

const int ResParamModel::REDUNDANT_ALLOWDED_ENABLE = 1;
const int ResParamModel::REDUNDANT_ALLOWDED_DISABLE = 0;
    

//////////////////////////////////////////////////////////
// Member Function
//////////////////////////////////////////////////////////
string * ResParamModel::getRepositoryFileName(){
    return this->repositoryFileName;
}

void ResParamModel::setRepositoryFileName(char * repository){
    if( repository!=NULL ){
        *this->repositoryFileName = repository;
    }
}


ResPopParam * ResParamModel::getResParamByEnumId(int resEnumId){
    if(this->idValueParamsMap!=NULL){
        map<int, ResPopParam *> ::iterator iterator;
        iterator = idValueParamsMap->find(resEnumId);
        if(iterator != idValueParamsMap->end()){
            return iterator->second;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}

ResPopParam * ResParamModel::getResParamByEnumIdName(string * resEnumName){
    if(this->idNameParamsMap!=NULL){
        map<string, ResPopParam *> ::iterator iterator;
        iterator = idNameParamsMap->find(*resEnumName);

        if(iterator != idNameParamsMap->end()){
            return iterator->second;
        }else{
            return NULL;
        }
    }else{
        return NULL;
    }
}

// The primary index is EnumId
void ResParamModel::addResParam(ResPopParam * resPopParam){
    if(resPopParam!=NULL){
        int enumId = resPopParam->getIdEnumValue();
        string * idName = resPopParam->getIdEnumString();
        string tmpStr;

        ResPopParam *temp = NULL;
        if(enumId == ResPopParam::ID_ENUM_VALUD_NOT_EXIST){
            resPopParam->toString(&tmpStr);
            cout<<"[WARNNING] Res ID can't be null, DUMP:\n\t"<<tmpStr<<endl;
            return;
        }
        // Check if the item is exist in map
        temp = this->getResParamByEnumId(enumId);
        if(temp == NULL && this->idValueParamsMap!= NULL ){
            if(this->idValueParamsMap!= NULL){
                (*this->idValueParamsMap)[enumId] = resPopParam;
            }else{
                cout<<"[WARNNING] idValueParamsMap NULL, ID = "<<resPopParam->getIdEnumValue()<<endl;
                return;
            }

            if( idName!= NULL && this->idNameParamsMap!=NULL){
                (*this->idNameParamsMap)[*idName] = resPopParam;
                this->orderedParams->push_back(resPopParam);
            }else{
                cout<<"[WARNNING] RES ID String can't be NULL, ID = "<<resPopParam->getIdEnumValue()<<endl;
                return;
            }

        }else{
            // ITEM is alreay populated
            // Add the item to redundantParams vector
            this->redundantParams->push_back(resPopParam);
            
            // Add to ordered population list only when redundantAllowed is set
            if(this->redundantAllowed && this->orderedParams!=NULL){
                this->orderedParams->push_back(resPopParam);
            }
        }
    }
}

vector<ResPopParam *> * ResParamModel::getAllResParams(){
    return this->orderedParams;
}


void ResParamModel::show(){
    map<int, ResPopParam *>::iterator iterator;
    cout<<"=================== ResParamModel Dump ========================="<<endl;
    // Iterate All items with idValueParamsMap
    for( iterator = this->idValueParamsMap->begin(); iterator != this->idValueParamsMap->end(); iterator++ ) {
        string tmp("");
        ResPopParam* param = iterator->second;
        param->toString(&tmp);
        cout << "[INFO] KEY: " << iterator->first << ", PARAM: (" <<tmp<< ")"<<endl;
    }


}

void ResParamModel::flush(ParamTextFileDAO * daoObj){
    if(this->orderedParams!=NULL && this->repositoryFileName!=NULL){
        daoObj->saveResPopParam(this->repositoryFileName,this->orderedParams);
		// Write out duplicated resource population
		if(this->redundantParams!=NULL){
			string * redundantDbName = new string(*(this->repositoryFileName));
			*redundantDbName = "dup_" + *redundantDbName;
			daoObj->saveResPopParam(redundantDbName,this->redundantParams);
			delete redundantDbName;
		}
    }else{
        cout<< "[ERROR]: ResParamModel::flush(), param can't be NULL"<<endl;
    }
}


void ResParamModel::loadFromRepository(ParamTextFileDAO * dao){
    if(this->repositoryFileName!=NULL && this->repositoryFileName->c_str()!=NULL){

    vector<ResPopParam*> * tmp = new vector<ResPopParam*>();
    // Read All Params
    dao->getResPopParams(this->repositoryFileName->c_str(), tmp);
    // Add params to Model
    for(unsigned int i=0;i< tmp->size();i++){
        if( (*tmp)[i] != NULL){
            this->addResParam((*tmp)[i]);
        }
    }
    delete tmp;
    }

}

void ResParamModel::setRedundantAllowed(int _redundantAllowed){
    this->redundantAllowed = _redundantAllowed;
}

int ResParamModel::getRedundantAllowed(){
    return this->redundantAllowed;
}

ResParamModel::ResParamModel(){
    this->redundantAllowed = ResParamModel::REDUNDANT_ALLOWDED_DISABLE;
    this->repositoryFileName = new string("default.text");
    this->idValueParamsMap = new map<int, ResPopParam *>();
    this->idNameParamsMap = new map<string, ResPopParam *>();
    this->redundantParams=new vector<ResPopParam *>();
    this->orderedParams = new vector<ResPopParam *>();
}

ResParamModel::~ResParamModel(){
    if(this->repositoryFileName!=NULL){
        delete this->repositoryFileName;
    }
    if(this->idValueParamsMap!=NULL){
        delete this->idValueParamsMap;
    }
    if(this->redundantParams!=NULL){
        delete this->redundantParams;
    }
    if(this->orderedParams!=NULL){
        delete this->orderedParams;
    }
}
