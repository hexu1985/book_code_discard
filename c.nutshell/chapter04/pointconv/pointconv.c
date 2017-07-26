/* pointconv.c:  显示的指针转换 */

#include <stdio.h>

struct Data {
	short id;
	double val;
};


int main()
{
	struct Data myDate = { 0x123, 77.7 };

	unsigned char* cp = (unsigned char*)&myDate;

	printf( "%p: ", cp);

	int i;
	for ( i = 0; i < sizeof(myDate); ++i )
		printf( "%02X ", *(cp + i) );
	putchar( '\n' );

	return 0;
}
