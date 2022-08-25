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
 *    OfflineResPopCAPI.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   C API Broker layer of offline resgen system
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

#include "OfflineResParam.h"
#include "OfflineResDAO.h"
#include "OfflineResParamModel.h"
#include "OfflineResHelper.h"
#include "OfflineResId.h"


using namespace std;

// External Interface for C sources

extern "C"{
#include "OfflineResPopCAPI.h"
}


void ConvertToResFileName(char * resFileName, char * path, char * immediateFileName, int sizeLimit){
    cout<<"ConvertToResFileName:"<<path<<","<<immediateFileName<<","<<sizeLimit<<endl;
    DAOHelper::convertToResFileName(resFileName, path, immediateFileName, sizeLimit);
    cout<<"ConvertToResFileName:"<<resFileName<<endl;
}

static OfflineResIdModel* globalIdModel = NULL;

//////////////////////////////////////////////////////////
// ID Operation Model
//////////////////////////////////////////////////////////
void OfflineIdModelInit(char * fileName){
    //cout<<"OfflineIdModelInit..."<<endl;
    globalIdModel = new OfflineResIdModel();
    globalIdModel->loadIds(fileName);
    //globalIdModel->show();	
}

void OfflineIdModelDeinit(){
    delete globalIdModel;
    //cout<<"finished deinit"<<endl;
}	

//////////////////////////////////////////////////////////
// Private Offline population control APIs
//////////////////////////////////////////////////////////

static void startOfflinePopulation(char* fileName, ResParamModel ** paramModel){
    if(*paramModel!=NULL){
        delete (*paramModel);
    }
    *paramModel = new ResParamModel();
    (*paramModel)->setRepositoryFileName(fileName);

}

static void stopOfflinePopulation(ResParamModel **paramModel, ParamTextFileDAO * daoObj){
    if( (*paramModel)!=NULL){
        (*paramModel)->flush(daoObj);
        delete (*paramModel);
        (*paramModel) = NULL;
    }
}



//////////////////////////////////////////////////////////
// String Adaptor API Implementation
//////////////////////////////////////////////////////////

static ResParamModel * strParamModel = NULL;

void StringAdaptorStartOfflinePopulation(char* fileName){
    startOfflinePopulation(fileName, &strParamModel);

}

// Flush out the entire param list
void StringAdaptorStopOfflinePopulation(){
    ParamTextFileDAO * daoObj = new StringParamTextFileDAO();
    stopOfflinePopulation(&strParamModel, daoObj);
    delete daoObj;
}

void StringAdaptorSetString(int stringId, char* stringContent, char * appId, char* desc, char * stringEnumName, char* fileName, int noCompiling){
    if(strParamModel!=NULL){
        StringResParam * param = new StringResParam(stringId,stringEnumName,fileName,desc, noCompiling,stringContent );
        param->setAppId(appId);
        strParamModel->addResParam(param);
    }else{

        cout<<"[WARNING]Please invoke StringAdaptorStartOfflinePopulation before StringAdaptorSetString"<<endl;
    }

}


//////////////////////////////////////////////////////////
// Image Adaptor API Implementation
//////////////////////////////////////////////////////////

static ResParamModel * imageParamModel = NULL;

void ImageAdaptorStartOfflinePopulation(char* fileName){
    startOfflinePopulation(fileName, &imageParamModel);
}

// Flush out the entire param list
void ImageAdaptorStopOfflinePopulation(){
    ParamTextFileDAO * daoObj = new ImageParamTextFileDAO();
    stopOfflinePopulation(&imageParamModel, daoObj);
    delete daoObj;
}


