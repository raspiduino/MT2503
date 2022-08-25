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
 *   OfflineResHelper.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Utility of Offline Resgen system
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "stdafx.h"
#include <iostream>  
#include <fstream>  
#include <sstream>  
#include "OfflineResHelper.h"

using namespace std;  

const string DAOHelper::newLineToBeChecked = "\n";
const string DAOHelper::newLinePattern = "\\n";
const string DAOHelper::SLASH_ORIGINAL= "\\";
const string DAOHelper::SLASH_PATTERN = "\\\\";

const string DAOHelper::xmlSlash="\\\\\\\\";
const string DAOHelper::imagePathSlash="\\\\";
const string DAOHelper::xmlSlash_5="\\\\\\\\\\";
const string DAOHelper::xmlSlash_3="\\\\\\";

const  string DAOHelper::XML_QUOTE="\"";
const  string DAOHelper::IMAGE_PATH_QUOTE="";

//const string SPACES =" \t\r\n";

string& DAOHelper::StringTrim(string &st,const string & t){
    string d(st);
    st = rTrim(lTrim(d, t), t);
    return st;

}

string&  DAOHelper::lTrim(string &st,const string & t )  
{   
    string d(st);
    st = d.erase(0, st.find_first_not_of (t));
    return st;
}   

string& DAOHelper::rTrim(string &st,const string & t) 
{   
    string d (st);
    string::size_type i(d.find_last_not_of (t));
    if (i == string::npos){
        st ="";
    }else{
        st = d.erase(d.find_last_not_of (t) + 1) ;
    }
    return st;
}   



void DAOHelper::stringEscapeNewLine(string * dest){

    DAOHelper::stringReplaceAll(dest, &newLineToBeChecked, &newLinePattern);

}

void DAOHelper::stringRecoverEscapedNewLine(string * dest){

    DAOHelper::stringReplaceAll(dest, &newLinePattern,&newLineToBeChecked);

}

void DAOHelper::stringEscapeSlash(string * dest){

    DAOHelper::stringReplaceAll(dest, &SLASH_ORIGINAL, &SLASH_PATTERN);

}

void DAOHelper::stringRecoverEscapedSlash(string * dest){

    DAOHelper::stringReplaceAll(dest, &SLASH_PATTERN,&SLASH_ORIGINAL);

}


void DAOHelper::stringReplaceAll(string * dest, const string * toBeReplace, const string* newPart){
    string::size_type p1 = 0;// search start
    string::size_type p2 = 0;// copy start
    p2 = dest->find(*toBeReplace,p1);

    while( p1 >= 0 && p2>= 0 && p2!= string::npos){

        dest->replace(p2, toBeReplace->length(), *newPart);
        p1 = p2 + newPart->length();

        if(p1 >= dest->length() ){
            break;
        }

        p2 = dest->find(*toBeReplace,p1);
    }

}

void DAOHelper::stringTokenize(const string& str,
                               vector<string>& tokens,
                               const string& delimiters )
{
    string::size_type p1 = 0;// copy start
    string::size_type p2 = str.find_first_of(delimiters, 0); // next copy start
    string::size_type p3 = string::npos;

    while( p1>=0 &&p2 < str.length() && p2!= string::npos){
        string s = str.substr(p1, p2 - p1);
        tokens.push_back(s);
        p3 = str.find_first_of(delimiters, p2+1);
        p1 = p2+1;
        p2 = p3;

    }
}

void DAOHelper::stringTokenizeWithLast(const string& str,
                                       vector<string>& tokens,
                                       const string& delimiters )
{
    string::size_type p1 = 0;// copy start
    string::size_type p2 = str.find_first_of(delimiters, 0); // next copy start
    string::size_type p3 = string::npos;

    while( p1>=0 &&p2 < str.length() && p2!= string::npos){
        string s = str.substr(p1, p2 - p1);
        tokens.push_back(s);
        p3 = str.find_first_of(delimiters, p2+1);
        p1 = p2+1;
        p2 = p3;

    }
    string::size_type last_indx  = str.size() - 1;
    if(p1 <= last_indx){
        string last = str.substr(p1, (last_indx - p1 +1) );
        tokens.push_back(last);
    }
}

void DAOHelper::convertToResFileName(char * resFileName, char * path, char * immediateFileName, int sizeLimit){
    string inputStr = "";
    string resturnStr = "";
    
    if(path != NULL){
        inputStr = path;
    }
    if(immediateFileName!=NULL){
        inputStr += immediateFileName;
    }

    string::size_type end_pos     = inputStr.find_last_of(".");

    if(end_pos > 0 && end_pos!= string::npos){
        resturnStr = inputStr.substr(0, end_pos);
    }else{
        resturnStr = inputStr;
    }
    resturnStr +=".res";
    strncpy(resFileName, resturnStr.c_str(),sizeLimit);
}

void DAOHelper::pathCorrect(string * dest){
    const string delimiters("\\");
    string::size_type start_pos     = dest->find_first_of(delimiters, 0);
    string::size_type last_pos      = dest->find_first_not_of(delimiters, start_pos);

    while(start_pos != string::npos ){
        string::size_type len = string::npos;
        if(last_pos!=string::npos ){
            len = last_pos - start_pos;
        }else{
            len = dest->length() - start_pos;

        }

        if(len %2 !=0){
            // Correct it!!
            dest->erase(start_pos,1);
            last_pos = last_pos-1;
        }        
        start_pos     = dest->find_first_of(delimiters, last_pos);
        last_pos      = dest->find_first_not_of(delimiters, start_pos);
    }
}
