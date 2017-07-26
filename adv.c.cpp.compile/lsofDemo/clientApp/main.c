#include <stdio.h>
#include <dlfcn.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"

int main(int argc, char* argv[])
{
    shlibfirst_function(1);
    
    void* pLibSecond = dlopen("../libSecond/libsecond.so", RTLD_GLOBAL | RTLD_NOW);
    if(NULL == pLibSecond)
    {
		printf("Failed loading libsecond.so\n");
		printf("Error: %s\n", dlerror());
		return -1;
	}
	
	SHLIBSECOND_FUNCTION pShlibSecondFunction = 
	     dlsym(pLibSecond, "shlibsecond_function");
	if(NULL == pShlibSecondFunction)
	{
		printf("Failed finding the symbol \"shlibsecond_function\"\n");
		printf("Error: %s\n", dlerror());
		dlclose(pLibSecond);
		pLibSecond = NULL;
		return -1;
	}
	
    pShlibSecondFunction(2);

    printf("Press any key to continue to dlclose() the libsecond.so\n");
    printf("Before doing so, you may run lsof -p `pgrep clientApp`...\n");
    getchar();
    
    dlclose(pLibSecond);
    pLibSecond = NULL;    

    printf("Press any key to continue to terminate the app\n");
    printf("Before doing so, you may run again lsof -p `pgrep clientApp`...\n");
    getchar();
      
    return 0;
}
