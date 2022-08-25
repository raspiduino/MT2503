/****************************************************************************
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
 *    mm_pq_path_mt6260.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file manages MMSYS PQ path control for all MDP and LCD engines.
 *    Currently this file is only used in MT6260 project.
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
 * 01 24 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 02 06 2013 peter.wang
 * removed!
 * .
 *
 * 12 05 2012 peter.wang
 * removed!
 * .
 *
 * 11 02 2012 peter.wang
 * removed!
 * .
 * 

 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

/*****************************************************************************
 * include directives
 *****************************************************************************/
#include "reg_base.h"
#include <kal_release.h>

#include "mmsys_pq_path.h"
/*****************************************************************************
 * HW register definitions and macros
 *****************************************************************************/
#define RESIZER_PATH_SEL                (MMSYS_CONFIG_base)
#define COLOR_PATH_SEL                  (MMSYS_CONFIG_base + 0x04)
#define ROTDMA_PATH_SEL                 (MMSYS_CONFIG_base + 0x08)

#define REG_RESIZER_PATH_SEL            (*((volatile unsigned int*) RESIZER_PATH_SEL))
#define REG_COLOR_PATH_SEL              (*((volatile unsigned int*) COLOR_PATH_SEL))
#define REG_ROTDMA_PATH_SEL             (*((volatile unsigned int*) ROTDMA_PATH_SEL))

#define RESIZER_OUT_SEL_BIT             (0x01)
#define COLOR_IN_SEL_BIT                (0x10)
#define COLOR_OUT_SEL_BIT               (0x01)
#define ROTDMA_IN_SEL_BIT               (0x10)

/*****************************************************************************
 * global variables
 *****************************************************************************/

static kal_uint32 _pq_path = 0;

/*****************************************************************************
 * external function definitions
 *****************************************************************************/
void mm_color_set_path(mm_pq_module_enum_t input, mm_pq_module_enum_t output)
{
    switch (input)
    {
        case MM_PQ_MODULE_LCD: //default path
            REG_COLOR_PATH_SEL |= COLOR_IN_SEL_BIT;
            break;

        case MM_PQ_MODULE_RESIZER: 
            REG_COLOR_PATH_SEL &= ~COLOR_IN_SEL_BIT;
            break;

        default:
            ASSERT(0);
            break;
    }

    switch (output)
    {
        case MM_PQ_MODULE_LCD: //default path
            REG_COLOR_PATH_SEL |= COLOR_OUT_SEL_BIT;
            break;

        case MM_PQ_MODULE_ROTDMA:
            REG_COLOR_PATH_SEL &= ~COLOR_OUT_SEL_BIT;
            break;

        default:
            ASSERT(0);
            break;
    }
}

void mm_resizer_set_path(mm_pq_module_enum_t output)
{
    switch (output)
    {
        case MM_PQ_MODULE_ROTDMA: //default path
            REG_RESIZER_PATH_SEL &= ~RESIZER_OUT_SEL_BIT;
            break;

        case MM_PQ_MODULE_COLOR:
            REG_RESIZER_PATH_SEL |= RESIZER_OUT_SEL_BIT;
            break;

        default:
            ASSERT(0);
            break;
    }
}

void mm_rotdma_set_path(mm_pq_module_enum_t input)
{
    switch (input)
    {
        case MM_PQ_MODULE_RESIZER: //default path
            REG_ROTDMA_PATH_SEL &= ~ROTDMA_IN_SEL_BIT;
            break;

        case MM_PQ_MODULE_COLOR:
            REG_ROTDMA_PATH_SEL |= ROTDMA_IN_SEL_BIT;
            break;

        default:
            ASSERT(0);
            break;
    }
}

void mm_color_for_mdp(void)
{
    mm_resizer_set_path(MM_PQ_MODULE_COLOR);
    mm_color_set_path(MM_PQ_MODULE_RESIZER, MM_PQ_MODULE_ROTDMA);
    mm_rotdma_set_path(MM_PQ_MODULE_COLOR);

    _pq_path = 1;
}

void mm_color_for_lcd(void)
{
    mm_resizer_set_path(MM_PQ_MODULE_ROTDMA);
    mm_color_set_path(MM_PQ_MODULE_LCD, MM_PQ_MODULE_LCD);
    mm_rotdma_set_path(MM_PQ_MODULE_RESIZER);

    _pq_path = 0;
}

#endif //#if defined(MT6260)


