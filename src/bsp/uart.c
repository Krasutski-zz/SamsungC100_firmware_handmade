/* begin: uart.c ----- */
/* created 11/11/2016 by dkrasutski@octonion.com ---------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include "uart.h"
#include "bsp.h"
#include <cx805_uart.h>
/* ----- Types -------------------------------------------------------------- */


/* ----- Settings ----------------------------------------------------------- */
#define UART_TIMEOUT_MS                                 (1000U)
#define UART1_RX_BUFFER_SIZE                            (16)
#define UART3_RX_BUFFER_SIZE                            (16)

/* ----- Global variables --------------------------------------------------- */
/* ----- Local functions ---------------------------------------------------- */

static UART_HandleTypeDef DebugPort;
static UART_HandleTypeDef SDSPort;
/* ----- HAL callbacks  ---------------------------------------------------- */

/* -------------------------------------------------------------------------- */



/* =====> Implementation ---------------------------------------------------- */

void uarts_init() {

    DebugPort.Instance = (SerialPort_TypeDef*)DEBUG_UART_BASE_ADDR;
    DebugPort.Init.BaudRate = 115200;
    DebugPort.Init.WordLength = UART_WORDLENGTH_8B;
    DebugPort.Init.StopBits = UART_STOPBITS_1;
    DebugPort.Init.Parity = UART_PARITY_NONE;
    DebugPort.Init.Mode = UART_MODE_TX_RX;

    HAL_UART_Init(&DebugPort);

    SDSPort.Instance = (SerialPort_TypeDef*)SDS_SERIAL_BASE_ADDR;
    SDSPort.Init.BaudRate = 115200;
    SDSPort.Init.WordLength = UART_WORDLENGTH_8B;
    SDSPort.Init.StopBits = UART_STOPBITS_1;
    SDSPort.Init.Parity = UART_PARITY_NONE;
    SDSPort.Init.Mode = UART_MODE_TX_RX;

    HAL_UART_Init(&SDSPort);
}

/* -------------------------------------------------------------------------- */

void bsp_debug_write(const uint8_t *data, uint32_t lenght) {
    HAL_UART_Transmit(&DebugPort, data, lenght);
}

/* -------------------------------------------------------------------------- */

__weak void bsp_debug_data_recived(const uint8_t *rx_data, uint32_t len) {

}

/* -------------------------------------------------------------------------- */

void bsp_sds_write(const uint8_t *data, uint32_t lenght) {
    HAL_UART_Transmit(&SDSPort, data, lenght);
}

/* -------------------------------------------------------------------------- */

__weak void bsp_sds_data_recived(const uint8_t *rx_data, uint32_t len) {

}


/* -------------------------------------------------------------------------- */


/* end: uart.c ----- */

