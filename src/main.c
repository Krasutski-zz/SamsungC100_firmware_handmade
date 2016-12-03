

#include <cx805_i2c.h>


#include "cx20524.h"

#include <stdio.h>
#include <string.h>

#include "bsp.h"

#include "logger/logger.h"


void delay(volatile  uint32_t delay)
{
    while(delay--)
    {
        for(int n = delay; n!=0; n--);
    }
}

int main()
{
    bsp_init();


    int n = 0;

    uint8_t PowerOn[] = {PM_CONTROL, PMCR_PHONE_ON};
    if(HAL_I2C_Write(CX20524_I2C_ADDR << 1, PowerOn, sizeof(PowerOn)) == HAL_OK)
    {
       INFO("Power On! Let's work.\r\n");

       /* Debug dump of regs */
        uint8_t RdReg[16] ={0x00};
        HAL_I2C_Read(CX20524_I2C_ADDR << 1, RdReg, sizeof(RdReg));
        for(int i=0; i<15; i++)
        {
            INFO("REG[%02X]=0x%02X\r\n", i, RdReg[i+1]);
        }
    }

    uint32_t Clock = bsp_get_core_freq();
    INFO("ARM Core Freq=%d Hz\r\n", Clock);

    for(;;)
    {
        ++n;
        bsp_blue_led_on();
        delay(500);
        bsp_blue_led_off();
        delay(500);

        bsp_green_led_on();
        delay(500);
        bsp_green_led_off();
        delay(500);

        bsp_red_led_on();
        delay(500);
        bsp_red_led_off();
        delay(500);
        INFO("Test Message DEBUG %d\r\n", n);
    }

    //return 0;
}

void Default_Handler( void );
void Default_Handler( void )
{
	for( ;; );
}
