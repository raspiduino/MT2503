#ifndef __IGV5LIGHT_H
#define __IGV5LIGHT_H

#define LIGHT_NUM_MAX 4

#include "IGV5Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!****************************************************************************
 @Struct      EPODLight
 @brief       Enum for the POD format light types
******************************************************************************/
typedef enum {
	ePODPoint=0,	 /*!< Point light */
	ePODDirectional, /*!< Directional light */
	ePODSpot		 /*!< Spot light */
} EPODLight;


struct light {
	EPODLight type;
	Vec3 lightPosDir;
	Vec4 lightColor;
};

typedef struct {
	unsigned lightCount;
	struct light aryLight[LIGHT_NUM_MAX];
} IGV5Light;

#ifdef __cplusplus
}
#endif

#endif