#include "sharedLibExports.h"
#include "staticLibExports.h"

void printMessage(void)
{
	printf("Running the function exported from the shared library\n");
	printStaticLibMessage(1);
}
