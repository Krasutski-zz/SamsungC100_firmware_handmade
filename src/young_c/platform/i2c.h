/*
 * i2c.h
 *
 *  Created on: 08.08.2011
 *      Author: Krasutski Denis
 */

#ifndef I2C_H_
#define I2C_H_

#include "cx805.h"

unsigned short SendI2C(unsigned char cAddr,unsigned char cReg,unsigned char cDat);
unsigned short PutToPMU(unsigned char cReg,unsigned char cDat);
unsigned char I2C_WriteByte(unsigned char data);

#define SDA I2C_DAT
#define SCL I2C_CLK

#define I2C_START SDA=1;SCL=1;SDA=0;SCL=0
#define I2C_STOP SDA=0;SCL=1;SDA=1
#define I2C_SET1 SDA=1;SCL=1;SCL=0
#define I2C_SET0 SDA=0;SCL=1;SCL=0

#endif /* I2C_H_ */
