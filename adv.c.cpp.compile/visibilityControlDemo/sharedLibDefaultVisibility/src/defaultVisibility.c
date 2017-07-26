#include "sharedLibExports.h"

void mylocalfunction1(void)
{
	printf("function1\n");
}

void mylocalfunction2(void)
{
	printf("function2\n");
}

void mylocalfunction3(void)
{
	printf("function3\n");
}

void printMessage(void)
{
	printf("Running the function exported from the shared library\n");
}
