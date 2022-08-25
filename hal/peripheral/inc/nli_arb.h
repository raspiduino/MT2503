/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * nli_arb.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to define NLI Arbiter reigter and operation macro for MT6276, MT6256 and etc.. 
 *
 * Author:
 * -------
 *
 *  Bin Han (mtk80391)
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 22 2012 haitao.shang
 * removed!
 * .
 *
 * 01 13 2012 haitao.shang
 * removed!
 * .
 *
 * 07 19 2011 bin.han
 * removed!
 * .
 *
 *
 *******************************************************************************/
#ifndef __NLI_ARB_H__
#define __NLI_ARB_H__

#include "reg_base.h"
#include "nld_central_ctrl.h"


//////////////////////////  Reigster Operation Macro Define  ////////////////////////////
#ifdef NLI_ARB_base

#define REG_NLI_ARB_STATUS              *((volatile unsigned int *)(NLI_ARB_base+0x000))
#define REG_NLI_ARB_SWRST               *((volatile unsigned int *)(NLI_ARB_base+0x010))
#define REG_NLI_ARB_CS                  *((volatile unsigned int *)(NLI_ARB_base+0x014))
#define REG_NLI_ARB_CONT_GRANT           *((volatile unsigned int *)(NLI_ARB_base+0x018))
#define REG_NLI_ARB_HANDOVER           *((volatile unsigned int *)(NLI_ARB_base+0x01C))
#define REG_NLI_ARB_MON_SRC           *((volatile unsigned int *)(NLI_ARB_base+0x040))
#define REG_NLI_ARB_MON_CLR           *((volatile unsigned int *)(NLI_ARB_base+0x044))
#define REG_NLI_ARB_MON_START           *((volatile unsigned int *)(NLI_ARB_base+0x048))
#define REG_NLI_ARB_MON_RD           *((volatile unsigned int *)(NLI_ARB_base+0x050))
#define REG_NLI_ARB_MON_WR           *((volatile unsigned int *)(NLI_ARB_base+0x054))
#define REG_NLI_ARB_MON_CYC           *((volatile unsigned int *)(NLI_ARB_base+0x058))


#define NLI_ARB_CS_FAVOR_NORMAL_BIT    (0x10000)
#define NLI_ARB_CS_FAVOR_ULTRA_BIT     (0x20000)
#define NLI_ARB_HANDOVER_ENTER_LCD_BIT    (0x00001)
#define NLI_ARB_HANDOVER_ENTER_NF_BIT    (0x00002)
#define NLI_ARB_HANDOVER_ENTER_HIF0_BIT    (0x00004)
#define NLI_ARB_HANDOVER_ENTER_HIF1_BIT    (0x00008)
#define NLI_ARB_HANDOVER_LEAVE_LCD_BIT    (0x000010)
#define NLI_ARB_HANDOVER_LEAVE_NF_BIT    (0x000020)
#define NLI_ARB_HANDOVER_LEAVE_HIF0_BIT    (0x000040)
#define NLI_ARB_HANDOVER_LEAVE_HIF1_BIT    (0x000080)
#define NLI_ARB_HANDOVER_MASK    (0x000F00)
#define ENABLE_NLI_ARB_FAVOR_NORMAL()  REG_NLI_ARB_CS |= NLI_ARB_CS_FAVOR_NORMAL_BIT;
#define DISABLE_NLI_ARB_FAVOR_NORMAL() REG_NLI_ARB_CS &= (~NLI_ARB_CS_FAVOR_NORMAL_BIT);
#define ENABLE_NLI_ARB_FAVOR_ULTRA()   REG_NLI_ARB_CS |= NLI_ARB_CS_FAVOR_ULTRA_BIT;
#define DISABLE_NLI_ARB_FAVOR_ULTRA()  REG_NLI_ARB_CS &= (~NLI_ARB_CS_FAVOR_ULTRA_BIT);
#define GET_NLI_ARB_FAVOR_NORMAL_ENABLE()  (REG_NLI_ARB_CS & NLI_ARB_CS_FAVOR_NORMAL_BIT)
#define GET_NLI_ARB_FAVOR_ULTRA_ENABLE()  (REG_NLI_ARB_CS & NLI_ARB_CS_FAVOR_ULTRA_BIT)
//added for handover cycle 
#define ENABLE_NLI_ARB_HANDOVER_LCD_ENTER()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_ENTER_LCD_BIT;
#define DISABLE_NLI_ARB_HANDOVER_LCD_ENTER() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_ENTER_LCD_BIT);
#define ENABLE_NLI_ARB_HANDOVER_NF_ENTER()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_ENTER_NF_BIT;
#define DISABLE_NLI_ARB_HANDOVER_NF_ENTER() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_ENTER_NF_BIT);
#define ENABLE_NLI_ARB_HANDOVER_HIF0_ENTER()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_ENTER_HIF0_BIT;
#define DISABLE_NLI_ARB_HANDOVER_HIF0_ENTER() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_ENTER_HIF0_BIT);
#define ENABLE_NLI_ARB_HANDOVER_HIF1_ENTER()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_ENTER_HIF1_BIT;
#define DISABLE_NLI_ARB_HANDOVER_HIF1_ENTER() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_ENTER_HIF1_BIT);

