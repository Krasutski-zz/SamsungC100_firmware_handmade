/*
 * RTC.h
 *
 *  Created on: 14.08.2011
 *      Author: Admin
 */

#ifndef RTC_H_
#define RTC_H_

#include "../types.h"
#include "cx805.h"

typedef struct
{
	u16 sec;
	u16 min;
	u16 hours;
	u16 days;
	u16 mounth;
	u16 year;
	u16 ctrl;
	u16 test;
} RTC_Time_t;

typedef struct
{
	u16 min;
	u16 hours;
	u16 days;
	u16 mounth;
	u16 year;
} RTC_Alarm_t;


void SetTime(RTC_Time_t* time);
void GetTime(RTC_Time_t* time);





#endif /* RTC_H_ */
