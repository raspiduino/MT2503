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
 * BtcmSrvMain.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
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
 *============================================================================
 ****************************************************************************/
#ifdef __BCM_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "Bcm_btcmSrvProt.h"
#include "Bcm_btcmSrvGprot.h"
#include "bcm_trc.h"
#include "bluetooth_bm_struct.h"

#ifdef __SUPPORT_JBT__
#include "mmiapi_bt_struct.h"
#include "BTMMIBccGprots.h"
#endif


// #ifdef __DM_LAWMO_SUPPORT__
// #include "dmuigprot.h"
// #endif /*__DM_LAWMO_SUPPORT__*/

#include "conversions.h"

// RHR: add
#include "kal_trace.h"
#include "stack_msgs.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "kal_public_api.h"
//#include "bt_a2dp_base_struct.h"
// RHR: add

/***************************************************************************** 
* External Variable
*****************************************************************************/


srv_bt_cm_profile_struct_int g_srv_bt_cm_profile_tbl[SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE];

extern MMI_BOOL srv_bt_cm_is_hf_profile_connected(U32);

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
srv_bt_cm_cntx_struct g_srv_bt_cm_cntx;

MMI_BOOL SRV_BT_CM_GET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_srv_bt_cm_cntx.flag) & flag) != 0 ? MMI_TRUE : MMI_FALSE;
}
#ifdef __BT_DIALER_SUPPORT__
void srv_bt_cm_set_btdialor_mode(MMI_BOOL val)
{
	g_srv_bt_cm_cntx.bt_dialor_mode=val;

}

MMI_BOOL srv_bt_cm_get_btdialor_mode(void)
{
	return g_srv_bt_cm_cntx.bt_dialor_mode;
}
#endif
#ifdef __MMI_BT_DIALER_SUPPORT__
void srv_bt_cm_set_btdialor_app_mode(MMI_BOOL val)
{
	g_srv_bt_cm_cntx.bt_dialor_app_mode=val;
}
MMI_BOOL srv_bt_cm_get_btdialor_app_mode(void)
{
	return g_srv_bt_cm_cntx.bt_dialor_app_mode;
}
#endif

void SRV_BT_CM_SET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_FLAG, g_srv_bt_cm_cntx.flag, g_srv_bt_cm_cntx.flag | flag);
    g_srv_bt_cm_cntx.flag |= flag;
}

void SRV_BT_CM_RESET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_RESET_FLAG, g_srv_bt_cm_cntx.flag, ((g_srv_bt_cm_cntx.flag)&(~flag)));
    (g_srv_bt_cm_cntx.flag) &=  ~flag;
}

MMI_BOOL SRV_BT_CM_GET_RAMFLAG(U32 ram_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_srv_bt_cm_cntx.ram_flag) & ram_flag) != 0 ? MMI_TRUE : MMI_FALSE;
}

void SRV_BT_CM_SET_RAMFLAG(U32 ram_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_SET_RAMFLAG, g_srv_bt_cm_cntx.ram_flag, ((g_srv_bt_cm_cntx.ram_flag)|ram_flag));
    ((g_srv_bt_cm_cntx.ram_flag) |= ram_flag);
}

void SRV_BT_CM_RESET_RAMFLAG(U32 ram_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_BT_RESET_RAMFLAG, g_srv_bt_cm_cntx.ram_flag, ((g_srv_bt_cm_cntx.ram_flag)&(~ram_flag)));
    ((g_srv_bt_cm_cntx.ram_flag) &= ~ram_flag);
}

void SRV_BT_CM_STATE_TRANS(U32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_STATE_TRANS, g_srv_bt_cm_cntx.state, state);
    g_srv_bt_cm_cntx.state = (srv_bt_cm_state_enum)state;
}

void SRV_BT_CM_TMP_STATE_TRANS(U32 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_TMP_STATE_TRANS, g_srv_bt_cm_cntx.tmp_state, state);
    g_srv_bt_cm_cntx.tmp_state = (srv_bt_cm_state_enum)state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_init_event_handler
 * DESCRIPTION
 *  This function is to init event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_INIT_EVENT_HANDLER);
