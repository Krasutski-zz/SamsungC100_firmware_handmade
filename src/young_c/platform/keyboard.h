/*
 * c100hard.h
 *
 *  Created on: 11.08.2011
 *      Author: Denis
 */

#ifndef C100HARD_H_
#define C100HARD_H_


#include "cx805.h"


unsigned short keyb();
void init_keyb();


#define KEY_PWR 0x0801
#define KEY_1 0x0110
#define KEY_2 0x0210
#define KEY_3 0x0410
#define KEY_4 0x0108
#define KEY_5 0x0208
#define KEY_6 0x0408
#define KEY_7 0x0104
#define KEY_8 0x0204
#define KEY_9 0x0404
#define KEY_0 0x0202
#define KEY_UP 0x0280
#define KEY_DOWN 0x0220
#define KEY_LEFT 0x0140
#define KEY_RIGHT 0x0440
#define KEY_C 0x0420
#define KEY_SEND 0x0120
#define KEY_SL 0x0180
#define KEY_SR 0x0480
#define KEY_VUP 0x0201
#define KEY_VDOWN 0x0101
#define KEY_STAR 0x0102
#define KEY_LATTICE 0x0402



#endif /* C100HARD_H_ */
