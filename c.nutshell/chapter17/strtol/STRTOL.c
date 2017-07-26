/* STRTOL.c */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char date[] = "10/3/2005, 13:44:18 +0100", *more = date;
	long day, mo, yr, hr, min, sec, tzone;
	int base = 10;
	day = strtol( more, &more, base );
	mo = strtol( more + 1, &more, base );
	yr = strtol( more + 1, &more, base );
	hr = strtol( more + 1, &more, base );
	min = strtol( more + 1, &more, base );
	sec = strtol( more + 1, &more, base );
	tzone = strtol( more + 1, &more, base );
	printf( "the date[] is %s\n", date );
	printf( "the date from strtol is %d/%d/%d, %d:%d:%d +0%d\n", 
			day, mo, yr, hr, min, sec, tzone );

	printf( "\n" );
	return 0;
}