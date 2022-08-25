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
 *   maui_GFH_body.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH body and content for tiny system parts
 *
 * Author:
 * -------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SV5_ENABLED__

#include "br_GFH_file_info.h"
#include "GFH_defs.h"
#include "WIFI_ROM_GFH_body.h"
#include "custom_img_config.h"
#include "kal_general_types.h"

//==============================================================================
// Linker symbols
//==============================================================================
extern kal_uint32 Load$$WIFI_ROM_GFH$$Base;
extern kal_uint32 Load$$WIFI_ROM$$Length;//
extern kal_uint32 Image$$WIFI_ROM$$Base;
extern kal_uint32 Image$$WIFI_ROM_GFH$$Length;


#define WIFI_BIN_VERSION 1


//==============================================================================
// Smart watch tiny system GFH header body
//==============================================================================
#pragma arm section rodata = "WIFI_ROM_GFH"
const WIFI_ROM_GFH g_wifi_rom_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         WIFI_BIN_VERSION,
         IOT_WIFI_BIN,
         0,
         SIG_NONE,

         (kal_uint32)(&Load$$WIFI_ROM_GFH$$Base),//load_addr
         GFH_FILE_SIZE_BY_POST_BUILD, //file_len
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$WIFI_ROM_GFH$$Length),//content_offset
         SIG_NONE_LEN,
         (kal_uint32)(&Image$$WIFI_ROM$$Base),//jump_offset 
         0
      },
};

#pragma arm section rodata



//==============================================================================
//Signature
//==============================================================================


//==============================================================================
// Dummy reference
//==============================================================================
kal_uint32 WIFI_DummyReference()
{
    kal_uint32 size = 0;
    size += (kal_uint32)(&g_wifi_rom_gfh);
    return size;
}

#endif /* __SV5_ENABLED__ */
