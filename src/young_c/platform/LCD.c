/*
 * mmLCD.c
 *
 *  Created on: 08.08.2011
 *      Author: Krasutski Denis
 */
#include "LCD.h"
#include "../types.h"
const unsigned char init_table[16]={0x2C,0x02,0x01,0x20,0x05,0x26,0x0F,0x10,0x04,0x22,0x01,0x34,0x8D,0x2A,0xA8,0x51};

void lcd_init()
{
	unsigned char i;

	GRPD_CTL&=0xfe;		//set GPIO_D[1] as output
	GRPD_DAT=0x1;		//set
	CS3_CONFIG=0x805;	//set CS3

	for(i=0;i<16;i++)
	{
		LCD_base=init_table[i];
	}

}

void lcd_SetContrast(char val)
{
	LCD_base=0x2a;
	LCD_base=val;
}


/*
 * Set Pixel
 */

void lcd_SetPixel(u16 x, u16 y, u16 color){

		LCD_base=0x43;
		LCD_base=0x10+x;
		LCD_base=x+1;
		LCD_base=0x42;
		LCD_base=y;
		LCD_base=y+1;


		LCD_data=color;

}


void lcd_clear(u16 color)
{
	char i,j;

		LCD_base=0x43;
		LCD_base=0x10;
		LCD_base=0x8f;
		LCD_base=0x42;
		LCD_base=0x0;
		LCD_base=0x7f;

		for(i=0;i<128;i++)
		{
			for(j=0;j<128;j++)
			{
				LCD_data=color;
			}
		}
}

