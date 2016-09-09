
/* begin: cx805_hal.h ----- */
/* created 9/7/2016 by user ----------------------------------- */


#ifndef __CX805_HAL_H__
#define __CX805_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ----- Includes ----------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>

#include <cx805.h>

/* ----- Types -------------------------------------------------------------- */

/**
  * @brief  HAL Status structures definition
  */
typedef enum
{
  HAL_OK       = 0x00,
  HAL_ERROR    = 0x01,
  HAL_BUSY     = 0x02,
  HAL_TIMEOUT  = 0x03
} HAL_StatusTypeDef;

typedef enum
{
  DISABLE = 0,
  ENABLE = !DISABLE
} FunctionalState;

/* ----- Settings ----------------------------------------------------------- */
#ifndef ASSERT
#define ASSERT(n)
#endif
/* ----- Prototypes --------------------------------------------------------- */

#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_HAL_H__ */

/* end: cx805_hal.h ----- */
