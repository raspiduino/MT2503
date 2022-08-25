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
 *   StringCompressionBuffer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    Construct string decompressed structure and symbol
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
 
#ifndef __STRING_CONPRESSION_BUFFER_H__
#define __STRING_CONPRESSION_BUFFER_H__

#include <iostream>  
//#include <fstream>  
#include <sstream>  
#include <string>
//#include <map>
#include <vector>
#include "ResgenCatConfig.h"

#define STRING_COMPRESSION_USER_RESERVED_ZI_SIZE "USER_RESERVED_BUFFER_BYTES"
#define STRING_COMPRESSION_USER_RESERVED_ZI_TYPE "U8"
#define STRING_COMPRESSION_USER_RESERVED_ZI_SYMBOL "decompressedReservedSpace"

#define STRING_COMPRESSION_USER_RESERVED_ZI_SIZE "USER_RESERVED_BUFFER_BYTES"
#define STRING_COMPRESSION_USER_RESERVED_ZI_TYPE "U8"
#define STRING_COMPRESSION_USER_RESERVED_ZI_SYMBOL "decompressedReservedSpace"

#define STRING_COMPRESSION_INITIAL_ZI_TYPE "struct StrResStruct"
#define STRING_COMPRESSION_INITIAL_ZI_SYMBOL "StrRes"
#define STRING_COMPRESSION_INITIAL_ZI_SIZE_SYMBOL "mtk_gStrResSize"

#define STRING_COMPRESSION_STRRES_ITEM_TYPE "CUSTOM_STRING"
#define STRING_COMPRESSION_STRMAP_16_ITEM_TYPE "CUSTOM_STRING_MAP_16"
#define STRING_COMPRESSION_STRMAP_32_ITEM_TYPE "CUSTOM_STRING_MAP"

#define STRING_COMPRESSION_GSTRLIST_STRRES_TYPE "CUSTOM_STRING*"
#define STRING_COMPRESSION_GSTRLIST_STRMAP_TYPE "void *"

#define STRING_COMPRESSION_STRRES_ZI_SYMBOL_PREFIX "strRes"
#define STRING_COMPRESSION_STRMAP_ZI_SYMBOL_PREFIX "strMap"
#define STRING_COMPRESSION_FIXED_STRRES_ZI_SYMBOL "strRes_Fixed"
#define STRING_COMPRESSION_FIXED_STRMAP_ZI_SYMBOL "strMap_Fixed"
#define STRING_COMPRESSION_DUP_STRRES_ZI_SYMBOL "strRes_Dup"


using namespace std;

class StrDecompressionBufferCreator;
class StrDecompressionBufferModel;
class StrMemBuffer;

class StrMemBuffer{
private:
    string symbolName;
    long size;
    string typeName;
public:
    StrMemBuffer(const char * symbolName, const char* typeName,int size);
    string& getSymbolName();
    long getSize();
    string& getTypeName();
};


class StrDecompressionBufferModel{
private:
    vector<StrMemBuffer*> strResMemBufs;
    vector<StrMemBuffer*> strMapMemBufs;
    StrMemBuffer* fixedStrResMemBuf;
    StrMemBuffer* fixedStrMapMemBuf;
    StrMemBuffer* dupStrResMemBuf;
public:
    StrDecompressionBufferModel();
    int addStrBufferByLang(StrMemBuffer * resBuf,StrMemBuffer *mapBuf);
    int setDupStrBuffer(StrMemBuffer * mapBuf);
    int setFixedStrBuffer(StrMemBuffer * resBuf,StrMemBuffer * mapBuf);
    StrMemBuffer * getStrResBuffer(unsigned int);
    StrMemBuffer * getStrMapBuffer(unsigned int);
    StrMemBuffer * getFixedStrResBuffer();
    StrMemBuffer * getFixedStrMapBuffer();
    StrMemBuffer * getDupStrResBuffer();
    int getTotalLanguages();
    ~StrDecompressionBufferModel();
};

class StrDecompressionBufferCreator{
private:
    string declartionStr;
    string definitionStr;
    StrDecompressionBufferModel model;
    string& getBufferEntryDeclaration(string& tempStr, StrMemBuffer * tempBuf);
    int singleStrResEnabled;

public:
    static char * STR_RES_TYPE;
    static char * STR_MAP_16_TYPE;
    static char * STR_MAP_32_TYPE;

    void setSingleStrResEnabled(int enabled);
    int setSingleStrResEnabled(void);

    StrDecompressionBufferCreator();
    int addStrBufferByLang(int resSize, int mapResSize, int is16Bit);
    int setDupStrBuffer(int resSize);
    int setFixedStrBuffer(int resSize, int mapResSize, int is16Bit);
    string * getDeclartionStatements();
    string * getDefinitionStatements(long reservedSize);
    string * getStrResBufferSymbol(int langIndex);
    string * getStrMapBufferSymbol(int langIndex);
    string * getFixedStrResBufferSymbol();
    string *getFixedStrMapBufferSymbol();
    string *getDupStrResBufferSymbol();

};

#endif //__STRING_CONPRESSION_BUFFER_H__
