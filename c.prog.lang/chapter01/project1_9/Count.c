#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	long nc;
	
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
	
	system("PAUSE");	
	return 0;
}
