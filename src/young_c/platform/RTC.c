/*
 * RTC.c
 *
 *  Created on: 14.08.2011
 *      Author: Admin
 */
#include "RTC.h"

void GetTime(RTC_Time_t* time)
{
		memcpy(time,(void*)0x040080,sizeof(RTC_Time_t));
	return;
}


void SetTime(RTC_Time_t* time)
{
//		memcpy(time,(void*)0x040080,sizeof(RTC_Time_t));
//		RTC_t
	return;
}

//void SetTime(RTC_Time_t* time)
//{
//	char i;
//	RTC_CTL=0xff;
//
//	for(i=0;i<time->sec;i++)RTC_SEC=1;
//	for(i=0;i<time->min;i++)RTC_MIN=1;
//	for(i=0;i<time->hour;i++)RTC_H=1;
//	for(i=0;i<time->day;i++)RTC_DAY=1;
//	for(i=0;i<time->month;i++)RTC_MON=1;
//	for(i=0;i<time->year;i++)RTC_Y=1;
//}
