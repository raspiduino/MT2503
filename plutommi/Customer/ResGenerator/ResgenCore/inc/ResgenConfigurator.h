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
 *   ResgenConfigurator.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Interface of Resgen Configurator
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

#ifndef __RESGEN_CONFIGURATIONTOR_H__
#define __RESGEN_CONFIGURATIONTOR_H__

#include <string>
#include <map>
#include <vector>
#include "OfflineResHelper.h"

using namespace std;
class IResgenConfigurator;
class IResgenConfiguratorDAO;

class IResgenConfigurator{
public:
    virtual int loadConfiguration(IResgenConfiguratorDAO * daoObj)=0;
    virtual void setAttribute(const char * key, const char* value)=0;
    virtual void setAttribute(const char * key, int value)=0;
    virtual int getIntAttribute(const char* key,int defaultValue)=0;
    virtual const char * getAttribute(const char * key)=0;
};

class ResgenConfigurator:public IResgenConfigurator{
private:
    static ResgenConfigurator * instance;
    ResgenConfigurator();
    ~ResgenConfigurator();
protected:
    map<string,string> *attributeMap;

public:
    static const char * KEY_MAX_THREAD_NUMBER;
    static const char * KEY_DEBUG_LEVEL;
    static const int DEFAULT_MAX_THREAD_NUMBER;
    static const int DEFAULT_DEBUG_LEVEL;
    static const char * DEFAULT_CONFIG_FILE;
    static ResgenConfigurator * getInstance();
    static void release();
    virtual int loadConfiguration(IResgenConfiguratorDAO * daoObj);
    virtual const char * getAttribute(const char * key);
    virtual void setAttribute(const char * key, const char* value);
    virtual void setAttribute(const char * key, int value);
    virtual int getIntAttribute(const char* key,int defaultValue);
    int loadConfiguration(const char * configFileName);
    int getMaxThreadNumber();
    void setMaxThreadNumber(int maxThreadNumber);
    int getDebugLevel();
    void setDebugLevel(int level);
};


// Encapsulate Data Access Logic of resegn configutor
class IResgenConfiguratorDAO{
public:
    virtual int loadConfiguration(IResgenConfigurator * configurator)=0;
};

// Encapsulate Data Access Logic of resegn configutor
class ResgenConfiguratorPlainTextFileDAO:public IResgenConfiguratorDAO{
private:
    string configurationFile;
    int isComment(string * str);
public:
    static string PATTERN_COMMENT;
    void setConfigurationFile(const char * fileName);
    const char * getConfigurationFile();
    virtual int loadConfiguration(IResgenConfigurator * configurator);
};




#endif //#ifndef __RESGEN_CONFIGURATIONTOR_H__
