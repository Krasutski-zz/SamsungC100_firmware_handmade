/**
  ******************************************************************************
  * @file    cx805_gpio.h
  * @author  DKrasutski@gmail.com
  * @version V1.0
  * @date    9/7/2016
  * @brief   This file contains all the functions prototypes for the
  *          GPIO driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */
#ifndef __CX805_GPIO_H__
#define __CX805_GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <cx805_hal.h>

/* Exported types ------------------------------------------------------------*/
/**
* @brief  GPIO Bit SET and Bit RESET enumeration
*/
typedef enum
{
    GPIO_PIN_RESET = 0,
    GPIO_PIN_SET
}GPIO_PinState_t;

/**
* @brief  GPIO Port mode enumeration
*/
typedef enum
{
    GPIO_PIN_INPUT = 0,
    GPIO_PIN_OUTPUT
}GPIO_PinMode_t;

/**
* @brief  GPIO Port list enumeration
*/
typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
}GPIO_Port_t;

/**
* @brief  GPIO DC control list mode apply for A-C ports
*/
typedef enum
{
    DRIVE_0_8MA = 0x00,
    DRIVE_2_8MA = 0x01,
    DRIVE_4_8MA = 0x02,
    DRIVE_6_8MA = 0x03,
    DRIVE_10_8MA = 0x04,
    DRIVE_12_8MA = 0x05,
    DRIVE_14_8MA = 0x06,
    DRIVE_16_8MA = 0x07,
}GPIO_DriveControl;

/**
* @brief  GPIO DC control list mode (A-E)
*/
typedef enum
{
    DC_NO_PULL = 0x00,
    DC_10UA_PULL_DOWN = 0x01,
    DC_100UA_PULL_UP = 0x02,
    DC_10UA_PULL_UP = 0x03,
}GPIO_DC_Control;

/**
* @brief  GPIO DC control list mode apply for E port
*/
typedef enum
{
    DRIVE_E_0_8MA = 0x00,
    DRIVE_E_4_8MA = 0x01,
    DRIVE_E_10_8MA = 0x02,
    DRIVE_E_14_8MA = 0x04,
}GPIO_DriveControl_PortE;

/**
* @brief  GPIO power control paramaters, except PortE
*/
typedef struct
{
    uint32_t Group0_DriveControl;
    uint32_t Group1_DriveControl;
    uint32_t Group2_DriveControl;
    uint32_t Group3_DriveControl;
    uint32_t Group0_DC_Control;
    uint32_t Group1_DC_Control;
    uint32_t Group2_DC_Control;
    uint32_t Group3_DC_Control;
    uint32_t EnableAlternateDCs;    /*!< @ref GPIO_Alternate_DC */
}GPIO_PowerControl_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/** @defgroup GPIO_pins_define GPIO pins define
* @{
*/
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
/**
* @}
*/

/** @defgroup GPIO_Alternate_DC enable list
* @{
*/
#define GPIO_ALTERNATE_DC_PORTA_EN     ((uint16_t)0x0004)
#define GPIO_ALTERNATE_DC_PORTB_EN     ((uint16_t)0x0008)
#define GPIO_ALTERNATE_DC_PORTC_EN     ((uint16_t)0x0400)
/**
* @}
*/

/** @defgroup GPIO bit shift for confirure gpoups:0123
* @{
*/
#define GPIO_GROUP10_G1_DRIVE_SHIFT (12U)
#define GPIO_GROUP10_G0_DRIVE_SHIFT (4U)
#define GPIO_GROUP10_G1_DC_SHIFT    (8U)
#define GPIO_GROUP10_G0_DC_SHIFT    (0U)
#define GPIO_GROUP32_G3_DRIVE_SHIFT (12U)
#define GPIO_GROUP32_G2_DRIVE_SHIFT (4U)
#define GPIO_GROUP32_G3_DC_SHIFT    (8U)
#define GPIO_GROUP32_G2_DC_SHIFT    (0U)
/**
* @}
*/

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
GPIO_PinState_t HAL_GPIO_ReadPin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin, GPIO_PinState_t PinState);
void HAL_GPIO_TogglePin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_Init(GPIO_Port_t GPIOx, uint16_t GPIO_Pin, GPIO_PinMode_t Mode);
void HAL_GPIO_SetPower(GPIO_PowerControl_t *PowerParams);
void HAL_GPIO_SetPower_GPIOE(uint16_t GPIO_Pin, GPIO_DriveControl_PortE DriveControl, GPIO_DC_Control DC_Mode);
#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_GPIO_H__ */

/* end: cx805_gpio.h ----- */
