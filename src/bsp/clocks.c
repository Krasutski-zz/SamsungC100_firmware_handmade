/* begin: clocks.c ---------------------------------------------------------- */
/* created 11/11/2016 by dkrasutski.octonion@com ---------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_clk.h>
#include "clocks.h"
#include "bsp.h"
/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */


/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */


/* ----- Local functions ---------------------------------------------------- */


/* =====> Implementation ---------------------------------------------------- */

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
  *            PLL_M                          = 1
  *            PLL_N                          = 40
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
void clocks_init(void)
{

    HAL_ClockPeriphControl(
//                           PLL_CLOCK_ARM_CORE |
//                           PLL_CLOCK_AM |
//                           PLL_CLOCK_SLP |
//                           PLL_CLOCK_PTGA |
//                           PLL_CLOCK_PTGB |
                           //PLL_CLOCK_DSP |
                           PLL_CLOCK_DEBUG_PORT |
                           PLL_CLOCK_SDS_PORT
                           , ENABLE);

    HAL_PLL_Init(PLL_P_DIV_1, PLL_Q_DIV_2, 11);
}

/* -------------------------------------------------------------------------- */

uint32_t bsp_get_core_freq(void){
    return HAL_GetFreq();
}

/* -------------------------------------------------------------------------- */


/* end: clocks.c ----- */

