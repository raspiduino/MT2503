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
 *    idp_hisr_mt6252.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
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
 * 10 14 2013 chrono.wu
 * removed!
 * 	.
 *
 * 08 10 2011 peter.wang
 * removed!
 * .
 *
 * 07 14 2011 peter.wang
 * removed!
 * .
 *
 * 05 09 2011 peter.wang
 * removed!
 * .
 *
 * 04 26 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 15 2010 cm.huang
 * NULL
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

#include <idp_define.h>

#if defined(DRV_IDP_6252_SERIES)

#if defined(IDP_HISR_SUPPORT)

#include "visualhisr.h"
#include "mt6252\idp_hisr.h"

#define MAX_HISR_CB (3)

struct idp_hisr_cb_t
{
    kal_uint32 m_key;
    kal_uint32 m_activate;

    idp_hisr_intr_cb_t mp_cb;
    idp_hisr_intr_cb_param_t mp_cb_param;

    VISUAL_HISR_ID m_visual_hisr_id;
};
typedef struct idp_hisr_cb_t idp_hisr_cb_t;

static idp_hisr_cb_t imgdma_hisr_cb[MAX_HISR_CB] = {0};
static idp_hisr_cb_t resz_hisr_cb[MAX_HISR_CB] = {0};

static kal_semid imgdma_hisr_cb_sem;
static kal_semid resz_hisr_cb_sem;

static void
idp_hisr_find_real_target(idp_hisr_cb_type const type,
                          idp_hisr_cb_t ** const target,
                          kal_uint32 * const size,
                          kal_semid * const sem_id)
{
    switch (type)
    {
        case IDP_HISR_CB_TYPE_IMGDMA:
            (*target) = imgdma_hisr_cb;
            (*size) = MAX_HISR_CB;
            (*sem_id) = imgdma_hisr_cb_sem;
            break;

        case IDP_HISR_CB_TYPE_RESZ:
            (*target) = resz_hisr_cb;
            (*size) = MAX_HISR_CB;
            (*sem_id) = resz_hisr_cb_sem;
            break;

        default:
            (*target) = NULL;
            (*size) = 0;
            (*sem_id) = NULL;
            break;
    }
}

static idp_hisr_cb_t *
idp_hisr_find_available_slot(idp_hisr_cb_type const type)
{
    idp_hisr_cb_t *hisr_cb;
    kal_uint32     hisr_cb_size;
    kal_semid      sem_id;
    kal_uint32     i;

    /* Because I need to call semaphore API, I have to ensure
    * this function will not be called from HISR & LISR.
    */
    if (kal_if_hisr() || kal_if_lisr())
    {
        return NULL;
    }

    idp_hisr_find_real_target(type, &hisr_cb, &hisr_cb_size, &sem_id);


    kal_take_sem(sem_id, KAL_INFINITE_WAIT);

    for (i = 0; i < hisr_cb_size; ++i)
    {
        if (0 == (hisr_cb + i)->m_key)
        {
            kal_give_sem(sem_id);

            return (hisr_cb + i);
        }
    }

    kal_give_sem(sem_id);
    return NULL;

}

idp_hisr_handle_t
idp_hisr_register(kal_uint32 const key,
                  idp_hisr_cb_type const type,
                  idp_hisr_intr_cb_t const cb,
                  idp_hisr_intr_cb_param_t const param)
{
    // This function should be called under Task context.
    idp_hisr_cb_t * const hisr_cb = idp_hisr_find_available_slot(type);

    ASSERT(key != 0);
    ASSERT(hisr_cb != NULL);

    hisr_cb->m_key = key;
    hisr_cb->m_activate = 0;

    hisr_cb->mp_cb = cb;
    hisr_cb->mp_cb_param = param;

    return (void *)hisr_cb;
}

void
idp_hisr_activate(idp_hisr_handle_t const handle)
{
    idp_hisr_cb_t * const hisr_cb = (idp_hisr_cb_t *)handle;

    ASSERT(NULL != hisr_cb);
    // This function may be called from LISR, so that I have
    // to ensure the following line will be atomic.
    {
        kal_uint32 const save_irq_mask = SaveAndSetIRQMask();
        ++(hisr_cb->m_activate);
        RestoreIRQMask(save_irq_mask);
    }
#ifndef __MAUI_BASIC__
    visual_active_hisr(hisr_cb->m_visual_hisr_id);
#endif
}

