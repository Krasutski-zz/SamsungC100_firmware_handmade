/**
  ******************************************************************************
  * @file    bsp.h
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

#ifndef __BSP_H__
#define __BSP_H__

#ifdef __cplusplus
extern "C";
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "gpio.h"
#include "clocks.h"
#include "uart.h"

/* Exported types ------------------------------------------------------------*/
typedef enum bsp_result_e {

    BSP_RESULT_OK = 0U,
    BSP_RESULT_ERROR = 1U,

} bsp_result_t;
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

bool bsp_is_button1_pressed(void);

void bsp_delay_ms(uint32_t delay_ms);
void bsp_init();

void bsp_debug_write(const uint8_t *data, uint32_t lenght);
void bsp_debug_data_recived(const uint8_t *rx_data, uint32_t len);


#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __BSP_H__ */

/* end: bsp.h ----- */