#if 0
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
#ifdef __MMI_BT_SIMPLE_PAIR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BT_SIMPLE_PAIR__ */
/* under construction !*/
#ifdef __MMI_BT_AUTHORIZE__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BT_AUTHORIZE__ */
/* under construction !*/
#ifdef __BT_BOND_CANCEL__
/* under construction !*/
#endif
/* under construction !*/
#endif
}
    
    
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_name_duplicated
 * DESCRIPTION
 *  This function is to check if name is duplicated with other paired device, if yes, will add a prefix.
 * PARAMETERS
 *  name_p                  [OUT]       name pointer
 *  skip_paired_index       [IN]          the index of paired device to skip
 * RETURNS
 *  MMI_BOOL        TRUE : the name is duplicated
 *                  FALSE : the name is not duplicated
 *****************************************************************************/
/* MMI_BOOL srv_bt_cm_is_name_duplicated(kal_uint8* name_p, U8 skip_paired_index) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_BOOL result = MMI_FALSE; */
/*     U32 i,j; */
/*     U8 paired_name_byte_cnt;    /\* paired_dev_num *\/ */
/*     srv_bt_cm_dev_struct* dev_p; */
/*     kal_uint8 in_name_buf[SRV_BT_CM_BD_FNAME_LEN]; */
/*     kal_uint8 paired_name_buf[SRV_BT_CM_BD_FNAME_LEN]; */
/*     U8 dup_counter, dup_counter_array[SRV_BT_CM_MAX_DEVICE_LIST]; */
/*     kal_char *counter_str, *last_p; */
/*     kal_uint8 prefix_buf[15]; */
/*     kal_uint8 tmp_name_1[SRV_BT_CM_BD_FNAME_LEN], tmp_name_2[SRV_BT_CM_BD_FNAME_LEN]; */

/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     memset(prefix_buf, 0, 15); */
/*     memcpy(in_name_buf, name_p, SRV_BT_CM_BD_FNAME_LEN); */
/*     //paired_dev_num = g_srv_bt_cm_cntx.paired_dev_num; */
/*     for (i =0; i < SRV_BT_CM_MAX_DEVICE_LIST; i++) */
/*     { */
/*         dup_counter_array[i] = 0; */
/*     } */
    
/*     //for (i = 0; i < paired_dev_num; i++) */
/*     for (i = 0; i < SRV_BT_CM_MAX_DEVICE_LIST; i++) */
/*     { */
/*         if ((i == skip_paired_index) || */
/*             (g_srv_bt_cm_cntx.dev_list[i].ref_cnt == 0)) */
/*         { */
/*             continue; */
/*         } */

/*         dev_p = &(g_srv_bt_cm_cntx.dev_list[i].dev_info); */
/*         memcpy(paired_name_buf, dev_p->name, SRV_BT_CM_BD_FNAME_LEN); */

/*         /\* get character count of utf8 string *\/ */
/*         paired_name_byte_cnt = strlen((const char*)paired_name_buf); */

/*         /\* only compare the device name length *\/ */
/*         mmi_chset_utf8_to_ucs2_string( */
/*             (kal_uint8*)tmp_name_1, */
/*             SRV_BT_CM_BD_FNAME_LEN, */
/*             (kal_uint8*)name_p); */
/*         mmi_chset_utf8_to_ucs2_string( */
/*             (kal_uint8*)tmp_name_2, */
/*             SRV_BT_CM_BD_FNAME_LEN, */
/*             (kal_uint8*)paired_name_buf); */
        
/*         /\* change the encoding from UTF8 to UCS2, then compare the (device name length) *2 *\/ */
/*         if (mmi_ucs2ncmp((const char*)tmp_name_1, (const char*)tmp_name_2, (SRV_BT_CM_BD_FNAME_LEN - 2) / 3) == 0 && */
/*             (dev_p->bd_addr.lap != 0 || dev_p->bd_addr.nap != 0 || dev_p->bd_addr.uap !=0)) */
/*         { */
/*             result = MMI_TRUE; */
/*         } */
/*         /\* compare the usc2 string length *\/ */
/*         if (mmi_ucs2strlen((const S8*)tmp_name_1) <= mmi_ucs2strlen((const S8*)tmp_name_2) || */
/*             mmi_ucs2strlen((const S8*)tmp_name_2) == (SRV_BT_CM_BD_FNAME_LEN - 2) / 3) */
/*         { */
/*             /\* if the prefix is Dup, then compare the remaining string *\/ */
/*             if (strncmp((S8*)paired_name_buf, "Dup", 3) == 0) */
/*             { */
/*                 j = 0; */
/*                 while (j < paired_name_byte_cnt) */
/*                 { */
/*                     if (paired_name_buf[j]== ')') */
/*                     { */
/*                         break; */
/*                     } */
/*                     j++; */
/*                 } */

