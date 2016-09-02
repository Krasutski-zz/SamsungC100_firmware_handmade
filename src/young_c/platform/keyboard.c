/*
 * c100hard.c
 *
 *  Created on: 11.08.2011
 *      Author: Denis
 */

#include "keyboard.h"

void init_keyb()
{
	KEYB_CTL=0x0;
}
unsigned short keyb()
{
	unsigned short ShiftBit=0x0080,ret=0;
	KEYB_STRB=0x0;
	switch(KEYB_RET)
	{
		case 0x001f:
		{
			ret=0x0;
			break;
		}
		case 0x001E:
		{
			do
			{
				ShiftBit<<=1;
				KEYB_STRB=~ShiftBit;
			}while((ShiftBit!=0x00)&&(KEYB_RET==0x001f));

			ret=0x0100 | (ShiftBit>>8);
			break;
		}
		case 0x001D:
		{
			do
			{
				ShiftBit<<=1;
				KEYB_STRB=~ShiftBit;
			}while((ShiftBit!=0x00)&&(KEYB_RET==0x001f));


			ret=0x0200 | (ShiftBit>>8);

			break;
		}
		case 0x001B:
		{
			do
			{
				ShiftBit<<=1;
				KEYB_STRB=~ShiftBit;
			}while((ShiftBit!=0x00)&&(KEYB_RET==0x001f));


			ret=0x0400 | (ShiftBit>>8);

			break;
		}
		case 0x0017:
		{
			do
			{
				ShiftBit<<=1;
				KEYB_STRB=~ShiftBit;
			}while((ShiftBit!=0x00)&&(KEYB_RET==0x001f));


			ret=0x0800 | (ShiftBit>>8);

			break;
		}
	//	default: return KEYB_RET;
	}
	return ret;
}
