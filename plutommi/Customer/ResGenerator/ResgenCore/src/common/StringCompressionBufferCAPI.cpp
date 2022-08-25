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
 *   C language API to construct string decompressed structure and symbol
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 

#include "StringCompressionBuffer.h"
#include "StringCompressionBufferCAPI.h"

static StrDecompressionBufferCreator *strDecompressBufferCreator = NULL;


int InitStrDeCompressionBufferCreator(void){
    if(strDecompressBufferCreator != NULL){
        delete strDecompressBufferCreator;
    }
    strDecompressBufferCreator = new StrDecompressionBufferCreator();
    strDecompressBufferCreator->setSingleStrResEnabled(1);
    return 1;
}

int DenitStrDeCompressionBufferCreator(){
    if(strDecompressBufferCreator != NULL){
        delete strDecompressBufferCreator;
    }
    return 1;
}

void StrDeCompressBufGetStrResSymbol(int index, char * symbolBuf, int len){
    string *tmp = strDecompressBufferCreator->getStrResBufferSymbol(index);
    strncpy(symbolBuf,tmp->c_str(),len);
    delete tmp;
}

void StrDeCompressBufGetStrMapSymbol(int index, char *  symbolBuf, int len){
    string *tmp = strDecompressBufferCreator->getStrMapBufferSymbol(index);
    strncpy(symbolBuf,tmp->c_str(),len);
    delete tmp;
}
void StrDeCompressBufGetDupStrResSymbol( char *  symbolBuf,  int len){
    string *tmp = strDecompressBufferCreator->getDupStrResBufferSymbol();
    strncpy(symbolBuf,tmp->c_str(),len);
    delete tmp;
}

void StrDeCompressBufGetFixedStrResSymbol(char *  symbolBuf, int len){
    string *tmp = strDecompressBufferCreator->getFixedStrResBufferSymbol();
    strncpy(symbolBuf,tmp->c_str(),len);
    delete tmp;
}
void StrDeCompressBufGetFixedStrMapSymbol(char *  symbolBuf, int len){
    string *tmp = strDecompressBufferCreator->getFixedStrMapBufferSymbol();
    strncpy(symbolBuf,tmp->c_str(),len);
    delete tmp;
}
const char * StrDeCompressBufGetDeclartionStatements(){
    return strDecompressBufferCreator->getDeclartionStatements()->c_str();
}
const char * StrDeCompressBufGetDefinitionStatements(long reservedSize){
    return strDecompressBufferCreator->getDefinitionStatements(reservedSize)->c_str();
}


int StrDeCompressBufAddStrBuf(int resSize, int mapSize, int is16Bit){
    strDecompressBufferCreator->addStrBufferByLang(resSize,mapSize,is16Bit);
    return 1;

}

int StrDeCompressBufSetFixedStrBuf(int resSize, int mapSize, int is16Bit){
    strDecompressBufferCreator->setFixedStrBuffer(resSize,mapSize,is16Bit);
    return 1;

}
int StrDeCompressBufSetDupStrBuf(int resSize){
    strDecompressBufferCreator->setDupStrBuffer(resSize);
    return 1;
}
