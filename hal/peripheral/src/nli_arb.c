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
 * nli_arb.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is to implement NLI Arbiter driver for MT6276, MT6256 and etc.. 
 *
 * Author:
 * -------
 *
 *  Bin Han (mtk80391)
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 10 28 2013 chrono.wu
 * removed!
 * .
 *
 * 05 22 2012 haitao.shang
 * removed!
 * .
 *
 * 01 13 2012 haitao.shang
 * removed!
 * .
 *
 * 08 18 2011 bin.han
 * removed!
 * .
 *
 * 08 18 2011 bin.han
 * removed!
 * .
 *
 * 07 19 2011 bin.han
 * removed!
 * .
 *
 *
 *******************************************************************************/
#include "kal_release.h"
#include "reg_base.h"
#include "nli_arb.h"

#if defined(__MTK_TARGET__) && defined(NLI_ARB_base)

extern kal_uint32 SaveAndSetIRQMask( void );
extern void   RestoreIRQMask( kal_uint32 );

void NLI_ARB_init()
{
    static kal_bool nli_arb_init_done_flag = KAL_FALSE;

    if(nli_arb_init_done_flag == KAL_FALSE)
    {
        ///TODO: do init activity here
        nli_arb_init_done_flag = KAL_TRUE;
    }
}

