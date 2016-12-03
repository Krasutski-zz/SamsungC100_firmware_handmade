/**
  ******************************************************************************
  * @file    uart.h
  * @author  DKrasutski@octonion.com
  * @version V1.0
  * @date    11/11/2016
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */

#ifndef __UART_H__
#define __UART_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void uarts_init(void);

void bsp_debug_write(const uint8_t *data, uint32_t lenght);
void bsp_debug_data_recived(const uint8_t *rx_data, uint32_t len);

void bsp_sds_write(const uint8_t *data, uint32_t lenght);
void bsp_sds_data_recived(const uint8_t *rx_data, uint32_t len);


#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __UART_H__ */

/* end: uart.h ----- */
