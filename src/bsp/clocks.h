/**
  ******************************************************************************
  * @file    clocks.h
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

#ifndef __CLOCKS_H__
#define __CLOCKS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void clocks_init(void);
uint32_t bsp_get_core_freq(void);


#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CLOCKS_H__ */

/* end: clocks.h ----- */
