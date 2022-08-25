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
 * custom_config_account.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to configure data account.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TCPIP__

#include "custom_config_account.h"
#include "custom_data_account.h"

#include "kal_general_types.h"

#ifndef __DA_MEMORY_CUT__
#if defined(__DA_SMART_SELECTION_SUPPORT__)
#ifdef __MMI_GPRS_FEATURES__
static const custom_dtcnt_prof_gprs_struct g_config_account_gprs[] = 
{    
    /* CMCC CMWAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile WAP", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 

    /* CMCC CMNET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile Internet", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"cmnet"
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },
        
        (const kal_uint8*)"cmwap"
    }, 
    
    /* CMCC DM */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_DM_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China DM", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_DM, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"cmwap"
    },

    /* CHT GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT WAP", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"emome"
    },

    /* CHT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT MMS", /* Account Name */
            "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"emome"
    },

    /* CHT INTERNET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT Internet", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46692" /* SIM ID */
        },
                    
        (const kal_uint8*)"internet"
    },

    /* AIRTEL GPRS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel", /* Account Name */
            "http://www.google.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "202.56.231.117", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelgprs.com"
    },

    /* AIRTEL GPRS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel WAP", /* Account Name */
            "http://www.google.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "202.56.231.117", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelgprs.com"
    },

    /* AIRTEL MMS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel MMS", /* Account Name */
            "http://100.1.201.171:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8799, /* proxy port */
            "100.1.201.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelmms.com"
    },
#ifndef __SLIM_NWK_PROFILE__
    /* AIRTEL MMS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Airtel WAP MMS", /* Account Name */
            "http://100.1.201.171:10021/mmsc", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "100.1.201.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"airtelmms.com"
    },
    
    /* HUTCH GPRS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch", /* Account Name */
            "http://www.hutchworld.co.in", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            9401, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },    


    /* HUTCH GPRS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch WAP", /* Account Name */
            "http://www.hutchworld.co.in", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },


    /* HUTCH MMS HTTP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch MMS", /* Account Name */
            "http://mms1.live.vodafone.in/mms/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            9401, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },
    
    /* HUTCH MMS WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Hutch WAP MMS", /* Account Name */
            "http://mms1.live.vodafone.in/mms/", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_CO_WSP,  /* proxy service type */
            9201, /* proxy port */
            "10.10.1.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS | DTCNT_APPTYPE_MRE_WAP, /* app type */
            "40402, 40403, 40410, 40431, 40440, 40445, 40449, 40490, 40492, 40493, 40494, 40495, 40496, 40497, 40498, 40551, 40552, 40553, 40554, 40555, 40556, 63310" /* SIM ID */
        },

        (const kal_uint8*)"portalnmms"
    },
#endif
    /* OGDR IMPS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"OrangeWorld", /* Account Name */
            "http://www.orange.fr", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "orange", "orange"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "192.168.10.100", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_IMPS, /* app type */
            "20801" /* SIM ID */
        },

        (const kal_uint8*)"orange"
    },

    /* CU GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom WAP", /* Account Name */
            "http://wap.uni-info.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46001" /* SIM ID */
        },

        (const kal_uint8*)"uniwap"
    },
    
    /* CU MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom MMS", /* Account Name */
            "http://mmsc.myuni.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46001" /* SIM ID */
        },

        (const kal_uint8*)"uniwap"
    },

    /* CU Uninet */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"Unicom Uninet", /* Account Name */
            "http://wap.uni-info.com.cn", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            0, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_MRE_NET | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46001" /* SIM ID */
        },
        (const kal_uint8*)"uninet"
    },

    /* FET GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET", /* Account Name */
            "http://mobile.fetnet.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_DEF, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"fetnet01"
    },

    /* FET GPRS 2*/
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET GPRS", /* Account Name */
            "http://www.myfetbravo.com.tw", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_EMAIL | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_NTP | DTCNT_APPTYPE_PUSH, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"internet"
    },

    /* FET MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46601" /* SIM ID */
        },
        (const kal_uint8*)"fetnet01"
    },
    
    /* TWN GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN", /* Account Name */
            "http://ewap", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            0, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_MRE_WAP | DTCNT_APPTYPE_TETHERING | DTCNT_APPTYPE_PLAYER | DTCNT_APPTYPE_DEF | DTCNT_APPTYPE_PUSH, /* app type */
            "46697" /* SIM ID */
        },

        (const kal_uint8*)"internet"
    },

    /* TWN MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46697" /* SIM ID */
        },
        (const kal_uint8*)"mms"
    },
    
    /* for KGT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"KGT MMS", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46688" /* SIM ID */
        },

        (const kal_uint8*)"kgtmms"
    },

    /* for TAT GPRS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TAT", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_NONE, /* app type */
            "46699" /* SIM ID */
        },
        (const kal_uint8*)"hank"
    }
};
#endif

#ifdef __TCPIP_OVER_CSD__
static const custom_dtcnt_prof_csd_struct g_config_account_csd[] = 
{
    /* CMCC WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CMCC MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"China Mobile CSD MMS", /* Account Name */
            "http://mmsc.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "wap", "wap"  /* username, password */
            },
            1,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.0.0.172", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46000, 46002, 46007" /* SIM ID */
        },

        (const kal_uint8*)"17266",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE,   /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX         /* CSD data rate */
    },

    /* CHT WAP */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT CSD", /* Account Name */
            "http://wap.monternet.com", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* CHT MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"CHT CSD MMS", /* Account Name */
            "http://mms.emome.net:8002", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            8080, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46692" /* SIM ID */
        },
        
        (const kal_uint8*)"0933000369",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* FET */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET CSD", /* Account Name */
            "http://mobile.fetnet.net", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* FET MMS */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"FET CSD MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "210.241.199.199", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46601" /* SIM ID */
        },
        
        (const kal_uint8*)"0936010010",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN CSD", /* Account Name */
            "http://ewap", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_BRW_HTTP, /* app type */
            "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },

    /* TWN */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TWN CSD MMS", /* Account Name */
            "http://mms", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "10.1.1.1", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_MMS, /* app type */
            "46697" /* SIM ID */
        },
        
        (const kal_uint8*)"0935120120",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    },
    
    /* TAT */
    {
        {
            0,  0,
            CUSTOM_DTCNT_PROF_TYPE_FACTORY_CONF, /* type */ 
            CUSTOM_DTCNT_SIM_TYPE_1,      /* SIM1/SIM2 */
            (const kal_uint8*)L"TAT CSD", /* Account Name */
            "", /* Home page */
            {
                CUSTOM_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL,
                "", ""  /* username, password */
            },
            0,
            CUSTOM_DTCNT_PROF_PX_SRV_HTTP,  /* proxy service type */
            80, /* proxy port */
            "", /* proxy address, domain name */
            "", "",  /* proxy username, password */
            "", "", "", "", "", "",
            DTCNT_APPTYPE_NONE, /* app type */
            "46699" /* SIM ID */
        },
        
        (const kal_uint8*)"0931777777",     /* CSD profile dial number(ASCII) */
        CUSTOM_DTCNT_PROF_CSD_DIAL_TYPE_ISDN,  /* CSD dial type */
        CUSTOM_DTCNT_PROF_CSD_RATE_NINE_SIX    /* CSD data rate */
    }                
};
#endif

#else /* __DA_SMART_SELECTION_SUPPORT__ */

#ifdef __MMI_GPRS_FEATURES__
static const custom_dtcnt_prof_gprs_struct g_config_account_gprs[1];
#if 0 /* comment predefined account */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __TCPIP_OVER_CSD__
static const custom_dtcnt_prof_csd_struct g_config_account_csd[1];
#if 0 /* comment predefined account */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif /* __DA_SMART_SELECTION_SUPPORT__ */

#define CUSTOM_TABLE_SIZE(a)    sizeof(a)/sizeof(a[0])

