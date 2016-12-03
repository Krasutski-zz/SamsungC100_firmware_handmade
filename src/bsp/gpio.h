/**
  ******************************************************************************
  * @file    gpio.h
  * @author  DKrasutski@gmail.com
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

#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C";
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void gpios_init(void);

void bsp_blue_led_off(void);
void bsp_blue_led_on(void);
void bsp_blue_led_toggle(void);
void bsp_green_led_off(void);
void bsp_green_led_on(void);
void bsp_green_led_toggle(void);
void bsp_red_led_off(void);
void bsp_red_led_on(void);
void bsp_red_led_toggle(void);

#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __GPIO_H__ */

/* end: gpio.h ----- */
