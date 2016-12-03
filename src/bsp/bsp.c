
/* begin: bsp.c ------------------------------------------------------------- */
/* created 11/11/2016 by dkrasutski@octonion.com ---------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include "bsp.h"
#include <cx805_uart.h>

#include "gpio.h"
#include "uart.h"
#include "clocks.h"
/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */


/* ----- Global variables --------------------------------------------------- */

/* ----- Local variables ---------------------------------------------------- */


/* ----- Local functions ---------------------------------------------------- */


/* =====> Implementation ---------------------------------------------------- */

/* -------------------------------------------------------------------------- */

bool bsp_is_button1_pressed() {

    return false;
}

/* -------------------------------------------------------------------------- */


void bsp_delay_ms(uint32_t delay_ms) {
}
/* -------------------------------------------------------------------------- */

uint32_t  bsp_get_tick_ms(void) {
    return 0;
}


/* -------------------------------------------------------------------------- */

void bsp_init() {

    gpios_init();
    clocks_init();
    uarts_init();
}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    static uint8_t output_line[64];

    sprintf(output_line, "\r\n>>Assert:%s:%d\r\n", file, line);

    bsp_debug_wite(output_line);
}
#endif

/* end: bsp.c ----- */

