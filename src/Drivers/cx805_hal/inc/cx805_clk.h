/**
  ******************************************************************************
  * @file    cx805_clk.h
  * @author  DKrasutski@gmail.com
  * @version V1.0
  * @date
  * @brief   This file contains all the functions prototypes for the HAL
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 Denis Krasutski </center></h2>
  *
  ******************************************************************************
  */

#ifndef __CX805_CLK_H__
#define __CX805_CLK_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Includes ------------------------------------------------------------------*/
#include <cx805_hal.h>

/* Exported types ------------------------------------------------------------*/
typedef enum PLL_P_Div
{
    PLL_P_DIV_1 = 0U,
    PLL_P_DIV_2,
    PLL_P_DIV_3,
    PLL_P_DIV_4
}PLL_P_Div_TypeDef;

typedef enum PLL_Q_Div
{
    PLL_Q_DIV_1 = 0U,
    PLL_Q_DIV_2,
    PLL_Q_DIV_3,
    PLL_Q_DIV_4
}PLL_Q_Div_TypeDef;


/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define PLL_P_DIV_MASK          0x0300
#define PLL_Q_DIV_MASK          0x0060
#define PLL_N_MULT_MASK         0x001F

#define PLL_P_DIV_SHIFT         8U
#define PLL_Q_DIV_SHIFT         5U
#define PLL_N_MULT_SHIFT        0U


#define PLL_CLOCK_ARM_CORE      ((uint16_t) 0x0001)
#define PLL_CLOCK_AM            ((uint16_t) 0x0002)
#define PLL_CLOCK_SLP           ((uint16_t) 0x0004)
#define PLL_CLOCK_SIM           ((uint16_t) 0x0008)
#define PLL_CLOCK_PWM           ((uint16_t) 0x0010)
#define PLL_CLOCK_TIMER_B       ((uint16_t) 0x0020)
#define PLL_CLOCK_CRC           ((uint16_t) 0x0040)
#define PLL_CLOCK_PTGA          ((uint16_t) 0x0080)
#define PLL_CLOCK_PTCB          ((uint16_t) 0x0100)
#define PLL_CLOCK_DEBUG_PORT    ((uint16_t) 0x0200)
#define PLL_CLOCK_SDS_PORT      ((uint16_t) 0x0400)
#define PLL_CLOCK_AUTOBAUD      ((uint16_t) 0x0800)
#define PLL_CLOCK_DMA1          ((uint16_t) 0x1000)
#define PLL_CLOCK_DMA2          ((uint16_t) 0x2000)
#define PLL_CLOCK_DSP           ((uint16_t) 0x4000)
#define PLL_CLOCK_IRDA_ESCP     ((uint16_t) 0x8000)

/* Exported functions --------------------------------------------------------*/
void HAL_PLL_Init(PLL_P_Div_TypeDef P, PLL_Q_Div_TypeDef Q, uint32_t N);
uint32_t HAL_GetFreq();
void HAL_ClockPeriphControl(uint16_t Target, FunctionalState State);
#ifdef __cplusplus
 }
#endif /* __cplusplus */


#endif /* __CX805_CLK_H__ */

/* end: cx805_clk.h ----- */
