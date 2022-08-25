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
 *   GeneralResParam.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Implementation of general resource population parameters
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
#include "OfflineResHelper.h"
//////////////////////////////////////////////////////
// Implementation of ResPopParam
/////////////////////////////////////////////////////

const unsigned int ResPopParam::ID_ENUM_VALUD_NOT_EXIST = 0xFFFFFFFF;

// Attribute Getters
unsigned int ResPopParam::getIdEnumValue(){
    return this->idEnumValue;
}
string * ResPopParam::getIdEnumString(){
    return this->idEnumString;
}
string * ResPopParam::getResFilePath(){
    return this->resFilePath;
}

string * ResPopParam::getDescription(){
    return this->description;
}

string * ResPopParam::getAppId(){
    return this->appId;
}

int ResPopParam::isNoCompiling(){
    return this->noCompiling;
}

// Attribute Setters

void ResPopParam::setIdEnumValue(int _idEnumString){
    this->idEnumValue = _idEnumString;
}
void ResPopParam::setIdEnumString(string *idEnumString){
    *(this->idEnumString) = *idEnumString;// Copy the enum String
    DAOHelper::StringTrim(*(this->idEnumString));
}

void ResPopParam::setIdEnumString(char *idEnumString){
    *(this->idEnumString) = idEnumString;// Copy the enum String
    DAOHelper::StringTrim(*(this->idEnumString));
}

void ResPopParam::setResFilePath(string * _resFilePath){
    *(this->resFilePath) = *_resFilePath;// Copy the enum String
}

void ResPopParam::setResFilePath(char * _resFilePath){
    *(this->resFilePath) = _resFilePath;// Copy the enum String
}

void ResPopParam::setDescription(char * _description){
    *(this->description) = _description;// Copy the enum String
}

void ResPopParam::setDescription(string * _description){
    if(_description!=NULL){
        *(this->description) = * _description;// Copy the enum String
    }
}


void ResPopParam::setAppId(string * appId){
    if(appId!=NULL){
        *(this->appId) = * appId;// Copy the enum String
    }
}
void ResPopParam::setAppId(char * appId){
    *(this->appId) = appId;// Copy the enum String
}


void ResPopParam::setNoCompiling(int _noCompiling){
    this->noCompiling = _noCompiling;
}

void ResPopParam::init(){
    this->idEnumValue = ResPopParam::ID_ENUM_VALUD_NOT_EXIST;
    this->idEnumString = new string();
    this->description = new string();
    this->resFilePath = new string();
    this->noCompiling = 1;
    this->appId = new string("APP name unknown");
}
