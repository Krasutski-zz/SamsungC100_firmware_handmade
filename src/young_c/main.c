/*
 * main.c
 *
 *  Created on: 22.07.2011
 *      Author: Krasutski Denis
 */
//טחלודודעÿ
#include "platform/cx805.h"
#include "platform/i2c.h"
#include "platform/LCD.h"
#include "platform/keyboard.h"
#include "platform/RTC.h"

#define onRED GRPA_DAT=0x207f
#define onBLUE GRPA_DAT=0x407f
#define onGREEN GRPA_DAT=0x087f
#define onORANGE GRPA_DAT=0x287f
#define onBIRCH GRPA_DAT=0x487f
#define onROSE GRPA_DAT=0x607f
#define onWHITE GRPA_DAT=0x687f
#define onLCD GRPA_DAT=0x8080

#define SETDATABIT(REG,bit) REG=(  (unsigned short)( 1<<(bit+8) )  | ((1<<bit) ) )

//int main() __attribute__ ((section(".entry")));
int main();

void __attribute__ ((section(".entry"))) _entry() {
	main();
}

char tmp[22] = "Proverka LCD Samsung!";
unsigned short *addr = (unsigned short*) 0xc700;


void sleep(){

	u16 del=0x3fff;

	while(del--);
}

u16 test_array[255];

int main() {
	unsigned short Status, i, j = 0xffff, prev, k, press = 1;
	GRPA_CTL = 0;
	onBLUE;



	Status = PutToPMU(0x3, 0x1);
	if (Status != 0) {
		onRED;
	}

	while(keyb()==KEY_PWR);

	lcd_init();
	init_keyb();
	onLCD;

	font_SetColor(RGB(0,0xff,0), RGB(0,0,0));
	lcd_clear(0);

	font_printlcd("RxReg", 1);
	font_SetColor(RGB(25,0,255), RGB(0,0,0));

	prev = SDS_RX_HOLD;
	SDS_RX_CTL |= 1;

	SDS_TX_CTL|=0x01;
	SDS_TX_BRS=0x22;
	SDS_TX_HOLD;
	SDS_TX_STAT;

	lcd_clear(0);

	while (keyb() != KEY_SEND) {

				font_SetColor(RGB(0,0xff,0), RGB(0,0,0));
				i = SDS_RX_CTL;
				font_printHex(0, 2 * 8, i >> 8);
				font_printHex(12, 2 * 8, i);
				i = SDS_RX_BRS;
				font_printHex(0, 3 * 8, i >> 8);
				font_printHex(12, 3 * 8, i);
				i = SDS_RX_HOLD;
				font_printHex(0, 4 * 8, i >> 8);
				font_printHex(12, 4 * 8, i);
				i = SDS_RX_STAT;
				font_printHex(0, 5 * 8, i >> 8);
				font_printHex(12, 5 * 8, i);

				font_SetColor(RGB(0,0,0xff), RGB(0,0,0));
				i = SDS_TX_CTL;
				font_printHex(0, 7 * 8, i >> 8);
				font_printHex(12, 7 * 8, i);
				i = SDS_TX_BRS;
				font_printHex(0, 8 * 8, i >> 8);
				font_printHex(12, 8 * 8, i);
				i = SDS_TX_HOLD;
				font_printHex(0, 9 * 8, i >> 8);
				font_printHex(12, 9 * 8, i);
				i = SDS_TX_STAT;
				font_printHex(0, 10 * 8, i >> 8);
				font_printHex(12, 10 * 8, i);

				font_SetColor(RGB(0,0xff,0xff), RGB(0,0,0));
				font_printTime(80, 0);



//				if (RX_HOLD != prev) {
//					j++;//=(j+1)%22;
//					j %= 22;
//					tmp[j] = RX_HOLD;
//					tmp[j+1] = 0;
//					//RX_HOLD=0;
//					prev = RX_HOLD;
//					//TX_HOLD=RX_HOLD;
////					TX_BRS=RX_BRS;
//					//TX_HOLD=0xaa;
//
//					//RX_STAT=0;
//				}

				font_SetColor(RGB(0xf0,0xf0,0xf0), RGB(0,0,0));
				font_printlcd(tmp,15);

				sleep();sleep();sleep();sleep();sleep();sleep();sleep();
				printf("Test_consolle:123456789\n\r");
				printf("Regs=0x%x\n\r",SDS_RX_HOLD);
	}
	lcd_init();

	Status = PutToPMU(0x3, 0x0);

	return 0;
}
