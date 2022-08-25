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
 *    OfflineResId.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation for offline resource IDs
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

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>
#include "OfflineResParam.h"
#include "OfflineResHelper.h"
#include "OfflineResId.h"



void OfflineResID::setName(string * _name){
    this->name = *_name;
}

void OfflineResID::setName(char * _name){
    this->name = _name;
}

void OfflineResID::setValue(int _value){
    this->value = _value;
}



string * OfflineResID::getName(){
    return &(this->name);
}

unsigned int OfflineResID::getValue(){
    return this->value;
}

OfflineResID::OfflineResID(const string &_name, unsigned int _value):name(_name), value(_value){

}

OfflineResID::OfflineResID(const char * _name, unsigned int _value):value(_value){
    if(_name != NULL){
        this->name = _name;   
    }
}

string * OfflineResID::toString(){
    string * returnStr = new string("");
    stringstream oss;
    oss <<this->name<<" = "<<this->value;
    return new string(oss.str());
}

void OfflineResIdModel::show(){
    map<string, OfflineResID *>::iterator iterator;
	string * tmp = NULL;

    cout<<"=================== ResParamModel Dump ========================="<<endl;
    // Iterate All items with idValueParamsMap
    for( iterator = this->idMap.begin(); iterator != this->idMap.end(); iterator++ )
	{
        OfflineResID * idObj = iterator->second;
		if(idObj != NULL){
	        tmp = idObj->toString();
			if(tmp!=NULL){
				cout<<*tmp<<endl;
			}else{
				cout<<"Get NULL from OfflineResID object tostring ..."<<endl;
			}
		}
		else{
			cout<<"Get NULL OfflineResID object ..."<<endl;
		}
    }
	//cout<<"Leave Show..."<<endl;

}
void OfflineResIdModel::loadIds(char * fileName){
    if(fileName == NULL){
        return;
    }
    this->idMap.clear();
    string * strLine = new string("");
    int paramIndex = 0;
    char oneline[1024];
    string delimiters = "=";
    vector<string> tokens;
    ifstream inFile(fileName);  

    while (inFile)
    {

        inFile.getline(oneline, 1024);
        *strLine=oneline;
        tokens.clear();
        //get a ID form the line
        if(strLine->length()>0){
        DAOHelper::stringTokenizeWithLast(*strLine, tokens,delimiters);
        std::stringstream strStream;
        if(tokens.size() >= 2 ){
            string * tempString = new string("");
            string strId = DAOHelper::StringTrim(tokens[0]);
            unsigned int enumId = 0;
            *tempString = DAOHelper::StringTrim(tokens[1]);
            // parse the id string representation
            strStream<<*tempString;
            strStream>>enumId;
            this->addId(new OfflineResID(strId, enumId));
			delete tempString;
        }


        //cout <<"[p]"<< oneline << endl;
        	}
		}
	delete strLine;

    inFile.close();
}
void OfflineResIdModel::addId(OfflineResID * _id){
    if(_id!=NULL){
        this->idMap[*(_id->getName())] = _id;
    }else{
        cout<<"[WARNNING] id can't be NULL in OfflineResIdModel::addId"<<endl;
    }

}

OfflineResID * OfflineResIdModel::getId(string* id){
	if(id == NULL){
		return NULL;
	}
	string trimIdStr = *id;
	DAOHelper::StringTrim(trimIdStr);

	map<string, OfflineResID *> ::iterator iterator;
    iterator = this->idMap.find(trimIdStr);

    if(iterator != this->idMap.end()){
        return iterator->second;
    }else{
        return NULL;
    }
}

OfflineResID * OfflineResIdModel::getId(char* id){
    if(id == NULL){
        return NULL;
    }
    string tmp = id;
    return getId(&tmp);
}
