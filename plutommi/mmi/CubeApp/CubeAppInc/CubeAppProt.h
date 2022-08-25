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
*  CubeAppProt.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Shell Application header file
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
*============================================================================
*==============================================================================*/

#ifndef _CUBE_APP_PROT_H
#define _CUBE_APP_PROT_H

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMIDataType.h"
#include "kal_general_types.h"
#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define 
 *****************************************************************************/
#if defined(__VS_DEBUG_SHELL__) && defined(__MAUI_SOFTWARE_LA__)
#ifdef __cplusplus
extern "C"
{
#endif
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction); 
#ifdef __cplusplus
}   /* extern "C" */
#endif

#define MMI_VS_CUBE_START_LOGGING(_symbol_)\
        SLA_CustomLogging(##_symbol_##, 1)
#define MMI_VS_CUBE_STOP_LOGGING(_symbol_)\
        SLA_CustomLogging(##_symbol_##, 0)
#else /* defined(__MM_DEBUG_MEASURE__) */
#define MMI_VS_CUBE_START_LOGGING(_symbol_)
#define MMI_VS_CUBE_STOP_LOGGING(_symbol_)
#endif /* defined(__MM_DEBUG_MEASURE__) */


/***************************************************************************** 
 * Structure and Enums
 *****************************************************************************/
typedef enum {
    MMI_CUBE_VAPP_DIR_NONE,
    MMI_CUBE_VAPP_DIR_NEXT,
    MMI_CUBE_VAPP_DIR_PREV,
    MMI_CUBE_VAPP_DIR_TOTAL
} mmi_cube_vapp_dir_enum;


/***************************************************************************** 
 * Function 
 *****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif
extern void mmi_cube_app_set_img_prefetch_mode(MMI_BOOL enable);
extern MMI_BOOL mmi_cube_app_get_img_prefetch_mode(void);
extern void *mmi_cube_vapp_get_hs_category(U8 scr_idx);
extern S8 mmi_cube_vapp_get_title(U8 scr_idx, U16 *title_id);
extern void *mmi_vs_show_vip_contact(void);
extern void *mmi_cube_vapp_show_media_player(void);
extern void *mmi_cube_vapp_show_imgview(void);
extern void mmi_cube_vapp_close_hs_category(void);
extern void EntryCubeVappByDir(MMI_BOOL is_small_cube, MMI_BOOL is_free_mode, 
                               mmi_cube_vapp_dir_enum dir);
extern void EntryCubeVapp(void);
extern void ExitCubeVapp(void);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif/* _CUBE_APP_PROT_H */


