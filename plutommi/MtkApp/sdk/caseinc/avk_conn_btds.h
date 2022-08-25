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
#ifndef AVK_CONN_BTDS_H
#define AVK_CONN_BTDS_H
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#if 1
#include "MMI_include.h"


/************************************************************************/
/* DS VECTOR START                                                      */
/************************************************************************/
#define LOG_FOLDER ((WCHAR*)L"DS_LOG\\")
#define LOG_FILE L"ds.txt"

#define DS_BUF_SIZE 512

#define DS_FALSE (0)
#define DS_TRUE (!0)
#define MAX_TXT 14

#ifdef vs_test_item_enum
#undef vs_test_item_enum
#endif

typedef S32 vs_test_item_enum;

//#define BT_RES_ITEM

typedef void* DS_HANDLE;
typedef U32 DS_U32;
typedef S32 DS_S32;
typedef S8 DS_S8;
typedef U8 DS_U8;
typedef S16 DS_S16;
typedef WCHAR DS_U16;
typedef MMI_BOOL DS_BOOL;

extern "C" FS_HANDLE vs_bt_ds_fileopen(const DS_U16* name);
extern "C" DS_S32 vs_bt_ds_filewrite(FS_HANDLE hdl, const DS_U16* txt, UINT size);
extern "C" DS_S32 vs_bt_ds_fileread(FS_HANDLE hdl, DS_U16* txt, UINT size);
extern "C" DS_S32 vs_bt_ds_fileclose(FS_HANDLE hdl);

#if defined(WIN32) && defined(_DEBUG)


extern "C" void vs_bt_win32_setdata(int line, const char* file);
extern "C" void vs_bt_win32_outlog(const char* log, ...);

#define DS_OUTLOG vs_bt_win32_setdata(__LINE__, __FILE__); vs_bt_win32_outlog 


#else /* defined(WIN32) && defined(_DEBUG) */


extern "C"  void vs_bt_target_setdata(DS_S32 line, const DS_S8* file);
extern "C"  void vs_bt_target_outfile(const DS_S8* log, ...);
extern "C"  void vs_bt_target_catcher(const DS_S8* log, ...);

#undef DS_OUTLOG
#define DS_OUTLOG(...)

#undef DS_OUTLOG
#define DS_OUTLOG vs_bt_target_setdata(__LINE__, __FILE__); vs_bt_target_catcher

#undef DS_OUTLOG
#define DS_OUTLOG vs_bt_target_setdata(__LINE__, __FILE__); vs_bt_target_outfile


#endif /* defined(WIN32) && defined(_DEBUG) */

extern "C" U8 vs_str2hex(const CHAR * str);

#endif /* 1 */

#endif /* __MAUI_SDK_TEST__ */

#endif /* AVK_CONN_BTDS_H */
