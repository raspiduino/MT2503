#ifndef __DRV_FEATURES_SPI_H__
#define __DRV_FEATURES_SPI_H__

#include "drv_features_chip_select.h"

#if defined(DRV_SPI_6268_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
    #define DRV_SPI_COMMAND
#elif defined(DRV_SPI_6236_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
    #define  DRV_SPI_GMC_ARBITRATE
     #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON
#elif defined(DRV_SPI_6276_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
    #define  DRV_SPI_GMC_ARBITRATE
    #define  DRV_SPI_PAD_MACRO_SELECT
     #define DRV_SPI_COMMAND
    #define  DRV_SPI_PDN_ON
#elif defined(DRV_SPI_6256_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL    
   #define  DRV_SPI_GMC_ARBITRATE
    #define DRV_SPI_PAD_MACRO_SELECT   
    #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON
#elif defined(DRV_SPI_6255_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL   
    #define DRV_SPI_GMC_ARBITRATE
    #define DRV_SPI_PAD_MACRO_SELECT  
    #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON
#elif defined(DRV_SPI_6250_SERIES)
    #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
    #define DRV_SPI_GMC_ARBITRATE  
    #define DRV_SPI_PAD_MACRO_SELECT    
     #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON 
    #define DRV_SPI_SYS_PDN  // MCU/AP SYS  control  
#elif defined(DRV_SPI_6260_SERIES)
   #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
   #define DRV_SPI_PAD_MACRO_SELECT
   #define DRV_SPI_SINGLE_PAD_SUPPORT /* ONLY ONE PAD support in 6260 */
   #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON 
    #define DRV_SPI_SYS_PDN  // MCU/AP SYS  control
#elif defined(DRV_SPI_6261_SERIES)
   #define DRV_SPI_SUPPORT
    #define DRV_SPI_HAL
   #define DRV_SPI_PAD_MACRO_SELECT
   #define DRV_SPI_SINGLE_PAD_SUPPORT /* ONLY ONE PAD support in 6260 */
   #define DRV_SPI_COMMAND
    #define DRV_SPI_PDN_ON 
    #define DRV_SPI_SYS_PDN  // MCU/AP SYS  control
#endif


#endif
