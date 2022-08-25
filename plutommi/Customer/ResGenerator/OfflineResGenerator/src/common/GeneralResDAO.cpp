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
 *   GeneralResDAO.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of general data access object for resource population parameters
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

#include "OfflineResDAO.h"
#include "OfflineResParamModel.h"


//////////////////////////////////////////////////////
// Implementation of ParamTextFileDAO
/////////////////////////////////////////////////////
int ParamTextFileDAO::getResPopParams(const char * fileName, vector<ResPopParam *> * params){

    string * strLine = new string("");
    int paramIndex = 0;

    if( params==NULL || fileName ==NULL){
        return -1;
    }
    char * oneline = new char[4096];
    ifstream inFile(fileName);  

    while (inFile)
    {
        ResPopParam * paramItem = NULL;
        inFile.getline(oneline, 4096);
        *strLine=oneline;
        paramItem = this->parseResParam(strLine);
        if( paramItem !=NULL ){
            params->push_back(paramItem);
        }

        //cout << oneline << endl;
    }

    inFile.close();

		delete [] oneline;
		
    return 0;
}

int ParamTextFileDAO::getResPopParams(vector<ResPopParam *> * params){

    string * strLine = new string("");

    if( params==NULL || this->textFilePath!=NULL){
    
        return -1;
    }
    char * oneline = new char[4096];

    ifstream inFile(this->textFilePath->c_str());  

    while (inFile)
    {
        ResPopParam * paramItem = NULL;
        inFile.getline(oneline, 4096);
        *strLine=oneline;
        paramItem = this->parseResParam(strLine);
        if( paramItem!=NULL){
            params->push_back(paramItem);
        }

        //cout << oneline << endl;
    }

    inFile.close();

		delete [] oneline;
    return 0;
}


int ParamTextFileDAO::saveResPopParam(const char * fileName, vector<ResPopParam *> * params){
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

int ParamTextFileDAO::saveResPopParam(string * fileName, vector<ResPopParam *> * params){

    if( params==NULL || fileName ==NULL|| fileName->length()==0){
        return -1;
    }

    return this->saveResPopParam(fileName->c_str(),params);
}

int ParamTextFileDAO::saveResPopParam(vector<ResPopParam *> * params){
    return saveResPopParam(this->textFilePath, params);
}
