/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_wap_cust_pack.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains WAP/MMS configuration default value. 
 *
 * Author:
 * -------
 * -------
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
#include "kal_release.h"        /* Basic data type */
#include "MMI_features.h"
#include "custom_wap_config.h"
#include "custom_nvram_editor_data_item.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "custom_data_account.h"

#ifndef __OPTR_NONE__
#include "op_custom_wap_cust_pack.h"
#endif


#ifdef OBIGO_Q05A

const custom_wap_bkm_struct wap_bkm_default = 
{
    WAP_CUSTOM_CFG_N_NBR_BOOKMARKS,
    #ifdef CUSTOM_WAP_BOOKMARKS
    {
    	  CUSTOM_WAP_BOOKMARKS
    }
    #else /* CUSTOM_WAP_BOOKMARKS */ 
    {
     {  /* bookmark 1 - yahoo */
      1,
      0,
      "Yahoo",
      "http://wap.yahoo.com"},
     {  /* bookmark 2 - sina */
      1,
      0,
      "Sina",
      "http://wap.sina.com"},
     {  /* bookmark 3 - google */
      1,
      0,
      "Google",
      "http://wap.google.com"},
     {  /* bookmark 4 - rediff */
      1,
      0,
      "Rediff",
      "http://mobile.rediff.com"},
     {  /* bookmark 5 - obigo */
      1,
      0,
      "Obigo",
      "http://wap.obigo.com"},
     {  /* bookmark 6 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 7 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 8 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 9 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 10 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 11 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 12 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 13 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 14 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 15 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 16 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 17 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 18 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 19 - empty */
      1,
      1,
      "",
      ""},
     {  /* bookmark 20 - empty */
      1,
      1,
      "",
      ""}
    }
    #endif /* CUSTOM_WAP_BOOKMARKS */ 
};
#endif 

#ifdef BROWSER_SUPPORT
#ifdef __MMI_OP12_BRW_EMBEDDED_LINKS__
const custom_wap_embed_link_struct wap_embed_link_default = 
{
    WAP_CUSTOM_CFG_N_NBR_EMBEDDED_LINKS,
    #ifdef CUSTOM_WAP_EMBEDDED_LINKS
    {
    	  CUSTOM_WAP_EMBEDDED_LINKS
    }
    #else /* CUSTOM_WAP_EMBEDDED_LINKS */ 
    {
     {  /* elink 1 - empty */
      1,
      ""},
     {  /* elink 2 - empty */
      1,
      ""},
     {  /* elink 3 - empty */
      1,
      ""},
     {  /* elink 4 - empty */
      1,
      ""},
     {  /* elink 5 - empty */
      1,
      ""},
     {  /* elink 6 - empty */
      1,
      ""},
     {  /* elink 7 - empty */
      1,
      ""},
     {  /* elink 8 - empty */
      1,
      ""},
     {  /* elink 9 - empty */
      1,
      ""},
     {  /* elink 10 - empty */
      1,
      ""},
     {  /* elink 11 - empty */
      1,
      ""},
     {  /* elink 12 - empty */
      1,
      ""},
     {  /* elink 13 - empty */
      1,
      ""},
     {  /* elink 14 - empty */
      1,
      ""},
     {  /* elink 15 - empty */
      1,
      ""},
     {  /* elink 16 - empty */
      1,
      ""},
     {  /* elink 17 - empty */
      1,
      ""},
     {  /* elink 18 - empty */
      1,
      ""},
     {  /* elink 19 - empty */
      1,
      ""},
     {  /* elink 20 - empty */
      1,
      ""},
     {  /* elink 21 - empty */
      1,
      ""},
     {  /* elink 22 - empty */
      1,
      ""},
     {  /* elink 23 - empty */
      1,
      ""},
     {  /* elink 24 - empty */
      1,
      ""},
     {  /* elink 25 - empty */
      1,
      ""},
     {  /* elink 26 - empty */
      1,
      ""},
     {  /* elink 27 - empty */
      1,
      ""},
     {  /* elink 28 - empty */
      1,
      ""},
     {  /* elink 29 - empty */
      1,
      ""},
     {  /* elink 30 - empty */
      1,
      ""}
	}
	#endif /* CUSTOM_WAP_EMBEDDED_LINKS */
};
#endif /* __MMI_OP12_BRW_EMBEDDED_LINKS__ */ 

#endif /* OBIGO_Q05A */ 