#define ENABLE_NLI_ARB_HANDOVER_LCD_LEAVE()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_LEAVE_LCD_BIT;
#define DISABLE_NLI_ARB_HANDOVER_LCD_LEAVE() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_LEAVE_LCD_BIT);
#define ENABLE_NLI_ARB_HANDOVER_NF_LEAVE()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_LEAVE_NF_BIT;
#define DISABLE_NLI_ARB_HANDOVER_NF_LEAVE() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_LEAVE_NF_BIT);
#define ENABLE_NLI_ARB_HANDOVER_HIF0_LEAVE()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_LEAVE_HIF0_BIT;
#define DISABLE_NLI_ARB_HANDOVER_HIF0_LEAVE() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_LEAVE_HIF0_BIT);
#define ENABLE_NLI_ARB_HANDOVER_HIF1_LEAVE()  REG_NLI_ARB_HANDOVER |= NLI_ARB_HANDOVER_LEAVE_HIF1_BIT;
#define DISABLE_NLI_ARB_HANDOVER_HIF1_LEAVE() REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_LEAVE_HIF1_BIT);

#define SET_NLI_ARB_HANDOVER_CYCLE(data) REG_NLI_ARB_HANDOVER &= (~NLI_ARB_HANDOVER_MASK);\
		                                     REG_NLI_ARB_HANDOVER |= ((data&0xF)<<8);


#define SET_NLI_ARB_CS_SOURCE_SELECTION(src,dest)  do{REG_NLI_ARB_CS &=  ~(0x7<<(dest)); REG_NLI_ARB_CS |= ((src)<<(dest));} while(0)
#define GET_NLI_ARB_CS_SOURCE_SELECTION(dest)  ((REG_NLI_ARB_CS >> (dest)) & 0x7)
#else

// Dummy MACRO to avoid build error
#define ENABLE_NLI_ARB_FAVOR_NORMAL() 
#define DISABLE_NLI_ARB_FAVOR_NORMAL() 
#define ENABLE_NLI_ARB_FAVOR_ULTRA()  
#define DISABLE_NLI_ARB_FAVOR_ULTRA() 

#define SET_NLI_ARB_CS_SOURCE_SELECTION_LPCE0B(x)  
#define SET_NLI_ARB_CS_SOURCE_SELECTION_LPCE1B(x) 
#define SET_NLI_ARB_CS_SOURCE_SELECTION_LPCE2B(x)
#define SET_NLI_ARB_CS_SOURCE_SELECTION_LPCE3B(x) 

#endif  //NLI_ARB_base


//////////////////////////  User Interface   ////////////////////////////
typedef enum
{
    NLI_ARB_USER_LCD = 0,
    NLI_ARB_USER_NAND,
    NLI_ARB_USER_HIF0,
    NLI_ARB_USER_HIF1,

    NLI_ARB_USER_NUM
}NLI_ARB_USER_ENUM;

