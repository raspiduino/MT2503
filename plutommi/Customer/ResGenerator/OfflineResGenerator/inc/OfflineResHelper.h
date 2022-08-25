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
 *   OfflineResHelper.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Utility class of Offline Resgen
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

#ifndef __OFFLINE_RES_HELPER__
#define __OFFLINE_RES_HELPER__


#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>
#include "OfflineResParam.h"
using namespace std;

#define SPACES " \t\r\n"

class DAOHelper{
private:
    static string &  lTrim(string &ss ,const string & t = SPACES);
    static string & rTrim(string &ss ,const string & t= SPACES);
public:
    static string & StringTrim(string &ss,const string & t =  SPACES);
    static const string newLineToBeChecked;
    static const string newLinePattern;
    static const string SLASH_ORIGINAL;
    static const string SLASH_PATTERN;
    static const string xmlSlash;
    static const string imagePathSlash;
    static const string xmlSlash_5;
    static const string xmlSlash_3;
    static const string XML_QUOTE;
    static const string IMAGE_PATH_QUOTE;

    static void stringEscapeNewLine(string * dest);
    static void stringRecoverEscapedNewLine(string * dest);

    static void stringEscapeSlash(string * dest);
    static void stringRecoverEscapedSlash(string * dest);

    static void pathCorrect(string * dest);

    static void stringReplaceAll(string * dest, const string * toBeReplace, const string* newPart);
    static void stringTokenize(const string& str,
        vector<string>& tokens,
        const string& delimiters = "\t");
    static void stringTokenizeWithLast(const string& str,
        vector<string>& tokens,
        const string& delimiters );

    static void convertToResFileName(char * resFileName, char * path, char * immediateFileName, int sizeLimit);
		
};

#endif // __OFFLINE_RES_HELPER__
