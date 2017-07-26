#include <iostream>
#include <dlfcn.h>
#include "shlibfirstexports.h"
#include "shlibsecondexports.h"
#include "singleton.h"

using namespace std;

int main(int argc, char* argv[])
{
    shlibfirst_function();
    shlibsecond_function();	
    cout << "Accesing singleton directly from the client app" << endl;
    Singleton& singleton = Singleton::GetInstance();
    singleton.DoSomething();
    return 0;
}
