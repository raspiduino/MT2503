/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 * Filename:
 * ---------
 * ps_em_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for engineer mode.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 23 2012 xi.li
 * removed!
 * .
 *
 * 02 23 2012 lexel.yu
 * removed!
 * Integration change. 
 *
 * 02 14 2012 chenhao.gong
 * removed!
 * .
 *
 * 11 18 2011 chenhao.gong
 * removed!
 * .
 *
 * 11 09 2011 chenhao.gong
 * removed!
 * .
 *
 * 10 28 2011 lexel.yu
 * removed!
 * Integration change.
 *
 * 09 27 2011 lexel.yu
 * removed!
 * Integration change.  
 *
 * 06 10 2011 lexel.yu
 * removed!
 * Integration change. 
 *
 * 05 11 2011 xi.li
 * removed!
 * .
 *
 * 04 20 2011 xuechao.wang
 * removed!
 * .
 *
 * 03 09 2011 popcafa.shih
 * removed!
 * .
 *
 * 03 04 2011 xi.li
 * removed!
 * .
 *
 * 03 01 2011 junzhen.qin
 * removed!
 * .
 *
 * 02 24 2011 yongjiao.yu
 * removed!
 * .
 *
 * 02 17 2011 yongjiao.yu
 * removed!
 * FDD2TDD code sync stage 3, CTA menu, steady_inactive_ind.
 *
 * 12 08 2010 yc.chen
 * removed!
 * .
 *
 * 11 24 2010 zhiwei.wang
 * removed!
 * Patch NVRAM parts for EM menu.
 *
 * 11 23 2010 chenhao.gong
 * removed!
 * L4 Add PS conformance test EM menu support & AT command Support
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PS_EM_ENUM_H__
#define __PS_EM_ENUM_H__

/* Constants defined for PS conformance test mode special profile*/


typedef enum
{
	PS_CONF_TEST_NONE,
	PS_CONF_TEST_CTA,
	PS_CONF_TEST_FTA,
	PS_CONF_TEST_IOT,
	PS_CONF_TEST_OPERATOR,
	PS_CONF_TEST_FACTORY,
	/* Add new test mode here! */
	PS_CONF_TEST_END
} ps_conf_test_mode_enum;

/***************
 * Define bit mask for MMI and PS, each special setting occupy 1 bit.  $$$ 1 bit, please
 * Please try to use the format like this:
 * (MODE)_(MENUNAME)_BIT_FOR_(MODULE)
 * eg. CTA_INTEGRITY_CHECK_BIT_FOR_MM
 *     FTA_ABC_FOR_XYZ or FTA_AB_C_FOR_XYZ_MNQ
 *************** */

/* General bits, and these bits CAN NOT taken by others whatever mode it's (CTA/FTA/IOT) 
   Please avoid to add any more bits here! */
#define GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD 0x00800000

/* CTA Items */
#define CTA_INTEGRITY_CHECK_BIT_FOR_MM          0x00000001
//#define CTA_RLC_BIT_FOR_RLC                     0x00000002
#define CTA_TL1_BIT_FOR_TL1                     0x00000002
#define CTA_K1297_BIT_FOR_RRCE                  0x00000004
#define CTA_SNCONFLICT_BIT_FOR_RLC_RRCE         0x00000008
#define CTA_CFQUERY_BIT_FOR_SS                  0x00000010
#define CTA_PLMN_LOCK_BIT_FOR_CSCE              0x00000020
#define CTA_OPEN_MEAS_BIT_FOR_CSCE              0x00000040
#define CTA_DISABLE_DPA_BIT_FOR_RRCE            0x00000080 /*this will disable UPA as well for R7*/
#define CTA_OPEN_INVALID_INTRA_CELL_REPORT__BIT_FOR_MEME     0x00000100
#define CTA_AUTO_ADJUST_BIT_FOR_RRCE            0x00000200
#define CTA_DISABLE_UPA_BIT_FOR_RRCE            0x00000400
#define CTA_RELEASE_ADAPTION_BIT_FOR_RRCE       0x00000800
/* Add new definition here! */

