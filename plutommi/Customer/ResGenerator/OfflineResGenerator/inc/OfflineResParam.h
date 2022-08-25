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
 *   OfflineResParam.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Define interface of offline resource population parameter domain objects
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

#ifndef _OFFLINERESPARAM_H
#define _OFFLINERESPARAM_H

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>
#include <map>
#include <vector>

using namespace std;


class ResPopParam{
protected:
    unsigned int idEnumValue;
    string * appId;
    string * idEnumString;
    string * resFilePath;
    string * description;
    int noCompiling;
    virtual void init();
public:
    const static unsigned int ID_ENUM_VALUD_NOT_EXIST;
    unsigned int getIdEnumValue();
    string * getIdEnumString();
    string * getResFilePath();
    string * getDescription();
    string * getAppId();
    int isNoCompiling();

    void setIdEnumValue(int idEnumValue);
    void setIdEnumString(string *idEnumString);
    void setIdEnumString(char *idEnumString);

    void setResFilePath(string *resFilePath);
    void setResFilePath(char *resFilePath);

    void setDescription(string * description);
    void setDescription(char * description);

    void setAppId(string * appId);
    void setAppId(char* appId);

    void setNoCompiling(int noCompiling);


    virtual void toString(string * result) =0;
};

/**
* @brief StringResParam carries string poplulation
* parameters. It is also the traffic object between
* data access layer to Model/Control/View Layer
* 
*/
class StringResParam: public ResPopParam{
private:
    string * defaultString;
    virtual void init();
public:
    virtual void toString(string * result);
    StringResParam();
    StringResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath,string *_description, int _noCompiling, string* _defaultString);
    StringResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath,string *_description, int _noCompiling);
    StringResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling);
    StringResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, char* _defaultString);
    ~StringResParam();

    string * getDefaultString();
    void setDefaultString(string * _defaultString);
    void setDefaultString(char * _defaultString);
};


/**
* @brief ImageResParam carries image poplulation
* parameters. It is also the traffic object between
* data access layer to Model/Control/View Layer
* 
*/

class ImageResParam: public ResPopParam{
private:
    string * imageFilePath;
    int isMultipleBin;
    int forceType;
    int isENFB;
    int quality;
	int isCompression;
	
    virtual void init();
public:
    static int QUALITY_HIGH;
    static int QUALITY_MEDIUM;
    static int QUALITY_LOW;

    virtual void toString(string * result);
    ImageResParam();
    ImageResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath,string *_description, int _noCompiling, int _isMultipleBin, int _forceType, string * _imageFilePath, int _isENFB);
    ImageResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _isMultipleBin, int _forceType,char * _imageFilePath, int _isENFB);
    ImageResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _isMultipleBin, int _forceType,char * _imageFilePath, int _isENFB, int _xmlSource);
    ImageResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath,string *_description, int _noCompiling, int _isMultipleBin, int _forceType, string * _imageFilePath, int _isENFB,int _xmlSource);

    ~ImageResParam();
    int getIsMultipleBin();
	int getIsCompression();
    int getForceType();
    string * getImageFilePath();
    int getIsENFB();

    void setIsMultipleBin(int _isMultipleBin);
	void setIsCompression(int isCompression);
    void setForceType(int _forceType);
    void setImageFilePath(string * _imageFilePath);
    void setImageFilePath(char * _imageFilePath);
    void setIsENFB(int isENFB);
    void setQuality(int quality);
    int getQuality();

};

/**
* @brief AudioResParam carries audio poplulation
* parameters. It is also the traffic object between
* data access layer to Model/Control/View Layer
* 
*/
class AudioResParam: public ResPopParam{
private:
    string * audioFilePath;
    int isMultipleBin;
    int forceType;
    void init();
public:
    virtual void toString(string * result);
    AudioResParam();
    AudioResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath, string *_description, int _noCompiling, int _isMultipleBin, int _forceType, string * _audioFilePath);
    AudioResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _isMultipleBin, int _forceType, char * _audioFilePath);
    AudioResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath, string *_description, int _noCompiling, int _isMultipleBin, int _forceType, string * _audioFilePath, int xmlCorrect);
    AudioResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _isMultipleBin, int _forceType, char * _audioFilePath,int xmlCorrect);

    ~AudioResParam();

    int getIsMultipleBin();
    int getForceType();
    string * getAudioFilePath();

    void setIsMultipleBin(int _isMultipleBin);
    void setForceType(int _forceType);
    void setAudioFilePath(string * _audioFilePath);
    void setAudioFilePath(char * _audioFilePath);

};


/**
* @brief BinaryResParam carries audio poplulation
* parameters. It is also the traffic object between
* data access layer to Model/Control/View Layer
* 
*/
class BinaryResParam: public ResPopParam{
private:
    string * binaryFilePath;
    int binaryType;
    void init();
public:
    virtual void toString(string * result);
    BinaryResParam();
    BinaryResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath, string *_description, int _noCompiling, int _forceType, string * _audioFilePath);
    BinaryResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _forceType, char * _audioFilePath);
    BinaryResParam(int _idEnumValue, string * _idEnumString, string* _resFilePath, string *_description, int _noCompiling, int _forceType, string * _audioFilePath, int isFromXML);
    BinaryResParam(int _idEnumValue, char * _idEnumString, char * _resFilePath,char * _description, int _noCompiling, int _forceType, char * _audioFilePath, int isFromXML);

    ~BinaryResParam();

    int getBinaryType();
    void setBinaryType(int _binaryType);

    string * getBinaryFilePath();

    void setBinaryFilePath(string * _binaryFilePath);
    void setBinaryFilePath(char * _binaryFilePath);

};
#endif //_OFFLINERESPARAM_H
