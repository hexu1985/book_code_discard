/* charstr.c:  ×Ö·ûÊý×é */

#include <string.h>
#include <stdio.h>


int main()
{
	char teststr[] = "let's go";
	int length = sizeof(teststr);
	printf( "length = %d\n", length );

	char str1[] = "Let's go";
	char str2[] = " to London!";

	strcat( str1, str2 );
	puts( str1 );

	printf( "\n" );
	return 0;
}