/*                 if (j < paired_name_byte_cnt) */
/*                 { */
/*                     mmi_chset_utf8_to_ucs2_string( */
/*                         (kal_uint8*)tmp_name_1, */
/*                         SRV_BT_CM_BD_FNAME_LEN, */
/*                         (kal_uint8*)paired_name_buf+(j+1)); */
/*                     mmi_chset_utf8_to_ucs2_string( */
/*                         (kal_uint8*)tmp_name_2, */
/*                         SRV_BT_CM_BD_FNAME_LEN, */
/*                         (kal_uint8*)name_p); */
        
/*                     /\* change the encoding from UTF8 to UCS2, then compare the (device name length) *2 *\/ */
/*                     if (mmi_ucs2ncmp( */
/*                             (const char*)tmp_name_1, */
/*                             (const char*)tmp_name_2, */
/*                             (SRV_BT_CM_BD_FNAME_LEN - 2) / 3 - strlen("Dup(1)")) == 0) */
/*                     { */
/*                         counter_str = (kal_char*)kal_strtok_r( */
/*                             (kal_char*)(paired_name_buf + 4), */
/*                             (const kal_char*)")", */
/*                             (kal_char**)&last_p); */
/*                         if (counter_str != NULL) */
/*                         { */
/*                             dup_counter = atoi(counter_str); */
/*                             if (dup_counter != 0 && dup_counter < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST) */
/*                             { */
/*                                 dup_counter_array[dup_counter] = 1; */
/*                             } */
/*                         } */
/*                     } */
/*                 } */
/*             } */
/*         } */
/*     } */

/*     for (i = 1; i < SRV_BT_CM_MAX_PAIRED_DEVICE_LIST; i++) */
/*     { */
/*         if (dup_counter_array[i] == 0) */
/*         { */
/*             break; */
/*         } */
/*     } */

/*     switch (result) */
/*     { */
/*         case MMI_TRUE: */
/*             kal_sprintf((S8*)prefix_buf, "Dup(%d)", i); */
/*             strcpy((char*)name_p, (const char*)prefix_buf); */
/*             /\*Dup(*), utf8 encoding *\/ */
/*             mmi_chset_utf8_to_ucs2_string( */
/*                 (kal_uint8*)tmp_name_1, */
/*                 SRV_BT_CM_BD_FNAME_LEN, */
/*                 (kal_uint8*)name_p); */
/*             mmi_chset_utf8_to_ucs2_string( */
/*                 (kal_uint8*)tmp_name_2, */
/*                 SRV_BT_CM_BD_FNAME_LEN, */
/*                 (kal_uint8*)in_name_buf); */
/*             mmi_ucs2ncat((S8*)tmp_name_1, (S8*)tmp_name_2, (SRV_BT_CM_BD_FNAME_LEN - 2) / 3 - strlen("Dup(1)")); */
/*             mmi_chset_ucs2_to_utf8_string(name_p, SRV_BT_CM_BD_FNAME_LEN, tmp_name_1); */
/*             break; */
/*     } */

