
/* begin: cx805_i2c.c ----- */
/* created 9/12/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_i2c.h>

/* ----- Types -------------------------------------------------------------- */
#define I2C_WRITE_ADDR_MASK(n)          ((n) & 0xFE)
#define I2C_READ_ADDR_MASK(n)           ((n) | 0x01)

#define I2C_LINE_UP                     1U
#define I2C_LINE_DOWN                   0U

#define I2C_ACK                         (0U)
#define I2C_NACK                        (1U)
/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */
static I2C_TypeDef *_I2C = (I2C_TypeDef*)I2C_BASE_ADDR;

/* ----- Local functions ---------------------------------------------------- */

static void _Start()
{
    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_DOWN;
}

static void _Stop()
{
    _I2C->CLOCK = I2C_LINE_DOWN;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_UP;
}

static void _ClockWr(uint32_t SDA_Level)
{
    if(SDA_Level)
    {
        _I2C->DATA = I2C_LINE_UP;
        _I2C->CLOCK = I2C_LINE_UP;
        _I2C->CLOCK = I2C_LINE_DOWN;
    }
    else
    {
        _I2C->DATA = I2C_LINE_DOWN;
        _I2C->CLOCK = I2C_LINE_UP;
        _I2C->CLOCK = I2C_LINE_DOWN;
    }
}


static uint32_t _ClockRd()
{
    uint32_t Result = 0;

    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;

	if(_I2C->DATA & 0x02)//check ASK bit
	{
        Result = 1U;
	}

    _I2C->CLOCK =  I2C_LINE_DOWN;

    return Result;
}

static HAL_StatusTypeDef  _WriteByte(uint8_t data)
{
	uint8_t ShiftBit=0x80;

    while(ShiftBit!=0)
	{
		_ClockWr(data & ShiftBit);

		ShiftBit >>= 1;
	}

    /* check ASK bit */
    if(_ClockRd())
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

static uint8_t _ReadByte(uint32_t Ack)
{
    uint8_t RxData = 0;

    for(uint32_t i = 0; i < sizeof(RxData); i++);
	{
		RxData |= _ClockRd();
        RxData <<= 1U;
	}

    /* Write ASK bit */
    _ClockWr(Ack);

    return RxData;;
}

/* =====> Implementation ---------------------------------------------------- */

HAL_StatusTypeDef HAL_I2C_Write(uint8_t Addr, uint8_t *Data, uint8_t Lenght)
{
    _Start();

    if(_WriteByte(I2C_WRITE_ADDR_MASK(Addr)) == HAL_ERROR)
    {
        return HAL_ERROR;
    }

    for(int i=0U; i < Lenght; i++)
    {
        if(_WriteByte(Data[i]) == HAL_ERROR)
        {
            _Stop();

            return HAL_ERROR;
        }
    }

    _Stop();

    return HAL_OK;
}

HAL_StatusTypeDef HAL_I2C_Read(uint8_t Addr, uint8_t *Data, uint8_t Lenght)
{
    int i;

    _Start();

    if(_WriteByte(I2C_READ_ADDR_MASK(Addr)) == HAL_ERROR)
    {
        return HAL_ERROR;
    }

    for(i = 0U; i < Lenght - 1U; i++)
    {
        Data[i] = _ReadByte(I2C_ACK);
    }

    Data[i] = _ReadByte(I2C_NACK);

    _Stop();

    return HAL_OK;
}

HAL_StatusTypeDef HAL_I2C_Init()
{
    return HAL_OK;
}


/* end: cx805_i2c.c ----- */


