/* begin: gpio.c ------------------------------------------------------------ */
/* created 11/11/2016 by dkrasutski@octonion.com ---------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include "gpio.h"
#include <cx805_gpio.h>
/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */


/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */


/* ----- Local functions ---------------------------------------------------- */

/* =====> Implementation ---------------------------------------------------- */
inline void bsp_red_led_toggle(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}

/* -------------------------------------------------------------------------- */

inline void bsp_red_led_on(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
}

/* -------------------------------------------------------------------------- */

inline void bsp_red_led_off(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

/* -------------------------------------------------------------------------- */

inline void bsp_green_led_toggle(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
}

/* -------------------------------------------------------------------------- */

inline void bsp_green_led_on(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
}

/* -------------------------------------------------------------------------- */

inline void bsp_green_led_off(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
}

/* -------------------------------------------------------------------------- */

inline void bsp_blue_led_toggle(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
}

/* -------------------------------------------------------------------------- */

inline void bsp_blue_led_on(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
}

/* -------------------------------------------------------------------------- */

inline void bsp_blue_led_off(void) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
}

/* -------------------------------------------------------------------------- */

void gpios_init() {

    GPIO_PowerControl_t PowerParams;

    PowerParams.Group0_DriveControl = DRIVE_4_8MA;
    PowerParams.Group0_DC_Control = DC_10UA_PULL_UP;
    PowerParams.Group1_DriveControl = DRIVE_4_8MA;
    PowerParams.Group1_DC_Control = DC_10UA_PULL_UP;
    PowerParams.Group2_DriveControl = DRIVE_4_8MA;
    PowerParams.Group2_DC_Control = DC_10UA_PULL_UP;
    PowerParams.Group3_DriveControl = DRIVE_4_8MA;
    PowerParams.Group3_DC_Control = DC_10UA_PULL_UP;
    PowerParams.EnableAlternateDCs = GPIO_ALTERNATE_DC_PORTA_EN;
    HAL_GPIO_SetPower(&PowerParams);

    HAL_GPIO_SetPower_GPIOE(GPIO_PIN_2 |GPIO_PIN_3, DRIVE_E_0_8MA, DC_10UA_PULL_UP);

}



/* end: gpio.c ----- */

