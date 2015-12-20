/*

	About: gmtime - convert the calendar time into broken down time
	Author: Minix Developers
	Convert to Pawn: ziggi

*/

#if defined _gmtime_included
	#endinput
#endif

#define _gmtime_included
#pragma library gmtime


/*
	Defines
*/

#define YEAR0           1900            /* the first year */
#define EPOCH_YR        1970            /* EPOCH = Jan 1 1970 00:00:00 */
#define SECS_DAY        (24 * 60 * 60)
#define EPOCH_YR        1970
#define LEAPYEAR(%0)  (!((%0) % 4) && (((%0) % 100) || !((%0) % 400)))
#define YEARSIZE(%0)  (LEAPYEAR(%0) ? 366 : 365)

/*
	Vars
*/
static const _ytab[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/*
	gmtime(timestamp, &year = 1970, &month = 1, &day = 1, &hour = 0, &minute = 0, &second = 0)
*/

stock gmtime(timestamp, &year = EPOCH_YR, &month = 1, &day = 1, &hour = 0, &minute = 0, &second = 0)
{
	static dayclock;

	year = EPOCH_YR;
	dayclock = timestamp % SECS_DAY;
	day = timestamp / SECS_DAY;
	
	second = dayclock % 60;
	minute = (dayclock % 3600) / 60;
	hour = dayclock / 3600;
	
	while (day >= YEARSIZE(year)) {
		day -= YEARSIZE(year);
		year++;
	}

	month = 0;

	while (day >= _ytab[LEAPYEAR(year)][month]) {
		day -= _ytab[LEAPYEAR(year)][month];
		month++;
	}

	day++;
	month++;
}
