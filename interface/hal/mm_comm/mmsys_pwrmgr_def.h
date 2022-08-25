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
 *    mmsys_pwrmgr_def.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Header file for mm_power_ctrl
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

 
#if defined(MT6268A) || defined(MT6516) || defined(MT6268)
#include "mm_pwrmgr_def_mt6268.h"
#endif  /* MT6268 */

#if defined(MT6270A) 
#include "mm_pwrmgr_def_mt6270A.h"
#endif  /* MT6270A */

#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#include"mm_pwrmgr_def_mt6250.h"
#endif

#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#include"mm_pwrmgr_def_mt6253.h"
#endif

#if defined(MT6235) || defined(MT6235B)
#include"mm_pwrmgr_def_mt6235.h"
#endif

#if defined(MT6236) || defined(MT6236B)
#include "mm_pwrmgr_def_mt6236.h"
#endif  /* MT6236 */

#if defined(MT6276)
#include "mm_pwrmgr_def_mt6276.h"
#endif  /* MT6276 */

#if defined(MT6255)
#include "mm_pwrmgr_def_mt6255.h"
#endif  /* MT6255 */

#if defined(MT6256)
#if defined(MT6256_S00)
#include "mm_pwrmgr_def_mt6256_e1.h"
#else
#include "mm_pwrmgr_def_mt6256_e2.h"
#endif  /* MT6256_S00 */
#endif /* MT6256 */

