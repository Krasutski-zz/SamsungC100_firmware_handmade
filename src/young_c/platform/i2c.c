/*
 * i2c.c
 *
 *  Created on: 08.08.2011
 *      Author: Krasutski Denis
 */
#include "i2c.h"

/* PutToPMU
 * 			write data over i2c bus
 * @param
 * 			cAddr slave address
 * 			cReg register address
 * 			cDat register value
 *
 * @return
 * 			0 if the data is successfully written
 */
unsigned short SendI2C(unsigned char cAddr,unsigned char cReg,unsigned char cDat)
{
	unsigned char cStatus;

	I2C_START;//start condition

	cStatus=I2C_WriteByte(cAddr<<1);
	if(cStatus){I2C_STOP; return 1;}

	cStatus=I2C_WriteByte(cReg);
	if(cStatus){I2C_STOP; return 2;}

	cStatus=I2C_WriteByte(cDat);
	if(cStatus){I2C_STOP; return 3;}

	I2C_STOP;//stop condition

	return 0;
}

/* PutToPMU
 * 			write data to PMU(Power Manager Unit)
 * @param
 * 			cReg is 8 bit register address
 * 			cDat register value
 *
 * @return
 * 			0 if the data is successfully written
 */
unsigned short PutToPMU(unsigned char cReg,unsigned char cDat)
{
	unsigned char cStatus;

	I2C_START;//start condition

	cStatus=I2C_WriteByte(0x90);//write address slave
	if(cStatus){I2C_STOP; return 1;}

	cStatus=I2C_WriteByte(cReg);//write register address
	if(cStatus){I2C_STOP; return 2;}

	cStatus=I2C_WriteByte(cDat);//write rester value
	if(cStatus){I2C_STOP; return 3;}

	I2C_STOP;//stop condition

	return 0;
}

/* I2C_WriteByte
 *
 * @param
 * 			data is 8 bit data for write over i2s bus
 *
 * @return
 * 			0 if the data is successfully written
 */
unsigned char I2C_WriteByte(unsigned char data)
{
	unsigned char cBit=0x80;
	do
	{//write 8 bit data
		if (data & cBit )
		{
			I2C_SET1;
		}else
		{
			I2C_SET0;
		}
		cBit>>=1;
	}while(cBit!=0);

	SDA=1;
	SCL=1;
	if(SDA & 0x2)//check ASK bit
	{
		SCL=0;
		return 1;
	}else
	{
		SCL=0;
		return 0;
	}
}
