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
 *  AppListBarrel.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AppList VLW
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
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#include "MMI_features.h"



#if defined(__MMI_APPLIST_BARREL_SUPPORT__)

#include "MMIDataType.h"
#include "AppListBarrel.h"

#define MMI_APPLIST_BARREL_AUTO_SLIDE_BACK_DELAY 800

U16 g_barrel_type;

#ifndef __MMI_APPLIST_BARREL_DISABLE_NORMAL_EFFECT__
static void mmi_applist_barrel_get_normal(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_DOWN_EFFECT__
static void mmi_applist_barrel_get_slide_down(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_UP_EFFECT__
static void mmi_applist_barrel_get_slide_up(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CENTER_EFFECT__
static void mmi_applist_barrel_get_collection_center(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CORNER_EFFECT__
static void mmi_applist_barrel_get_collection_corner(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
static void mmi_applist_barrel_get_jump_up(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__
static void mmi_applist_barrel_get_space_beam(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_ROLL_EFFECT__
static void mmi_applist_barrel_get_roll(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
static void mmi_applist_barrel_get_cylinder(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__
static void mmi_applist_barrel_get_cube(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
static void mmi_applist_barrel_get_tornado(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
static void mmi_applist_barrel_get_ball(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__
static void mmi_applist_barrel_get_tilt(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__
static void mmi_applist_barrel_get_wave(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z);
#endif
#if !defined(__MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__) || !defined(__MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__)
static void mmi_applist_barrel_get_tilt_ext(S32 cell_index, gdi_lt_matrix_struct *transform, U8 *opacity, float *pos_z, U8 photo_wall_type);
#endif



transform_func g_barrel_get_transform_func_array[] =
{
#ifndef __MMI_APPLIST_BARREL_DISABLE_NORMAL_EFFECT__
    &mmi_applist_barrel_get_normal,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_DOWN_EFFECT__
    &mmi_applist_barrel_get_slide_down,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_UP_EFFECT__
    &mmi_applist_barrel_get_slide_up,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CENTER_EFFECT__
    &mmi_applist_barrel_get_collection_center,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CORNER_EFFECT__
    &mmi_applist_barrel_get_collection_corner,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
    &mmi_applist_barrel_get_jump_up,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__
    &mmi_applist_barrel_get_space_beam,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_ROLL_EFFECT__
    &mmi_applist_barrel_get_roll,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
    &mmi_applist_barrel_get_cylinder,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__
    &mmi_applist_barrel_get_cube,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
    &mmi_applist_barrel_get_tornado,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
    &mmi_applist_barrel_get_ball,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__
    &mmi_applist_barrel_get_tilt,
#endif
#ifndef __MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__
    &mmi_applist_barrel_get_wave
#endif
};




/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_transform_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_3x3_identity(gdi_lt_matrix_struct *transform)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    transform->m[0] = 1.0f;
    transform->m[1] = 0.0f;
    transform->m[2] = 0.0f;
    transform->m[3] = 0.0f;
    transform->m[4] = 1.0f;
    transform->m[5] = 0.0f;
    transform->m[6] = 0.0f;
    transform->m[7] = 0.0f;
    transform->m[8] = 1.0f;    
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_t
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static float mmi_applist_barrel_get_t(S32 cell_index)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 page_idx, page_start;
    float t;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    page_idx = cell_index / MMI_APPLIST_APP_COUNT_PER_PAGE;
    page_start = page_idx * MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;

    t = (float)(page_start - applist_p->slide_region.x) / MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
    
    return t;
}

#ifndef __MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_camera
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_camera(
    float m[16], /* Out */
    float scaleX,
    float scaleY,
    float translateX,
    float translateY,
    float nearPlane,
    float cameraDistance,
    float cameraUp,
    float tile,
    float pan)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    m[0] = scaleX * mmi_applist_cos(APPLIST_DEG_TO_RAD(pan)) + (translateX * mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane)* -1 * mmi_applist_sin(APPLIST_DEG_TO_RAD(pan));
    m[4] = translateX * mmi_applist_sin(APPLIST_DEG_TO_RAD(tile))/nearPlane ;
    m[8] = scaleX * mmi_applist_sin(APPLIST_DEG_TO_RAD(pan)) + (translateX * mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane)* mmi_applist_cos(APPLIST_DEG_TO_RAD(pan));
    m[12] = translateX * cameraDistance / nearPlane;

    m[1] = (-1 * scaleY * mmi_applist_sin(APPLIST_DEG_TO_RAD(tile)) + translateY * mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane) * -1 * mmi_applist_sin(APPLIST_DEG_TO_RAD(pan));
    m[5] = scaleY * mmi_applist_cos(APPLIST_DEG_TO_RAD(tile)) + translateY * mmi_applist_sin(APPLIST_DEG_TO_RAD(tile))/nearPlane;
    m[9] = (-1 * scaleY * mmi_applist_sin(APPLIST_DEG_TO_RAD(tile)) + translateY * mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane) * mmi_applist_cos(APPLIST_DEG_TO_RAD(pan));
    m[13] = scaleY * cameraUp + translateY * cameraDistance / nearPlane;

    m[2] = mmi_applist_cos(APPLIST_DEG_TO_RAD(tile)) * -1 * mmi_applist_sin(APPLIST_DEG_TO_RAD(pan));
    m[6] = mmi_applist_sin(APPLIST_DEG_TO_RAD(tile));
    m[10] = mmi_applist_cos(APPLIST_DEG_TO_RAD(tile)) * mmi_applist_cos(APPLIST_DEG_TO_RAD(pan));
    m[14] = cameraDistance;

    m[3] = mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane * -1 * mmi_applist_sin(APPLIST_DEG_TO_RAD(pan));
    m[7] = mmi_applist_sin(APPLIST_DEG_TO_RAD(tile))/nearPlane;
    m[11] = mmi_applist_cos(APPLIST_DEG_TO_RAD(tile))/nearPlane * mmi_applist_cos(APPLIST_DEG_TO_RAD(pan));
    m[15] = cameraDistance/nearPlane;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_identity
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_identity(float m[16])
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    m[0] = 1;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 1;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1;
    m[11] = 0;
    m[12] = 0;
    m[13] = 0;
    m[14] = 0;
    m[15] = 1;   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_4x4_multiply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_4x4_multiply(float a[16], float b[16], float out[16])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Column major matrix multiplication */
    out[0]  = a[0] * b[0]  + a[4] * b[1]  + a[8] * b[2]  + a[12] * b[3];
    out[4]  = a[0] * b[4]  + a[4] * b[5]  + a[8] * b[6]  + a[12] * b[7];
    out[8]  = a[0] * b[8]  + a[4] * b[9]  + a[8] * b[10] + a[12] * b[11];
    out[12] = a[0] * b[12] + a[4] * b[13] + a[8] * b[14] + a[12] * b[15];

    out[1]  = a[1] * b[0]  + a[5] * b[1]  + a[9] * b[2]  + a[13] * b[3];
    out[5]  = a[1] * b[4]  + a[5] * b[5]  + a[9] * b[6]  + a[13] * b[7];
    out[9]  = a[1] * b[8]  + a[5] * b[9]  + a[9] * b[10] + a[13] * b[11];
    out[13] = a[1] * b[12] + a[5] * b[13] + a[9] * b[14] + a[13] * b[15];

    out[2]  = a[2] * b[0]  + a[6] * b[1]  + a[10] * b[2]  + a[14] * b[3];
    out[6]  = a[2] * b[4]  + a[6] * b[5]  + a[10] * b[6]  + a[14] * b[7];
    out[10] = a[2] * b[8]  + a[6] * b[9]  + a[10] * b[10] + a[14] * b[11];
    out[14] = a[2] * b[12] + a[6] * b[13] + a[10] * b[14] + a[14] * b[15];

    out[3]  = a[3] * b[0]  + a[7] * b[1]  + a[11] * b[2]  + a[15] * b[3];
    out[7]  = a[3] * b[4]  + a[7] * b[5]  + a[11] * b[6]  + a[15] * b[7];
    out[11] = a[3] * b[8]  + a[7] * b[9]  + a[11] * b[10] + a[15] * b[11];
    out[15] = a[3] * b[12] + a[7] * b[13] + a[11] * b[14] + a[15] * b[15];

}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_init_3x3_matrix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_init_3x3_matrix(float out[9], float m[16])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    out[0] = m[0];
    out[3] = m[4];
    out[6] = m[12];
    out[1] = m[1];
    out[4] = m[5];
    out[7] = m[13];
    out[2] = m[3];
    out[5] = m[7];
    out[8] = m[15];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_transpose_3x3_matrix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_transpose_3x3_matrix(float m[9])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    float tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 3; i ++)
    {
        for (j = i + 1; j < 3; j ++)
        {
            tmp = m[i * 3 + j];
            m[i * 3 + j] = m[j * 3 + i];
            m[j * 3 + i] = tmp;
        }
    }

    for (i = 0; i < 9; i ++)
    {
        m[i] /= m[8];        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_translation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_translation(float m[16], float tx, float ty, float tz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_barrel_set_4x4_identity(m);

    /* Column major matrix */
    m[12] = tx;
    m[13] = ty;
    m[14] = tz;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_rotate_by_x
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_rotate_by_x(float m[16], float rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_barrel_set_4x4_identity(m);

    /* Column major matrix */
    m[5] = m[10] = mmi_applist_cos(rad);
    m[6] = mmi_applist_sin(rad);
    m[9] = -1 * m[6];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_rotate_by_y
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_rotate_by_y(float m[16], float rad)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_applist_barrel_set_4x4_identity(m);

    /* Column major matrix */
    m[0] = m[10] = mmi_applist_cos(rad);
    m[8] = mmi_applist_sin(rad);
    m[2] = -1 * m[8];
}


#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_cylinder_model
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_cylinder_model(float m[16], S32 index_x, S32 index_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float model1[16], model2[16], rotate2[16], out[16];
    float radius = MMI_APPLIST_BARREL_CYLINDER_RADIUS;
    float angleb, cosb, sinb, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_barrel_set_4x4_translation(
            model1, 
           -MMI_APPLIST_CELL_WIDTH / 2, 
           -MMI_APPLIST_CELL_HEIGHT / 2,
           0);

#if (MMI_APPLIST_CELL_COLUMN_COUNT == 4)
    
    if (index_x == 0)
    {
        angleb = -51;
    }
    else if (index_x == 1)
    {
        angleb = -17;
    }
    else if (index_x == 2)
    {
        angleb = 17;
    }
    else
    {
        angleb = 51;
    }
    
#elif (MMI_APPLIST_CELL_COLUMN_COUNT == 5)    
    
    if (index_x == 0)
    {
        angleb = 51;
    }
    else if (index_x == 1)
    {
        angleb = 26;
    }
    else if (index_x == 2)
    {
        angleb = 0;
    }
    else if (index_x == 3)
    {
        angleb = -26;
    }
    else
    {
        angleb = -51;
    }
 
#else /* MMI_APPLIST_CELL_COLUMN_COUNT == 3 */   
    
    if (index_x == 0)
    {
        angleb = -45;
    }
    else if (index_x == 1)
    {
        angleb = 0;
    }
    else 
    {
        angleb = 45;
    }
    
#endif /* MMI_APPLIST_CELL_COLUMN_COUNT == xxx  */ 

    mmi_applist_barrel_set_4x4_rotate_by_y(rotate2, APPLIST_DEG_TO_RAD(-angleb));
   
    sinb = mmi_applist_sin(APPLIST_DEG_TO_RAD(angleb));
    cosb = mmi_applist_cos(APPLIST_DEG_TO_RAD(angleb));

#if (MMI_APPLIST_CELL_ROW_COUNT == 4)
    offset_y = 1.5f;        
#elif (MMI_APPLIST_CELL_ROW_COUNT == 5)    
    offset_y = 2.0f;        
#else /* MMI_APPLIST_CELL_ROW_COUNT == 3 */   
    offset_y = 1.0f;        
#endif /* MMI_APPLIST_CELL_ROW_COUNT == xxx  */ 

    mmi_applist_barrel_set_4x4_translation(
        model2,
        radius * sinb, 
        MMI_APPLIST_CELL_HEIGHT * (index_y - offset_y), 
        -radius * cosb);

    mmi_applist_barrel_4x4_multiply(rotate2, model1, out);
    mmi_applist_barrel_4x4_multiply(model2, out, m);    
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_set_4x4_cylinder_model
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_set_4x4_ball_model(float m[16], S32 index_x, S32 index_y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float model1[16], model2[16], rotate1[16], rotate2[16], out_1[16], out_2[16];
    float radius = MMI_APPLIST_BARREL_BALL_RADIUS;
    float anglea, angleb, cosa, cosb, sina, sinb;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_applist_barrel_set_4x4_translation(
            model1, 
           -MMI_APPLIST_CELL_WIDTH / 2, 
           -MMI_APPLIST_CELL_HEIGHT / 2,
           0);

#if (MMI_APPLIST_CELL_ROW_COUNT == 4)
    
    if (index_y == 0)
    {
        anglea = 51;
    }
    else if (index_y == 1)
    {
        anglea = 17;
    }
    else if (index_y == 2)
    {
        anglea = -17;
    }
    else
    {
        anglea = -51;
    }
    
#elif (MMI_APPLIST_CELL_ROW_COUNT == 5)    
    
    if (index_y == 0)
    {
        anglea = 51;
    }
    else if (index_y == 1)
    {
        anglea = 26;
    }
    else if (index_y == 2)
    {
        anglea = 0;
    }
    else if (index_y == 3)
    {
        anglea = -26;
    }
    else
    {
        anglea = -51;
    }
 
#else /* MMI_APPLIST_CELL_ROW_COUNT == 3 */   
    
    if (index_y == 0)
    {
        anglea = 45;
    }
    else if (index_y == 1)
    {
        anglea = 0;
    }
    else 
    {
        anglea = -45;
    }
    
#endif /* MMI_APPLIST_CELL_ROW_COUNT == xxx  */ 

#if (MMI_APPLIST_CELL_COLUMN_COUNT == 4)
        
        if (index_x == 0)
        {
            angleb = -51;
        }
        else if (index_x == 1)
        {
            angleb = -17;
        }
        else if (index_x == 2)
        {
            angleb = 17;
        }
        else
        {
            angleb = 51;
        }
        
#elif (MMI_APPLIST_CELL_COLUMN_COUNT == 5)    
        
        if (index_x == 0)
        {
            angleb = 51;
        }
        else if (index_x == 1)
        {
            angleb = 26;
        }
        else if (index_x == 2)
        {
            angleb = 0;
        }
        else if (index_x == 3)
        {
            angleb = -26;
        }
        else
        {
            angleb = -51;
        }
     
#else /* MMI_APPLIST_CELL_COLUMN_COUNT == 3 */   
        
        if (index_x == 0)
        {
            angleb = -45;
        }
        else if (index_x == 1)
        {
            angleb = 0;
        }
        else 
        {
            angleb = 45;
        }
        
#endif /* MMI_APPLIST_CELL_COLUMN_COUNT == xxx  */ 

    mmi_applist_barrel_set_4x4_rotate_by_x(rotate1, APPLIST_DEG_TO_RAD(-anglea));
    mmi_applist_barrel_set_4x4_rotate_by_y(rotate2, APPLIST_DEG_TO_RAD(-angleb));

    sina = mmi_applist_sin(APPLIST_DEG_TO_RAD(anglea));
    cosa = mmi_applist_cos(APPLIST_DEG_TO_RAD(anglea));
    sinb = mmi_applist_sin(APPLIST_DEG_TO_RAD(angleb));
    cosb = mmi_applist_cos(APPLIST_DEG_TO_RAD(angleb));

    mmi_applist_barrel_set_4x4_translation(
        model2,
        radius * cosa * sinb, 
        -radius * sina, 
        -radius * cosa * cosb);

    mmi_applist_barrel_4x4_multiply(model2, rotate2, out_1);
    mmi_applist_barrel_4x4_multiply(out_1, rotate1, out_2);
    mmi_applist_barrel_4x4_multiply(out_2, model1, m);    
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
#endif  //__MMI_APPLIST_BARREL_DISABLE_MATRIX_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_NORMAL_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_normal(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    gdi_lt_matrix_struct move, affine;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    /* Assign matrix */
    //move orgin point to cell center
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move); 
    
    mmi_applist_barrel_set_3x3_identity(&affine);

    /* Fixed value */
    *pos_z = 0;
    
    /* Move to destination */
    if (cell == applist_p->focus_cell.cell_p)
    {
        affine.m[2] += GET_FINAL_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x); 
    }
    else
    {
        affine.m[2] += GET_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x); 
    }
    affine.m[5] += cell->pos.y;
    mmi_applist_matrix_multiply(affine.m, move.m, transform->m); 

    /* Opacity */
    *opacity = cell->opacity;
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_NORMAL_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_DOWN_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_slide_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_slide_down(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 pos_x, pos_y, shift;
    gdi_lt_matrix_struct move, affine;
    S32 page_idx, index_x, index_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);
    
    pos_x = GET_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x);
    pos_y = cell->pos.y;    

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);

    *pos_z = (float)(300 - (index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT));;
    
    shift = (S32)(MMI_APPLIST_SLIDE_AREA_HEIGHT * APPLIST_ABS(t));

    pos_y += shift;

    /* Assign matrix */
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move);    
    
    mmi_applist_barrel_set_3x3_identity(&affine);
    affine.m[2] += pos_x;
    affine.m[5] += pos_y;

    mmi_applist_matrix_multiply(affine.m, move.m, transform->m); 
    
    /* Opacity */
    *opacity = (U8)((1.0f - APPLIST_ABS(t))* 255);   
     
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_SLIDE_DOWN_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_SLIDE_UP_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_slide_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_slide_up(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 pos_x, pos_y, shift;
    gdi_lt_matrix_struct move, affine;
    S32 page_idx, index_x, index_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    pos_x = GET_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x);
    pos_y = cell->pos.y;  

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);

    *pos_z = (float)(300 - (index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT));
    
    shift = (S32)(MMI_APPLIST_SLIDE_AREA_HEIGHT * APPLIST_ABS(t));

    pos_y -= shift;


    /* Assign matrix */
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move);    
    
    mmi_applist_barrel_set_3x3_identity(&affine);
    affine.m[2] += pos_x;
    affine.m[5] += pos_y;

    mmi_applist_matrix_multiply(affine.m, move.m, transform->m); 
    
    /* Opacity */
    *opacity = (U8)((1.0f - APPLIST_ABS(t))* 255);   
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_SLIDE_UP_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CENTER_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_collection_center
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_get_collection_center(
        S32 cell_index, 
        gdi_lt_matrix_struct *transform, 
        U8 *opacity,
        float *pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 pos_x, pos_y;
    S32 lX1, lX2, rX1, rX2, lY1, lY2, rY1, rY2;
    float l1 = -0.7f, l2 = -0.5f, r1 = 0.5f, r2 = 0.7f; 
    gdi_lt_matrix_struct move, affine;
    S32 page_idx, index_x, index_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);
    
    lX1 = (S32)(-0.7f * MMI_APPLIST_CELL_WIDTH);
    lX2 = (S32)(-0.3f * MMI_APPLIST_CELL_WIDTH);
    rX1 = (S32)(MMI_APPLIST_PAGE_WIDTH_INC_MARGIN - 0.7f * MMI_APPLIST_CELL_WIDTH);
    rX2 = (S32)(MMI_APPLIST_PAGE_WIDTH_INC_MARGIN - 0.3f * MMI_APPLIST_CELL_WIDTH);

    //lY1 = lY2 = rY1 = rY2 = (S32)(0.5f * pos_y * (MMI_APPLIST_CELL_ROW_COUNT - 1));
    lY1 = lY2 = rY1 = rY2 = (S32)(0.9f * MMI_APPLIST_CELL_HEIGHT * (MMI_APPLIST_CELL_ROW_COUNT - 1));
  
    pos_x = GET_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x);
    pos_y = cell->pos.y;    

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    *pos_z = (float)(300 - (index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT));
    
    /* Assign matrix */
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move); 
    mmi_applist_barrel_set_3x3_identity(&affine);
    
    if(t >= -1 && t < l1)
    {     
        pos_x = lX1 - MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        pos_y = lY1;
        affine.m[2] += lX1 + (pos_x - lX1) * (t - l1) / (-1 - l1);
        affine.m[5] += lY1 + (pos_y - lY1) * (t - l1) / (-1 - l1);       
    }   
    else if(t >= l1 && t < l2)
    {
        affine.m[2] += lX2 + (lX1 - lX2) * (t - l2) / (l1 - l2);
        affine.m[5] += lY2 + (lY1 - lY2) * (t - l2) / (l1 - l2);
    }
    else if(t >= l2 && t < 0)
    {
        affine.m[2] += pos_x + (lX2 - pos_x) * (t - 0) / (l2 - 0);
        affine.m[5] += pos_y + (lY2 - pos_y) * (t - 0) / (l2 - 0);
    }
    else if(t >= 0 && t < r1)
    {
        affine.m[2] += rX1 + (pos_x - rX1) * (t - r1) / (0 - r1);
        affine.m[5] += rY1 + (pos_y - rY1) * (t - r1) / (0 - r1);
    }
    else if(t >= r1 && t < r2)
    {
        affine.m[2] += rX2 + (rX1 - rX2) * (t - r2) / (r1 - r2);
        affine.m[5] += rY2 + (rY1 - rY2) * (t - r2) / (r1 - r2);
    }
    else if(t >= r2)
    {
        pos_x = rX2 + MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        pos_y = rY2;
        affine.m[2] += pos_x + (rX2 - pos_x) * (t - 1) / (r2 - 1);
        affine.m[5] += pos_y + (rY2 - pos_y) * (t - 1) / (r2 - 1);
    }
    
    mmi_applist_matrix_multiply(affine.m, move.m, transform->m);
    
    /* Opacity */
    *opacity = (U8)cell->opacity; 
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_COLLECTION_CENTER_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_COLLECTION_CORNER_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_collection_corner
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_applist_barrel_get_collection_corner(
        S32 cell_index, 
        gdi_lt_matrix_struct *transform, 
        U8 *opacity,
        float *pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 pos_x, pos_y;
    S32 lX1, lX2, rX1, rX2, lY1, lY2, rY1, rY2;
    float l1 = -0.7f, l2 = -0.5f, r1 = 0.5f, r2 = 0.7f; 
    gdi_lt_matrix_struct move, affine;
    S32 page_idx, index_x, index_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);
    
    lX1 = (S32)(-0.7f * MMI_APPLIST_CELL_WIDTH);
    lX2 = (S32)(-0.3f * MMI_APPLIST_CELL_WIDTH);
    rX1 = (S32)(MMI_APPLIST_PAGE_WIDTH_INC_MARGIN - 0.7f * MMI_APPLIST_CELL_WIDTH);
    rX2 = (S32)(MMI_APPLIST_PAGE_WIDTH_INC_MARGIN - 0.3f * MMI_APPLIST_CELL_WIDTH);

    lY1 = lY2 = 0;
    rY1 = rY2 = MMI_APPLIST_SLIDE_AREA_Y + MMI_APPLIST_CELL_HEIGHT * (MMI_APPLIST_CELL_ROW_COUNT - 1);
    
    pos_x = GET_CELL_X(MMI_APPLIST_CELL_TYPE_PANEL, cell->pos.x);
    pos_y = cell->pos.y; 

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    *pos_z = (float)(300 - (index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT));
    
    /* Assign matrix */
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move); 
    mmi_applist_barrel_set_3x3_identity(&affine);

    if(t >= -1 && t < l1)
    {
        pos_x = lX1 - MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        pos_y = lY1;
        affine.m[2] += lX1 + (pos_x - lX1) * (t - l1) / (-1 - l1);
        affine.m[5] += lY1 + (pos_y - lY1) * (t - l1) / (-1 - l1);       
    }   
    else if(t >= l1 && t < l2)
    {
        affine.m[2] += lX2 + (lX1 - lX2) * (t - l2) / (l1 - l2);
        affine.m[5] += lY2 + (lY1 - lY2) * (t - l2) / (l1 - l2);
    }
    else if(t >= l2 && t < 0)
    {
        affine.m[2] += pos_x + (lX2 - pos_x) * (t - 0) / (l2 - 0);
        affine.m[5] += pos_y + (lY2 - pos_y) * (t - 0) / (l2 - 0);
    }
    else if(t >= 0 && t < r1)
    {
        affine.m[2] += rX1 + (pos_x - rX1) * (t - r1) / (0 - r1);
        affine.m[5] += rY1 + (pos_y - rY1) * (t - r1) / (0 - r1);
    }
    else if(t >= r1 && t < r2)
    {
        affine.m[2] += rX2 + (rX1 - rX2) * (t - r2) / (r1 - r2);
        affine.m[5] += rY2 + (rY1 - rY2) * (t - r2) / (r1 - r2);
    }
    else if(t >= r2)
    {
        pos_x = rX2 + MMI_APPLIST_PAGE_WIDTH_INC_MARGIN;
        pos_y = rY2;
        affine.m[2] += pos_x + (rX2 - pos_x) * (t - 1) / (r2 - 1);
        affine.m[5] += pos_y + (rY2 - pos_y) * (t - 1) / (r2 - 1);
    }
    
    mmi_applist_matrix_multiply(affine.m, move.m, transform->m);
    
    /* Opacity */
    *opacity = (U8)cell->opacity; 
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_COLLECTION_CORNER_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_jump_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_jump_up(
        S32 cell_index, 
        gdi_lt_matrix_struct *transform, 
        U8 *opacity,
        float *pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 orin_x, orin_y, page_idx, index_x, index_y, target_x, target_y;
    float opacity_f, normal_t, adj_t, adj_t2, end_t, sec_start_t;
    gdi_lt_matrix_struct scale, affine;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    if (t < - 0.5f || t > 0.5f)
    {
        *opacity = 0;
        return;
    }

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    *pos_z = 300;
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;
    
    /* Assign matrix */
    mmi_applist_barrel_set_3x3_identity(&affine);
    
    normal_t = APPLIST_ABS(t) * 2;
    sec_start_t = 0.55f;

    if (index_x == 0)
    {
        end_t = 0.91f;
    }
    else if (index_x == 1)
    {
        end_t = 0.81f;
    }
    else if (index_x == 2)
    {
        end_t = 0.72f;
    }
    else
    {
        end_t = 1.0f;
    }
    
    if (normal_t > end_t)
    {
        adj_t = 1.0f;
    }
    else
    {
        adj_t = normal_t/end_t;
    }

    if (adj_t < 0)
    {
        adj_t = 0;
    }
    else if (adj_t > 1)
    {
        adj_t = 1;
    }

    target_x = MMI_APPLIST_JUMP_UP_VANISH_POINT_X;
    target_y = MMI_APPLIST_JUMP_UP_VANISH_POINT_Y - 100;

    adj_t2 = adj_t;

    if (normal_t > sec_start_t)
    {
        orin_x = (S32)(orin_x + (target_x - orin_x) * sec_start_t/end_t);
        orin_y = (S32)(orin_y + (target_y - orin_y) * sec_start_t/end_t);

        target_x = MMI_APPLIST_JUMP_UP_VANISH_POINT_X;
        target_y = MMI_APPLIST_JUMP_UP_VANISH_POINT_Y;

        adj_t2 = (normal_t - sec_start_t)/end_t;
    }
    
    affine.m[2] += (target_x - orin_x) * adj_t2 + orin_x;
    affine.m[5] += (target_y - orin_y) * adj_t2 + orin_y;
    
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_SCALE,
        (MMI_APPLIST_JUMP_UP_VANISH_POINT_SCALE - 1) * adj_t + 1,
        (MMI_APPLIST_JUMP_UP_VANISH_POINT_SCALE - 1) * adj_t + 1,
        &scale);
    
    mmi_applist_matrix_multiply(affine.m, scale.m, transform->m);

    
    opacity_f = 1.0f - adj_t;    
    
    /* Opacity */
    *opacity = (U8)(opacity_f * 255); 
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_JUMP_UP_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_space_beam
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_space_beam(
        S32 cell_index, 
        gdi_lt_matrix_struct *transform, 
        U8 *opacity,
        float *pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 orin_x, orin_y, page_idx, index_x, index_y;
    float opacity_f, normal_t, adj_t, adj_t2, start_t;
    gdi_lt_matrix_struct scale, affine;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    if (t < - 0.5f || t > 0.5f)
    {
        *opacity = 0;
        return;
    }

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;
    
    /* Assign matrix */
    mmi_applist_barrel_set_3x3_identity(&affine);
    
    normal_t = APPLIST_ABS(t) * 2;
    start_t = (float)(index_y * MMI_APPLIST_CELL_COLUMN_COUNT + index_x) / (MMI_APPLIST_CELL_COLUMN_COUNT * MMI_APPLIST_CELL_ROW_COUNT) * 0.5f;

    if (normal_t < start_t)
    {
        adj_t = 0;
    }
    else
    {
        //adj_t = (normal_t - start_t)/ (1.0f - start_t);
        adj_t = (normal_t - start_t)/ (0.625f);
    }

    if (adj_t < 0)
    {
        adj_t = 0;
    }
    else if (adj_t > 1)
    {
        adj_t = 1;
    }

    affine.m[2] += (MMI_APPLIST_SPACE_BEAM_VANISH_POINT_X - orin_x) * adj_t + orin_x;
    affine.m[5] += (MMI_APPLIST_SPACE_BEAM_VANISH_POINT_Y - orin_y) * adj_t + orin_y;
    
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_SCALE,
        (float)(((MMI_APPLIST_SPACE_BEAM_VANISH_POINT_SCALE - 1) * adj_t) + 1),
        (float)(((MMI_APPLIST_SPACE_BEAM_VANISH_POINT_SCALE - 1) * adj_t) + 1),
        &scale);
    
    mmi_applist_matrix_multiply(affine.m, scale.m, transform->m);

    
    opacity_f = 1.0f - adj_t;    
    
    /* Opacity */
    *opacity = (U8)(opacity_f * 255); 
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_SPACE_BEAM_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_ROLL_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_roll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_roll(
        S32 cell_index, 
        gdi_lt_matrix_struct *transform, 
        U8 *opacity,
        float *pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t;
    S32 orin_x, orin_y, page_idx, index_x, index_y, idx, radius, lcx, lcy, rcx, rcy, lx, ly, rx, ry;
    float opacity_f, normal_t, adj_t, adj_t2, theta, la, ra, l, r, factor;
    gdi_lt_matrix_struct move, affine, rotate, out;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    *pos_z = (float)(300 - (index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT));
        
    /* Assign matrix */
    mmi_applist_barrel_set_3x3_identity(&affine);
    
    mmi_applist_get_matrix(
        MMI_APPLIST_MATRIX_TYPE_MOVE, 
        -MMI_APPLIST_CELL_WIDTH / 2, 
        -MMI_APPLIST_CELL_HEIGHT / 2,
        &move);

    idx = index_x + index_y * MMI_APPLIST_CELL_COLUMN_COUNT;
    theta = -idx * 2 * APPLIST_PI / MMI_APPLIST_CELL_ROW_COUNT / MMI_APPLIST_CELL_COLUMN_COUNT; 
            
    radius = MMI_APPLIST_CELL_HEIGHT * 3 / 2;
    lcx = 0;
    lcy = (S32)(0.7f * (MMI_APPLIST_SLIDE_AREA_Y + MMI_APPLIST_SLIDE_AREA_HEIGHT));
    rcx = LCD_WIDTH;
    rcy = (S32)(0.7f * (MMI_APPLIST_SLIDE_AREA_Y + MMI_APPLIST_SLIDE_AREA_HEIGHT));
    
    lx = (S32)(lcx + radius * mmi_applist_cos(theta));
    ly = (S32)(lcy + radius * mmi_applist_sin(theta));
    la = theta - 0.5f * APPLIST_PI;

    rx = lx + LCD_WIDTH;
    ry = ly;   
    ra = theta - 0.5f * APPLIST_PI;              
  
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH + 0.5f * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT + 0.5f * MMI_APPLIST_CELL_HEIGHT;


    l = -0.5f, r = 0.5f;
    factor = 3.2f;


    if(t < l)
    {
        affine.m[2] += lcx + radius * factor * (t - l) + radius * mmi_applist_sin(factor * (t - l) + theta + 0.5f  * APPLIST_PI);
        affine.m[5] += lcy - radius * mmi_applist_cos(factor * (t - l) + theta + 0.5f  * APPLIST_PI );
        //target_frame->transform.data.affine.rz = la + factor * (t - l);
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_ROTATE, 
            (float)(la + factor * (t - l)) * 10, 
            0,
            &rotate);
    }
    else if(t >= l && t < 0)
    {
        affine.m[2] += orin_x + (lx - orin_x) * (t - 0) / (l - 0);
        affine.m[5] += orin_y + (ly - orin_y) * (t - 0) / (l - 0);  
        //target_frame->transform.data.affine.rz = 0 + (la - 0) * (t - 0) / (l - 0);  
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_ROTATE, 
            (float)((la - 0) * (t - 0) / (l - 0)) * 10, 
            0,
            &rotate);
    }
    else if(t >= 0 && t < r)
    {
        affine.m[2] += rx + (orin_x - rx) * (t - r) / (0 - r);
        affine.m[5] += ry + (orin_y - ry) * (t - r) / (0 - r);   
        //target_frame->transform.data.affine.rz = ra + (0 - ra) * (t - r) / (0 - r);    
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_ROTATE, 
            (float)(ra + (0 - ra) * (t - r) / (0 - r)) * 10, 
            0,
            &rotate);

    }
    else if(t >= r)
    {
        affine.m[2] += rcx + radius * factor * (t - r) + radius * mmi_applist_sin(factor* (t - r) + theta  + 0.5f  * APPLIST_PI);
        affine.m[5] += rcy - radius * mmi_applist_cos(factor* (t - r) + theta + 0.5f  * APPLIST_PI);
        //target_frame->transform.data.affine.rz = ra + factor * (t - r);       
        mmi_applist_get_matrix(
            MMI_APPLIST_MATRIX_TYPE_ROTATE, 
            (float)(ra + factor * (t - r)) * 10, 
            0,
            &rotate);
    }

    affine.m[0] = affine.m[4] = 1;
    affine.m[6] = affine.m[7] = 0;

    mmi_applist_matrix_multiply(move.m, affine.m, out.m);
    mmi_applist_matrix_multiply(out.m, rotate.m, transform->m);
       
    /* Opacity */
    *opacity = cell->opacity; 
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_ROLL_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_cylinder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_cylinder(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t, interpolate, opacity_f;
    float from_float = 0;
    float to_float = -180;
    S32 orin_x, orin_y, page_idx, index_x, index_y;
    float rotate_by_y[16], camera[16], model[16], total_project[16], out[16];
    float temp_t, det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    interpolate = (from_float) + (to_float - from_float) * t;

    mmi_applist_barrel_set_4x4_rotate_by_y(rotate_by_y, APPLIST_DEG_TO_RAD(interpolate));
    
    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;

    mmi_applist_barrel_set_camera(
                camera,
                1.0f,
                1.0f,
                LCD_WIDTH / 2,
                MMI_APPLIST_SLIDE_AREA_Y + MMI_APPLIST_SLIDE_AREA_HEIGHT /2,
                MMI_APPLIST_BARREL_CYLINDER_NEAR,
                MMI_APPLIST_BARREL_CYLINDER_NEAR + MMI_APPLIST_BARREL_CYLINDER_RADIUS,
                0.0f,
                0.0f,
                0.0f);
    mmi_applist_barrel_set_4x4_cylinder_model(model, index_x, index_y);

    mmi_applist_barrel_4x4_multiply(rotate_by_y, model, out);
    mmi_applist_barrel_4x4_multiply(camera, out, total_project);

    *pos_z = total_project[14];

    /* Column major matrix multiplication */
    mmi_applist_barrel_init_3x3_matrix(transform->m, total_project);

    if (APPLIST_ABS(t) < 0.3f)
    {
        temp_t = APPLIST_ABS(t)/0.3f;
        transform->m[0] = temp_t * transform->m[0] + (1 - temp_t) * 1;
        transform->m[1] = temp_t * transform->m[1];
        transform->m[2] = temp_t * transform->m[2];
        transform->m[3] = temp_t * transform->m[3];
        transform->m[4] = temp_t * transform->m[4] + (1 - temp_t) * 1;
        transform->m[5] = temp_t * transform->m[5];
        transform->m[6] = temp_t * transform->m[6] + (1 - temp_t) * orin_x;
        transform->m[7] = temp_t * transform->m[7] + (1 - temp_t) * orin_y;
        transform->m[8] = temp_t * transform->m[8] + (1 - temp_t) * 1;
    } 


    // do Culling
    det = ((transform->m[0] * transform->m[4] * transform->m[8]) + (transform->m[6] * transform->m[1] * transform->m[5]) + (transform->m[3] * transform->m[7] * transform->m[2]) -
               (transform->m[3] * transform->m[1] * transform->m[8]) - (transform->m[0] * transform->m[7] * transform->m[5]) - (transform->m[6] * transform->m[4] * transform->m[2])) *
              ((transform->m[2] + transform->m[8]) * (transform->m[5] + transform->m[8]) * transform->m[8]);
    

    /* Change from column-major to row-major matrix */
    mmi_applist_barrel_transpose_3x3_matrix(transform->m);

    /* Opacity */
    if (APPLIST_ABS(t) > 0.9)
    {
        temp_t = (APPLIST_ABS(t) - 0.9f) / 0.1f;
        opacity_f = 1 - temp_t;
        if (opacity_f < 0)
        {
           opacity_f = 0;
        }
    }
    else
    {
        opacity_f = 1.0f;
    }
    

    if (APPLIST_ABS(det) < 0.2f)
    {
        opacity_f = 0;
    }

    *opacity = (U8)(opacity_f * 255);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_CYLINDER_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_cube
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_cube(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t, opacity_f = 1.0f;
    S32 orin_x, orin_y, page_idx, index_x, index_y;
    float camera[16], rotate_by_y[16], total_project[16], out[16], model[16];
    float angle = 0, temp_y_angle, camera_distance, z_shift, det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    if (angle == 90.0f)
    {
        temp_y_angle =  -t * (90.0f);
        camera_distance = MMI_APPLIST_CUBE_TRANSITION_CAMERA_DISTANCE + 0.414214f * LCD_WIDTH/2 * mmi_applist_sin(APPLIST_ABS(temp_y_angle)/90.0f * APPLIST_PI);
        z_shift = (float)LCD_WIDTH/2;
    }
    else
    {
        temp_y_angle =  -t * (60.0f);
        camera_distance = MMI_APPLIST_CUBE_TRANSITION_CAMERA_DISTANCE + 0.133975f * LCD_WIDTH * mmi_applist_sin(APPLIST_ABS(temp_y_angle)/60.0f * APPLIST_PI);
        z_shift = LCD_WIDTH * 0.8f;//0.866025f;
    }

    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;

    mmi_applist_barrel_set_4x4_rotate_by_y(rotate_by_y, APPLIST_DEG_TO_RAD(temp_y_angle));
    mmi_applist_barrel_set_camera(camera,
        1.0f,
        1.0f,
        LCD_WIDTH/2,
        MMI_APPLIST_SLIDE_AREA_HEIGHT/2,
        MMI_APPLIST_CUBE_TRANSITION_CAMERA_DISTANCE - z_shift,
        camera_distance,
        0,
        0,
        0);

    mmi_applist_barrel_4x4_multiply(camera, rotate_by_y, out);

    mmi_applist_barrel_set_4x4_translation(model,
        orin_x - LCD_WIDTH / 2,
        orin_y - MMI_APPLIST_SLIDE_AREA_HEIGHT / 2,
        -z_shift);

    mmi_applist_barrel_4x4_multiply(out, model, total_project);

    /* Column major matrix multiplication */
    mmi_applist_barrel_init_3x3_matrix(transform->m, total_project);


    // do Culling
    det = ((transform->m[0] * transform->m[4] * transform->m[8]) + (transform->m[6] * transform->m[1] * transform->m[5]) + (transform->m[3] * transform->m[7] * transform->m[2]) -
               (transform->m[3] * transform->m[1] * transform->m[8]) - (transform->m[0] * transform->m[7] * transform->m[5]) - (transform->m[6] * transform->m[4] * transform->m[2])) *
              ((transform->m[2] + transform->m[8]) * (transform->m[5] + transform->m[8]) * transform->m[8]);
    

    /* Change from column-major to row-major matrix */
    mmi_applist_barrel_transpose_3x3_matrix(transform->m);

    /* Opacity */
    if (APPLIST_ABS(det) < 0.2f)
    {
        opacity_f = 0;
    }

    *opacity = (U8)(opacity_f * 255);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_CUBE_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_tornado
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_tornado(
        S32 cell_index,
        gdi_lt_matrix_struct * transform,
        U8 * opacity,
        float * pos_z)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t, offset, opacity_f;
    S32 orin_x, orin_y, page_idx, index_x, index_y;
    float camera[16], model[16], total_project[16], out[16], rt[16];
    float temp, temp_t, shift, tempOffset, distance, angleAAA, angleBBB, det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);
    
    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;
    
    //offset = cellIndex - focusIndex;
    offset = (t + index_x/(float)(MMI_APPLIST_CELL_COLUMN_COUNT * MMI_APPLIST_CELL_ROW_COUNT) + index_y/(float)MMI_APPLIST_CELL_ROW_COUNT) * (MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT + 0) - 5;

    mmi_applist_barrel_set_camera(
                camera,
                1.0f,
                1.0f,
                LCD_WIDTH / 2,
                MMI_APPLIST_SLIDE_AREA_HEIGHT / 2 + MMI_APPLIST_TORNADO_MENU_Y_SHIFT,
                340.0f,
                340.0f + MMI_APPLIST_TORNADO_MENU_FROM_RADIUS * 0.8f,
                0.0f,
                0.0f,
                0.0f);
    
    // set Model View :
    // The model view matirx decides the origin and direction of model.
    // We set the origin of each item to the center of item.
    // So we need to apply a negative translate. 
    mmi_applist_barrel_set_4x4_translation(model, 
                    -1 * MMI_APPLIST_CELL_WIDTH/2,
                    -1 * MMI_APPLIST_CELL_HEIGHT/2,
                    0);

    if (offset > MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT)
    {        
        tempOffset = MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT;
        distance = ((tempOffset + MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT) * (MMI_APPLIST_TORNADO_MENU_TO_RADIUS - MMI_APPLIST_TORNADO_MENU_FROM_RADIUS)/(MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT + MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT) + MMI_APPLIST_TORNADO_MENU_FROM_RADIUS);
        angleAAA = tempOffset * (MMI_APPLIST_TORNADO_MENU_ANGLE/ 180.0f * APPLIST_PI) - APPLIST_PI/2;
        angleBBB = tempOffset * (-1.0f * MMI_APPLIST_TORNADO_MENU_ANGLE/ 180.0f * APPLIST_PI);
        
        rt[12] = mmi_applist_cos(angleAAA) * distance;
        rt[13] = (tempOffset * 0.125f + (offset - tempOffset)) * MMI_APPLIST_TORNADO_MENU_Y_GAP;
        rt[14] = mmi_applist_sin(angleAAA) * distance;

        
        rt[0] = rt[10] = mmi_applist_cos(angleBBB);
        rt[8] = mmi_applist_sin(angleBBB);
        rt[2] = -1 * rt[8];
    }
    else
    {
        distance = ((offset + MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT) * (MMI_APPLIST_TORNADO_MENU_TO_RADIUS - MMI_APPLIST_TORNADO_MENU_FROM_RADIUS)/(MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT + MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT) + MMI_APPLIST_TORNADO_MENU_FROM_RADIUS);
        angleAAA = offset * (MMI_APPLIST_TORNADO_MENU_ANGLE/ 180.0f * APPLIST_PI) - APPLIST_PI/2;
        angleBBB = offset * (-1.0f * MMI_APPLIST_TORNADO_MENU_ANGLE/ 180.0f * APPLIST_PI);

        rt[12] = mmi_applist_cos(angleAAA) * distance;
        rt[13] = offset * 0.125f * MMI_APPLIST_TORNADO_MENU_Y_GAP; 
        rt[14] = mmi_applist_sin(angleAAA) * distance;

        rt[0] = rt[10] = mmi_applist_cos(angleBBB);
        rt[8] = mmi_applist_sin(angleBBB);
        rt[2] = -1 * rt[8];
    }
    
    temp = rt[2] * model[12] + rt[14];
    transform->m[0] = rt[0] + camera[8] * rt[2];
    transform->m[3] = 0;
    transform->m[6] = rt[0] * model[12] + rt[12] + camera[8] * temp + camera[12];
    transform->m[1] = camera[9] * rt[2];
    transform->m[4] = 1.0f;
    transform->m[7] = model[13] + rt[13] + camera[9] * temp + camera[13];
    transform->m[2] = camera[11] * rt[2];
    transform->m[5] = 0;
    transform->m[8] = camera[11] * temp + camera[15];
    
   *pos_z = rt[14];

    
    // adjust opacity
    if (offset > MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT + 10)
    {
        opacity_f = 1.0f - (offset - MMI_APPLIST_TORNADO_MENU_BEHIND_COUNT);
        if (opacity_f < 0)
        {
            opacity_f = 0;
        }    
    }
    else if (offset < -1 * MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT)
    {
        //opacity_f = 1.0f - (-1 * MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT - offset);
        opacity_f = 1.0f + MMI_APPLIST_TORNADO_MENU_AHEAD_COUNT + offset;
        if (opacity_f < 0)
        {
            opacity_f = 0;
        }
    }
    else
    {
        // We want the item far from the screen opacity near to 0.5,
        // and close to screen near to 1.
        // This code also relative to the number in a circle and the
        // total number of cell in screen. if you add more items,
        // you need to add enough if check
        if (offset > -16 && offset <= -8)
        {
            shift = APPLIST_ABS(offset - (-12));
        }
        else if (offset > -8  && offset <= 0)
        {
            shift = APPLIST_ABS(offset - (-4));
        }
        else if (offset > 0 && offset <= 8)
        {
            shift = APPLIST_ABS(offset - (4));
        }
        else if (offset > 8 && offset <= 16)
        {
            shift = APPLIST_ABS(offset - (12));
        }
        else if (offset > 16 && offset <= 24)
        {
            shift = APPLIST_ABS(offset - (20));
        }
        else
        {
            shift = 4;
        }
        //opacity_f = shift / 4 * 0.5 + 0.5;
        opacity_f = shift * 0.125f + 0.5f;
    }

    if (APPLIST_ABS(t) < 0.3f)
    {
        temp_t = APPLIST_ABS(t)/0.3f;
        transform->m[0] = temp_t  * transform->m[0] + (1 - temp_t) * 1;
        transform->m[1] = temp_t  * transform->m[1] ;
        transform->m[2] = temp_t  * transform->m[2] ;
        transform->m[3] = temp_t  * transform->m[3] ;
        transform->m[4] = temp_t  * transform->m[4] + (1 - temp_t) * 1;
        transform->m[5] = temp_t  * transform->m[5] ;
        transform->m[6] = temp_t  * transform->m[6] + (1 - temp_t) * orin_x;
        transform->m[7] = temp_t  * transform->m[7] + (1 - temp_t) * orin_y;
        transform->m[8] = temp_t  * transform->m[8] + (1 - temp_t) * 1;
    }


    // do Culling
    det = ((transform->m[0] * transform->m[4] * transform->m[8]) + (transform->m[6] * transform->m[1] * transform->m[5]) + (transform->m[3] * transform->m[7] * transform->m[2]) -
               (transform->m[3] * transform->m[1] * transform->m[8]) - (transform->m[0] * transform->m[7] * transform->m[5]) - (transform->m[6] * transform->m[4] * transform->m[2])) *
              ((transform->m[2] + transform->m[8]) * (transform->m[5] + transform->m[8]) * transform->m[8]);
    


    /* Change from column-major to row-major matrix */
    mmi_applist_barrel_transpose_3x3_matrix(transform->m);

    if (APPLIST_ABS(t) > 0.9)
    {
        temp_t = (APPLIST_ABS(t) - 0.9f)/0.1f;
        opacity_f = 1 - temp_t;
        if (opacity_f < 0)
        {
            opacity_f = 0;
        }
    }
    else if (t == 0)
    {
        opacity_f = 1.0f;
    }
    

    if (APPLIST_ABS(det) < 0.2f)
    {
        opacity_f = 0;
    }

    *opacity = (U8)(opacity_f * 255);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_TORNADO_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_ball
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_ball(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t, interpolate, opacity_f;
    float from_float = 0;
    float to_float = -180;
    S32 orin_x, orin_y, page_idx, index_x, index_y;
    float rotate_by_y[16], camera[16], model[16], total_project[16], out[16];
    float temp_t, det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);

    interpolate = (from_float) + (to_float - from_float) * t;

    mmi_applist_barrel_set_4x4_rotate_by_y(rotate_by_y, APPLIST_DEG_TO_RAD(interpolate));
    
    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;

    mmi_applist_barrel_set_camera(
                camera,
                1.0f,
                1.0f,
                LCD_WIDTH / 2,
                MMI_APPLIST_SLIDE_AREA_Y + MMI_APPLIST_SLIDE_AREA_HEIGHT /2,
                340.0f,
                340.0f + MMI_APPLIST_BARREL_BALL_RADIUS,
                0.0f,
                0.0f,
                0.0f);
    mmi_applist_barrel_set_4x4_ball_model(model, index_x, index_y);

    mmi_applist_barrel_4x4_multiply(rotate_by_y, model, out);
    mmi_applist_barrel_4x4_multiply(camera, out, total_project);

    *pos_z = total_project[14];

    /* Column major matrix multiplication */
    mmi_applist_barrel_init_3x3_matrix(transform->m, total_project);

    if (APPLIST_ABS(t) < 0.3f)
    {
        temp_t = APPLIST_ABS(t)/0.3f;
        transform->m[0] = (temp_t) * transform->m[0] + (1 - temp_t) * 1;
        transform->m[1] = (temp_t) * transform->m[1];
        transform->m[2] = (temp_t) * transform->m[2];
        transform->m[3] = (temp_t) * transform->m[3];
        transform->m[4] = (temp_t) * transform->m[4] + (1 - temp_t) * 1;
        transform->m[5] = (temp_t) * transform->m[5];
        transform->m[6] = (temp_t) * transform->m[6] + (1 - temp_t) * orin_x;
        transform->m[7] = (temp_t) * transform->m[7] + (1 - temp_t) * orin_y;
        transform->m[8] = (temp_t) * transform->m[8] + (1 - temp_t) * 1;
    } 


    // do Culling
    det = ((transform->m[0] * transform->m[4] * transform->m[8]) + (transform->m[6] * transform->m[1] * transform->m[5]) + (transform->m[3] * transform->m[7] * transform->m[2]) -
               (transform->m[3] * transform->m[1] * transform->m[8]) - (transform->m[0] * transform->m[7] * transform->m[5]) - (transform->m[6] * transform->m[4] * transform->m[2])) *
              ((transform->m[2] + transform->m[8]) * (transform->m[5] + transform->m[8]) * transform->m[8]);
    

    /* Change from column-major to row-major matrix */
    mmi_applist_barrel_transpose_3x3_matrix(transform->m);

    /* Opacity */
    if (APPLIST_ABS(t) > 0.9)
    {
        temp_t = (APPLIST_ABS(t) - 0.9f) / 0.1f;
        opacity_f = 1 - temp_t;
        if (opacity_f < 0)
        {
           opacity_f = 0;
        }
    }
    else
    {
        opacity_f = 1.0f;
    }
    

    if (APPLIST_ABS(det) < 0.2f)
    {
        opacity_f = 0;
    }

    *opacity = (U8)(opacity_f * 255);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_BALL_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_tilt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_tilt(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    mmi_applist_barrel_get_tilt_ext(cell_index, transform, opacity, pos_z, 0);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__


#ifndef __MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_wave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_wave(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    mmi_applist_barrel_get_tilt_ext(cell_index, transform, opacity, pos_z, 2);
}
#endif  //__MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__


#if !defined(__MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__) || !defined(__MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_tilt_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_get_tilt_ext(
        S32 cell_index,
        gdi_lt_matrix_struct *transform,
        U8 *opacity,
        float *pos_z,
        U8 photo_wall_type)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_applist_cell_struct *cell;
    float t, interpolate, opacity_f = 1.0f;
    float from_float = 0;
    float to_float = -30;
    S32 orin_x, orin_y, page_idx, index_x, index_y, direction = 1;
    float camera[16], rotate_by_y[16], model[16], total_project[16], out[16];
    float det;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cell = mmi_applist_get_cell_ptr(MMI_APPLIST_CELL_TYPE_PANEL, cell_index);

    t = mmi_applist_barrel_get_t(cell_index);
    
#if defined(__MMI_TOUCH_SCREEN__)
    direction = applist_p->pen_last_pos.x - applist_p->pen_down_pos.x > 0 ? -1 : 1;
#elif defined(__MMI_APPLIST_KEY_SUPPORT__)
    direction = applist_p->long_press_dir;
#endif

    if (photo_wall_type == 1)
    {
        to_float = 30;
    }
    
    if (t < 0.5f)
    {
        interpolate = from_float + (to_float - from_float) * mmi_applist_sin(t * APPLIST_PI);
    }
    else
    {
        interpolate = to_float * mmi_applist_sin(t * APPLIST_PI);
    }

    if (photo_wall_type == 0)
    {
        interpolate = -direction * APPLIST_ABS(interpolate);
    }

    mmi_applist_barrel_set_camera(
                camera,
                1.0f,
                1.0f,
                LCD_WIDTH / 2,
                MMI_APPLIST_SLIDE_AREA_HEIGHT /2,
                240.0f,
                240.0f,
                0.0f,
                0.0f,
                0.0f);

    mmi_applist_barrel_set_4x4_rotate_by_y(rotate_by_y, APPLIST_DEG_TO_RAD(interpolate));

    mmi_applist_barrel_4x4_multiply(camera, rotate_by_y, out);
    
    mmi_applist_get_panel_cell_location(
        cell_index, &page_idx, &index_x, &index_y);
    
    orin_x = index_x * MMI_APPLIST_CELL_WIDTH;
    orin_y = MMI_APPLIST_SLIDE_AREA_Y + index_y * MMI_APPLIST_CELL_HEIGHT;

    mmi_applist_barrel_set_4x4_translation(model,
        orin_x + LCD_WIDTH * t - LCD_WIDTH / 2,
        orin_y - MMI_APPLIST_SLIDE_AREA_HEIGHT / 2,
        0);

    mmi_applist_barrel_4x4_multiply(out, model, total_project);


    /* Column major matrix multiplication */
    mmi_applist_barrel_init_3x3_matrix(transform->m, total_project);


    // do Culling
    det = ((transform->m[0] * transform->m[4] * transform->m[8]) + (transform->m[6] * transform->m[1] * transform->m[5]) + (transform->m[3] * transform->m[7] * transform->m[2]) -
               (transform->m[3] * transform->m[1] * transform->m[8]) - (transform->m[0] * transform->m[7] * transform->m[5]) - (transform->m[6] * transform->m[4] * transform->m[2])) *
              ((transform->m[2] + transform->m[8]) * (transform->m[5] + transform->m[8]) * transform->m[8]);
    

    /* Change from column-major to row-major matrix */
    mmi_applist_barrel_transpose_3x3_matrix(transform->m);

    /* Opacity */
    if (APPLIST_ABS(det) < 0.2f)
    {
        opacity_f = 0;
    }

    *opacity = (U8)(opacity_f * 255);
}
#endif  //!defined(__MMI_APPLIST_BARREL_DISABLE_TILT_EFFECT__) || !defined(__MMI_APPLIST_BARREL_DISABLE_WAVE_EFFECT__)



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_auto_slide_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_auto_slide_back()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;
    
    if (applist_p->slide_region.slide_dir == MMI_APPLIST_DIR_LEFT)
    {
        mmi_applist_slide_to_page(mmi_applist_get_current_page_idx() + 1);
    }
    else
    {
        mmi_applist_slide_to_page(mmi_applist_get_current_page_idx() - 1);
    }

    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data();
    
    applist_p->mode = MMI_APPLIST_MODE_NORMAL;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_change_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_change_transform()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 max_type = sizeof(g_barrel_get_transform_func_array) / sizeof(transform_func);
    S32 curr_page = mmi_applist_get_current_page_idx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_barrel_type + 1 >= max_type)
        g_barrel_type = 0;
    else
        g_barrel_type++;
    
    WriteRecord(NVRAM_EF_APPLIST_BARREL_EFFECT_LID, 1, (void*)&g_barrel_type, 1, &error);

    applist_p->slide_type = MMI_APPLIST_SLIDE_BY_KEY;
    applist_p->mode = MMI_APPLIST_MODE_EFFECT_PREVIEW;
    
    if (curr_page + 1 >= mmi_applist_get_current_page_num())
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_LEFT;
        mmi_applist_slide_to_page(curr_page - 1);
    }
    else
    {
        applist_p->slide_region.slide_dir = MMI_APPLIST_DIR_RIGHT;
        mmi_applist_slide_to_page(curr_page + 1);
    }
        
    gui_cancel_timer(mmi_applist_update_anima_data);    
    mmi_applist_update_anima_data();
    gui_start_timer(MMI_APPLIST_BARREL_AUTO_SLIDE_BACK_DELAY, mmi_applist_barrel_auto_slide_back);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_applist_barrel_get_transform
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
transform_func mmi_applist_barrel_get_transform(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 max_type = sizeof(g_barrel_get_transform_func_array) / sizeof(transform_func);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    if (g_barrel_type >= max_type)
        return NULL;
    
    return g_barrel_get_transform_func_array[g_barrel_type];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_applist_load_barrel_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_applist_barrel_load_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 max_type = sizeof(g_barrel_get_transform_func_array) / sizeof(transform_func);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    ASSERT(max_type > 0);
    ReadRecord(NVRAM_EF_APPLIST_BARREL_EFFECT_LID, 1, (void*)&g_barrel_type, (S8)1, &error);

    if (g_barrel_type < 0 || g_barrel_type >= max_type)
        g_barrel_type = 0;
}


#endif /* __MMI_APPLIST_BARREL_SUPPORT__ */

