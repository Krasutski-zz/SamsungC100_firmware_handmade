/**
  ******************************************************************************
  * @file    cx805_uart.h
  * @author  DKrasutski@gmail.com
  * @version V1.0
  * @date    9/9/2016
  * @brief   This file contains all the functions prototypes for the UART
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */
#ifndef __CX805_UART_H__
#define __CX805_UART_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <cx805_hal.h>

/* Exported types ------------------------------------------------------------*/

/** @defgroup UART_Word_Length UART Word Length
* @{
*/
#define UART_WORDLENGTH_7B                  ((uint16_t)0x0004)
#define UART_WORDLENGTH_8B                  ((uint16_t)0x0000)
/**
* @}
*/

/** @defgroup UART_Stop_Bits UART Number of Stop Bits
* @{
*/
#define UART_STOPBITS_1                     ((uint16_t)0x0000)
#define UART_STOPBITS_2                     ((uint16_t)0x0040)
/**
* @}
*/

/** @defgroup UART_Parity UART Parity
* @{
*/
#define UART_PARITY_NONE                    ((uint16_t)0x0000)
#define UART_PARITY_EVEN                    ((uint16_t)0x0008)
#define UART_PARITY_ODD                     ((uint16_t)0x0018)
#define UART_PARITY_SPACE                   ((uint16_t)0x0028)
#define UART_PARITY_MARK                    ((uint16_t)0x0038)
/**
* @}
*/

/** @defgroup UART_Mode UART Transfer Mode
* @{
*/
#define UART_MODE_RX                        ((uint32_t)0x00000001)
#define UART_MODE_TX                        ((uint32_t)0x00000002)
#define UART_MODE_TX_RX                     ((uint32_t)0x00000003)
/**
* @}
*/

#define UART_CONTROL_PARAMS_MASK            ((uint16_t)0x007E)
#define UART_CONTROL_EN                     ((uint16_t)0x0001)
#define UART_CONTROL_PIO                    ((uint16_t)0x0002)
/**
* @brief UART Init Structure definition
*/
typedef struct
{
    uint32_t BaudRate;                  /*!< This member configures the UART communication baud rate.
                                            Note: Max uart baudrate 230.4 kbps */

    uint32_t WordLength;                /*!< Specifies the number of data bits transmitted or received in a frame.
                                            This parameter can be a value of @ref UART_Word_Length */

    uint32_t StopBits;                  /*!< Specifies the number of stop bits transmitted.
                                            This parameter can be a value of @ref UART_Stop_Bits */

    uint32_t Parity;                    /*!< Specifies the parity mode.
                                            This parameter can be a value of @ref UART_Parity */

    uint32_t Mode;                      /*!< Specifies whether the Receive or Transmit mode is enabled or disabled.
                                             This parameter can be a value of @ref UART_Mode */
}UART_InitTypeDef;

/**
* @brief  UART handle Structure definition
*/
typedef struct
{
    SerialPort_TypeDef  *Instance;      /*!< UART registers base address        */
    UART_InitTypeDef    Init;           /*!< UART communication parameters      */

}UART_HandleTypeDef;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/

HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *Handle);
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *Handle, const uint8_t *pData, uint32_t Lenght);
#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_UART_H__ */

/* end: cx805_uart.h ----- */
