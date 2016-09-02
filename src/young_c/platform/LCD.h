/*
 * mmLCD.h
 *
 *  Created on: 08.08.2011
 *      Author: Krasutski Denis
 */

#ifndef MMLCD_H_
#define MMLCD_H_

#include "cx805.h"

void lcd_init();
void lcd_SetContrast(char val);

#define RGB(r,g,b)           (((r&0xF8)<<8)|((g&0xFC)<<3)|((b&0xF8)>>3)) //5 red | 6 green | 5 blue



#endif /* MMLCD_H_ */
