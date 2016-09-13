
/* begin: cx805_i2c.h ----- */
/* created 9/12/2016 by user ----------------------------------- */


#ifndef __CX805_I2C_H__
#define __CX805_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_hal.h>

/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */


/* ----- Prototypes --------------------------------------------------------- */
HAL_StatusTypeDef HAL_I2C_Init();
HAL_StatusTypeDef HAL_I2C_Write(uint8_t Addr, uint8_t *Data, uint8_t Lenght);
HAL_StatusTypeDef HAL_I2C_Read(uint8_t Addr, uint8_t *Data, uint8_t Lenght);

#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_I2C_H__ */

/* end: cx805_i2c.h ----- */
