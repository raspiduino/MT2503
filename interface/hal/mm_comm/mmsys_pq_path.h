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
 *    mmsys_pq_path.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Header file for mmsys pq path
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MM_PQ_PATH_H__
#define __MM_PQ_PATH_H__

typedef enum
{
    MM_PQ_MODULE_LCD,
    MM_PQ_MODULE_RESIZER,
    MM_PQ_MODULE_ROTDMA,
    MM_PQ_MODULE_COLOR,
} mm_pq_module_enum_t;


/******************************************************************************
 * API functions
 *****************************************************************************/
/**
 * Set MM COLOR module input and output path. 
 * 
 * @param input The COLOR input module, form LCD(default) or RESIZER
 * @param output The COLOR output module, to LCD(default) or ROTDMA
 */
extern void mm_color_set_path(mm_pq_module_enum_t input, mm_pq_module_enum_t output);

/**
 * Set MM RESIZER module output path. 
 * 
 * @param output The RESIZER output module, to ROTDMA(default) or COLOR
 */
extern void mm_resizer_set_path(mm_pq_module_enum_t output);

/**
 * Set MM ROTDMA module input path. 
 * 
 * @param input The ROTDMA input module, form RESIZER(default) or COLOR
 */
extern void mm_rotdma_set_path(mm_pq_module_enum_t input);


/**
 * Set MM COLOR module for MDP use. 
 * 
 * @param none
 */
extern void mm_color_for_mdp(void);

/**
 * Set MM COLOR module for LCD use. 
 * 
 * @param none
 */
extern void mm_color_for_lcd(void);

#endif  /* __MM_PQ_PATH_H__ */