/*
	This function for nli arbiter handover cycle setting.
	This API for central control,be called in NLDShareBusCenCtrl().
*/
#if defined(__NLD_CENTRAL_CTRL__) 
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void NLI_ARB_Set_Handover_Cycle(kal_uint32 handoverType,kal_uint32 handoverCycle)
{
	kal_uint32 temp;
	REG_NLI_ARB_HANDOVER &=(~0xFF);
	temp = handoverType&0xFF;
	REG_NLI_ARB_HANDOVER |= temp;
	SET_NLI_ARB_HANDOVER_CYCLE(handoverCycle);
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif
#endif
kal_bool NLI_ARB_IOCtrl(NLI_ARB_USER_ENUM user, NLI_ARB_CONTROL_CODE_ENUM ctrlCode, void *ctrlStruct)
{
    kal_bool result;
    kal_uint32 mask;

    if(user >= NLI_ARB_USER_NUM ||
       ctrlCode >= NLI_ARB_CONTROL_CODE_NUM ||
       ctrlStruct == NULL)
    {
        return KAL_FALSE;
    }

    ///TODO: debugging logging maybe necessary

    result = KAL_TRUE;
    mask = SaveAndSetIRQMask();
    switch(ctrlCode)
    {
        // Set operation
        case NLI_ARB_SET_FAVOR_NORMAL:
            {
                NLI_ARB_SET_QUERY_FAVOR_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_FAVOR_STRUCT *)ctrlStruct;

                if(pCtrlPara->enable)
                {
                    ENABLE_NLI_ARB_FAVOR_NORMAL();
                }
                else
                {
                    DISABLE_NLI_ARB_FAVOR_NORMAL();
                }
            }
            break;
        case NLI_ARB_SET_FAVOR_ULTRA:
            {
                NLI_ARB_SET_QUERY_FAVOR_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_FAVOR_STRUCT *)ctrlStruct;
        
                if(pCtrlPara->enable)
                {
                    ENABLE_NLI_ARB_FAVOR_ULTRA();
                }
                else
                {
                    DISABLE_NLI_ARB_FAVOR_ULTRA();
                }
            }
            break;
        case NLI_ARB_SET_CS_MAPPING:
            {
                NLI_ARB_SET_QUERY_CS_MAPPING_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_CS_MAPPING_STRUCT *)ctrlStruct;

                if(pCtrlPara->cs_source >= NLI_ARB_CS_SOURCE_NUMBER ||
                    pCtrlPara->cs_dest >= NLI_ARB_CS_DEST_NUMBER)
                {
                    result = KAL_FALSE;
                }
                else
                {
                    SET_NLI_ARB_CS_SOURCE_SELECTION(pCtrlPara->cs_source, pCtrlPara->cs_dest);
                }
            }
            break;
        #if !defined(__NLD_CENTRAL_CTRL__) 
        case NLI_ARB_SET_HANDOVER_COUNT:
            {
                NLI_ARB_SET_QUERY_HANDOVER_COUNT_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_HANDOVER_COUNT_STRUCT *)ctrlStruct;

                switch(pCtrlPara->handover_en)
                {
                	case NLI_ARB_HANDOVER_ENTER_LCD_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_LCD_ENTER();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_LCD_ENTER();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_ENTER_NF_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_NF_ENTER();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_NF_ENTER();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_ENTER_HIF0_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_HIF0_ENTER();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_HIF0_ENTER();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_ENTER_HIF1_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_HIF1_ENTER();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_HIF1_ENTER();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_LEAVE_LCD_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_LCD_LEAVE();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_LCD_LEAVE();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_LEAVE_NF_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_NF_LEAVE();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_NF_LEAVE();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_LEAVE_HIF0_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_HIF0_LEAVE();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_HIF0_LEAVE();
                			}
                		}
                		break;
                	case NLI_ARB_HANDOVER_LEAVE_HIF1_EN:
                		{
                			if(pCtrlPara->enable)
                			{
                				ENABLE_NLI_ARB_HANDOVER_HIF1_LEAVE();
                				SET_NLI_ARB_HANDOVER_CYCLE(pCtrlPara->handover_cycle);
                			}
                			else
                			{
                				DISABLE_NLI_ARB_HANDOVER_HIF1_LEAVE();
                			}
                		}
                		break;
                	default:
                		result = KAL_FALSE;
                		break;              		
              	}
            }
            break;
				#endif
        // Query operation
        case NLI_ARB_QUERY_FAVOR_NORMAL:
            {
                NLI_ARB_SET_QUERY_FAVOR_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_FAVOR_STRUCT *)ctrlStruct;

                if(GET_NLI_ARB_FAVOR_NORMAL_ENABLE() != 0)
                {
                    pCtrlPara->enable = KAL_TRUE;
                }
                else
                {
                    pCtrlPara->enable = KAL_FALSE;
                }
            }
            break;

        case NLI_ARB_QUERY_FAVOR_ULTRA:
            {
                NLI_ARB_SET_QUERY_FAVOR_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_FAVOR_STRUCT *)ctrlStruct;

                if(GET_NLI_ARB_FAVOR_ULTRA_ENABLE() != 0)
                {
                    pCtrlPara->enable = KAL_TRUE;
                }
                else
                {
                    pCtrlPara->enable = KAL_FALSE;
                }
            }
            break;

        case NLI_ARB_QUERY_CS_MAPPING:
            {
                ///TODO: since the mapping relationship is determined in HW layout phase, do we really need this ?
                NLI_ARB_SET_QUERY_CS_MAPPING_STRUCT *pCtrlPara = (NLI_ARB_SET_QUERY_CS_MAPPING_STRUCT *)ctrlStruct;

                if(pCtrlPara->cs_dest >= NLI_ARB_CS_DEST_NUMBER)
                {
                    result = KAL_FALSE;
                }
                else
                {
                    pCtrlPara->cs_source = (NLI_ARB_CS_SOURCE_ENUM)GET_NLI_ARB_CS_SOURCE_SELECTION(pCtrlPara->cs_dest);
                }
            }
            break;


        default:
            result = KAL_FALSE;
            break;
    }
    RestoreIRQMask(mask);

    return result;
}

#else

void NLI_ARB_init()
{
}
#if defined(__NLD_CENTRAL_CTRL__)   
void NLI_ARB_Set_Handover_Cycle(kal_uint32 handoverType,kal_uint32 handoverCycle)
{
	
}
#endif
kal_bool NLI_ARB_IOCtrl(NLI_ARB_USER_ENUM user, NLI_ARB_CONTROL_CODE_ENUM ctrlCode, void *ctrlStruct)
{
    return KAL_FALSE;
}


#endif  // defined(__MTK_TARGET__) && defined(NLI_ARB_base)


