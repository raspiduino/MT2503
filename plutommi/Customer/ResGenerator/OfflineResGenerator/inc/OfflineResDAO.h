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
 *   OfflineResDAO.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Define Data Access Layer inteface in resgen system
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

#ifndef _OFFLINERESDAO_H
#define _OFFLINERESDAO_H

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>
#include "OfflineResParam.h"
#include "OfflineResHelper.h"
using namespace std;






class ParamTextFileDAO{
protected:
    string * textFilePath;

public:
    // Befer read the params, parse function must be invoked at least one time
    virtual ResPopParam* parseResParam(string * strLine)=0;
    virtual void toSerializedString(ResPopParam * _param, string * strLine)=0;;
    virtual int getResPopParams(vector<ResPopParam *> *params);
    virtual int getResPopParams(const char * fileName, vector<ResPopParam *> * params);
    virtual int saveResPopParam(vector<ResPopParam *> *params);
    virtual int saveResPopParam(string * fileName, vector<ResPopParam *> * params);
    virtual int saveResPopParam(const char * fileName, vector<ResPopParam *> * params);
};

// Data access layer of regen parameter
class StringParamTextFileDAO: public ParamTextFileDAO{
public:
       virtual ResPopParam* parseResParam(string * strLine);
    virtual void toSerializedString(ResPopParam * _param, string * strLine);
};

// Data access layer of regen parameter
class ImageParamTextFileDAO: public ParamTextFileDAO{
public:
    virtual ResPopParam* parseResParam(string * strLine);
    virtual void toSerializedString(ResPopParam * _param, string * strLine);
};

// Data access layer of regen parameter
class AudioParamTextFileDAO: public ParamTextFileDAO{
public:
    virtual void toSerializedString(ResPopParam * _param, string * strLine);
    virtual ResPopParam* parseResParam(string * strLine);
};

// Data access layer of Binary regen parameter
class BinaryParamTextFileDAO: public ParamTextFileDAO{
public:
    virtual void toSerializedString(ResPopParam * _param, string * strLine);
    virtual ResPopParam* parseResParam(string * strLine);
};


#endif //_OFFLINERESDAO_H
