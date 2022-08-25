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
 *   cache_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of L1 and L2 cache.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CACHE_HW_H
#define _CACHE_HW_H

#if ( defined(MT6228) || defined(MT6229) || defined(MT6230))

/* L1 Cache and MPU */
#define L1CACHE_BASE    (0x80700000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x80701000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))

/* L2 Cache */
#define L2CACHE_BASE    (0x80050000)
#define L2C_CON         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0000))
#define L2_TARGET       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0004))
#define L2C_STA         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0008))
#define L2C_TAG         ((volatile kal_uint32 *)(L2CACHE_BASE+0x000C))
#define L2C_DATA        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0010))

#elif defined(MT6225)

#define L1CACHE_BASE    (0x80700000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x80701000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))

#elif (defined(MT6253T) || defined(MT6253) || defined(MT6251))

#define L1CACHE_BASE    (0x85000000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x850F0000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10       ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11       ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12       ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13       ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15       ((volatile kal_uint32 *)(MPU_BASE+0x003C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_CACHE10      ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_CACHE11      ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_CACHE12      ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_CACHE13      ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_CACHE14      ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_CACHE15      ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)

#define L1CACHE_BASE    (0x85000000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#if !defined(MT6253E_S00) && !defined(MT6253L_S00)
#define MPU_CHANNEL_EN  ((volatile kal_uint32 *)(L1CACHE_BASE+0x002C))
#endif /* !defined(MT6253E_S00) && !defined(MT6253L_S00) */

#define MPU_BASE        (0x850F0000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))
#define MPU_PROT16      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_PROT17      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_PROT18      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_PROT19      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_PROT20      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_PROT21      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_PROT22      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_PROT23      ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_PROT24      ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_PROT25      ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_PROT26      ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_PROT27      ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_PROT28      ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_PROT29      ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_PROT30      ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_PROT31      ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_CACHE10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_CACHE11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_CACHE12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_CACHE13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_CACHE14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_CACHE15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))
#define MPU_CACHE16      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE17      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE18      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE19      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE20      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE21      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE22      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE23      ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_CACHE24      ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_CACHE25      ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_CACHE26      ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_CACHE27      ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_CACHE28      ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_CACHE29      ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_CACHE30      ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_CACHE31      ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#define REMAP_BASE      (0x85001000)
#define NCREMAP_HI0     ((volatile kal_uint32 *)(REMAP_BASE+0x0000))
#define NCREMAP_LO0     ((volatile kal_uint32 *)(REMAP_BASE+0x0004))
#define NCREMAP_HI1     ((volatile kal_uint32 *)(REMAP_BASE+0x0008))
#define NCREMAP_LO1     ((volatile kal_uint32 *)(REMAP_BASE+0x000C))

#elif (defined(MT6238) || defined(MT6239))   /* MT6228 || MT6229 || MT6230 */

/* L2 Cache */
#define L2CACHE_BASE    (0x810b0000)
#define L2C_CON         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0000))
#define L2_TARGET       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0004))
#define L2C_STA         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0008))
#define L2C_TAG         ((volatile kal_uint32 *)(L2CACHE_BASE+0x000C))
#define L2C_DATA        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0010))
#define L2C_MODE        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0014))
#define L2C_DMYTAG      ((volatile kal_uint32 *)(L2CACHE_BASE+0x0018))
#define L2C_HCNTL       ((volatile kal_uint32 *)(L2CACHE_BASE+0x001C))
#define L2C_HCNTU       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0020))
#define L2C_ACNTL       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0024))
#define L2C_ACNTU       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0028))

#elif defined(MT6268T) || defined(MT6268H) /* MT6228 || MT6229 || MT6230 */

/* L1 Cache and MPU */
#define L1CACHE_BASE    (0x80700000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x80701000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_CACHE10     ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_CACHE11     ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_CACHE12     ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_CACHE13     ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_CACHE14     ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_CACHE15     ((volatile kal_uint32 *)(MPU_BASE+0x007C))

/* L2 Cache */
#define L2CACHE_BASE    (0x80050000)
#define L2C_CON         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0000))
#define L2_TARGET       ((volatile kal_uint32 *)(L2CACHE_BASE+0x0004))
#define L2C_STA         ((volatile kal_uint32 *)(L2CACHE_BASE+0x0008))
#define L2C_TAG         ((volatile kal_uint32 *)(L2CACHE_BASE+0x000C))
#define L2C_DATA        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0010))
#define L2C_MODE        ((volatile kal_uint32 *)(L2CACHE_BASE+0x0014))
#define L2C_DMYTAG      ((volatile kal_uint32 *)(L2CACHE_BASE+0x0018))

#elif defined(TK6516) || defined(MT6516)   /* MT6228 || MT6229 || MT6230 */

/* L1 Cache and MPU */
#define L1CACHE_BASE    (0x5fff0000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

#define MPU_BASE        (0x5fff1000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_CACHE10     ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_CACHE11     ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_CACHE12     ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_CACHE13     ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_CACHE14     ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_CACHE15     ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) /* TK6516 || MT6516 */

/* Cache control registers */
#define L1CACHE_BASE    (0xA0530000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

/* MPU region registers */
#define MPU_CHANNEL_EN  ((volatile kal_uint32 *)(L1CACHE_BASE+0x002C))

#define MPU_BASE        (0xA0540000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

#define MPU_PROT0_END       ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_PROT1_END       ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_PROT2_END       ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_PROT3_END       ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_PROT4_END       ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_PROT5_END       ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_PROT6_END       ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_PROT7_END       ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_PROT8_END       ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_PROT9_END       ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_PROT10_END      ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_PROT11_END      ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_PROT12_END      ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_PROT13_END      ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_PROT14_END      ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_PROT15_END      ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_CACHE10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_CACHE11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_CACHE12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_CACHE13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_CACHE14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_CACHE15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

/* Address remapping Registers */
#define REMAP_BASE      (0xA0531000)
#define NCREMAP_HI0     ((volatile kal_uint32 *)(REMAP_BASE+0x0000))
#define NCREMAP_LO0     ((volatile kal_uint32 *)(REMAP_BASE+0x0004))
#define NCREMAP_HI1     ((volatile kal_uint32 *)(REMAP_BASE+0x0008))
#define NCREMAP_LO1     ((volatile kal_uint32 *)(REMAP_BASE+0x000C))
#if defined(MT6261) || defined(MT2501) || defined(MT2502)
#define NCREMAP_HI2     ((volatile kal_uint32 *)(REMAP_BASE+0x0010))
#define NCREMAP_LO2     ((volatile kal_uint32 *)(REMAP_BASE+0x0014))
#endif
#endif   /* MT6250 || MT6260 || MT6261 || MT2501 || MT2502 */

#endif /* _CACHE_HW_H */
