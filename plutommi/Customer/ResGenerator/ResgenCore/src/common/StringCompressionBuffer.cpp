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
 *   StringCompressionBuffer.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Construct string decompressed structure and symbol
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "StringCompressionBuffer.h"




string & StrMemBuffer::getSymbolName(){
    return this->symbolName;
}

string & StrMemBuffer::getTypeName(){
    return this->typeName;
}

long StrMemBuffer::getSize(){
    return this->size;
}

StrMemBuffer::StrMemBuffer(const char* lSymbolName, const char* lTypeName,int lSize){
    if(lSymbolName == NULL){
        symbolName = "ERROR";
    }else{
        this->symbolName = lSymbolName;
    }
    if(lTypeName == NULL){
        this->typeName = "ERROR";
    }else{
        this->typeName = lTypeName;
    }
    this->size = lSize;
};



StrDecompressionBufferModel::StrDecompressionBufferModel(){
    fixedStrResMemBuf = NULL;
    fixedStrMapMemBuf = NULL;
    dupStrResMemBuf = NULL;
}

int StrDecompressionBufferModel::addStrBufferByLang(StrMemBuffer * resBuf,StrMemBuffer *mapBuf){

    strResMemBufs.push_back(resBuf);
    strMapMemBufs.push_back(mapBuf);
    return 1;
}

int StrDecompressionBufferModel::setDupStrBuffer(StrMemBuffer * mapBuf){
    this->dupStrResMemBuf = mapBuf;
    return 1;
}

int StrDecompressionBufferModel::setFixedStrBuffer(StrMemBuffer * resBuf,StrMemBuffer * mapBuf){
    this->fixedStrMapMemBuf = mapBuf;
    this->fixedStrResMemBuf = resBuf;
    return 1;
}

StrMemBuffer * StrDecompressionBufferModel::getStrResBuffer(unsigned int index){

    if(index >= this->strResMemBufs.size() || index < 0){
        return NULL;
    }
    return this->strResMemBufs[index];

}
StrMemBuffer * StrDecompressionBufferModel::getStrMapBuffer(unsigned int index){
    if(index >= this->strMapMemBufs.size() || index < 0){
        return NULL;
    }
    return this->strMapMemBufs[index];
}
StrMemBuffer * StrDecompressionBufferModel::getFixedStrResBuffer(){
    return this->fixedStrResMemBuf;
}
StrMemBuffer * StrDecompressionBufferModel::getFixedStrMapBuffer(){
    return this->fixedStrMapMemBuf;
}
StrMemBuffer * StrDecompressionBufferModel::getDupStrResBuffer(){

    return this->dupStrResMemBuf;
}

StrDecompressionBufferModel::~StrDecompressionBufferModel(){
    if(fixedStrResMemBuf!=NULL){
        delete this->fixedStrResMemBuf;
    }
    if(fixedStrMapMemBuf!=NULL){
        delete this->fixedStrMapMemBuf;
    }
    if(dupStrResMemBuf!=NULL){
        delete this->dupStrResMemBuf;
    }
    for(int i = 0 ;i< this->strResMemBufs.size();i++){
        delete this->strResMemBufs[i];
    }

    for(int i = 0 ;i< this->strMapMemBufs.size();i++){
        delete this->strMapMemBufs[i];
    }
    this->strResMemBufs.clear();
    this->strMapMemBufs.clear();
}

int StrDecompressionBufferModel::getTotalLanguages(){
    return this->strMapMemBufs.size();
}


StrDecompressionBufferCreator::StrDecompressionBufferCreator(){
    declartionStr ="";
    definitionStr ="";
}

int StrDecompressionBufferCreator::addStrBufferByLang(int resSize, int mapResSizeInBytes, int is16Bit){
    stringstream oss;
    int langIndex = this->model.getTotalLanguages();
    string *returnStr = new string("");
    string resSymbolNameStr("");
    string mapSymbolNameStr("");

    oss<<STRING_COMPRESSION_STRRES_ZI_SYMBOL_PREFIX<<"_"<<(langIndex+1);
    resSymbolNameStr = oss.str();
    oss.str(string());
    oss.clear();

    oss<<STRING_COMPRESSION_STRMAP_ZI_SYMBOL_PREFIX<<"_"<<(langIndex+1);
    mapSymbolNameStr = oss.str();

    const char * resSymbolName = resSymbolNameStr.c_str();
    const char * mapSymbolName = mapSymbolNameStr.c_str();

    StrMemBuffer * resBuf = NULL;
    StrMemBuffer * mapBuf = NULL;
    resBuf = new StrMemBuffer(resSymbolName, StrDecompressionBufferCreator::STR_RES_TYPE, resSize);
    if(is16Bit != 0){
        mapBuf = new StrMemBuffer(mapSymbolName, StrDecompressionBufferCreator::STR_MAP_16_TYPE, mapResSizeInBytes/2 );
    }else{
        mapBuf = new StrMemBuffer(mapSymbolName, StrDecompressionBufferCreator::STR_MAP_32_TYPE, mapResSizeInBytes/4 );
    }
    return this->model.addStrBufferByLang(resBuf,mapBuf);
}

