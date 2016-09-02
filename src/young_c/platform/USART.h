/*
 * USART.h
 *
 *  Created on: 26.07.2012
 *      Author: Krasutski Denis
 */

#ifndef USART_H_
#define USART_H_

#include "cx805.h"



#define SDS_TX_ENABLED 1


#define SDS_RX_ENABLED 1

static void PrintChar(char c)
{
	/* Send a char like:
	   while(Transfer not completed);
	   Transmit a char;
	*/
	SDS_TX_HOLD=c;

	while(SDS_TX_STAT & 0x1);
}



#endif /* USART_H_ */
