#include "sharedLibExports.h"

#if 1
#define FOR_EXPORT __attribute__ ((visibility("default")))
#else
#define FOR_EXPORT
#endif

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

// 
// also supported:
// 		FOR_EXPORT void printMessage(void)
// but this is not supported:
//  	void printMessage FOR_EXPORT (void)
// nor this:
// 		void printMessage(void) FOR_EXPORT
//
// i.e. attribute may be declared anywhere 
// before the function name

void FOR_EXPORT printMessage(void)
{
	printf("Running the function exported from the shared library\n");
}
