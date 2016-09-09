
/* begin: cx805_uart.c ----- */
/* created 9/9/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_uart.h>

/* ----- Types -------------------------------------------------------------- */

/* ----- Settings ----------------------------------------------------------- */
#define UART_CLK        3900000U

/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */


/* ----- Local functions ---------------------------------------------------- */


/* =====> Implementation ---------------------------------------------------- */

HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *Handle)
{
    if(Handle == NULL || Handle->Instance == NULL)
    {
        return HAL_ERROR;
    }

    if(Handle->Init.Mode & UART_MODE_TX)
    {
        Handle->Instance->TX_CONTROL &= ~UART_CONTROL_EN;
        Handle->Instance->TX_CONTROL &= ~UART_CONTROL_PARAMS_MASK;

        Handle->Instance->TX_CONTROL |= (uint16_t)Handle->Init.WordLength;
        Handle->Instance->TX_CONTROL |= (uint16_t)Handle->Init.StopBits;
        Handle->Instance->TX_CONTROL |= (uint16_t)Handle->Init.Parity;

        Handle->Instance->TX_BR =(uint16_t) (Handle->Init.BaudRate / UART_CLK);

        Handle->Instance->TX_CONTROL |= UART_CONTROL_PIO;
        Handle->Instance->TX_CONTROL |= UART_CONTROL_EN;
    }

    if(Handle->Init.Mode & UART_MODE_RX)
    {
        Handle->Instance->RX_CONTROL &= ~UART_CONTROL_EN;
        Handle->Instance->RX_CONTROL &= ~UART_CONTROL_PARAMS_MASK;

        Handle->Instance->RX_CONTROL |= (uint16_t)Handle->Init.WordLength;
        Handle->Instance->RX_CONTROL |= (uint16_t)Handle->Init.StopBits;
        Handle->Instance->RX_CONTROL |= (uint16_t)Handle->Init.Parity;

        Handle->Instance->RX_BR =(uint16_t) (Handle->Init.BaudRate / UART_CLK);

        Handle->Instance->RX_CONTROL |= UART_CONTROL_PIO;
        Handle->Instance->RX_CONTROL |= UART_CONTROL_EN;
    }

    return HAL_OK;
}

HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *Handle, const uint8_t *pData, uint32_t Lenght)
{
    if( (Handle == NULL) || (pData == NULL) )
    {
        return HAL_ERROR;
    }

    for(uint32_t i=0; i<Lenght; ++i)
    {
        /*TODO: search info about status register */
        while(Handle->Instance->TX_STATUS & 0x0001);
        Handle->Instance->TX_HOLDING = pData[i];
    }

    return HAL_OK;
}

/* end: cx805_uart.c ----- */


