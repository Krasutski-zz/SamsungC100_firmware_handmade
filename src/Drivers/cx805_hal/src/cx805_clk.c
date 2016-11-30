
/* begin: cx805_clk.c ----- */
/* created 9/16/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_clk.h>

/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */


/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */
static PLL_TypeDef *const _PLL = (PLL_TypeDef *)PLL_BASE_ADDR;
static ClockControl_TypeDef *const _ClockControl = (ClockControl_TypeDef*)CLOCK_CONTROL_BASE_ADDR;
/* ----- Local functions ---------------------------------------------------- */


/* =====> Implementation ---------------------------------------------------- */


#define PLL_SET_DEFAULT PLL_CONTROL=0x0113
#define PLL_SET(div1, div2, mult)
//PLL_CONTROL=(PLL_CONTROL_DIV_P_MASK & div1)|(PLL_CONTROL_DIV_Q_MASK & div2)|(PLL_CONTROL_DIV_N_MASK & mult)

void HAL_PLL_Init(PLL_P_Div_TypeDef P, PLL_Q_Div_TypeDef Q, uint32_t N)
{
    _PLL->CONTROL = (uint16_t)(P << PLL_P_DIV_SHIFT |
                                Q << PLL_Q_DIV_SHIFT |
                                 (N & PLL_N_MULT_MASK));
}

uint32_t HAL_GetFreq()
{
    uint32_t P = (_PLL->CONTROL & PLL_P_DIV_MASK) >> PLL_P_DIV_SHIFT;
    uint32_t Q = (_PLL->CONTROL & PLL_Q_DIV_MASK) >> PLL_Q_DIV_SHIFT;
    uint32_t N = (_PLL->CONTROL & PLL_N_MULT_MASK) >> PLL_N_MULT_SHIFT;

    //TODO Check zero

    return SYSTEM_CLK / P * N / Q;
}

void HAL_ClockPeriphControl(uint16_t Target, FunctionalState State)
{
    if(State == DISABLE)
    {
        _ClockControl->CONTROL1 &= ~Target;
    }
    else
    {
        _ClockControl->CONTROL1 |= Target;
    }
}

/* end: cx805_clk.c ----- */