/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_IS_NAME_DUPLICATED, result); */
/*     return result; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_activate_profiles
 * DESCRIPTION
 *  This function is to process activat profile request and invoke activate functions of profiles
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_activate_profiles_int(MMI_BOOL flight_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        /* if it's in flight mode, don't activate DUN, FAX */
        if (flight_mode)
        {
            if ((g_srv_bt_cm_profile_tbl[i].profile_id == SRV_BT_CM_DUN_PROFILE_UUID) ||
                (g_srv_bt_cm_profile_tbl[i].profile_id == SRV_BT_CM_FAX_PROFILE_UUID))
            {
                continue;
            }
        }

        if ((g_srv_bt_cm_cntx.deactivate_flag & (g_srv_bt_cm_profile_tbl[i].deactivate_flag)))
        {
            if (g_srv_bt_cm_profile_tbl[i].activater)
            {
                (*g_srv_bt_cm_profile_tbl[i].activater)();
                MMI_TRACE(
                    MMI_CONN_TRC_G7_BT,
                    SRV_BT_CM_ACTIVATE_PROFILES_INT,
                    g_srv_bt_cm_cntx.deactivate_flag,
                    flight_mode,
                    g_srv_bt_cm_profile_tbl[i].profile_id);
            }
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_all_supported_profiles_activated
 * DESCRIPTION
 *  This function is to check if all supported profiles are activated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : all supported profiles are activated
                    FALSE : not all supported profiles are activated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_all_supported_profiles_activated(MMI_BOOL flight_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if ((g_srv_bt_cm_cntx.deactivate_flag & (g_srv_bt_cm_profile_tbl[i].deactivate_flag)) && 
            (g_srv_bt_cm_profile_tbl[i].activater))
        {
            /* if it's in flight mode, don't activate DUN, FAX */
            if (flight_mode)
            {
                if (g_srv_bt_cm_profile_tbl[i].profile_id == SRV_BT_CM_DUN_PROFILE_UUID ||
                    g_srv_bt_cm_profile_tbl[i].profile_id == SRV_BT_CM_FAX_PROFILE_UUID)
                {
                    continue;
                }
            }

            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_IS_ALL_SUPPORTED_PROFILES_ACTIVATED,
                flight_mode,
                g_srv_bt_cm_profile_tbl[i].profile_id,
                result);
            result = MMI_FALSE;
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_all_supported_profiles_deactivated
 * DESCRIPTION
 *  This function is to check if all supported profiles are deactivated
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : all supported profiles are deactivated
                    FALSE : not all supported profiles are deactivated
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_all_supported_profiles_deactivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_HOST_SUPPORTED_PROFILE; ++i)
    {
        if (!(g_srv_bt_cm_cntx.deactivate_flag & (g_srv_bt_cm_profile_tbl[i].deactivate_flag)) && 
            (g_srv_bt_cm_profile_tbl[i].deactivater))
        {
            result = MMI_FALSE;
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_IS_ALL_SUPPORTED_PROFILES_DEACTIVATED,
                g_srv_bt_cm_profile_tbl[i].profile_id,
                result);
            break;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_deactivate_flag
 * DESCRIPTION
 *  This function is to set deactivate flag
 * PARAMETERS
 *  prof_flag       [IN]            profile flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_deactivate_flag(U32 prof_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_DEACTIVATE_FLAG,
        prof_flag);
    g_srv_bt_cm_cntx.deactivate_flag |= prof_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_reset_deactivate_flag
 * DESCRIPTION
 *  This function is to reset deactivate flag
 * PARAMETERS
 *  prof_flag       [IN]            profile flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_reset_deactivate_flag(U32 prof_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_RESET_DEACTIVATE_FLAG,
        prof_flag);

    g_srv_bt_cm_cntx.deactivate_flag &= ~(prof_flag);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_pairing_permitted
 * DESCRIPTION
 *  This function is to check if pairing is permitted
 * PARAMETERS
 *  srv_bt_cm_bt_addr dev_addr, specify the device address
 * RETURNS
 *  MMI_BOOL    MMI_TRUE    permitted
 *              MMI_FALSE   not permitted
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_pairing_permitted(srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result =  MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_bt_cm_cntx.pair_permission_cb.func_ptr)
    {
        result = (*g_srv_bt_cm_cntx.pair_permission_cb.func_ptr)(dev_addr);
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_IS_PAIRING_PERMITTED,
        g_srv_bt_cm_cntx.pair_permission_cb.profile_uuid,
        result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_a2dp_prohibit_vis
 * DESCRIPTION
 *  This function is to set A2DP prohibit visibility
 * PARAMETERS
 *  setting     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_a2dp_prohibit_vis(MMI_BOOL setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_A2DP_PROHIBIT_VIS,
        setting);
    g_srv_bt_cm_cntx.a2dp_prohibit_vis = setting;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_increase_paired_dev_num
 * DESCRIPTION
 *  This function is to increase g_srv_bt_cm_cntx.paired_dev_num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_increase_paired_dev_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bt_cm_cntx.paired_dev_num++;
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_INCREASE_PAIRED_DEV_NUM,
        g_srv_bt_cm_cntx.paired_dev_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_decrease_paired_dev_num
 * DESCRIPTION
 *  This function is decrease g_srv_bt_cm_cntx.paired_dev_num
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_decrease_paired_dev_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BT_ASSERT(g_srv_bt_cm_cntx.paired_dev_num);
    g_srv_bt_cm_cntx.paired_dev_num--;
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_DECREASE_PAIRED_DEV_NUM,
        g_srv_bt_cm_cntx.paired_dev_num--);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_action_index
 * DESCRIPTION
 *  This function is to set g_srv_bt_cm_cntx.action_index
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_action_index(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_ACTION_INDEX,
        index);
    g_srv_bt_cm_cntx.action_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_echo_conn_cnf_stack
 * DESCRIPTION
 *  This function is echo the conn_cnf stack info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_echo_conn_cnf_stack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 5; i++)
    {
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_ECHO_CONN_CNF_STACK,
        i,
        g_srv_bt_cm_cntx.conn_cnf[i].profile_id,
        g_srv_bt_cm_cntx.conn_cnf[i].conn_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_push_conn_cnf_stack
 * DESCRIPTION
 *  This function is push conn cnf structure into stack
 * PARAMETERS
 *  profile_id : connection confirm profile id
 *  conn_id    : connection confirm index of device
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_push_conn_cnf_stack(U32 profile_id, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; i++)
    {
        if (g_srv_bt_cm_cntx.conn_cnf[i].profile_id == 0)
        {
            g_srv_bt_cm_cntx.conn_cnf[i].profile_id = profile_id;
            g_srv_bt_cm_cntx.conn_cnf[i].conn_id = conn_id;
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_PUSH_CONN_CNF_STACK,
                i,
                profile_id,
                conn_id);
            srv_bt_cm_echo_conn_cnf_stack();
            return;
        }
    }

    MMI_BT_ASSERT(i < SRV_BT_CM_MAX_CONNECTION);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_pop_conn_cnf_stack
 * DESCRIPTION
 *  This function is to popup conn cnf structure out of stack
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_conn_cnf_struct
 *****************************************************************************/
srv_bt_cm_conn_cnf_struct* srv_bt_cm_pop_conn_cnf_stack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_BT_CM_MAX_CONNECTION - 1; i >= 0; i--)
    {
        if (g_srv_bt_cm_cntx.conn_cnf[i].profile_id != 0)
        {
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_POP_CONN_CNF_STACK,
                i,
                g_srv_bt_cm_cntx.conn_cnf[i].profile_id,
                g_srv_bt_cm_cntx.conn_cnf[i].conn_id);
            return &(g_srv_bt_cm_cntx.conn_cnf[i]);
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_clear_top_conn_cnf_stack
 * DESCRIPTION
 *  This function is to set top of conn cnf structure stack as zero
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
// void srv_bt_cm_clear_top_conn_cnf_stack(void)
// {
//     /*----------------------------------------------------------------*/
//     /* Local Variables                                                */
//     /*----------------------------------------------------------------*/
//     int i;

//     /*----------------------------------------------------------------*/
//     /* Code Body                                                      */
//     /*----------------------------------------------------------------*/
//     for (i = SRV_BT_CM_MAX_CONNECTION-1; i >= 0; i--)
//     {
//         if (g_srv_bt_cm_cntx.conn_cnf[i].conn_cnf_profile_id != 0)
//         {
//             g_srv_bt_cm_cntx.conn_cnf[i].conn_cnf_profile_id = 0;
//             g_srv_bt_cm_cntx.conn_cnf[i].conn_cnf_idx = 0;
//             MMI_TRACE(
//                 MMI_CONN_TRC_G7_BT,
//                 MMI_BT_G7_SRV_BT_CM_CLEAR_TOP_CONN_CNF_STACK,
//                 i,
//                 g_srv_bt_cm_cntx.conn_cnf[i].conn_cnf_profile_id);
//             srv_bt_cm_echo_stack_info();
//             return;
//         }
//     }

//     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_CLEAR_TOP_CONN_CNF_STACK_NOT_FOUND);
// }


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_clear_specific_conn_cnf_stack
 * DESCRIPTION
 *  This function is to set specific conn cnf structure stack as zero
 * PARAMETERS
 *  conn_id : profile ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_cm_clear_specific_conn_cnf_stack(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_BT_CM_MAX_CONNECTION - 1; i >= 0; --i)
    {
        if (g_srv_bt_cm_cntx.conn_cnf[i].conn_id == conn_id)
        {
            result = MMI_TRUE;
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BT_CM_CLEAR_SPECIFIC_CONN_CNF_STACK,
                g_srv_bt_cm_cntx.conn_cnf[i].profile_id,
                conn_id);

            for (j = i; j < SRV_BT_CM_MAX_CONNECTION - 1; j++)
            {
                if (g_srv_bt_cm_cntx.conn_cnf[j + 1].conn_id != 0)
                {
                    g_srv_bt_cm_cntx.conn_cnf[j].profile_id = 
                        g_srv_bt_cm_cntx.conn_cnf[j + 1].profile_id;
                    g_srv_bt_cm_cntx.conn_cnf[j].conn_id =
                        g_srv_bt_cm_cntx.conn_cnf[j + 1].conn_id;
                }
                else
                {
                    break;
                }
            }

            g_srv_bt_cm_cntx.conn_cnf[j].profile_id = 0;
            g_srv_bt_cm_cntx.conn_cnf[j].conn_id = 0;
            break;
        }
    }

    srv_bt_cm_echo_conn_cnf_stack();
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_connect_paired_headset_with_index
 * DESCRIPTION
 *  This function is to process connect headset, with paired index as parameter
 * PARAMETERS
 *  paired_index : the paired device index 
 *  show_prgs_scr : to show progressing screen or not
 * RETURNS
 *  MMI_BOOL        TRUE : success to connect
 *                  FALSE : otherwise
 *****************************************************************************/
