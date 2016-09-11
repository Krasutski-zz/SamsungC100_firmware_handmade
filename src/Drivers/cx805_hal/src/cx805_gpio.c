/* begin: cx805_gpio.c ----- */
/* created 9/7/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_gpio.h>

/* ----- Types -------------------------------------------------------------- */

/* ----- Settings ----------------------------------------------------------- */


/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */
static GPIO_TypeDef *_GPIO = (GPIO_TypeDef *)GPIO_BASE_ADDR;

/* ----- Local functions ---------------------------------------------------- */
typedef struct
{
    uint16_t *CTL;
    uint16_t *DAT;
}GPIO_CustomPort;

/* Lets use this table this allow fast acces to control registers */
static const GPIO_CustomPort _GPIO_Table[] =
{
    [GPIOA] = {(uint16_t*)(GPIO_BASE_ADDR + 0x04), (uint16_t*)(GPIO_BASE_ADDR + 0x0C)},
    [GPIOB] = {(uint16_t*)(GPIO_BASE_ADDR + 0x06), (uint16_t*)(GPIO_BASE_ADDR + 0x0E)},
    [GPIOC] = {(uint16_t*)(GPIO_BASE_ADDR + 0x08), (uint16_t*)(GPIO_BASE_ADDR + 0x10)},
    [GPIOD] = {(uint16_t*)(GPIO_BASE_ADDR + 0x0A), (uint16_t*)(GPIO_BASE_ADDR + 0x12)},
    [GPIOE] = {(uint16_t*)(GPIO_BASE_ADDR + 0x1A), (uint16_t*)(GPIO_BASE_ADDR + 0x1C)},
};
/* =====> Implementation ---------------------------------------------------- */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_Port GPIOx, uint16_t GPIO_Pin)
{
    return (*_GPIO_Table[GPIOx].DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void HAL_GPIO_WritePin(GPIO_Port GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
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

void HAL_GPIO_TogglePin(GPIO_Port GPIOx, uint16_t GPIO_Pin)
{
    uint16_t temp = *_GPIO_Table[GPIOx].DAT;

    temp ^= GPIO_Pin << 8U;
    temp |= GPIO_Pin;

    *_GPIO_Table[GPIOx].DAT = temp;
}

void HAL_GPIO_ABCD_Init(GPIO_Port GPIOx, uint16_t GPIO_Pin, GPIO_PinMode Mode, GPIO_ABCD_DriveControl DriveControl, GPIO_DC_Control DC_Mode)
{
    uint16_t PinMask = GPIO_Pin | (GPIO_Pin << 8U);

    /* Set DC controls and DRIVE controls */
    switch(GPIOx)
    {
        /* Group 0 */
    case GPIOA:
    case GPIOB:
        _GPIO->GRP10_CTL &= ~(GPIO_GROUP10_G0_DRIVE_MASK | GPIO_GROUP10_G0_DC_MASK);
        _GPIO->GRP10_CTL |= DriveControl << GPIO_GROUP10_G0_DRIVE_SHIFT;
        _GPIO->GRP10_CTL |= DC_Mode << GPIO_GROUP10_G0_DC_SHIFT;
        break;
        /* Group 1 */
    case GPIOC:
        _GPIO->GRP10_CTL &= ~(GPIO_GROUP10_G1_DRIVE_MASK | GPIO_GROUP10_G1_DC_MASK);
        _GPIO->GRP10_CTL |= DriveControl << GPIO_GROUP10_G1_DRIVE_SHIFT;
        _GPIO->GRP10_CTL |= DC_Mode << GPIO_GROUP10_G1_DC_SHIFT;
        break;
        /* Group 2-3 */
    case GPIOD:
        if(GPIO_Pin & (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3))
        {
            _GPIO->GRP32_CTL &= ~(GPIO_GROUP32_G2_DRIVE_MASK | GPIO_GROUP32_G2_DC_MASK);
            _GPIO->GRP32_CTL |= DriveControl << GPIO_GROUP32_G2_DRIVE_SHIFT;
            _GPIO->GRP32_CTL |= DC_Mode << GPIO_GROUP32_G2_DC_SHIFT;
        }
        else
        {
            _GPIO->GRP32_CTL &= ~(GPIO_GROUP32_G3_DRIVE_MASK | GPIO_GROUP32_G3_DC_MASK);
            _GPIO->GRP32_CTL |= DriveControl << GPIO_GROUP32_G3_DRIVE_SHIFT;
            _GPIO->GRP32_CTL |= DC_Mode << GPIO_GROUP32_G3_DC_SHIFT;
        }
        break;
    default:
        ASSERT(TRUE);
        break;
    }


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
//TODO one init function
void HAL_GPIO_E_Init(uint16_t GPIO_Pin, GPIO_PinMode Mode, GPIOE_DriveControl DriveControl, GPIO_DC_Control DC_Mode)
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

    /* Setup direction */
    if(Mode == GPIO_PIN_INPUT)
    {
        _GPIO->GRPE_CTL |= GPIO_Pin | (GPIO_Pin << 8U);
    }
    else
    {
        _GPIO->GRPE_CTL &= ~(uint16_t)(GPIO_Pin | (GPIO_Pin << 8U));
    }
}

void HAL_GPIO_ABC_AlternativeDC(GPIO_Port GPIOx, FunctionalState State)
{
    switch(GPIOx)
    {
    case GPIOA:
        if(State == ENABLE)
        {
            _GPIO->GRP10_CTL |= GPIO_GROUP10_A_PORTA_EN;
        }
        else
        {
            _GPIO->GRP10_CTL &= ~GPIO_GROUP10_A_PORTA_EN;
        }
        break;
    case GPIOB:
        if(State == ENABLE)
        {
            _GPIO->GRP10_CTL |= GPIO_GROUP10_B_PORTA_EN;
        }
        else
        {
            _GPIO->GRP10_CTL &= ~GPIO_GROUP10_B_PORTA_EN;
        }
        break;
    case GPIOC:
        if(State == ENABLE)
        {
            _GPIO->GRP10_CTL |= GPIO_GROUP10_C_PORTA_EN;
        }
        else
        {
            _GPIO->GRP10_CTL &= ~GPIO_GROUP10_C_PORTA_EN;
        }
        break;
    default:
        ASSERT(TRUE);
        break;
    }
}


/* end: cx805_gpio.c ----- */


