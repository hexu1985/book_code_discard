#include <iostream>
#include <dlfcn.h>
#include "shlibfirstexports.h"
using namespace std;

typedef int (*PFUNCTION)(void);

int main(int argc, char* argv[])
{
	void* pShlibFirst = NULL;
	void* pShlibSecond = NULL;
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

        pShlibSecond = dlopen("../shlibSecond/libsecond.so", RTLD_GLOBAL | RTLD_NOW);
        if(NULL == pShlibSecond)
        {
            cout << dlerror() << endl;
            break;
        }
        
        PFUNCTION pSecondFunction = (PFUNCTION)dlsym(pShlibSecond, "shlibsecond_function");
        if(NULL == pSecondFunction)
        {
			cout << dlerror() << endl;
			break;
		}
		pSecondFunction();
		
	}while(0);
	
	if(pShlibFirst)
	{
        dlclose(pShlibFirst);
        pShlibFirst = NULL;
	}
	if(pShlibSecond)
	{
		dlclose(pShlibSecond);
		pShlibSecond = NULL;
	}
	
	cout << "Accesing singleton directly from the client app" << endl;
	Singleton& singleton = Singleton::GetInstance();
	singleton.DoSomething();
	return 0;
}