//#if defined(__GPS_TRACK__)
static apn_struct apns[] =
{
	//{[MCC][MNC], [apn], [name], [password]},				//[Country], [Network], [Operator or brand name], [Status]
	{"20201", "internet", "", ""},				//Greece, Cosmote Mobile Teelecommunications S.A., Cosmote, Operational
	{"20205", "internet.vodafone.gr", "", ""},				//Greece, Vodafone - Panafon, Vodafone, Operational
	{"20210", "gint.b-online.gr", "", ""},				//Greece, Wind Hellas Telecommunications S.A., Wind, Operational
	{"20404", "live.vodafone.com", "vodafone", "vodafone"},				//Netherlands, Vodafone, Vodafone, Operational
	{"20408", "portalmmm.nl", "", ""},				//Netherlands, KPN B.V, KPN, Operational
	{"20412", "internet", "", ""},				//Netherlands, Telfort B.V, Telfort, Operational
	{"20416", "internet", "", ""},				//Netherlands, T-Mobile, T-mobile, Operational
	{"20420", "rabo.plus", "", ""},				//Netherlands, T-mobile, T-mobile, Operational
	{"20601", "internet.proximus.be", "", ""},				//Belgium, Belgacom Mobile, Proximus, Operational
	{"20605", "telenetwap.be", "", ""},				//Belgium, Telenet, Telenet, Operational
	{"20610", "mworld.be", "mobistar", "mobistar"},				//Belgium, France Telecom, Mobistar, Operational
	{"20620", "gprs.base.be", "BASE", "1234"},				//Belgium, KPN, Base, Operational
	{"20801", "orange", "orange", "orange"},				//France, France Telecom, Orange, Operational
	{"20810", "sl2sfr", "", ""},				//France, Vivendi, SFR, Operational
	{"20820", "mmsbouygtel.com", "", ""},				//France, Bouygues Telecom, Bouygues, Operational
	{"21401", "airtelwap.es", "wap@wap", "wap125"},				//Spain, Vodafone Spain, Vodafone, Operational
	{"21403", "internet", "", ""},				//Spain, France Telecom Espa?a SA, Orange, Operational
	{"21404", "internet", "", ""},				//Spain, Xfera Moviles SA, Yoigo, Operational
	{"21406", "airtelnet.es", "vodafone", "vodafone"},				//Spain, Vodafone Spain, Vodafone, Operational
	{"21407", "telefonica.es", "telefonica", "telefonica"},				//Spain, Telef車nica M車viles Espa?a, movistar, Operational
	{"21408", "internet.euskaltel.mobi", "CLIENTE", "EUSKALTEL"},				//Spain, Euskaltel, Euskaltel, Operational
	{"21416", "internet.telecable.es", "telecable", "telecable"},				//Spain, Telecable de Asturias S.A.U., TeleCable, Operational
	{"21601", "online", "", ""},				//Hungary, Telenor Magyarorsz芍g Zrt., Telenor, Operational
	{"21630", "wnw", "", ""},				//Hungary, Magyar Telekom Plc, T-Mobile, Operational
	{"21670", "internet.vodafone.net", "", ""},				//Hungary, Vodafone Magyarorsz芍g Zrt., Vodafone, Operational
	{"21901", "web.htgprs", "", ""},				//Croatia, T-Mobile, , Operational
	{"21902", "internet.tele2.hr", "", ""},				//Croatia, Tele2, , Operational
	{"21910", "data.vip.hr", "38591", "38591"},				//Croatia, VIPnet, , Operational
	{"22001", "internet", "telenor", "gprs"},				//Serbia, Telenor Serbia, Telenor, Operational
	{"22003", "gprswap", "mts", "64"},				//Serbia, Telekom Srbija a.d., mt:s, Operational
	{"22004", "tmcg-wnw", "38267", "38267"},				//Serbia, Monet, , Inactive
	{"22005", "vipmobile", "vipmobile", "vipmobile"},				//Serbia, Vip mobile d.o.o., VIP, Operational
	{"22201", "wap.tim.it", "WAPTIM", "WAPTIM"},				//Italy, Telecom Italia SpA, TIM, Operational
	{"22210", "mobile.vodafone.it", "", ""},				//Italy, Vodafone Omnitel N.V., Vodafone, Operational
	{"22288", "internet.wind", "", ""},				//Italy, Wind Telecomunicazioni SpA, Wind, Operational
	{"22299", "tre.it", "", ""},				//Italy, Hutchison 3G, 3 Italia, Operational
	{"22601", "internet.vodafone.ro", "internet.vodafone.ro", "vodafone"},				//Romania, Vodafone Romania SA, , Operational
	{"22603", "vpn-shared-static", "48", ""},				//Romania, Cosmote (Zapp), , Operational
	{"22606", "wnw", "wnw", "wnw"},				//Romania, Cosmote, , Operational
	{"22610", "internet", "", ""},				//Romania, Orange Romania, , Operational
	{"22801", "gprs.swisscom.ch", "", ""},				//Switzerland, Swisscom Ltd, Swisscom, Operational
	{"22802", "internet", "", ""},				//Switzerland, Sunrise Communications AG, Sunrise, Operational
	{"22803", "internet", "", ""},				//Switzerland, Orange Communications SA, Orange, Operational
	{"23001", "internet.t-mobile.cz", "wap", "wap"},				//Czech Rep., T-Mobile Czech Republic a.s., T-Mobile, Operational
	{"23002", "internet", "", ""},				//Czech Rep., Telef車nica O2 Czech Republic a.s., O2, Operational
	{"23003", "internet", "", ""},				//Czech Rep., Vodafone Czech Republic a.s., Vodafone, Operational
	{"23101", "internet", "", ""},				//Slovakia, Orange Slovensko, Orange, Operational
	{"23102", "internet", "", ""},				//Slovakia, T-Mobile Slovensko, T-Mobile, Operational
	{"23106", "o2internet", "", ""},				//Slovakia, Telef車nica O2, O2, Operational
	{"23201", "a1.net", "ppp@a1plus.at", "ppp"},				//Austria, A1 Telekom Austria, A1, Operational
	{"23203", "gprsinternet", "t-mobile", "tm"},				//Austria, T-Mobile, T-Mobile, Operational
	{"23205", "orange.web", "web", "web"},				//Austria, Orange, Orange, Operational
	{"23207", "web", "web@telering.at", "web"},				//Austria, tele.ring, Tele.ring, Operational
	{"23210", "drei.at", "", ""},				//Austria, Hutchison 3G Austria, 3 (Drei), Operational
	{"23211", "bob.at", "data@bob.at", "ppp"},				//Austria, A1 Telekom Austria, Bob, Operational
	{"23212", "web.yesss.at", "", ""},				//Austria, Yesss (Orange), Yesss, Operational
	{"23401", "internet", "", ""},				//UK, Mudio Mobile Ltd, Vectone MObile, Operational
	{"23402", "mobile.o2.co.uk", "O2web", "O2web"},				//UK, O2 UK Ltd, O2, Operational
	{"23410", "mobile.o2.co.uk", "o2web", "password"},				//UK, Telef車nica Europe, O2, Operational
	{"23411", "mobile.o2.co.uk", "O2web", "O2web"},				//UK, Telef車nica Europe, O2, Operational
	{"23415", "wap.vodafone.co.uk", "wap", "wap"},				//UK, Vodafone Ltd, Vodafone, Operational
	{"23420", "three.co.uk", "user", ""},				//UK, Hutchison 3G UK Ltd, 3, Operational
	{"23430", "general.t-mobile.uk", "t-mobile", "tm"},				//UK, Everything Everywhere Ltd, T-mobile, Operational
	{"23431", "general.t-mobile.uk", "t-mobile", "tm"},				//UK, Virgin Media (MVNO on EE), Virgin, Operational
	{"23432", "general.t-mobile.uk", "t-mobile", "tm"},				//UK, Virgin Media (MVNO on EE), Virgin, Operational
	{"23433", "orangeinternet", "", ""},				//UK, Everything Everywhere Ltd, Orange, Operational
	{"23434", "orangeinternet", "", ""},				//UK, Everything Everywhere Ltd, Orange, Operational
	{"23450", "pepper", "", ""},				//UK, Jersey Telecom GSM, JT-Wave, Operational
	{"23455", "internet", "", ""},				//UK, Cable and Wireless Plc, Cable and Wireless, Operational
	{"23458", "3gpronto", "", ""},				//UK, Manx Telecom, Manx Telecom, Operational
	{"23801", "internet", "", ""},				//Denmark, TDC Mobil APS, TDC, Operational
	{"23802", "Internet", "", ""},				//Denmark, Telenor Denmark, Telenor, Operational
	{"23806", "data.tre.dk", "", ""},				//Denmark, H3G APS, 3, Operational
	{"23820", "websp", "", ""},				//Denmark, Telia Sonera APS, Telia, Operational
	{"23877", "Internet", "", ""},				//Denmark, Telenor Denmark, Telenor, Operational
	{"24001", "online.telia.se", "", ""},				//Sweden, Telia Sonera AB, Telia, Operational
	{"24002", "data.tre.se", "", ""},				//Sweden, H3G Access AB, 3, Operational
	{"24006", "services.telenor.se", "", ""},				//Sweden, Telenor Sweden AB, Telenor, Operational
	{"24007", "internet.tele2.no", "", ""},				//Sweden, Tele2 Sweden AB, Tele2, Operational
	{"24008", "services.telenor.se", "", ""},				//Sweden, Telenor Sweden AB, Telenor, Operational
	{"24009", "services.telenor.se", "", ""},				//Sweden, Djuice Mobile Sweden, Djuice Mobile Sweden, Operational
	{"24010", "data.springmobil.se", "", ""},				//Sweden, Spring Mobil AB, Spring, Operational
	{"24017", "halebop.telia.se", "", ""},				//Sweden, G?talandsn?tet AB, G?talandsn?tet AB, Operational
	{"24201", "internet.ventelo.no", "", ""},				//Norway, Telenor Norway AS, Telenor, Operational
	{"24202", "wap", "", ""},				//Norway, TeliaSonera Norway AS, Netcom, Operational
	{"24204", "internet.tele2.no", "", ""},				//Norway, Tele2 Norway AS, Tele2, Operational
	{"24205", "internet", "", ""},				//Norway, Network Norway AS, Network Norway, Operational
	{"24403", "internet", "", ""},				//Finland, DNA Oy, DNA, Operational
	{"24405", "internet", "", ""},				//Finland, Elisa Oyj, Elisa, Operational
	{"24410", "internet.song.fi", "song@internet", "songnet"},				//Finland, TDC Oy, TDC, Operational
	{"24412", "internet", "", ""},				//Finland, DNA Oy, DNA, Operational
	{"24421", "internet.saunalahti", "", ""},				//Finland, Saunalahti, Saunalahti, Operational
	{"24491", "internet", "", ""},				//Finland, TeliaSonera Finland Oyj, Sonera, Operational
	{"24601", "omnitel", "omni", "omni"},				//Lithuania, Omnitel, , Operational
	{"24602", "wap", "", ""},				//Lithuania, Bite GSM, , Operational
	{"24603", "internet.tele2.lt", "wap", "wap"},				//Lithuania, Tele2, , Operational
	{"24701", "internet.lmt.lv", "", ""},				//Latvia, Latvian Mobile Phone (LMT), LMT, Operational
	{"24702", "internet.tele2.lv", "wap", "wap"},				//Latvia, Tele2, Tele2, Operational
	{"24705", "internet", "", ""},				//Latvia, Bite Latvija, Bite, Operational
	{"24801", "internet.emt.ee", "", ""},				//Estonia, EMT GSM, EMT, Operational
	{"24802", "internet", "", ""},				//Estonia, Elisa Eesti, Elisa, Operational
	{"24803", "internet.tele2.ee", "", ""},				//Estonia, Tele 2 Eesti, Tele 2, Operational
	{"25001", "internet.mts.ru", "mts", "mts"},				//Russia, Mobile TeleSystems, MTS, Operational
	{"25002", "internet", "", ""},				//Russia, MegaFon OJSC, MegaFon, Operational
	{"25020", "internet.tele2.ru", "", ""},				//Russia, Tele2, Tele2, Operational
	{"25099", "internet.beeline.ru", "beeline", "beeline"},				//Russia, OJSC VimpelCom, Beeline, Operational
	{"25501", "wap.jeans.ua", "", ""},				//Ukraine, Ukrainian Mobile Communication, UMC, MTS, Operational
	{"25502", "internet.beeline.ua", "", ""},				//Ukraine, Ukranian Radio Systems, URS, Beeline, Operational
	{"25503", "wap.ab.kyivstar.net", "", ""},				//Ukraine, Kyivstar GSM JSC, Kyivstar, Operational
	{"25506", "internet", "", ""},				//Ukraine, Astelit, life:), Operational
	{"25507", "3g.utel.ua", "", ""},				//Ukraine, Ukrtelecom, Ukrtelecom, Operational
	{"26001", "internet", "", ""},				//Poland, Plus GSM (Polkomtel S.A.), Plus (Polkomtel), Operational
	{"26002", "erainternet", "", ""},				//Poland, ERA GSM (Polska Telefonia Cyfrowa Sp. Z.o.o.), T-Mobile, Operational
	{"26003", "internet", "internet", "internet"},				//Poland, Orange, Orange, Operational
	{"26006", "internet", "", ""},				//Poland, Play (P4), Play (P4), Operational
	{"26201", "internet.t-mobile", "t-mobile", "tm"},				//Germany, T-Mobile Deutschland GmbH, T-Mobile, Operational
	{"26202", "web.vodafone.de", "", ""},				//Germany, Vodafone D2 GmbH, Vodafone, Operational
	{"26203", "internet.eplus.de", "eplus", "internet"},				//Germany, E-Plus Mobilfunk GmbH & Co. KG, E-plus, Operational
	{"26207", "internet", "", ""},				//Germany, O2 (Germany) GmbH & Co. OHG, O2, Operational
	{"26801", "net2.vodafone.pt", "vodafone", "vodafone"},				//Portugal, Vodafone Portugal, Vodafone, Operational
	{"26803", "umts", "", ""},				//Portugal, Sonaecom ? Servi?os de Comunica??es, S.A., Optimus, Operational
	{"26806", "internet", "", ""},				//Portugal, Telecomunica??es M車veis Nacionais, TMN, Operational
	{"27001", "wap.pt.lu", "wap", "wap"},				//Luxembourg, LuxGSM, LuxGSM, Operational
	{"27077", "internet", "tango", "tango"},				//Luxembourg, Tango, Tango, Operational
	{"27099", "vox.lu", "", ""},				//Luxembourg, Orange S.A., Orange, Operational
	{"27201", "live.vodafone.com", "", ""},				//Ireland, Vodafone Ireland Plc, Vodafone, Operational
	{"27202", "internet", "", ""},				//Ireland, O2 Ireland, O2, Operational
	{"27203", "data.mymeteor.ie", "", ""},				//Ireland, Meteor Mobile Communications Ltd., Meteor, Operational
	{"27205", "3ireland.ie", "", ""},				//Ireland, Hutchison 3G Ireland limited, 3, Operational
	{"27211", "tescomobile.liffeytelecom.com", "", ""},				//Ireland, Liffey Telecom, Tesco Mobile, Operational
	{"27401", "internet", "", ""},				//Iceland, Iceland Telecom Ltd., Siminn, Operational
	{"27402", "gprs.is", "", ""},				//Iceland, Vodafone, Vodafone, Operational
	{"27411", "net.nova.is", "", ""},				//Iceland, Nova ehf, Nova, Operational
	{"27801", "internet", "internet", "internet"},				//Malta, Vodafone Malta, Vodafone, Operational
	{"28001", "cytamobile", "user", "pass"},				//Cyprus, CYTA, Cytamobile-Vodafone, Operational
	{"28010", "wap", "wap", "wap"},				//Cyprus, Areeba Ltd, MTN, Operational
	{"28401", "inet-gprs.mtel.bg", "", ""},				//Bulgaria, M-Tel GSM BG, M-Tel, Operational
	{"28405", "globul", "", ""},				//Bulgaria, Globul, GLOBUL, Operational
	{"28601", "internet", "gprs", "gprs"},				//Turkey, Turkcell Iletisim Hizmetleri A.S., Turkcell, Operational
	{"28602", "internet", "vodafone", "vodafone"},				//Turkey, Vodafone, Vodafone, Operational
	{"28603", "internet", "wap", "wap"},				//Turkey, Avea, Avea, Operational
	{"29001", "internet", "", ""},				//Greenland, Tele Greenland, , Operational
	{"29340", "internet.simobil.si", "simobil", "internet"},				//Slovenia, SI Mobil D.D, Si.mobil, Operational
	{"29341", "internet", "mobitel", "internet"},				//Slovenia, Ipkonet, Mobitel, Operational
	{"29401", "internet", "internet", "t-mobile"},				//Macedonia, T-Mobile, , Operational
	{"29403", "vipoperator", "vipoperator", "vipoperator"},				//Macedonia, VIP Operator, , Operational
	{"29702", "tmcg-wnw", "38267", "38267"},				//Montenegro, T-Mobile Montenegro LLC, T-Mobile, Operational
	{"302220", "sp.telus.com", "", ""},				//Canada, Telus Mobility, Telus, Operational
	{"302320", "wap.davewireless.com", "", ""},				//Canada, Dave Wireless, Mobilicity, Operational
	{"302370", "fido-core-appl1.apn", "", ""},				//Canada, Fido Solutions (Rogers Wireless), Fido, Operational
	{"302490", "internet.windmobile.ca", "", ""},				//Canada, Globalive Communications, WIND Mobile, Operational
	{"302500", "media.videotron", "", ""},				//Canada, Videotron, Videotron, Operational
	{"302610", "pda.bell.ca", "", ""},				//Canada, Bell Mobility, Bell, Operational
	{"302720", "isp.apn", "", ""},				//Canada, Rorges Communications, Rogers Wireless, Operational
	{"302780", "pda.stm.sk.ca", "", ""},				//Canada, SaskTel Mobility, SaskTel, Operational
	{"31030", "private.centennialwireless.com", "privuser", "priv"},				//United States, Centennial Communications, Centennial, Operational
	{"31090", "isp", "", ""},				//United States, AT&T, AT&T, Operational
	{"310100", "plateauweb", "", ""},				//United States, New Mexico RSA 4 East Ltd. Partnership, Plateau Wireless, Operational
	{"310160", "epc.tmobile.com", "", ""},				//United States, T-Mobile, T-Mobile, Operational
	{"310170", "isp.cingular", "", ""},				//United States, Cingular Wireless, , Inactive
	{"310200", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310210", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310220", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310230", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310240", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310250", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310260", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Operational
	{"310270", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310310", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310380", "proxy", "", ""},				//United States, New Cingular Wireless PCS, LLC, , Inactive
	{"310410", "wap.cingular", "WAP@CINGULARGPRS.COM", "CINGULAR1"},				//United States, AT&T, AT&T, Operational
	{"310470", "isp.cingular", "", ""},				//United States, Omnipoint, , Inactive
	{"310480", "isp.cingular", "", ""},				//United States, Verizon Wireless, Verizon, Operational
	{"310490", "epc.tmobile.com", "", ""},				//United States, T-Mobile, T-Mobile, Operational
	{"310580", "epc.tmobile.com", "", ""},				//United States, Inland Cellular Telephone Company, , Inactive
	{"310610", "internet.epictouch", "", ""},				//United States, Elkhart Telephone Co., Epic Touch, Operational
	{"310660", "epc.tmobile.com", "", ""},				//United States, MetroPCS, MetroPCS, Operational
	{"310770", "i2.iwireless.com", "", ""},				//United States, Iowa Wireless Services LLC dba I Wireless, i wireless, Operational
	{"310800", "epc.tmobile.com", "", ""},				//United States, T-Mobile, , Inactive
	{"310840", "isp", "", ""},				//United States, Telecom North America Mobile, Inc., telna Mobile, Operational
	{"310910", "wap.firstcellular.com", "", ""},				//United States, Verizon Wireless, Verizon, Operational
	{"311210", "internet.farmerswireless.com", "", ""},				//United States, Farmers Cellular Telephone, Farmers Cellular, Operational
	{"33403", "internet.movistar.mx", "movistar", "movistar"},				//Mexico, Telefonica Moviles (Movistar), Movistar, Operational
	{"33420", "internet.itelcel.com", "webgprs", "webgprs2002"},				//Mexico, Am谷rica M車vil, Telcel, Inactive
	{"33450", "web.iusacellgsm.mx", "Iusacellgsm", "Iusacellgsm"},				//Mexico, Iusacell / Unefon, Iusacell / Unefon, Operational
	{"33850", "web.digiceljamaica.com", "", ""},				//Jamaica, Digicel (Jamaica) Limited, Digicel, Operational
	{"33870", "internet.ideasclaro.com.jm", "", ""},				//Jamaica, Oceanic Digital Jamaica Limited, Claro, Operational
	{"338180", "internet", "", ""},				//Jamaica, Cable and Wireless Jamaica Limited, LIME (formerly known as Cable & Wireless), Operational
	{"34001", "orangewap", "orange", "wap"},				//Martinique & Guadeloupe, Orange Cara?be Mobiles, Orange, Operational
	{"34020", "wap.digicelfr.com", "wap", "wap"},				//Martinique & Guadeloupe, DIGICEL Antilles Fran?aise Guyane, Digicel, Operational
	{"36801", "internet", "", ""},				//Cuba, Empresa de Telecomunicaciones de Cuba, SA, Cubacel, Operational
	{"37001", "orangenet.com.do", "", ""},				//Dominican Republic, Orange Dominicana, S.A., Orange, Operational
	{"37002", "internet.ideasclaro.com.do", "", ""},				//Dominican Republic, Compa?赤a Dominicana de Tel谷fonos, C por, Claro, Operational
	{"37004", "edge.viva.net.do", "viva", "viva"},				//Dominican Republic, Trilogy Dominicana, S.A., Viva, Operational
	{"37412", "internet", "", ""},				//Trinidad and Tobago, BMobile, bMobile, Operational
	{"40101", "internet.beeline.kz", "@internet.beeline", "beeline"},				//Kazakhstan, Kar-Tel llc, Beeline, Operational
	{"40102", "internet", "", ""},				//Kazakhstan, GSM Kazakhstan Ltd, Kcell, Operational
	{"40177", "internet", "", ""},				//Kazakhstan, Mobile Telecom Service LLP, Mobile Telecom Service, Operational
	{"40401", "www", "", ""},				//India, Vodafone (Haryana), Vodafone, Operational
	{"40402", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Punjab), Airtel, Operational
	{"40403", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Himachal Pradesh), Airtel, Operational
	{"40404", "internet", "", ""},				//India, Idea (Delhi), Idea, Operational
	{"40405", "www", "", ""},				//India, Vodafone (Gujarat), Vodafone, Operational
	{"40407", "internet", "", ""},				//India, Idea (Andhra Pradesh), Idea, Operational
	{"40409", "SMARTNET", "", ""},				//India, Reliance Telecom (Assam), Reliance Telecom, Operational
	{"40410", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Delhi), Airtel, Operational
	{"40411", "www", "", ""},				//India, Vodafone (Delhi), Vodafone, Operational
	{"40412", "internet", "", ""},				//India, Idea (Haryana), Idea, Operational
	{"40413", "www", "", ""},				//India, Vodafone (Andhra Pradesh), Vodafone, Operational
	{"40414", "spicegprs", "", ""},				//India, Idea (Punjab), Idea, Operational
	{"40415", "www", "", ""},				//India, Vodafone (Uttar Pradesh (East), Vodafone, Operational
	{"40416", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (North East), Airtel, Operational
	{"40417", "aircelwebpost", "", ""},				//India, Aircel (West Bengal), Aircel, Operational
	{"40418", "SMARTNET", "", ""},				//India, Reliance Telecom (Himachal Pradesh), Reliance Telecom, Operational
	{"40419", "internet", "", ""},				//India, Idea (Kerala), Idea, Operational
	{"40420", "www", "", ""},				//India, Vodafone (Mumbai), Vodafone, Operational
	{"40421", "www", "", ""},				//India, LOOP (Mumbai), LOOP, Operational
	{"40422", "internet", "", ""},				//India, Idea (Maharashtra), Idea, Operational
	{"40424", "internet", "", ""},				//India, Idea (Gujarat), Idea, Operational
	{"40425", "aircelwebpost", "", ""},				//India, Aircel (Bihar), Aircel, Operational
	{"40427", "www", "", ""},				//India, Vodafone (Maharashtra), Vodafone, Operational
	{"40428", "aircelwebpost", "", ""},				//India, Aircel (Orissa), Aircel, Operational
	{"40429", "aircelwebpost", "", ""},				//India, Aircel (Assam), Aircel, Operational
	{"40430", "www", "", ""},				//India, Vodafone (Kolkata), Vodafone, Operational
	{"40431", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Kolkata), Airtel, Operational
	{"40433", "aircelwebpost", "", ""},				//India, Aircel (North East), Aircel, Operational
	{"40434", "bsnlnet", "", ""},				//India, BSNL (Haryana), BSNL, Operational
	{"40435", "aircelwebpost", "", ""},				//India, Aircel (Himachal Pradesh), Aircel, Operational
	{"40436", "SMARTNET", "", ""},				//India, Reliance Telecom (Bihar), Reliance Telecom, Operational
	{"40437", "aircelwebpost", "", ""},				//India, Aircel (Jammu & Kashmir), Aircel, Operational
	{"40438", "bsnlnet", "", ""},				//India, BSNL (Assam), BSNL, Operational
	{"40440", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Chennai), Airtel, Operational
	{"40441", "aircelgprs.po", "", ""},				//India, Aircel (Chennai), Aircel, Operational
	{"40442", "aircelgprs.po", "", ""},				//India, Aircel (Tamilnadu), Aircel, Operational
	{"40443", "www", "", ""},				//India, Vodafone (Tamilnadu), Vodafone, Operational
	{"40444", "simplyinternet", "", ""},				//India, Idea (Karnataka), Idea, Operational
	{"40445", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Karnataka), Airtel, Operational
	{"40446", "www", "", ""},				//India, Vodafone (Kerala), Vodafone, Operational
	{"40449", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Andhra Pradesh), Airtel, Operational
	{"40450", "SMARTNET", "", ""},				//India, Reliance Telecom (North East), Reliance Telecom, Operational
	{"40451", "bsnlnet", "", ""},				//India, BSNL (Himachal Pradesh), BSNL, Operational
	{"40452", "SMARTNET", "", ""},				//India, Reliance Telecom (Orissa), Reliance Telecom, Operational
	{"40453", "bsnlnet", "", ""},				//India, BSNL (Punjab), BSNL, Operational
	{"40454", "bsnlnet", "", ""},				//India, BSNL (Uttar Pradesh (West), BSNL, Operational
	{"40455", "bsnlnet", "", ""},				//India, BSNL (Uttar Pradesh (East), BSNL, Operational
	{"40456", "internet", "", ""},				//India, Idea (Uttar Pradesh (West), Idea, Operational
	{"40457", "bsnlnet", "", ""},				//India, BSNL (Gujarat), BSNL, Operational
	{"40458", "bsnlnet", "", ""},				//India, BSNL (Madhya Pradesh), BSNL, Operational
	{"40459", "bsnlnet", "", ""},				//India, BSNL (Rajasthan), BSNL, Operational
	{"40460", "www", "", ""},				//India, Vodafone (Rajasthan), Vodafone, Operational
	{"40462", "bsnlnet", "", ""},				//India, BSNL (Jammu & Kashmir), BSNL, Operational
	{"40464", "bsnlnet", "", ""},				//India, BSNL (Chennai), BSNL, Operational
	{"40466", "bsnlnet", "", ""},				//India, BSNL (Maharashtra), BSNL, Operational
	{"40467", "SMARTNET", "", ""},				//India, Reliance Telecom (Madhya Pradesh), Reliance Telecom, Operational
	{"40468", "gprsmtnldel", "mtnl", "mtnl123"},				//India, MTNL (Delhi), Dolphin, Operational
	{"40469", "gprsmtnlmum", "mtnl", "mtnl123"},				//India, MTNL (Mumbai), Dolphin, Operational
	{"40470", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Rajasthan), Airtel, Operational
	{"40471", "bsnlnet", "", ""},				//India, BSNL (Karnataka), BSNL, Operational
	{"40472", "bsnlnet", "", ""},				//India, BSNL (Kerala), BSNL, Operational
	{"40473", "bsnlnet", "", ""},				//India, BSNL (Andhra Pradesh), BSNL, Operational
	{"40474", "bsnlnet", "", ""},				//India, BSNL (West Bengal), BSNL, Operational
	{"40475", "bsnlnet", "", ""},				//India, BSNL (Bihar), BSNL, Operational
	{"40476", "bsnlnet", "", ""},				//India, BSNL (Orissa), BSNL, Operational
	{"40477", "bsnlnet", "", ""},				//India, BSNL (North East), BSNL, Operational
	{"40478", "internet", "", ""},				//India, Idea (Madhya Pradesh), Idea, Operational
	{"40479", "bsnlnet", "", ""},				//India, BSNL (Andaman Nicobar), BSNL, Operational
	{"40480", "bsnlnet", "", ""},				//India, BSNL (Tamilnadu), BSNL, Operational
	{"40481", "bsnlnet", "", ""},				//India, BSNL (Kolkata), BSNL, Operational
	{"40482", "internet", "", ""},				//India, Idea (Himachal Pradesh), Idea, Operational
	{"40483", "SMARTNET", "", ""},				//India, Reliance Telecom (Kolkata), Reliance Telecom, Operational
	{"40484", "www", "", ""},				//India, Vodafone (Chennai), Vodafone, Operational
	{"40485", "SMARTNET", "", ""},				//India, Reliance Telecom (West Bengal), Reliance Telecom, Operational
	{"40486", "www", "", ""},				//India, Vodafone (Karnataka), Vodafone, Operational
	{"40487", "internet", "", ""},				//India, Idea (Rajasthan), Idea, Operational
	{"40488", "www", "", ""},				//India, Vodafone (Punjab), Vodafone, Operational
	{"40489", "internet", "", ""},				//India, Idea (Uttar Pradesh (East), Idea, Operational
	{"40490", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Maharashtra), Airtel, Operational
	{"40491", "aircelwebpost", "", ""},				//India, Aircel (Kolkata), Aircel, Operational
	{"40492", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Mumbai), Airtel, Operational
	{"40493", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Madhya Pradesh), Airtel, Operational
	{"40494", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Tamilnadu), Airtel, Operational
	{"40495", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Kerala), Airtel, Operational
	{"40496", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Haryana), Airtel, Operational
	{"40497", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Uttar Pradesh (West), Airtel, Operational
	{"40498", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Gujarat), Airtel, Operational
	{"40501", "rcomnet", "", ""},				//India, Reliance Telecom (Andhra Pradesh), Reliance Telecom, Operational
	{"40503", "rcomnet", "", ""},				//India, Reliance Telecom (Bihar), Reliance Telecom, Operational
	{"40504", "rcomnet", "", ""},				//India, Reliance Telecom (Chennai), Reliance Telecom, Operational
	{"40505", "rcomnet", "", ""},				//India, Reliance Telecom (Delhi), Reliance Telecom, Operational
	{"40506", "rcomnet", "", ""},				//India, Reliance Telecom (Gujarat), Reliance Telecom, Operational
	{"40507", "rcomnet", "", ""},				//India, Reliance Telecom (Haryana), Reliance Telecom, Operational
	{"40508", "rcomnet", "", ""},				//India, Reliance Telecom (Himachal Pradesh), Reliance Telecom, Operational
	{"40509", "rcomnet", "", ""},				//India, Reliance Telecom (Jammu & Kashmir), Reliance Telecom, Operational
	{"40510", "rcomnet", "", ""},				//India, Reliance Telecom (Karnataka), Reliance Telecom, Operational
	{"40511", "rcomnet", "", ""},				//India, Reliance Telecom (Kerala), Reliance Telecom, Operational
	{"40512", "rcomnet", "", ""},				//India, Reliance Telecom (Kolkata), Reliance Telecom, Operational
	{"40513", "rcomnet", "", ""},				//India, Reliance Telecom (Maharashtra), Reliance Telecom, Operational
	{"40514", "rcomnet", "", ""},				//India, Reliance Telecom (Madhya Pradesh), Reliance Telecom, Operational
	{"40515", "rcomnet", "", ""},				//India, Reliance Telecom (Mumbai), Reliance Telecom, Operational
	{"40517", "rcomnet", "", ""},				//India, Reliance Telecom (Orissa), Reliance Telecom, Operational
	{"40518", "rcomnet", "", ""},				//India, Reliance Telecom (Punjab), Reliance Telecom, Operational
	{"40519", "rcomnet", "", ""},				//India, Reliance Telecom (Rajasthan), Reliance Telecom, Operational
	{"40520", "rcomnet", "", ""},				//India, Reliance Telecom (Tamilnadu), Reliance Telecom, Operational
	{"40521", "rcomnet", "", ""},				//India, Reliance Telecom (Uttar Pradesh (East), Reliance Telecom, Operational
	{"40522", "rcomnet", "", ""},				//India, Reliance Telecom (Uttar Pradesh (West), Reliance Telecom, Operational
	{"40523", "rcomnet", "", ""},				//India, Reliance Telecom (West Bengal), Reliance Telecom, Operational
	{"40525", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Andhra Pradesh), TATA Teleservices, Operational
	{"40526", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Assam), TATA Teleservices, Operational
	{"40527", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Bihar), TATA Teleservices, Operational
	{"40528", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Chennai), TATA Teleservices, Operational
	{"40529", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Delhi), TATA Teleservices, Operational
	{"40530", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Gujarat), TATA Teleservices, Operational
	{"40531", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Haryana), TATA Teleservices, Operational
	{"40532", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Himachal Pradesh), TATA Teleservices, Operational
	{"40533", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Jammu & Kashmir), TATA Teleservices, Operational
	{"40534", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Karnataka), TATA Teleservices, Operational
	{"40535", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Kerala), TATA Teleservices, Operational
	{"40536", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Kolkata), TATA Teleservices, Operational
	{"40537", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Maharashtra), TATA Teleservices, Operational
	{"40538", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Madhya Pradesh), TATA Teleservices, Operational
	{"40539", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Mumbai), TATA Teleservices, Operational
	{"40540", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (North East), TATA Teleservices, Operational
	{"40541", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Orissa), TATA Teleservices, Operational
	{"40542", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Punjab), TATA Teleservices, Operational
	{"40543", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Rajasthan), TATA Teleservices, Operational
	{"40544", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Tamilnadu), TATA Teleservices, Operational
	{"40545", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Uttar Pradesh (East), TATA Teleservices, Operational
	{"40546", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (Uttar Pradesh (West), TATA Teleservices, Operational
	{"40547", "TATA.DOCOMO.INTERNET", "", ""},				//India, TATA Teleservices (West Bengal), TATA Teleservices, Operational
	{"40551", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (West Bengal), Airtel, Operational
	{"40552", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Bihar), Airtel, Operational
	{"40553", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Orissa), Airtel, Operational
	{"40554", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Uttar Pradesh (East), Airtel, Operational
	{"40555", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Jammu & Kashmir), Airtel, Operational
	{"40556", "airtelgprs.com", "", ""},				//India, Bharti Airtel Ltd (Assam), Airtel, Operational
	{"40566", "www", "", ""},				//India, Vodafone (Uttar Pradesh (West), Vodafone, Operational
	{"40567", "www", "", ""},				//India, Vodafone (West Bengal), Vodafone, Operational
	{"40570", "internet", "", ""},				//India, Idea (Bihar), Idea, Operational
	{"405750", "jkgprs", "", ""},				//India, Vodafone (Jammu & Kashmir), Vodafone, Operational
	{"405751", "www", "", ""},				//India, Vodafone (Assam), Vodafone, Operational
	{"405752", "www", "", ""},				//India, Vodafone (Bihar), Vodafone, Operational
	{"405753", "www", "", ""},				//India, Vodafone (Orissa), Vodafone, Operational
	{"405754", "www", "", ""},				//India, Vodafone (Himachal Pradesh), Vodafone, Operational
	{"405755", "www", "", ""},				//India, Vodafone (North East), Vodafone, Operational
	{"405756", "www", "", ""},				//India, Vodafone (Madhya Pradesh), Vodafone, Operational
	{"405799", "internet", "", ""},				//India, Idea (Mumbai), Idea, Operational
	{"405800", "aircelgprs", "", ""},				//India, Aircel (Delhi), Aircel, Operational
	{"405801", "aircelgprs", "", ""},				//India, Aircel (Andhra Pradesh), Aircel, Operational
	{"405802", "aircelgprs", "", ""},				//India, Aircel (Gujarat), Aircel, Operational
	{"405803", "aircelgprs", "", ""},				//India, Aircel (Karnataka), Aircel, Operational
	{"405804", "aircelgprs", "", ""},				//India, Aircel (Maharashtra), Aircel, Operational
	{"405805", "aircelgprs", "", ""},				//India, Aircel (Mumbai), Aircel, Operational
	{"405806", "aircelgprs", "", ""},				//India, Aircel (Rajasthan), Aircel, Operational
	{"405807", "aircelgprs", "", ""},				//India, Aircel (Haryana), Aircel, Operational
	{"405808", "aircelgprs", "", ""},				//India, Aircel (Madhya Pradesh), Aircel, Operational
	{"405809", "aircelgprs", "", ""},				//India, Aircel (Kerala), Aircel, Operational
	{"405810", "aircelgprs", "", ""},				//India, Aircel (Uttar Pradesh (East), Aircel, Operational
	{"405811", "aircelgprs", "", ""},				//India, Aircel (Uttar Pradesh (West), Aircel, Operational
	{"405812", "aircelgprs", "", ""},				//India, Aircel (Punjab), Aircel, Operational
	{"405813", "uninor", "", ""},				//India, Telenor Unitech (Haryana), Uninor, Operational
	{"405814", "uninor", "", ""},				//India, Telenor Unitech (Himachal Pradesh), Uninor, Operational
	{"405815", "uninor", "", ""},				//India, Telenor Unitech (Jammu & Kashmir), Uninor, Operational
	{"405816", "uninor", "", ""},				//India, Telenor Unitech (Punjab), Uninor, Operational
	{"405817", "uninor", "", ""},				//India, Telenor Unitech (Rajasthan), Uninor, Operational
	{"405818", "uninor", "", ""},				//India, Telenor Unitech (Uttar Pradesh (West), Uninor, Operational
	{"405819", "uninor", "", ""},				//India, Telenor Unitech (Andhra Pradesh), Uninor, Operational
	{"405820", "uninor", "", ""},				//India, Telenor Unitech (Karnataka), Uninor, Operational
	{"405821", "uninor", "", ""},				//India, Telenor Unitech (Kerala), Uninor, Operational
	{"405822", "uninor", "", ""},				//India, Telenor Unitech (Kolkata), Uninor, Operational
	{"405823", "vinternet.com", "", ""},				//India, Videocon (Andhra Pradesh), Videocon, Operational
	{"405824", "vinternet.com", "", ""},				//India, Videocon (Assam), Videocon, Operational
	{"405825", "vinternet.com", "", ""},				//India, Videocon (Bihar), Videocon, Operational
	{"405826", "vinternet.com", "", ""},				//India, Videocon (Delhi), Videocon, Operational
	{"405827", "vinternet.com", "", ""},				//India, Videocon (Gujarat), Videocon, Operational
	{"405828", "vinternet.com", "", ""},				//India, Videocon (Haryana), Videocon, Operational
	{"405829", "vinternet.com", "", ""},				//India, Videocon (Himachal Pradesh), Videocon, Operational
	{"405830", "vinternet.com", "", ""},				//India, Videocon (Jammu & Kashmir), Videocon, Operational
	{"405831", "vinternet.com", "", ""},				//India, Videocon (Karnataka), Videocon, Operational
	{"405832", "vinternet.com", "", ""},				//India, Videocon (Kerala), Videocon, Operational
	{"405833", "vinternet.com", "", ""},				//India, Videocon (Kolkata), Videocon, Operational
	{"405834", "vinternet.com", "", ""},				//India, Videocon (Madhya Pradesh), Videocon, Operational
	{"405835", "vinternet.com", "", ""},				//India, Videocon (Maharashtra), Videocon, Operational
	{"405836", "vinternet.com", "", ""},				//India, Videocon (Mumbai), Videocon, Operational
	{"405837", "vinternet.com", "", ""},				//India, Videocon (North East), Videocon, Operational
	{"405838", "vinternet.com", "", ""},				//India, Videocon (Orissa), Videocon, Operational
	{"405839", "vinternet.com", "", ""},				//India, Videocon (Rajasthan), Videocon, Operational
	{"405840", "vinternet.com", "", ""},				//India, Videocon (Tamilnadu), Videocon, Operational
	{"405841", "vinternet.com", "", ""},				//India, Videocon (Uttar Pradesh (East), Videocon, Operational
	{"405842", "vinternet.com", "", ""},				//India, Videocon (Uttar Pradesh (West), Videocon, Operational
	{"405843", "vinternet.com", "", ""},				//India, Videocon (West Bengal), Videocon, Operational
	{"405844", "uninor", "", ""},				//India, Telenor Unitech (Delhi), Uninor, Operational
	{"405845", "internet", "", ""},				//India, Idea (Assam), Idea, Operational
	{"405846", "internet", "", ""},				//India, Idea (Jammu & Kashmir), Idea, Operational
	{"405848", "internet", "", ""},				//India, Idea (Kolkata), Idea, Operational
	{"405849", "internet", "", ""},				//India, Idea (North East), Idea, Operational
	{"405850", "internet", "", ""},				//India, Idea (Orissa), Idea, Operational
	{"405852", "internet", "", ""},				//India, Idea (Tamilnadu), Idea, Operational
	{"405853", "internet", "", ""},				//India, Idea (West Bengal), Idea, Operational
	{"405875", "uninor", "", ""},				//India, Telenor Unitech (Assam), Uninor, Operational
	{"405876", "uninor", "", ""},				//India, Telenor Unitech (Bihar), Uninor, Operational
	{"405877", "uninor", "", ""},				//India, Telenor Unitech (North East), Uninor, Operational
	{"405878", "uninor", "", ""},				//India, Telenor Unitech (Orissa), Uninor, Operational
	{"405879", "uninor", "", ""},				//India, Telenor Unitech (Uttar Pradesh (East), Uninor, Operational
	{"405880", "uninor", "", ""},				//India, Telenor Unitech (West Bengal), Uninor, Operational
	{"405881", "gprs.stel.in", "", ""},				//India, S TEL (Assam), S TEL, Operational
	{"405882", "gprs.stel.in", "", ""},				//India, S TEL (Bihar), S TEL, Operational
	{"405883", "gprs.stel.in", "", ""},				//India, S TEL (Himachal Pradesh), S TEL, Operational
	{"405884", "gprs.stel.in", "", ""},				//India, S TEL (Jammu & Kashmir), S TEL, Operational
	{"405885", "gprs.stel.in", "", ""},				//India, S TEL (North East), S TEL, Operational
	{"405886", "gprs.stel.in", "", ""},				//India, S TEL (Orissa), S TEL, Operational
	{"405925", "uninor", "", ""},				//India, Telenor Unitech (Tamilnadu), Uninor, Operational
	{"405926", "uninor", "", ""},				//India, Telenor Unitech (Mumbai), Uninor, Operational
	{"405927", "uninor", "", ""},				//India, Telenor Unitech (Gujarat), Uninor, Operational
	{"405928", "uninor", "", ""},				//India, Telenor Unitech (Madhya Pradesh), Uninor, Operational
	{"405929", "uninor", "", ""},				//India, Telenor Unitech (Maharashtra), Uninor, Operational
	{"405932", "vinternet.com", "", ""},				//India, Videocon (Punjab), Videocon, Operational
	{"41001", "connect.mobilinkworld.com", "Mobilink", "Mobilink"},				//Pakistan, Mobilink-PMCL, Mobilink, Operational
	{"41003", "Ufone.internet", "", ""},				//Pakistan, Pakistan Telecommunication Mobile Ltd, Ufone, Operational
	{"41004", "zonginternet", "", ""},				//Pakistan, China Mobile, Zong, Operational
	{"41006", "internet", "", ""},				//Pakistan, Telenor Pakistan, Telenor, Operational
	{"41007", "Wap.warid", "", ""},				//Pakistan, WaridTel, Warid, Operational
	{"41501", "internet.mic1.com.lb", "mic1", "mic1"},				//Lebanon, MIC 1, Alfa, Operational
	{"41503", "gprs.mtctouch.com.lb", "", ""},				//Lebanon, MIC 2, mtc touch, Operational
	{"41601", "internet", "", ""},				//Jordan, Jordan Mobile Telephone Services, zain JO, Operational
	{"41603", "internet", "", ""},				//Jordan, Umniah, Umniah, Operational
	{"41677", "net.orange.jo", "net", "net"},				//Jordan, Petra Jordanian Mobile Telecommunications Company (MobileCom), Orange, Operational
	{"41902", "pps", "pps", "pps"},				//Kuwait, Mobile Telecommunications Company, Zain, Operational
	{"41903", "action.wataniya.com", "", ""},				//Kuwait, Wataniya Telecom, Wataniya, Operational
	{"41904", "VIVA", "", ""},				//Kuwait, Kuwait Telecommunication Company, Viva, Operational
	{"42001", "jawalnet.com.sa", "", ""},				//Saudi Arabia, Saudi Telecom Company, Al Jawal, Operational
	{"42003", "web2", "", ""},				//Saudi Arabia, Etihad Etisalat Company, Mobily, Operational
	{"42004", "zain", "", ""},				//Saudi Arabia, Zain SA, Zain SA, Operational
	{"42202", "taif", "taif", "taif"},				//Oman, Oman Mobile Telecommunications Company, Oman Mobile, Operational
	{"42203", "isp.nawras.com.om", "", ""},				//Oman, Oman Qatari Telecommunications Company (Nawras), Nawras, Operational
	{"42402", "etisalat.ae", "", ""},				//United Arab Emirates, E mirates Telecom Corp, Etisalat, Operational
	{"42403", "du", "", ""},				//United Arab Emirates, Emirates Integrated Telecommunications Company, du, Operational
	{"42501", "uwap.orange.co.il", "orange", "mobile54"},				//Israel, Partner Communications Co. Ltd., Orange, Operational
	{"42502", "Sphone", "", ""},				//Israel, Cellcom Israel Ltd., Cellcom, Operational
	{"42503", "sphone.pelephone.net.il", "pcl@3g", "pcl"},				//Israel, Pelephone Communications Ltd., Pelephone, Operational
	{"42601", "internet.batelco.com", "", ""},				//Bahrain, Bahrain Telecommunications Company, Batelco, Operational
	{"42602", "connect.mobilinkworld.com", "Mobilink", "Mobilink"},				//Bahrain, Zain Bahrain, Zain BH, Operational
	{"42604", "viva.bh", "", ""},				//Bahrain, STC Bahrain, Viva, Operational
	{"42701", "gprs.qtel", "gprs", "gprs"},				//Quatar, Qtel, Qtel, Operational
	{"42702", "vodafone.com.qa", "", ""},				//Quatar, Vodaphone Quatar, Vodafone, Operational
	{"43235", "mtnirancell", "", ""},				//Iran, Irancell Telecommunications Services Company, Irancell, Operational
	{"44010", "mopera.net", "", ""},				//Japan, NTT DoCoMo, DoCoMo, Operational
	{"45005", "roaming.sktelecom.com", "", ""},				//Korea (South), SK Telecom, SKT, Operational
	{"45008", "alwayson-r6.ktfwing.com", "", ""},				//Korea (South), KTF SHOW, KTF Show, Operational
	{"45201", "m-wap", "mms", "mms"},				//Vietnam, Vietnam Mobile Telecom (VMS), MobilFone, Operational
	{"45202", "m3-world", "mms", "mms"},				//Vietnam, Vinaphone, Vinaphone, Operational
	{"45204", "v-internet", "", ""},				//Vietnam, Viettel Corporation (Viettel Mobile), Viettel, Operational
	{"45205", "internet", "", ""},				//Vietnam, Hanoi Telecom, Vietnamobile, Operational
	{"45207", "internet", "", ""},				//Vietnam, GTEL Mobile JSC, Beeline VN, Operational
	{"45400", "hkcsl", "", ""},				//Hongkong, China, CSL Ltd, 1O1O / One2Free, Operational
	{"45402", "hkcsl", "", ""},				//Hongkong, China, CSL Ltd, CSL, Operational
	{"45403", "mobile.three.com.hk", "", ""},				//Hongkong, China, Hutchison Telecom, 3 (3G), Operational
	{"45404", "web-g.three.com.hk", "", ""},				//Hongkong, China, Hutchison Telecom, 3 (2G), Operational
	{"45406", "SmarTone-Vodafone", "", ""},				//Hongkong, China, SmarTone Mobile Communications Ltd, SmarTone-Vodafone, Operational
	{"45410", "hkcsl", "", ""},				//Hongkong, China, CSL Ltd, New World Mobility, Operational
	{"45412", "peoples.net", "", ""},				//Hongkong, China, China Mobile Hong Kong Company Ltd, CMCC HK, Operational
	{"45416", "pccwdata", "", ""},				//Hongkong, China, PCCW Ltd, PCCW Mobile, Operational
	{"45419", "pccw", "", ""},				//Hongkong, China, PCCW Ltd, PCCW Mobile, Operational
	{"45500", "smartgprs", "", ""},				//Macao China, SmarTone, , Operational
	{"45501", "ctm-mobile", "", ""},				//Macao China, C.T.M Telemovel+, CTM, Operational
	{"45503", "web-g.three.com.hk", "hutchison", "1234"},				//Macao China, Hutchison Telecom, 3, Operational
	{"45504", "ctm-mobile", "", ""},				//Macao China, C.T.M Telemovel+, CTM, Operational
	{"45601", "cellcard", "mobitel", "mobitel"},				//Cambodia, CamGSM, Mobitel, Operational
	{"45605", "smart", "", ""},				//Cambodia, Applifone Co. Ltd, Star-Cell, Operational
	{"45608", "metfone", "", ""},				//Cambodia, Viettel, Mefone, Operational
	{"46000", "cmnet", "", ""},				//China, China Mobile, , Operational
	{"46001", "UNINET", "", ""},				//China, China Unicom, , Operational
	{"46002", "cmnet", "", ""},				//China, Liaoning PPTA, , Operational
       {"46004", "cmmtm", "", ""},				//China, Liaoning PPTA, , Operational
      {"46006", "UNIM2M.NJM2MAPN", "", ""},		//
	{"46007", "cmnet", "", ""},				//China, China Mobile, , Operational
	{"46601", "internet", "", ""},				//Taiwan, Far EasTone Telecommunications Co Ltd, FarEasTone, Operational
	{"46688", "internet", "", ""},				//Taiwan, KG Telecom, KG Telecom, Operational
	{"46689", "vibo", "", ""},				//Taiwan, VIBO Telecom, VIBO, Operational
	{"46692", "internet", "", ""},				//Taiwan, Chunghwa Telecom LDM, Chungwa, Operational
	{"46693", "TWM", "", ""},				//Taiwan, Mobitai Communications, MobiTai, Operational
	{"46697", "TWM", "", ""},				//Taiwan, Taiwan Cellular Corporation, Taiwan Mobile, Operational
	{"46699", "TWM", "", ""},				//Taiwan, TransAsia Telecoms, TransAsia, Operational
	{"50212", "net", "maxis", "wap"},				//Malaysia, Maxis Communications Berhad, Maxis, Operational
	{"50216", "diginet", "", ""},				//Malaysia, DIGI, DiGi, Operational
	{"50218", "my3g", "", ""},				//Malaysia, U Mobile Sdn Bhd, U Mobile, Operational
	{"50219", "celcom.net.my", "", ""},				//Malaysia, CelCom, Celcom, Operational
	{"50501", "Telstra.wap", "", ""},				//Australia, Telstra Corporation Ltd., Telstra, Operational
	{"50502", "internet", "", ""},				//Australia, Optus Mobile Pty. Ltd., Optus, Operational
	{"50503", "live.vodafone.com", "", ""},				//Australia, Vodafone Network Pty. Ltd., Vodafone, Operational
	{"50506", "3netaccess", "", ""},				//Australia, Hutchison 3G Australia Pty. Ltd., Hi3G, Operational
	{"50511", "Telstra.wap", "", ""},				//Australia, Telstra Corporation Ltd., , Inactive
	{"50512", "3netaccess", "", ""},				//Australia, Hutchison 3G Australia Pty. Ltd., Hi3G, Operational
	{"50571", "Telstra.wap", "", ""},				//Australia, Telstra Corporation Ltd., Telstra, Operational
	{"50572", "Telstra.wap", "", ""},				//Australia, Telstra Corporation Ltd., Telstra, Operational
	{"50588", "vfinternet.au", "", ""},				//Australia, Localstar Holding Pty. Ltd., , Inactive
	{"50590", "internet", "", ""},				//Australia, Optus Ltd., Optus, Operational
	{"51001", "indosat3g", "indosat", "indosat"},				//Indonesia, PT Indonesian Satellite Corporation Tbk (INDOSAT), INDOSAT, Operational
	{"51008", "AXIS", "AXIS", "123456"},				//Indonesia, PT Natrindo Telepon Seluler, AXIS, Operational
	{"51010", "internet", "wap", "wap123"},				//Indonesia, PT Telekomunikasi Selular, Telkomsel, Operational
	{"51011", "www.xlgprs.net", "xlgprs", "proxl"},				//Indonesia, PT XL Axiata Tbk, XL, Operational
	{"51021", "indosatgprs", "indosat", "indosat"},				//Indonesia, PT Indonesian Satelite Corporation Tbk (Indosat), IM3, Inactive
	{"51089", "3gprs", "3gprs", "3gprs"},				//Indonesia, PT Hutchison CP Telecommunications, 3, Operational
	{"51502", "internet.globe.com.ph", "", ""},				//Philippines, Globe Telecom, Globe, Operational
	{"51503", "internet", "", ""},				//Philippines, PLDT via Smart Communications, Smart, Operational
	{"51505", "minternet", "", ""},				//Philippines, Digital Telecommunications Philippines, Sun, Operational
	{"51518", "redinternet", "", ""},				//Philippines, PLDT via Smarts Connectivity Unlimited Resources Enterprise, Cure, Operational
	{"52001", "internet", "", ""},				//Thailand, Advanced Info Service, AIS, Operational
	{"52018", "www.dtac.co.th", "", ""},				//Thailand, Total Access Communications (DTAC), dTac, Operational
	{"52099", "internet", "TRUE", "TRUE"},				//Thailand, True Corporation, True Move, Operational
	{"52501", "e-ideas", "", ""},				//Singapore, Singapore Telecom, SingTel, Operational
	{"52502", "e-ideas", "", ""},				//Singapore, Singapore Telecom, SingTel-G18, Operational
	{"52503", "sunsurf", "65", ""},				//Singapore, MobileOne Asia, M1, Operational
	{"52505", "internet", "", ""},				//Singapore, StarHub Mobile, StarHub, Operational
	{"53001", "www.vodafone.net.nz", "", ""},				//New Zealand, Vodafone New Zealand, Vodafone, Operational
	{"53005", "internet.telecom.co.nz", "", ""},				//New Zealand, Telecom New Zealand, XT Mobile (Telecom), Operational
	{"53024", "internet", "", ""},				//New Zealand, 2degrees, 2degrees, Operational
	{"60201", "MobinilWeb", "", ""},				//Egypt, EEMS - Mobinil, Mobinil, Operational
	{"60202", "internet.vodafone.net", "internet", "internet"},				//Egypt, Vodafone Egypt, Vodafone, Operational
	{"60203", "Etisalat", "", ""},				//Egypt, Etisalat Egypt, Etisalat, Operational
	{"60502", "gprs.tn", "gprs", "gprs"},				//Tunisia, Tunisie Telecom, Tunicell, Operational
	{"60503", "internet.tunisiana.com", "internet", "internet"},				//Tunisia, Orascom Telecom, Tunisiana, Operational
	{"62120", "internet.ng.Zain.com", "", ""},				//Nigeria, Bharti Airtel Ltd, Airtel, Operational
	{"62130", "web.gprs.mtnnigeria.net", "web", "web"},				//Nigeria, MTN Nigeria Communications, MTN, Operational
	{"62150", "glosecure", "gprs", "gprs"},				//Nigeria, Globacom Ltd, Glo, Operational
	{"62160", "etisalat", "", ""},				//Nigeria, Etisalat Ltd., Etisalat, Operational
	{"63902", "Safaricom", "saf", "data"},				//Kenya, Safaricom Ltd., Safaricom, Operational
	{"63903", "wap.ke.celtel.com", "wap", "wap"},				//Kenya, Celtel Kenya Limited, Zain, Operational
	{"63907", "wap.orange.co.ke", "", ""},				//Kenya, Econet Wireless Kenya, Orange Kenya, Operational
	{"64004", "Wap", "", ""},				//Tanzania, Vodacom Tanzania Ltd, Vodacom, Operational
	{"64700", "orangerun", "orange", "orange"},				//Reunion, Orange, , Operational
	{"64710", "sl2sfr", "", ""},				//Reunion, SFR Reunion, , Operational
	{"65101", "internet", "", ""},				//Lesotho, Vodacom Lesotho (pty) Ltd., Vodacom, Operational
	{"65501", "internet", "", ""},				//South Africa, Vodacom (Pty) Ltd., Vodacom, Operational
	{"65502", "internet", "", ""},				//South Africa, Telkom, Telkom Mobile / 8.ta, Operational
	{"65507", "internet", "", ""},				//South Africa, Cell C (Pty) Ltd., Cell C & Virgin, Operational
	{"65510", "myMTN", "mtn", ""},				//South Africa, Mobile Telephone Networks, MTN, Operational
	{"70401", "internet.ideasclaro", "", ""},				//Guatemala, Servicios de Comunicaciones Personales Inal芍mbricas, S.A., Claro, Operational
	{"70402", "broadband.tigo.gt", "", ""},				//Guatemala, Comunicaciones Celulares S.A., Comcel / Tigo, Operational
	{"70403", "internet.movistar.gt", "movistargt", "movistargt"},				//Guatemala, Telef車nica Centroam谷rica Guatemala S.A., Movistar, Operational
	{"70601", "internet.ideasclaro", "", ""},				//El Salvador, CTE Telecom Personal, S.A. de C.V., CTW Telecom Personal, Operational
	{"70603", "broadband.tigo.sv", "", ""},				//El Salvador, Telemovil EL Salvador S.A., Tigo, Operational
	{"70604", "internet.movistar.sv", "movistarsv", "movistarsv"},				//El Salvador, Telef車nica M車viles El Salvador, movistar, Operational
	{"70801", "web.megatel.hn", "webmegatel", "webmegatel"},				//Honduras, Servicios de Comunicaciones de Honduras S.A. de C.V., Claro, Operational
	{"70802", "internet.tigo.hn", "", ""},				//Honduras, Celtel / Tigo, Tigo, Operational
	{"71021", "web.emovil", "webemovil", "webemovil"},				//Nicaraqua, Empresa Nicarag邦ense de Telecomunicaciones, S.A. (ENITEL), Claro, Operational
	{"710730", "web.emovil", "webemovil", "webemovil"},				//Nicaraqua, SERCOM S.A. (Nicaragua), , Inactive
	{"71201", "kolbi3g", "", ""},				//Costa Rica, Instituto Costarricense de Electricidad - ICE, ICE, Operational
	{"71202", "kolbi3g", "", ""},				//Costa Rica, Instituto Costarricense de Electricidad - ICE, ICE, Operational
	{"71401", "apn01.cwpanama.com.pa", "", ""},				//Panama, Cable & Wireless Panama S.A., Cable & Wireless, Operational
	{"71403", "web.claro.com.pa", "CLAROWEB", "CLAROWEB"},				//Panama, Am谷rica M車vil, Claro, Operational
	{"71420", "internet.movistar.pa", "movistarpa", "movistarpa"},				//Panama, Movistar, , Inactive
	{"71606", "movistar.pe", "movistar@datos", "movistar"},				//Peru, Telef車nica M車viles Per迆, movistar, Operational
	{"71610", "claro.pe", "claro", "claro"},				//Peru, Am谷rica M車vil Per迆, Claro, Operational
	{"72207", "wap.gprs.unifon.com.ar", "wap", "wap"},				//Argentina, Telefonica M車viles Argentina SA, Movistar, Operational
	{"72234", "gprs.personal.com", "gprs", "adgj"},				//Argentina, Telecom Personal S.A., Personal, Inactive
	{"722310", "igprs.claro.com.ar", "ctigprs", "ctigprs999"},				//Argentina, AMX Argentina S.A, Claro, Operational
	{"722341", "gprs.personal.com", "gprs", "adgj"},				//Argentina, Telecom Personal S.A., Personal, Inactive
	{"72402", "timbrasil.br", "tim", "tim"},				//Brazil, Telecom Italia Mobile, TIM, Operational
	{"72403", "timbrasil.br", "tim", "tim"},				//Brazil, Telecom Italia Mobile, TIM, Operational
	{"72404", "timbrasil.br", "tim", "tim"},				//Brazil, Telecom Italia Mobile, TIM, Operational
	{"72405", "java.claro.com.br", "claro", "claro"},				//Brazil, Claro, Claro, Operational
	{"72406", "zap.vivo.com.br", "vivo", "vivo"},				//Brazil, Vivo S.A, Vivo, Operational
	{"72407", "sercomtel.com.br", "sercomtel", "sercomtel"},				//Brazil, CTBC Telecom, CTBC Celular, Operational
	{"72410", "zap.vivo.com.br", "vivo", "vivo"},				//Brazil, Vivo S.A, Vivo, Operational
	{"72411", "zap.vivo.com.br", "vivo", "vivo"},				//Brazil, Vivo S.A, Vivo, Operational
	{"72416", "brt.br", "brt", "brt"},				//Brazil, Brasil Telecom Celular S.A, Oi, Operational
	{"72419", "gprs.telemigcelular.com.br", "celular", "celular"},				//Brazil, Telemig Cel, , Inactive
	{"72423", "zap.vivo.com.br", "vivo", "vivo"},				//Brazil, Vivo S.A, Oi, Operational
	{"72424", "gprs.amazoniacelular.com.br", "celular", "celular"},				//Brazil, Amazonia Celular S/A, Oi / Brasil Telecom, Operational
	{"72431", "gprs.oi.com.br", "", ""},				//Brazil, TNL PCS, Oi, Operational
	{"73001", "bam.entelpcs.cl", "entelpcs", "entelpcs"},				//Chile, Entel PCS Telecomunicaciones S.A., entel, Operational
	{"73002", "web.tmovil.cl", "web", "web"},				//Chile, Telef車nica M車vil de Chile, movistar, Operational
	{"73003", "bam.clarochile.cl", "clarochile", "clarochile"},				//Chile, Claro Chile S.A., Claro, Operational
	{"73010", "bam.entelpcs.cl", "entelpcs", "entelpcs"},				//Chile, Entel Telefonia M車vil S.A., entel, Operational
	{"732101", "internet.comcel.com.co", "COMCELWEB", "COMCELWEB"},				//Colombia, Comcel S.A. Occel S.A./Celcaribe, Comcel, Operational
	{"732103", "web.colombiamovil.com.co", "", ""},				//Colombia, Colombia M車vil S.A., Tigo, Operational
	{"732111", "web.colombiamovil.com.co", "", ""},				//Colombia, Colombia M車vil S.A., Tigo, Operational
	{"732123", "internet.movistar.com.co", "movistar", "movistar"},				//Colombia, Telef車nica M車viles Colombia, Movistar, Operational
	{"73401", "gprsweb.digitel.ve", "", ""},				//Venezuela, Digitel, Digitel, Operational
	{"73402", "gprsweb.digitel.ve", "", ""},				//Venezuela, Digitel, Digitel, Operational
	{"73403", "gprsweb.digitel.ve", "", ""},				//Venezuela, Digitel, Digitel, Operational
	{"73404", "internet.movistar.ve", "", ""},				//Venezuela, Movistar, Movistar, Operational
	{"73406", "int.movilnet.com.ve", "", ""},				//Venezuela, Movilnet, Movilnet, Operational
	{"74000", "internet.movistar.com.ec", "movistar", "movistar"},				//Ecuador, Otecel S.A. - Bellsouth, Moviestar, Operational
	{"74001", "internet.porta.com.ec", "", ""},				//Ecuador, Am谷rica M車vil, Porta, Operational
	{"74002", "internet.alegro.net.ec", "", ""},				//Ecuador, Telecsa S.A., Alegro, Operational
	{"74401", "vox.internet", "", ""},				//Paraquay, Hola Paraguay S.A, VOX, Operational
	{"74402", "igprs.claro.com.py", "ctigprs", "ctigprs999"},				//Paraquay, AMX Paraguay S.A., Claro, Operational
	{"74404", "internet.tigo.py", "", ""},				//Paraquay, Telefonica Celular Del Paraguay S.A. (Telecel), Claro, Operational
	{"74405", "internet", "personal", "personal"},				//Paraquay, N迆cleo S.A, Personal, Operational
	{"74801", "wap", "", ""},				//Uruguay, Compania estatal (ANTEL), Ancel, Operational
	{"74807", "webapn.movistar.com.uy", "movistar", "movistar"},				//Uruguay, Telef車nica M車viles Uruguay, Movistar, Operational
	{"74810", "igprs.claro.com.uy", "ctigprs", "ctigprs999"},				//Uruguay, AM Wireless Uruguay S.A., Claro, Operational
	//軞杅ㄩ591
};



track_custom_gprs_apn_struct *track_net_get_apn(char *imsi)
{
    static track_custom_gprs_apn_struct apn_cust = {0};
    char sim_id[10] = {0};
    int size, i;
    if(strlen(imsi) < 15)
    {
        //OTA_LOGD(L_SOC, L_V1, "ERROR APN!");
        return NULL;
    }
    strncpy(sim_id, imsi, 5);
    //OTA_LOGD(L_SOC, L_V5, "sim id:%s", sim_id);

    size = sizeof(apns) / sizeof(apn_struct);
    //OTA_LOGD(L_SOC, L_V5, "size:%d", size);
    for(i=0; i<size; i++)
    {
        if(!strcmp(apns[i].MCC_MNC, sim_id))
        {
            apn_cust.APN = apns[i].APN;
            apn_cust.UserName = apns[i].Name;
            apn_cust.Passwd = apns[i].Password;
            //OTA_LOGD(L_SOC, L_V5, "[%d] apn name:%s,%s,%s", i, apn_cust.APN, apn_cust.UserName, apn_cust.Passwd);
            return &apn_cust;
        }
    }

    strncpy(sim_id, imsi, 6);
    for(i=0; i<size; i++)
    {
        if(!strcmp(apns[i].MCC_MNC, sim_id))
        {
            apn_cust.APN = apns[i].APN;
            apn_cust.UserName = apns[i].Name;
            apn_cust.Passwd = apns[i].Password;
            return &apn_cust;
        }
    }
    return NULL;
}
//#endif

/*****************************************************************************
 * FUNCTION
 *  custom_config_get_gprs_account
 * DESCRIPTION
 *  get gprs bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_gprs_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    static kal_int32 gprs_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_gprs);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GPRS_FEATURES__
    if (gprs_num < max_size)
    {
        return (void*)&g_config_account_gprs[gprs_num++];
    }
    gprs_num = 0;
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  custom_config_get_csd_account
 * DESCRIPTION
 *  get csd bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
static void *custom_config_get_csd_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP_OVER_CSD__
    static kal_int32 csd_num = 0;
    kal_int32 max_size = CUSTOM_TABLE_SIZE(g_config_account_csd);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP_OVER_CSD__   
    if (csd_num < max_size)
    {
        return (void*)&g_config_account_csd[csd_num++];
    }
    csd_num = 0;
#endif    
    return NULL;    
}


#endif  //__DA_MEMORY_CUT__

/*****************************************************************************
 * FUNCTION
 *  custom_config_get_account
 * DESCRIPTION
 *  get bearer account
 * PARAMETERS
 *  type    [IN]   bearer type
 * RETURNS
 *  void * return account information on success, otherwise NULL.
 *****************************************************************************/
void *custom_config_get_account(kal_int32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DA_MEMORY_CUT__
    return NULL;
#else
    if (type == CUSTOM_DATA_ACCOUNT_BEARER_GPRS)
    {
        return custom_config_get_gprs_account();
    }

    return custom_config_get_csd_account();
#endif
}

#endif /* __TCPIP__ */ 


