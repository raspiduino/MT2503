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
 *   BinaryModeResGen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Define Binary mode resource population interface
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

#ifndef __BINARY_MODE_RES_GEN_H__
#define __BINARY_MODE_RES_GEN_H__

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <vector>


using namespace std;

///////////////////////////////////////////////////////
// Domain Objects for Resourc File Generation
//////////////////////////////////////////////////////
class ResFileGenParam{
protected:
    int type;
    string * srcPath;
    string * destPath;
public:
    static const int UNKNOWN_TYPE;
    static const int IMAGE_TYPE;
    static const int AUDIO_TYPE;
    static const int FONT_TYPE;

    int getType();
    void setType(int type);

    string * getSrcPath();
    void setSrcPath(string * srcPath);
    void setSrcPath(char * srcPath);

    string * getDestPath();
    void setDestPath(string * destPath);
    void setDestPath(char * destPath);

    virtual void toString(string * result);
    void init();

    ResFileGenParam();
    ResFileGenParam(int type,string* srcPath, string* destPath);
    ResFileGenParam(int type,char* srcPath, char* destPath);
    ~ResFileGenParam();
};

///////////////////////////////////////////////////////
// Data Access Layer Interface for Resourc File Generation
//////////////////////////////////////////////////////
class ResFileGenParamTextFileDAO{
public:
    virtual int getResFileGenParams(const char * fileName, vector<ResFileGenParam *> * params);
    virtual ResFileGenParam* parseResParam(string * strLine);
    virtual void toSerializedString(ResFileGenParam * _param, string * strLine);
    virtual int saveToFile(string * fileName, vector<ResFileGenParam *> * params);
    virtual int saveToFile(const char * fileName, vector<ResFileGenParam *> * params);
};

///////////////////////////////////////////////////////
// Data Model for Resourc File Generation
//////////////////////////////////////////////////////
class ResFileGenParamModel{
protected:
    string * repositoryFileName;
    vector<ResFileGenParam *> * orderedParams;
public:
    string * getRepositoryFileName();
    void setRepositoryFileName(char * repository);
    virtual void show();
    virtual vector<ResFileGenParam *> * getAllResFileGenParam();
    virtual void addResParam(ResFileGenParam * resPopParam);
    virtual void flush();
    virtual void loadFromRepository(ResFileGenParamTextFileDAO * daoObj);
    virtual void clear();
    ResFileGenParamModel();
    ~ResFileGenParamModel();
};

#endif //__BINARY_MODE_RES_GEN_H__