/* MMI_BOOL srv_bt_cm_connect_paired_headset_with_index(U32 paired_index, srv_bt_cm_hs_connect_scr_show_enum prgs_scr) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_BOOL result = MMI_FALSE; */
/*     MMI_BOOL b_show_prgs_scr = (prgs_scr == SRV_BT_CM_HS_SHOW_CONNECT_SCR) ? MMI_TRUE: MMI_FALSE; */
    
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_CONNECT_INDEXED_HEADSET, paired_index, prgs_scr); */
/*     MMI_BT_ASSERT(paired_index < g_srv_bt_cm_cntx.paired_dev_num); */

/*     /\* reset the state *\/ */
/*     g_srv_bt_cm_cntx.hs_conn_state = SRV_BT_CM_HS_CONNECTING_STATE_IDLE; */

/*     if (srv_bt_cm_is_service_support(paired_index, SRV_BT_CM_HF_PROFILE_UUID)) */
/*     { */
/*         if (b_show_prgs_scr && g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) */
/*         { */
/*             (*g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)(SCR_BT_CONNECT_LAST_HEADSET, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            NULL, */
/*                                                                            MMI_FALSE, */
/*                                                                            NULL); */
/*         } */
        
/*         result = srv_bt_cm_connect(&(g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr), SRV_BT_CM_HF_PROFILE_UUID); */

