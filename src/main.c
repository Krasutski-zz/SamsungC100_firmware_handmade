#include <cx805_gpio.h>
#include <cx805_uart.h>

#include <stdio.h>
#include <string.h>

UART_HandleTypeDef DebugPort;
UART_HandleTypeDef SDSPort;

void delay(volatile  uint32_t delay)
{
    while(delay--)
    {
        for(int n = delay; n!=0; n--);
    }
}

int main()
{
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

    int n = 0;
    uint8_t str[64];

    for(;;)
    {
        ++n;
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
        delay(500);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
        delay(500);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        delay(500);

        sprintf((char*)str,"Test Message DEBUG %d\r\n", n);
        HAL_UART_Transmit(&DebugPort, str, strlen((char*)str));

        sprintf((char*)str,"Test Message SDS %d\r\n", n);
        HAL_UART_Transmit(&SDSPort, str, strlen((char*)str));
    }

    //return 0;
}
