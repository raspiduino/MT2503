/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

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
 *
 * Filename:
 * ---------
 * bt_cust.c
 *
 * Project:
 * --------
 *   BT Project
 *
 * Description:
 * ------------
 *   This file is used to customization bt host
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifdef __BT_USE_CUST_DATA__

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "bt_cust_type.h"
#ifdef BTMTK_ON_MAUI
#include <stdarg.h>
#endif
#ifdef BTMTK_ON_LINUX
#include <cutils/log.h>
#endif

/*************************************
*   Macro
**************************************/
#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "[BT][CUST]"

/*************************************
*   Typedef
**************************************/
typedef struct _bt_config_item
{
    const char *name; /* config name */
    const void *value; /* shall be int or pointer to const string */
} bt_config_item;

typedef struct _bt_dev_config_item
{
    const char *name; /* config name */
    const void *value; /* shall be int or pointer to const string */
    unsigned int cid;
} bt_dev_config_item;

typedef struct _bt_dev_config
{
    const char *name; /* device name */
    bt_dev_config_item *config_table;
} bt_dev_config;


/*************************************
*   Extern functions
**************************************/
extern unsigned int getCustTable(bt_config_item **table);
extern unsigned int getDevCustTable(bt_dev_config **config);


/*************************************
*   Global variable
**************************************/
static bt_log g_log_api = NULL;
static bt_config_item *g_cust_table = NULL;
static unsigned int g_cust_table_size = 0;
static bt_dev_config *g_dev_config = NULL;
static unsigned int g_dev_config_size = 0;

/* default log api */
void cust_log(const char *log)
{
#ifdef BTMTK_ON_LINUX
    ALOGD("%s", log);
#endif
}

void debug_log(const char *fmt, ...)
{
    char buffer[200];   /* Output buffer */
    va_list args;
    va_start(args, fmt);
    vsnprintf(buffer, 200, fmt, args);
    va_end(args);
    g_log_api(buffer);
}

void dumpCust(void)
{
    unsigned int i, j;
    bt_dev_config_item *dev;
    debug_log("dumpCust");
    /* Display cust table */
    debug_log("g_cust_table=%p, g_cust_table_size=%u", g_cust_table, g_cust_table_size);
    for (i = 0; i < g_cust_table_size; i++)
    {
        debug_log("%u : %s=%p", i, g_cust_table[i].name, g_cust_table[i].value);
    }
    /* Display dev table */
    debug_log("g_dev_config=%p, g_dev_config_size=%u", g_dev_config, g_dev_config_size);
    for (i = 0; i < g_dev_config_size; i++)
    {
        debug_log("%d : dev=%s, config=%p", i, g_dev_config[i].name, g_dev_config[i].config_table);
        dev = g_dev_config[i].config_table;
        j = 0;
        while (dev && dev->name)
        {
            debug_log("  %d : %s=%p cid=%u", j++, dev->name, dev->value, dev->cid);
            dev++;
        }
    }
}

/* return the customization id : 0 means no match */
BT_CUST_ID getCustID(const char *name)
{
    unsigned int i;
    if (g_cust_table)
    {
        for (i = 0; i < g_cust_table_size; i++)
        {
            if (strcmp(g_cust_table[i].name, name) == 0)
                return (BT_CUST_ID)(i + 1);
        }
    }
    debug_log("getCustID failed : %s", name ? name : "NULL");
    dumpCust();
    return BT_CUST_UNKNOWN;
}

/* return the device id : 0 means no match */
BT_DEVICE_ID getDeviceID(const char *name)
{
    unsigned int i;
    if (g_dev_config)
    {
        for (i = 0; i < g_dev_config_size; i++)
        {
            if (strcmp(g_dev_config[i].name, name) == 0)
                return (BT_DEVICE_ID)(i + 1);
        }
    }
    debug_log("getDeviceID failed : %s", name ? name : "NULL");
    dumpCust();
    return BT_DEVICE_UNKNOWN;
}