/*         if (result == SRV_BT_CM_RESULT_SUCCESS) */
/*         { */
/*             g_srv_bt_cm_cntx.hs_conn_state = SRV_BT_CM_HS_CONNECTING_STATE_HFP_CONNECTING; */
/*         } */
/*     } */
/*     else if (srv_bt_cm_is_service_support(paired_index, SRV_BT_CM_HS_PROFILE_UUID))   */
/*     { */
/*         if (b_show_prgs_scr && g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) */
/*         { */
/*             (*g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)(SCR_BT_CONNECT_LAST_HEADSET, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            NULL, */
/*                                                                            MMI_FALSE, */
/*                                                                            NULL); */
/*         } */

/*         result = srv_bt_cm_connect(&(g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr), SRV_BT_CM_HS_PROFILE_UUID); */

/*         if (result == SRV_BT_CM_RESULT_SUCCESS) */
/*         { */
/*             g_srv_bt_cm_cntx.hs_conn_state = SRV_BT_CM_HS_CONNECTING_STATE_HSP_CONNECTING; */
/*         } */
/*     } */
/*     else if (g_srv_bt_cm_cntx.paired_list[paired_index].service_list_num == 0) */
/*     { */
/*         if (b_show_prgs_scr && g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr) */
/*         { */
/*             (*g_srv_bt_cm_cntx.scr_cb_tbl.mmi_bt_scr_cb_show_progress_scr)(SCR_BT_CONNECT_LAST_HEADSET, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            STR_GLOBAL_CONNECTING, */
/*                                                                            NULL, */
/*                                                                            MMI_FALSE, */
/*                                                                            NULL); */
/*         } */

/*         result = srv_bt_cm_connect(&(g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr), SRV_BT_CM_HF_PROFILE_UUID); */

/*         if (result == SRV_BT_CM_RESULT_SUCCESS) */
/*         { */
/*             g_srv_bt_cm_cntx.hs_conn_state = SRV_BT_CM_HS_CONNECTING_STATE_HSP_CONNECTING; */
/*         } */
/*     } */

