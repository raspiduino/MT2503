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
 * SWTR_TEST_DATA.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is used by software tracer for test on MoDIS.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SWTR_TEST_DATA_H
#define  SWTR_TEST_DATA_H

#include "SoftwareTracerProt.h"

/* functions in this file is for testinf in modis mode */

mmi_swtr_task_struct g_mmi_swtr_task_log[MMI_SWTR_MAX_LOG_ITEM_NUMBER];


/*****************************************************************************
 * FUNCTION
 *  mmi_swtr_test_data_fill
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swtr_test_data_fill(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_uint32 t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&t);
    srand(t);

    for (i = 0; i < MMI_SWTR_MAX_LOG_ITEM_NUMBER; i++)
    {
        /* sprintf(g_mmi_swtr_task_log[i].name,"IDLE"); */
        sprintf(g_mmi_swtr_task_log[i].name, "T_%02d", (rand() % 20));
        g_mmi_swtr_task_log[i].running_time = (rand() % 30) + 5;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_software_tracer_analyzing_mode_parsing_on_modis_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_software_tracer_analyzing_mode_parsing_on_modis_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_swtr_task_number = 0;
    g_mmi_swtr_log_item_number = MMI_SWTR_MAX_LOG_ITEM_NUMBER;
    g_mmi_swtr_total_running_time = 0;
    g_mmi_swtr_max_running_time = 0;
    for (i = 0; i < MMI_SWTR_MAX_LOG_ITEM_NUMBER; i++)
    {
        int flag = 0;

        g_mmi_swtr_total_running_time = g_mmi_swtr_total_running_time + g_mmi_swtr_task_log[i].running_time;

        for (j = 0; j < g_mmi_swtr_task_number; j++)
        {
            if (!strcmp(g_mmi_swtr_task_log[i].name, g_mmi_swtr_task_list[j].name))
            {
                flag = 1;
                g_mmi_swtr_task_list[j].running_time += g_mmi_swtr_task_log[i].running_time;

                if (g_mmi_swtr_task_list[j].running_time > g_mmi_swtr_max_running_time)
                {
                    g_mmi_swtr_max_running_time = g_mmi_swtr_task_list[j].running_time;
                }
                break;
            }
        }

        if (flag == 0)
        {
            strcpy(g_mmi_swtr_task_list[g_mmi_swtr_task_number].name, g_mmi_swtr_task_log[i].name);
            g_mmi_swtr_task_list[g_mmi_swtr_task_number].running_time = g_mmi_swtr_task_log[i].running_time;
            g_mmi_swtr_task_number++;
        }
    }

}

#endif /* SWTR_TEST_DATA_H */ 