/* 0 : no match, others means success */
unsigned int getCustValue(BT_CUST_ID cid, unsigned int *value)
{
    if (value && g_cust_table && cid > 0 && cid <= g_cust_table_size)
    {
        *value = (unsigned int)g_cust_table[(cid - 1)].value;
        return 1;
    }
    debug_log("getCustValue failed : cid=%u, value=%p", cid, value);
    dumpCust();
    return 0;
}

/*
unsigned int getCustInt(BT_CUST_ID cid, unsigned int *value){
    if(value && g_cust_table && cid > 0 && cid <= g_cust_table_size){
        *value = (unsigned int)g_cust_table[(cid-1)].value;
        return 1;
    }
    return 0;
}

unsigned int getCustStr(BT_CUST_ID cid, const char **value){
    if(g_cust_table && cid <= g_cust_table_size){
        *value = (const char*)g_cust_table[(cid-1)].value;
        return 1;
    }
    return 0;
}

unsigned int getDevCustInt(BT_DEVICE_ID did, BT_CUST_ID cid){
    if(g_dev_config && cid <= g_cust_table_size){
        return (const char*)g_cust_table[(cid-1)].value;
    }
}

const char *getDevCustStr(BT_DEVICE_ID did, BT_CUST_ID cid);
*/

/* 0 : no match, others means success */
unsigned int getDevCustValue(BT_DEVICE_ID did, BT_CUST_ID cid, unsigned int *value)
{
    bt_dev_config_item *config;
    if (value && g_dev_config
        && did > 0 && did <= g_dev_config_size)
    {
        config = g_dev_config[(did - 1)].config_table;
        if (config)
        {
            while (config->name)
            {
                if (config->cid == cid)
                {
                    *value = (unsigned int)config->value;
                    return 1;
                }
                config++;
            }
        }
        debug_log("getDevCustValue : cannot get cid(%u) in did(%u). Try cust table", cid, did);
    }
    else
    {
        debug_log("getDevCustValue failed : try getCustValue. did=%u, cid=%u, value=%p,", did, cid, value);
    }
    return getCustValue(cid, value);
}

/* Init the customization table */
int initCust(bt_log log_api)
{
    unsigned int i, j;
    bt_dev_config_item *dev = NULL;
    g_log_api = (log_api == NULL) ? cust_log : log_api;
    g_cust_table_size = getCustTable(&g_cust_table);
    g_dev_config_size = getDevCustTable(&g_dev_config);
    debug_log("initCust : cust table size=%d(%p), dev num=%d(%p)",
              g_cust_table_size,
              g_cust_table,
              g_dev_config_size,
              g_dev_config);
    /* init dev config cid */
    for (i = 0; i < g_dev_config_size; i++)
    {
        dev = g_dev_config[i].config_table;
        while (dev->name)
        {
            dev->cid = getCustID(dev->name);
            if (dev->cid == BT_CUST_UNKNOWN)
            {
                debug_log("[CUST] Can not find device(%s) cust(%s) in g_config_table in bt_cust_table.h",
                          g_dev_config[i].name,
                          dev->name);
#ifdef BTMTK_ON_LINUX
                usleep(2);
                abort();
#else
                return 0;  //TODO:
#endif
            }
            dev++;
        }
    }
    return 1;
}

#ifdef BTMTK_ON_MAUI
#include "bt_cust_table.h"

unsigned int getCustTable(bt_config_item **table)
{
    *table = (bt_config_item *)&cust_config_table;
    return sizeof(cust_config_table) / sizeof(cust_config_table[0]);
}

unsigned int getDevCustTable(bt_dev_config **config)
{
    *config = (bt_dev_config *)&cust_dev_config;
    return sizeof(cust_dev_config) / sizeof(cust_dev_config[0]);
}

#endif
#endif /*__BT_USE_CUST_DATA__*/