int StrDecompressionBufferCreator::setDupStrBuffer(int resSize){
    if(resSize <= 0){
        return 0;
    }
    StrMemBuffer* resBuf = new StrMemBuffer(STRING_COMPRESSION_DUP_STRRES_ZI_SYMBOL, StrDecompressionBufferCreator::STR_RES_TYPE, resSize);
    return this->model.setDupStrBuffer(resBuf);
}

int StrDecompressionBufferCreator::setFixedStrBuffer(int resSize,int mapResSizeInBytes, int is16Bit){
    StrMemBuffer * resBuf = NULL;
    StrMemBuffer * mapBuf = NULL;
    resBuf = new StrMemBuffer(STRING_COMPRESSION_FIXED_STRRES_ZI_SYMBOL, StrDecompressionBufferCreator::STR_RES_TYPE, resSize);
    if(is16Bit != 0){
        mapBuf = new StrMemBuffer(STRING_COMPRESSION_FIXED_STRMAP_ZI_SYMBOL, StrDecompressionBufferCreator::STR_MAP_16_TYPE, mapResSizeInBytes/2 );
    }else{
        mapBuf = new StrMemBuffer(STRING_COMPRESSION_FIXED_STRMAP_ZI_SYMBOL, StrDecompressionBufferCreator::STR_MAP_32_TYPE, mapResSizeInBytes/4 );
    }
    return this->model.setFixedStrBuffer(resBuf,mapBuf);
}


string * StrDecompressionBufferCreator::getStrResBufferSymbol(int langIndex){
    string * returnStr = new string("");
    if(this->singleStrResEnabled){
        (*returnStr) = "(" STRING_COMPRESSION_GSTRLIST_STRRES_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL "." STRING_COMPRESSION_STRRES_ZI_SYMBOL_PREFIX; 
    }else{
        (*returnStr) = "(" STRING_COMPRESSION_GSTRLIST_STRRES_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL ".";
        (*returnStr) += this->model.getStrResBuffer(langIndex)->getSymbolName();
    }
    return returnStr;
}

string * StrDecompressionBufferCreator::getStrMapBufferSymbol(int langIndex){
    string * returnStr = new string("");
    (*returnStr) =  "(" STRING_COMPRESSION_GSTRLIST_STRMAP_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL ".";
    (*returnStr) += this->model.getStrMapBuffer(langIndex)->getSymbolName();
    return returnStr;
}

string * StrDecompressionBufferCreator::getFixedStrResBufferSymbol(){
    string * returnStr = new string("");
    (*returnStr) = "(" STRING_COMPRESSION_GSTRLIST_STRRES_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL ".";
    (*returnStr) += this->model.getFixedStrResBuffer()->getSymbolName();
    return returnStr;
}
string *StrDecompressionBufferCreator::getFixedStrMapBufferSymbol(){
    string * returnStr = new string("");
    (*returnStr) = "(" STRING_COMPRESSION_GSTRLIST_STRMAP_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL ".";
    (*returnStr) += this->model.getFixedStrMapBuffer()->getSymbolName();
    return returnStr;
}
string *StrDecompressionBufferCreator::getDupStrResBufferSymbol(){
    string * returnStr = new string("");
    (*returnStr) = "(" STRING_COMPRESSION_GSTRLIST_STRRES_TYPE ")" STRING_COMPRESSION_INITIAL_ZI_SYMBOL ".";
    (*returnStr) += this->model.getDupStrResBuffer()->getSymbolName();
    return returnStr;
}

string& StrDecompressionBufferCreator::getBufferEntryDeclaration(string& tempStr, StrMemBuffer * tempBuf ){
    stringstream oss;
    if(tempBuf != NULL){
        oss<<tempBuf->getTypeName()<<" "<<tempBuf->getSymbolName()<<"["<<tempBuf->getSize()<<"];\n";
    }
    tempStr = oss.str();
    return tempStr;
}

