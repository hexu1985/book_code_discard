#include <iostream>
#include "singleton.h"
using namespace std;

#ifdef TRY_STATIC_VARIABLE_SCENARIO
Singleton* Singleton::m_pInstance = NULL;
#endif // TRY_STATIC_VARIABLE_SCENARIO

Singleton::Singleton(void)
{
	
}

Singleton::~Singleton()
{
	
}

Singleton& Singleton::GetInstance(void)
{
#ifdef TRY_STATIC_VARIABLE_SCENARIO
    if(NULL == m_pInstance)
        m_pInstance = new Singleton();
    return *m_pInstance;
#else
    static Singleton singleton;
    return singleton;
#endif
}

int Singleton::DoSomething(void)
{
    cout << "singleton instance address = " << this << endl;
    return 0;
}
    
