#include <cx805_gpio.h>
#include <cx805_uart.h>
#include <cx805_i2c.h>
#include <cx805_clk.h>

#include "cx20524.h"

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

    HAL_ClockPeriphControl(
                           PLL_CLOCK_ARM_CORE |
                           PLL_CLOCK_AM |
                           PLL_CLOCK_SLP |
                           PLL_CLOCK_DEBUG_PORT |
                           PLL_CLOCK_SDS_PORT
                           , ENABLE);

    //HAL_PLL_Init(PLL_P_DIV_2, PLL_Q_DIV_2, 10);

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


    uint8_t PowerOn[] = {PM_CONTROL, PMCR_PHONE_ON};
    if(HAL_I2C_Write(0x90, PowerOn, sizeof(PowerOn)) == HAL_OK)
    {
        sprintf((char*)str,"Power On! Let's work.\r\n");
        HAL_UART_Transmit(&DebugPort, str, strlen((char*)str));

        uint8_t RdReg[16] ={0x00};
        HAL_I2C_Read(0x90, RdReg, sizeof(RdReg));
        for(int i=0; i<16; i++)
        {
            sprintf((char*)str,"REG[%02X]=0x%02X\r\n", i, RdReg[i+1]);
            HAL_UART_Transmit(&DebugPort, str, strlen((char*)str));
        }
    }


    uint32_t Clock = HAL_GetFreq();
    sprintf((char*)str,"ARM Core Freq=%d\r\b", Clock);
    HAL_UART_Transmit(&DebugPort, str, strlen((char*)str));
    HAL_UART_Transmit(&SDSPort, str, strlen((char*)str));



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

void Default_Handler( void );
void Default_Handler( void )
{
	for( ;; );
}
