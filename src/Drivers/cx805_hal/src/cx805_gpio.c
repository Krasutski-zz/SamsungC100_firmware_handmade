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


/* =====> Implementation ---------------------------------------------------- */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_Port GPIOx, uint16_t GPIO_Pin)
{
    GPIO_PinState PinState;

    switch(GPIOx)
    {
    case GPIOA:
        PinState = (_GPIO->GRPA_DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        break;
    case GPIOB:
        PinState = (_GPIO->GRPB_DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        break;
    case GPIOC:
        PinState = (_GPIO->GRPC_DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        break;
    case GPIOD:
        PinState = (_GPIO->GRPD_DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        break;
    case GPIOE:
        PinState = (_GPIO->GRPE_DAT & GPIO_Pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
        break;
    default:
        ASSERT(TRUE);
        break;
    }

    return PinState;
}

void HAL_GPIO_WritePin(GPIO_Port GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
    const uint16_t NewState = (PinState == GPIO_PIN_SET)?(GPIO_Pin << 8U) : 0U;

    switch(GPIOx)
    {
    case GPIOA:
        _GPIO->GRPA_DAT = NewState;
        _GPIO->GRPA_DAT |= GPIO_Pin;
        break;
    case GPIOB:
        _GPIO->GRPB_DAT = NewState;
        _GPIO->GRPB_DAT |= GPIO_Pin;
        break;
    case GPIOC:
        _GPIO->GRPC_DAT = NewState;
        _GPIO->GRPC_DAT |= GPIO_Pin;
        break;
    case GPIOD:
        _GPIO->GRPD_DAT = NewState;
        _GPIO->GRPD_DAT |= GPIO_Pin;
        break;
    case GPIOE:
        _GPIO->GRPE_DAT = NewState;
        _GPIO->GRPE_DAT |= GPIO_Pin;
        break;
    default:
        ASSERT(TRUE);
        break;
    }
}

void HAL_GPIO_TogglePin(GPIO_Port GPIOx, uint16_t GPIO_Pin)
{
    const uint16_t NewState = GPIO_Pin << 8U;

    switch(GPIOx)
    {
    case GPIOA:
        _GPIO->GRPA_DAT ^= NewState;
        _GPIO->GRPA_DAT |= GPIO_Pin;
        break;
    case GPIOB:
        _GPIO->GRPB_DAT = NewState;
        _GPIO->GRPB_DAT |= GPIO_Pin;
        break;
    case GPIOC:
        _GPIO->GRPC_DAT ^= NewState;
        _GPIO->GRPC_DAT |= GPIO_Pin;
        break;
    case GPIOD:
        _GPIO->GRPD_DAT ^= NewState;
        _GPIO->GRPD_DAT |= GPIO_Pin;
        break;
    case GPIOE:
        _GPIO->GRPE_DAT ^= NewState;
        _GPIO->GRPE_DAT |= GPIO_Pin;
        break;
    default:
        ASSERT(TRUE);
        break;
    }
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
    switch(GPIOx)
    {
    case GPIOA:
        if(Mode == GPIO_PIN_INPUT)
        {
            _GPIO->GRPA_CTL |= PinMask;
        }
        else
        {
            _GPIO->GRPA_CTL &= ~PinMask;
        }
        break;
    case GPIOB:
        if(Mode == GPIO_PIN_INPUT)
        {
            _GPIO->GRPB_CTL |= PinMask;
        }
        else
        {
            _GPIO->GRPB_CTL &= ~PinMask;
        }
        break;
    case GPIOC:
        if(Mode == GPIO_PIN_INPUT)
        {
            _GPIO->GRPC_CTL |= PinMask;
        }
        else
        {
            _GPIO->GRPC_CTL &= ~PinMask;
        }
        break;
    case GPIOD:
        if(Mode == GPIO_PIN_INPUT)
        {
            _GPIO->GRPD_CTL |= PinMask;
        }
        else
        {
            _GPIO->GRPD_CTL &= ~PinMask;
        }
        break;
    default:
        ASSERT(TRUE);
        break;
    }
}

void HAL_GPIO_E_Init(uint16_t GPIO_Pin, GPIO_PinMode Mode, GPIOE_DriveControl DriveControl, GPIO_DC_Control DC_Mode)
{
    uint32_t PinNum = 0;
    uint16_t Pin = GPIO_Pin;

    /* Set DC controls and DRIVE controls */
    while(Pin)
    {
        if(GPIO_Pin & 1U)
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


