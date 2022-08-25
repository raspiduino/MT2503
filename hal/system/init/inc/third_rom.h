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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   third_rom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"

#ifndef _THIRD_ROM_H
#define _THIRD_ROM_H

/*******************************************************************************
 * Define constants.
 *******************************************************************************/
#define MAX_CONTENT_NUMBER     (ENFB_CONTENT_LAST_ID)

#define ENFB_TBLNUM            MAX_CONTENT_NUMBER


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/
typedef struct 
{
   void        *dst_addr;
   kal_uint32   offset;
   kal_uint32   length;
} enfb_scatter;

typedef enum {
   ENFB_CONTENT_RESERVED  = 0x0,
   /* Built dynamic RO-CODE */
   /* External Binary Files */
   ENFB_CONTENT_IMAGERES,
   ENFB_CONTENT_STRINGRES,
   ENFB_CONTENT_THEMES,
   ENFB_CONTENT_APPICONS,
   ENFB_CONTENT_HANDWRITING,
   ENFB_CONTENT_FONT,
   ENFB_CONTENT_MRE_CALC,
   ENFB_CONTENT_MRE_CONV,
   ENFB_CONTENT_MRE_HEALTH,
   ENFB_CONTENT_MRE_OPERA,
   ENFB_CONTENT_MRE_STOPWATCH,
   ENFB_CONTENT_MRE_WEIBO,
   ENFB_CONTENT_MRE_WEIBOVSM,
   ENFB_CONTENT_MRE_OPERA_V6,
   ENFB_CONTENT_MRE_3GT_BALL,
   ENFB_CONTENT_MRE_3GT_MOTO,
   ENFB_CONTENT_MRE_3GT_BOW,
   ENFB_CONTENT_MRE_3GT_DAN,
   ENFB_CONTENT_MRE_GL_AS6,
   ENFB_CONTENT_MRE_GL_ACR,
   ENFB_CONTENT_MRE_GL_BBR,
   ENFB_CONTENT_MRE_GL_BCL,
   ENFB_CONTENT_MRE_GL_MC2,
   ENFB_CONTENT_MRE_GL_GLLV2,
   ENFB_CONTENT_MRE_TWITTER,
   ENFB_CONTENT_MRE_TWITTER_VSM,
   ENFB_CONTENT_MRE_YMV2,
   ENFB_CONTENT_MRE_YMV2_UI_VSM,
   ENFB_CONTENT_MRE_YMV2_SSL_VSM,
   ENFB_CONTENT_MRE_FBV2,
   ENFB_CONTENT_MRE_FBV2_VSM,
   ENFB_CONTENT_MRE_FBV2_MSG,
   ENFB_CONTENT_MRE_YW,
   ENFB_CONTENT_MRE_YF,
   ENFB_CONTENT_MRE_YN,
   ENFB_CONTENT_MRE_KAIXIN,
   ENFB_CONTENT_MRE_KAIXINVSM,
   ENFB_CONTENT_MRE_YOUKU,
   ENFB_CONTENT_WOCHACHA,
   ENFB_CONTENT_MRE_ZAKAT,
   ENFB_CONTENT_MRE_ANGRYBIRD,
   ENFB_CONTENT_MRE_FISHINGFUN,
   ENFB_CONTENT_MRE_FRUITNINJA,
   ENFB_CONTENT_MRE_EGYPTCODE,
   ENFB_CONTENT_MRE_GILRSLOT,
   ENFB_CONTENT_MRE_GOLDENMINER,
   ENFB_CONTENT_MRE_HAPPYEGG,
   ENFB_CONTENT_MRE_HAPPYWAR,
   ENFB_CONTENT_MRE_KINGCOMBAT,
   ENFB_CONTENT_MRE_MOTO,
   ENFB_CONTENT_MRE_PARKOUR,
   ENFB_CONTENT_MRE_TEARDRESS,
   /* --------------------- */
   ENFB_CONTENT_LAST_ID,
   ENFB_CONTENT_ENDMARKER = 0xff
} enfb_cidtbl;

typedef struct _ENFB_Header_
{
   kal_char    ID1[11];
   kal_uint8   type;
   kal_uint32  begin;
   kal_uint32  end;
   kal_char    ID2[12];
} ENFB_HEADER;

typedef struct _THIRDROM_Header_
{
   ENFB_HEADER content_tbl[ENFB_TBLNUM];
   kal_char    ProjectVernoStr[40];
} THIRDROM_HEADER;

typedef struct 
{
   kal_uint32   type;
   kal_uint32   offset;
   kal_uint32   length;
} enfb_indextbl_t;


extern kal_uint32 maxContentNum;
extern enfb_indextbl_t enfb_tbl[];

/*******************************************************************************
 * Define function prototypes.
 *******************************************************************************/
void NFB_LIB_Load(kal_uint8 cid);
void NFB_LIB_Unload(kal_uint8 cid);
kal_bool NFB_RES_Load(kal_uint8 cid, void * dst_addr, kal_uint32 offset, kal_uint32 length);
kal_bool NFB_RES_Loadv(kal_uint8 cid, enfb_scatter *Scatter, kal_uint32 scatter_number);
kal_uint32 NFB_RES_get_content_size(kal_uint8 target_type);

#endif /* _THIRD_ROM_H */