string * StrDecompressionBufferCreator::getDefinitionStatements(long reservedSzie){

    stringstream oss;
    string tempStr("");
    this->definitionStr = "";
    oss<<"#define "<<STRING_COMPRESSION_USER_RESERVED_ZI_SIZE<<" "<<reservedSzie<<"\n\n";
    //struct StrResStruct{
    oss<<"struct StrResStruct{\n";
    //CUSTOM_STRING strRes[71670];

    // Create unified RES buffers
    if(this->singleStrResEnabled){
        long maxSize = 0;

        for(int i=0;i<this->model.getTotalLanguages();i++){
            long tmp = this->model.getStrResBuffer(i)->getSize();
            if(tmp > maxSize){
                maxSize = tmp;
            }
        }
        oss<<"CUSTOM_STRING strRes["<<maxSize<<"];\n";
    }    

    //CUSTOM_STRING_MAP_16 strMap_1[2862];
    //CUSTOM_STRING_MAP_16 strMap_2[2862];
    StrMemBuffer * tempBuf = NULL;
    for(int i=0;i<this->model.getTotalLanguages();i++){
        tempBuf = this->model.getStrMapBuffer(i);
        oss<<this->getBufferEntryDeclaration(tempStr,tempBuf);
        if(!this->singleStrResEnabled){
            tempBuf = this->model.getStrResBuffer(i);
            oss<<this->getBufferEntryDeclaration(tempStr,tempBuf);	
        }
        //oss<<tempBuf->getTypeName()<<" "<<tempBuf->getSymbolName()<<"["<<tempBuf->getSize()<<"];\n";
    }

    //CUSTOM_STRING strRes_Dup[1864];
    tempBuf = this->model.getDupStrResBuffer();
    if(tempBuf != NULL){
        oss<<this->getBufferEntryDeclaration(tempStr,tempBuf);
    }
    //CUSTOM_STRING strRes_Fixed[15594];
    tempBuf = this->model.getFixedStrResBuffer();
    if(tempBuf != NULL) {
        oss<<this->getBufferEntryDeclaration(tempStr,tempBuf);
    }

    //CUSTOM_STRING_MAP_16 strMap_Fixed[1462];
    tempBuf = this->model.getFixedStrMapBuffer();
    if(tempBuf != NULL){
        oss<<this->getBufferEntryDeclaration(tempStr,tempBuf);
    }

    // U8 reserved[USER_RESERVED_BUFFER_BYTES];
    if(reservedSzie >0 ){
        oss<<STRING_COMPRESSION_USER_RESERVED_ZI_TYPE<<" "<<STRING_COMPRESSION_USER_RESERVED_ZI_SYMBOL<<"["<<STRING_COMPRESSION_USER_RESERVED_ZI_SIZE<<"];\n";
    }
    oss<<"};\n";

    this->definitionStr =  oss.str();
    return &(this->definitionStr);
}
string * StrDecompressionBufferCreator::getDeclartionStatements(){
    stringstream oss;
    this->declartionStr = "";
    oss<<"__align(4) "<<STRING_COMPRESSION_INITIAL_ZI_TYPE<<" "<<STRING_COMPRESSION_INITIAL_ZI_SYMBOL<<";\n";
    oss<<"long "<<STRING_COMPRESSION_INITIAL_ZI_SIZE_SYMBOL<<" = "<<"sizeof("<<STRING_COMPRESSION_INITIAL_ZI_SYMBOL<<");\n";
    this->declartionStr=  oss.str();
    return &(this->declartionStr);
}

void StrDecompressionBufferCreator::setSingleStrResEnabled(int enabled){
    this->singleStrResEnabled = enabled;
}
int StrDecompressionBufferCreator::setSingleStrResEnabled(){
    return this->singleStrResEnabled;
}

char * StrDecompressionBufferCreator::STR_RES_TYPE  = STRING_COMPRESSION_STRRES_ITEM_TYPE; 
char * StrDecompressionBufferCreator::STR_MAP_16_TYPE  = STRING_COMPRESSION_STRMAP_16_ITEM_TYPE;
char * StrDecompressionBufferCreator::STR_MAP_32_TYPE  = STRING_COMPRESSION_STRMAP_32_ITEM_TYPE;