/*     return result; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_connect_headset
 * DESCRIPTION
 *  This function is to process connect headset
 * PARAMETERS
 *  dev_addr : bd_addr of headset
 *  conn_cb : connection callback function
 * RETURNS
 *  MMI_BOOL        TRUE : success to connect
 *                  FALSE : otherwise
 *****************************************************************************/
/* MMI_BOOL srv_bt_cm_connect_headset(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_headset_connect_callback conn_cb) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_BOOL result = MMI_FALSE; */
/*     U32 paired_index; */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, */
/*               MMI_BT_G7_SRV_BT_CM_CONNECT_HEADSET, */
/*               g_srv_bt_cm_cntx.state, */
/*               dev_addr->lap, */
/*               dev_addr->uap, */
/*               dev_addr->nap, */
/*               conn_cb); */

/*     if (g_srv_bt_cm_cntx.state != SRV_BT_CM_STATE_IDLE) */
/*     { */
/*         MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_CONNECT_HEADSET_ERR_STATE, g_srv_bt_cm_cntx.state); */
/*         result = MMI_FALSE; */
/*         goto RET; */
/*     } */

/*     for (paired_index = 0; paired_index < g_srv_bt_cm_cntx.paired_dev_num; paired_index++) */
/*     { */
/*         if (g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr.lap == dev_addr->lap && */
/*             g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr.uap == dev_addr->uap && */
/*             g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr.nap == dev_addr->nap) */
/*         { */
/*             break; */
/*         } */
/*     } */

/*     /\* paired_index cannot be equal to g_srv_bt_cm_cntx.paired_dev_num *\/ */
/*     /\* if paired_index=0 and g_srv_bt_cm_cntx.paired_dev_num=0, assert it *\/ */
/*     MMI_BT_ASSERT(paired_index != g_srv_bt_cm_cntx.paired_dev_num); */
/* #ifdef __MMI_HFP_SUPPORT__ */
/*     result = mmi_hfg_attach(dev_addr, (HfgAttachCallback)conn_cb, HFG_OPT_BACKGROUND); */
/* #endif /\* __MMI_HFP_SUPPORT__ *\/ */
    
/* RET: */
/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_CONNECT_HEADSET_RETURN, result); */
    
/*     return result; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_disconnect_headset
 * DESCRIPTION
 *  This function is to process disconnect headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : success to disconnect
 *                  FALSE : otherwise
 *****************************************************************************/
/* MMI_BOOL srv_bt_cm_disconnect_headset(void) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     U32 conn_index; */
/*     U32 paired_index = 0, table_index = 0; */
/*     U32 connection_id = 0; */
/*     srv_bt_cm_connection_type conn_type = SRV_BT_CM_NO_CONNECTION; */
/*     U32 supported_profile_uuid = SRV_BT_CM_MAX_PROFILE_UUID; */
/*     MMI_BOOL result = MMI_FALSE; */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     for (conn_index = 0; conn_index < g_srv_bt_cm_cntx.existed_conn_num; conn_index++) */
/*     { */
/*         if (g_srv_bt_cm_cntx.existed_conn[conn_index].conn_type == SRV_BT_CM_HFP_CONNECTION || */
/*             g_srv_bt_cm_cntx.existed_conn[conn_index].conn_type == SRV_BT_CM_HSP_CONNECTION) */
/*         { */
/*             paired_index = g_srv_bt_cm_cntx.existed_conn[conn_index].index_of_paried_list; */
/*             connection_id = g_srv_bt_cm_cntx.existed_conn[conn_index].conn_id; */
/*             conn_type = g_srv_bt_cm_cntx.existed_conn[conn_index].conn_type; */
/*             break; */
/*         } */
/*     } */
/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_DISCONNECT_HEADSET,conn_index, connection_id,conn_type); */
/*     /\* conn_index cannot be equal to g_srv_bt_cm_cntx.paired_dev_num *\/ */
/*     /\* if conn_index=0 and g_srv_bt_cm_cntx.paired_dev_num=0, assert it *\/ */
/*     if (conn_index == g_srv_bt_cm_cntx.existed_conn_num) */
/*     { */
/*         MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_NO_CONNECTED_HEADSET); */
/*         return FALSE; */
/*     } */
/*     g_srv_bt_cm_cntx.disconnect_con_id = connection_id; */
/*     MMI_TRACE( */
/*         MMI_CONN_TRC_G7_BT, */
/*         MMI_BT_G7_SRV_BT_CM_SET_DISCONNECT_CON_ID, */
/*         g_srv_bt_cm_cntx.disconnect_con_id); */
/*     SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_DISCONNECTING); */
/*     switch (conn_type) */
/*     { */
/*         case SRV_BT_CM_HFP_CONNECTION: */
/*             supported_profile_uuid = SRV_BT_CM_HFG_PROFILE_UUID; */
/*             break; */
/*         case SRV_BT_CM_HSP_CONNECTION: */
/*             supported_profile_uuid = SRV_BT_CM_HEADSET_AG_SERVICE_UUID; */
/*             break; */
/*         default: */
/*             MMI_BT_ASSERT(0); */
/*             break; */
/*     } */
/*     table_index = 0; */
/*     while (support_profile_tbl[table_index].uuid != SRV_BT_CM_MAX_PROFILE_UUID) */
/*     { */
/*         if ((support_profile_tbl[table_index].uuid == supported_profile_uuid)) */
/*         { */
/*             if (support_profile_tbl[table_index].disconnect_func_ptr) */
/*             { */
/*                 (*support_profile_tbl[table_index].disconnect_func_ptr)( */
/*                     g_srv_bt_cm_cntx.paired_list[paired_index].bd_addr, */
/*                     connection_id); */
/*             } */
/*             result = MMI_TRUE; */
/*             break; */
/*         } */
/*         table_index++; */
/*     } */
/*     return result; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_cancel_connect_headset
 * DESCRIPTION
 *  This function is to process cancel connect headset
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL        TRUE : success to cancel connect
 *                  FALSE : otherwise
 *****************************************************************************/
