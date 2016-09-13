
/* begin: cx805_i2c.c ----- */
/* created 9/12/2016 by user ----------------------------------- */

/* ----- Includes ----------------------------------------------------------- */
#include <cx805_i2c.h>

/* ----- Types -------------------------------------------------------------- */
#define I2C_WRITE_ADDR_MASK(n)          ((n) & 0xFE)
#define I2C_READ_ADDR_MASK(n)           ((n) | 0x01)

#define I2C_LINE_UP                     1U
#define I2C_LINE_DOWN                   0U

/* ----- Global variables --------------------------------------------------- */


/* ----- Local variables ---------------------------------------------------- */
static I2C_TypeDef *_I2C = (I2C_TypeDef*)I2C_BASE_ADDR;

/* ----- Local functions ---------------------------------------------------- */
static void _Strobe()
{
    asm("NOP");
}

static HAL_StatusTypeDef  _WriteByte(uint8_t data)
{
	uint8_t ShiftBit=0x80;

    while(ShiftBit!=0)
	{
		if (data & ShiftBit )
		{
			_I2C->DATA = I2C_LINE_UP;
			_I2C->CLOCK = I2C_LINE_UP;
            _Strobe();
			_I2C->CLOCK = I2C_LINE_DOWN;
		}
        else
		{
			_I2C->DATA = I2C_LINE_DOWN;
			_I2C->CLOCK = I2C_LINE_UP;
            _Strobe();
			_I2C->CLOCK = I2C_LINE_DOWN;
		}

		ShiftBit >>= 1;
	};

    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;

	if(_I2C->DATA & 0x2)//check ASK bit
	{
        _I2C->CLOCK =  I2C_LINE_DOWN;
		return HAL_ERROR;
	}

    _I2C->CLOCK =  I2C_LINE_DOWN;

    return HAL_OK;
}

static HAL_StatusTypeDef  _ReadByte(uint8_t data)
{
	uint8_t ShiftBit=0x80;

    while(ShiftBit!=0)
	{
		if (data & ShiftBit )
		{
			_I2C->DATA = I2C_LINE_UP;
			_I2C->CLOCK = I2C_LINE_UP;
            _Strobe();
			_I2C->CLOCK = I2C_LINE_DOWN;
		}
        else
		{
			_I2C->DATA = I2C_LINE_DOWN;
			_I2C->CLOCK = I2C_LINE_UP;
            _Strobe();
			_I2C->CLOCK = I2C_LINE_DOWN;
		}

		ShiftBit >>= 1;
	};

    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;

	if(_I2C->DATA & 0x2)//check ASK bit
	{
        _I2C->CLOCK =  I2C_LINE_DOWN;
		return HAL_ERROR;
	}

    _I2C->CLOCK =  I2C_LINE_DOWN;

    return HAL_OK;
}

/* =====> Implementation ---------------------------------------------------- */

HAL_StatusTypeDef HAL_I2C_Write(uint8_t Addr, uint8_t *Data, uint8_t Lenght)
{
    /* Start */
    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_DOWN;

    if(_WriteByte(I2C_WRITE_ADDR_MASK(Addr)) == HAL_ERROR)
    {
        return HAL_ERROR;
    }

    for(int i=0U; i < Lenght; i++)
    {
        if(_WriteByte(Data[i]) == HAL_ERROR)
        {
            return HAL_ERROR;
        }
    }

    /* Stop */
    _I2C->CLOCK = I2C_LINE_DOWN;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_UP;

    return HAL_OK;
}

HAL_StatusTypeDef HAL_I2C_Read(uint8_t Addr, uint8_t *Data, uint8_t Lenght)
{
    /* Start */
    _I2C->DATA = I2C_LINE_UP;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_DOWN;

    if(_WriteByte(I2C_READ_ADDR_MASK(Addr)) == HAL_ERROR)
    {
        return HAL_ERROR;
    }

    for(int i=0U; i < Lenght; i++)
    {
        if(_WriteByte(Data[i]) == HAL_ERROR)
        {
            return HAL_ERROR;
        }
    }

    /* Stop */
    _I2C->CLOCK = I2C_LINE_DOWN;
    _I2C->DATA = I2C_LINE_DOWN;
    _I2C->CLOCK = I2C_LINE_UP;
    _I2C->DATA = I2C_LINE_UP;

    return HAL_OK;
}


/* end: cx805_i2c.c ----- */