void ImageAdaptorSetImage(int imageId, char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB){
    if(imageParamModel!=NULL){
        ImageResParam * param = new ImageResParam(imageId,stringEnumName,resFilePath,desc, noCompiling, isMultipleBin, forceType, imageFilePath, isENFB, noCompiling);
        param->setAppId(appId);
        imageParamModel->addResParam(param);
    }else{
        cout<<"[WARNING]Please invoke StringAdaptorStartOfflinePopulation before StringAdaptorSetString"<<endl;
    }

}
void ImageAdaptorSetImageWithQuality(int imageId, char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB, int quality, int compression){
    if(imageParamModel!=NULL){
        ImageResParam * param = new ImageResParam(imageId,stringEnumName,resFilePath,desc, noCompiling, isMultipleBin, forceType, imageFilePath, isENFB, noCompiling);
        param->setQuality(quality);
        param->setAppId(appId);
		param->setIsCompression(compression);
        imageParamModel->addResParam(param);
    }else{
        cout<<"[WARNING]Please invoke StringAdaptorStartOfflinePopulation before StringAdaptorSetString"<<endl;
    }

}


void ImageAdaptorSetImageAutoId(char* imageFilePath,  char * appId,char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB){
    if(stringEnumName!=NULL){
        OfflineResID * idObj = globalIdModel->getId(stringEnumName);		
        ImageAdaptorSetImage(idObj->getValue(), imageFilePath,appId, desc, stringEnumName, resFilePath, noCompiling, forceType, isMultipleBin, isENFB);

    }else{
        cout<<"[WARNING][ImageAdaptorSetImageAutoId] stringEnumName can't be NULL"<<endl ;
    }
}

void ImageAdaptorSetImageAutoIdWithQuality(char* imageFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin, int isENFB, int quality, int compression){
    if(stringEnumName!=NULL){
        OfflineResID * idObj = globalIdModel->getId(stringEnumName);		
        ImageAdaptorSetImageWithQuality(idObj->getValue(), imageFilePath, appId,desc, stringEnumName, resFilePath, noCompiling, forceType, isMultipleBin, isENFB, quality, compression);
    }else{
        cout<<"[WARNING][ImageAdaptorSetImageAutoId] stringEnumName can't be NULL"<<endl ;
    }
}

//////////////////////////////////////////////////////////
// Audio Adaptor API Implementation
//////////////////////////////////////////////////////////

static ResParamModel * audioParamModel = NULL;

void AudioAdaptorStartOfflinePopulation(char* fileName){
    startOfflinePopulation(fileName, &audioParamModel);
}

// Flush out the entire param list
void AudioAdaptorStopOfflinePopulation(){
    ParamTextFileDAO * daoObj = new AudioParamTextFileDAO();
    stopOfflinePopulation(&audioParamModel, daoObj);
    delete daoObj;
}


void AudioAdaptorSetAudio(int imageId, char* audioFilePath, char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType, int isMultipleBin){
    if(audioParamModel!=NULL){
        AudioResParam * param = new AudioResParam(imageId,stringEnumName,resFilePath,desc, noCompiling, isMultipleBin, forceType, audioFilePath, noCompiling);
        param->setAppId(appId);
        audioParamModel->addResParam(param);
    }else{
        cout<<"Please invoke AudioAdaptorStartOfflinePopulation before AudioAdaptorStopOfflinePopulation"<<endl;
    }

}


//////////////////////////////////////////////////////////
// Binary Adaptor API Implementation
//////////////////////////////////////////////////////////

static ResParamModel * binaryParamModel = NULL;

void BinaryAdaptorStartOfflinePopulation(char* fileName){
    startOfflinePopulation(fileName, &binaryParamModel);
    binaryParamModel->setRedundantAllowed(ResParamModel::REDUNDANT_ALLOWDED_ENABLE);
}

// Flush out the entire param list
void BinaryAdaptorStopOfflinePopulation(){
    ParamTextFileDAO * daoObj = new BinaryParamTextFileDAO();
    stopOfflinePopulation(&binaryParamModel, daoObj);
    delete daoObj;
}


void BinaryAdaptorSetBinary(int imageId, char* audioFilePath,char * appId, char* desc, char * stringEnumName, char* resFilePath, int noCompiling, int forceType){
    if(binaryParamModel!=NULL){
        BinaryResParam * param = new BinaryResParam(imageId,stringEnumName,resFilePath,desc, noCompiling,forceType, audioFilePath,noCompiling);
        param->setAppId(appId);
        binaryParamModel->addResParam(param);
    }else{
        cout<<"Please invoke BinaryAdaptorStartOfflinePopulation before BinaryAdaptorStopOfflinePopulation"<<endl;
    }

}