/* MMI_BOOL srv_bt_cm_cancel_connect_headset(void) */
/* { */
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Local Variables                                                *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_BOOL result = MMI_FALSE; */
    
/*     /\*----------------------------------------------------------------*\/ */
/*     /\* Code Body                                                      *\/ */
/*     /\*----------------------------------------------------------------*\/ */
/*     MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_G7_SRV_BT_CM_CONNECT_CANCEL_HEADSET, g_srv_bt_cm_cntx.hs_conn_state); */
/* #ifdef __MMI_HFP_SUPPORT__ */
/*     result = mmi_hfg_abort(); */
/* #endif /\* __MMI_HFP_SUPPORT__ *\/ */
/*     return result; */
/* } */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_active_hfp_connect_id
 * DESCRIPTION
 *  This function is to get current active hfp/hsp connection id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8          active HFP connection id
 *****************************************************************************/
U8 srv_bt_cm_get_active_hfp_connect_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* assume that there is only one active HFP or HSP connection in active connection list */
    U32 i, id = 0xff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
        if ( srv_bt_cm_is_hf_profile_connected(i)&&(g_srv_bt_cm_cntx.existed_conn[i].active))
        {
            id = g_srv_bt_cm_cntx.existed_conn[i].conn_id;
            break;
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_GET_ACTIVE_HFP_CONNECT_ID,
        id);
    return id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_copy_n_utf8_chars
 * DESCRIPTION
 *  to copy n chars to dest string
 * PARAMETERS
 *  dest             [IN]        dest buffer 
 *  size_of_dest     [IN]        max size of dest buffer
 *  src              [IN]        src buffer 
 *  charNum          [IN]        number of char to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_copy_n_utf8_chars(U8* dest, U16 size_of_dest, U8* src, U8 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 char_count = 0;
    U8 char_byte_cnt = 0;
    U8 ucs_char[4];
    U16 byes_copied = 0;
    U16 max_size_of_dest = size_of_dest-2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_BT_ASSERT(dest);
    while (*src && char_count < char_num && byes_copied < max_size_of_dest)
    {
        char_byte_cnt = (U8)mmi_chset_utf8_to_ucs2(ucs_char, src);
        if ((byes_copied+char_byte_cnt) > max_size_of_dest)
        {
            //*dest = 0;
            //*(dest+1) = 0;
            break;
        }

        memcpy(dest, src, char_byte_cnt);
        dest += char_byte_cnt;
        src += char_byte_cnt;
        char_count++;
        byes_copied += char_byte_cnt;
    }

    *dest = 0;
    *(dest+1) = 0;
}

#endif /* __MMI_BT_SUPPORT__ */ 
