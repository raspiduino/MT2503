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
*   AMConfig.c
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   AM Configration Src
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
 * removed!
 * removed!
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
//#ifdef __MRE_AM__
#include "mmi_features.h"
#if defined(__MMI_MRE_SUB_MENU__)||defined( __MMI_MRE_MAIN_MENU__)
/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "AMSwitch.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "string.h"

#include "AMGprot.h"
#include "AMDef.h"
#include "AMConfig.h"
#include "AMProt.h"
#include "mmi_rp_app_am_def.h"
#include "liblist.h"

/***************************************************************************** 
* Variable
*****************************************************************************/
extern mmi_am_cntx_struct g_am_cntx;
extern U8 AM_App_Default[];

#ifdef MMI_AM_SC_APP_AS
extern U8 AM_App_AS[];
#endif 
#ifdef MMI_AM_SC_APP_QQBROWSER
extern U8 AM_App_QQBrowser[];
#endif 
#ifdef MMI_AM_SC_APP_QQ
extern U8 AM_App_QQ2009[];
#endif 
#ifdef MMI_AM_SC_APP_WLOL
extern U8 AM_App_WLOL[];
#endif 
#ifdef MMI_AM_SC_APP_MOBILEKK
extern U8 AM_App_MobileKK[];
#endif 
#ifdef MMI_AM_SC_APP_STOCKSTAR
extern U8 AM_App_StockStar[];
#endif 
#ifdef MMI_AM_SC_APP_FETION
extern U8 AM_App_Fetion[];
#endif 
#ifdef MMI_AM_SC_APP_QQLANDLORD
extern U8 AM_App_QQLandlord[];
#endif 
#ifdef MMI_AM_SC_APP_MSN
extern U8 AM_App_MSN[];
#endif 
#ifdef MMI_AM_SC_APP_OPERA
extern U8 AM_App_Opera[];
#endif 
#ifdef MMI_AM_SC_APP_100TV
extern U8 AM_App_100TV[];
#endif 
#ifdef MMI_AM_SC_APP_AIPIM
extern U8 AM_App_AIPIM[];
#endif 
#ifdef MMI_AM_SC_APP_LUUTOO
extern U8 AM_App_Luutoo[];
#endif 
#ifdef MMI_AM_SC_APP_SHANGMAIL
extern U8 AM_App_Shangmail[];
#endif 

#define AM_APP_AS_SIZE 427
#define AM_APP_QQBROWSER_SIZE 447
#define AM_APP_QQ2009_SIZE 347
#define AM_APP_WLOL_SIZE 351
#define AM_APP_MOBILEKK_SIZE 351
#define AM_APP_STOCKSTAR_SIZE 443
#define AM_APP_FETION_SIZE 275
#define AM_APP_QQLANDLORD_SIZE 463
#define AM_APP_MSN_SIZE 203
#define AM_APP_OPERA_SIZE 491
#define AM_APP_100TV_SIZE 299
#define AM_APP_AIPIM_SIZE 439
#define AM_APP_LUUTOO_SIZE 275
#define AM_APP_SHANGMAIL_SIZE 323

/* quick launch app info list */
static mmi_am_quick_launch_info_struct am_ql_info_list[] = 
{
    /* the first one just a sample */
    {
        APPID_NONE,
            0x00000000,
            "sample.k"
    }

#if defined(__MMI_MRE_CALCULATOR__)
    ,
        /* calculator */
    {
        APPID_CALCULATOR,           /* app id */
            0x001100B3,                 /* app download id */
            /* app file name */
#if (!defined(__MMI_FTE_SUPPORT__))
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
            "calculator_qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
            "calculator_qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
            "calculator_qv_ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
            "calculator_wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
            "calculator_hv.vxp"
#else
            NULL
#endif
#else   /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
            "calculator_qc_fte.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
            "calculator_qv_fte.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
            "calculator_qv_ls_fte.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
            "calculator_wq_fte.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
            "calculator_hv_fte.vxp"
#else
            NULL
#endif
#endif  /* __MMI_FTE_SUPPORT__ */
    }
#endif  /* __MMI_MRE_CALCULATOR__ */

#if defined(__MMI_MRE_WORLD_CLOCK__)
    ,
        /* worldclock */
    {
        APPID_WORLDCLOCK,           /* app id */
            0x001100B4,                 /* app download id */
            /* app file name */
#if (!defined(__MMI_FTE_SUPPORT__))
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
            "worldclock_qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
            "worldclock_qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
            "worldclock_qv_ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
            "worldclock_wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
            "worldclock_hv.vxp"
#else
            NULL
#endif
#else   /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
            "worldclock_qc_fte.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
            "worldclock_qv_fte.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
            "worldclock_qv_ls_fte.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
            "worldclock_wq_fte.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
            "worldclock_hv_fte.vxp"
#else
            NULL
#endif
#endif  /* __MMI_FTE_SUPPORT__ */
    }
#endif  /* __MMI_MRE_WORLD_CLOCK__ */

#if defined(__MMI_MRE_APP_OPERA_MINI__)
    ,
        /* opera mini */
    {
        APPID_OPERA,				/* app id */
            0x003500CA,                 /* app download id */                            
            "OpearMini.vxp"				/* app file name */
    }
#endif  /* __MMI_MRE_APP_OPERA_MINI__ */
};

