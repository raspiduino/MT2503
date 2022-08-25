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
 *  CustDataProts.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************
   FILENAME : CustDataProts.h

      PURPOSE     : To define Common Structures used by the UI Elements and Cutomization Tool 
              for Customizing Strings and Images.

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : 2nd Oct 2003.

   Copyright (c) 2002 All rights reserved by Pixtel Communications
*************************************************************/

#ifndef _PIXCOM_CUSTDATAPROTS_H
#define _PIXCOM_CUSTDATAPROTS_H

#ifdef __RESOURCE_GEN_
#include "ResgenDataType.h"
#else // __RESOURCE_GEN_
#include "MMIDataType.h"
#endif // __RESOURCE_GEN_

typedef enum
{
    HIDE,
    SHOW
} HIDESHOW;

#define NONMOVEABLE 0x00
#define MOVEABLEWITHINPARENT 0x01
#define MOVEABLEACROSSPARENT  0x02
#define INSERTABLE              0x04
#define SHORTCUTABLE            0x08

#define MMI_RG_MENU_FLAG_NONE            0x00
#define MMI_RG_MENU_FLAG_RADIO           0x10
#define MMI_RG_MENU_FLAG_CHECKBOX        0x20

typedef enum
{
    DEFAULT,    /* Cannot be changed to list,matrix,circular */
    DISP_LIST,
    DISP_MATRIX,
    DISP_CIRCULAR_3D,
    DISP_PAGE,
    DISP_ANI_BG_LIST,
    DISP_MATRIX_EMS,
    DISP_ROTATE,
    DISP_MOTION,
    DISP_LIST_MATRIX,
    DISP_MATRIX_PAGE,
    MMI_RG_MENU_TYPE_ORIGINAL,
    MMI_RG_MENU_TYPE_APP_MAIN,
    MMI_RG_MENU_TYPE_APP_SUB,
    MMI_RG_MENU_TYPE_OPTION,
    DISP_FIXED_GRID
} DISPATTRIBUTE;

typedef enum
{
    AUTO_TYPE,
    FORCE_ABM,
    FORCE_AB2,
    FORCE_BMP,
    FORCE_ABM_SEQUENCE
} RESGEN_IMAGE_FORCETYPE;

typedef enum
{
    AUTO_ADO_TYPE,
    FORCE_ADO_MIDI
} RESGEN_AUDIO_FORCETYPE;

#define MMI_RES_FLAG_FONT_IS_ENFB 0x00000001

#ifdef DEVELOPER_BUILD_FIRST_PASS

typedef void (*FuncPtr) (void);

extern void SetStringWithDisplay(U16 nStrId, S8 *pString, S8 *pDisplay, S8 *enum_value, S8 *resfile);
extern void SetString(U16 StrId, S8 *String, S8 *enum_value, S8 *resfile);
extern void SetImage(U16 ImageId, S8 *ImgFileName, S8 *enum_value, U32 res_type, S8 *resfile);
extern void SetImageWithBufferForceType(U16 nImgId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL imgFlag, S8 *resfile, S32 froce_type);
extern void SetImageWithBuffer(U16 nImgId, S8 *pBuffName, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL imgFlag, S8 *resfile);
extern void SetAudioWithBufferForceType(U16 nAdoId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL adoFlag, S8 *resfile, S32 froce_type);
extern void SetAudioWithBuffer(U16 nAdoId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL adoFlag, S8 *resfile);
extern void SetBinaryWithBuffer(U16 res_id, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, binary_type_enum binary_type_flag, S8 *resfile);
extern void SetFontWithBuffer(U16 nFontId, S8 *filename, S8 *pDisplayName, S8 *enum_value, U32 res_type, BOOL fontFlag, S8 *resfile);
extern void SetMenuItem(U16 arg1, ...);
/* Menuitem reduce memory, move registe hilite handlers to resgen */
extern void SetMenuHiliteHandler(U16 MenuID, S8 *MenuIDEnum, S8 *FuncName);
extern void SetMenuHintHandler(U16 MenuID, S8 *MenuIDEnum, S8 *FuncName);  
extern S8 g_resmenu_filename[];
extern MMI_BOOL g_is_log;

extern void AddApp(U32 nId, S8 *pName, U16 nMinId, U16 nMaxId);
extern void SetNFBImage(S8 *filename);
#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

#ifdef DEVELOPER_BUILD_FIRST_PASS

//#include <time.h>

#define TRACETIME    //{    char ltime[9];  static clock_t tick = 0; _strtime( ltime );     printf("[Time]:%s:%d File=[%s] Line=[%d]\n", ltime, clock(), __FILE__, __LINE__); tick = clock();}