void
idp_hisr_clear_all(kal_uint32 const key,
                   idp_hisr_cb_type const type)
{
    idp_hisr_cb_t *hisr_cb;
    kal_uint32     hisr_cb_size;
    kal_semid      sem_id;
    kal_uint32     i;

    ASSERT(key != 0);

    /* Because I need to call semaphore API, I have to ensure
    * this function will not be called from HISR & LISR.
    */
    ASSERT(!kal_if_hisr());
    ASSERT(!kal_if_lisr());

    idp_hisr_find_real_target(type, &hisr_cb, &hisr_cb_size, &sem_id);


    kal_take_sem(sem_id, KAL_INFINITE_WAIT);

    for (i = 0; i < hisr_cb_size; ++i)
    {
        if ((hisr_cb + i)->m_key == key)
        {
            (hisr_cb + i)->m_key = 0;
            (hisr_cb + i)->mp_cb = NULL;
            (hisr_cb + i)->mp_cb_param = NULL;
        }
    }

    kal_give_sem(sem_id);
}

void
idp_hisr_imgdma(void)
{
    kal_uint32 i;

    for (i = 0; i < MAX_HISR_CB; ++i)
    {
        // This function is in the Visual HISR context, however,
        // it may preempt other tasks, and those tasks may be
        // changing the xxx_hisr_cb.m_key. so that I have to
        // protect the accessing of key.
        kal_uint32 save_irq_mask = SaveAndSetIRQMask();
        kal_uint32 const key = imgdma_hisr_cb[i].m_key;
        kal_uint32 const activate = imgdma_hisr_cb[i].m_activate;
        RestoreIRQMask(save_irq_mask);

        if ((key != 0) && (imgdma_hisr_cb[i].mp_cb != NULL) && (activate != 0))
        {
            kal_bool const result = (*imgdma_hisr_cb[i].mp_cb)(imgdma_hisr_cb[i].mp_cb_param);

            save_irq_mask = SaveAndSetIRQMask();
            --(imgdma_hisr_cb[i].m_activate);
            RestoreIRQMask(save_irq_mask);

            if (KAL_TRUE == result)
            {
                return;
            }
        }
    }
}


void
idp_hisr_resz(void)
{
    kal_uint32 i;

    for (i = 0; i < MAX_HISR_CB; ++i)
    {
        // This function is in the Visual HISR context, however,
        // it may preempt other tasks, and those tasks may be
        // changing the xxx_hisr_cb.m_key. so that I have to
        // protect the accessing of key.
        kal_uint32 save_irq_mask = SaveAndSetIRQMask();
        kal_uint32 const key = resz_hisr_cb[i].m_key;
        kal_uint32 const activate = resz_hisr_cb[i].m_activate;
        RestoreIRQMask(save_irq_mask);

        if ((key != 0) && (resz_hisr_cb[i].mp_cb != NULL) && (activate != 0))
        {
            kal_bool const result = (*resz_hisr_cb[i].mp_cb)(resz_hisr_cb[i].mp_cb_param);

            save_irq_mask = SaveAndSetIRQMask();
            --(resz_hisr_cb[i].m_activate);
            RestoreIRQMask(save_irq_mask);

            if (KAL_TRUE == result)
            {
                return;
            }
        }
    }
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

void
idp_hisr_init(void)
{
    kal_uint32 i;

    imgdma_hisr_cb_sem = kal_create_sem("IDP_IMGDMA_HISR", 1);
    resz_hisr_cb_sem = kal_create_sem("IDP_RESZ_HISR", 1);
    //imgproc_hisr_cb_sem = kal_create_sem("IDP_IMGPROC_HISR", 1);

#if !defined(__MAUI_BASIC__)
    VISUAL_Register_HISR(VISUAL_IMGDMA_HISR_ID, idp_hisr_imgdma);
    VISUAL_Register_HISR(VISUAL_RESIZER_HISR_ID, idp_hisr_resz);
    //VISUAL_Register_HISR(VISUAL_IMGPROC_HISR_ID, idp_hisr_imgproc);
#endif

    for (i = 0; i < MAX_HISR_CB; ++i)
    {
        imgdma_hisr_cb[i].m_visual_hisr_id = VISUAL_IMGDMA_HISR_ID;
        imgdma_hisr_cb[i].m_key = 0;
        imgdma_hisr_cb[i].mp_cb = NULL;
        imgdma_hisr_cb[i].mp_cb_param = NULL;

        resz_hisr_cb[i].m_visual_hisr_id = VISUAL_RESIZER_HISR_ID;
        resz_hisr_cb[i].m_key = 0;
        resz_hisr_cb[i].mp_cb = NULL;
        resz_hisr_cb[i].mp_cb_param = NULL;
    }
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

#endif // #if defined(IDP_HISR_SUPPORT)

#endif // #if defined(DRV_IDP_6252_SERIES)

