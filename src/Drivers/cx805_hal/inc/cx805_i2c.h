/**
  ******************************************************************************
  * @file    cx805_i2c.h
  * @author  DKrasutski@gmail.com
  * @version V1.0
  * @date
  * @brief   This file contains all the functions prototypes for the I2C
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */
#ifndef __CX805_I2C_H__
#define __CX805_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
/* Includes ------------------------------------------------------------------*/
#include <cx805_hal.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
HAL_StatusTypeDef HAL_I2C_Init();
HAL_StatusTypeDef HAL_I2C_Write(uint8_t Addr, uint8_t *Data, uint8_t Lenght);
HAL_StatusTypeDef HAL_I2C_Read(uint8_t Addr, uint8_t *Data, uint8_t Lenght);

#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_I2C_H__ */

/* end: cx805_i2c.h ----- */
