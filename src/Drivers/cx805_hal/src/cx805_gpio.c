/* begin: cx805_gpio.c ----- */
/* created 9/7/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_gpio.h>

/* ----- Types -------------------------------------------------------------- */

/* ----- Global variables --------------------------------------------------- */

/* ----- Local variables ---------------------------------------------------- */

static GPIO_TypeDef *_GPIO = (GPIO_TypeDef *)GPIO_BASE_ADDR;

/* Lets use this table, this allow fast acces to control registers */
struct
{
    uint16_t *CTL;
    uint16_t *DAT;
}_GPIO_Table[] =
{
    [GPIOA] = {(uint16_t*)(GPIO_BASE_ADDR + 0x04), (uint16_t*)(GPIO_BASE_ADDR + 0x0C)},
    [GPIOB] = {(uint16_t*)(GPIO_BASE_ADDR + 0x06), (uint16_t*)(GPIO_BASE_ADDR + 0x0E)},
    [GPIOC] = {(uint16_t*)(GPIO_BASE_ADDR + 0x08), (uint16_t*)(GPIO_BASE_ADDR + 0x10)},
    [GPIOD] = {(uint16_t*)(GPIO_BASE_ADDR + 0x0A), (uint16_t*)(GPIO_BASE_ADDR + 0x12)},
    [GPIOE] = {(uint16_t*)(GPIO_BASE_ADDR + 0x1A), (uint16_t*)(GPIO_BASE_ADDR + 0x1C)},
};

/* ----- Local functions ---------------------------------------------------- */

/* =====> Implementation ---------------------------------------------------- */

GPIO_PinState_t HAL_GPIO_ReadPin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin)
{
    return (*_GPIO_Table[GPIOx].DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void HAL_GPIO_WritePin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin, GPIO_PinState_t PinState)
{
    if(PinState == GPIO_PIN_RESET)
    {
        *_GPIO_Table[GPIOx].DAT = GPIO_Pin;
    }
    else
    {
        *_GPIO_Table[GPIOx].DAT = (GPIO_Pin << 8U) | GPIO_Pin;
    }
}

void HAL_GPIO_TogglePin(GPIO_Port_t GPIOx, uint16_t GPIO_Pin)
{
    uint16_t temp = *_GPIO_Table[GPIOx].DAT;

    temp ^= GPIO_Pin << 8U;
    temp |= GPIO_Pin;

    *_GPIO_Table[GPIOx].DAT = temp;
}

void HAL_GPIO_Init(GPIO_Port_t GPIOx, uint16_t GPIO_Pin, GPIO_PinMode_t Mode)
{
    const uint16_t PinMask = GPIO_Pin | (GPIO_Pin << 8U);

    /* Setup direction */
    if(Mode == GPIO_PIN_INPUT)
    {
        *_GPIO_Table[GPIOx].CTL |= PinMask;
    }
    else
    {
        *_GPIO_Table[GPIOx].CTL &= ~PinMask;
    }
}

void HAL_GPIO_SetPower(GPIO_PowerControl_t *PowerParams)
{
    _GPIO->GRP10_CTL = (PowerParams->Group0_DriveControl << GPIO_GROUP10_G0_DRIVE_SHIFT) |
        (PowerParams->Group1_DriveControl << GPIO_GROUP10_G1_DRIVE_SHIFT) |
        (PowerParams->Group0_DC_Control << GPIO_GROUP10_G0_DC_SHIFT) |
        (PowerParams->Group1_DC_Control << GPIO_GROUP10_G1_DC_SHIFT) |
         PowerParams->EnableAlternateDCs;

    _GPIO->GRP32_CTL = (PowerParams->Group2_DriveControl << GPIO_GROUP32_G2_DRIVE_SHIFT) |
        (PowerParams->Group3_DriveControl << GPIO_GROUP32_G3_DRIVE_SHIFT) |
        (PowerParams->Group2_DC_Control << GPIO_GROUP32_G2_DC_SHIFT) |
        (PowerParams->Group3_DC_Control << GPIO_GROUP32_G3_DC_SHIFT);
}

void HAL_GPIO_SetPower_GPIOE(uint16_t GPIO_Pin, GPIO_DriveControl_PortE DriveControl, GPIO_DC_Control DC_Mode)
{
    uint32_t PinNum = 0;
    uint16_t Pin = GPIO_Pin;

    /* Set DC controls and DRIVE controls */
    while(Pin)
    {
        if(Pin & 1U)
        {
            _GPIO->GRPE_DC = DC_Mode << PinNum;
            _GPIO->GRPE_DRV = DriveControl << PinNum;
        }

        Pin >>= 1U;
        ++PinNum;
    }
}

/* end: cx805_gpio.c ----- */