/* FTA Items */
#define FTA_MODEM_AUTO_BOOT_AND_AUTO_ANSWER_BIT_FOR_L4C     0x00000800
/* Add new definition here! */

/* IOT items */
/* Add new definition here! */

/* Operator Test Items */
#define OPERATOR_TEST_MS_USIM_COMPATIBLE        0x00000001
/* Add new definition here! */

/* Factory Items */
/* Add new definition here! */
#define FACTORY_MODEM_VIRTUAL_SIM_ON_BIT_FOR_L4C     0x00000001


/* -----------For NW EVENT start--------------------- */
#define MAX_LEN_OF_NW_EVENT_NAME 20  
#define MAX_LEN_OF_NW_GROUP_NAME 5
#define EM_NW_NUM_OF_QUEUE_EVENT 32  

typedef enum
{
/* John Tang 2006/11/13 */
#ifdef __UMTS_RAT__
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
#endif /* __UMTS_RAT__ */

    EM_NW_EVENT_ID_TEST0,     /* 0 */
    EM_NW_EVENT_ID_TEST1,
    EM_NW_EVENT_ID_TEST2,
    EM_NW_EVENT_ID_TEST3,
    EM_NW_EVENT_ID_TEST4,
    EM_NW_EVENT_ID_TEST5,
    EM_NW_EVENT_ID_TEST6,     /* 5 */
    EM_NW_EVENT_ID_TEST7,
    EM_NW_EVENT_ID_TEST8,
    EM_NW_EVENT_ID_TEST9,
    EM_NW_EVENT_ID_TEST10,
    EM_NW_EVENT_ID_TEST11,    /* 10 */
    EM_NW_EVENT_ID_TEST12,
    EM_NW_EVENT_ID_TEST13,
    EM_NW_EVENT_ID_TEST14,
    EM_NW_EVENT_ID_TEST15,
    EM_NW_EVENT_ID_TEST16,    /* 15 */
    EM_NW_EVENT_ID_TEST17,
    EM_NW_EVENT_ID_TEST18,
    EM_NW_EVENT_ID_TEST19,
    EM_NW_EVENT_ID_TEST20,
    EM_NW_EVENT_ID_TEST21,    /* 20 */
    EM_NW_EVENT_ID_TEST22,
    EM_NW_EVENT_ID_TEST23,
    EM_NW_EVENT_ID_TEST24,
    EM_NW_EVENT_ID_TEST25,
    EM_NW_EVENT_ID_TEST26,    /* 25 */
    EM_NW_EVENT_ID_TEST27,
    EM_NW_EVENT_ID_TEST28,
    EM_NW_EVENT_ID_TEST29,
    EM_NW_EVENT_ID_TEST30,
    EM_NW_EVENT_ID_TEST31,    /* 30 */
    EM_NW_EVENT_ID_TEST32,
    EM_NW_EVENT_ID_TEST33,
    EM_NW_EVENT_ID_TEST34,
    EM_NW_EVENT_ID_TEST35,
    EM_NW_EVENT_ID_TEST36,    /* 35 */
    EM_NW_EVENT_ID_TEST37,
    
    /* RAC Event start */
    EM_NW_EVENT_ID_CELL_POWER_LEVEL_IND,
    EM_NW_EVENT_ID_GMMREG_ATTACH_CNF,

    /* RAC Event End */
    
    EM_NW_EVENT_ID_MAX
    
} EM_NW_EVENT_ID_ENUM;

typedef enum
{
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __UMTS_RAT__ */
    EM_NW_EVENT_GROUP_RAC,
    /* don't remove this item and add new item before it */
    EM_NW_MAX_NO_OF_GROUP
} EM_NW_EVENT_GROUP_ENUM;
/* -----------For NW EVENT end------------------------- */


#endif  /* __PS_EM_ENUM_H__ */

