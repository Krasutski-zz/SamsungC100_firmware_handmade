/**
  ******************************************************************************
  * @file    cx805_hal.h
  * @author  DKrasutski@gmail.com
  * @version V1.0
  * @date    9/7/2016
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */
#ifndef __CX805_HAL_H__
#define __CX805_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>

#include <cx805.h>

/* Exported types ------------------------------------------------------------*/
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

/* Exported constants --------------------------------------------------------*/
#define SYSTEM_CLK        3900000U
/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_HAL_H__ */

/* end: cx805_hal.h ----- */
