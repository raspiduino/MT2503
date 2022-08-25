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
 *   OfflineResParamModel.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Model object interface for offline resource population parameters
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


#ifndef _OFFLINERESPARAMMODEL_H
#define _OFFLINERESPARAMMODEL_H

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>
#include "OfflineResParam.h"
#include "OfflineResHelper.h"
#include "OfflineResDAO.h"


#define RES_PARAM_MODEL_USING_EXIST 0;
#define RES_PARAM_MODEL_CREATE_NEW 1;


using namespace std;

class ResParamModel{
protected:
  	int redundantAllowed;
    string * repositoryFileName;
    map<int, ResPopParam *> * idValueParamsMap;
    map<string,ResPopParam *> * idNameParamsMap;
    vector<ResPopParam *> * redundantParams;
    vector<ResPopParam *> * orderedParams;
public:

    static const int REDUNDANT_ALLOWDED_ENABLE;
    static const int REDUNDANT_ALLOWDED_DISABLE;

    string * getRepositoryFileName();
    void setRepositoryFileName(char * repository);

    void setRedundantAllowed(int _redundantAllowed);
    int getRedundantAllowed();

    virtual void show();
    virtual vector<ResPopParam *> * getAllResParams();
    virtual ResPopParam * getResParamByEnumId(int resEnumId);
    virtual ResPopParam * getResParamByEnumIdName(string * resEnumName);
    virtual void addResParam(ResPopParam * resPopParam);
    virtual void flush(ParamTextFileDAO * daoObj);
    virtual void loadFromRepository(ParamTextFileDAO * dao);
    ResParamModel();
    ~ResParamModel();
};

#endif // _OFFLINERESPARAMMODEL_H
