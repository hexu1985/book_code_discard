#include "sharedLibExports.h"
#include <unistd.h> // needed for the _exit() function

// Must define the interpretor to be the dynamic linker
#ifdef __LP64__
const char service_interp[] __attribute__((section(".interp"))) = "/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2"; 
#else
const char service_interp[] __attribute__((section(".interp"))) = "/lib/ld-linux.so.2"; 
#endif

void printMessage(void)
{
	printf("Running the function exported from the shared library\n");
}

int main(int argc, char* argv[])
{
	printf("Shared library %s() function\n", __FUNCTION__);
	
	// must make the entry point function to be a 'no-return' function type
	_exit(0);
}