#ifdef RESXML_VC_DEBUG
#define RES_PRINT_INFO
#define RES_PRINT_ERROR
#else
#ifdef __DEVAPP_RESOURCE_OUTPUT__
#define RES_PRINT_INFO(f, a...)     {DevAppResgenTrace(f, ##a);}
#define RES_PRINT_ERROR(f, a...)    {DevAppResgenTrace(f, ##a);}
#else /* __DEVAPP_RESOURCE_OUTPUT__ */
extern void MtkResgenTrace(char *fmt,...);
#define RES_PRINT_INFO(f, a...)     {MtkResgenTrace(f, ##a);}
#define RES_PRINT_ERROR(f, a...)     MtkResgenTrace(f, ##a); 
#endif /* __DEVAPP_RESOURCE_OUTPUT__ */
#endif


#define ADD_APPLICATION_STRING(stringId, string)                            \
    RES_PRINT_INFO("ADD STRING\t(%s [%d])...\n", __FILE__, __LINE__);       \
    SetString(stringId, string, #stringId, __FILE__);                       \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_STRING2(stringId, string, display)                  \
    RES_PRINT_INFO("ADD STRING2\t(%s [%d])...\n", __FILE__, __LINE__);      \
    SetStringWithDisplay(stringId, string, display, #stringId, __FILE__);   \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_STRING3(stringId, tmp, string, display)             \
    RES_PRINT_INFO("ADD STRING3\t(%s [%d])...\n", __FILE__, __LINE__);      \
    SetStringWithDisplay(stringId, string, display, tmp, __FILE__);         \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_IMAGE(ImageId, ImgFileName)                         \
    RES_PRINT_INFO("ADD IMAGE\t(%s [%d])...\n", __FILE__, __LINE__);        \
    SetImage(ImageId, ImgFileName, #ImageId, RES_IMAGE, __FILE__);          \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_IMAGE2(ImageId, filename, display)                                  \
    RES_PRINT_INFO("ADD IMAGE2\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetImageWithBuffer(ImageId, filename, display, #ImageId, RES_IMAGE, FALSE, __FILE__);   \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_IMAGE3(ImageId, filename, display)                                  \
    RES_PRINT_INFO("ADD IMAGE3\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetImageWithBuffer(ImageId, filename, display, #ImageId, RES_IMAGE, TRUE, __FILE__);    \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_IMAGE4(ImageId, tmp, path, filename, display, isMB)                 \
    RES_PRINT_INFO("ADD IMAGE4\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    {char fullpath[150]; sprintf(fullpath, "%s%s", path, filename);                         \
        SetImageWithBuffer(ImageId, fullpath, display, tmp, RES_IMAGE, isMB, __FILE__);}    \
    RES_PRINT_INFO("\tdone.\n");
    
#define ADD_APPLICATION_IMAGE_TYPE(ImageId, filename, display, isMB, type)                                \
    RES_PRINT_INFO("ADD IMAGE TYPE\t(%s [%d])...\n", __FILE__, __LINE__);                                 \
    SetImageWithBufferForceType(ImageId, filename, display, #ImageId, RES_IMAGE, isMB, __FILE__, type);   \
    RES_PRINT_INFO("\tdone.\n");
    
#define  ADD_NFB_IMAGE(args)                                                    \
    RES_PRINT_INFO("ADD NFB IMAGE\t(%s [%d])...\n", __FILE__, __LINE__);        \
    SetNFBImage(args);                                                          \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_MEDIA(ImageId, ImgFileName)                         \
    RES_PRINT_INFO("ADD MEDIA\t(%s [%d])...\n", __FILE__, __LINE__);        \
    SetImage(ImageId,ImgFileName,#ImageId, RES_MEDIA, __FILE__);            \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_MEDIA2(ImageId, filename, display)                                  \
    RES_PRINT_INFO("ADD MEDIA2\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetImageWithBuffer(ImageId, filename, display, #ImageId, RES_MEDIA, FALSE, __FILE__);   \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_MEDIA3(ImageId, filename, display)                                  \
    RES_PRINT_INFO("ADD MEDIA3\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetImageWithBuffer(ImageId, filename, display, #ImageId, RES_MEDIA, TRUE, __FILE__);    \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_MEDIA4(ImageId, tmp, path, filename, display, isMB)                 \
    RES_PRINT_INFO("ADD MEDIA4\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    {char fullpath[150]; sprintf(fullpath, "%s%s", path, filename);                         \
        SetImageWithBuffer(ImageId, fullpath, display, tmp, RES_MEDIA, isMB, __FILE__);}    \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_AUDIO2(AudioId, filename, display)                                  \
    RES_PRINT_INFO("ADD AUDIO2\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetAudioWithBuffer(AudioId, filename, display, #AudioId, RES_AUDIO, FALSE, __FILE__);   \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_AUDIO3(AudioId, filename, display)                                  \
    RES_PRINT_INFO("ADD AUDIO3\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetAudioWithBuffer(AudioId, filename, display, #AudioId, RES_AUDIO, TRUE, __FILE__);    \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_AUDIO_TYPE(AudioId, filename, display, isMB, type)                                \
    RES_PRINT_INFO("ADD AUDIO TYPE\t(%s [%d])...\n", __FILE__, __LINE__);                                 \
    SetAudioWithBufferForceType(AudioId, filename, display, #AudioId, RES_AUDIO, isMB, __FILE__, type);   \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_BINARY(res_id, filename, type, display)                                  \
    RES_PRINT_INFO("ADD BINARY\t(%s [%d])...\n", __FILE__, __LINE__);                       \
    SetBinaryWithBuffer(res_id, filename, display, #res_id, RES_BINARY, type, __FILE__);   \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_MENUITEM(args)                                      \
    RES_PRINT_INFO("ADD MENUITEM\t(%s [%d])...\n", __FILE__, __LINE__);     \
    SetMenuItem args;                                                       \
    strcpy(g_resmenu_filename, __FILE__);                                   \
    PrintMenuItems(#args);                                                  \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_MENUITEM2(args)                                     \
    RES_PRINT_INFO("ADD MENUITEM2\t(%s [%d])...\n", __FILE__, __LINE__);    \
    SetMenuItem2 args;                                                      \
    strcpy(g_resmenu_filename, __FILE__);                                   \
    PrintMenuItems2(#args);                                                 \
    RES_PRINT_INFO("\tdone.\n");
#define ADD_APPLICATION_MENUITEM5(args)                                     \
    RES_PRINT_INFO("ADD MENUITEM5\t(%s [%d])...\n", __FILE__, __LINE__);    \
    SetMenuItem5 args;                                                      \
    strcpy(g_resmenu_filename, __FILE__);                                   \
    PrintMenuItems5(#args);                                                 \
    RES_PRINT_INFO("\tdone.\n");

/* Menuitem reduce memory, move registe hilite handlers to resgen */
#define ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MenuID, HiliteHandler)          \
    RES_PRINT_INFO("ADD HILITE HANDLER\t(%s [%d])...\n", __FILE__, __LINE__);   \
    SetMenuHiliteHandler(MenuID, #MenuID, #HiliteHandler);                               \
    RES_PRINT_INFO("\tdone.\n");

#define ADD_APPLICATION_MENUITEM_HINT_HANDLER(MenuID, HintHandler)          \
    RES_PRINT_INFO("ADD HINT HANDLER\t(%s [%d])...\n", __FILE__, __LINE__); \
    SetMenuHintHandler(MenuID, #MenuID, #HintHandler);                               \
    RES_PRINT_INFO("\tdone.\n");

#define  ADD_APPLICATION(nId, pName, nMinId, nMaxId)    \
    AddApp(nId, pName, nMinId, nMaxId);

#define RESOURCE_ID_OUT_OF_RANGE_HANDLER()  \
    do {                                    \
        RES_PRINT_INFO("[ResGen error] Use more resource IDs than pre-defined range. (%s [%d])\n", __FILE__, __LINE__); exit(2);   \
    } while (0)

#define  WM_ADDSTRINGMESSAGE  10000
#define  WM_ADDIMAGEMESSAGE   10001
#define  WM_GENSTRFILE     10003
#define  WM_GENIMGFILE     10004
#define  WM_GENMENUFILE    10005
#define  WM_CLEARFILES     10007
#define  WM_ADDAPPLICATION 10010

#else /* DEVELOPER_BUILD_FIRST_PASS */ 
#define ADD_APPLICATION_STRING(stringId,string)          NULL
#define ADD_APPLICATION_IMAGE(stringId,string)           NULL
#define ADD_APPLICATION_MEDIA(stringId,string)           NULL   /* 120304 Calvin modified for media resource */
#define ADD_APPLICATION_STRING2(stringId,string,display)    NULL
#define ADD_APPLICATION_IMAGE2(ImageId,filename,display)    NULL
#define ADD_APPLICATION_MEDIA2(ImageId,filename,display)    NULL        /* 120304 Calvin modified for media resource */
   /* 101205 audio resource Calvin Start */
#define ADD_APPLICATION_AUDIO2(AudioId,filename,display)    NULL
#define ADD_APPLICATION_AUDIO3(AudioId,filename,display)    NULL
#define ADD_APPLICATION_AUDIO_TYPE(AudioId, filename, display, isMB, type)    NULL
   /* 101205 audio resource Calvin End */
#define ADD_APPLICATION_BINARY(res_id, filename, type, display) NULL
#define ADD_APPLICATION_MENUITEM(args)          NULL
#define  ADD_APPLICATION(nId,pName,nMinId,nMaxId)  NULL
#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

#define  ADD_SCREEN_STRINGS(args)      NULL
#define  ADD_SCREEN_IMAGES(args)       NULL
#define  ADD_SCREEN_MENUS(args)        NULL
#define  APPEND_SCREEN_IMAGE_LIST(arg1,arg2) NULL
#define  APPEND_SCREEN_STRING_LIST(arg1,arg2) NULL
#endif /* _PIXCOM_CUSTDATAPROTS_H */ 

