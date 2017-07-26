#include <iostream>
#include <dlfcn.h>
#include "shlibsecondexports.h"
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef int (*PFUNCTION)(void);

int shlibsecond_function(void)
{
	cout << __FUNCTION__ << ":" << endl;
	
	void* pShlibFirst = NULL;
	do
	{
		pShlibFirst = dlopen("../shlibFirst/libfirst.so", RTLD_GLOBAL|RTLD_NOW);
        if(NULL == pShlibFirst)
        {
            cout << dlerror() << endl;
            break;
        }
	
        PFUNCTION pFirstFunction = (PFUNCTION)dlsym(pShlibFirst, "shlibfirst_function");
        if(NULL == pFirstFunction)
        {
            cout << dlerror() << endl;
            break;
        }
        pFirstFunction();
    } while(0);
    
    if(pShlibFirst)
    {
        dlclose(pShlibFirst);
        pShlibFirst = NULL;
	}
	
	cout << "Accessing singleton from shlibsecond..." << endl;
	
	Singleton& singleton = Singleton::GetInstance();
	singleton.DoSomething();
	
    return 0;
}

#ifdef __cplusplus
}
#endif // __cplusplus
