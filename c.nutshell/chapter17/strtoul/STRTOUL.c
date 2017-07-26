/* STRTOUL.c */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char dotted[] = "172.16.2.10", *ptr = dotted, *nextdot = NULL;
	unsigned long dest = 0;
	unsigned long destarr[4] = 0;
	int i;
	for ( i = 0; i < 4; i++ )
	{
		dest << 8;
		dest += strtoul( ptr, &nextdot, 10 );
		ptr = nextdot + 1;
	}

}