/* am shortcut app list */
static mmi_am_shortcut_info_struct am_shortcut_info_list[] = 
{
    /* the first one just a sample */
    {APPID_NONE,
    0,
    0,
    0,
    0,
    0,
    "sample.k"}
#ifdef MMI_AM_SC_APP_AS
    ,
        /* appstore */
    {APPID_VAS,
    IMG_ID_AM_APP_AS,      /* icon resource id */
    //0,
    STR_ID_AM_APP_NAME_AS, /* name resource id */
    0,//AM_App_AS,             /* name pointer */
    AM_APP_AS_SIZE,        /* name size */
    0x00010000,
    MMI_AM_AS_FILE_NAME}
#endif /* MMI_AM_SC_APP_AS */ 

#ifdef MMI_AM_SC_APP_QQBROWSER
    ,
        /* QQ Browser */
    {APPID_QQBROWSER,
    IMG_ID_AM_APP_QQBROWSER,       /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_QQBROWSER,  /* name resource id */
    AM_App_QQBrowser,              /* name pointer */
    AM_APP_QQBROWSER_SIZE,         /* name size */
    2687131,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "QQBrowser-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "QQBrowser-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "QQBrowser-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "QQBrowser-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "QQBrowser-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_QQBROWSER */ 

#ifdef MMI_AM_SC_APP_QQ
    ,
        /* QQ */
    {APPID_QQ,
    IMG_ID_AM_APP_QQ,      /* icon resource id */
    //STATUS_ICON_MRE_QQ,
    STR_ID_AM_APP_NAME_QQ, /* name resource id */
    AM_App_QQ2009,         /* name pointer */
    AM_APP_QQ2009_SIZE,    /* name size */
    2687133,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "qq2009-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "qq2009-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "qq2009-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "qq2009-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "qq2009-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_QQ */ 

#ifdef MMI_AM_SC_APP_WLOL
    ,
        /* WulinOL */
    {APPID_WLOL,
    IMG_ID_AM_APP_WLOL,        /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_WLOL,   /* name resource id */
    AM_App_WLOL,               /* name pointer */
    AM_APP_WLOL_SIZE,          /* name size */
    3276983,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "wlol-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "wlol-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "wlol-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "wlol-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "wlol-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_WLOL */ 

#ifdef MMI_AM_SC_APP_MOBILEKK
    ,
        /* MobileKK */
    {APPID_MOBILEKK,
    IMG_ID_AM_APP_MOBILEKK,        /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_MOBILEKK,   /* name resource id */
    AM_App_MobileKK,               /* name pointer */
    AM_APP_MOBILEKK_SIZE,          /* name size */
    3408071,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "MobileKK-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "MobileKK-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "MobileKK-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "MobileKK-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "MobileKK-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_MOBILEKK */ 

#ifdef MMI_AM_SC_APP_STOCKSTAR
    ,
        /* Stock star */
    {APPID_STOCKSTAR,
    IMG_ID_AM_APP_STOCKSTAR,       /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_STOCKSTAR,  /* name resource id */
    AM_App_StockStar,              /* name pointer */
    AM_APP_STOCKSTAR_SIZE,         /* name size */
    3014817,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "zqzx-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "zqzx-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "zqzx-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "zqzx-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "zqzx-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_STOCKSTAR */ 

#ifdef MMI_AM_SC_APP_FETION
    ,
        /* Fetion */
    {APPID_FETION,
    IMG_ID_AM_APP_FETION,      /* icon resource id */
    //STATUS_ICON_MRE_FETION,
    STR_ID_AM_APP_NAME_FETION, /* name resource id */
    AM_App_Fetion,             /* name pointer */
    AM_APP_FETION_SIZE,        /* name size */
    1835135,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "fetion-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "fetion-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "fetion-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "fetion-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "fetion-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_FETION */ 

#ifdef MMI_AM_SC_APP_QQLANDLORD
    ,
        /* QQ Landlord */
    {APPID_QQLANDLORD,
    IMG_ID_AM_APP_QQLANDLORD,      /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_QQLANDLORD, /* name resource id */
    AM_App_QQLandlord,             /* name pointer */
    AM_APP_QQLANDLORD_SIZE,        /* name size */
    2687141,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "QQddz-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "QQddz-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "QQddz-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "QQddz-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "QQddz-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_QQLANDLORD */ 

#ifdef MMI_AM_SC_APP_MSN
    ,
        /* MSN */
    {APPID_MSN,
    IMG_ID_AM_APP_MSN,         /* icon resource id */
    //STATUS_ICON_MRE_MSN,
    STR_ID_AM_APP_NAME_MSN,    /* name resource id */
    AM_App_MSN,                /* name pointer */
    AM_APP_MSN_SIZE,           /* name size */
    2752670,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "msn-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "msn-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "msn-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "msn-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "msn-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_MSN */ 

#ifdef MMI_AM_SC_APP_OPERA
    ,
        /* Opera Mini */
    {APPID_OPERA,
    IMG_ID_AM_APP_OPERA,       /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_OPERA,  /* name resource id */
    AM_App_Opera,              /* name pointer */
    AM_APP_OPERA_SIZE,         /* name size */
    3473610,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "OperaMini-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "OperaMini-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "OperaMini-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "OperaMini-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "OperaMini-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_OPERA */ 

#ifdef MMI_AM_SC_APP_100TV
    ,
        /* 100TV */
    {APPID_100TV,
    IMG_ID_AM_APP_100TV,       /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_100TV,  /* name resource id */
    AM_App_100TV,              /* name pointer */
    AM_APP_100TV_SIZE,         /* name size */
    3211448,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "100tv-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "100tv-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "100tv-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "100tv-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "100tv-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_100TV */ 

#ifdef MMI_AM_SC_APP_AIPIM
    ,
        /* AIPIM */
    {APPID_AIPIM,
    IMG_ID_AM_APP_AIPIM,       /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_AIPIM,  /* name resource id */
    AM_App_AIPIM,              /* name pointer */
    AM_APP_AIPIM_SIZE,         /* name size */
    3145914,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "AIPIM-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "AIPIM-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "AIPIM-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "AIPIM-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "AIPIM-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_AIPIM */ 

#ifdef MMI_AM_SC_APP_LUUTOO
    ,
        /* Luutoo */
    {APPID_LUUTOO,
    IMG_ID_AM_APP_LUUTOO,      /* icon resource id */
    //STATUS_ICON_MRE_DEFAULT,
    STR_ID_AM_APP_NAME_LUUTOO, /* name resource id */
    AM_App_Luutoo,             /* name pointer */
    AM_APP_LUUTOO_SIZE,        /* name size */
    2883765,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "luutoo-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "luutoo-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "luutoo-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "luutoo-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "luutoo-hv.vxp"
#else 
    NULL
#endif 
    }
#endif /* MMI_AM_SC_APP_LUUTOO */ 

#ifdef MMI_AM_SC_APP_SHANGMAIL
    ,
        /* Pushmail */
    {APPID_PUSHMAIL,
    IMG_ID_AM_APP_PUSHMAIL,        /* icon resource id */
    //STATUS_ICON_MRE_PUSHMAIL,
    STR_ID_AM_APP_NAME_PUSHMAIL,   /* name resource id */
    AM_App_Shangmail,              /* name pointer */
    AM_APP_SHANGMAIL_SIZE,         /* name size */
    1769598,
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "pushmail-qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "pushmail-qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "pushmail-qv-ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "pushmail-wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "pushmail-hv.vxp"
#else 
    NULL
#endif 
    },
#endif /* MMI_AM_SC_APP_SHANGMAIL */ 
};

static mmi_am_config_ms_struct am_ms_info = 
{
    /* QCIF */
#if defined(__MMI_MAINLCD_176X220__)
    2, 2,
    8, 8, 8, IMG_ID_AM_HIGHLIGHT
    /* QVGA */
#elif defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_FTE_SUPPORT__
    3, 3,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 3,
    8, 8, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
    /* L-QVGA */
#elif defined(__MMI_MAINLCD_320X240__)
    4, 2,
    11, 11, 4, IMG_ID_AM_HIGHLIGHT
    /* WQVGA */
#elif defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__
    3, 4,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 4,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
    /* HVGA */
#elif defined(__MMI_MAINLCD_320X480__)
#ifdef __MMI_FTE_SUPPORT__
    4, 5,
    4, 4, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    4, 5,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
#else 
    0, 0,
    0, 0, 0, 0
#endif 
};


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_sc_num
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 mmi_am_config_get_am_sc_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (sizeof(am_shortcut_info_list) / sizeof(mmi_am_shortcut_info_struct)) - 1;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_sc_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return am_shortcut_info_list + 1;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_sc_info_by_appid
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  
*****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_info_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        if (am_shortcut_info_list[i].app_id == appid)
        {
            return &am_shortcut_info_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_sc_name_by_appid
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  
*****************************************************************************/
S8 *mmi_am_config_get_am_sc_name_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_shortcut_info_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mmi_am_config_get_am_sc_info_by_appid(appid);
    if (!p)
    {
        return NULL;
    }
    else
    {
        return p->file_name;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_sc_name_by_idx
* DESCRIPTION
*  
* PARAMETERS
*  idx     [IN]        
* RETURNS
*  
*****************************************************************************/
S8 *mmi_am_config_get_am_sc_name_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = idx + 1;
    return am_shortcut_info_list[index].file_name;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_ql_info_by_appid
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  
*****************************************************************************/
mmi_am_quick_launch_info_struct *mmi_am_config_get_ql_info_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(am_ql_info_list) / sizeof(mmi_am_shortcut_info_struct); i++)
    {
        if (am_ql_info_list[i].app_id == appid)
        {
            return &am_ql_info_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_ql_app_name_by_appid
* DESCRIPTION
*  
* PARAMETERS
*  appid       [IN]        
* RETURNS
*  
*****************************************************************************/
S8 *mmi_am_config_get_ql_app_name_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_quick_launch_info_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mmi_am_config_get_ql_info_by_appid(appid); 
    if (!p)
    {
        return NULL;
    }
    else
    {
        return p->file_name;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_is_shortcut_app
* DESCRIPTION
*  Check whether the app is shortcut app according to app name.
* PARAMETERS
*  app_name        [IN]        application name.
* RETURNS
*  
*****************************************************************************/
MMI_BOOL mmi_am_config_is_shortcut_app(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 shortcut_app_name[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check AM Shortcut app list */
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        memset(shortcut_app_name, 0, sizeof(shortcut_app_name));
        mmi_asc_to_wcs(shortcut_app_name, (S8 *)am_shortcut_info_list[i].file_name);

        if (mmi_wcsicmp(app_name, shortcut_app_name) == 0)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_get_am_ms_info
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
mmi_am_config_ms_struct *mmi_am_config_get_am_ms_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_one_screen;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_one_screen = am_ms_info.app_num_per_col * am_ms_info.app_num_per_row;
    num_of_items = mre_single_list_get_size(g_am_cntx.vxp_file_list) + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

    /* have scroll bar? */
    if (num_of_items > num_of_one_screen)
    {
        am_ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
    }

    return &am_ms_info;
}


/*****************************************************************************
* FUNCTION
*  mmi_am_config_update_am_ms_info
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_am_config_update_am_ms_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_one_screen;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_one_screen = am_ms_info.app_num_per_col * am_ms_info.app_num_per_row;
    num_of_items = g_am_cntx.vxp_app_num + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

    /* have scroll bar? */
    if (num_of_items > num_of_one_screen)
    {
        am_ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
    }
    else
    {
        am_ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT;
    }

}

#endif /* __MRE_AM__ */ 

