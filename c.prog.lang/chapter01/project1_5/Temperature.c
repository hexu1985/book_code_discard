#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 	int fahr;
	
	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf("\t%3d\t%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
		
	system("PAUSE");	
	return 0;
}