///Notice: the following enum define is chip depedent
typedef enum
{
    NLI_ARB_CS_SOURCE_LCD0 = 0,
    NLI_ARB_CS_SOURCE_LCD1 = 1,
    NLI_ARB_CS_SOURCE_LCD2 = 2,
    NLI_ARB_CS_SOURCE_HIF0 = 3,
    NLI_ARB_CS_SOURCE_HIF1 = 4,

    NLI_ARB_CS_SOURCE_NUMBER
}NLI_ARB_CS_SOURCE_ENUM;


///Notice: the following enum define is chip depedent
typedef enum
{
    NLI_ARB_CS_DEST_LPCE0B = 0,
    NLI_ARB_CS_DEST_LPCE1B = 1,
    NLI_ARB_CS_DEST_LPCE2B = 2,
    NLI_ARB_CS_DEST_LPCE3B = 3,

    NLI_ARB_CS_DEST_NUMBER
}NLI_ARB_CS_DEST_ENUM;

//defined in nld_central_ctrl.h if defined __NLD_CENTRAL_CTRL__
#if !defined(__NLD_CENTRAL_CTRL__) 
typedef enum
{
    NLI_ARB_HANDOVER_ENTER_LCD_EN  = 0x01,
    NLI_ARB_HANDOVER_ENTER_NF_EN   = 0x02,
    NLI_ARB_HANDOVER_ENTER_HIF0_EN = 0x04,
    NLI_ARB_HANDOVER_ENTER_HIF1_EN = 0x08,
    NLI_ARB_HANDOVER_LEAVE_LCD_EN  = 0x10,
    NLI_ARB_HANDOVER_LEAVE_NF_EN   = 0x20,
    NLI_ARB_HANDOVER_LEAVE_HIF0_EN = 0x40,
    NLI_ARB_HANDOVER_LEAVE_HIF1_EN = 0x80,

    NLI_ARB_HANDOVER_NUMBER
}NLI_ARB_HANDOVER_ENUM;
#endif
typedef enum
{
    // Set operation
    NLI_ARB_SET_FAVOR_NORMAL = 0,
    NLI_ARB_SET_FAVOR_ULTRA,
    NLI_ARB_SET_CS_MAPPING,
    NLI_ARB_SET_HANDOVER_COUNT,
    
    // Query operation
    NLI_ARB_QUERY_FAVOR_NORMAL,
    NLI_ARB_QUERY_FAVOR_ULTRA,
    NLI_ARB_QUERY_CS_MAPPING,
    NLI_ARB_QUERY_HANDOVER_COUNT,//[2011.1.13]this function not support now

    NLI_ARB_CONTROL_CODE_NUM
}NLI_ARB_CONTROL_CODE_ENUM;


typedef struct
{
    kal_bool enable;
}NLI_ARB_SET_QUERY_FAVOR_STRUCT;


typedef struct
{
    NLI_ARB_CS_SOURCE_ENUM cs_source;   /// LCD0, LCD1, LCD2, HIF0, HIF1
    NLI_ARB_CS_DEST_ENUM   cs_dest;     /// LPCE0B,LPCE1B, LPCE2B, LPCE3B
}NLI_ARB_SET_QUERY_CS_MAPPING_STRUCT;

#if !defined(__NLD_CENTRAL_CTRL__)   
typedef struct
{
    NLI_ARB_HANDOVER_ENUM handover_en;   /// LCD, NF, HIF0, HIF1
    kal_bool enable;									///enable or disable
    kal_uint32   handover_cycle;     /// cycle
}NLI_ARB_SET_QUERY_HANDOVER_COUNT_STRUCT;
#endif

//The drv init function
void NLI_ARB_init(void);
//The drv IO control function , return KAL_FALSE means set or query is fail
kal_bool NLI_ARB_IOCtrl(NLI_ARB_USER_ENUM user, NLI_ARB_CONTROL_CODE_ENUM ctrlCode, void *ctrlStruct);
#if defined(__NLD_CENTRAL_CTRL__) 
//The handover setting function for NLD central control mechanism only
void NLI_ARB_Set_Handover_Cycle(kal_uint32 handoverType,kal_uint32 handoverCycle);
#endif
#endif  // __NLI_ARB_H__
